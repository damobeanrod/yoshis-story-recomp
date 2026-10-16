#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8002570C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002570C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025710: addiu       $t6, $t6, 0x56A8
    ctx->r14 = ADD32(ctx->r14, 0X56A8);
    // 0x80025714: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025718: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x8002571C: jr          $ra
    // 0x80025720: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025720: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8002535C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002535C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025360: addiu       $t6, $t6, 0x513C
    ctx->r14 = ADD32(ctx->r14, 0X513C);
    // 0x80025364: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025368: jr          $ra
    // 0x8002536C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x8002536C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8040D230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040D234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040D238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040D23C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D240: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D244: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x8040D248: bnel        $v0, $zero, L_8040D27C
    if (ctx->r2 != 0) {
        // 0x8040D24C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8040D27C;
    }
    goto skip_0;
    // 0x8040D24C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x8040D250: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x8040D254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D258: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8040D25C: bnel        $t6, $zero, L_8040D27C
    if (ctx->r14 != 0) {
        // 0x8040D260: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8040D27C;
    }
    goto skip_1;
    // 0x8040D260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x8040D264: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D268: jal         0x8040E254
    // 0x8040D26C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040E254(rdram, ctx);
        goto after_0;
    // 0x8040D26C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8040D270: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8040D274: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x8040D278: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8040D27C:
    // 0x8040D27C: bnel        $v0, $at, L_8040D2F0
    if (ctx->r2 != ctx->r1) {
        // 0x8040D280: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_8040D2F0;
    }
    goto skip_2;
    // 0x8040D280: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_2:
    // 0x8040D284: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8040D288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D28C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D290: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x8040D294: beq         $at, $zero, L_8040D2A8
    if (ctx->r1 == 0) {
        // 0x8040D298: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8040D2A8;
    }
    // 0x8040D298: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8040D29C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040D2A0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8040D2A4: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
L_8040D2A8:
    // 0x8040D2A8: lw          $t0, 0x1E0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040D2AC: bnel        $t0, $zero, L_8040D2C8
    if (ctx->r8 != 0) {
        // 0x8040D2B0: lw          $t1, 0x30($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X30);
            goto L_8040D2C8;
    }
    goto skip_3;
    // 0x8040D2B0: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    skip_3:
    // 0x8040D2B4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D2B8: jal         0x8040E254
    // 0x8040D2BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040E254(rdram, ctx);
        goto after_1;
    // 0x8040D2BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8040D2C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8040D2C4: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
L_8040D2C8:
    // 0x8040D2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D2CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D2D0: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x8040D2D4: bne         $at, $zero, L_8040D2EC
    if (ctx->r1 != 0) {
        // 0x8040D2D8: addiu       $a2, $zero, 0x9
        ctx->r6 = ADD32(0, 0X9);
            goto L_8040D2EC;
    }
    // 0x8040D2D8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8040D2DC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D2E0: jal         0x8040E254
    // 0x8040D2E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040D2E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8040D2E8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8040D2EC:
    // 0x8040D2EC: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_8040D2F0:
    // 0x8040D2F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8040D2F4: bnel        $v0, $at, L_8040D328
    if (ctx->r2 != ctx->r1) {
        // 0x8040D2F8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8040D328;
    }
    goto skip_4;
    // 0x8040D2F8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_4:
    // 0x8040D2FC: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x8040D300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D308: bne         $t2, $zero, L_8040D324
    if (ctx->r10 != 0) {
        // 0x8040D30C: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8040D324;
    }
    // 0x8040D30C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8040D310: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D314: jal         0x8040E254
    // 0x8040D318: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040E254(rdram, ctx);
        goto after_3;
    // 0x8040D318: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x8040D31C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8040D320: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_8040D324:
    // 0x8040D324: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8040D328:
    // 0x8040D328: bnel        $v0, $at, L_8040D35C
    if (ctx->r2 != ctx->r1) {
        // 0x8040D32C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8040D35C;
    }
    goto skip_5;
    // 0x8040D32C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_5:
    // 0x8040D330: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x8040D334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D33C: bne         $t3, $zero, L_8040D358
    if (ctx->r11 != 0) {
        // 0x8040D340: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8040D358;
    }
    // 0x8040D340: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8040D344: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D348: jal         0x8040E254
    // 0x8040D34C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040E254(rdram, ctx);
        goto after_4;
    // 0x8040D34C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x8040D350: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8040D354: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_8040D358:
    // 0x8040D358: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_8040D35C:
    // 0x8040D35C: bnel        $v0, $at, L_8040D370
    if (ctx->r2 != ctx->r1) {
        // 0x8040D360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040D370;
    }
    goto skip_6;
    // 0x8040D360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8040D364: jal         0x8040D164
    // 0x8040D368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040D164(rdram, ctx);
        goto after_5;
    // 0x8040D368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8040D36C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040D370:
    // 0x8040D370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040D374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040D378: jr          $ra
    // 0x8040D37C: nop

    return;
    // 0x8040D37C: nop

;}
RECOMP_FUNC void func_8067414C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067414C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80674154: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80674158: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X1B74) << 16);
    // 0x8067415C: addiu       $t8, $t8, 0x4B54
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(529, 0X1B74));
    // 0x80674160: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80674164: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80674168: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8067416C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80674170: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80674174: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80674178: beql        $v1, $zero, L_806741AC
    if (ctx->r3 == 0) {
        // 0x8067417C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806741AC;
    }
    goto skip_0;
    // 0x8067417C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80674180: jalr        $v1
    // 0x80674184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80674184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80674188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067418C: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80674190: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x80674194: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80674198: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8067419C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x806741A0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x806741A4: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x806741A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806741AC:
    // 0x806741AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806741B0: jr          $ra
    // 0x806741B4: nop

    return;
    // 0x806741B4: nop

;}
RECOMP_FUNC void func_8006B7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B7D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8006B7DC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006B7E0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8006B7E4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8006B7E8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8006B7EC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006B7F0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006B7F4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006B7F8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006B7FC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006B800: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006B804: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8006B808: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8006B80C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x8006B810: lh          $s0, 0x8A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X8A);
    // 0x8006B814: sll         $s7, $a2, 16
    ctx->r23 = S32(ctx->r6 << 16);
    // 0x8006B818: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8006B81C: lh          $t8, 0x16($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X16);
    // 0x8006B820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B824: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8006B828: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8006B82C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x8006B830: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x8006B834: bne         $s0, $v0, L_8006B8EC
    if (ctx->r16 != ctx->r2) {
        // 0x8006B838: sh          $t8, 0x6A($sp)
        MEM_H(0X6A, ctx->r29) = ctx->r24;
            goto L_8006B8EC;
    }
    // 0x8006B838: sh          $t8, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r24;
    // 0x8006B83C: lh          $s3, 0x8E($sp)
    ctx->r19 = MEM_H(ctx->r29, 0X8E);
    // 0x8006B840: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x8006B844: lh          $s4, 0x86($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X86);
    // 0x8006B848: beq         $s3, $zero, L_8006BAD4
    if (ctx->r19 == 0) {
        // 0x8006B84C: sll         $a2, $s4, 16
        ctx->r6 = S32(ctx->r20 << 16);
            goto L_8006BAD4;
    }
L_8006B84C:
    // 0x8006B84C: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x8006B850: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x8006B854: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B858: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B85C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8006B860: jal         0x8006B6E4
    // 0x8006B864: addiu       $a1, $sp, 0x5A
    ctx->r5 = ADD32(ctx->r29, 0X5A);
    func_8006B6E4(rdram, ctx);
        goto after_0;
    // 0x8006B864: addiu       $a1, $sp, 0x5A
    ctx->r5 = ADD32(ctx->r29, 0X5A);
    after_0:
    // 0x8006B868: beq         $v0, $zero, L_8006B880
    if (ctx->r2 == 0) {
        // 0x8006B86C: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006B880;
    }
    // 0x8006B86C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B870: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x8006B874: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x8006B878: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x8006B87C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
L_8006B880:
    // 0x8006B880: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8006B884: addiu       $a2, $sp, 0x56
    ctx->r6 = ADD32(ctx->r29, 0X56);
    // 0x8006B888: lh          $a3, 0x82($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X82);
    // 0x8006B88C: jal         0x8006AB7C
    // 0x8006B890: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_8006AB7C(rdram, ctx);
        goto after_1;
    // 0x8006B890: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_1:
    // 0x8006B894: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006B898: beq         $v0, $at, L_8006B8C8
    if (ctx->r2 == ctx->r1) {
        // 0x8006B89C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8006B8C8;
    }
    // 0x8006B89C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006B8A0: lh          $t9, 0x58($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X58);
    // 0x8006B8A4: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x8006B8A8: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x8006B8AC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006B8B0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8006B8B4: lh          $a3, 0x6A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X6A);
    // 0x8006B8B8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x8006B8BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006B8C0: jal         0x8006B454
    // 0x8006B8C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_8006B454(rdram, ctx);
        goto after_2;
    // 0x8006B8C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
L_8006B8C8:
    // 0x8006B8C8: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x8006B8CC: sll         $t1, $s3, 1
    ctx->r9 = S32(ctx->r19 << 1);
    // 0x8006B8D0: addu        $s2, $s2, $t1
    ctx->r18 = ADD32(ctx->r18, ctx->r9);
    // 0x8006B8D4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8006B8D8: lh          $s4, 0x5C($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X5C);
    // 0x8006B8DC: bne         $v0, $zero, L_8006B84C
    if (ctx->r2 != 0) {
        // 0x8006B8E0: sra         $s3, $s3, 16
        ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
            goto L_8006B84C;
    }
    // 0x8006B8E0: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8006B8E4: b           L_8006BAD4
    // 0x8006B8E8: sh          $s4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r20;
        goto L_8006BAD4;
    // 0x8006B8E8: sh          $s4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r20;
L_8006B8EC:
    // 0x8006B8EC: lh          $s3, 0x8E($sp)
    ctx->r19 = MEM_H(ctx->r29, 0X8E);
    // 0x8006B8F0: bne         $s3, $v0, L_8006B9A8
    if (ctx->r19 != ctx->r2) {
        // 0x8006B8F4: nop
    
            goto L_8006B9A8;
    }
    // 0x8006B8F4: nop

    // 0x8006B8F8: beq         $s0, $zero, L_8006BAD4
    if (ctx->r16 == 0) {
        // 0x8006B8FC: addiu       $fp, $sp, 0x58
        ctx->r30 = ADD32(ctx->r29, 0X58);
            goto L_8006BAD4;
    }
    // 0x8006B8FC: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x8006B900: addiu       $s6, $sp, 0x5E
    ctx->r22 = ADD32(ctx->r29, 0X5E);
    // 0x8006B904: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x8006B908: lh          $s4, 0x86($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X86);
L_8006B90C:
    // 0x8006B90C: lh          $s0, 0x8A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X8A);
    // 0x8006B910: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x8006B914: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8006B918: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x8006B91C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B920: jal         0x8006B6E4
    // 0x8006B924: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_8006B6E4(rdram, ctx);
        goto after_3;
    // 0x8006B924: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x8006B928: beq         $v0, $zero, L_8006B940
    if (ctx->r2 == 0) {
        // 0x8006B92C: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_8006B940;
    }
    // 0x8006B92C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8006B930: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
    // 0x8006B934: lh          $t2, 0x8A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X8A);
    // 0x8006B938: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x8006B93C: sh          $t3, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r11;
L_8006B940:
    // 0x8006B940: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B944: addiu       $a2, $sp, 0x56
    ctx->r6 = ADD32(ctx->r29, 0X56);
    // 0x8006B948: lh          $a3, 0x82($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X82);
    // 0x8006B94C: jal         0x8006AB7C
    // 0x8006B950: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_8006AB7C(rdram, ctx);
        goto after_4;
    // 0x8006B950: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_4:
    // 0x8006B954: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006B958: beq         $v0, $at, L_8006B980
    if (ctx->r2 == ctx->r1) {
        // 0x8006B95C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8006B980;
    }
    // 0x8006B95C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006B960: lh          $t4, 0x56($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X56);
    // 0x8006B964: lh          $t5, 0x8A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8A);
    // 0x8006B968: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8006B96C: lh          $a2, 0x6A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6A);
    // 0x8006B970: lh          $a3, 0x58($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X58);
    // 0x8006B974: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8006B978: jal         0x8006B554
    // 0x8006B97C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_8006B554(rdram, ctx);
        goto after_5;
    // 0x8006B97C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_5:
L_8006B980:
    // 0x8006B980: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x8006B984: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
    // 0x8006B988: lh          $a2, 0x60($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X60);
    // 0x8006B98C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006B990: addu        $s2, $s2, $t7
    ctx->r18 = ADD32(ctx->r18, ctx->r15);
    // 0x8006B994: sh          $v0, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r2;
    // 0x8006B998: bne         $v0, $zero, L_8006B90C
    if (ctx->r2 != 0) {
        // 0x8006B99C: sh          $a2, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r6;
            goto L_8006B90C;
    }
    // 0x8006B99C: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    // 0x8006B9A0: b           L_8006BAD8
    // 0x8006B9A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8006BAD8;
    // 0x8006B9A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8006B9A8:
    // 0x8006B9A8: beq         $s3, $zero, L_8006BAD4
    if (ctx->r19 == 0) {
        // 0x8006B9AC: addiu       $fp, $sp, 0x58
        ctx->r30 = ADD32(ctx->r29, 0X58);
            goto L_8006BAD4;
    }
    // 0x8006B9AC: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x8006B9B0: addiu       $s6, $sp, 0x5E
    ctx->r22 = ADD32(ctx->r29, 0X5E);
    // 0x8006B9B4: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x8006B9B8: lh          $s4, 0x86($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X86);
L_8006B9BC:
    // 0x8006B9BC: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x8006B9C0: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x8006B9C4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B9C8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B9CC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8006B9D0: addiu       $a1, $sp, 0x5A
    ctx->r5 = ADD32(ctx->r29, 0X5A);
    // 0x8006B9D4: lh          $s1, 0x82($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X82);
    // 0x8006B9D8: jal         0x8006B6E4
    // 0x8006B9DC: lh          $s0, 0x8A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X8A);
    func_8006B6E4(rdram, ctx);
        goto after_6;
    // 0x8006B9DC: lh          $s0, 0x8A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X8A);
    after_6:
    // 0x8006B9E0: beql        $v0, $zero, L_8006B9FC
    if (ctx->r2 == 0) {
        // 0x8006B9E4: lh          $t8, 0x8A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X8A);
            goto L_8006B9FC;
    }
    goto skip_0;
    // 0x8006B9E4: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    skip_0:
    // 0x8006B9E8: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x8006B9EC: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x8006B9F0: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x8006B9F4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8006B9F8: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
L_8006B9FC:
    // 0x8006B9FC: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x8006BA00: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x8006BA04: beq         $t8, $zero, L_8006BAAC
    if (ctx->r24 == 0) {
        // 0x8006BA08: sll         $a2, $s1, 16
        ctx->r6 = S32(ctx->r17 << 16);
            goto L_8006BAAC;
    }
L_8006BA08:
    // 0x8006BA08: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x8006BA0C: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x8006BA10: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006BA14: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006BA18: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8006BA1C: jal         0x8006B6E4
    // 0x8006BA20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_8006B6E4(rdram, ctx);
        goto after_7;
    // 0x8006BA20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
    // 0x8006BA24: beq         $v0, $zero, L_8006BA3C
    if (ctx->r2 == 0) {
        // 0x8006BA28: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006BA3C;
    }
    // 0x8006BA28: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BA2C: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
    // 0x8006BA30: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x8006BA34: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006BA38: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8006BA3C:
    // 0x8006BA3C: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x8006BA40: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006BA44: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8006BA48: addiu       $a2, $sp, 0x56
    ctx->r6 = ADD32(ctx->r29, 0X56);
    // 0x8006BA4C: jal         0x8006AB7C
    // 0x8006BA50: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_8006AB7C(rdram, ctx);
        goto after_8;
    // 0x8006BA50: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_8:
    // 0x8006BA54: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006BA58: beq         $v0, $at, L_8006BA8C
    if (ctx->r2 == ctx->r1) {
        // 0x8006BA5C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8006BA8C;
    }
    // 0x8006BA5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006BA60: lh          $t9, 0x58($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X58);
    // 0x8006BA64: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x8006BA68: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x8006BA6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006BA70: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8006BA74: lh          $a3, 0x6A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X6A);
    // 0x8006BA78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BA7C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006BA80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006BA84: jal         0x8006B620
    // 0x8006BA88: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_8006B620(rdram, ctx);
        goto after_9;
    // 0x8006BA88: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_9:
L_8006BA8C:
    // 0x8006BA8C: lh          $v0, 0x5E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5E);
    // 0x8006BA90: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8006BA94: addu        $s2, $s2, $t1
    ctx->r18 = ADD32(ctx->r18, ctx->r9);
    // 0x8006BA98: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8006BA9C: lh          $s1, 0x60($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X60);
    // 0x8006BAA0: bne         $v0, $zero, L_8006BA08
    if (ctx->r2 != 0) {
        // 0x8006BAA4: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_8006BA08;
    }
    // 0x8006BAA4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006BAA8: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
L_8006BAAC:
    // 0x8006BAAC: multu       $s7, $s3
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BAB0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8006BAB4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8006BAB8: lh          $s4, 0x5C($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X5C);
    // 0x8006BABC: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8006BAC0: mflo        $t2
    ctx->r10 = lo;
    // 0x8006BAC4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8006BAC8: bne         $v0, $zero, L_8006B9BC
    if (ctx->r2 != 0) {
        // 0x8006BACC: addu        $s2, $t3, $t4
        ctx->r18 = ADD32(ctx->r11, ctx->r12);
            goto L_8006B9BC;
    }
    // 0x8006BACC: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x8006BAD0: sh          $s4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r20;
L_8006BAD4:
    // 0x8006BAD4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8006BAD8:
    // 0x8006BAD8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006BADC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BAE0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006BAE4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006BAE8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006BAEC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006BAF0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8006BAF4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8006BAF8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8006BAFC: jr          $ra
    // 0x8006BB00: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8006BB00: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8001E834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E83C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E840: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E844: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x8001E848: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001E84C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001E850: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x8001E854: bnel        $t7, $zero, L_8001E884
    if (ctx->r15 != 0) {
        // 0x8001E858: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8001E884;
    }
    goto skip_0;
    // 0x8001E858: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8001E85C: lw          $t8, 0x34($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X34);
    // 0x8001E860: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x8001E864: bnel        $t9, $zero, L_8001E884
    if (ctx->r25 != 0) {
        // 0x8001E868: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8001E884;
    }
    goto skip_1;
    // 0x8001E868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8001E86C: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8001E870: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E874: lbu         $t1, 0x12($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X12);
    // 0x8001E878: beq         $t1, $zero, L_8001E9AC
    if (ctx->r9 == 0) {
        // 0x8001E87C: nop
    
            goto L_8001E9AC;
    }
    // 0x8001E87C: nop

    // 0x8001E880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8001E884:
    // 0x8001E884: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001E888: jal         0x8001E478
    // 0x8001E88C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8001E478(rdram, ctx);
        goto after_0;
    // 0x8001E88C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001E890: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E894: lwc1        $f4, -0x430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X430);
    // 0x8001E898: lwc1        $f0, 0xDC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8001E89C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001E8A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E8A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001E8A8: nop

    // 0x8001E8AC: bc1tl       L_8001E914
    if (c1cs) {
        // 0x8001E8B0: lwc1        $f8, 0x12C0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X12C0);
            goto L_8001E914;
    }
    goto skip_2;
    // 0x8001E8B0: lwc1        $f8, 0x12C0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C0);
    skip_2:
    // 0x8001E8B4: lwc1        $f6, -0x42C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42C);
    // 0x8001E8B8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8001E8BC: nop

    // 0x8001E8C0: bc1tl       L_8001E914
    if (c1cs) {
        // 0x8001E8C4: lwc1        $f8, 0x12C0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X12C0);
            goto L_8001E914;
    }
    goto skip_3;
    // 0x8001E8C4: lwc1        $f8, 0x12C0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C0);
    skip_3:
    // 0x8001E8C8: lbu         $t2, 0x18($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X18);
    // 0x8001E8CC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8001E8D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E8D4: bnel        $t2, $at, L_8001E8F0
    if (ctx->r10 != ctx->r1) {
        // 0x8001E8D8: lbu         $t3, 0x30($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X30);
            goto L_8001E8F0;
    }
    goto skip_4;
    // 0x8001E8D8: lbu         $t3, 0x30($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X30);
    skip_4:
    // 0x8001E8DC: jal         0x8001E324
    // 0x8001E8E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_1;
    // 0x8001E8E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8001E8E4: b           L_8001E9BC
    // 0x8001E8E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8001E9BC;
    // 0x8001E8E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001E8EC: lbu         $t3, 0x30($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X30);
L_8001E8F0:
    // 0x8001E8F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E8F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E8F8: beql        $t3, $at, L_8001E9BC
    if (ctx->r11 == ctx->r1) {
        // 0x8001E8FC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8001E9BC;
    }
    goto skip_5;
    // 0x8001E8FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_5:
    // 0x8001E900: jal         0x8001E324
    // 0x8001E904: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_2;
    // 0x8001E904: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8001E908: b           L_8001E9BC
    // 0x8001E90C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8001E9BC;
    // 0x8001E90C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001E910: lwc1        $f8, 0x12C0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C0);
L_8001E914:
    // 0x8001E914: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E918: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001E91C: jal         0x80065954
    // 0x8001E920: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8001E920: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_3:
    // 0x8001E924: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001E928: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001E92C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001E930: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001E934: nop

    // 0x8001E938: bc1tl       L_8001E978
    if (c1cs) {
        // 0x8001E93C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8001E978;
    }
    goto skip_6;
    // 0x8001E93C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_6:
    // 0x8001E940: lwc1        $f18, 0x12C4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C4);
    // 0x8001E944: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E948: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001E94C: jal         0x80065954
    // 0x8001E950: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8001E950: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_4:
    // 0x8001E954: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E958: lwc1        $f6, -0x428($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X428);
    // 0x8001E95C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001E960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001E964: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8001E968: nop

    // 0x8001E96C: bc1f        L_8001E988
    if (!c1cs) {
        // 0x8001E970: nop
    
            goto L_8001E988;
    }
    // 0x8001E970: nop

    // 0x8001E974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8001E978:
    // 0x8001E978: jal         0x8001E324
    // 0x8001E97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_5;
    // 0x8001E97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8001E980: b           L_8001E9BC
    // 0x8001E984: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8001E9BC;
    // 0x8001E984: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8001E988:
    // 0x8001E988: jal         0x8001E674
    // 0x8001E98C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8001E674(rdram, ctx);
        goto after_6;
    // 0x8001E98C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_6:
    // 0x8001E990: beq         $v0, $zero, L_8001E9B8
    if (ctx->r2 == 0) {
        // 0x8001E994: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8001E9B8;
    }
    // 0x8001E994: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001E998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E99C: jal         0x8001E324
    // 0x8001E9A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_7;
    // 0x8001E9A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8001E9A4: b           L_8001E9BC
    // 0x8001E9A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8001E9BC;
    // 0x8001E9A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8001E9AC:
    // 0x8001E9AC: jal         0x8001E324
    // 0x8001E9B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_8;
    // 0x8001E9B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8001E9B4: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_8001E9B8:
    // 0x8001E9B8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8001E9BC:
    // 0x8001E9BC: sb          $t4, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = ctx->r12;
    // 0x8001E9C0: lw          $t5, 0x174($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X174);
    // 0x8001E9C4: lbu         $t6, 0x12($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X12);
    // 0x8001E9C8: bnel        $t6, $zero, L_8001EA14
    if (ctx->r14 != 0) {
        // 0x8001E9CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001EA14;
    }
    goto skip_7;
    // 0x8001E9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8001E9D0: jal         0x80065954
    // 0x8001E9D4: lwc1        $f12, 0xC4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC4);
    func_80065954(rdram, ctx);
        goto after_9;
    // 0x8001E9D4: lwc1        $f12, 0xC4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC4);
    after_9:
    // 0x8001E9D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E9DC: lwc1        $f14, -0x424($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X424);
    // 0x8001E9E0: lui         $at, 0x3EC0
    ctx->r1 = S32(0X3EC0 << 16);
    // 0x8001E9E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001E9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001E9EC: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001E9F0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8001E9F4: nop

    // 0x8001E9F8: bc1fl       L_8001EA08
    if (!c1cs) {
        // 0x8001E9FC: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_8001EA08;
    }
    goto skip_8;
    // 0x8001E9FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_8:
    // 0x8001EA00: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8001EA04: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_8001EA08:
    // 0x8001EA08: jal         0x8001E70C
    // 0x8001EA0C: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    func_8001E70C(rdram, ctx);
        goto after_10;
    // 0x8001EA0C: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    after_10:
    // 0x8001EA10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EA14:
    // 0x8001EA14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001EA18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001EA1C: jr          $ra
    // 0x8001EA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001EA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80441D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441D98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80441D9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80441DA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80441DA4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80441DA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80441DAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80441DB0: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80441DB4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80441DB8: addiu       $a1, $zero, 0x2638
    ctx->r5 = ADD32(0, 0X2638);
    // 0x80441DBC: addiu       $s3, $a3, 0x1C30
    ctx->r19 = ADD32(ctx->r7, 0X1C30);
    // 0x80441DC0: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80441DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80441DC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80441DCC: jal         0x800657CC
    // 0x80441DD0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x80441DD0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80441DD4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80441DD8: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80441DDC: addiu       $s0, $zero, 0x95
    ctx->r16 = ADD32(0, 0X95);
    // 0x80441DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80441DE4: swc1        $f4, 0x1C78($a3)
    MEM_W(0X1C78, ctx->r7) = ctx->f4.u32l;
    // 0x80441DE8: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80441DEC: addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // 0x80441DF0: swc1        $f6, 0x1C7C($a3)
    MEM_W(0X1C7C, ctx->r7) = ctx->f6.u32l;
L_80441DF4:
    // 0x80441DF4: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80441DF8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80441DFC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80441E00: swc1        $f8, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f8.u32l;
    // 0x80441E04: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80441E08: bgez        $s0, L_80441DF4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80441E0C: swc1        $f10, -0x2C($v0)
        MEM_W(-0X2C, ctx->r2) = ctx->f10.u32l;
            goto L_80441DF4;
    }
    // 0x80441E0C: swc1        $f10, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f10.u32l;
    // 0x80441E10: jal         0x8043F240
    // 0x80441E14: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8043F240(rdram, ctx);
        goto after_1;
    // 0x80441E14: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80441E18: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EE4) << 16);
    // 0x80441E1C: lwc1        $f0, 0x3DE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EE4));
    // 0x80441E20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80441E24: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EE8) << 16);
    // 0x80441E28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80441E2C: swc1        $f0, 0x1C24($a3)
    MEM_W(0X1C24, ctx->r7) = ctx->f0.u32l;
    // 0x80441E30: swc1        $f0, 0x1C28($a3)
    MEM_W(0X1C28, ctx->r7) = ctx->f0.u32l;
    // 0x80441E34: lwc1        $f16, 0x3DE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EE8));
    // 0x80441E38: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80441E3C: addiu       $s0, $zero, 0x95
    ctx->r16 = ADD32(0, 0X95);
    // 0x80441E40: sw          $t6, 0x1C70($a3)
    MEM_W(0X1C70, ctx->r7) = ctx->r14;
    // 0x80441E44: sw          $zero, 0x1C90($a3)
    MEM_W(0X1C90, ctx->r7) = 0;
    // 0x80441E48: sw          $t7, 0x262C($a3)
    MEM_W(0X262C, ctx->r7) = ctx->r15;
    // 0x80441E4C: addiu       $s1, $a3, 0x1BF0
    ctx->r17 = ADD32(ctx->r7, 0X1BF0);
    // 0x80441E50: swc1        $f16, 0x1C2C($a3)
    MEM_W(0X1C2C, ctx->r7) = ctx->f16.u32l;
L_80441E54:
    // 0x80441E54: jal         0x800653D8
    // 0x80441E58: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x80441E58: nop

    after_2:
    // 0x80441E5C: bgez        $v0, L_80441E70
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80441E60: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_80441E70;
    }
    // 0x80441E60: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80441E64: beq         $t8, $zero, L_80441E70
    if (ctx->r24 == 0) {
        // 0x80441E68: nop
    
            goto L_80441E70;
    }
    // 0x80441E68: nop

    // 0x80441E6C: addiu       $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
L_80441E70:
    // 0x80441E70: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80441E74: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80441E78: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x80441E7C: addiu       $s1, $s1, -0x30
    ctx->r17 = ADD32(ctx->r17, -0X30);
    // 0x80441E80: bgez        $s0, L_80441E54
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80441E84: sw          $t0, 0x50($s1)
        MEM_W(0X50, ctx->r17) = ctx->r8;
            goto L_80441E54;
    }
    // 0x80441E84: sw          $t0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r8;
    // 0x80441E88: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_80441E8C:
    // 0x80441E8C: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    // 0x80441E90: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80441E94: bgez        $s0, L_80441E8C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80441E98: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80441E8C;
    }
    // 0x80441E98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80441E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80441EA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80441EA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80441EA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80441EAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80441EB0: jr          $ra
    // 0x80441EB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80441EB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807A00AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A00AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A00B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A00B4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807A00B8: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(838, 0X16B4) << 16);
    // 0x807A00BC: addiu       $t6, $t6, 0xD14
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(838, 0X16B4));
    // 0x807A00C0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807A00C4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807A00C8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807A00CC: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x807A00D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A00D4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807A00D8: jal         0x807A0380
    // 0x807A00DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807A0380(rdram, ctx);
        goto after_0;
    // 0x807A00DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x807A00E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A00E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807A00E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807A00EC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x807A00F0: jr          $ra
    // 0x807A00F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807A00F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80736C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736C10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80736C14: jal         0x80045A34
    // 0x80736C18: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80736C18: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80736C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80736C20: bne         $v0, $zero, L_80736C30
    if (ctx->r2 != 0) {
        // 0x80736C24: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80736C30;
    }
    // 0x80736C24: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80736C28: b           L_80736C3C
    // 0x80736C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80736C3C;
    // 0x80736C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736C30:
    // 0x80736C30: jal         0x80736BBC
    // 0x80736C34: nop

    func_80736BBC(rdram, ctx);
        goto after_1;
    // 0x80736C34: nop

    after_1:
    // 0x80736C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80736C3C:
    // 0x80736C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736C44: jr          $ra
    // 0x80736C48: nop

    return;
    // 0x80736C48: nop

;}
RECOMP_FUNC void func_80580FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580FAC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80580FB0: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(399, 0X4634) << 16);
    // 0x80580FB4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80580FB8: addiu       $t6, $t6, 0x3444
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(399, 0X4634));
    // 0x80580FBC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80580FC0: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80580FC4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80580FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580FD0: jal         0x80580F6C
    // 0x80580FD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80580F6C(rdram, ctx);
        goto after_0;
    // 0x80580FD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80580FD8: jal         0x80580F30
    // 0x80580FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80580F30(rdram, ctx);
        goto after_1;
    // 0x80580FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80580FE0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80580FE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80580FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580FEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80580FF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80580FF4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80580FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80580FFC: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80581000: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80581004: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80581008: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8058100C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581010: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80581014: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80581018: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8058101C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80581020: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80581024: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x80581028: sb          $t8, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r24;
    // 0x8058102C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80581030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581038: jr          $ra
    // 0x8058103C: nop

    return;
    // 0x8058103C: nop

;}
RECOMP_FUNC void func_804B92FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B92FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804B9300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9304: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804B9308: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804B930C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804B9310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B9314: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x804B9318: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804B931C: lw          $t8, 0x320($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X320);
    // 0x804B9320: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804B9324: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x804B9328: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x804B932C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804B9330: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x804B9334: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x804B9338: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x804B933C: lw          $t1, 0x168($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X168);
    // 0x804B9340: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804B9344: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x804B9348: jal         0x80077338
    // 0x804B934C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x804B934C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_0:
    // 0x804B9350: jal         0x80058958
    // 0x804B9354: nop

    func_80058958(rdram, ctx);
        goto after_1;
    // 0x804B9354: nop

    after_1:
    // 0x804B9358: beq         $v0, $zero, L_804B93B8
    if (ctx->r2 == 0) {
        // 0x804B935C: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_804B93B8;
    }
    // 0x804B935C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804B9360: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804B9364: lw          $t3, -0x7BC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7BC4);
    // 0x804B9368: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x804B936C: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x804B9370: lw          $t4, 0x10C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10C);
    // 0x804B9374: ori         $t9, $t9, 0xFE23
    ctx->r25 = ctx->r25 | 0XFE23;
    // 0x804B9378: addiu       $t0, $zero, -0xC07
    ctx->r8 = ADD32(0, -0XC07);
    // 0x804B937C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x804B9380: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x804B9384: beq         $t6, $zero, L_804B93B8
    if (ctx->r14 == 0) {
        // 0x804B9388: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_804B93B8;
    }
    // 0x804B9388: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804B938C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x804B9390: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x804B9394: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804B9398: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804B939C: lui         $t4, 0x7A84
    ctx->r12 = S32(0X7A84 << 16);
    // 0x804B93A0: ori         $t4, $t4, 0x7AFF
    ctx->r12 = ctx->r12 | 0X7AFF;
    // 0x804B93A4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x804B93A8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x804B93AC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x804B93B0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x804B93B4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_804B93B8:
    // 0x804B93B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804B93BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B93C0: jal         0x8007711C
    // 0x804B93C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x804B93C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x804B93C8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x804B93CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804B93D0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x804B93D4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x804B93D8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x804B93DC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x804B93E0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x804B93E4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804B93E8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x804B93EC: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x804B93F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B93F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804B93F8: jr          $ra
    // 0x804B93FC: nop

    return;
    // 0x804B93FC: nop

;}
RECOMP_FUNC void func_800621A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800621A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800621AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800621B0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800621B4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800621B8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800621BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800621C0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800621C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800621C8: sw          $t6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r14;
    // 0x800621CC: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800621D0: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800621D4: sh          $t7, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r15;
    // 0x800621D8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800621DC: lh          $t9, 0x56($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X56);
    // 0x800621E0: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800621E4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800621E8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800621EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800621F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800621F4: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800621F8: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800621FC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80062200: swc1        $f16, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f16.u32l;
    // 0x80062204: jal         0x8005FFB4
    // 0x80062208: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    func_8005FFB4(rdram, ctx);
        goto after_0;
    // 0x80062208: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x8006220C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80062210: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80062214: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80062218: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8006221C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80062220: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80062224: lh          $t0, 0x52($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X52);
    // 0x80062228: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x8006222C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80062230: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80062234: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80062238: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8006223C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80062240: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x80062244: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80062248: lwc1        $f8, 0x8C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8006224C: lh          $t2, 0x54($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X54);
    // 0x80062250: lw          $t3, 0x70($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X70);
    // 0x80062254: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80062258: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8006225C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80062260: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80062264: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80062268: beq         $a0, $zero, L_80062340
    if (ctx->r4 == 0) {
        // 0x8006226C: swc1        $f16, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
            goto L_80062340;
    }
    // 0x8006226C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80062270: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    // 0x80062274: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80062278: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x8006227C: beq         $t4, $zero, L_80062340
    if (ctx->r12 == 0) {
        // 0x80062280: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80062340;
    }
    // 0x80062280: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062284: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80062288: lwc1        $f22, 0xD68($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0XD68);
    // 0x8006228C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80062290:
    // 0x80062290: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062294: beql        $v1, $zero, L_8006232C
    if (ctx->r3 == 0) {
        // 0x80062298: addiu       $t6, $v0, 0x4
        ctx->r14 = ADD32(ctx->r2, 0X4);
            goto L_8006232C;
    }
    goto skip_0;
    // 0x80062298: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x8006229C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800622A0: beql        $t5, $v1, L_80062318
    if (ctx->r13 == ctx->r3) {
        // 0x800622A4: lh          $t4, 0x78($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X78);
            goto L_80062318;
    }
    goto skip_1;
    // 0x800622A4: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    skip_1:
    // 0x800622A8: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x800622AC: lw          $t6, 0x174($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X174);
    // 0x800622B0: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x800622B4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800622B8: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x800622BC: bnel        $t9, $zero, L_80062318
    if (ctx->r25 != 0) {
        // 0x800622C0: lh          $t4, 0x78($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X78);
            goto L_80062318;
    }
    goto skip_2;
    // 0x800622C0: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    skip_2:
    // 0x800622C4: lbu         $t0, 0x5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X5);
    // 0x800622C8: beq         $t0, $zero, L_800622DC
    if (ctx->r8 == 0) {
        // 0x800622CC: nop
    
            goto L_800622DC;
    }
    // 0x800622CC: nop

    // 0x800622D0: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
    // 0x800622D4: beql        $t1, $zero, L_80062318
    if (ctx->r9 == 0) {
        // 0x800622D8: lh          $t4, 0x78($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X78);
            goto L_80062318;
    }
    goto skip_3;
    // 0x800622D8: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    skip_3:
L_800622DC:
    // 0x800622DC: jal         0x80060960
    // 0x800622E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060960(rdram, ctx);
        goto after_1;
    // 0x800622E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800622E4: beql        $v0, $zero, L_80062318
    if (ctx->r2 == 0) {
        // 0x800622E8: lh          $t4, 0x78($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X78);
            goto L_80062318;
    }
    goto skip_4;
    // 0x800622E8: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    skip_4:
    // 0x800622EC: jal         0x80060ED0
    // 0x800622F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ED0(rdram, ctx);
        goto after_2;
    // 0x800622F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800622F4: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x800622F8: swc1        $f20, 0x120($t2)
    MEM_W(0X120, ctx->r10) = ctx->f20.u32l;
    // 0x800622FC: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x80062300: swc1        $f20, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f20.u32l;
    // 0x80062304: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80062308: lwc1        $f18, 0xC4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8006230C: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80062310: swc1        $f6, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f6.u32l;
    // 0x80062314: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
L_80062318:
    // 0x80062318: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x8006231C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80062320: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80062324: sh          $t5, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r13;
    // 0x80062328: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
L_8006232C:
    // 0x8006232C: beq         $a0, $zero, L_80062340
    if (ctx->r4 == 0) {
        // 0x80062330: sw          $t6, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r14;
            goto L_80062340;
    }
    // 0x80062330: sw          $t6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r14;
    // 0x80062334: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    // 0x80062338: bnel        $t7, $zero, L_80062290
    if (ctx->r15 != 0) {
        // 0x8006233C: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_80062290;
    }
    goto skip_5;
    // 0x8006233C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_5:
L_80062340:
    // 0x80062340: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80062344: lh          $t9, 0x184($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X184);
    // 0x80062348: beql        $t9, $zero, L_80062364
    if (ctx->r25 == 0) {
        // 0x8006234C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80062364;
    }
    goto skip_6;
    // 0x8006234C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x80062350: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80062354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062358: jalr        $t9
    // 0x8006235C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8006235C: nop

    after_3:
    // 0x80062360: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80062364:
    // 0x80062364: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80062368: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8006236C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80062370: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80062374: jr          $ra
    // 0x80062378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80062378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001D560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D56C: jal         0x80045A34
    // 0x8001D570: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8001D570: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_0:
    // 0x8001D574: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8001D578: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8001D57C: bne         $v0, $zero, L_8001D594
    if (ctx->r2 != 0) {
        // 0x8001D580: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8001D594;
    }
    // 0x8001D580: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8001D584: jal         0x800445A4
    // 0x8001D588: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8001D588: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8001D58C: b           L_8001D5A4
    // 0x8001D590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001D5A4;
    // 0x8001D590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001D594:
    // 0x8001D594: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8001D598: jal         0x80065728
    // 0x8001D59C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8001D59C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8001D5A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001D5A4:
    // 0x8001D5A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D5A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D5AC: jr          $ra
    // 0x8001D5B0: nop

    return;
    // 0x8001D5B0: nop

;}
RECOMP_FUNC void func_804E9A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9A70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804E9A74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804E9A78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804E9A7C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x804E9A80: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(264, 0X7FC) << 16);
    // 0x804E9A84: addiu       $t8, $t8, -0x5E94
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(264, 0X7FC));
    // 0x804E9A88: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x804E9A8C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x804E9A90: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x804E9A94: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x804E9A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804E9A9C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x804E9AA0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x804E9AA4: jal         0x80045A34
    // 0x804E9AA8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804E9AA8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    after_0:
    // 0x804E9AAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804E9AB0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804E9AB4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x804E9AB8: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x804E9ABC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804E9AC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x804E9AC4: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x804E9AC8: jal         0x804E9F10
    // 0x804E9ACC: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    func_804E9F10(rdram, ctx);
        goto after_1;
    // 0x804E9ACC: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    after_1:
    // 0x804E9AD0: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x804E9AD4: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x804E9AD8: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x804E9ADC: lui         $t2, 0x804F
    ctx->r10 = S32(RELOC_HI16(264, 0X7BC) << 16);
    // 0x804E9AE0: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x804E9AE4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804E9AE8: addiu       $t2, $t2, -0x5ED4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(264, 0X7BC));
    // 0x804E9AEC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x804E9AF0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804E9AF4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804E9AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804E9AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804E9B00: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804E9B04: jal         0x804E9F98
    // 0x804E9B08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804E9F98(rdram, ctx);
        goto after_2;
    // 0x804E9B08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804E9B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804E9B10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804E9B14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804E9B18: jr          $ra
    // 0x804E9B1C: nop

    return;
    // 0x804E9B1C: nop

;}
RECOMP_FUNC void func_805E4140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4140: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805E4144: addiu       $at, $zero, 0x451C
    ctx->r1 = ADD32(0, 0X451C);
    // 0x805E4148: beq         $v0, $at, L_805E4170
    if (ctx->r2 == ctx->r1) {
        // 0x805E414C: addiu       $at, $zero, 0x451D
        ctx->r1 = ADD32(0, 0X451D);
            goto L_805E4170;
    }
    // 0x805E414C: addiu       $at, $zero, 0x451D
    ctx->r1 = ADD32(0, 0X451D);
    // 0x805E4150: beq         $v0, $at, L_805E417C
    if (ctx->r2 == ctx->r1) {
        // 0x805E4154: addiu       $at, $zero, 0x451E
        ctx->r1 = ADD32(0, 0X451E);
            goto L_805E417C;
    }
    // 0x805E4154: addiu       $at, $zero, 0x451E
    ctx->r1 = ADD32(0, 0X451E);
    // 0x805E4158: beq         $v0, $at, L_805E4188
    if (ctx->r2 == ctx->r1) {
        // 0x805E415C: addiu       $at, $zero, 0x451F
        ctx->r1 = ADD32(0, 0X451F);
            goto L_805E4188;
    }
    // 0x805E415C: addiu       $at, $zero, 0x451F
    ctx->r1 = ADD32(0, 0X451F);
    // 0x805E4160: beq         $v0, $at, L_805E4194
    if (ctx->r2 == ctx->r1) {
        // 0x805E4164: nop
    
            goto L_805E4194;
    }
    // 0x805E4164: nop

    // 0x805E4168: b           L_805E41A0
    // 0x805E416C: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XB0C) << 16);
        goto L_805E41A0;
    // 0x805E416C: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XB0C) << 16);
L_805E4170:
    // 0x805E4170: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XB0C) << 16);
    // 0x805E4174: jr          $ra
    // 0x805E4178: addiu       $v0, $v0, 0x4C4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB0C));
    return;
    // 0x805E4178: addiu       $v0, $v0, 0x4C4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB0C));
L_805E417C:
    // 0x805E417C: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XB40) << 16);
    // 0x805E4180: jr          $ra
    // 0x805E4184: addiu       $v0, $v0, 0x4C80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB40));
    return;
    // 0x805E4184: addiu       $v0, $v0, 0x4C80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB40));
L_805E4188:
    // 0x805E4188: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XB90) << 16);
    // 0x805E418C: jr          $ra
    // 0x805E4190: addiu       $v0, $v0, 0x4CD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB90));
    return;
    // 0x805E4190: addiu       $v0, $v0, 0x4CD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB90));
L_805E4194:
    // 0x805E4194: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(486, 0XBE0) << 16);
    // 0x805E4198: jr          $ra
    // 0x805E419C: addiu       $v0, $v0, 0x4D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XBE0));
    return;
    // 0x805E419C: addiu       $v0, $v0, 0x4D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XBE0));
L_805E41A0:
    // 0x805E41A0: addiu       $v0, $v0, 0x4C4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(486, 0XB0C));
    // 0x805E41A4: jr          $ra
    // 0x805E41A8: nop

    return;
    // 0x805E41A8: nop

;}
RECOMP_FUNC void func_805ACE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACE38: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x805ACE3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ACE40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805ACE44: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805ACE48: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x805ACE4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805ACE50: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805ACE54: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x805ACE58: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x805ACE5C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x805ACE60: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ACE64: jal         0x80045A34
    // 0x805ACE68: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805ACE68: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x805ACE6C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x805ACE70: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805ACE74: bne         $v0, $zero, L_805ACE8C
    if (ctx->r2 != 0) {
        // 0x805ACE78: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_805ACE8C;
    }
    // 0x805ACE78: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805ACE7C: jal         0x800445A4
    // 0x805ACE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805ACE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805ACE84: b           L_805AD208
    // 0x805ACE88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805AD208;
    // 0x805ACE88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACE8C:
    // 0x805ACE8C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x805ACE90: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(441, 0X12F4) << 16);
    // 0x805ACE94: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805ACE98: addiu       $t8, $t8, -0x2B1C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(441, 0X12F4));
    // 0x805ACE9C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805ACEA0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x805ACEA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805ACEA8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x805ACEAC: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x805ACEB0: sw          $t1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r9;
    // 0x805ACEB4: sw          $t2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r10;
    // 0x805ACEB8: lui         $t3, 0x805B
    ctx->r11 = S32(RELOC_HI16(441, 0X654) << 16);
    // 0x805ACEBC: addiu       $t3, $t3, -0x37BC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(441, 0X654));
    // 0x805ACEC0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805ACEC4: sw          $t3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r11;
    // 0x805ACEC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ACECC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x805ACED0: jal         0x805AC7E0
    // 0x805ACED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AC7E0(rdram, ctx);
        goto after_2;
    // 0x805ACED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805ACED8: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x805ACEDC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x805ACEE0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805ACEE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ACEE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805ACEEC: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
    // 0x805ACEF0: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x805ACEF4: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x805ACEF8: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
    // 0x805ACEFC: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x805ACF00: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x805ACF04: swc1        $f0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f0.u32l;
    // 0x805ACF08: beq         $v1, $zero, L_805ACFEC
    if (ctx->r3 == 0) {
        // 0x805ACF0C: swc1        $f0, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
            goto L_805ACFEC;
    }
    // 0x805ACF0C: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x805ACF10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805ACF14: beq         $v1, $at, L_805ACF3C
    if (ctx->r3 == ctx->r1) {
        // 0x805ACF18: addiu       $a1, $a2, 0x200
        ctx->r5 = ADD32(ctx->r6, 0X200);
            goto L_805ACF3C;
    }
    // 0x805ACF18: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    // 0x805ACF1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805ACF20: beq         $v1, $at, L_805ACF78
    if (ctx->r3 == ctx->r1) {
        // 0x805ACF24: addiu       $a1, $a2, 0x400
        ctx->r5 = ADD32(ctx->r6, 0X400);
            goto L_805ACF78;
    }
    // 0x805ACF24: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    // 0x805ACF28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805ACF2C: beq         $v1, $at, L_805ACFB0
    if (ctx->r3 == ctx->r1) {
        // 0x805ACF30: addiu       $a1, $a2, 0x600
        ctx->r5 = ADD32(ctx->r6, 0X600);
            goto L_805ACFB0;
    }
    // 0x805ACF30: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    // 0x805ACF34: b           L_805AD018
    // 0x805ACF38: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
        goto L_805AD018;
    // 0x805ACF38: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805ACF3C:
    // 0x805ACF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACF40: jal         0x8004590C
    // 0x805ACF44: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x805ACF44: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_3:
    // 0x805ACF48: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805ACF4C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805ACF50: addiu       $t4, $zero, 0x2242
    ctx->r12 = ADD32(0, 0X2242);
    // 0x805ACF54: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x805ACF58: addiu       $t7, $zero, 0x2244
    ctx->r15 = ADD32(0, 0X2244);
    // 0x805ACF5C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x805ACF60: sh          $t4, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r12;
    // 0x805ACF64: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805ACF68: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805ACF6C: sh          $t7, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = ctx->r15;
    // 0x805ACF70: b           L_805AD014
    // 0x805ACF74: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
        goto L_805AD014;
    // 0x805ACF74: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
L_805ACF78:
    // 0x805ACF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACF7C: jal         0x8004590C
    // 0x805ACF80: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x805ACF80: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_4:
    // 0x805ACF84: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x805ACF88: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805ACF8C: addiu       $t2, $zero, 0x4222
    ctx->r10 = ADD32(0, 0X4222);
    // 0x805ACF90: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x805ACF94: addiu       $t4, $zero, 0x2244
    ctx->r12 = ADD32(0, 0X2244);
    // 0x805ACF98: sh          $t2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r10;
    // 0x805ACF9C: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x805ACFA0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x805ACFA4: sh          $t4, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = ctx->r12;
    // 0x805ACFA8: b           L_805AD014
    // 0x805ACFAC: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_805AD014;
    // 0x805ACFAC: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_805ACFB0:
    // 0x805ACFB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACFB4: jal         0x8004590C
    // 0x805ACFB8: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8004590C(rdram, ctx);
        goto after_5;
    // 0x805ACFB8: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_5:
    // 0x805ACFBC: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x805ACFC0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805ACFC4: addiu       $t7, $zero, 0x2224
    ctx->r15 = ADD32(0, 0X2224);
    // 0x805ACFC8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x805ACFCC: addiu       $t3, $zero, 0x4244
    ctx->r11 = ADD32(0, 0X4244);
    // 0x805ACFD0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x805ACFD4: sh          $t7, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r15;
    // 0x805ACFD8: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x805ACFDC: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x805ACFE0: sh          $t3, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r11;
    // 0x805ACFE4: b           L_805AD014
    // 0x805ACFE8: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
        goto L_805AD014;
    // 0x805ACFE8: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
L_805ACFEC:
    // 0x805ACFEC: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805ACFF0: addiu       $t4, $zero, 0x2422
    ctx->r12 = ADD32(0, 0X2422);
    // 0x805ACFF4: addiu       $t7, $zero, 0x2444
    ctx->r15 = ADD32(0, 0X2444);
    // 0x805ACFF8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805ACFFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x805AD000: sh          $t4, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r12;
    // 0x805AD004: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x805AD008: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805AD00C: sh          $t7, 0x1A($t2)
    MEM_H(0X1A, ctx->r10) = ctx->r15;
    // 0x805AD010: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
L_805AD014:
    // 0x805AD014: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805AD018:
    // 0x805AD018: slti        $at, $v0, 0x45B6
    ctx->r1 = SIGNED(ctx->r2) < 0X45B6 ? 1 : 0;
    // 0x805AD01C: bne         $at, $zero, L_805AD038
    if (ctx->r1 != 0) {
        // 0x805AD020: addiu       $t5, $v0, -0x4198
        ctx->r13 = ADD32(ctx->r2, -0X4198);
            goto L_805AD038;
    }
    // 0x805AD020: addiu       $t5, $v0, -0x4198
    ctx->r13 = ADD32(ctx->r2, -0X4198);
    // 0x805AD024: addiu       $at, $zero, 0x4698
    ctx->r1 = ADD32(0, 0X4698);
    // 0x805AD028: beq         $v0, $at, L_805AD0D0
    if (ctx->r2 == ctx->r1) {
        // 0x805AD02C: lui         $t5, 0x805B
        ctx->r13 = S32(RELOC_HI16(441, 0X12FC) << 16);
            goto L_805AD0D0;
    }
    // 0x805AD02C: lui         $t5, 0x805B
    ctx->r13 = S32(RELOC_HI16(441, 0X12FC) << 16);
    // 0x805AD030: b           L_805AD100
    // 0x805AD034: lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X44);
        goto L_805AD100;
    // 0x805AD034: lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X44);
L_805AD038:
    // 0x805AD038: slti        $at, $v0, 0x419E
    ctx->r1 = SIGNED(ctx->r2) < 0X419E ? 1 : 0;
    // 0x805AD03C: bne         $at, $zero, L_805AD054
    if (ctx->r1 != 0) {
        // 0x805AD040: addiu       $at, $zero, 0x45B5
        ctx->r1 = ADD32(0, 0X45B5);
            goto L_805AD054;
    }
    // 0x805AD040: addiu       $at, $zero, 0x45B5
    ctx->r1 = ADD32(0, 0X45B5);
    // 0x805AD044: beq         $v0, $at, L_805AD0C8
    if (ctx->r2 == ctx->r1) {
        // 0x805AD048: addiu       $t2, $zero, 0x45B6
        ctx->r10 = ADD32(0, 0X45B6);
            goto L_805AD0C8;
    }
    // 0x805AD048: addiu       $t2, $zero, 0x45B6
    ctx->r10 = ADD32(0, 0X45B6);
    // 0x805AD04C: b           L_805AD100
    // 0x805AD050: lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X44);
        goto L_805AD100;
    // 0x805AD050: lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X44);
L_805AD054:
    // 0x805AD054: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x805AD058: beq         $at, $zero, L_805AD0FC
    if (ctx->r1 == 0) {
        // 0x805AD05C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_805AD0FC;
    }
    // 0x805AD05C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x805AD060: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(441, 0X1340) << 16);
    // 0x805AD064: addu        $at, $at, $t5
    gpr jr_addend_805AD06C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x805AD068: lw          $t5, -0x2AD0($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(441, 0X1340));
    // 0x805AD06C: jr          $t5
    // 0x805AD070: nop

    switch (jr_addend_805AD06C >> 2) {
        case 0: goto L_805AD074; break;
        case 1: goto L_805AD080; break;
        case 2: goto L_805AD08C; break;
        case 3: goto L_805AD0A4; break;
        case 4: goto L_805AD0B0; break;
        case 5: goto L_805AD0BC; break;
        default: switch_error(__func__, 0x805AD06C, 0x805AD530);
    }
    // 0x805AD070: nop

L_805AD074:
    // 0x805AD074: addiu       $t6, $zero, 0x4030
    ctx->r14 = ADD32(0, 0X4030);
    // 0x805AD078: b           L_805AD0FC
    // 0x805AD07C: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
        goto L_805AD0FC;
    // 0x805AD07C: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
L_805AD080:
    // 0x805AD080: addiu       $t8, $zero, 0x4031
    ctx->r24 = ADD32(0, 0X4031);
    // 0x805AD084: b           L_805AD0FC
    // 0x805AD088: sh          $t8, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r24;
        goto L_805AD0FC;
    // 0x805AD088: sh          $t8, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r24;
L_805AD08C:
    // 0x805AD08C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(441, 0X1358) << 16);
    // 0x805AD090: lwc1        $f8, -0x2AB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(441, 0X1358));
    // 0x805AD094: addiu       $t4, $zero, 0x4032
    ctx->r12 = ADD32(0, 0X4032);
    // 0x805AD098: sh          $t4, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r12;
    // 0x805AD09C: b           L_805AD0FC
    // 0x805AD0A0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
        goto L_805AD0FC;
    // 0x805AD0A0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_805AD0A4:
    // 0x805AD0A4: addiu       $t9, $zero, 0x4033
    ctx->r25 = ADD32(0, 0X4033);
    // 0x805AD0A8: b           L_805AD0FC
    // 0x805AD0AC: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
        goto L_805AD0FC;
    // 0x805AD0AC: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
L_805AD0B0:
    // 0x805AD0B0: addiu       $t1, $zero, 0x4034
    ctx->r9 = ADD32(0, 0X4034);
    // 0x805AD0B4: b           L_805AD0FC
    // 0x805AD0B8: sh          $t1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r9;
        goto L_805AD0FC;
    // 0x805AD0B8: sh          $t1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r9;
L_805AD0BC:
    // 0x805AD0BC: addiu       $t7, $zero, 0x4035
    ctx->r15 = ADD32(0, 0X4035);
    // 0x805AD0C0: b           L_805AD0FC
    // 0x805AD0C4: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
        goto L_805AD0FC;
    // 0x805AD0C4: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
L_805AD0C8:
    // 0x805AD0C8: b           L_805AD0FC
    // 0x805AD0CC: sh          $t2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r10;
        goto L_805AD0FC;
    // 0x805AD0CC: sh          $t2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r10;
L_805AD0D0:
    // 0x805AD0D0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805AD0D4: lw          $v0, -0x76C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76C0);
    // 0x805AD0D8: bltz        $v0, L_805AD0E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x805AD0DC: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_805AD0E8;
    }
    // 0x805AD0DC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x805AD0E0: bnel        $at, $zero, L_805AD0F0
    if (ctx->r1 != 0) {
        // 0x805AD0E4: sll         $t3, $v0, 1
        ctx->r11 = S32(ctx->r2 << 1);
            goto L_805AD0F0;
    }
    goto skip_0;
    // 0x805AD0E4: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    skip_0:
L_805AD0E8:
    // 0x805AD0E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x805AD0EC: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
L_805AD0F0:
    // 0x805AD0F0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x805AD0F4: lhu         $t5, -0x2B14($t5)
    ctx->r13 = MEM_HU(ctx->r13, (int16_t)RELOC_LO16(441, 0X12FC));
    // 0x805AD0F8: sh          $t5, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r13;
L_805AD0FC:
    // 0x805AD0FC: lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X44);
L_805AD100:
    // 0x805AD100: addiu       $at, $zero, 0x45B6
    ctx->r1 = ADD32(0, 0X45B6);
    // 0x805AD104: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x805AD108: beq         $t6, $at, L_805AD17C
    if (ctx->r14 == ctx->r1) {
        // 0x805AD10C: addiu       $a0, $zero, 0x45B6
        ctx->r4 = ADD32(0, 0X45B6);
            goto L_805AD17C;
    }
    // 0x805AD10C: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    // 0x805AD110: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x805AD114: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AD118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805AD11C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(441, 0X135C) << 16);
    // 0x805AD120: lwc1        $f16, -0x2AB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(441, 0X135C));
    // 0x805AD124: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x805AD128: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x805AD12C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x805AD130: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x805AD134: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x805AD138: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x805AD13C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x805AD140: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x805AD144: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x805AD148: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x805AD14C: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x805AD150: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x805AD154: lw          $t9, 0x54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X54);
    // 0x805AD158: jalr        $t9
    // 0x805AD15C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x805AD15C: nop

    after_6:
    // 0x805AD160: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805AD164: bne         $v0, $zero, L_805AD1E0
    if (ctx->r2 != 0) {
        // 0x805AD168: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_805AD1E0;
    }
    // 0x805AD168: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x805AD16C: jal         0x800445A4
    // 0x805AD170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x805AD170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805AD174: b           L_805AD208
    // 0x805AD178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805AD208;
    // 0x805AD178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AD17C:
    // 0x805AD17C: jal         0x80047090
    // 0x805AD180: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_80047090(rdram, ctx);
        goto after_8;
    // 0x805AD180: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_8:
    // 0x805AD184: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AD188: lui         $at, 0x45B6
    ctx->r1 = S32(0X45B6 << 16);
    // 0x805AD18C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x805AD190: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805AD194: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805AD198: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x805AD19C: jal         0x8004613C
    // 0x805AD1A0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_9;
    // 0x805AD1A0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_9:
    // 0x805AD1A4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805AD1A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AD1AC: bne         $v0, $zero, L_805AD1C4
    if (ctx->r2 != 0) {
        // 0x805AD1B0: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_805AD1C4;
    }
    // 0x805AD1B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x805AD1B4: jal         0x800445A4
    // 0x805AD1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_10;
    // 0x805AD1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805AD1BC: b           L_805AD208
    // 0x805AD1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805AD208;
    // 0x805AD1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AD1C4:
    // 0x805AD1C4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x805AD1C8: jal         0x80047F9C
    // 0x805AD1CC: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x805AD1CC: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_11:
    // 0x805AD1D0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805AD1D4: jal         0x8005FDC4
    // 0x805AD1D8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_8005FDC4(rdram, ctx);
        goto after_12;
    // 0x805AD1D8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_12:
    // 0x805AD1DC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
L_805AD1E0:
    // 0x805AD1E0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x805AD1E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x805AD1E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AD1EC: jal         0x80057978
    // 0x805AD1F0: sb          $t1, 0x17C($t7)
    MEM_B(0X17C, ctx->r15) = ctx->r9;
    func_80057978(rdram, ctx);
        goto after_13;
    // 0x805AD1F0: sb          $t1, 0x17C($t7)
    MEM_B(0X17C, ctx->r15) = ctx->r9;
    after_13:
    // 0x805AD1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AD1F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AD1FC: jal         0x805AD274
    // 0x805AD200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805AD274(rdram, ctx);
        goto after_14;
    // 0x805AD200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x805AD204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AD208:
    // 0x805AD208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AD20C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x805AD210: jr          $ra
    // 0x805AD214: nop

    return;
    // 0x805AD214: nop

;}
RECOMP_FUNC void func_8042A444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042A448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042A44C: jal         0x8042A2EC
    // 0x8042A450: nop

    func_8042A2EC(rdram, ctx);
        goto after_0;
    // 0x8042A450: nop

    after_0:
    // 0x8042A454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042A458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042A45C: jr          $ra
    // 0x8042A460: nop

    return;
    // 0x8042A460: nop

;}
RECOMP_FUNC void func_805ADAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADAAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADAB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805ADAB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADAB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADABC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADAC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADAC4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADAC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADACC: addiu       $t6, $zero, 0x1CD4
    ctx->r14 = ADD32(0, 0X1CD4);
    // 0x805ADAD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADAD4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADAD8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADADC: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x805ADAE0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADAE4: jal         0x805AD70C
    // 0x805ADAE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADAE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADAEC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADAF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADAF8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805ADAFC: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADB00: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805ADB04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADB08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADB0C: jr          $ra
    // 0x805ADB10: nop

    return;
    // 0x805ADB10: nop

;}
RECOMP_FUNC void func_8051F3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F3E8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8051F3EC: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(303, 0X8D0) << 16);
    // 0x8051F3F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8051F3F4: addiu       $t6, $t6, -0x6B0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(303, 0X8D0));
    // 0x8051F3F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8051F3FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051F400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051F404: jal         0x8051F6D0
    // 0x8051F408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8051F6D0(rdram, ctx);
        goto after_0;
    // 0x8051F408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8051F40C: jal         0x8051F454
    // 0x8051F410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8051F454(rdram, ctx);
        goto after_1;
    // 0x8051F410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8051F414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051F418: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8051F41C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8051F420: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x8051F424: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8051F428: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(303, 0X324) << 16);
    // 0x8051F42C: addiu       $t0, $t0, -0xC5C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(303, 0X324));
    // 0x8051F430: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8051F434: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8051F438: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    // 0x8051F43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F440: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8051F444: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051F448: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x8051F44C: jr          $ra
    // 0x8051F450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051F450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805C64F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C64F0: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(447, 0X35A8) << 16);
    // 0x805C64F4: addiu       $v0, $v0, -0x6568
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(447, 0X35A8));
    // 0x805C64F8: jr          $ra
    // 0x805C64FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805C64FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80559814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559814: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80559818: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8055981C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80559820: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80559824: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80559828: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8055982C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80559830: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80559834: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80559838: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8055983C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80559840: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80559844: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80559848: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8055984C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80559850: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80559854: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80559858: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8055985C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80559860: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80559864: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80559868: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8055986C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80559870: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80559874: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80559878: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8055987C: jalr        $t9
    // 0x80559880: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80559880: nop

    after_0:
    // 0x80559884: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80559888: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8055988C: jal         0x800447C8
    // 0x80559890: sb          $t0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r8;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80559890: sb          $t0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r8;
    after_1:
    // 0x80559894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80559898: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8055989C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805598A0: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x805598A4: jr          $ra
    // 0x805598A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805598A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805D80E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D80E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D80E4: lh          $t7, 0x22($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X22);
    // 0x805D80E8: beq         $t7, $zero, L_805D81A0
    if (ctx->r15 == 0) {
        // 0x805D80EC: nop
    
            goto L_805D81A0;
    }
    // 0x805D80EC: nop

    // 0x805D80F0: lhu         $t8, 0xC($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XC);
    // 0x805D80F4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805D80F8: bne         $t8, $at, L_805D81A0
    if (ctx->r24 != ctx->r1) {
        // 0x805D80FC: nop
    
            goto L_805D81A0;
    }
    // 0x805D80FC: nop

    // 0x805D8100: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x805D8104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D8108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805D810C: bnel        $t9, $at, L_805D8120
    if (ctx->r25 != ctx->r1) {
        // 0x805D8110: lw          $t0, 0x174($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X174);
            goto L_805D8120;
    }
    goto skip_0;
    // 0x805D8110: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x805D8114: b           L_805D8138
    // 0x805D8118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805D8138;
    // 0x805D8118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805D811C: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
L_805D8120:
    // 0x805D8120: lw          $t2, 0x174($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X174);
    // 0x805D8124: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x805D8128: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x805D812C: bne         $t1, $t3, L_805D8138
    if (ctx->r9 != ctx->r11) {
        // 0x805D8130: nop
    
            goto L_805D8138;
    }
    // 0x805D8130: nop

    // 0x805D8134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805D8138:
    // 0x805D8138: beq         $v0, $zero, L_805D81A0
    if (ctx->r2 == 0) {
        // 0x805D813C: nop
    
            goto L_805D81A0;
    }
    // 0x805D813C: nop

    // 0x805D8140: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805D8144: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x805D8148: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805D814C: nop

    // 0x805D8150: bc1fl       L_805D8180
    if (!c1cs) {
        // 0x805D8154: lwc1        $f8, 0xC4($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0XC4);
            goto L_805D8180;
    }
    goto skip_1;
    // 0x805D8154: lwc1        $f8, 0xC4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC4);
    skip_1:
    // 0x805D8158: lwc1        $f4, 0xC4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x805D815C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x805D8160: nop

    // 0x805D8164: bc1f        L_805D81A0
    if (!c1cs) {
        // 0x805D8168: nop
    
            goto L_805D81A0;
    }
    // 0x805D8168: nop

    // 0x805D816C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805D8170: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805D8174: jr          $ra
    // 0x805D8178: swc1        $f2, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->f2.u32l;
    return;
    // 0x805D8178: swc1        $f2, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->f2.u32l;
    // 0x805D817C: lwc1        $f8, 0xC4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC4);
L_805D8180:
    // 0x805D8180: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x805D8184: nop

    // 0x805D8188: bc1f        L_805D81A0
    if (!c1cs) {
        // 0x805D818C: nop
    
            goto L_805D81A0;
    }
    // 0x805D818C: nop

    // 0x805D8190: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805D8194: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x805D8198: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x805D819C: swc1        $f16, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->f16.u32l;
L_805D81A0:
    // 0x805D81A0: jr          $ra
    // 0x805D81A4: nop

    return;
    // 0x805D81A4: nop

;}
RECOMP_FUNC void func_80002818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002818: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8000281C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002820: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002824: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80002828: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8000282C: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80002830: lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XA);
    // 0x80002834: lhu         $t5, 0x10($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X10);
    // 0x80002838: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8000283C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80002840: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80002844: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002848: lbu         $t1, 0x5($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X5);
    // 0x8000284C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80002850: lhu         $ra, 0x12($a2)
    ctx->r31 = MEM_HU(ctx->r6, 0X12);
    // 0x80002854: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80002858: beq         $t5, $t0, L_800028A4
    if (ctx->r13 == ctx->r8) {
        // 0x8000285C: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_800028A4;
    }
    // 0x8000285C: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x80002860: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80002864: subu        $t7, $t0, $t4
    ctx->r15 = SUB32(ctx->r8, ctx->r12);
    // 0x80002868: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8000286C: mflo        $a3
    ctx->r7 = lo;
    // 0x80002870: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80002874: bne         $v0, $zero, L_80002880
    if (ctx->r2 != 0) {
        // 0x80002878: nop
    
            goto L_80002880;
    }
    // 0x80002878: nop

    // 0x8000287C: break       7
    do_break(2147494012);
L_80002880:
    // 0x80002880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002884: bne         $v0, $at, L_80002898
    if (ctx->r2 != ctx->r1) {
        // 0x80002888: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80002898;
    }
    // 0x80002888: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000288C: bne         $t7, $at, L_80002898
    if (ctx->r15 != ctx->r1) {
        // 0x80002890: nop
    
            goto L_80002898;
    }
    // 0x80002890: nop

    // 0x80002894: break       6
    do_break(2147494036);
L_80002898:
    // 0x80002898: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8000289C: b           L_800028B4
    // 0x800028A0: or          $t3, $ra, $zero
    ctx->r11 = ctx->r31 | 0;
        goto L_800028B4;
    // 0x800028A0: or          $t3, $ra, $zero
    ctx->r11 = ctx->r31 | 0;
L_800028A4:
    // 0x800028A4: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x800028A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800028AC: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800028B0: or          $t3, $ra, $zero
    ctx->r11 = ctx->r31 | 0;
L_800028B4:
    // 0x800028B4: beq         $ra, $v1, L_800028FC
    if (ctx->r31 == ctx->r3) {
        // 0x800028B8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800028FC;
    }
    // 0x800028B8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800028BC: subu        $t8, $a0, $t3
    ctx->r24 = SUB32(ctx->r4, ctx->r11);
    // 0x800028C0: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800028C4: mflo        $t0
    ctx->r8 = lo;
    // 0x800028C8: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x800028CC: bne         $v0, $zero, L_800028D8
    if (ctx->r2 != 0) {
        // 0x800028D0: nop
    
            goto L_800028D8;
    }
    // 0x800028D0: nop

    // 0x800028D4: break       7
    do_break(2147494100);
L_800028D8:
    // 0x800028D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800028DC: bne         $v0, $at, L_800028F0
    if (ctx->r2 != ctx->r1) {
        // 0x800028E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800028F0;
    }
    // 0x800028E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800028E4: bne         $t8, $at, L_800028F0
    if (ctx->r24 != ctx->r1) {
        // 0x800028E8: nop
    
            goto L_800028F0;
    }
    // 0x800028E8: nop

    // 0x800028EC: break       6
    do_break(2147494124);
L_800028F0:
    // 0x800028F0: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800028F4: b           L_80002904
    // 0x800028F8: lbu         $t2, 0x4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4);
        goto L_80002904;
    // 0x800028F8: lbu         $t2, 0x4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4);
L_800028FC:
    // 0x800028FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80002900: lbu         $t2, 0x4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4);
L_80002904:
    // 0x80002904: andi        $t9, $t1, 0x7F
    ctx->r25 = ctx->r9 & 0X7F;
    // 0x80002908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000290C: beq         $t2, $t1, L_80002958
    if (ctx->r10 == ctx->r9) {
        // 0x80002910: andi        $t6, $t2, 0x7F
        ctx->r14 = ctx->r10 & 0X7F;
            goto L_80002958;
    }
    // 0x80002910: andi        $t6, $t2, 0x7F
    ctx->r14 = ctx->r10 & 0X7F;
    // 0x80002914: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x80002918: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8000291C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x80002920: mflo        $t9
    ctx->r25 = lo;
    // 0x80002924: sh          $t9, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r25;
    // 0x80002928: bne         $v0, $zero, L_80002934
    if (ctx->r2 != 0) {
        // 0x8000292C: nop
    
            goto L_80002934;
    }
    // 0x8000292C: nop

    // 0x80002930: break       7
    do_break(2147494192);
L_80002934:
    // 0x80002934: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002938: bne         $v0, $at, L_8000294C
    if (ctx->r2 != ctx->r1) {
        // 0x8000293C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000294C;
    }
    // 0x8000293C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002940: bne         $t8, $at, L_8000294C
    if (ctx->r24 != ctx->r1) {
        // 0x80002944: nop
    
            goto L_8000294C;
    }
    // 0x80002944: nop

    // 0x80002948: break       6
    do_break(2147494216);
L_8000294C:
    // 0x8000294C: sb          $t1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r9;
    // 0x80002950: b           L_8000295C
    // 0x80002954: nop

        goto L_8000295C;
    // 0x80002954: nop

L_80002958:
    // 0x80002958: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
L_8000295C:
    // 0x8000295C: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002960: addiu       $a1, $zero, 0x5C0
    ctx->r5 = ADD32(0, 0X5C0);
    // 0x80002964: mflo        $t6
    ctx->r14 = lo;
    // 0x80002968: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8000296C: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
    // 0x80002970: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002974: mflo        $t8
    ctx->r24 = lo;
    // 0x80002978: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x8000297C: sh          $t9, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r25;
    // 0x80002980: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80002984: andi        $t9, $t2, 0x7F
    ctx->r25 = ctx->r10 & 0X7F;
    // 0x80002988: addiu       $a2, $zero, 0x1A0
    ctx->r6 = ADD32(0, 0X1A0);
    // 0x8000298C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80002990: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80002994: beq         $t8, $zero, L_80002A30
    if (ctx->r24 == 0) {
        // 0x80002998: nop
    
            goto L_80002A30;
    }
    // 0x80002998: nop

    // 0x8000299C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800029A0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800029A4: sh          $a3, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r7;
    // 0x800029A8: sh          $t0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r8;
    // 0x800029AC: sh          $t2, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r10;
    // 0x800029B0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800029B4: jal         0x80000FA0
    // 0x800029B8: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    func_80000FA0(rdram, ctx);
        goto after_0;
    // 0x800029B8: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    after_0:
    // 0x800029BC: lh          $t0, 0x5C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5C);
    // 0x800029C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800029C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800029C8: lh          $a3, 0x5E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5E);
    // 0x800029CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800029D0: lh          $a2, 0x5A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5A);
    // 0x800029D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800029D8: jal         0x80001088
    // 0x800029DC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    func_80001088(rdram, ctx);
        goto after_1;
    // 0x800029DC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    after_1:
    // 0x800029E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800029E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800029E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800029EC: jal         0x80001114
    // 0x800029F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80001114(rdram, ctx);
        goto after_2;
    // 0x800029F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800029F4: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x800029F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800029FC: lh          $t2, 0x58($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X58);
    // 0x80002A00: beq         $v0, $at, L_80002A20
    if (ctx->r2 == ctx->r1) {
        // 0x80002A04: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_80002A20;
    }
    // 0x80002A04: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80002A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002A0C: beq         $v0, $at, L_80002A28
    if (ctx->r2 == ctx->r1) {
        // 0x80002A10: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_80002A28;
    }
    // 0x80002A10: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80002A14: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80002A18: b           L_80002B00
    // 0x80002A1C: lw          $a1, 0x773C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X773C);
        goto L_80002B00;
    // 0x80002A1C: lw          $a1, 0x773C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X773C);
L_80002A20:
    // 0x80002A20: b           L_80002B00
    // 0x80002A24: lw          $a1, 0x7734($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7734);
        goto L_80002B00;
    // 0x80002A24: lw          $a1, 0x7734($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7734);
L_80002A28:
    // 0x80002A28: b           L_80002B00
    // 0x80002A2C: lw          $a1, 0x7738($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7738);
        goto L_80002B00;
    // 0x80002A2C: lw          $a1, 0x7738($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7738);
L_80002A30:
    // 0x80002A30: bne         $a3, $zero, L_80002AA0
    if (ctx->r7 != 0) {
        // 0x80002A34: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80002AA0;
    }
    // 0x80002A34: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80002A38: bnel        $t0, $zero, L_80002AA4
    if (ctx->r8 != 0) {
        // 0x80002A3C: sll         $t9, $t2, 1
        ctx->r25 = S32(ctx->r10 << 1);
            goto L_80002AA4;
    }
    goto skip_0;
    // 0x80002A3C: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    skip_0:
    // 0x80002A40: bne         $t2, $zero, L_80002AA0
    if (ctx->r10 != 0) {
        // 0x80002A44: lh          $t6, 0x5A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X5A);
            goto L_80002AA0;
    }
    // 0x80002A44: lh          $t6, 0x5A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5A);
    // 0x80002A48: bne         $t6, $zero, L_80002AA0
    if (ctx->r14 != 0) {
        // 0x80002A4C: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80002AA0;
    }
    // 0x80002A4C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80002A50: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80002A54: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80002A58: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80002A5C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80002A60: sra         $t7, $t8, 4
    ctx->r15 = S32(SIGNED(ctx->r24) >> 4);
    // 0x80002A64: ori         $t8, $t7, 0xC00
    ctx->r24 = ctx->r15 | 0XC00;
    // 0x80002A68: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80002A6C: lhu         $t9, 0x82($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X82);
    // 0x80002A70: addiu       $t7, $zero, 0x940
    ctx->r15 = ADD32(0, 0X940);
    // 0x80002A74: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x80002A78: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x80002A7C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80002A80: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x80002A84: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x80002A88: sra         $t6, $t3, 1
    ctx->r14 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80002A8C: addiu       $t7, $zero, 0xAE0
    ctx->r15 = ADD32(0, 0XAE0);
    // 0x80002A90: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x80002A94: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80002A98: b           L_80002B78
    // 0x80002A9C: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
        goto L_80002B78;
    // 0x80002A9C: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
L_80002AA0:
    // 0x80002AA0: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
L_80002AA4:
    // 0x80002AA4: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80002AA8: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x80002AAC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80002AB0: lui         $at, 0x1200
    ctx->r1 = S32(0X1200 << 16);
    // 0x80002AB4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80002AB8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80002ABC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80002AC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80002AC4: andi        $t6, $t0, 0xFFFF
    ctx->r14 = ctx->r8 & 0XFFFF;
    // 0x80002AC8: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80002ACC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80002AD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80002AD4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80002AD8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80002ADC: lui         $t9, 0x1600
    ctx->r25 = S32(0X1600 << 16);
    // 0x80002AE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80002AE4: andi        $t7, $ra, 0xFFFF
    ctx->r15 = ctx->r31 & 0XFFFF;
    // 0x80002AE8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80002AEC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80002AF0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80002AF4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80002AF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80002AFC: lw          $a1, 0x773C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X773C);
L_80002B00:
    // 0x80002B00: lhu         $t6, 0x82($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X82);
    // 0x80002B04: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80002B08: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80002B0C: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80002B10: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80002B14: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80002B18: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80002B1C: lw          $t6, 0x7730($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7730);
    // 0x80002B20: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80002B24: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80002B28: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80002B2C: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x80002B30: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80002B34: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80002B38: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80002B3C: andi        $t8, $t2, 0x80
    ctx->r24 = ctx->r10 & 0X80;
    // 0x80002B40: sra         $t7, $t8, 7
    ctx->r15 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80002B44: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80002B48: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80002B4C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80002B50: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80002B54: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x80002B58: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x80002B5C: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80002B60: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80002B64: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x80002B68: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x80002B6C: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80002B70: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80002B74: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_80002B78:
    // 0x80002B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002B7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80002B80: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80002B84: jr          $ra
    // 0x80002B88: nop

    return;
    // 0x80002B88: nop

;}
RECOMP_FUNC void func_800345AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800345B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800345B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800345B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800345BC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800345C0: jal         0x8006593C
    // 0x800345C4: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800345C4: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x800345C8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x800345CC: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800345D0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800345D4: beq         $t8, $zero, L_800346DC
    if (ctx->r24 == 0) {
        // 0x800345D8: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800346DC;
    }
    // 0x800345D8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800345DC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800345E0: lbu         $t9, -0x7684($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7684);
    // 0x800345E4: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x800345E8: beq         $t9, $t0, L_8003467C
    if (ctx->r25 == ctx->r8) {
        // 0x800345EC: nop
    
            goto L_8003467C;
    }
    // 0x800345EC: nop

    // 0x800345F0: lw          $t2, 0x12EC($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X12EC);
    // 0x800345F4: bne         $t2, $zero, L_8003463C
    if (ctx->r10 != 0) {
        // 0x800345F8: nop
    
            goto L_8003463C;
    }
    // 0x800345F8: nop

    // 0x800345FC: jal         0x80040FD4
    // 0x80034600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_1;
    // 0x80034600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80034604: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80034608: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003460C: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80034610: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80034614: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034618: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003461C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80034620: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80034624: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80034628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003462C: jalr        $t9
    // 0x80034630: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80034630: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80034634: b           L_800346C4
    // 0x80034638: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
        goto L_800346C4;
    // 0x80034638: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8003463C:
    // 0x8003463C: jal         0x80040C9C
    // 0x80034640: nop

    func_80040C9C(rdram, ctx);
        goto after_3;
    // 0x80034640: nop

    after_3:
    // 0x80034644: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80034648: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003464C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80034650: lw          $t9, -0xFFC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFFC);
    // 0x80034654: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034658: addiu       $v1, $v0, 0xB
    ctx->r3 = ADD32(ctx->r2, 0XB);
    // 0x8003465C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80034660: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x80034664: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80034668: lbu         $a1, -0xFC1($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFC1);
    // 0x8003466C: jalr        $t9
    // 0x80034670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80034670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80034674: b           L_800346C4
    // 0x80034678: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
        goto L_800346C4;
    // 0x80034678: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8003467C:
    // 0x8003467C: jal         0x80040CE0
    // 0x80034680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040CE0(rdram, ctx);
        goto after_5;
    // 0x80034680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80034684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034688: jal         0x80040E24
    // 0x8003468C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80040E24(rdram, ctx);
        goto after_6;
    // 0x8003468C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80034690: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80034694: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80034698: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8003469C: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x800346A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800346A4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800346A8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800346AC: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x800346B0: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x800346B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800346B8: jalr        $t9
    // 0x800346BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800346BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_7:
    // 0x800346C0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_800346C4:
    // 0x800346C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800346C8: bne         $v1, $at, L_80034864
    if (ctx->r3 != ctx->r1) {
        // 0x800346CC: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80034864;
    }
    // 0x800346CC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800346D0: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800346D4: b           L_80034864
    // 0x800346D8: sw          $t6, 0xE0($t7)
    MEM_W(0XE0, ctx->r15) = ctx->r14;
        goto L_80034864;
    // 0x800346D8: sw          $t6, 0xE0($t7)
    MEM_W(0XE0, ctx->r15) = ctx->r14;
L_800346DC:
    // 0x800346DC: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800346E0: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800346E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800346E8: lwc1        $f8, 0xAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XAC);
    // 0x800346EC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800346F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800346F4: addiu       $t0, $s0, 0xC4
    ctx->r8 = ADD32(ctx->r16, 0XC4);
    // 0x800346F8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800346FC: nop

    // 0x80034700: bc1tl       L_8003475C
    if (c1cs) {
        // 0x80034704: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8003475C;
    }
    goto skip_0;
    // 0x80034704: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    skip_0:
    // 0x80034708: lwc1        $f10, 0xB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB0);
    // 0x8003470C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034710: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80034714: nop

    // 0x80034718: bc1tl       L_8003475C
    if (c1cs) {
        // 0x8003471C: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8003475C;
    }
    goto skip_1;
    // 0x8003471C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    skip_1:
    // 0x80034720: jal         0x80040E24
    // 0x80034724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80040E24(rdram, ctx);
        goto after_8;
    // 0x80034724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80034728: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8003472C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80034730: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80034734: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80034738: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8003473C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80034740: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80034744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034748: jalr        $t9
    // 0x8003474C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8003474C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_9:
    // 0x80034750: b           L_80034868
    // 0x80034754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80034868;
    // 0x80034754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034758: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8003475C:
    // 0x8003475C: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x80034760: lw          $t2, 0x68($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X68);
    // 0x80034764: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80034768: beq         $t2, $t3, L_80034800
    if (ctx->r10 == ctx->r11) {
        // 0x8003476C: nop
    
            goto L_80034800;
    }
    // 0x8003476C: nop

    // 0x80034770: lw          $t5, 0x12EC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12EC);
    // 0x80034774: bne         $t5, $zero, L_800347B8
    if (ctx->r13 != 0) {
        // 0x80034778: nop
    
            goto L_800347B8;
    }
    // 0x80034778: nop

    // 0x8003477C: jal         0x80040FD4
    // 0x80034780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_10;
    // 0x80034780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80034784: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80034788: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003478C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80034790: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80034794: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034798: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003479C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800347A0: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x800347A4: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x800347A8: jalr        $t9
    // 0x800347AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800347AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800347B0: b           L_80034854
    // 0x800347B4: nop

        goto L_80034854;
    // 0x800347B4: nop

L_800347B8:
    // 0x800347B8: jal         0x80040D78
    // 0x800347BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040D78(rdram, ctx);
        goto after_12;
    // 0x800347BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800347C0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800347C4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800347C8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800347CC: lw          $t8, 0x68($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X68);
    // 0x800347D0: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800347D4: lw          $t9, -0xFFC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFFC);
    // 0x800347D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800347DC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800347E0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800347E4: sb          $t8, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r24;
    // 0x800347E8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x800347EC: lbu         $a1, -0xFC1($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFC1);
    // 0x800347F0: jalr        $t9
    // 0x800347F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800347F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800347F8: b           L_80034854
    // 0x800347FC: nop

        goto L_80034854;
    // 0x800347FC: nop

L_80034800:
    // 0x80034800: jal         0x80040D78
    // 0x80034804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040D78(rdram, ctx);
        goto after_14;
    // 0x80034804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80034808: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8003480C: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80034810: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x80034814: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80034818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003481C: beq         $a2, $t1, L_80034838
    if (ctx->r6 == ctx->r9) {
        // 0x80034820: lui         $t9, 0x800A
        ctx->r25 = S32(0X800A << 16);
            goto L_80034838;
    }
    // 0x80034820: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80034824: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80034828: lw          $t3, 0x12EC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X12EC);
    // 0x8003482C: beql        $t3, $zero, L_8003483C
    if (ctx->r11 == 0) {
        // 0x80034830: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_8003483C;
    }
    goto skip_2;
    // 0x80034830: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    skip_2:
    // 0x80034834: addiu       $v1, $v0, 0xB
    ctx->r3 = ADD32(ctx->r2, 0XB);
L_80034838:
    // 0x80034838: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
L_8003483C:
    // 0x8003483C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80034840: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80034844: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80034848: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8003484C: jalr        $t9
    // 0x80034850: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_15;
    // 0x80034850: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    after_15:
L_80034854:
    // 0x80034854: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034858: lwc1        $f16, 0xB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XB4);
    // 0x8003485C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80034860: swc1        $f16, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f16.u32l;
L_80034864:
    // 0x80034864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80034868:
    // 0x80034868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003486C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80034870: jr          $ra
    // 0x80034874: nop

    return;
    // 0x80034874: nop

;}
RECOMP_FUNC void func_80460DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460DBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80460DC0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80460DC4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80460DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460DCC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80460DD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80460DD4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80460DD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80460DDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80460DE0: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X368C) << 16);
    // 0x80460DE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80460DE8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80460DEC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80460DF0: lw          $t2, 0x3C1C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X368C));
    // 0x80460DF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80460DF8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80460DFC: jal         0x8046075C
    // 0x80460E00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046075C(rdram, ctx);
        goto after_0;
    // 0x80460E00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80460E04: jal         0x804607B8
    // 0x80460E08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804607B8(rdram, ctx);
        goto after_1;
    // 0x80460E08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80460E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460E14: jr          $ra
    // 0x80460E18: nop

    return;
    // 0x80460E18: nop

;}
RECOMP_FUNC void func_8002D34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D354: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D358: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002D35C: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x8002D360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002D364: jal         0x8002D1CC
    // 0x8002D368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002D1CC(rdram, ctx);
        goto after_0;
    // 0x8002D368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002D36C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D370: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002D374: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8002D378: addiu       $t7, $t7, 0x48C
    ctx->r15 = ADD32(ctx->r15, 0X48C);
    // 0x8002D37C: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x8002D380: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x8002D384: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002D388: jal         0x800231C8
    // 0x8002D38C: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    func_800231C8(rdram, ctx);
        goto after_1;
    // 0x8002D38C: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002D390: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D394: addiu       $a1, $a1, -0x2A88
    ctx->r5 = ADD32(ctx->r5, -0X2A88);
    // 0x8002D398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D39C: jal         0x80028118
    // 0x8002D3A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002D3A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_2:
    // 0x8002D3A4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8002D3A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D3AC: jal         0x80067838
    // 0x8002D3B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8002D3B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8002D3B4: jal         0x800677F8
    // 0x8002D3B8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x8002D3B8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_4:
    // 0x8002D3BC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8002D3C0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D3C4: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x8002D3C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D3CC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002D3D0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D3D4: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x8002D3D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D3DC: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8002D3E0: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x8002D3E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8002D3E8: sw          $t1, 0xD8($t2)
    MEM_W(0XD8, ctx->r10) = ctx->r9;
    // 0x8002D3EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D3F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002D3F4: jr          $ra
    // 0x8002D3F8: nop

    return;
    // 0x8002D3F8: nop

;}
RECOMP_FUNC void func_804625EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804625EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804625F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804625F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804625F8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804625FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80462600: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X3824) << 16);
    // 0x80462604: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80462608: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8046260C: addiu       $t7, $t7, 0x3DB4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X3824));
    // 0x80462610: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80462614: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80462618: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8046261C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80462624: jal         0x80462680
    // 0x80462628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80462680(rdram, ctx);
        goto after_0;
    // 0x80462628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8046262C: jal         0x80462554
    // 0x80462630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80462554(rdram, ctx);
        goto after_1;
    // 0x80462630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80462634: bne         $v0, $zero, L_80462644
    if (ctx->r2 != 0) {
        // 0x80462638: lui         $t9, 0x8005
        ctx->r25 = S32(0X8005 << 16);
            goto L_80462644;
    }
    // 0x80462638: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8046263C: b           L_8046266C
    // 0x80462640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046266C;
    // 0x80462640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80462644:
    // 0x80462644: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80462648: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8046264C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80462650: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80462654: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80462658: jal         0x804624B0
    // 0x8046265C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804624B0(rdram, ctx);
        goto after_2;
    // 0x8046265C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80462660: jal         0x804625D4
    // 0x80462664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804625D4(rdram, ctx);
        goto after_3;
    // 0x80462664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80462668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8046266C:
    // 0x8046266C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80462670: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80462678: jr          $ra
    // 0x8046267C: nop

    return;
    // 0x8046267C: nop

;}
RECOMP_FUNC void func_8058499C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058499C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805849A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805849A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805849A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805849AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805849B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805849B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805849B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805849BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805849C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805849C4: jr          $ra
    // 0x805849C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805849C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void trunc_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008205C: trunc.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x80082060: jr          $ra
    // 0x80082064: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x80082064: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_80581BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581C04: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80581C08: beql        $v1, $zero, L_80581C38
    if (ctx->r3 == 0) {
        // 0x80581C0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80581C38;
    }
    goto skip_0;
    // 0x80581C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80581C10: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x80581C14: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80581C18: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x80581C1C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80581C20: lw          $t6, 0x6F08($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6F08);
    // 0x80581C24: bnel        $t6, $zero, L_80581C38
    if (ctx->r14 != 0) {
        // 0x80581C28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80581C38;
    }
    goto skip_1;
    // 0x80581C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80581C2C: jal         0x80067818
    // 0x80581C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x80581C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80581C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581C38:
    // 0x80581C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581C3C: jr          $ra
    // 0x80581C40: nop

    return;
    // 0x80581C40: nop

;}
RECOMP_FUNC void func_8001DE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DE40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DE44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DE48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001DE4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001DE50: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001DE54: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001DE58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001DE5C: lwc1        $f0, 0x68($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X68);
    // 0x8001DE60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001DE64: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8001DE68: nop

    // 0x8001DE6C: bc1fl       L_8001DEB4
    if (!c1cs) {
        // 0x8001DE70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001DEB4;
    }
    goto skip_0;
    // 0x8001DE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001DE74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001DE78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001DE7C: jal         0x8002F9D4
    // 0x8001DE80: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8002F9D4(rdram, ctx);
        goto after_0;
    // 0x8001DE80: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8001DE84: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DE88: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001DE8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001DE90: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001DE94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001DE98: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001DE9C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DEA0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8001DEA4: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001DEA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001DEAC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8001DEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001DEB4:
    // 0x8001DEB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001DEB8: jr          $ra
    // 0x8001DEBC: nop

    return;
    // 0x8001DEBC: nop

;}
RECOMP_FUNC void func_8001FD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FD40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FD44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FD48: lw          $t6, 0x11C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X11C);
    // 0x8001FD4C: beql        $t6, $zero, L_8001FD68
    if (ctx->r14 == 0) {
        // 0x8001FD50: lw          $t7, 0x2C($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X2C);
            goto L_8001FD68;
    }
    goto skip_0;
    // 0x8001FD50: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    skip_0:
    // 0x8001FD54: jal         0x8002F3FC
    // 0x8001FD58: nop

    func_8002F3FC(rdram, ctx);
        goto after_0;
    // 0x8001FD58: nop

    after_0:
    // 0x8001FD5C: b           L_8001FD90
    // 0x8001FD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001FD90;
    // 0x8001FD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FD64: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
L_8001FD68:
    // 0x8001FD68: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x8001FD6C: beq         $t8, $zero, L_8001FD84
    if (ctx->r24 == 0) {
        // 0x8001FD70: nop
    
            goto L_8001FD84;
    }
    // 0x8001FD70: nop

    // 0x8001FD74: jal         0x8002F47C
    // 0x8001FD78: nop

    func_8002F47C(rdram, ctx);
        goto after_1;
    // 0x8001FD78: nop

    after_1:
    // 0x8001FD7C: b           L_8001FD90
    // 0x8001FD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001FD90;
    // 0x8001FD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001FD84:
    // 0x8001FD84: jal         0x8002DB78
    // 0x8001FD88: nop

    func_8002DB78(rdram, ctx);
        goto after_2;
    // 0x8001FD88: nop

    after_2:
    // 0x8001FD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001FD90:
    // 0x8001FD90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FD94: jr          $ra
    // 0x8001FD98: nop

    return;
    // 0x8001FD98: nop

;}
RECOMP_FUNC void func_806EC4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC4B0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CC4) << 16);
    // 0x806EC4B4: lwc1        $f2, 0xC14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CC4));
    // 0x806EC4B8: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EC4BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EC4C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EC4C4: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x806EC4C8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EC4CC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806EC4D0: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x806EC4D4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806EC4D8: bne         $t6, $at, L_806EC514
    if (ctx->r14 != ctx->r1) {
        // 0x806EC4DC: nop
    
            goto L_806EC514;
    }
    // 0x806EC4DC: nop

    // 0x806EC4E0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EC4E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806EC4E8: nop

    // 0x806EC4EC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806EC4F0: nop

    // 0x806EC4F4: bc1fl       L_806EC50C
    if (!c1cs) {
        // 0x806EC4F8: sub.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_806EC50C;
    }
    goto skip_0;
    // 0x806EC4F8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x806EC4FC: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806EC500: b           L_806EC528
    // 0x806EC504: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
        goto L_806EC528;
    // 0x806EC504: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x806EC508: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
L_806EC50C:
    // 0x806EC50C: b           L_806EC528
    // 0x806EC510: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
        goto L_806EC528;
    // 0x806EC510: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
L_806EC514:
    // 0x806EC514: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CC8) << 16);
    // 0x806EC518: lwc1        $f8, 0xC18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CC8));
    // 0x806EC51C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EC520: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806EC524: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_806EC528:
    // 0x806EC528: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806EC52C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806EC530: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EC534: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x806EC538: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806EC53C: nop

    // 0x806EC540: bc1fl       L_806EC558
    if (!c1cs) {
        // 0x806EC544: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806EC558;
    }
    goto skip_1;
    // 0x806EC544: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x806EC548: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x806EC54C: b           L_806EC574
    // 0x806EC550: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
        goto L_806EC574;
    // 0x806EC550: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EC554: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806EC558:
    // 0x806EC558: nop

    // 0x806EC55C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EC560: nop

    // 0x806EC564: bc1fl       L_806EC578
    if (!c1cs) {
        // 0x806EC568: lwc1        $f16, 0x50($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
            goto L_806EC578;
    }
    goto skip_2;
    // 0x806EC568: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x806EC56C: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x806EC570: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
L_806EC574:
    // 0x806EC574: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
L_806EC578:
    // 0x806EC578: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x806EC57C: jr          $ra
    // 0x806EC580: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806EC580: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8042DF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DF38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042DF3C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042DF40: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042DF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DF48: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8042DF4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042DF50: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8042DF54: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042DF58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8042DF5C: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(53, 0X3DC) << 16);
    // 0x8042DF60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042DF64: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042DF68: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042DF6C: lw          $t2, -0x2004($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(53, 0X3DC));
    // 0x8042DF70: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042DF74: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042DF78: jal         0x8042DD58
    // 0x8042DF7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042DD58(rdram, ctx);
        goto after_0;
    // 0x8042DF7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042DF80: jal         0x8042DDB4
    // 0x8042DF84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042DDB4(rdram, ctx);
        goto after_1;
    // 0x8042DF84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042DF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042DF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DF90: jr          $ra
    // 0x8042DF94: nop

    return;
    // 0x8042DF94: nop

    // 0x8042DF98: nop

    // 0x8042DF9C: nop

;}
RECOMP_FUNC void func_8064BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BE80: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064BE84: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X1C14) << 16);
    // 0x8064BE88: addiu       $t6, $t6, -0x431C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X1C14));
    // 0x8064BE8C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064BE90: jr          $ra
    // 0x8064BE94: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064BE94: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80461D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461D60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80461D64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80461D68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80461D6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80461D70: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80461D74: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461D78: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80461D7C: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80461D80: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A38) << 16);
    // 0x80461D84: lwc1        $f6, 0x3FC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A38));
    // 0x80461D88: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80461D8C: lb          $t7, 0x2($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X2);
    // 0x80461D90: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A3C) << 16);
    // 0x80461D94: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80461D98: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80461D9C: bc1f        L_80461DC8
    if (!c1cs) {
        // 0x80461DA0: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80461DC8;
    }
    // 0x80461DA0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80461DA4: lwc1        $f8, 0x3FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A3C));
    // 0x80461DA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80461DAC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80461DB0: nop

    // 0x80461DB4: bc1fl       L_80461DCC
    if (!c1cs) {
        // 0x80461DB8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80461DCC;
    }
    goto skip_0;
    // 0x80461DB8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x80461DBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80461DC0: b           L_80461DD4
    // 0x80461DC4: nop

        goto L_80461DD4;
    // 0x80461DC4: nop

L_80461DC8:
    // 0x80461DC8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80461DCC:
    // 0x80461DCC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80461DD0: nop

L_80461DD4:
    // 0x80461DD4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80461DD8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80461DDC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80461DE0: sub.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80461DE4: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x80461DE8: nop

    // 0x80461DEC: bc1fl       L_80461EA4
    if (!c1cs) {
        // 0x80461DF0: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80461EA4;
    }
    goto skip_1;
    // 0x80461DF0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x80461DF4: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80461DF8: jal         0x80461C80
    // 0x80461DFC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_80461C80(rdram, ctx);
        goto after_0;
    // 0x80461DFC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80461E00: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80461E04: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461E08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80461E0C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80461E10: nop

    // 0x80461E14: bc1fl       L_80461E5C
    if (!c1cs) {
        // 0x80461E18: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80461E5C;
    }
    goto skip_2;
    // 0x80461E18: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_2:
    // 0x80461E1C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80461E20: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80461E24: jal         0x8008D250
    // 0x80461E28: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80461E28: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80461E2C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80461E30: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80461E34: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80461E38: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80461E3C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80461E40: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461E44: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80461E48: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80461E4C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80461E50: b           L_80461EA0
    // 0x80461E54: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_80461EA0;
    // 0x80461E54: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80461E58: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80461E5C:
    // 0x80461E5C: nop

    // 0x80461E60: bc1fl       L_80461EA4
    if (!c1cs) {
        // 0x80461E64: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80461EA4;
    }
    goto skip_3;
    // 0x80461E64: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x80461E68: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80461E6C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80461E70: jal         0x8008D250
    // 0x80461E74: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    fcos(rdram, ctx);
        goto after_2;
    // 0x80461E74: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80461E78: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80461E7C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80461E80: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80461E84: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80461E88: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461E8C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80461E90: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80461E94: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80461E98: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80461E9C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_80461EA0:
    // 0x80461EA0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
L_80461EA4:
    // 0x80461EA4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A40) << 16);
    // 0x80461EA8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80461EAC: nop

    // 0x80461EB0: bc1f        L_80461EC0
    if (!c1cs) {
        // 0x80461EB4: nop
    
            goto L_80461EC0;
    }
    // 0x80461EB4: nop

    // 0x80461EB8: b           L_80461ED8
    // 0x80461EBC: swc1        $f14, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
        goto L_80461ED8;
    // 0x80461EBC: swc1        $f14, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
L_80461EC0:
    // 0x80461EC0: lwc1        $f2, 0x3FD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A40));
    // 0x80461EC4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80461EC8: nop

    // 0x80461ECC: bc1fl       L_80461EDC
    if (!c1cs) {
        // 0x80461ED0: swc1        $f16, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
            goto L_80461EDC;
    }
    goto skip_4;
    // 0x80461ED0: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    skip_4:
    // 0x80461ED4: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
L_80461ED8:
    // 0x80461ED8: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
L_80461EDC:
    // 0x80461EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80461EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80461EE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80461EE8: jr          $ra
    // 0x80461EEC: nop

    return;
    // 0x80461EEC: nop

;}
RECOMP_FUNC void func_804443E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804443E0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x804443E4: addiu       $at, $zero, 0x40EB
    ctx->r1 = ADD32(0, 0X40EB);
    // 0x804443E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804443EC: bne         $t6, $at, L_80444400
    if (ctx->r14 != ctx->r1) {
        // 0x804443F0: nop
    
            goto L_80444400;
    }
    // 0x804443F0: nop

    // 0x804443F4: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X12CB0) << 16);
    // 0x804443F8: jr          $ra
    // 0x804443FC: addiu       $v0, $v0, 0x7090
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(98, 0X12CB0));
    return;
    // 0x804443FC: addiu       $v0, $v0, 0x7090
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(98, 0X12CB0));
L_80444400:
    // 0x80444400: jr          $ra
    // 0x80444404: nop

    return;
    // 0x80444404: nop

;}
RECOMP_FUNC void func_80021F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F54: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x80021F58: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80021F5C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80021F60: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80021F64: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80021F68: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80021F6C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80021F70: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80021F74: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80021F78: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80021F7C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80021F80: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80021F84: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80021F88: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80021F8C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80021F90: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80021F94: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80021F98: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80021F9C: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80021FA0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80021FA4: lbu         $t6, 0x12($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X12);
    // 0x80021FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80021FAC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80021FB0: bne         $t6, $zero, L_80022238
    if (ctx->r14 != 0) {
        // 0x80021FB4: lui         $s2, 0x800A
        ctx->r18 = S32(0X800A << 16);
            goto L_80022238;
    }
    // 0x80021FB4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80021FB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80021FBC: lwc1        $f4, -0x3A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A4);
    // 0x80021FC0: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80021FC4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80021FC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80021FCC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80021FD0: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x80021FD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021FD8: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80021FDC: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80021FE0: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x80021FE4: addiu       $t7, $t7, -0x63D8
    ctx->r15 = ADD32(ctx->r15, -0X63D8);
    // 0x80021FE8: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    // 0x80021FEC: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80021FF0: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80021FF4: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80021FF8: swc1        $f8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f8.u32l;
    // 0x80021FFC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80022000: addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // 0x80022004: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80022008: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8002200C: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80022010: lw          $s1, -0x6428($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X6428);
    // 0x80022014: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80022018: lw          $s2, -0x6418($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X6418);
    // 0x8002201C: lw          $s3, -0x6408($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X6408);
    // 0x80022020: lw          $s4, -0x63F8($s4)
    ctx->r20 = MEM_W(ctx->r20, -0X63F8);
    // 0x80022024: lw          $s5, -0x63E8($s5)
    ctx->r21 = MEM_W(ctx->r21, -0X63E8);
    // 0x80022028: lw          $s6, 0x0($a2)
    ctx->r22 = MEM_W(ctx->r6, 0X0);
    // 0x8002202C: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    // 0x80022030: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x80022034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80022038: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x8002203C: jal         0x80047AB8
    // 0x80022040: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80022040: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80022044: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x80022048: lwc1        $f18, 0x110($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8002204C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80022050: beql        $t0, $zero, L_8002206C
    if (ctx->r8 == 0) {
        // 0x80022054: lwc1        $f20, 0x120($s0)
        ctx->f20.u32l = MEM_W(ctx->r16, 0X120);
            goto L_8002206C;
    }
    goto skip_0;
    // 0x80022054: lwc1        $f20, 0x120($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x80022058: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002205C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80022060: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x80022064: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x80022068: lwc1        $f20, 0x120($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X120);
L_8002206C:
    // 0x8002206C: jal         0x80066DE4
    // 0x80022070: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80022070: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80022074: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80022078: jal         0x80066E88
    // 0x8002207C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8002207C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80022080: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022084: lwc1        $f10, -0x3A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A0);
    // 0x80022088: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8002208C: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80022090: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80022094: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80022098: addiu       $fp, $sp, 0xF8
    ctx->r30 = ADD32(ctx->r29, 0XF8);
    // 0x8002209C: addiu       $s7, $sp, 0x100
    ctx->r23 = ADD32(ctx->r29, 0X100);
    // 0x800220A0: beq         $s1, $zero, L_80022238
    if (ctx->r17 == 0) {
        // 0x800220A4: swc1        $f16, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->f16.u32l;
            goto L_80022238;
    }
    // 0x800220A4: swc1        $f16, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f16.u32l;
    // 0x800220A8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800220AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800220B0: lwc1        $f24, -0x39C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X39C);
    // 0x800220B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800220B8: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800220BC: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x800220C0: lwc1        $f22, -0x398($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X398);
L_800220C4:
    // 0x800220C4: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800220C8: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800220CC: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800220D0: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800220D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800220D8: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800220DC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800220E0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800220E4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800220E8: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800220EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800220F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800220F4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800220F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800220FC: jal         0x80021F08
    // 0x80022100: nop

    func_80021F08(rdram, ctx);
        goto after_3;
    // 0x80022100: nop

    after_3:
    // 0x80022104: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80022108: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8002210C: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80022110: lwc1        $f18, 0xD8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80022114: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80022118: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8002211C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80022120: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80022124: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x80022128: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8002212C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80022130: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x80022134: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80022138: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8002213C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x80022140: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80022144: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x80022148: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002214C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80022150: jal         0x80021F08
    // 0x80022154: nop

    func_80021F08(rdram, ctx);
        goto after_4;
    // 0x80022154: nop

    after_4:
    // 0x80022158: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8002215C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80022160: addiu       $t2, $t2, -0x63CC
    ctx->r10 = ADD32(ctx->r10, -0X63CC);
    // 0x80022164: bnel        $t1, $t2, L_800221D0
    if (ctx->r9 != ctx->r10) {
        // 0x80022168: lwc1        $f18, 0x100($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
            goto L_800221D0;
    }
    goto skip_1;
    // 0x80022168: lwc1        $f18, 0x100($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
    skip_1:
    // 0x8002216C: mul.s       $f0, $f20, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80022170: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80022174: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80022178: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8002217C: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80022180: lwc1        $f16, 0xFC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80022184: lw          $t3, 0xA68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XA68);
    // 0x80022188: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x8002218C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80022190: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80022194: swc1        $f22, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f22.u32l;
    // 0x80022198: swc1        $f24, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f24.u32l;
    // 0x8002219C: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800221A0: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x800221A4: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x800221A8: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x800221AC: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
    // 0x800221B0: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x800221B4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800221B8: lw          $t9, 0x28($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X28);
    // 0x800221BC: jalr        $t9
    // 0x800221C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800221C0: nop

    after_5:
    // 0x800221C4: b           L_80022224
    // 0x800221C8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
        goto L_80022224;
    // 0x800221C8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800221CC: lwc1        $f18, 0x100($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
L_800221D0:
    // 0x800221D0: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800221D4: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800221D8: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800221DC: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800221E0: lw          $t5, 0xA68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XA68);
    // 0x800221E4: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x800221E8: swc1        $f20, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f20.u32l;
    // 0x800221EC: swc1        $f20, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f20.u32l;
    // 0x800221F0: swc1        $f22, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f22.u32l;
    // 0x800221F4: swc1        $f24, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f24.u32l;
    // 0x800221F8: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    // 0x800221FC: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x80022200: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x80022204: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    // 0x80022208: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8002220C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80022210: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x80022214: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x80022218: jalr        $t9
    // 0x8002221C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8002221C: nop

    after_6:
    // 0x80022220: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80022224:
    // 0x80022224: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80022228: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8002222C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80022230: bne         $s1, $zero, L_800220C4
    if (ctx->r17 != 0) {
        // 0x80022234: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800220C4;
    }
    // 0x80022234: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80022238:
    // 0x80022238: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002223C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80022240: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80022244: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80022248: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8002224C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80022250: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80022254: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80022258: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8002225C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80022260: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80022264: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80022268: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8002226C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80022270: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80022274: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80022278: jr          $ra
    // 0x8002227C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8002227C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_80673808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067380C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673810: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80673814: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80673818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8067381C: beq         $t6, $zero, L_8067388C
    if (ctx->r14 == 0) {
        // 0x80673820: nop
    
            goto L_8067388C;
    }
    // 0x80673820: nop

    // 0x80673824: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80673828: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8067382C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80673830: jalr        $t9
    // 0x80673834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80673834: nop

    after_0:
    // 0x80673838: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8067383C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80673840: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80673844: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80673848: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8067384C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80673850: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80673854: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80673858: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8067385C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80673860: bne         $v0, $at, L_80673884
    if (ctx->r2 != ctx->r1) {
        // 0x80673864: sh          $t3, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r11;
            goto L_80673884;
    }
    // 0x80673864: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80673868: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8067386C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80673870: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80673874: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80673878: bne         $at, $zero, L_80673884
    if (ctx->r1 != 0) {
        // 0x8067387C: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_80673884;
    }
    // 0x8067387C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80673880: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80673884:
    // 0x80673884: b           L_8067388C
    // 0x80673888: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8067388C;
    // 0x80673888: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8067388C:
    // 0x8067388C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673890: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80673894: jr          $ra
    // 0x80673898: nop

    return;
    // 0x80673898: nop

;}
RECOMP_FUNC void func_8078A0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A0C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078A0CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078A0D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078A0D4: jal         0x8078A084
    // 0x8078A0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8078A084(rdram, ctx);
        goto after_0;
    // 0x8078A0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078A0DC: bne         $v0, $zero, L_8078A0F4
    if (ctx->r2 != 0) {
        // 0x8078A0E0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8078A0F4;
    }
    // 0x8078A0E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078A0E4: jal         0x800445A4
    // 0x8078A0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078A0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8078A0EC: b           L_8078A138
    // 0x8078A0F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078A138;
    // 0x8078A0F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078A0F4:
    // 0x8078A0F4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8078A0F8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8078A0FC: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8078A100: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8078A104: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8078A108: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x8078A10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078A110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078A114: jal         0x8078A148
    // 0x8078A118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078A148(rdram, ctx);
        goto after_2;
    // 0x8078A118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8078A11C: jal         0x80789CD8
    // 0x8078A120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80789CD8(rdram, ctx);
        goto after_3;
    // 0x8078A120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078A124: bnel        $v0, $zero, L_8078A138
    if (ctx->r2 != 0) {
        // 0x8078A128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A138;
    }
    goto skip_0;
    // 0x8078A128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078A12C: jal         0x800445A4
    // 0x8078A130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8078A130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8078A134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078A138:
    // 0x8078A138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078A13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078A140: jr          $ra
    // 0x8078A144: nop

    return;
    // 0x8078A144: nop

;}
RECOMP_FUNC void func_800481B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800481B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800481B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800481BC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800481C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800481C4: addiu       $a2, $a2, -0x7E94
    ctx->r6 = ADD32(ctx->r6, -0X7E94);
    // 0x800481C8: jal         0x80047F34
    // 0x800481CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80047F34(rdram, ctx);
        goto after_0;
    // 0x800481CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_0:
    // 0x800481D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800481D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800481D8: jr          $ra
    // 0x800481DC: nop

    return;
    // 0x800481DC: nop

;}
RECOMP_FUNC void func_80030A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030A6C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80030A70: jal         0x80042880
    // 0x80030A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80042880(rdram, ctx);
        goto after_0;
    // 0x80030A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80030A78: jal         0x80041D3C
    // 0x80030A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041D3C(rdram, ctx);
        goto after_1;
    // 0x80030A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80030A80: jal         0x800309C4
    // 0x80030A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800309C4(rdram, ctx);
        goto after_2;
    // 0x80030A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80030A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030A90: jr          $ra
    // 0x80030A94: nop

    return;
    // 0x80030A94: nop

;}
RECOMP_FUNC void func_800290F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800290F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800290F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800290FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029100: jal         0x80028B64
    // 0x80029104: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80028B64(rdram, ctx);
        goto after_0;
    // 0x80029104: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80029108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002910C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029110: jal         0x80028DB4
    // 0x80029114: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80028DB4(rdram, ctx);
        goto after_1;
    // 0x80029114: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80029118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002911C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029120: jr          $ra
    // 0x80029124: nop

    return;
    // 0x80029124: nop

;}
RECOMP_FUNC void func_804BAD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAD44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BAD48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804BAD4C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804BAD50: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804BAD54: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804BAD58: lwc1        $f20, 0x3C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804BAD5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BAD60: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804BAD64: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804BAD68: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x804BAD6C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x804BAD70: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x804BAD74: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804BAD78: bc1f        L_804BADA0
    if (!c1cs) {
        // 0x804BAD7C: mov.s       $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
            goto L_804BADA0;
    }
    // 0x804BAD7C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x804BAD80: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804BAD84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BAD88: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC44) << 16);
    // 0x804BAD8C: lwc1        $f10, -0x485C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC44));
    // 0x804BAD90: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804BAD94: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804BAD98: b           L_804BADCC
    // 0x804BAD9C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
        goto L_804BADCC;
    // 0x804BAD9C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
L_804BADA0:
    // 0x804BADA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BADA4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC48) << 16);
    // 0x804BADA8: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x804BADAC: nop

    // 0x804BADB0: bc1fl       L_804BADCC
    if (!c1cs) {
        // 0x804BADB4: lui         $at, 0x42FA
        ctx->r1 = S32(0X42FA << 16);
            goto L_804BADCC;
    }
    goto skip_0;
    // 0x804BADB4: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    skip_0:
    // 0x804BADB8: sub.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x804BADBC: lwc1        $f6, -0x4858($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC48));
    // 0x804BADC0: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BADC4: nop

    // 0x804BADC8: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
L_804BADCC:
    // 0x804BADCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BADD0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804BADD4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804BADD8: nop

    // 0x804BADDC: bc1fl       L_804BAE00
    if (!c1cs) {
        // 0x804BADE0: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_804BAE00;
    }
    goto skip_1;
    // 0x804BADE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x804BADE4: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x804BADE8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC4C) << 16);
    // 0x804BADEC: lwc1        $f10, -0x4854($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC4C));
    // 0x804BADF0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804BADF4: b           L_804BAE28
    // 0x804BADF8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
        goto L_804BAE28;
    // 0x804BADF8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804BADFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_804BAE00:
    // 0x804BAE00: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC50) << 16);
    // 0x804BAE04: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804BAE08: nop

    // 0x804BAE0C: bc1fl       L_804BAE28
    if (!c1cs) {
        // 0x804BAE10: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_804BAE28;
    }
    goto skip_2;
    // 0x804BAE10: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x804BAE14: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x804BAE18: lwc1        $f6, -0x4850($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC50));
    // 0x804BAE1C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BAE20: nop

    // 0x804BAE24: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_804BAE28:
    // 0x804BAE28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804BAE2C: bc1fl       L_804BAE3C
    if (!c1cs) {
        // 0x804BAE30: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_804BAE3C;
    }
    goto skip_3;
    // 0x804BAE30: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_3:
    // 0x804BAE34: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804BAE38: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_804BAE3C:
    // 0x804BAE3C: nop

    // 0x804BAE40: bc1fl       L_804BAE50
    if (!c1cs) {
        // 0x804BAE44: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_804BAE50;
    }
    goto skip_4;
    // 0x804BAE44: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_4:
    // 0x804BAE48: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x804BAE4C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_804BAE50:
    // 0x804BAE50: nop

    // 0x804BAE54: bc1fl       L_804BAE64
    if (!c1cs) {
        // 0x804BAE58: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_804BAE64;
    }
    goto skip_5;
    // 0x804BAE58: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_5:
    // 0x804BAE5C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x804BAE60: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_804BAE64:
    // 0x804BAE64: nop

    // 0x804BAE68: bc1fl       L_804BAE78
    if (!c1cs) {
        // 0x804BAE6C: add.s       $f8, $f2, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
            goto L_804BAE78;
    }
    goto skip_6;
    // 0x804BAE6C: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    skip_6:
    // 0x804BAE70: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x804BAE74: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
L_804BAE78:
    // 0x804BAE78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BAE7C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804BAE80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BAE84: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804BAE88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804BAE8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804BAE90: sub.s       $f18, $f14, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x804BAE94: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x804BAE98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804BAE9C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804BAEA0: nop

    // 0x804BAEA4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x804BAEA8: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804BAEAC: nop

    // 0x804BAEB0: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804BAEB4: beql        $v1, $zero, L_804BAF04
    if (ctx->r3 == 0) {
        // 0x804BAEB8: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_804BAF04;
    }
    goto skip_7;
    // 0x804BAEB8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_7:
    // 0x804BAEBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BAEC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804BAEC4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804BAEC8: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804BAECC: nop

    // 0x804BAED0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804BAED4: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804BAED8: nop

    // 0x804BAEDC: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804BAEE0: bne         $v1, $zero, L_804BAEF8
    if (ctx->r3 != 0) {
        // 0x804BAEE4: nop
    
            goto L_804BAEF8;
    }
    // 0x804BAEE4: nop

    // 0x804BAEE8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804BAEEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804BAEF0: b           L_804BAF10
    // 0x804BAEF4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_804BAF10;
    // 0x804BAEF4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_804BAEF8:
    // 0x804BAEF8: b           L_804BAF10
    // 0x804BAEFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_804BAF10;
    // 0x804BAEFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x804BAF00: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_804BAF04:
    // 0x804BAF04: nop

    // 0x804BAF08: bltz        $v1, L_804BAEF8
    if (SIGNED(ctx->r3) < 0) {
        // 0x804BAF0C: nop
    
            goto L_804BAEF8;
    }
    // 0x804BAF0C: nop

L_804BAF10:
    // 0x804BAF10: sb          $v1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r3;
    // 0x804BAF14: sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // 0x804BAF18: sb          $v1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r3;
    // 0x804BAF1C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x804BAF20: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804BAF24: jr          $ra
    // 0x804BAF28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x804BAF28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80566DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566DFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566E04: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566E08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80566E0C: jal         0x8056682C
    // 0x80566E10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8056682C(rdram, ctx);
        goto after_0;
    // 0x80566E10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80566E14: jal         0x80566674
    // 0x80566E18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80566674(rdram, ctx);
        goto after_1;
    // 0x80566E18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80566E1C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80566E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80566E24: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80566E28: bnel        $t8, $zero, L_80566E3C
    if (ctx->r24 != 0) {
        // 0x80566E2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80566E3C;
    }
    goto skip_0;
    // 0x80566E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80566E30: jal         0x805670F4
    // 0x80566E34: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80566E34: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80566E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566E3C:
    // 0x80566E3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80566E40: jr          $ra
    // 0x80566E44: nop

    return;
    // 0x80566E44: nop

;}
RECOMP_FUNC void func_800080D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080D4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800080D8: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800080DC: sw          $zero, 0x12DC($v0)
    MEM_W(0X12DC, ctx->r2) = 0;
    // 0x800080E0: jr          $ra
    // 0x800080E4: sw          $zero, 0x133C($v0)
    MEM_W(0X133C, ctx->r2) = 0;
    return;
    // 0x800080E4: sw          $zero, 0x133C($v0)
    MEM_W(0X133C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8064EC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EC1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064EC20: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8064EC24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8064EC28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064EC2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064EC30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064EC34: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064EC38: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064EC3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EC40: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x8064EC44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EC48: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EC4C: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EC50: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064EC54: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8064EC58: jal         0x8064EA0C
    // 0x8064EC5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064EC5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8064EC60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8064EC64: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D3C) << 16);
    // 0x8064EC68: lwc1        $f2, 0x473C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D3C));
    // 0x8064EC6C: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8064EC70: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x8064EC74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8064EC78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8064EC7C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064EC80: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EC84: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EC88: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8064EC8C: jal         0x8064EA0C
    // 0x8064EC90: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_1;
    // 0x8064EC90: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8064EC94: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EC98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EC9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064ECA0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064ECA4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064ECA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064ECAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064ECB0: jr          $ra
    // 0x8064ECB4: nop

    return;
    // 0x8064ECB4: nop

;}
RECOMP_FUNC void func_80024C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024C90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024C94: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80024C98: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x80024C9C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80024CA0: addiu       $t9, $t9, 0x4C1C
    ctx->r25 = ADD32(ctx->r25, 0X4C1C);
    // 0x80024CA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80024CA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80024CAC: lw          $t8, -0x3D10($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3D10);
    // 0x80024CB0: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80024CB4: jr          $ra
    // 0x80024CB8: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    return;
    // 0x80024CB8: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80532244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532244: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80532248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053224C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80532250: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80532254: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80532258: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8053225C: addiu       $a1, $zero, 0x338
    ctx->r5 = ADD32(0, 0X338);
    // 0x80532260: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80532264: jal         0x80045A34
    // 0x80532268: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80532268: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8053226C: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x80532270: bne         $v0, $zero, L_80532288
    if (ctx->r2 != 0) {
        // 0x80532274: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80532288;
    }
    // 0x80532274: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80532278: jal         0x800445A4
    // 0x8053227C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8053227C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80532280: b           L_805322D8
    // 0x80532284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805322D8;
    // 0x80532284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80532288:
    // 0x80532288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053228C: addiu       $a1, $zero, 0x338
    ctx->r5 = ADD32(0, 0X338);
    // 0x80532290: jal         0x80065728
    // 0x80532294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80532294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80532298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8053229C: jal         0x8005D730
    // 0x805322A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x805322A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x805322A4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x805322A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805322AC: sw          $t8, 0x260($s0)
    MEM_W(0X260, ctx->r16) = ctx->r24;
    // 0x805322B0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x805322B4: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x805322B8: jal         0x8053137C
    // 0x805322BC: sh          $t0, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r8;
    func_8053137C(rdram, ctx);
        goto after_4;
    // 0x805322BC: sh          $t0, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r8;
    after_4:
    // 0x805322C0: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x805322C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805322C8: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805322CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805322D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805322D4: swc1        $f8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->f8.u32l;
L_805322D8:
    // 0x805322D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805322DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805322E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805322E4: jr          $ra
    // 0x805322E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805322E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006A328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A32C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A334: bne         $a1, $zero, L_8006A344
    if (ctx->r5 != 0) {
        // 0x8006A338: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8006A344;
    }
    // 0x8006A338: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006A33C: b           L_8006A3D4
    // 0x8006A340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A3D4;
    // 0x8006A340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A344:
    // 0x8006A344: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A348: addiu       $a1, $zero, 0x1BF
    ctx->r5 = ADD32(0, 0X1BF);
    // 0x8006A34C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006A350: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8006A354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A358: beql        $t7, $zero, L_8006A378
    if (ctx->r15 == 0) {
        // 0x8006A35C: lw          $a1, 0x0($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X0);
            goto L_8006A378;
    }
    goto skip_0;
    // 0x8006A35C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8006A360: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A364: jal         0x80071380
    // 0x8006A368: addiu       $a0, $a0, 0xF80
    ctx->r4 = ADD32(ctx->r4, 0XF80);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006A368: addiu       $a0, $a0, 0xF80
    ctx->r4 = ADD32(ctx->r4, 0XF80);
    after_0:
    // 0x8006A36C: b           L_8006A3D4
    // 0x8006A370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A3D4;
    // 0x8006A370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006A374: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
L_8006A378:
    // 0x8006A378: jal         0x80069FE4
    // 0x8006A37C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A37C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8006A380: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8006A384: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A388: bne         $v0, $zero, L_8006A3A8
    if (ctx->r2 != 0) {
        // 0x8006A38C: sw          $v0, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r2;
            goto L_8006A3A8;
    }
    // 0x8006A38C: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8006A390: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A394: addiu       $a0, $a0, 0xF90
    ctx->r4 = ADD32(ctx->r4, 0XF90);
    // 0x8006A398: jal         0x80071380
    // 0x8006A39C: addiu       $a1, $zero, 0x1CA
    ctx->r5 = ADD32(0, 0X1CA);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8006A39C: addiu       $a1, $zero, 0x1CA
    ctx->r5 = ADD32(0, 0X1CA);
    after_2:
    // 0x8006A3A0: b           L_8006A3D4
    // 0x8006A3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A3D4;
    // 0x8006A3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A3A8:
    // 0x8006A3A8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8006A3AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A3B0: bgez        $t8, L_8006A3C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006A3B4: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8006A3C0;
    }
    // 0x8006A3B4: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8006A3B8: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8006A3BC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8006A3C0:
    // 0x8006A3C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006A3C4: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8006A3C8: mflo        $t0
    ctx->r8 = lo;
    // 0x8006A3CC: sh          $t0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r8;
    // 0x8006A3D0: nop

L_8006A3D4:
    // 0x8006A3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A3D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A3DC: jr          $ra
    // 0x8006A3E0: nop

    return;
    // 0x8006A3E0: nop

;}
RECOMP_FUNC void func_805A922C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A922C: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x805A9230: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805A9234: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(429, 0X13CC) << 16);
    // 0x805A9238: addiu       $v0, $v0, -0x5F34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(429, 0X13CC));
    // 0x805A923C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x805A9240: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x805A9244: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x805A9248: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x805A924C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x805A9250: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x805A9254: jr          $ra
    // 0x805A9258: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x805A9258: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80536774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536774: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536778: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053677C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536780: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536784: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536788: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053678C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536790: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536794: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536798: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053679C: jr          $ra
    // 0x805367A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805367A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80007014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007014: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80007018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000701C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80007020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80007024: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80007028: jal         0x8000744C
    // 0x8000702C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8000744C(rdram, ctx);
        goto after_0;
    // 0x8000702C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80007030: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80007034: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80007038: jal         0x800073BC
    // 0x8000703C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800073BC(rdram, ctx);
        goto after_1;
    // 0x8000703C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80007040: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80007044: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80007048: jal         0x800073F8
    // 0x8000704C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800073F8(rdram, ctx);
        goto after_2;
    // 0x8000704C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80007050: beq         $v0, $zero, L_80007078
    if (ctx->r2 == 0) {
        // 0x80007054: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80007078;
    }
    // 0x80007054: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80007058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000705C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80007060: jal         0x800067BC
    // 0x80007064: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800067BC(rdram, ctx);
        goto after_3;
    // 0x80007064: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_3:
    // 0x80007068: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000706C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80007070: b           L_800070D8
    // 0x80007074: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_800070D8;
    // 0x80007074: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80007078:
    // 0x80007078: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x8000707C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80007080: lb          $v0, 0x19($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X19);
    // 0x80007084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80007088: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000708C: bne         $v0, $at, L_800070A8
    if (ctx->r2 != ctx->r1) {
        // 0x80007090: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800070A8;
    }
    // 0x80007090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80007094: lb          $t9, 0x18($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X18);
    // 0x80007098: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000709C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800070A0: b           L_800070D8
    // 0x800070A4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
        goto L_800070D8;
    // 0x800070A4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_800070A8:
    // 0x800070A8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800070AC: jal         0x800071C8
    // 0x800070B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800071C8(rdram, ctx);
        goto after_4;
    // 0x800070B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x800070B4: beq         $v0, $zero, L_800070C8
    if (ctx->r2 == 0) {
        // 0x800070B8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800070C8;
    }
    // 0x800070B8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800070BC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800070C0: b           L_800070D8
    // 0x800070C4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_800070D8;
    // 0x800070C4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_800070C8:
    // 0x800070C8: lb          $t2, 0x18($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X18);
    // 0x800070CC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800070D0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800070D4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_800070D8:
    // 0x800070D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800070DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800070E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800070E4: jr          $ra
    // 0x800070E8: nop

    return;
    // 0x800070E8: nop

;}
RECOMP_FUNC void func_80558F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558F2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558F30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558F38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558F3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558F40: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80558F44: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x80558F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558F4C: jal         0x80048F84
    // 0x80558F50: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80558F50: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80558F54: jal         0x805580E8
    // 0x80558F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80558F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80558F5C: jal         0x805582E0
    // 0x80558F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80558F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558F64: beq         $v0, $zero, L_80558FD4
    if (ctx->r2 == 0) {
        // 0x80558F68: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80558FD4;
    }
    // 0x80558F68: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80558F6C: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x80558F70: beql        $t6, $zero, L_80558FA4
    if (ctx->r14 == 0) {
        // 0x80558F74: lw          $t9, 0x24($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X24);
            goto L_80558FA4;
    }
    goto skip_0;
    // 0x80558F74: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    skip_0:
    // 0x80558F78: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80558F7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80558F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558F84: bne         $t7, $zero, L_80558FA0
    if (ctx->r15 != 0) {
        // 0x80558F88: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80558FA0;
    }
    // 0x80558F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558F8C: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    // 0x80558F90: jal         0x80559928
    // 0x80558F94: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80558F94: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80558F98: b           L_80558FD8
    // 0x80558F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80558FD8;
    // 0x80558F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558FA0:
    // 0x80558FA0: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
L_80558FA4:
    // 0x80558FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80558FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558FAC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80558FB0: beq         $at, $zero, L_80558FCC
    if (ctx->r1 == 0) {
        // 0x80558FB4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80558FCC;
    }
    // 0x80558FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558FBC: jal         0x80559928
    // 0x80558FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x80558FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80558FC4: b           L_80558FD8
    // 0x80558FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80558FD8;
    // 0x80558FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558FCC:
    // 0x80558FCC: jal         0x80559928
    // 0x80558FD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x80558FD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
L_80558FD4:
    // 0x80558FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558FD8:
    // 0x80558FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558FE0: jr          $ra
    // 0x80558FE4: nop

    return;
    // 0x80558FE4: nop

;}
RECOMP_FUNC void func_806F2290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F2298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F229C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806F22A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806F22A4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806F22A8: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806F22AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F22B0: bnel        $v0, $at, L_806F2308
    if (ctx->r2 != ctx->r1) {
        // 0x806F22B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2308;
    }
    goto skip_0;
    // 0x806F22B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F22B8: jal         0x8005FE48
    // 0x806F22BC: nop

    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x806F22BC: nop

    after_0:
    // 0x806F22C0: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806F22C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F22C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F22CC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F22D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806F22D4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x806F22D8: jal         0x806F2554
    // 0x806F22DC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F2554(rdram, ctx);
        goto after_1;
    // 0x806F22DC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806F22E0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806F22E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F22E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806F22EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806F22F0: jal         0x80067BBC
    // 0x806F22F4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806F22F4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x806F22F8: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x806F22FC: jal         0x80067818
    // 0x806F2300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806F2300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806F2304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2308:
    // 0x806F2308: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F230C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2310: jr          $ra
    // 0x806F2314: nop

    return;
    // 0x806F2314: nop

;}
RECOMP_FUNC void func_806A9BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9BBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806A9BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A9BC4: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x806A9BC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806A9BCC: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9BD0: beq         $a1, $zero, L_806A9CC8
    if (ctx->r5 == 0) {
        // 0x806A9BD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806A9CC8;
    }
    // 0x806A9BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806A9BD8: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x806A9BDC: lh          $t7, 0x8($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X8);
    // 0x806A9BE0: lh          $t6, 0x1BC($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BC);
    // 0x806A9BE4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x806A9BE8: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
    // 0x806A9BEC: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x806A9BF0: bgezl       $v0, L_806A9C00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x806A9BF4: slti        $at, $v0, 0x48
        ctx->r1 = SIGNED(ctx->r2) < 0X48 ? 1 : 0;
            goto L_806A9C00;
    }
    goto skip_0;
    // 0x806A9BF4: slti        $at, $v0, 0x48
    ctx->r1 = SIGNED(ctx->r2) < 0X48 ? 1 : 0;
    skip_0:
    // 0x806A9BF8: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x806A9BFC: slti        $at, $v0, 0x48
    ctx->r1 = SIGNED(ctx->r2) < 0X48 ? 1 : 0;
L_806A9C00:
    // 0x806A9C00: bnel        $at, $zero, L_806A9C10
    if (ctx->r1 != 0) {
        // 0x806A9C04: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_806A9C10;
    }
    goto skip_1;
    // 0x806A9C04: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    skip_1:
    // 0x806A9C08: addiu       $v0, $v0, -0x48
    ctx->r2 = ADD32(ctx->r2, -0X48);
    // 0x806A9C0C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
L_806A9C10:
    // 0x806A9C10: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x806A9C14: lh          $t0, 0xC($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XC);
    // 0x806A9C18: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x806A9C1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806A9C20: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x806A9C24: nop

    // 0x806A9C28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806A9C2C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806A9C30: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x806A9C34: lh          $t1, 0x9C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X9C);
    // 0x806A9C38: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806A9C3C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x806A9C40: nop

    // 0x806A9C44: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806A9C48: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806A9C4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806A9C50: swc1        $f6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
    // 0x806A9C54: lhu         $t3, 0x1C0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1C0);
    // 0x806A9C58: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x806A9C5C: beq         $t4, $zero, L_806A9CC0
    if (ctx->r12 == 0) {
        // 0x806A9C60: nop
    
            goto L_806A9CC0;
    }
    // 0x806A9C60: nop

    // 0x806A9C64: lhu         $v1, 0x12C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X12C);
    // 0x806A9C68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806A9C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806A9C70: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x806A9C74: bnel        $at, $zero, L_806A9CA4
    if (ctx->r1 != 0) {
        // 0x806A9C78: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_806A9CA4;
    }
    goto skip_2;
    // 0x806A9C78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_2:
    // 0x806A9C7C: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x806A9C80: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806A9C84: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806A9C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9C8C: jal         0x806A97E8
    // 0x806A9C90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_806A97E8(rdram, ctx);
        goto after_0;
    // 0x806A9C90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x806A9C94: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9C98: b           L_806A9CB4
    // 0x806A9C9C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
        goto L_806A9CB4;
    // 0x806A9C9C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x806A9CA0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_806A9CA4:
    // 0x806A9CA4: jal         0x806A97E8
    // 0x806A9CA8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_806A97E8(rdram, ctx);
        goto after_1;
    // 0x806A9CA8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x806A9CAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9CB0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_806A9CB4:
    // 0x806A9CB4: sh          $v1, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r3;
    // 0x806A9CB8: b           L_806A9CC8
    // 0x806A9CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806A9CC8;
    // 0x806A9CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806A9CC0:
    // 0x806A9CC0: b           L_806A9CC8
    // 0x806A9CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806A9CC8;
    // 0x806A9CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806A9CC8:
    // 0x806A9CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A9CCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806A9CD0: jr          $ra
    // 0x806A9CD4: nop

    return;
    // 0x806A9CD4: nop

;}
RECOMP_FUNC void func_804531D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804531D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804531D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804531D8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804531DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804531E0: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x804531E4: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x804531E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804531EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x804531F0: jal         0x8044EDC4
    // 0x804531F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x804531F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x804531F8: jal         0x80446D70
    // 0x804531FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x804531FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80453200: jal         0x8045310C
    // 0x80453204: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8045310C(rdram, ctx);
        goto after_2;
    // 0x80453204: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80453208: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8045320C: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80453210: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80453214: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80453218: lw          $t8, 0x6A28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A28);
    // 0x8045321C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80453224: bne         $t8, $at, L_80453234
    if (ctx->r24 != ctx->r1) {
        // 0x80453228: nop
    
            goto L_80453234;
    }
    // 0x80453228: nop

    // 0x8045322C: b           L_80453234
    // 0x80453230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80453234;
    // 0x80453230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80453234:
    // 0x80453234: jr          $ra
    // 0x80453238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80453238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804A1F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A1F04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A1F08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A1F0C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A1F10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A1F14: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804A1F18: jal         0x804A1820
    // 0x804A1F1C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A1F1C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x804A1F20: bnel        $v0, $zero, L_804A2014
    if (ctx->r2 != 0) {
        // 0x804A1F24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804A2014;
    }
    goto skip_0;
    // 0x804A1F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804A1F28: jal         0x804A2910
    // 0x804A1F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A1F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804A1F30: beql        $v0, $zero, L_804A1FB8
    if (ctx->r2 == 0) {
        // 0x804A1F34: lw          $t1, 0x138($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X138);
            goto L_804A1FB8;
    }
    goto skip_1;
    // 0x804A1F34: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    skip_1:
    // 0x804A1F38: jal         0x804A13E8
    // 0x804A1F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A13E8(rdram, ctx);
        goto after_2;
    // 0x804A1F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804A1F40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804A1F44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1F48: jal         0x80067ED8
    // 0x804A1F4C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_3;
    // 0x804A1F4C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x804A1F50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804A1F54: jal         0x80067818
    // 0x804A1F58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x804A1F58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x804A1F5C: jal         0x800653D8
    // 0x804A1F60: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x804A1F60: nop

    after_5:
    // 0x804A1F64: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x804A1F68: beq         $t8, $zero, L_804A1F84
    if (ctx->r24 == 0) {
        // 0x804A1F6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804A1F84;
    }
    // 0x804A1F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1F74: jal         0x804A27A0
    // 0x804A1F78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_6;
    // 0x804A1F78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x804A1F7C: b           L_804A2008
    // 0x804A1F80: nop

        goto L_804A2008;
    // 0x804A1F80: nop

L_804A1F84:
    // 0x804A1F84: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A1F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1F90: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x804A1F94: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x804A1F98: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804A1F9C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804A1FA0: addiu       $a2, $a2, 0xB
    ctx->r6 = ADD32(ctx->r6, 0XB);
    // 0x804A1FA4: jal         0x804A27A0
    // 0x804A1FA8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_804A27A0(rdram, ctx);
        goto after_7;
    // 0x804A1FA8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_7:
    // 0x804A1FAC: b           L_804A2008
    // 0x804A1FB0: nop

        goto L_804A2008;
    // 0x804A1FB0: nop

    // 0x804A1FB4: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
L_804A1FB8:
    // 0x804A1FB8: lui         $t9, 0x804A
    ctx->r25 = S32(RELOC_HI16(173, 0X305C) << 16);
    // 0x804A1FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1FC0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x804A1FC4: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x804A1FC8: lw          $t9, 0x349C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(173, 0X305C));
    // 0x804A1FCC: jalr        $t9
    // 0x804A1FD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x804A1FD0: nop

    after_8:
    // 0x804A1FD4: beq         $v0, $zero, L_804A2000
    if (ctx->r2 == 0) {
        // 0x804A1FD8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_804A2000;
    }
    // 0x804A1FD8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804A1FDC: addiu       $a2, $a2, 0x9
    ctx->r6 = ADD32(ctx->r6, 0X9);
    // 0x804A1FE0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804A1FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1FE8: jal         0x804A27A0
    // 0x804A1FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_9;
    // 0x804A1FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x804A1FF0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A1FF4: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x804A1FF8: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x804A1FFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_804A2000:
    // 0x804A2000: jal         0x804A1398
    // 0x804A2004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A1398(rdram, ctx);
        goto after_10;
    // 0x804A2004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_804A2008:
    // 0x804A2008: jal         0x804A1D18
    // 0x804A200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A1D18(rdram, ctx);
        goto after_11;
    // 0x804A200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x804A2010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A2014:
    // 0x804A2014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A2018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A201C: jr          $ra
    // 0x804A2020: nop

    return;
    // 0x804A2020: nop

;}
RECOMP_FUNC void func_80581040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581040: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80581044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80581048: beq         $v1, $zero, L_80581064
    if (ctx->r3 == 0) {
        // 0x8058104C: nop
    
            goto L_80581064;
    }
    // 0x8058104C: nop

    // 0x80581050: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x80581054: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80581058: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8058105C: jr          $ra
    // 0x80581060: lw          $v0, 0x6EF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF8);
    return;
    // 0x80581060: lw          $v0, 0x6EF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF8);
L_80581064:
    // 0x80581064: jr          $ra
    // 0x80581068: nop

    return;
    // 0x80581068: nop

;}
RECOMP_FUNC void func_80446164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446164: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446168: jr          $ra
    // 0x8044616C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    return;
    // 0x8044616C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8069A028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069A028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069A02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A030: jal         0x80699C60
    // 0x8069A034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x8069A034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069A038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069A03C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069A040: jal         0x8069A0F0
    // 0x8069A044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x8069A044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8069A048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A050: jr          $ra
    // 0x8069A054: nop

    return;
    // 0x8069A054: nop

;}
RECOMP_FUNC void func_80711510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711510: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80711514: lui         $t9, 0x8071
    ctx->r25 = S32(RELOC_HI16(727, 0X18D4) << 16);
    // 0x80711518: addiu       $t9, $t9, 0x2844
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(727, 0X18D4));
    // 0x8071151C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80711520: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80711524: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80711528: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8071152C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80711530: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80711534: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80711538: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8071153C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x80711540: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80711544: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80711548: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8071154C: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x80711550: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80711554: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80711558: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8071155C: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x80711560: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80711564: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80711568: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8071156C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80711570: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80711574: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80711578: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8071157C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80711580: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80711584: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80711588: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x8071158C: bnel        $at, $zero, L_807115C4
    if (ctx->r1 != 0) {
        // 0x80711590: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807115C4;
    }
    goto skip_0;
    // 0x80711590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80711594: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80711598: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8071159C: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x807115A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x807115A4: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x807115A8: bne         $at, $zero, L_807115B8
    if (ctx->r1 != 0) {
        // 0x807115AC: nop
    
            goto L_807115B8;
    }
    // 0x807115AC: nop

    // 0x807115B0: b           L_807115C4
    // 0x807115B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_807115C4;
    // 0x807115B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_807115B8:
    // 0x807115B8: b           L_807115C4
    // 0x807115BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807115C4;
    // 0x807115BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807115C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807115C4:
    // 0x807115C4: jr          $ra
    // 0x807115C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807115C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800545F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800545F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800545F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800545FC: jal         0x80064E84
    // 0x80054600: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80054600: nop

    after_0:
    // 0x80054604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005460C: jr          $ra
    // 0x80054610: nop

    return;
    // 0x80054610: nop

;}
RECOMP_FUNC void func_80790714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079071C: jal         0x80790640
    // 0x80790720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790640(rdram, ctx);
        goto after_0;
    // 0x80790720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80790724: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80790728: beq         $v0, $at, L_80790744
    if (ctx->r2 == ctx->r1) {
        // 0x8079072C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80790744;
    }
    // 0x8079072C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80790730: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80790734: beq         $v0, $at, L_80790754
    if (ctx->r2 == ctx->r1) {
        // 0x80790738: nop
    
            goto L_80790754;
    }
    // 0x80790738: nop

    // 0x8079073C: b           L_80790764
    // 0x80790740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80790764;
    // 0x80790740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80790744:
    // 0x80790744: jal         0x80790434
    // 0x80790748: nop

    func_80790434(rdram, ctx);
        goto after_1;
    // 0x80790748: nop

    after_1:
    // 0x8079074C: b           L_80790764
    // 0x80790750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80790764;
    // 0x80790750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80790754:
    // 0x80790754: jal         0x80790434
    // 0x80790758: nop

    func_80790434(rdram, ctx);
        goto after_2;
    // 0x80790758: nop

    after_2:
    // 0x8079075C: b           L_80790764
    // 0x80790760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80790764;
    // 0x80790760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80790764:
    // 0x80790764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079076C: jr          $ra
    // 0x80790770: nop

    return;
    // 0x80790770: nop

;}
RECOMP_FUNC void func_8070FCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FCFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8070FD00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8070FD04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8070FD08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8070FD0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070FD10: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8070FD14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070FD18: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8070FD1C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x8070FD20: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8070FD24: bne         $at, $zero, L_8070FD34
    if (ctx->r1 != 0) {
        // 0x8070FD28: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_8070FD34;
    }
    // 0x8070FD28: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x8070FD2C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8070FD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070FD34:
    // 0x8070FD34: sra         $s1, $v0, 1
    ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8070FD38: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8070FD3C: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x8070FD40: beq         $at, $zero, L_8070FDC4
    if (ctx->r1 == 0) {
        // 0x8070FD44: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_8070FDC4;
    }
    // 0x8070FD44: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8070FD48: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8070FD4C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X1928) << 16);
    // 0x8070FD50: addu        $at, $at, $t8
    gpr jr_addend_8070FD58 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8070FD54: lw          $t8, 0xD18($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(724, 0X1928));
    // 0x8070FD58: jr          $t8
    // 0x8070FD5C: nop

    switch (jr_addend_8070FD58 >> 2) {
        case 0: goto L_8070FD60; break;
        case 1: goto L_8070FD74; break;
        case 2: goto L_8070FD88; break;
        case 3: goto L_8070FD9C; break;
        case 4: goto L_8070FDB0; break;
        default: switch_error(__func__, 0x8070FD58, 0x80710D18);
    }
    // 0x8070FD5C: nop

L_8070FD60:
    // 0x8070FD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FD64: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FD68: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8070FD6C: jal         0x8005C27C
    // 0x8070FD70: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x8070FD70: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_0:
L_8070FD74:
    // 0x8070FD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FD78: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FD7C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8070FD80: jal         0x8005C27C
    // 0x8070FD84: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8070FD84: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_1:
L_8070FD88:
    // 0x8070FD88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FD8C: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FD90: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8070FD94: jal         0x8005C27C
    // 0x8070FD98: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8070FD98: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
L_8070FD9C:
    // 0x8070FD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FDA0: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FDA4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8070FDA8: jal         0x8005C27C
    // 0x8070FDAC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x8070FDAC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
L_8070FDB0:
    // 0x8070FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FDB4: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FDB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8070FDBC: jal         0x8005C27C
    // 0x8070FDC0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x8070FDC0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_4:
L_8070FDC4:
    // 0x8070FDC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8070FDC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070FDCC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8070FDD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8070FDD4: jr          $ra
    // 0x8070FDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8070FDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807A6CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6CF4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15C0) << 16);
    // 0x807A6CF8: lwc1        $f4, 0x72C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15C0));
    // 0x807A6CFC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6D00: jr          $ra
    // 0x807A6D04: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x807A6D04: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80530E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530E78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80530E7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80530E80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80530E84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80530E88: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x80530E8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80530E90: bnel        $t6, $zero, L_80530F44
    if (ctx->r14 != 0) {
        // 0x80530E94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80530F44;
    }
    goto skip_0;
    // 0x80530E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80530E98: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80530E9C: addiu       $a0, $zero, 0x440B
    ctx->r4 = ADD32(0, 0X440B);
    // 0x80530EA0: jal         0x80047090
    // 0x80530EA4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80530EA4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80530EA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80530EAC: lui         $at, 0x440B
    ctx->r1 = S32(0X440B << 16);
    // 0x80530EB0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80530EB4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80530EB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80530EBC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80530EC0: jal         0x8004613C
    // 0x80530EC4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80530EC4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80530EC8: beq         $v0, $zero, L_80530F40
    if (ctx->r2 == 0) {
        // 0x80530ECC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80530F40;
    }
    // 0x80530ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80530ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80530ED4: jal         0x80047F9C
    // 0x80530ED8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80530ED8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80530EDC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80530EE0: lh          $t8, 0x144($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X144);
    // 0x80530EE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80530EE8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1828) << 16);
    // 0x80530EEC: sw          $t8, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r24;
    // 0x80530EF0: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x80530EF4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80530EF8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80530EFC: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80530F00: lwc1        $f6, 0x268($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X268);
    // 0x80530F04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80530F08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80530F0C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80530F10: lwc1        $f16, 0x2618($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1828));
    // 0x80530F14: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X19F4) << 16);
    // 0x80530F18: lui         $t0, 0x8053
    ctx->r8 = S32(RELOC_HI16(342, 0X1820) << 16);
    // 0x80530F1C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80530F20: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80530F24: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x80530F28: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80530F2C: lwc1        $f4, 0x27E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X19F4));
    // 0x80530F30: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80530F34: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
    // 0x80530F38: lw          $t0, 0x2610($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(342, 0X1820));
    // 0x80530F3C: sw          $t0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r8;
L_80530F40:
    // 0x80530F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80530F44:
    // 0x80530F44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80530F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80530F4C: jr          $ra
    // 0x80530F50: nop

    return;
    // 0x80530F50: nop

;}
RECOMP_FUNC void func_8057DA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DA44: jr          $ra
    // 0x8057DA48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8057DA48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80031850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031850: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80031854: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x80031858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003185C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031860: lhu         $t7, 0x64($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X64);
    // 0x80031864: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80031868: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8003186C: bnel        $t8, $zero, L_800318B4
    if (ctx->r24 != 0) {
        // 0x80031870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800318B4;
    }
    goto skip_0;
    // 0x80031870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80031874: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003187C: bne         $v0, $zero, L_800318AC
    if (ctx->r2 != 0) {
        // 0x80031880: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800318AC;
    }
    // 0x80031880: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80031884: jal         0x80062DD4
    // 0x80031888: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80062DD4(rdram, ctx);
        goto after_0;
    // 0x80031888: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003188C: beq         $v0, $zero, L_800318B0
    if (ctx->r2 == 0) {
        // 0x80031890: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_800318B0;
    }
    // 0x80031890: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80031894: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80031898: addiu       $t9, $t9, 0x18C0
    ctx->r25 = ADD32(ctx->r25, 0X18C0);
    // 0x8003189C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800318A0: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    // 0x800318A4: b           L_800318B0
    // 0x800318A8: sw          $t0, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r8;
        goto L_800318B0;
    // 0x800318A8: sw          $t0, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r8;
L_800318AC:
    // 0x800318AC: sw          $t1, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r9;
L_800318B0:
    // 0x800318B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800318B4:
    // 0x800318B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800318B8: jr          $ra
    // 0x800318BC: nop

    return;
    // 0x800318BC: nop

;}
RECOMP_FUNC void func_804EEF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EEF38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EEF3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EEF40: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804EEF44: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804EEF48: jal         0x80067114
    // 0x804EEF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x804EEF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EEF50: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804EEF54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804EEF58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EEF5C: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X1180) << 16);
    // 0x804EEF60: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x804EEF64: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804EEF68: lwc1        $f10, -0xF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X1180));
    // 0x804EEF6C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x804EEF70: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804EEF74: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x804EEF78: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    // 0x804EEF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EEF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EEF84: jr          $ra
    // 0x804EEF88: nop

    return;
    // 0x804EEF88: nop

;}
RECOMP_FUNC void eepmgr_HandleRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D2C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D2C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007D2CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007D2D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D2D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007D2D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007D2DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007D2E0: lbu         $t6, 0x21C($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X21C);
    // 0x8007D2E4: bnel        $t6, $zero, L_8007D2F8
    if (ctx->r14 != 0) {
        // 0x8007D2E8: lbu         $t7, 0x224($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0X224);
            goto L_8007D2F8;
    }
    goto skip_0;
    // 0x8007D2E8: lbu         $t7, 0x224($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X224);
    skip_0:
    // 0x8007D2EC: b           L_8007D368
    // 0x8007D2F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D368;
    // 0x8007D2F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D2F4: lbu         $t7, 0x224($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X224);
L_8007D2F8:
    // 0x8007D2F8: bnel        $t7, $zero, L_8007D354
    if (ctx->r15 != 0) {
        // 0x8007D2FC: lhu         $a2, 0x21E($s2)
        ctx->r6 = MEM_HU(ctx->r18, 0X21E);
            goto L_8007D354;
    }
    goto skip_1;
    // 0x8007D2FC: lhu         $a2, 0x21E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X21E);
    skip_1:
    // 0x8007D300: lhu         $t8, 0x21E($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X21E);
    // 0x8007D304: lw          $s1, 0x220($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X220);
    // 0x8007D308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007D30C: blez        $t8, L_8007D348
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007D310: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007D348;
    }
    // 0x8007D310: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007D314:
    // 0x8007D314: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8007D318: jal         0x8007CFB0
    // 0x8007D31C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    eepmgr_Read(rdram, ctx);
        goto after_0;
    // 0x8007D31C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x8007D320: beql        $v0, $zero, L_8007D334
    if (ctx->r2 == 0) {
        // 0x8007D324: lhu         $t9, 0x21E($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X21E);
            goto L_8007D334;
    }
    goto skip_2;
    // 0x8007D324: lhu         $t9, 0x21E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X21E);
    skip_2:
    // 0x8007D328: b           L_8007D368
    // 0x8007D32C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D368;
    // 0x8007D32C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D330: lhu         $t9, 0x21E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X21E);
L_8007D334:
    // 0x8007D334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007D338: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8007D33C: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007D340: bnel        $at, $zero, L_8007D314
    if (ctx->r1 != 0) {
        // 0x8007D344: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007D314;
    }
    goto skip_3;
    // 0x8007D344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
L_8007D348:
    // 0x8007D348: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007D34C: sb          $t0, 0x224($s2)
    MEM_B(0X224, ctx->r18) = ctx->r8;
    // 0x8007D350: lhu         $a2, 0x21E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X21E);
L_8007D354:
    // 0x8007D354: lw          $a0, 0x220($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X220);
    // 0x8007D358: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D35C: jal         0x8008C1F0
    // 0x8007D360: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    bcopy_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D360: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    after_1:
    // 0x8007D364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007D368:
    // 0x8007D368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D36C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D370: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D374: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007D378: jr          $ra
    // 0x8007D37C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007D37C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807A7098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A7098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A709C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A70A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807A70A4: jal         0x80045A34
    // 0x807A70A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807A70A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x807A70AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A70B0: bne         $v0, $zero, L_807A70C0
    if (ctx->r2 != 0) {
        // 0x807A70B4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807A70C0;
    }
    // 0x807A70B4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807A70B8: b           L_807A70CC
    // 0x807A70BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A70CC;
    // 0x807A70BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A70C0:
    // 0x807A70C0: jal         0x807A7080
    // 0x807A70C4: nop

    func_807A7080(rdram, ctx);
        goto after_1;
    // 0x807A70C4: nop

    after_1:
    // 0x807A70C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807A70CC:
    // 0x807A70CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A70D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A70D4: jr          $ra
    // 0x807A70D8: nop

    return;
    // 0x807A70D8: nop

;}
RECOMP_FUNC void func_8006E344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E344: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006E348: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006E34C: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x8006E350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E358: lwc1        $f0, 0xAC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x8006E35C: lwc1        $f2, 0xB0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x8006E360: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E364: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x8006E368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006E36C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006E370: lbu         $t7, 0xA8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA8);
    // 0x8006E374: bnel        $t7, $at, L_8006E390
    if (ctx->r15 != ctx->r1) {
        // 0x8006E378: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8006E390;
    }
    goto skip_0;
    // 0x8006E378: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_0:
    // 0x8006E37C: jal         0x8006E2B0
    // 0x8006E380: nop

    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E380: nop

    after_0:
    // 0x8006E384: b           L_8006E3C4
    // 0x8006E388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006E3C4;
    // 0x8006E388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E38C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
L_8006E390:
    // 0x8006E390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006E394: addiu       $t8, $a3, 0xC4
    ctx->r24 = ADD32(ctx->r7, 0XC4);
    // 0x8006E398: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8006E39C: nop

    // 0x8006E3A0: bc1tl       L_8006E3C4
    if (c1cs) {
        // 0x8006E3A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E3C4;
    }
    goto skip_1;
    // 0x8006E3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006E3A8: beql        $t8, $zero, L_8006E3C4
    if (ctx->r24 == 0) {
        // 0x8006E3AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E3C4;
    }
    goto skip_2;
    // 0x8006E3AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8006E3B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006E3B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8006E3B8: jal         0x800504D0
    // 0x8006E3BC: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    func_800504D0(rdram, ctx);
        goto after_1;
    // 0x8006E3BC: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    after_1:
    // 0x8006E3C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E3C4:
    // 0x8006E3C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E3C8: jr          $ra
    // 0x8006E3CC: nop

    return;
    // 0x8006E3CC: nop

;}
RECOMP_FUNC void func_804463DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804463DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804463E0: jr          $ra
    // 0x804463E4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    return;
    // 0x804463E4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80051BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051BEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80051BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051BF4: lbu         $a2, 0x0($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X0);
    // 0x80051BF8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80051BFC: addiu       $a0, $a0, 0x1B48
    ctx->r4 = ADD32(ctx->r4, 0X1B48);
    // 0x80051C00: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80051C04: jal         0x80051AC0
    // 0x80051C08: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_80051AC0(rdram, ctx);
        goto after_0;
    // 0x80051C08: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_0:
    // 0x80051C0C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80051C10: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x80051C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051C1C: jr          $ra
    // 0x80051C20: nop

    return;
    // 0x80051C20: nop

;}
RECOMP_FUNC void func_800534C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800534C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800534C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800534C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800534CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800534D0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800534D4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800534D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800534DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800534E0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800534E4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800534E8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800534EC: lw          $t6, 0x60D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X60D0);
    // 0x800534F0: bne         $t6, $zero, L_80053510
    if (ctx->r14 != 0) {
        // 0x800534F4: nop
    
            goto L_80053510;
    }
    // 0x800534F4: nop

    // 0x800534F8: jal         0x80052CDC
    // 0x800534FC: nop

    func_80052CDC(rdram, ctx);
        goto after_0;
    // 0x800534FC: nop

    after_0:
    // 0x80053500: bne         $v0, $zero, L_80053510
    if (ctx->r2 != 0) {
        // 0x80053504: nop
    
            goto L_80053510;
    }
    // 0x80053504: nop

    // 0x80053508: b           L_80053680
    // 0x8005350C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053680;
    // 0x8005350C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80053510:
    // 0x80053510: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80053514: lw          $v0, 0x60D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60D0);
    // 0x80053518: lw          $t7, 0x16C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X16C);
    // 0x8005351C: lw          $v1, 0x1B0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X1B0);
    // 0x80053520: bnel        $v1, $zero, L_80053534
    if (ctx->r3 != 0) {
        // 0x80053524: lw          $t8, 0x20($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X20);
            goto L_80053534;
    }
    goto skip_0;
    // 0x80053524: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    skip_0:
    // 0x80053528: b           L_80053680
    // 0x8005352C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053680;
    // 0x8005352C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80053530: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
L_80053534:
    // 0x80053534: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80053538: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8005353C: bnel        $t9, $zero, L_80053550
    if (ctx->r25 != 0) {
        // 0x80053540: trunc.w.s   $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
            goto L_80053550;
    }
    goto skip_1;
    // 0x80053540: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    skip_1:
    // 0x80053544: b           L_80053680
    // 0x80053548: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053680;
    // 0x80053548: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005354C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
L_80053550:
    // 0x80053550: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80053554: nop

    // 0x80053558: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8005355C: jal         0x8006A99C
    // 0x80053560: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x80053560: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80053564: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80053568: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8005356C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80053570: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80053574: nop

    // 0x80053578: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8005357C: jal         0x8006A99C
    // 0x80053580: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x80053580: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80053584: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80053588: bltz        $v0, L_8005359C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005358C: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_8005359C;
    }
    // 0x8005358C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80053590: lh          $a0, 0x1C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1C);
    // 0x80053594: bgez        $a0, L_800535A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80053598: nop
    
            goto L_800535A4;
    }
    // 0x80053598: nop

L_8005359C:
    // 0x8005359C: b           L_80053680
    // 0x800535A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053680;
    // 0x800535A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800535A4:
    // 0x800535A4: jal         0x8006ABF0
    // 0x800535A8: sh          $a1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r5;
    func_8006ABF0(rdram, ctx);
        goto after_3;
    // 0x800535A8: sh          $a1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r5;
    after_3:
    // 0x800535AC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800535B0: bne         $v0, $at, L_800535C0
    if (ctx->r2 != ctx->r1) {
        // 0x800535B4: sh          $v0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r2;
            goto L_800535C0;
    }
    // 0x800535B4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800535B8: b           L_80053680
    // 0x800535BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053680;
    // 0x800535BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800535C0:
    // 0x800535C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800535C4: lbu         $t4, 0x1E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1E);
    // 0x800535C8: lw          $t3, 0x174($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X174);
    // 0x800535CC: andi        $t5, $t4, 0xF8
    ctx->r13 = ctx->r12 & 0XF8;
    // 0x800535D0: xori        $t6, $t5, 0x28
    ctx->r14 = ctx->r13 ^ 0X28;
    // 0x800535D4: lbu         $v0, 0x10($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X10);
    // 0x800535D8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800535DC: beq         $v0, $zero, L_800535F4
    if (ctx->r2 == 0) {
        // 0x800535E0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800535F4;
    }
    // 0x800535E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800535E4: beql        $t6, $t7, L_800535F8
    if (ctx->r14 == ctx->r15) {
        // 0x800535E8: lbu         $v0, 0x1F($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X1F);
            goto L_800535F8;
    }
    goto skip_2;
    // 0x800535E8: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    skip_2:
    // 0x800535EC: b           L_80053680
    // 0x800535F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053680;
    // 0x800535F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800535F4:
    // 0x800535F4: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
L_800535F8:
    // 0x800535F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800535FC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80053600: srl         $t9, $v0, 6
    ctx->r25 = S32(U32(ctx->r2) >> 6);
    // 0x80053604: bnel        $t9, $at, L_80053680
    if (ctx->r25 != ctx->r1) {
        // 0x80053608: lhu         $v0, 0x1E($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X1E);
            goto L_80053680;
    }
    goto skip_3;
    // 0x80053608: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    skip_3:
    // 0x8005360C: lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XC);
    // 0x80053610: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80053614: andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // 0x80053618: beq         $v1, $at, L_80053624
    if (ctx->r3 == ctx->r1) {
        // 0x8005361C: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_80053624;
    }
    // 0x8005361C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80053620: bne         $v1, $at, L_80053674
    if (ctx->r3 != ctx->r1) {
        // 0x80053624: lui         $at, 0x406F
        ctx->r1 = S32(0X406F << 16);
            goto L_80053674;
    }
L_80053624:
    // 0x80053624: lui         $at, 0x406F
    ctx->r1 = S32(0X406F << 16);
    // 0x80053628: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8005362C: jal         0x80046DEC
    // 0x80053630: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_80046DEC(rdram, ctx);
        goto after_4;
    // 0x80053630: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_4:
    // 0x80053634: beq         $v0, $zero, L_80053674
    if (ctx->r2 == 0) {
        // 0x80053638: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80053674;
    }
    // 0x80053638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005363C: jal         0x8006F324
    // 0x80053640: nop

    func_8006F324(rdram, ctx);
        goto after_5;
    // 0x80053640: nop

    after_5:
    // 0x80053644: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    // 0x80053648: lh          $a0, 0x1C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1C);
    // 0x8005364C: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x80053650: andi        $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 & 0XF800;
    // 0x80053654: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80053658: jal         0x8006B1C8
    // 0x8005365C: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    func_8006B1C8(rdram, ctx);
        goto after_6;
    // 0x8005365C: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    after_6:
    // 0x80053660: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80053664: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80053668: lw          $t1, 0xABC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XABC);
    // 0x8005366C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80053670: sw          $t2, 0xABC($v1)
    MEM_W(0XABC, ctx->r3) = ctx->r10;
L_80053674:
    // 0x80053674: b           L_80053680
    // 0x80053678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053680;
    // 0x80053678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005367C: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
L_80053680:
    // 0x80053680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80053688: jr          $ra
    // 0x8005368C: nop

    return;
    // 0x8005368C: nop

;}
RECOMP_FUNC void func_80454318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045431C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80454320: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454324: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80454328: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8045432C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454330: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80454334: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80454338: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045433C: lwc1        $f4, 0x6C84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x80454340: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454344: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80454348: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045434C: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x80454350: lwc1        $f12, 0x6C84($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X6C84);
    // 0x80454354: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80454358: nop

    // 0x8045435C: bc1f        L_80454374
    if (!c1cs) {
        // 0x80454360: nop
    
            goto L_80454374;
    }
    // 0x80454360: nop

    // 0x80454364: jal         0x80450490
    // 0x80454368: nop

    func_80450490(rdram, ctx);
        goto after_0;
    // 0x80454368: nop

    after_0:
    // 0x8045436C: b           L_80454390
    // 0x80454370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80454390;
    // 0x80454370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80454374:
    // 0x80454374: jal         0x804448C8
    // 0x80454378: nop

    func_804448C8(rdram, ctx);
        goto after_1;
    // 0x80454378: nop

    after_1:
    // 0x8045437C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80454380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80454384: jal         0x8006E0FC
    // 0x80454388: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x80454388: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_2:
    // 0x8045438C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80454390:
    // 0x80454390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80454394: jr          $ra
    // 0x80454398: nop

    return;
    // 0x80454398: nop

;}
RECOMP_FUNC void func_8067B194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B194: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8067B198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067B19C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067B1A0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067B1A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067B1A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067B1AC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067B1B0: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8067B1B4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2D38) << 16);
    // 0x8067B1B8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8067B1BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067B1C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067B1C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8067B1C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067B1CC: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x8067B1D0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8067B1D4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067B1D8: beq         $t7, $zero, L_8067B228
    if (ctx->r15 == 0) {
        // 0x8067B1DC: lwc1        $f4, -0x3618($at)
        ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2D38));
            goto L_8067B228;
    }
    // 0x8067B1DC: lwc1        $f4, -0x3618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2D38));
    // 0x8067B1E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067B1E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067B1E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067B1EC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8067B1F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067B1F4: nop

    // 0x8067B1F8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8067B1FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067B200: nop

    // 0x8067B204: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067B208: bne         $t7, $zero, L_8067B220
    if (ctx->r15 != 0) {
        // 0x8067B20C: nop
    
            goto L_8067B220;
    }
    // 0x8067B20C: nop

    // 0x8067B210: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8067B214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067B218: b           L_8067B238
    // 0x8067B21C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067B238;
    // 0x8067B21C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067B220:
    // 0x8067B220: b           L_8067B238
    // 0x8067B224: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067B238;
    // 0x8067B224: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8067B228:
    // 0x8067B228: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8067B22C: nop

    // 0x8067B230: bltz        $t7, L_8067B220
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067B234: nop
    
            goto L_8067B220;
    }
    // 0x8067B234: nop

L_8067B238:
    // 0x8067B238: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x8067B23C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8067B240: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067B244: lui         $t3, 0x8068
    ctx->r11 = S32(RELOC_HI16(541, 0X2FF0) << 16);
    // 0x8067B248: bgez        $t8, L_8067B260
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8067B24C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8067B260;
    }
    // 0x8067B24C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8067B250: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067B254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067B258: nop

    // 0x8067B25C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8067B260:
    // 0x8067B260: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8067B264: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8067B268: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2E88) << 16);
    // 0x8067B26C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067B270: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8067B274: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8067B278: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8067B27C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8067B280: lwc1        $f8, -0x34C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2E88));
    // 0x8067B284: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067B288: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8067B28C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8067B290: nop

    // 0x8067B294: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8067B298: beql        $t1, $zero, L_8067B2E8
    if (ctx->r9 == 0) {
        // 0x8067B29C: mfc1        $t1, $f18
        ctx->r9 = (int32_t)ctx->f18.u32l;
            goto L_8067B2E8;
    }
    goto skip_0;
    // 0x8067B29C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x8067B2A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067B2A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8067B2A8: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8067B2AC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8067B2B0: nop

    // 0x8067B2B4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8067B2B8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8067B2BC: nop

    // 0x8067B2C0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8067B2C4: bne         $t1, $zero, L_8067B2DC
    if (ctx->r9 != 0) {
        // 0x8067B2C8: nop
    
            goto L_8067B2DC;
    }
    // 0x8067B2C8: nop

    // 0x8067B2CC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8067B2D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067B2D4: b           L_8067B2F4
    // 0x8067B2D8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8067B2F4;
    // 0x8067B2D8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8067B2DC:
    // 0x8067B2DC: b           L_8067B2F4
    // 0x8067B2E0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8067B2F4;
    // 0x8067B2E0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8067B2E4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
L_8067B2E8:
    // 0x8067B2E8: nop

    // 0x8067B2EC: bltz        $t1, L_8067B2DC
    if (SIGNED(ctx->r9) < 0) {
        // 0x8067B2F0: nop
    
            goto L_8067B2DC;
    }
    // 0x8067B2F0: nop

L_8067B2F4:
    // 0x8067B2F4: and         $t2, $t1, $v1
    ctx->r10 = ctx->r9 & ctx->r3;
    // 0x8067B2F8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8067B2FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8067B300: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067B304: bgez        $t2, L_8067B318
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8067B308: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8067B318;
    }
    // 0x8067B308: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067B30C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067B310: nop

    // 0x8067B314: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8067B318:
    // 0x8067B318: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8067B31C: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x8067B320: lw          $t3, -0x3360($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(541, 0X2FF0));
    // 0x8067B324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067B328: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8067B32C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8067B330: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8067B334: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8067B338: beql        $t0, $t4, L_8067B35C
    if (ctx->r8 == ctx->r12) {
        // 0x8067B33C: lw          $t6, 0xC($a1)
        ctx->r14 = MEM_W(ctx->r5, 0XC);
            goto L_8067B35C;
    }
    goto skip_1;
    // 0x8067B33C: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    skip_1:
    // 0x8067B340: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8067B344: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8067B348: jal         0x8067B088
    // 0x8067B34C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8067B088(rdram, ctx);
        goto after_0;
    // 0x8067B34C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_0:
    // 0x8067B350: b           L_8067B378
    // 0x8067B354: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
        goto L_8067B378;
    // 0x8067B354: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8067B358: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
L_8067B35C:
    // 0x8067B35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067B360: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8067B364: beql        $t5, $t6, L_8067B37C
    if (ctx->r13 == ctx->r14) {
        // 0x8067B368: lw          $t7, 0x128($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X128);
            goto L_8067B37C;
    }
    goto skip_2;
    // 0x8067B368: lw          $t7, 0x128($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X128);
    skip_2:
    // 0x8067B36C: jal         0x8067B088
    // 0x8067B370: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_8067B088(rdram, ctx);
        goto after_1;
    // 0x8067B370: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8067B374: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
L_8067B378:
    // 0x8067B378: lw          $t7, 0x128($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X128);
L_8067B37C:
    // 0x8067B37C: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8067B380: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8067B384: beq         $t7, $zero, L_8067B3AC
    if (ctx->r15 == 0) {
        // 0x8067B388: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_8067B3AC;
    }
    // 0x8067B388: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8067B38C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8067B390: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2FE4) << 16);
    // 0x8067B394: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8067B398: lwc1        $f4, -0x336C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2FE4));
    // 0x8067B39C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8067B3A0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8067B3A4: b           L_8067B3C4
    // 0x8067B3A8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
        goto L_8067B3C4;
    // 0x8067B3A8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_8067B3AC:
    // 0x8067B3AC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2FE4) << 16);
    // 0x8067B3B0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8067B3B4: lwc1        $f16, -0x336C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2FE4));
    // 0x8067B3B8: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8067B3BC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8067B3C0: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
L_8067B3C4:
    // 0x8067B3C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067B3C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8067B3CC: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8067B3D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8067B3D4: nop

    // 0x8067B3D8: bc1fl       L_8067B3F4
    if (!c1cs) {
        // 0x8067B3DC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8067B3F4;
    }
    goto skip_3;
    // 0x8067B3DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x8067B3E0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067B3E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067B3E8: b           L_8067B414
    // 0x8067B3EC: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
        goto L_8067B414;
    // 0x8067B3EC: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8067B3F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8067B3F4:
    // 0x8067B3F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067B3F8: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8067B3FC: nop

    // 0x8067B400: bc1fl       L_8067B418
    if (!c1cs) {
        // 0x8067B404: swc1        $f12, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
            goto L_8067B418;
    }
    goto skip_4;
    // 0x8067B404: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    skip_4:
    // 0x8067B408: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067B40C: nop

    // 0x8067B410: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_8067B414:
    // 0x8067B414: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
L_8067B418:
    // 0x8067B418: lw          $t8, 0x128($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X128);
    // 0x8067B41C: beql        $t8, $zero, L_8067B42C
    if (ctx->r24 == 0) {
        // 0x8067B420: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_8067B42C;
    }
    goto skip_5;
    // 0x8067B420: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    skip_5:
    // 0x8067B424: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8067B428: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_8067B42C:
    // 0x8067B42C: jal         0x80066DE4
    // 0x8067B430: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8067B430: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8067B434: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8067B438: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2FD8) << 16);
    // 0x8067B43C: addiu       $t9, $t9, -0x3378
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(541, 0X2FD8));
    // 0x8067B440: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8067B444: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8067B448: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8067B44C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8067B450: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8067B454: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8067B458: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067B45C: jal         0x80066E88
    // 0x8067B460: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8067B460: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8067B464: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8067B468: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8067B46C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8067B470: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8067B474: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8067B478: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8067B47C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8067B480: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067B484: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x8067B488: add.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8067B48C: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8067B490: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8067B494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067B498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067B49C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8067B4A0: jr          $ra
    // 0x8067B4A4: nop

    return;
    // 0x8067B4A4: nop

;}
RECOMP_FUNC void func_807168C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807168C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807168CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807168D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807168D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807168D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807168DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807168E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807168E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807168E8: addiu       $t6, $zero, 0x960
    ctx->r14 = ADD32(0, 0X960);
    // 0x807168EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807168F0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807168F4: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x807168F8: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x807168FC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716900: jal         0x8071637C
    // 0x80716904: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x80716904: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80716908: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8071690C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716910: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80716914: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80716918: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8071691C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80716920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80716924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80716928: jr          $ra
    // 0x8071692C: nop

    return;
    // 0x8071692C: nop

;}
RECOMP_FUNC void func_80581458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058145C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581460: jal         0x80580C70
    // 0x80581464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80581464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581468: jal         0x8058121C
    // 0x8058146C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8058121C(rdram, ctx);
        goto after_1;
    // 0x8058146C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581470: jal         0x805813E4
    // 0x80581474: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805813E4(rdram, ctx);
        goto after_2;
    // 0x80581474: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80581478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8058147C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581480: jr          $ra
    // 0x80581484: nop

    return;
    // 0x80581484: nop

;}
RECOMP_FUNC void func_805681B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805681B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805681B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805681B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805681BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805681C0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805681C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805681C8: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x805681CC: bnel        $t6, $zero, L_80568234
    if (ctx->r14 != 0) {
        // 0x805681D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80568234;
    }
    goto skip_0;
    // 0x805681D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x805681D4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805681D8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805681DC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x805681E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805681E4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805681E8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805681EC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805681F0: nop

    // 0x805681F4: bc1fl       L_80568230
    if (!c1cs) {
        // 0x805681F8: sw          $zero, 0x18($v1)
        MEM_W(0X18, ctx->r3) = 0;
            goto L_80568230;
    }
    goto skip_1;
    // 0x805681F8: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    skip_1:
    // 0x805681FC: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80568200: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80568204: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80568208: bnel        $t7, $zero, L_80568234
    if (ctx->r15 != 0) {
        // 0x8056820C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80568234;
    }
    goto skip_2;
    // 0x8056820C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x80568210: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80568214: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80568218: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8056821C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80568220: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80568224: b           L_80568230
    // 0x80568228: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
        goto L_80568230;
    // 0x80568228: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8056822C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_80568230:
    // 0x80568230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80568234:
    // 0x80568234: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x80568238: jal         0x80567DD4
    // 0x8056823C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80567DD4(rdram, ctx);
        goto after_0;
    // 0x8056823C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80568240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80568244: jal         0x80048F84
    // 0x80568248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80568248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8056824C: jal         0x805677F4
    // 0x80568250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805677F4(rdram, ctx);
        goto after_2;
    // 0x80568250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80568254: jal         0x80567C4C
    // 0x80568258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80567C4C(rdram, ctx);
        goto after_3;
    // 0x80568258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8056825C: bne         $v0, $zero, L_805682B0
    if (ctx->r2 != 0) {
        // 0x80568260: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_805682B0;
    }
    // 0x80568260: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80568264: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80568268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8056826C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80568270: bne         $at, $zero, L_80568280
    if (ctx->r1 != 0) {
        // 0x80568274: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80568280;
    }
    // 0x80568274: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80568278: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x8056827C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80568280:
    // 0x80568280: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80568284: bne         $v0, $at, L_805682B0
    if (ctx->r2 != ctx->r1) {
        // 0x80568288: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_805682B0;
    }
    // 0x80568288: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8056828C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80568290: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80568294: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21B0) << 16);
    // 0x80568298: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8056829C: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x805682A0: lwc1        $f8, -0x68A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21B0));
    // 0x805682A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x805682A8: jal         0x80569310
    // 0x805682AC: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    func_80569310(rdram, ctx);
        goto after_4;
    // 0x805682AC: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_4:
L_805682B0:
    // 0x805682B0: jal         0x80567E60
    // 0x805682B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80567E60(rdram, ctx);
        goto after_5;
    // 0x805682B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x805682B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805682BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805682C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805682C4: jr          $ra
    // 0x805682C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805682C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805A20D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A20D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A20DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A20E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A20E4: jal         0x8004700C
    // 0x805A20E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A20E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805A20EC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A20F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805A20F4: jal         0x800653D8
    // 0x805A20F8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805A20F8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x805A20FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805A2100: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805A2104: beql        $a1, $zero, L_805A2274
    if (ctx->r5 == 0) {
        // 0x805A2108: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A2274;
    }
    goto skip_0;
    // 0x805A2108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A210C: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x805A2110: beq         $a0, $zero, L_805A211C
    if (ctx->r4 == 0) {
        // 0x805A2114: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_805A211C;
    }
    // 0x805A2114: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x805A2118: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
L_805A211C:
    // 0x805A211C: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x805A2120: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1C48) << 16);
    // 0x805A2124: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A2128: lbu         $t8, 0x2FB8($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(411, 0X1C48));
    // 0x805A212C: sh          $t8, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r24;
    // 0x805A2130: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x805A2134: bnel        $t9, $zero, L_805A21DC
    if (ctx->r25 != 0) {
        // 0x805A2138: lwc1        $f16, 0x84($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
            goto L_805A21DC;
    }
    goto skip_1;
    // 0x805A2138: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    skip_1:
    // 0x805A213C: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x805A2140: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(411, 0X1C30) << 16);
    // 0x805A2144: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x805A2148: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x805A214C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805A2150: lw          $t1, 0x2FA0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(411, 0X1C30));
    // 0x805A2154: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x805A2158: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x805A215C: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
    // 0x805A2160: bne         $at, $zero, L_805A21D8
    if (ctx->r1 != 0) {
        // 0x805A2164: sw          $t1, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r9;
            goto L_805A21D8;
    }
    // 0x805A2164: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x805A2168: bne         $t4, $zero, L_805A218C
    if (ctx->r12 != 0) {
        // 0x805A216C: sw          $zero, 0x14($v1)
        MEM_W(0X14, ctx->r3) = 0;
            goto L_805A218C;
    }
    // 0x805A216C: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x805A2170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A2174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2178: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805A217C: jal         0x805A2B28
    // 0x805A2180: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_2;
    // 0x805A2180: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x805A2184: b           L_805A2274
    // 0x805A2188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A2274;
    // 0x805A2188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A218C:
    // 0x805A218C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x805A2190: jal         0x80065414
    // 0x805A2194: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80065414(rdram, ctx);
        goto after_3;
    // 0x805A2194: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x805A2198: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805A219C: cvt.s.d     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
    // 0x805A21A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805A21A4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x805A21A8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x805A21AC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x805A21B0: nop

    // 0x805A21B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A21B8: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805A21BC: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x805A21C0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x805A21C4: nop

    // 0x805A21C8: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x805A21CC: bgtz        $t7, L_805A21D8
    if (SIGNED(ctx->r15) > 0) {
        // 0x805A21D0: sw          $t7, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r15;
            goto L_805A21D8;
    }
    // 0x805A21D0: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
    // 0x805A21D4: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
L_805A21D8:
    // 0x805A21D8: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
L_805A21DC:
    // 0x805A21DC: lwc1        $f18, 0x84($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805A21E0: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1D58) << 16);
    // 0x805A21E4: lwc1        $f6, 0x30C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1D58));
    // 0x805A21E8: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805A21EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A21F0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x805A21F4: nop

    // 0x805A21F8: bc1f        L_805A2268
    if (!c1cs) {
        // 0x805A21FC: nop
    
            goto L_805A2268;
    }
    // 0x805A21FC: nop

    // 0x805A2200: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805A2204: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805A2208: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x805A220C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A2210: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805A2214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A2218: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805A221C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A2220: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x805A2224: nop

    // 0x805A2228: bc1f        L_805A2268
    if (!c1cs) {
        // 0x805A222C: nop
    
            goto L_805A2268;
    }
    // 0x805A222C: nop

    // 0x805A2230: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x805A2234: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805A2238: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x805A223C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805A2240: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805A2244: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805A2248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A224C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x805A2250: nop

    // 0x805A2254: bc1f        L_805A2260
    if (!c1cs) {
        // 0x805A2258: nop
    
            goto L_805A2260;
    }
    // 0x805A2258: nop

    // 0x805A225C: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
L_805A2260:
    // 0x805A2260: jal         0x805A2B28
    // 0x805A2264: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_4;
    // 0x805A2264: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_805A2268:
    // 0x805A2268: jal         0x805A1BA8
    // 0x805A226C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_5;
    // 0x805A226C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805A2270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A2274:
    // 0x805A2274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A2278: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A227C: jr          $ra
    // 0x805A2280: nop

    return;
    // 0x805A2280: nop

;}
RECOMP_FUNC void func_8004C13C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C13C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004C140: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004C144: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004C148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C14C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004C150: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004C154: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004C158: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004C15C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004C160: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004C164: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004C168: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004C16C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004C170: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004C174: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8004C178: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C17C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8004C180: jal         0x80049864
    // 0x8004C184: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004C184: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004C188: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8004C18C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004C190: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8004C194: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004C198: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8004C19C: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8004C1A0: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8004C1A4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C1A8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C1AC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004C1B0: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8004C1B4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004C1B8: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x8004C1BC: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C1C0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004C1C4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004C1C8: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8004C1CC: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004C1D0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8004C1D4: subu        $t6, $t5, $v1
    ctx->r14 = SUB32(ctx->r13, ctx->r3);
    // 0x8004C1D8: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8004C1DC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8004C1E0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8004C1E4: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
    // 0x8004C1E8: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004C1EC: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x8004C1F0: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x8004C1F4: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    // 0x8004C1F8: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    // 0x8004C1FC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8004C200: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8004C204: srl         $t8, $a0, 6
    ctx->r24 = S32(U32(ctx->r4) >> 6);
    // 0x8004C208: andi        $t1, $a0, 0x3F
    ctx->r9 = ctx->r4 & 0X3F;
    // 0x8004C20C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004C210: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004C214: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004C218: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004C21C: lw          $t5, 0xA24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA24);
    // 0x8004C220: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004C224: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8004C228: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x8004C22C: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8004C230: addiu       $t3, $t0, 0xC
    ctx->r11 = ADD32(ctx->r8, 0XC);
    // 0x8004C234: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004C238: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004C23C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004C240: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8004C244: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
    // 0x8004C248: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x8004C24C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C250: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8004C254: andi        $t5, $t8, 0x3F
    ctx->r13 = ctx->r24 & 0X3F;
    // 0x8004C258: xori        $t1, $t5, 0x3
    ctx->r9 = ctx->r13 ^ 0X3;
    // 0x8004C25C: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
    // 0x8004C260: andi        $t7, $t4, 0x1
    ctx->r15 = ctx->r12 & 0X1;
    // 0x8004C264: and         $t9, $t7, $t1
    ctx->r25 = ctx->r15 & ctx->r9;
    // 0x8004C268: beq         $t9, $zero, L_8004C300
    if (ctx->r25 == 0) {
        // 0x8004C26C: sub.s       $f12, $f0, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_8004C300;
    }
    // 0x8004C26C: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004C270: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x8004C274: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004C278: srav        $t8, $t2, $t4
    ctx->r24 = S32(SIGNED(ctx->r10) >> (ctx->r12 & 31));
    // 0x8004C27C: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x8004C280: beq         $t5, $zero, L_8004C300
    if (ctx->r13 == 0) {
        // 0x8004C284: lhu         $t7, 0x38($sp)
        ctx->r15 = MEM_HU(ctx->r29, 0X38);
            goto L_8004C300;
    }
    // 0x8004C284: lhu         $t7, 0x38($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X38);
    // 0x8004C288: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x8004C28C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8004C290: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004C294: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C298: jal         0x8004BF6C
    // 0x8004C29C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_8004BF6C(rdram, ctx);
        goto after_1;
    // 0x8004C29C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8004C2A0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8004C2A4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C2A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C2AC: slti        $at, $v1, -0x8
    ctx->r1 = SIGNED(ctx->r3) < -0X8 ? 1 : 0;
    // 0x8004C2B0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C2B4: beq         $at, $zero, L_8004C2E8
    if (ctx->r1 == 0) {
        // 0x8004C2B8: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8004C2E8;
    }
    // 0x8004C2B8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004C2BC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8004C2C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8004C2C4: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x8004C2C8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004C2CC: lwc1        $f6, 0x84($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X84);
    // 0x8004C2D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C2D4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8004C2D8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C2DC: lwc1        $f8, 0x8C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8C4);
    // 0x8004C2E0: b           L_8004C308
    // 0x8004C2E4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
        goto L_8004C308;
    // 0x8004C2E4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_8004C2E8:
    // 0x8004C2E8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8004C2EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004C2F0: sb          $t3, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r11;
    // 0x8004C2F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C2F8: b           L_8004C308
    // 0x8004C2FC: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
        goto L_8004C308;
    // 0x8004C2FC: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
L_8004C300:
    // 0x8004C300: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004C304: nop

L_8004C308:
    // 0x8004C308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004C30C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004C310: jr          $ra
    // 0x8004C314: nop

    return;
    // 0x8004C314: nop

;}
RECOMP_FUNC void func_8006F178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F180: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8006F184: addiu       $at, $zero, 0x406F
    ctx->r1 = ADD32(0, 0X406F);
    // 0x8006F188: beq         $v0, $at, L_8006F1B8
    if (ctx->r2 == ctx->r1) {
        // 0x8006F18C: addiu       $at, $zero, 0x4070
        ctx->r1 = ADD32(0, 0X4070);
            goto L_8006F1B8;
    }
    // 0x8006F18C: addiu       $at, $zero, 0x4070
    ctx->r1 = ADD32(0, 0X4070);
    // 0x8006F190: beq         $v0, $at, L_8006F1C8
    if (ctx->r2 == ctx->r1) {
        // 0x8006F194: addiu       $at, $zero, 0x466B
        ctx->r1 = ADD32(0, 0X466B);
            goto L_8006F1C8;
    }
    // 0x8006F194: addiu       $at, $zero, 0x466B
    ctx->r1 = ADD32(0, 0X466B);
    // 0x8006F198: beq         $v0, $at, L_8006F1D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006F19C: addiu       $at, $zero, 0x473C
        ctx->r1 = ADD32(0, 0X473C);
            goto L_8006F1D8;
    }
    // 0x8006F19C: addiu       $at, $zero, 0x473C
    ctx->r1 = ADD32(0, 0X473C);
    // 0x8006F1A0: beq         $v0, $at, L_8006F1D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006F1A4: addiu       $at, $zero, 0x473D
        ctx->r1 = ADD32(0, 0X473D);
            goto L_8006F1D8;
    }
    // 0x8006F1A4: addiu       $at, $zero, 0x473D
    ctx->r1 = ADD32(0, 0X473D);
    // 0x8006F1A8: beq         $v0, $at, L_8006F1D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006F1AC: nop
    
            goto L_8006F1D8;
    }
    // 0x8006F1AC: nop

    // 0x8006F1B0: b           L_8006F1E4
    // 0x8006F1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006F1E4;
    // 0x8006F1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F1B8:
    // 0x8006F1B8: jal         0x8006F1F0
    // 0x8006F1BC: nop

    func_8006F1F0(rdram, ctx);
        goto after_0;
    // 0x8006F1BC: nop

    after_0:
    // 0x8006F1C0: b           L_8006F1E4
    // 0x8006F1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006F1E4;
    // 0x8006F1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F1C8:
    // 0x8006F1C8: jal         0x8006E9EC
    // 0x8006F1CC: nop

    func_8006E9EC(rdram, ctx);
        goto after_1;
    // 0x8006F1CC: nop

    after_1:
    // 0x8006F1D0: b           L_8006F1E4
    // 0x8006F1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006F1E4;
    // 0x8006F1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F1D8:
    // 0x8006F1D8: jal         0x8006EA60
    // 0x8006F1DC: nop

    func_8006EA60(rdram, ctx);
        goto after_2;
    // 0x8006F1DC: nop

    after_2:
    // 0x8006F1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F1E4:
    // 0x8006F1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1E8: jr          $ra
    // 0x8006F1EC: nop

    return;
    // 0x8006F1EC: nop

;}
RECOMP_FUNC void func_807AE88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE88C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE894: jal         0x807AE060
    // 0x807AE898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807AE060(rdram, ctx);
        goto after_0;
    // 0x807AE898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AE89C: beql        $v0, $zero, L_807AE8B0
    if (ctx->r2 == 0) {
        // 0x807AE8A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AE8B0;
    }
    goto skip_0;
    // 0x807AE8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807AE8A4: jal         0x807AE174
    // 0x807AE8A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807AE174(rdram, ctx);
        goto after_1;
    // 0x807AE8A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807AE8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AE8B0:
    // 0x807AE8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE8B4: jr          $ra
    // 0x807AE8B8: nop

    return;
    // 0x807AE8B8: nop

;}
RECOMP_FUNC void blkclr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084820: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80084824: bne         $at, $zero, L_8008489C
    if (ctx->r1 != 0) {
        // 0x80084828: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8008489C;
    }
    // 0x80084828: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8008482C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80084830: beq         $v1, $zero, L_80084840
    if (ctx->r3 == 0) {
        // 0x80084834: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80084840;
    }
    // 0x80084834: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80084838: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8008483C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80084840:
    // 0x80084840: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80084844: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084848: beq         $a3, $zero, L_8008487C
    if (ctx->r7 == 0) {
        // 0x8008484C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008487C;
    }
    // 0x8008484C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80084850: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084854:
    // 0x80084854: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80084858: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8008485C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80084860: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80084864: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80084868: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8008486C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80084870: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80084874: bne         $a0, $a3, L_80084854
    if (ctx->r4 != ctx->r7) {
        // 0x80084878: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084854;
    }
    // 0x80084878: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008487C:
    // 0x8008487C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80084880: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084884: beq         $a3, $zero, L_8008489C
    if (ctx->r7 == 0) {
        // 0x80084888: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008489C;
    }
    // 0x80084888: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8008488C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084890:
    // 0x80084890: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80084894: bne         $a0, $a3, L_80084890
    if (ctx->r4 != ctx->r7) {
        // 0x80084898: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084890;
    }
    // 0x80084898: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008489C:
    // 0x8008489C: blez        $a1, L_800848B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800848A0: nop
    
            goto L_800848B4;
    }
    // 0x800848A0: nop

    // 0x800848A4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800848A8:
    // 0x800848A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800848AC: bne         $a0, $a1, L_800848A8
    if (ctx->r4 != ctx->r5) {
        // 0x800848B0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800848A8;
    }
    // 0x800848B0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800848B4:
    // 0x800848B4: jr          $ra
    // 0x800848B8: nop

    return;
    // 0x800848B8: nop

    // 0x800848BC: nop

;}
RECOMP_FUNC void func_8006E444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E44C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E450: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E454: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8006E458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006E45C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006E460: lbu         $t6, 0xA8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA8);
    // 0x8006E464: bnel        $t6, $at, L_8006E480
    if (ctx->r14 != ctx->r1) {
        // 0x8006E468: lw          $a0, 0x16C($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X16C);
            goto L_8006E480;
    }
    goto skip_0;
    // 0x8006E468: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    skip_0:
    // 0x8006E46C: jal         0x8006E2B0
    // 0x8006E470: nop

    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E470: nop

    after_0:
    // 0x8006E474: b           L_8006E490
    // 0x8006E478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006E490;
    // 0x8006E478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E47C: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
L_8006E480:
    // 0x8006E480: lw          $a1, 0xAC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XAC);
    // 0x8006E484: jal         0x800504D0
    // 0x8006E488: lw          $a2, 0xB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB0);
    func_800504D0(rdram, ctx);
        goto after_1;
    // 0x8006E488: lw          $a2, 0xB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB0);
    after_1:
    // 0x8006E48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E490:
    // 0x8006E490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E494: jr          $ra
    // 0x8006E498: nop

    return;
    // 0x8006E498: nop

;}
RECOMP_FUNC void func_806DF1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF1B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806DF1BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF1C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806DF1C4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806DF1C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DF1CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806DF1D0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806DF1D4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x806DF1D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DF1DC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806DF1E0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806DF1E4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x806DF1E8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806DF1EC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806DF1F0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806DF1F4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806DF1F8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806DF1FC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806DF200: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806DF204: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x806DF208: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806DF20C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806DF210: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x806DF214: jalr        $t9
    // 0x806DF218: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806DF218: nop

    after_0:
    // 0x806DF21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF220: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806DF224: jr          $ra
    // 0x806DF228: nop

    return;
    // 0x806DF228: nop

;}
RECOMP_FUNC void func_80473248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473248: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8047324C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80473250: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80473254: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80473258: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8047325C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80473260: lwc1        $f0, 0x174($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X174);
    // 0x80473264: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80473268: jal         0x80049018
    // 0x8047326C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8047326C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80473270: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80473274: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80473278: bne         $v0, $zero, L_80473288
    if (ctx->r2 != 0) {
        // 0x8047327C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80473288;
    }
    // 0x8047327C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80473280: b           L_8047328C
    // 0x80473284: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
        goto L_8047328C;
    // 0x80473284: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
L_80473288:
    // 0x80473288: sub.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f12.fl;
L_8047328C:
    // 0x8047328C: jal         0x80066DE4
    // 0x80473290: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80473290: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80473294: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80473298: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8047329C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1474) << 16);
    // 0x804732A0: lwc1        $f8, 0x4604($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1474));
    // 0x804732A4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804732A8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804732AC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804732B0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804732B4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x804732B8: jal         0x80066E88
    // 0x804732BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x804732BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x804732C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804732C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804732C8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1478) << 16);
    // 0x804732CC: lwc1        $f4, 0x4608($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1478));
    // 0x804732D0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804732D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804732D8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804732DC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804732E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x804732E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804732E8: bnel        $t7, $zero, L_80473328
    if (ctx->r15 != 0) {
        // 0x804732EC: lwc1        $f16, 0x78($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80473328;
    }
    goto skip_0;
    // 0x804732EC: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x804732F0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804732F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804732F8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804732FC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80473300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80473304: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80473308: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8047330C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80473310: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80473314: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80473318: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8047331C: b           L_8047333C
    // 0x80473320: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
        goto L_8047333C;
    // 0x80473320: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x80473324: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
L_80473328:
    // 0x80473328: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8047332C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80473330: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80473334: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80473338: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_8047333C:
    // 0x8047333C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80473340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80473344: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80473348: jr          $ra
    // 0x8047334C: nop

    return;
    // 0x8047334C: nop

;}
RECOMP_FUNC void func_806B0A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B0A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806B0A14: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x806B0A18: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806B0A1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B0A20: jal         0x80081FE0
    // 0x806B0A24: div.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x806B0A24: div.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    after_0:
    // 0x806B0A28: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806B0A2C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806B0A30: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x806B0A34: nop

    // 0x806B0A38: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806B0A3C: bgez        $v1, L_806B0A4C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x806B0A40: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_806B0A4C;
    }
    // 0x806B0A40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x806B0A44: b           L_806B0A5C
    // 0x806B0A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806B0A5C;
    // 0x806B0A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806B0A4C:
    // 0x806B0A4C: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x806B0A50: bnel        $at, $zero, L_806B0A60
    if (ctx->r1 != 0) {
        // 0x806B0A54: sh          $v0, 0x144($t8)
        MEM_H(0X144, ctx->r24) = ctx->r2;
            goto L_806B0A60;
    }
    goto skip_0;
    // 0x806B0A54: sh          $v0, 0x144($t8)
    MEM_H(0X144, ctx->r24) = ctx->r2;
    skip_0:
    // 0x806B0A58: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_806B0A5C:
    // 0x806B0A5C: sh          $v0, 0x144($t8)
    MEM_H(0X144, ctx->r24) = ctx->r2;
L_806B0A60:
    // 0x806B0A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B0A68: jr          $ra
    // 0x806B0A6C: nop

    return;
    // 0x806B0A6C: nop

;}
RECOMP_FUNC void func_80517174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051717C: jal         0x80517120
    // 0x80517180: nop

    func_80517120(rdram, ctx);
        goto after_0;
    // 0x80517180: nop

    after_0:
    // 0x80517184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051718C: jr          $ra
    // 0x80517190: nop

    return;
    // 0x80517190: nop

;}
RECOMP_FUNC void func_80052AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052AEC: jal         0x80052A28
    // 0x80052AF0: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    func_80052A28(rdram, ctx);
        goto after_0;
    // 0x80052AF0: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    after_0:
    // 0x80052AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052AFC: jr          $ra
    // 0x80052B00: nop

    return;
    // 0x80052B00: nop

;}
RECOMP_FUNC void func_80049148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004914C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049154: addiu       $a0, $a1, 0x2
    ctx->r4 = ADD32(ctx->r5, 0X2);
    // 0x80049158: jal         0x800490A8
    // 0x8004915C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800490A8(rdram, ctx);
        goto after_0;
    // 0x8004915C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80049160: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80049164: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80049168: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004916C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80049170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049178: jr          $ra
    // 0x8004917C: nop

    return;
    // 0x8004917C: nop

;}
RECOMP_FUNC void func_80056484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80056488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005648C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80056490: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80056494: lw          $a0, 0x180($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X180);
    // 0x80056498: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8005649C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800564A0: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x800564A4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x800564A8: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x800564AC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x800564B0: jal         0x8005FCA8
    // 0x800564B4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x800564B4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800564B8: jal         0x8005FC0C
    // 0x800564BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FC0C(rdram, ctx);
        goto after_1;
    // 0x800564BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800564C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800564C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800564C8: jr          $ra
    // 0x800564CC: nop

    return;
    // 0x800564CC: nop

;}
RECOMP_FUNC void func_8052634C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052634C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80526350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80526354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80526358: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052635C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6140) << 16);
    // 0x80526360: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526364: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80526368: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x8052636C: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    // 0x80526370: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80526374: lwc1        $f4, -0x3FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6140));
    // 0x80526378: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8052637C: addiu       $t7, $zero, 0x2A
    ctx->r15 = ADD32(0, 0X2A);
    // 0x80526380: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(327, 0X5148) << 16);
    // 0x80526384: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x80526388: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x8052638C: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x80526390: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80526394: lhu         $t8, -0x4FB8($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(327, 0X5148));
    // 0x80526398: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8052639C: lui         $v1, 0x8053
    ctx->r3 = S32(RELOC_HI16(327, 0X514A) << 16);
    // 0x805263A0: addiu       $v1, $v1, -0x4FB6
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(327, 0X514A));
    // 0x805263A4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x805263A8: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x805263AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805263B0: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x805263B4: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x805263B8: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x805263BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x805263C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805263C4: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x805263C8: lhu         $t1, -0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, -0X4);
    // 0x805263CC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x805263D0: sh          $t1, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r9;
    // 0x805263D4: lhu         $t2, -0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, -0X2);
    // 0x805263D8: sh          $t2, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r10;
    // 0x805263DC: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x805263E0: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x805263E4: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x805263E8: beq         $a0, $at, L_80526418
    if (ctx->r4 == ctx->r1) {
        // 0x805263EC: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80526418;
    }
    // 0x805263EC: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x805263F0: beq         $a0, $at, L_80526418
    if (ctx->r4 == ctx->r1) {
        // 0x805263F4: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80526418;
    }
    // 0x805263F4: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x805263F8: beq         $a0, $at, L_80526408
    if (ctx->r4 == ctx->r1) {
        // 0x805263FC: addiu       $at, $zero, 0x4583
        ctx->r1 = ADD32(0, 0X4583);
            goto L_80526408;
    }
    // 0x805263FC: addiu       $at, $zero, 0x4583
    ctx->r1 = ADD32(0, 0X4583);
    // 0x80526400: bne         $a0, $at, L_80526418
    if (ctx->r4 != ctx->r1) {
        // 0x80526404: nop
    
            goto L_80526418;
    }
    // 0x80526404: nop

L_80526408:
    // 0x80526408: jal         0x805276E0
    // 0x8052640C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805276E0(rdram, ctx);
        goto after_0;
    // 0x8052640C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80526410: b           L_80526420
    // 0x80526414: nop

        goto L_80526420;
    // 0x80526414: nop

L_80526418:
    // 0x80526418: jal         0x80527424
    // 0x8052641C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80527424(rdram, ctx);
        goto after_1;
    // 0x8052641C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80526420:
    // 0x80526420: jal         0x80063414
    // 0x80526424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80063414(rdram, ctx);
        goto after_2;
    // 0x80526424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80526428: addiu       $v1, $s0, 0x58
    ctx->r3 = ADD32(ctx->r16, 0X58);
    // 0x8052642C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80526430: addiu       $v0, $s0, 0x38
    ctx->r2 = ADD32(ctx->r16, 0X38);
    // 0x80526434: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80526438: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8052643C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80526440: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80526444: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80526448: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8052644C: lui         $t4, 0x8053
    ctx->r12 = S32(RELOC_HI16(327, 0X60E4) << 16);
    // 0x80526450: addiu       $t4, $t4, -0x401C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(327, 0X60E4));
    // 0x80526454: lui         $t5, 0x8053
    ctx->r13 = S32(RELOC_HI16(327, 0X60EC) << 16);
    // 0x80526458: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8052645C: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x80526460: addiu       $t5, $t5, -0x4014
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(327, 0X60EC));
    // 0x80526464: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x80526468: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8052646C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80526470: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80526474: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x80526478: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8052647C: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
    // 0x80526480: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80526484: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x80526488: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    // 0x8052648C: lui         $a0, 0x8053
    ctx->r4 = S32(RELOC_HI16(327, 0X6104) << 16);
    // 0x80526490: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80526494: lw          $a0, -0x3FFC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(327, 0X6104));
    // 0x80526498: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x8052649C: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x805264A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805264A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805264A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805264AC: jr          $ra
    // 0x805264B0: nop

    return;
    // 0x805264B0: nop

;}
RECOMP_FUNC void func_8040E2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E2A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040E2A4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8040E2A8: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8040E2AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E2B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040E2B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8040E2B8: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8040E2BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8040E2C0: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x8040E2C4: bnel        $at, $zero, L_8040E2D8
    if (ctx->r1 != 0) {
        // 0x8040E2C8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8040E2D8;
    }
    goto skip_0;
    // 0x8040E2C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x8040E2CC: b           L_8040E35C
    // 0x8040E2D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040E35C;
    // 0x8040E2D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8040E2D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8040E2D8:
    // 0x8040E2D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040E2DC: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F20) << 16);
    // 0x8040E2E0: lwc1        $f16, -0x1AE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F20));
    // 0x8040E2E4: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8040E2E8: lwc1        $f10, 0x44($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8040E2EC: lui         $a0, 0x4074
    ctx->r4 = S32(0X4074 << 16);
    // 0x8040E2F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040E2F4: ori         $a0, $a0, 0x2200
    ctx->r4 = ctx->r4 | 0X2200;
    // 0x8040E2F8: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x8040E2FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8040E300: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8040E304: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8040E308: jal         0x8004613C
    // 0x8040E30C: nop

    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8040E30C: nop

    after_0:
    // 0x8040E310: bne         $v0, $zero, L_8040E320
    if (ctx->r2 != 0) {
        // 0x8040E314: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8040E320;
    }
    // 0x8040E314: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8040E318: b           L_8040E35C
    // 0x8040E31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040E35C;
    // 0x8040E31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040E320:
    // 0x8040E320: addiu       $a0, $zero, 0x4074
    ctx->r4 = ADD32(0, 0X4074);
    // 0x8040E324: jal         0x80047090
    // 0x8040E328: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8040E328: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8040E32C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8040E330: andi        $t0, $v0, 0x3FF
    ctx->r8 = ctx->r2 & 0X3FF;
    // 0x8040E334: lhu         $t1, 0xE($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XE);
    // 0x8040E338: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x8040E33C: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8040E340: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x8040E344: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8040E348: jal         0x80044194
    // 0x8040E34C: sw          $t4, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r12;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8040E34C: sw          $t4, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r12;
    after_2:
    // 0x8040E350: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8040E354: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8040E358: sb          $t5, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r13;
L_8040E35C:
    // 0x8040E35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040E360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040E364: jr          $ra
    // 0x8040E368: nop

    return;
    // 0x8040E368: nop

    // 0x8040E36C: nop

;}
RECOMP_FUNC void func_8002BEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BEB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BEB4: beq         $a0, $zero, L_8002BEFC
    if (ctx->r4 == 0) {
        // 0x8002BEB8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002BEFC;
    }
    // 0x8002BEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BEBC: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8002BEC0: jal         0x80039DB4
    // 0x8002BEC4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80039DB4(rdram, ctx);
        goto after_0;
    // 0x8002BEC4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002BEC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BECC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002BED0: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8002BED4: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8002BED8: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x8002BEDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002BEE0: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x8002BEE4: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x8002BEE8: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x8002BEEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002BEF0: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8002BEF4: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x8002BEF8: sh          $t1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r9;
L_8002BEFC:
    // 0x8002BEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BF00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BF04: jr          $ra
    // 0x8002BF08: nop

    return;
    // 0x8002BF08: nop

;}
RECOMP_FUNC void func_8052249C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052249C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805224A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x805224A4: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x805224A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805224AC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x805224B0: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x805224B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x805224B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x805224BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805224C0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x805224C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805224C8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x805224CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x805224D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805224D4: beq         $s2, $zero, L_8052254C
    if (ctx->r18 == 0) {
        // 0x805224D8: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_8052254C;
    }
    // 0x805224D8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x805224DC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805224E0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x805224E4: addiu       $s4, $zero, 0x4115
    ctx->r20 = ADD32(0, 0X4115);
L_805224E8:
    // 0x805224E8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x805224EC: beq         $s0, $zero, L_80522544
    if (ctx->r16 == 0) {
        // 0x805224F0: nop
    
            goto L_80522544;
    }
    // 0x805224F0: nop

    // 0x805224F4: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x805224F8: bnel        $s4, $t6, L_8052253C
    if (ctx->r20 != ctx->r14) {
        // 0x805224FC: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8052253C;
    }
    goto skip_0;
    // 0x805224FC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80522500: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x80522504: beql        $a1, $zero, L_8052252C
    if (ctx->r5 == 0) {
        // 0x80522508: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_8052252C;
    }
    goto skip_1;
    // 0x80522508: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x8052250C: sub.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80522510: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x80522514: addiu       $a3, $s3, 0x1
    ctx->r7 = ADD32(ctx->r19, 0X1);
    // 0x80522518: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8052251C: jal         0x8052249C
    // 0x80522520: nop

    func_8052249C(rdram, ctx);
        goto after_0;
    // 0x80522520: nop

    after_0:
    // 0x80522524: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80522528: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_8052252C:
    // 0x8052252C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80522530: jal         0x805223C4
    // 0x80522534: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_805223C4(rdram, ctx);
        goto after_1;
    // 0x80522534: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80522538: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8052253C:
    // 0x8052253C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80522540: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_80522544:
    // 0x80522544: bne         $s2, $zero, L_805224E8
    if (ctx->r18 != 0) {
        // 0x80522548: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_805224E8;
    }
    // 0x80522548: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8052254C:
    // 0x8052254C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80522550: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80522554: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80522558: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8052255C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80522560: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80522564: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80522568: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8052256C: jr          $ra
    // 0x80522570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80522570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Math_FTruncF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081D30: jal         0x80082050
    // 0x80081D34: nop

    truncf_recomp(rdram, ctx);
        goto after_0;
    // 0x80081D34: nop

    after_0:
    // 0x80081D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081D40: jr          $ra
    // 0x80081D44: nop

    return;
    // 0x80081D44: nop

;}
RECOMP_FUNC void func_80791DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791DC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80791DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791DCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80791DD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80791DD4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80791DD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80791DDC: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80791DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791DE8: jal         0x807903C4
    // 0x80791DEC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80791DEC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791DF0: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x80791DF4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80791DF8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80791DFC: bne         $t8, $at, L_80791E0C
    if (ctx->r24 != ctx->r1) {
        // 0x80791E00: sw          $t8, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r24;
            goto L_80791E0C;
    }
    // 0x80791E00: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x80791E04: jal         0x800677F8
    // 0x80791E08: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x80791E08: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_1:
L_80791E0C:
    // 0x80791E0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80791E10: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80791E14: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80791E18: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80791E1C: nop

    // 0x80791E20: bc1t        L_80791E40
    if (c1cs) {
        // 0x80791E24: nop
    
            goto L_80791E40;
    }
    // 0x80791E24: nop

    // 0x80791E28: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80791E2C: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80791E30: lbu         $t3, 0x2C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2C);
    // 0x80791E34: beq         $t3, $zero, L_80791E40
    if (ctx->r11 == 0) {
        // 0x80791E38: nop
    
            goto L_80791E40;
    }
    // 0x80791E38: nop

    // 0x80791E3C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_80791E40:
    // 0x80791E40: jal         0x80790714
    // 0x80791E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_2;
    // 0x80791E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80791E48: beq         $v0, $zero, L_80791E7C
    if (ctx->r2 == 0) {
        // 0x80791E4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791E7C;
    }
    // 0x80791E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791E54: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80791E58: jal         0x8079393C
    // 0x80791E5C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_3;
    // 0x80791E5C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_3:
    // 0x80791E60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80791E64: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(817, 0X5EC) << 16);
    // 0x80791E68: addiu       $t4, $t4, 0x93C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(817, 0X5EC));
    // 0x80791E6C: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    // 0x80791E70: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80791E74: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80791E78: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
L_80791E7C:
    // 0x80791E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791E80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80791E84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791E88: jr          $ra
    // 0x80791E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80791E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
