#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80460D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80460D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80460D44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80460D48: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80460D4C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80460D50: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X3650) << 16);
    // 0x80460D54: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80460D58: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80460D5C: addiu       $t7, $t7, 0x3BE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X3650));
    // 0x80460D60: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80460D64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80460D68: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80460D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80460D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80460D74: jal         0x80460DB8
    // 0x80460D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80460DB8(rdram, ctx);
        goto after_0;
    // 0x80460D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80460D7C: jal         0x80460C80
    // 0x80460D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460C80(rdram, ctx);
        goto after_1;
    // 0x80460D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80460D84: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80460D88: jal         0x80460CA0
    // 0x80460D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460CA0(rdram, ctx);
        goto after_2;
    // 0x80460D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80460D90: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80460D94: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80460D98: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x80460D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80460DA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80460DA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80460DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80460DAC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80460DB0: jr          $ra
    // 0x80460DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80460DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8045B518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045B51C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045B520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045B524: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8045B528: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8045B52C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8045B530: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(104, 0XCB0) << 16);
    // 0x8045B534: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8045B538: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x8045B53C: addiu       $t8, $t8, -0x4940
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(104, 0XCB0));
    // 0x8045B540: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8045B544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045B548: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045B54C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045B550: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8045B554: jal         0x8045B594
    // 0x8045B558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8045B594(rdram, ctx);
        goto after_0;
    // 0x8045B558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8045B55C: lui         $t0, 0x8046
    ctx->r8 = S32(RELOC_HI16(104, 0X670) << 16);
    // 0x8045B560: addiu       $t0, $t0, -0x4F80
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(104, 0X670));
    // 0x8045B564: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x8045B568: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8045B56C: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x8045B570: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8045B574: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8045B578: jal         0x80048378
    // 0x8045B57C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8045B57C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    after_1:
    // 0x8045B580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045B584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045B588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045B58C: jr          $ra
    // 0x8045B590: nop

    return;
    // 0x8045B590: nop

;}
RECOMP_FUNC void func_806B2B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2B2C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2B30: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2B34: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2B38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2B3C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2B40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2B44: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2B48: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2B4C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2B50: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2B54: jr          $ra
    // 0x806B2B58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2B58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F9A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9A78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806F9A7C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x806F9A80: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806F9A84: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(697, 0X5B8) << 16);
    // 0x806F9A88: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x806F9A8C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806F9A90: lw          $t7, -0x64C8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(697, 0X5B8));
    // 0x806F9A94: jr          $ra
    // 0x806F9A98: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x806F9A98: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8040A4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A4D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040A4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A4D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8040A4DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8040A4E0: jal         0x80047090
    // 0x8040A4E4: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8040A4E4: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_0:
    // 0x8040A4E8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8040A4EC: beq         $v0, $at, L_8040A54C
    if (ctx->r2 == ctx->r1) {
        // 0x8040A4F0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8040A54C;
    }
    // 0x8040A4F0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8040A4F4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8040A4F8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8040A4FC: jal         0x80047AB8
    // 0x8040A500: sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8040A500: sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    after_1:
    // 0x8040A504: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x8040A508: lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2A);
    // 0x8040A50C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A510: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8040A514: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8040A518: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8040A51C: jal         0x8004613C
    // 0x8040A520: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x8040A520: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    after_2:
    // 0x8040A524: beq         $v0, $zero, L_8040A544
    if (ctx->r2 == 0) {
        // 0x8040A528: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8040A544;
    }
    // 0x8040A528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8040A52C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8040A530: jal         0x80047F9C
    // 0x8040A534: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8040A534: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8040A538: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8040A53C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8040A540: sb          $t8, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r24;
L_8040A544:
    // 0x8040A544: b           L_8040A550
    // 0x8040A548: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8040A550;
    // 0x8040A548: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8040A54C:
    // 0x8040A54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040A550:
    // 0x8040A550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A554: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040A558: jr          $ra
    // 0x8040A55C: nop

    return;
    // 0x8040A55C: nop

;}
RECOMP_FUNC void func_8003DC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DC80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DC84: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003DC88: addiu       $t6, $zero, 0x6D
    ctx->r14 = ADD32(0, 0X6D);
    // 0x8003DC8C: addiu       $t7, $t7, -0x2424
    ctx->r15 = ADD32(ctx->r15, -0X2424);
    // 0x8003DC90: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8003DC94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003DC98: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003DC9C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003DCA0: jal         0x8003DA30
    // 0x8003DCA4: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    func_8003DA30(rdram, ctx);
        goto after_0;
    // 0x8003DCA4: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    after_0:
    // 0x8003DCA8: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8003DCAC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8003DCB0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8003DCB4: jal         0x80067D5C
    // 0x8003DCB8: lbu         $a0, 0x1C($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8003DCB8: lbu         $a0, 0x1C($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C);
    after_1:
    // 0x8003DCBC: addiu       $a0, $zero, 0x22D
    ctx->r4 = ADD32(0, 0X22D);
    // 0x8003DCC0: jal         0x80067818
    // 0x8003DCC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8003DCC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8003DCC8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8003DCCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003DCD0: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8003DCD4: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8003DCD8: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8003DCDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003DCE0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x8003DCE4: lwc1        $f6, 0x220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X220);
    // 0x8003DCE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003DCEC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8003DCF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003DCF4: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8003DCF8: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8003DCFC: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8003DD00: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    // 0x8003DD04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DD08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003DD0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DD10: jr          $ra
    // 0x8003DD14: nop

    return;
    // 0x8003DD14: nop

;}
RECOMP_FUNC void func_8040B0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B0CC: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8040B0D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8040B0D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8040B0D8: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8040B0DC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8040B0E0: beq         $v0, $zero, L_8040B15C
    if (ctx->r2 == 0) {
        // 0x8040B0E4: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_8040B15C;
    }
    // 0x8040B0E4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8040B0E8: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8040B0EC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040B0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040B0F4: lw          $t8, 0x138($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X138);
    // 0x8040B0F8: bnel        $t8, $zero, L_8040B114
    if (ctx->r24 != 0) {
        // 0x8040B0FC: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_8040B114;
    }
    goto skip_0;
    // 0x8040B0FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x8040B100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040B104: nop

    // 0x8040B108: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8040B10C: nop

    // 0x8040B110: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
L_8040B114:
    // 0x8040B114: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8040B118: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8040B11C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8040B120: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x8040B124: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8040B128: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8040B12C: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x8040B130: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    // 0x8040B134: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8040B138: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8040B13C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8040B140: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B144: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8040B148: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8040B14C: bnel        $at, $zero, L_8040B160
    if (ctx->r1 != 0) {
        // 0x8040B150: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8040B160;
    }
    goto skip_1;
    // 0x8040B150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8040B154: jr          $ra
    // 0x8040B158: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x8040B158: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_8040B15C:
    // 0x8040B15C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040B160:
    // 0x8040B160: jr          $ra
    // 0x8040B164: nop

    return;
    // 0x8040B164: nop

;}
RECOMP_FUNC void func_80037314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003731C: jal         0x80021958
    // 0x80037320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80037320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037324: bne         $v0, $zero, L_80037334
    if (ctx->r2 != 0) {
        // 0x80037328: nop
    
            goto L_80037334;
    }
    // 0x80037328: nop

    // 0x8003732C: b           L_80037370
    // 0x80037330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037370;
    // 0x80037330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037334:
    // 0x80037334: jal         0x80041714
    // 0x80037338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041714(rdram, ctx);
        goto after_1;
    // 0x80037338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003733C: beq         $v0, $zero, L_8003734C
    if (ctx->r2 == 0) {
        // 0x80037340: nop
    
            goto L_8003734C;
    }
    // 0x80037340: nop

    // 0x80037344: b           L_80037370
    // 0x80037348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037370;
    // 0x80037348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003734C:
    // 0x8003734C: jal         0x800371FC
    // 0x80037350: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800371FC(rdram, ctx);
        goto after_2;
    // 0x80037350: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80037354: bne         $v0, $zero, L_80037364
    if (ctx->r2 != 0) {
        // 0x80037358: nop
    
            goto L_80037364;
    }
    // 0x80037358: nop

    // 0x8003735C: b           L_80037370
    // 0x80037360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037370;
    // 0x80037360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037364:
    // 0x80037364: jal         0x80036EDC
    // 0x80037368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036EDC(rdram, ctx);
        goto after_3;
    // 0x80037368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8003736C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037370:
    // 0x80037370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037378: jr          $ra
    // 0x8003737C: nop

    return;
    // 0x8003737C: nop

;}
RECOMP_FUNC void func_807C3844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C384C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C3850: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x807C3854: bnel        $t6, $zero, L_807C387C
    if (ctx->r14 != 0) {
        // 0x807C3858: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807C387C;
    }
    goto skip_0;
    // 0x807C3858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x807C385C: jal         0x80045A34
    // 0x807C3860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807C3860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C3864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807C3868: bne         $v0, $zero, L_807C3878
    if (ctx->r2 != 0) {
        // 0x807C386C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807C3878;
    }
    // 0x807C386C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807C3870: b           L_807C387C
    // 0x807C3874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807C387C;
    // 0x807C3874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C3878:
    // 0x807C3878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C387C:
    // 0x807C387C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3884: jr          $ra
    // 0x807C3888: nop

    return;
    // 0x807C3888: nop

;}
RECOMP_FUNC void round_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820DC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800820E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800820E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800820E8: nop

    // 0x800820EC: add.d       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f12.d + ctx->f4.d;
    // 0x800820F0: floor.w.d   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floor(ctx->f0.d));
    // 0x800820F4: jr          $ra
    // 0x800820F8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    return;
    // 0x800820F8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
;}
RECOMP_FUNC void func_8043E898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E898: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8043E89C: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0X1724) << 16);
    // 0x8043E8A0: addiu       $t6, $t6, -0x189C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(92, 0X1724));
    // 0x8043E8A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8043E8A8: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(92, 0X178C) << 16);
    // 0x8043E8AC: addiu       $t9, $t9, -0x1834
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(92, 0X178C));
    // 0x8043E8B0: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x8043E8B4: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8043E8B8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8043E8BC: jr          $ra
    // 0x8043E8C0: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x8043E8C0: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_8044D1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D1F4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8044D1F8: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8044D1FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044D200: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044D204: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8044D208: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8044D20C: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8044D210: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8044D214: lw          $t9, 0x10($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10);
    // 0x8044D218: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x8044D21C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8044D220: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8044D224: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    // 0x8044D228: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8044D22C: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8044D230: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8044D234: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8044D238: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x8044D23C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8044D240: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8044D244: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8044D248: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8044D24C: bltz        $t1, L_8044D268
    if (SIGNED(ctx->r9) < 0) {
        // 0x8044D250: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_8044D268;
    }
    // 0x8044D250: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8044D254: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8044D258: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8044D25C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8044D260: jal         0x8044D1F4
    // 0x8044D264: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D264: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
L_8044D268:
    // 0x8044D268: jal         0x80086EA0
    // 0x8044D26C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    guMtxIdentF(rdram, ctx);
        goto after_1;
    // 0x8044D26C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x8044D270: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8044D274: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8044D278: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8044D27C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8044D280: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8044D284: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8044D288: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8044D28C: jal         0x8044D078
    // 0x8044D290: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8044D078(rdram, ctx);
        goto after_2;
    // 0x8044D290: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x8044D294: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8044D298: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8044D29C: jal         0x8044CCE4
    // 0x8044D2A0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_8044CCE4(rdram, ctx);
        goto after_3;
    // 0x8044D2A0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x8044D2A4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8044D2A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8044D2AC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8044D2B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8044D2B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8044D2B8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8044D2BC: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x8044D2C0: beql        $v0, $zero, L_8044D2E0
    if (ctx->r2 == 0) {
        // 0x8044D2C4: lw          $t2, 0xC0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XC0);
            goto L_8044D2E0;
    }
    goto skip_0;
    // 0x8044D2C4: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    skip_0:
    // 0x8044D2C8: jalr        $v0
    // 0x8044D2CC: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x8044D2CC: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    after_4:
    // 0x8044D2D0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8044D2D4: jal         0x8044CB6C
    // 0x8044D2D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8044CB6C(rdram, ctx);
        goto after_5;
    // 0x8044D2D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x8044D2DC: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
L_8044D2E0:
    // 0x8044D2E0: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x8044D2E4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8044D2E8: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8044D2EC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8044D2F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8044D2F4: jal         0x8044CC54
    // 0x8044D2F8: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    func_8044CC54(rdram, ctx);
        goto after_6;
    // 0x8044D2F8: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    after_6:
    // 0x8044D2FC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x8044D300: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044D304: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8044D308: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x8044D30C: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8044D310: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8044D314: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8044D318: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8044D31C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8044D320: bltz        $a2, L_8044D34C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8044D324: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8044D34C;
    }
    // 0x8044D324: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8044D328: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8044D32C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8044D330: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8044D334: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8044D338: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8044D33C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8044D340: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    // 0x8044D344: jalr        $t9
    // 0x8044D348: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8044D348: nop

    after_7:
L_8044D34C:
    // 0x8044D34C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8044D350: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8044D354: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    // 0x8044D358: bltz        $t1, L_8044D378
    if (SIGNED(ctx->r9) < 0) {
        // 0x8044D35C: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_8044D378;
    }
    // 0x8044D35C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8044D360: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8044D364: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8044D368: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8044D36C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8044D370: jal         0x8044D1F4
    // 0x8044D374: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_8044D1F4(rdram, ctx);
        goto after_8;
    // 0x8044D374: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_8:
L_8044D378:
    // 0x8044D378: jal         0x8044CCD0
    // 0x8044D37C: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_8044CCD0(rdram, ctx);
        goto after_9;
    // 0x8044D37C: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_9:
    // 0x8044D380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044D384: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044D388: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8044D38C: jr          $ra
    // 0x8044D390: nop

    return;
    // 0x8044D390: nop

;}
RECOMP_FUNC void func_8077725C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077725C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80777260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80777264: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80777268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077726C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80777270: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80777274: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80777278: lui         $t9, 0x8077
    ctx->r25 = S32(RELOC_HI16(772, 0X840) << 16);
    // 0x8077727C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80777280: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80777284: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80777288: lw          $t9, 0x7310($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(772, 0X840));
    // 0x8077728C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80777290: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80777294: jal         0x80776AF8
    // 0x80777298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80776AF8(rdram, ctx);
        goto after_0;
    // 0x80777298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077729C: jal         0x80776B04
    // 0x807772A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80776B04(rdram, ctx);
        goto after_1;
    // 0x807772A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807772A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807772A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807772AC: jr          $ra
    // 0x807772B0: nop

    return;
    // 0x807772B0: nop

    // 0x807772B4: nop

    // 0x807772B8: nop

    // 0x807772BC: nop

;}
RECOMP_FUNC void func_8005C910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C918: jal         0x8005C4CC
    // 0x8005C91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005C4CC(rdram, ctx);
        goto after_0;
    // 0x8005C91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C924: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8005C928: beql        $v0, $zero, L_8005C95C
    if (ctx->r2 == 0) {
        // 0x8005C92C: sb          $zero, 0x165($a0)
        MEM_B(0X165, ctx->r4) = 0;
            goto L_8005C95C;
    }
    goto skip_0;
    // 0x8005C92C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    skip_0:
    // 0x8005C930: lbu         $t6, 0x164($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X164);
    // 0x8005C934: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005C938: beq         $t6, $at, L_8005C95C
    if (ctx->r14 == ctx->r1) {
        // 0x8005C93C: nop
    
            goto L_8005C95C;
    }
    // 0x8005C93C: nop

    // 0x8005C940: lbu         $t7, 0x165($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X165);
    // 0x8005C944: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C948: beq         $t7, $at, L_8005C95C
    if (ctx->r15 == ctx->r1) {
        // 0x8005C94C: nop
    
            goto L_8005C95C;
    }
    // 0x8005C94C: nop

    // 0x8005C950: b           L_8005C95C
    // 0x8005C954: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
        goto L_8005C95C;
    // 0x8005C954: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8005C958: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_8005C95C:
    // 0x8005C95C: jal         0x8005D110
    // 0x8005C960: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_8005D110(rdram, ctx);
        goto after_1;
    // 0x8005C960: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_1:
    // 0x8005C964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C96C: jr          $ra
    // 0x8005C970: nop

    return;
    // 0x8005C970: nop

;}
RECOMP_FUNC void func_804351E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804351E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804351EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804351F0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804351F4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804351F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804351FC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80435200: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80435204: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80435208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043520C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80435210: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80435214: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80435218: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(71, 0X2A00) << 16);
    // 0x8043521C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80435220: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80435224: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80435228: lw          $t2, 0x64B0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(71, 0X2A00));
    // 0x8043522C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80435230: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80435234: jal         0x80434718
    // 0x80435238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80434718(rdram, ctx);
        goto after_0;
    // 0x80435238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043523C: jal         0x804346A0
    // 0x80435240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804346A0(rdram, ctx);
        goto after_1;
    // 0x80435240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80435244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80435248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043524C: jr          $ra
    // 0x80435250: nop

    return;
    // 0x80435250: nop

;}
RECOMP_FUNC void func_8070D100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070D100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070D104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070D108: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070D10C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8070D110: bne         $v1, $zero, L_8070D12C
    if (ctx->r3 != 0) {
        // 0x8070D114: nop
    
            goto L_8070D12C;
    }
    // 0x8070D114: nop

    // 0x8070D118: jal         0x80045A34
    // 0x8070D11C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8070D11C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8070D120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070D124: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8070D128: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
L_8070D12C:
    // 0x8070D12C: bne         $v1, $zero, L_8070D13C
    if (ctx->r3 != 0) {
        // 0x8070D130: nop
    
            goto L_8070D13C;
    }
    // 0x8070D130: nop

    // 0x8070D134: b           L_8070D148
    // 0x8070D138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8070D148;
    // 0x8070D138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070D13C:
    // 0x8070D13C: jal         0x8070D0DC
    // 0x8070D140: nop

    func_8070D0DC(rdram, ctx);
        goto after_1;
    // 0x8070D140: nop

    after_1:
    // 0x8070D144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8070D148:
    // 0x8070D148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070D14C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070D150: jr          $ra
    // 0x8070D154: nop

    return;
    // 0x8070D154: nop

;}
RECOMP_FUNC void func_805DC140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DC144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC148: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DC14C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC150: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x805DC154: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805DC158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC15C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805DC160: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x805DC164: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x805DC168: jal         0x805DD234
    // 0x805DC16C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_805DD234(rdram, ctx);
        goto after_0;
    // 0x805DC16C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805DC170: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805DC174: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805DC178: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x805DC17C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805DC180: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805DC184: lwc1        $f6, 0x5C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x805DC188: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805DC18C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805DC190: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x805DC194: jal         0x80062D14
    // 0x805DC198: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805DC198: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x805DC19C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x805DC1A0: lui         $at, 0x43D0
    ctx->r1 = S32(0X43D0 << 16);
    // 0x805DC1A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DC1A8: lwc1        $f16, 0x60($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X60);
    // 0x805DC1AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805DC1B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC1B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805DC1B8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DC1BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DC1C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805DC1C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805DC1C8: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x805DC1CC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805DC1D0: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805DC1D4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805DC1D8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805DC1DC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x805DC1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC1E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DC1E8: jr          $ra
    // 0x805DC1EC: nop

    return;
    // 0x805DC1EC: nop

;}
RECOMP_FUNC void func_804BB598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB5A0: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804BB5A4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(188, 0XBAC) << 16);
    // 0x804BB5A8: addiu       $t8, $t8, -0x48F4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(188, 0XBAC));
    // 0x804BB5AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BB5B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804BB5B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804BB5B8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804BB5BC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804BB5C0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804BB5C4: beql        $v1, $zero, L_804BB5F8
    if (ctx->r3 == 0) {
        // 0x804BB5C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BB5F8;
    }
    goto skip_0;
    // 0x804BB5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BB5CC: jalr        $v1
    // 0x804BB5D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804BB5D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB5D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB5D8: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x804BB5DC: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x804BB5E0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x804BB5E4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x804BB5E8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x804BB5EC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x804BB5F0: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x804BB5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB5F8:
    // 0x804BB5F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB5FC: jr          $ra
    // 0x804BB600: nop

    return;
    // 0x804BB600: nop

;}
RECOMP_FUNC void func_804326C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804326C4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804326C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804326CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804326D0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804326D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804326D8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804326DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804326E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804326E4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804326E8: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(59, 0X430) << 16);
    // 0x804326EC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804326F0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804326F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804326F8: lw          $t1, 0x2710($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(59, 0X430));
    // 0x804326FC: jr          $ra
    // 0x80432700: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80432700: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80432704: nop

    // 0x80432708: nop

    // 0x8043270C: nop

;}
RECOMP_FUNC void func_8040CE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CE98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040CE9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040CEA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040CEA4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8040CEA8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8040CEAC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8040CEB0: beql        $t6, $zero, L_8040CF40
    if (ctx->r14 == 0) {
        // 0x8040CEB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040CF40;
    }
    goto skip_0;
    // 0x8040CEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040CEB8: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8040CEBC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8040CEC0: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(20, 0X1E38) << 16);
    // 0x8040CEC4: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8040CEC8: addiu       $a1, $a1, -0x1BC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(20, 0X1E38));
    // 0x8040CECC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8040CED0: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8040CED4: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8040CED8: jalr        $t9
    // 0x8040CEDC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040CEDC: nop

    after_0:
    // 0x8040CEE0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8040CEE4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8040CEE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040CEEC: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8040CEF0: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F0C) << 16);
    // 0x8040CEF4: lwc1        $f18, -0x1AF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F0C));
    // 0x8040CEF8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8040CEFC: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8040CF00: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8040CF04: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x8040CF08: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8040CF0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8040CF10: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8040CF14: lwc1        $f16, 0x44($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X44);
    // 0x8040CF18: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8040CF1C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8040CF20: lw          $t0, 0xC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC);
    // 0x8040CF24: andi        $t1, $t0, 0x3FF
    ctx->r9 = ctx->r8 & 0X3FF;
    // 0x8040CF28: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8040CF2C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8040CF30: lw          $t9, 0x20($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X20);
    // 0x8040CF34: jalr        $t9
    // 0x8040CF38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040CF38: nop

    after_1:
    // 0x8040CF3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040CF40:
    // 0x8040CF40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040CF44: jr          $ra
    // 0x8040CF48: nop

    return;
    // 0x8040CF48: nop

;}
RECOMP_FUNC void func_806CF7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF7E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CF7E4: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806CF7E8: beq         $at, $zero, L_806CF7F8
    if (ctx->r1 == 0) {
        // 0x806CF7EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_806CF7F8;
    }
    // 0x806CF7EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CF7F0: b           L_806CF854
    // 0x806CF7F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806CF854;
    // 0x806CF7F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806CF7F8:
    // 0x806CF7F8: bnel        $a0, $a1, L_806CF80C
    if (ctx->r4 != ctx->r5) {
        // 0x806CF7FC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_806CF80C;
    }
    goto skip_0;
    // 0x806CF7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x806CF800: b           L_806CF854
    // 0x806CF804: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_806CF854;
    // 0x806CF804: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x806CF808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_806CF80C:
    // 0x806CF80C: jal         0x800653D8
    // 0x806CF810: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806CF810: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806CF814: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CF818: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806CF81C: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x806CF820: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806CF824: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x806CF828: mfhi        $t8
    ctx->r24 = hi;
    // 0x806CF82C: bne         $t7, $zero, L_806CF838
    if (ctx->r15 != 0) {
        // 0x806CF830: nop
    
            goto L_806CF838;
    }
    // 0x806CF830: nop

    // 0x806CF834: break       7
    do_break(2154625076);
L_806CF838:
    // 0x806CF838: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806CF83C: bne         $t7, $at, L_806CF850
    if (ctx->r15 != ctx->r1) {
        // 0x806CF840: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806CF850;
    }
    // 0x806CF840: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806CF844: bne         $v0, $at, L_806CF850
    if (ctx->r2 != ctx->r1) {
        // 0x806CF848: nop
    
            goto L_806CF850;
    }
    // 0x806CF848: nop

    // 0x806CF84C: break       6
    do_break(2154625100);
L_806CF850:
    // 0x806CF850: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_806CF854:
    // 0x806CF854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CF858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CF85C: jr          $ra
    // 0x806CF860: nop

    return;
    // 0x806CF860: nop

;}
RECOMP_FUNC void func_80033B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033B7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80033B84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80033B88: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80033B8C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80033B90: lw          $a1, -0x7674($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7674);
    // 0x80033B94: jal         0x800338A8
    // 0x80033B98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800338A8(rdram, ctx);
        goto after_0;
    // 0x80033B98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033B9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80033BA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80033BA4: jal         0x80033760
    // 0x80033BA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80033760(rdram, ctx);
        goto after_1;
    // 0x80033BA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80033BAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033BB0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80033BB4: lwc1        $f4, 0x88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X88);
    // 0x80033BB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033BBC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80033BC0: nop

    // 0x80033BC4: bc1tl       L_80033BF8
    if (c1cs) {
        // 0x80033BC8: lwc1        $f8, 0x180($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X180);
            goto L_80033BF8;
    }
    goto skip_0;
    // 0x80033BC8: lwc1        $f8, 0x180($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80033BCC: lwc1        $f6, 0x8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X8C);
    // 0x80033BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033BD4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80033BD8: nop

    // 0x80033BDC: bc1tl       L_80033BF8
    if (c1cs) {
        // 0x80033BE0: lwc1        $f8, 0x180($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X180);
            goto L_80033BF8;
    }
    goto skip_1;
    // 0x80033BE0: lwc1        $f8, 0x180($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x80033BE4: jal         0x80033AE4
    // 0x80033BE8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80033AE4(rdram, ctx);
        goto after_2;
    // 0x80033BE8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80033BEC: b           L_80033BFC
    // 0x80033BF0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_80033BFC;
    // 0x80033BF0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80033BF4: lwc1        $f8, 0x180($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X180);
L_80033BF8:
    // 0x80033BF8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
L_80033BFC:
    // 0x80033BFC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80033C00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033C04: nop

    // 0x80033C08: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80033C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033C10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033C14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80033C18: jr          $ra
    // 0x80033C1C: nop

    return;
    // 0x80033C1C: nop

;}
RECOMP_FUNC void func_80080440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080440: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080444: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080448: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008044C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80080450: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80080454: nop

    // 0x80080458: bc1tl       L_80080498
    if (c1cs) {
        // 0x8008045C: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80080498;
    }
    goto skip_0;
    // 0x8008045C: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_0:
    // 0x80080460: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080464: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080468: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8008046C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080470: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080474: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080478: nop

    // 0x8008047C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80080480: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80080484: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080488: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8008048C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80080490: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80080494: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80080498:
    // 0x80080498: nop

    // 0x8008049C: bc1t        L_800804D8
    if (c1cs) {
        // 0x800804A0: nop
    
            goto L_800804D8;
    }
    // 0x800804A0: nop

    // 0x800804A4: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800804A8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800804AC: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800804B0: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800804B4: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800804B8: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800804BC: nop

    // 0x800804C0: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800804C4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800804C8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800804CC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800804D0: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800804D4: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
L_800804D8:
    // 0x800804D8: jr          $ra
    // 0x800804DC: nop

    return;
    // 0x800804DC: nop

;}
RECOMP_FUNC void func_8076D2B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D2B4: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8076D2B8: beq         $v0, $zero, L_8076D2C8
    if (ctx->r2 == 0) {
        // 0x8076D2BC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D2C8;
    }
    // 0x8076D2BC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D2C0: b           L_8076D30C
    // 0x8076D2C4: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
        goto L_8076D30C;
    // 0x8076D2C4: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
L_8076D2C8:
    // 0x8076D2C8: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8076D2CC: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X36C0) << 16);
    // 0x8076D2D0: addiu       $t1, $t1, -0x150
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(766, 0X36C0));
    // 0x8076D2D4: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8076D2D8: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x8076D2DC: bne         $at, $zero, L_8076D2F4
    if (ctx->r1 != 0) {
        // 0x8076D2E0: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_8076D2F4;
    }
    // 0x8076D2E0: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8076D2E4: addiu       $t9, $zero, 0x3F
    ctx->r25 = ADD32(0, 0X3F);
    // 0x8076D2E8: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8076D2EC: jr          $ra
    // 0x8076D2F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8076D2F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076D2F4:
    // 0x8076D2F4: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8076D2F8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8076D2FC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8076D300: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8076D304: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8076D308: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
L_8076D30C:
    // 0x8076D30C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076D310: jr          $ra
    // 0x8076D314: nop

    return;
    // 0x8076D314: nop

;}
RECOMP_FUNC void func_80776AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776AF8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80776AFC: jr          $ra
    // 0x80776B00: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    return;
    // 0x80776B00: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80022558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022558: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002255C: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80022560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022568: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8002256C: lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // 0x80022570: addiu       $a3, $a3, 0x2448
    ctx->r7 = ADD32(ctx->r7, 0X2448);
    // 0x80022574: addiu       $a2, $a2, 0x3E88
    ctx->r6 = ADD32(ctx->r6, 0X3E88);
    // 0x80022578: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x8002257C: jal         0x80057F74
    // 0x80022580: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x80022580: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x80022584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002258C: jr          $ra
    // 0x80022590: nop

    return;
    // 0x80022590: nop

;}
RECOMP_FUNC void func_80708E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708E6C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80708E70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80708E74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80708E78: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(715, 0X1C8) << 16);
    // 0x80708E7C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80708E80: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80708E84: lw          $t8, -0x7118($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(715, 0X1C8));
    // 0x80708E88: jr          $ra
    // 0x80708E8C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80708E8C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_807812CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807812CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807812D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807812D4: jal         0x80780DC4
    // 0x807812D8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_80780DC4(rdram, ctx);
        goto after_0;
    // 0x807812D8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807812DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807812E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807812E4: jr          $ra
    // 0x807812E8: nop

    return;
    // 0x807812E8: nop

;}
RECOMP_FUNC void func_8070D208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070D208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070D20C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8070D210: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8070D214: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8070D218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070D21C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8070D220: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8070D224: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8070D228: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8070D22C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8070D230: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8070D234: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8070D238: lui         $t2, 0x8071
    ctx->r10 = S32(RELOC_HI16(721, 0XD0C) << 16);
    // 0x8070D23C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8070D240: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8070D244: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8070D248: lw          $t2, -0x2C64($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(721, 0XD0C));
    // 0x8070D24C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8070D250: jal         0x8070D090
    // 0x8070D254: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8070D090(rdram, ctx);
        goto after_0;
    // 0x8070D254: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8070D258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070D25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070D260: jr          $ra
    // 0x8070D264: nop

    return;
    // 0x8070D264: nop

    // 0x8070D268: nop

    // 0x8070D26C: nop

;}
RECOMP_FUNC void func_8003063C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003063C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80030640: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80030644: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80030648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003064C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80030650: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80030654: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80030658: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003065C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80030660: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030664: lwc1        $f10, -0x38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X38);
    // 0x80030668: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8003066C: mul.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80030670: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80030674: nop

    // 0x80030678: bc1fl       L_8003068C
    if (!c1cs) {
        // 0x8003067C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8003068C;
    }
    goto skip_0;
    // 0x8003067C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80030680: b           L_800306A4
    // 0x80030684: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_800306A4;
    // 0x80030684: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80030688: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8003068C:
    // 0x8003068C: nop

    // 0x80030690: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80030694: nop

    // 0x80030698: bc1fl       L_800306A8
    if (!c1cs) {
        // 0x8003069C: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_800306A8;
    }
    goto skip_1;
    // 0x8003069C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_1:
    // 0x800306A0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_800306A4:
    // 0x800306A4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_800306A8:
    // 0x800306A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800306AC: jal         0x80065954
    // 0x800306B0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800306B0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800306B4: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x800306B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800306BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800306C0: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800306C4: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800306C8: lwc1        $f18, 0xC4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800306CC: sub.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800306D0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800306D4: jal         0x80065954
    // 0x800306D8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800306D8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800306DC: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800306E0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x800306E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800306E8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800306EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800306F0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800306F4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800306F8: bc1f        L_80030708
    if (!c1cs) {
        // 0x800306FC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80030708;
    }
    // 0x800306FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80030700: b           L_8003073C
    // 0x80030704: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
        goto L_8003073C;
    // 0x80030704: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
L_80030708:
    // 0x80030708: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003070C: nop

    // 0x80030710: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80030714: nop

    // 0x80030718: bc1fl       L_80030734
    if (!c1cs) {
        // 0x8003071C: lwc1        $f10, 0xC4($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
            goto L_80030734;
    }
    goto skip_2;
    // 0x8003071C: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    skip_2:
    // 0x80030720: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80030724: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80030728: b           L_8003073C
    // 0x8003072C: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
        goto L_8003073C;
    // 0x8003072C: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x80030730: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
L_80030734:
    // 0x80030734: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80030738: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
L_8003073C:
    // 0x8003073C: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80030740: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80030744: nop

    // 0x80030748: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003074C: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x80030750: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80030754: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80030758: nop

    // 0x8003075C: bc1fl       L_8003076C
    if (!c1cs) {
        // 0x80030760: lw          $v0, 0x38($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X38);
            goto L_8003076C;
    }
    goto skip_3;
    // 0x80030760: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    skip_3:
    // 0x80030764: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80030768: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_8003076C:
    // 0x8003076C: slti        $at, $v0, -0x28
    ctx->r1 = SIGNED(ctx->r2) < -0X28 ? 1 : 0;
    // 0x80030770: beql        $at, $zero, L_8003078C
    if (ctx->r1 == 0) {
        // 0x80030774: slti        $at, $v0, 0xF0
        ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
            goto L_8003078C;
    }
    goto skip_4;
    // 0x80030774: slti        $at, $v0, 0xF0
    ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    skip_4:
    // 0x80030778: jal         0x8002F5F4
    // 0x8003077C: nop

    func_8002F5F4(rdram, ctx);
        goto after_2;
    // 0x8003077C: nop

    after_2:
    // 0x80030780: b           L_800307C8
    // 0x80030784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800307C8;
    // 0x80030784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030788: slti        $at, $v0, 0xF0
    ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
L_8003078C:
    // 0x8003078C: beq         $at, $zero, L_800307C4
    if (ctx->r1 == 0) {
        // 0x80030790: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800307C4;
    }
    // 0x80030790: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80030794: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80030798: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003079C: lwc1        $f16, -0x34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X34);
    // 0x800307A0: lwc1        $f10, 0xCC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800307A4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800307A8: swc1        $f18, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f18.u32l;
    // 0x800307AC: lwc1        $f4, 0xCC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800307B0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800307B4: nop

    // 0x800307B8: bc1fl       L_800307C8
    if (!c1cs) {
        // 0x800307BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800307C8;
    }
    goto skip_5;
    // 0x800307BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800307C0: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
L_800307C4:
    // 0x800307C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800307C8:
    // 0x800307C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800307CC: jr          $ra
    // 0x800307D0: nop

    return;
    // 0x800307D0: nop

;}
RECOMP_FUNC void func_80049674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049674: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80049678: lbu         $t6, 0x5B8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5B8);
    // 0x8004967C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049680: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80049684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049688: bne         $t6, $zero, L_800496C4
    if (ctx->r14 != 0) {
        // 0x8004968C: lw          $v1, -0x7630($v1)
        ctx->r3 = MEM_W(ctx->r3, -0X7630);
            goto L_800496C4;
    }
    // 0x8004968C: lw          $v1, -0x7630($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7630);
    // 0x80049690: jal         0x80049318
    // 0x80049694: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80049318(rdram, ctx);
        goto after_0;
    // 0x80049694: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80049698: beq         $v0, $zero, L_800496C4
    if (ctx->r2 == 0) {
        // 0x8004969C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_800496C4;
    }
    // 0x8004969C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800496A0: slti        $at, $v1, 0x1D
    ctx->r1 = SIGNED(ctx->r3) < 0X1D ? 1 : 0;
    // 0x800496A4: beql        $at, $zero, L_800496C8
    if (ctx->r1 == 0) {
        // 0x800496A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800496C8;
    }
    goto skip_0;
    // 0x800496A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800496AC: jal         0x800492C0
    // 0x800496B0: addiu       $a0, $zero, -0x9B
    ctx->r4 = ADD32(0, -0X9B);
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x800496B0: addiu       $a0, $zero, -0x9B
    ctx->r4 = ADD32(0, -0X9B);
    after_1:
    // 0x800496B4: beq         $v0, $zero, L_800496C4
    if (ctx->r2 == 0) {
        // 0x800496B8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800496C4;
    }
    // 0x800496B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800496BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800496C0: sb          $t7, 0x5B8($at)
    MEM_B(0X5B8, ctx->r1) = ctx->r15;
L_800496C4:
    // 0x800496C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800496C8:
    // 0x800496C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800496CC: jr          $ra
    // 0x800496D0: nop

    return;
    // 0x800496D0: nop

;}
RECOMP_FUNC void func_806DF504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF504: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806DF508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DF50C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DF510: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x806DF514: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806DF518: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806DF51C: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x806DF520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806DF524: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806DF528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806DF52C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806DF530: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF534: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806DF538: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806DF53C: nop

    // 0x806DF540: bc1fl       L_806DF554
    if (!c1cs) {
        // 0x806DF544: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_806DF554;
    }
    goto skip_0;
    // 0x806DF544: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x806DF548: b           L_806DF57C
    // 0x806DF54C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_806DF57C;
    // 0x806DF54C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x806DF550: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_806DF554:
    // 0x806DF554: nop

    // 0x806DF558: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806DF55C: nop

    // 0x806DF560: bc1fl       L_806DF574
    if (!c1cs) {
        // 0x806DF564: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_806DF574;
    }
    goto skip_1;
    // 0x806DF564: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_1:
    // 0x806DF568: b           L_806DF57C
    // 0x806DF56C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_806DF57C;
    // 0x806DF56C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806DF570: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_806DF574:
    // 0x806DF574: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x806DF578: nop

L_806DF57C:
    // 0x806DF57C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806DF580: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806DF584: bne         $a1, $at, L_806DF5B0
    if (ctx->r5 != ctx->r1) {
        // 0x806DF588: nop
    
            goto L_806DF5B0;
    }
    // 0x806DF588: nop

    // 0x806DF58C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806DF590: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x806DF594: jal         0x80067D5C
    // 0x806DF598: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x806DF598: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x806DF59C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF5A0: jal         0x80067F78
    // 0x806DF5A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806DF5A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806DF5A8: b           L_806DF610
    // 0x806DF5AC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806DF610;
    // 0x806DF5AC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_806DF5B0:
    // 0x806DF5B0: jal         0x80067930
    // 0x806DF5B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x806DF5B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x806DF5B8: beq         $v0, $zero, L_806DF5F0
    if (ctx->r2 == 0) {
        // 0x806DF5BC: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_806DF5F0;
    }
    // 0x806DF5BC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806DF5C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806DF5C4: bne         $v0, $at, L_806DF610
    if (ctx->r2 != ctx->r1) {
        // 0x806DF5C8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806DF610;
    }
    // 0x806DF5C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806DF5CC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x806DF5D0: jal         0x80067D5C
    // 0x806DF5D4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x806DF5D4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x806DF5D8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF5DC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806DF5E0: jal         0x800678F0
    // 0x806DF5E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x806DF5E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x806DF5E8: b           L_806DF614
    // 0x806DF5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806DF614;
    // 0x806DF5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DF5F0:
    // 0x806DF5F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806DF5F4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x806DF5F8: jal         0x80067D5C
    // 0x806DF5FC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x806DF5FC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x806DF600: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF604: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806DF608: jal         0x80067838
    // 0x806DF60C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x806DF60C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_806DF610:
    // 0x806DF610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DF614:
    // 0x806DF614: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DF618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806DF61C: jr          $ra
    // 0x806DF620: nop

    return;
    // 0x806DF620: nop

;}
RECOMP_FUNC void func_8043BB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BB60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043BB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043BB68: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8043BB6C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043BB70: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043BB74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043BB78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043BB7C: jal         0x8043BBAC
    // 0x8043BB80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8043BBAC(rdram, ctx);
        goto after_0;
    // 0x8043BB80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8043BB84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043BB88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043BB8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043BB90: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8043BB94: jal         0x8043BA58
    // 0x8043BB98: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    func_8043BA58(rdram, ctx);
        goto after_1;
    // 0x8043BB98: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    after_1:
    // 0x8043BB9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043BBA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043BBA4: jr          $ra
    // 0x8043BBA8: nop

    return;
    // 0x8043BBA8: nop

;}
RECOMP_FUNC void func_8043DA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DA18: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0X990) << 16);
    // 0x8043DA1C: addiu       $t6, $t6, -0x2630
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(92, 0X990));
    // 0x8043DA20: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8043DA24: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8043DA28: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8043DA2C: jr          $ra
    // 0x8043DA30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043DA30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800388BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800388BC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800388C0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x800388C4: lh          $v0, 0xADE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XADE);
    // 0x800388C8: lh          $v1, 0xAE0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XAE0);
    // 0x800388CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800388D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800388D4: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x800388D8: beq         $t6, $zero, L_80038918
    if (ctx->r14 == 0) {
        // 0x800388DC: lw          $a1, 0x1F4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X1F4);
            goto L_80038918;
    }
    // 0x800388DC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800388E0: lw          $v0, 0x60($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X60);
    // 0x800388E4: slt         $t7, $zero, $v1
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800388E8: xor         $t8, $v0, $t7
    ctx->r24 = ctx->r2 ^ ctx->r15;
    // 0x800388EC: sltu        $t8, $zero, $t8
    ctx->r24 = 0 < ctx->r24 ? 1 : 0;
    // 0x800388F0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800388F4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800388F8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800388FC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80038900: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80038904: lw          $t9, -0x1428($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1428);
    // 0x80038908: jalr        $t9
    // 0x8003890C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003890C: nop

    after_0:
    // 0x80038910: b           L_8003891C
    // 0x80038914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003891C;
    // 0x80038914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038918:
    // 0x80038918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003891C:
    // 0x8003891C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038924: jr          $ra
    // 0x80038928: nop

    return;
    // 0x80038928: nop

;}
RECOMP_FUNC void func_80582A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582A5C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80582A60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80582A64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80582A68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80582A6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80582A70: jal         0x8057EF14
    // 0x80582A74: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80582A74: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    after_0:
    // 0x80582A78: beq         $v0, $zero, L_80582C9C
    if (ctx->r2 == 0) {
        // 0x80582A7C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80582C9C;
    }
    // 0x80582A7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80582A80: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80582A84: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80582A88: lw          $a1, 0xCEC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XCEC);
    // 0x80582A8C: jal         0x805824D8
    // 0x80582A90: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_805824D8(rdram, ctx);
        goto after_1;
    // 0x80582A90: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80582A94: lw          $t6, 0xFB8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XFB8);
    // 0x80582A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582A9C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80582AA0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80582AA4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80582AA8: bne         $t8, $zero, L_80582ACC
    if (ctx->r24 != 0) {
        // 0x80582AAC: addiu       $a2, $zero, 0x30
        ctx->r6 = ADD32(0, 0X30);
            goto L_80582ACC;
    }
    // 0x80582AAC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80582AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582AB4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80582AB8: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80582ABC: jal         0x805826F4
    // 0x80582AC0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_805826F4(rdram, ctx);
        goto after_2;
    // 0x80582AC0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_2:
    // 0x80582AC4: b           L_80582AD8
    // 0x80582AC8: lw          $v0, 0xCF0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XCF0);
        goto L_80582AD8;
    // 0x80582AC8: lw          $v0, 0xCF0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XCF0);
L_80582ACC:
    // 0x80582ACC: jal         0x805826F4
    // 0x80582AD0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_805826F4(rdram, ctx);
        goto after_3;
    // 0x80582AD0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_3:
    // 0x80582AD4: lw          $v0, 0xCF0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XCF0);
L_80582AD8:
    // 0x80582AD8: beql        $v0, $zero, L_80582CA0
    if (ctx->r2 == 0) {
        // 0x80582ADC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80582CA0;
    }
    goto skip_0;
    // 0x80582ADC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80582AE0: lw          $t9, 0xFB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XFB8);
    // 0x80582AE4: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // 0x80582AE8: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80582AEC: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80582AF0: bne         $t1, $zero, L_80582BD0
    if (ctx->r9 != 0) {
        // 0x80582AF4: nop
    
            goto L_80582BD0;
    }
    // 0x80582AF4: nop

    // 0x80582AF8: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // 0x80582AFC: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582B00: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(399, 0X472C) << 16);
    // 0x80582B04: addiu       $a1, $a1, 0x353C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(399, 0X472C));
    // 0x80582B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582B0C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80582B10: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80582B14: mflo        $t2
    ctx->r10 = lo;
    // 0x80582B18: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x80582B1C: jal         0x80582940
    // 0x80582B20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80582940(rdram, ctx);
        goto after_4;
    // 0x80582B20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80582B24: lw          $t4, 0xCF0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582B30: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582B34: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80582B38: mflo        $a3
    ctx->r7 = lo;
    // 0x80582B3C: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582B40: jal         0x8005C27C
    // 0x80582B44: nop

    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x80582B44: nop

    after_5:
    // 0x80582B48: lw          $v0, 0xCF0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582B50: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80582B54: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582B58: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x80582B5C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80582B60: mflo        $a3
    ctx->r7 = lo;
    // 0x80582B64: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582B68: jal         0x8005C27C
    // 0x80582B6C: nop

    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x80582B6C: nop

    after_6:
    // 0x80582B70: lw          $t5, 0xCF0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582B78: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80582B7C: multu       $t5, $s2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582B80: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80582B84: mflo        $a3
    ctx->r7 = lo;
    // 0x80582B88: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582B8C: jal         0x805826F4
    // 0x80582B90: nop

    func_805826F4(rdram, ctx);
        goto after_7;
    // 0x80582B90: nop

    after_7:
    // 0x80582B94: lw          $a0, 0xCF0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582B98: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80582B9C: jal         0x80069644
    // 0x80582BA0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80069644(rdram, ctx);
        goto after_8;
    // 0x80582BA0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_8:
    // 0x80582BA4: lw          $t6, 0xCF0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582BAC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80582BB0: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582BB4: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80582BB8: mflo        $a3
    ctx->r7 = lo;
    // 0x80582BBC: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x80582BC0: jal         0x80582804
    // 0x80582BC4: nop

    func_80582804(rdram, ctx);
        goto after_9;
    // 0x80582BC4: nop

    after_9:
    // 0x80582BC8: b           L_80582CA0
    // 0x80582BCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80582CA0;
    // 0x80582BCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80582BD0:
    // 0x80582BD0: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582BD4: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(399, 0X472C) << 16);
    // 0x80582BD8: addiu       $a1, $a1, 0x353C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(399, 0X472C));
    // 0x80582BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582BE0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80582BE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80582BE8: mflo        $t7
    ctx->r15 = lo;
    // 0x80582BEC: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x80582BF0: jal         0x80582940
    // 0x80582BF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80582940(rdram, ctx);
        goto after_10;
    // 0x80582BF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_10:
    // 0x80582BF8: lw          $t9, 0xCF0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582C04: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582C08: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80582C0C: mflo        $a3
    ctx->r7 = lo;
    // 0x80582C10: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582C14: jal         0x8005C27C
    // 0x80582C18: nop

    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x80582C18: nop

    after_11:
    // 0x80582C1C: lw          $v0, 0xCF0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582C24: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80582C28: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582C2C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x80582C30: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80582C34: mflo        $a3
    ctx->r7 = lo;
    // 0x80582C38: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582C3C: jal         0x8005C27C
    // 0x80582C40: nop

    func_8005C27C(rdram, ctx);
        goto after_12;
    // 0x80582C40: nop

    after_12:
    // 0x80582C44: lw          $t0, 0xCF0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582C4C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80582C50: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582C54: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80582C58: mflo        $a3
    ctx->r7 = lo;
    // 0x80582C5C: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582C60: jal         0x805826F4
    // 0x80582C64: nop

    func_805826F4(rdram, ctx);
        goto after_13;
    // 0x80582C64: nop

    after_13:
    // 0x80582C68: lw          $a0, 0xCF0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582C6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80582C70: jal         0x80069644
    // 0x80582C74: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80069644(rdram, ctx);
        goto after_14;
    // 0x80582C74: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_14:
    // 0x80582C78: lw          $t1, 0xCF0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XCF0);
    // 0x80582C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582C80: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80582C84: multu       $t1, $s2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582C88: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80582C8C: mflo        $a3
    ctx->r7 = lo;
    // 0x80582C90: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x80582C94: jal         0x80582804
    // 0x80582C98: nop

    func_80582804(rdram, ctx);
        goto after_15;
    // 0x80582C98: nop

    after_15:
L_80582C9C:
    // 0x80582C9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80582CA0:
    // 0x80582CA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80582CA4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80582CA8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80582CAC: jr          $ra
    // 0x80582CB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80582CB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_806E0858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0858: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806E085C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x806E0860: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806E0864: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x806E0868: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x806E086C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x806E0870: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x806E0874: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(646, 0X340) << 16);
    // 0x806E0878: lui         $a1, 0x4017
    ctx->r5 = S32(0X4017 << 16);
    // 0x806E087C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E0880: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806E0884: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x806E0888: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806E088C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x806E0890: addiu       $a0, $a0, 0xAF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(646, 0X340));
    // 0x806E0894: jal         0x80046804
    // 0x806E0898: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x806E0898: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x806E089C: beq         $v0, $zero, L_806E0A34
    if (ctx->r2 == 0) {
        // 0x806E08A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806E0A34;
    }
    // 0x806E08A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806E08A4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806E08A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E08AC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806E08B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E08B4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(646, 0X2B0) << 16);
    // 0x806E08B8: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x806E08BC: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x806E08C0: lwc1        $f8, 0xA60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(646, 0X2B0));
    // 0x806E08C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806E08C8: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x806E08CC: jal         0x80047F9C
    // 0x806E08D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x806E08D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x806E08D4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806E08D8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x806E08DC: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x806E08E0: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x806E08E4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x806E08E8: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(646, 0X340) << 16);
    // 0x806E08EC: lui         $a1, 0x4017
    ctx->r5 = S32(0X4017 << 16);
    // 0x806E08F0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E08F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806E08F8: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x806E08FC: addiu       $a0, $a0, 0xAF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(646, 0X340));
    // 0x806E0900: jal         0x80046804
    // 0x806E0904: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80046804(rdram, ctx);
        goto after_2;
    // 0x806E0904: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x806E0908: bne         $v0, $zero, L_806E0920
    if (ctx->r2 != 0) {
        // 0x806E090C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_806E0920;
    }
    // 0x806E090C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x806E0910: jal         0x800447C8
    // 0x806E0914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x806E0914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E0918: b           L_806E0A38
    // 0x806E091C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_806E0A38;
    // 0x806E091C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_806E0920:
    // 0x806E0920: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806E0924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E0928: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806E092C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806E0930: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(646, 0X2B4) << 16);
    // 0x806E0934: swc1        $f10, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f10.u32l;
    // 0x806E0938: swc1        $f16, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f16.u32l;
    // 0x806E093C: lwc1        $f18, 0xA64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(646, 0X2B4));
    // 0x806E0940: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x806E0944: swc1        $f18, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f18.u32l;
    // 0x806E0948: jal         0x80047F9C
    // 0x806E094C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x806E094C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x806E0950: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x806E0954: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x806E0958: sb          $t8, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = ctx->r24;
    // 0x806E095C: bne         $at, $zero, L_806E0968
    if (ctx->r1 != 0) {
        // 0x806E0960: sw          $zero, 0x24($s1)
        MEM_W(0X24, ctx->r17) = 0;
            goto L_806E0968;
    }
    // 0x806E0960: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x806E0964: addiu       $s2, $zero, 0x63
    ctx->r18 = ADD32(0, 0X63);
L_806E0968:
    // 0x806E0968: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x806E096C: bne         $at, $zero, L_806E0A30
    if (ctx->r1 != 0) {
        // 0x806E0970: lui         $a0, 0x806E
        ctx->r4 = S32(RELOC_HI16(646, 0X340) << 16);
            goto L_806E0A30;
    }
    // 0x806E0970: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(646, 0X340) << 16);
    // 0x806E0974: lui         $a1, 0x4017
    ctx->r5 = S32(0X4017 << 16);
    // 0x806E0978: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E097C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806E0980: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x806E0984: addiu       $a0, $a0, 0xAF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(646, 0X340));
    // 0x806E0988: jal         0x80046804
    // 0x806E098C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80046804(rdram, ctx);
        goto after_5;
    // 0x806E098C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x806E0990: bne         $v0, $zero, L_806E09B0
    if (ctx->r2 != 0) {
        // 0x806E0994: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806E09B0;
    }
    // 0x806E0994: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806E0998: jal         0x800447C8
    // 0x806E099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x806E099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806E09A0: jal         0x800447C8
    // 0x806E09A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806E09A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x806E09A8: b           L_806E0A38
    // 0x806E09AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_806E0A38;
    // 0x806E09AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_806E09B0:
    // 0x806E09B0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x806E09B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E09B8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806E09BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E09C0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(646, 0X2B8) << 16);
    // 0x806E09C4: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x806E09C8: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x806E09CC: lwc1        $f8, 0xA68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(646, 0X2B8));
    // 0x806E09D0: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
    // 0x806E09D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x806E09D8: jal         0x80047F9C
    // 0x806E09DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x806E09DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x806E09E0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x806E09E4: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x806E09E8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x806E09EC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x806E09F0: mflo        $t0
    ctx->r8 = lo;
    // 0x806E09F4: sb          $t9, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r25;
    // 0x806E09F8: sh          $t0, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r8;
    // 0x806E09FC: bne         $v0, $zero, L_806E0A08
    if (ctx->r2 != 0) {
        // 0x806E0A00: nop
    
            goto L_806E0A08;
    }
    // 0x806E0A00: nop

    // 0x806E0A04: break       7
    do_break(2154695172);
L_806E0A08:
    // 0x806E0A08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806E0A0C: bne         $v0, $at, L_806E0A20
    if (ctx->r2 != ctx->r1) {
        // 0x806E0A10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806E0A20;
    }
    // 0x806E0A10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806E0A14: bne         $s2, $at, L_806E0A20
    if (ctx->r18 != ctx->r1) {
        // 0x806E0A18: nop
    
            goto L_806E0A20;
    }
    // 0x806E0A18: nop

    // 0x806E0A1C: break       6
    do_break(2154695196);
L_806E0A20:
    // 0x806E0A20: mfhi        $t1
    ctx->r9 = hi;
    // 0x806E0A24: sh          $t1, 0x144($a1)
    MEM_H(0X144, ctx->r5) = ctx->r9;
    // 0x806E0A28: b           L_806E0A34
    // 0x806E0A2C: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
        goto L_806E0A34;
    // 0x806E0A2C: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
L_806E0A30:
    // 0x806E0A30: sh          $s2, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r18;
L_806E0A34:
    // 0x806E0A34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_806E0A38:
    // 0x806E0A38: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x806E0A3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x806E0A40: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x806E0A44: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x806E0A48: jr          $ra
    // 0x806E0A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x806E0A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80448280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448280: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448284: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448288: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x8044828C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448290: jr          $ra
    // 0x80448294: sw          $t6, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = ctx->r14;
    return;
    // 0x80448294: sw          $t6, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8043D154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043D158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D15C: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8043D160: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8043D164: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043D168: beq         $a1, $at, L_8043D184
    if (ctx->r5 == ctx->r1) {
        // 0x8043D16C: addiu       $a0, $zero, 0x51
        ctx->r4 = ADD32(0, 0X51);
            goto L_8043D184;
    }
    // 0x8043D16C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8043D170: jal         0x80067878
    // 0x8043D174: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8043D174: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8043D178: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043D17C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8043D180: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8043D184:
    // 0x8043D184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043D188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043D18C: jr          $ra
    // 0x8043D190: nop

    return;
    // 0x8043D190: nop

;}
RECOMP_FUNC void func_80408628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040862C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80408630: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80408634: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80408638: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040863C: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X2C98) << 16);
    // 0x80408640: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80408644: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80408648: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040864C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80408650: lw          $t8, -0x5998($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(11, 0X2C98));
    // 0x80408654: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80408658: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040865C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80408660: jal         0x80048490
    // 0x80408664: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80408664: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80408668: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8040866C: jal         0x80048378
    // 0x80408670: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80408670: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80408674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80408678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040867C: jr          $ra
    // 0x80408680: nop

    return;
    // 0x80408680: nop

;}
RECOMP_FUNC void func_80450D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450D80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80450D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450D88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80450D8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80450D90: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450D94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450D98: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80450D9C: lw          $t6, 0xA5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XA5C);
    // 0x80450DA0: addu        $v1, $s0, $at
    ctx->r3 = ADD32(ctx->r16, ctx->r1);
    // 0x80450DA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450DA8: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80450DAC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80450DB0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80450DB4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80450DB8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450DBC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450DC0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450DC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450DC8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80450DCC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450DD0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80450DD4: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80450DD8: addiu       $t1, $t0, 0xAE0
    ctx->r9 = ADD32(ctx->r8, 0XAE0);
    // 0x80450DDC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80450DE0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80450DE4: lwc1        $f4, 0x6CE0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6CE0);
    // 0x80450DE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450DEC: nop

    // 0x80450DF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80450DF4: swc1        $f8, 0x6CE0($v1)
    MEM_W(0X6CE0, ctx->r3) = ctx->f8.u32l;
    // 0x80450DF8: lw          $v0, 0xA50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA50);
    // 0x80450DFC: slti        $at, $v0, 0xB3
    ctx->r1 = SIGNED(ctx->r2) < 0XB3 ? 1 : 0;
    // 0x80450E00: beq         $at, $zero, L_80450E0C
    if (ctx->r1 == 0) {
        // 0x80450E04: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80450E0C;
    }
    // 0x80450E04: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80450E08: sw          $t2, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r10;
L_80450E0C:
    // 0x80450E0C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450E10: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80450E14: lwc1        $f0, 0x6CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x80450E18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80450E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80450E20: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80450E24: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80450E28: nop

    // 0x80450E2C: bc1t        L_80450EA4
    if (c1cs) {
        // 0x80450E30: nop
    
            goto L_80450EA4;
    }
    // 0x80450E30: nop

    // 0x80450E34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80450E38: addiu       $t5, $zero, 0x8D
    ctx->r13 = ADD32(0, 0X8D);
    // 0x80450E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80450E40: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80450E44: nop

    // 0x80450E48: bc1f        L_80450E9C
    if (!c1cs) {
        // 0x80450E4C: nop
    
            goto L_80450E9C;
    }
    // 0x80450E4C: nop

    // 0x80450E50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80450E54: jal         0x80446D70
    // 0x80450E58: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80450E58: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80450E5C: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80450E60: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80450E64: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80450E68: jal         0x8044EDC4
    // 0x80450E6C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_1;
    // 0x80450E6C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80450E70: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80450E74: lw          $t3, 0x6F0C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X6F0C);
    // 0x80450E78: bne         $t3, $zero, L_80450EA4
    if (ctx->r11 != 0) {
        // 0x80450E7C: nop
    
            goto L_80450EA4;
    }
    // 0x80450E7C: nop

    // 0x80450E80: jal         0x80445A34
    // 0x80450E84: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x80450E84: nop

    after_2:
    // 0x80450E88: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450E8C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80450E90: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80450E94: b           L_80450EA4
    // 0x80450E98: sw          $t4, 0x6F0C($at)
    MEM_W(0X6F0C, ctx->r1) = ctx->r12;
        goto L_80450EA4;
    // 0x80450E98: sw          $t4, 0x6F0C($at)
    MEM_W(0X6F0C, ctx->r1) = ctx->r12;
L_80450E9C:
    // 0x80450E9C: jal         0x80450B48
    // 0x80450EA0: sw          $t5, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r13;
    func_80450B48(rdram, ctx);
        goto after_3;
    // 0x80450EA0: sw          $t5, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r13;
    after_3:
L_80450EA4:
    // 0x80450EA4: jal         0x8044FD5C
    // 0x80450EA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_4;
    // 0x80450EA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80450EAC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80450EB0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80450EB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80450EB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80450EBC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80450EC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80450EC4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80450EC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80450ECC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80450ED0: sll         $t7, $t7, 8
    ctx->r15 = S32(ctx->r15 << 8);
    // 0x80450ED4: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    // 0x80450ED8: jal         0x8044ED68
    // 0x80450EDC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_5;
    // 0x80450EDC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_5:
    // 0x80450EE0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80450EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80450EE8: lw          $a1, 0xA50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA50);
    // 0x80450EEC: jal         0x8044E8B0
    // 0x80450EF0: sw          $t8, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r24;
    func_8044E8B0(rdram, ctx);
        goto after_6;
    // 0x80450EF0: sw          $t8, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r24;
    after_6:
    // 0x80450EF4: jal         0x8044F178
    // 0x80450EF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044F178(rdram, ctx);
        goto after_7;
    // 0x80450EF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80450EFC: jal         0x8044F384
    // 0x80450F00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044F384(rdram, ctx);
        goto after_8;
    // 0x80450F00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80450F04: jal         0x804507C4
    // 0x80450F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804507C4(rdram, ctx);
        goto after_9;
    // 0x80450F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80450F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80450F10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80450F14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80450F18: jr          $ra
    // 0x80450F1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80450F1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8041ECCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041ECCC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041ECD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041ECD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041ECD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041ECDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041ECE0: jal         0x8041DB1C
    // 0x8041ECE4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041ECE4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8041ECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ECEC: jal         0x8041E9A8
    // 0x8041ECF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041ECF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041ECF4: beq         $v0, $zero, L_8041ED98
    if (ctx->r2 == 0) {
        // 0x8041ECF8: lui         $at, 0x8042
        ctx->r1 = S32(RELOC_HI16(29, 0X3508) << 16);
            goto L_8041ED98;
    }
    // 0x8041ECF8: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3508) << 16);
    // 0x8041ECFC: lwc1        $f2, 0xB68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3508));
    // 0x8041ED00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041ED04: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X350C) << 16);
    // 0x8041ED08: lwc1        $f4, 0xB6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X350C));
    // 0x8041ED0C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8041ED10: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8041ED14: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8041ED18: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8041ED1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8041ED20: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8041ED24: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8041ED28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8041ED2C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8041ED30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8041ED34: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8041ED38: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041ED3C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8041ED40: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8041ED44: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8041ED48: lw          $t9, 0x34($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X34);
    // 0x8041ED4C: jalr        $t9
    // 0x8041ED50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8041ED50: nop

    after_2:
    // 0x8041ED54: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x8041ED58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ED5C: jal         0x80047F9C
    // 0x8041ED60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8041ED60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8041ED64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ED68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041ED6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8041ED70: jal         0x8041FE10
    // 0x8041ED74: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_4;
    // 0x8041ED74: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x8041ED78: jal         0x8041E5E8
    // 0x8041ED7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_5;
    // 0x8041ED7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8041ED80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ED84: jal         0x8041E430
    // 0x8041ED88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_6;
    // 0x8041ED88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8041ED8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ED90: jal         0x8041E7D4
    // 0x8041ED94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_7;
    // 0x8041ED94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
L_8041ED98:
    // 0x8041ED98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041ED9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041EDA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041EDA4: jr          $ra
    // 0x8041EDA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041EDA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80561B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561B44: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80561B48: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80561B4C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80561B50: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80561B54: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80561B58: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80561B5C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80561B60: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80561B64: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80561B68: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80561B6C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80561B70: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80561B74: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80561B78: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80561B7C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80561B80: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80561B84: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80561B88: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x80561B8C: lwc1        $f30, 0x3C($a0)
    ctx->f30.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80561B90: lwc1        $f20, 0x40($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80561B94: lw          $v0, 0x708($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X708);
    // 0x80561B98: lwc1        $f26, 0x718($s7)
    ctx->f26.u32l = MEM_W(ctx->r23, 0X718);
    // 0x80561B9C: addiu       $s6, $s7, 0x6C8
    ctx->r22 = ADD32(ctx->r23, 0X6C8);
    // 0x80561BA0: sll         $s4, $v0, 3
    ctx->r20 = S32(ctx->r2 << 3);
    // 0x80561BA4: addu        $s2, $s7, $s4
    ctx->r18 = ADD32(ctx->r23, ctx->r20);
    // 0x80561BA8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80561BAC: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561BB0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80561BB4: swc1        $f0, 0x6C0($s7)
    MEM_W(0X6C0, ctx->r23) = ctx->f0.u32l;
    // 0x80561BB8: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561BBC: sub.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80561BC0: swc1        $f6, 0x6C4($s7)
    MEM_W(0X6C4, ctx->r23) = ctx->f6.u32l;
    // 0x80561BC4: sub.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80561BC8: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80561BCC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80561BD0: jal         0x80066E88
    // 0x80561BD4: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80561BD4: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80561BD8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80561BDC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80561BE0: jal         0x80066DE4
    // 0x80561BE4: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80561BE4: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80561BE8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80561BEC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80561BF0: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80561BF4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80561BF8: mul.s       $f2, $f28, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80561BFC: addiu       $a0, $s7, 0x738
    ctx->r4 = ADD32(ctx->r23, 0X738);
    // 0x80561C00: addiu       $v1, $s7, 0x748
    ctx->r3 = ADD32(ctx->r23, 0X748);
    // 0x80561C04: mul.s       $f12, $f28, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80561C08: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80561C0C: addiu       $s4, $s4, 0xC0
    ctx->r20 = ADD32(ctx->r20, 0XC0);
    // 0x80561C10: slti        $at, $s4, 0x6C0
    ctx->r1 = SIGNED(ctx->r20) < 0X6C0 ? 1 : 0;
    // 0x80561C14: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80561C18: addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
    // 0x80561C1C: addiu       $s1, $a0, 0x20
    ctx->r17 = ADD32(ctx->r4, 0X20);
    // 0x80561C20: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80561C24: addiu       $s0, $v1, 0x20
    ctx->r16 = ADD32(ctx->r3, 0X20);
    // 0x80561C28: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80561C2C: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561C30: addiu       $fp, $zero, 0x8
    ctx->r30 = ADD32(0, 0X8);
    // 0x80561C34: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80561C38: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80561C3C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80561C40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80561C44: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80561C48: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561C4C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80561C50: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80561C54: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80561C58: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x80561C5C: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80561C60: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80561C64: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80561C68: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80561C6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80561C70: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80561C74: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80561C78: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80561C7C: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80561C80: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80561C84: lh          $t4, 0x72E($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X72E);
    // 0x80561C88: sh          $t4, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r12;
    // 0x80561C8C: lh          $t5, 0x730($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X730);
    // 0x80561C90: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80561C94: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x80561C98: sh          $t5, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r13;
    // 0x80561C9C: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x80561CA0: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80561CA4: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80561CA8: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x80561CAC: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x80561CB0: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x80561CB4: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x80561CB8: sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // 0x80561CBC: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x80561CC0: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x80561CC4: bne         $at, $zero, L_80561CD4
    if (ctx->r1 != 0) {
        // 0x80561CC8: sb          $v0, 0xF($a0)
        MEM_B(0XF, ctx->r4) = ctx->r2;
            goto L_80561CD4;
    }
    // 0x80561CC8: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    // 0x80561CCC: addiu       $s4, $s4, -0x6C0
    ctx->r20 = ADD32(ctx->r20, -0X6C0);
    // 0x80561CD0: addiu       $s2, $s2, -0x6C0
    ctx->r18 = ADD32(ctx->r18, -0X6C0);
L_80561CD4:
    // 0x80561CD4: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80561CD8: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561CDC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80561CE0: sub.s       $f20, $f0, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80561CE4: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x80561CE8: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561CEC: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80561CF0: addiu       $s6, $s6, 0x8
    ctx->r22 = ADD32(ctx->r22, 0X8);
    // 0x80561CF4: swc1        $f4, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->f4.u32l;
    // 0x80561CF8: sub.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80561CFC: jal         0x80067114
    // 0x80561D00: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x80561D00: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    after_2:
    // 0x80561D04: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80561D08: jal         0x80066E88
    // 0x80561D0C: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80561D0C: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    after_3:
    // 0x80561D10: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80561D14: jal         0x80066DE4
    // 0x80561D18: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x80561D18: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_4:
    // 0x80561D1C: mul.s       $f2, $f28, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80561D20: sll         $v0, $s5, 6
    ctx->r2 = S32(ctx->r21 << 6);
    // 0x80561D24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80561D28: mul.s       $f12, $f28, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80561D2C: addiu       $s4, $s4, 0xC0
    ctx->r20 = ADD32(ctx->r20, 0XC0);
    // 0x80561D30: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x80561D34: slti        $at, $s4, 0x6C0
    ctx->r1 = SIGNED(ctx->r20) < 0X6C0 ? 1 : 0;
    // 0x80561D38: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x80561D3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80561D40: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80561D44: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80561D48: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
    // 0x80561D4C: mov.s       $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    ctx->f18.fl = ctx->f22.fl;
    // 0x80561D50: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561D54: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80561D58: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80561D5C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80561D60: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80561D64: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80561D68: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80561D6C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80561D70: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561D74: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80561D78: sh          $v1, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r3;
    // 0x80561D7C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80561D80: sh          $a0, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r4;
    // 0x80561D84: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80561D88: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80561D8C: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80561D90: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80561D94: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80561D98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80561D9C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80561DA0: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
    // 0x80561DA4: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
    // 0x80561DA8: sh          $v0, -0x18($s1)
    MEM_H(-0X18, ctx->r17) = ctx->r2;
    // 0x80561DAC: lh          $t3, 0x72E($s7)
    ctx->r11 = MEM_H(ctx->r23, 0X72E);
    // 0x80561DB0: sh          $t3, -0x16($s1)
    MEM_H(-0X16, ctx->r17) = ctx->r11;
    // 0x80561DB4: lh          $t4, 0x730($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X730);
    // 0x80561DB8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80561DBC: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x80561DC0: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
    // 0x80561DC4: sh          $t5, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r13;
    // 0x80561DC8: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80561DCC: sh          $zero, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = 0;
    // 0x80561DD0: sb          $a3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r7;
    // 0x80561DD4: sb          $a3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r7;
    // 0x80561DD8: sb          $a3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r7;
    // 0x80561DDC: sb          $a3, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r7;
    // 0x80561DE0: sb          $a3, -0x14($s1)
    MEM_B(-0X14, ctx->r17) = ctx->r7;
    // 0x80561DE4: sb          $a3, -0x13($s1)
    MEM_B(-0X13, ctx->r17) = ctx->r7;
    // 0x80561DE8: sb          $a3, -0x12($s1)
    MEM_B(-0X12, ctx->r17) = ctx->r7;
    // 0x80561DEC: bne         $at, $zero, L_80561DFC
    if (ctx->r1 != 0) {
        // 0x80561DF0: sb          $a3, -0x11($s1)
        MEM_B(-0X11, ctx->r17) = ctx->r7;
            goto L_80561DFC;
    }
    // 0x80561DF0: sb          $a3, -0x11($s1)
    MEM_B(-0X11, ctx->r17) = ctx->r7;
    // 0x80561DF4: addiu       $s4, $s4, -0x6C0
    ctx->r20 = ADD32(ctx->r20, -0X6C0);
    // 0x80561DF8: addiu       $s2, $s2, -0x6C0
    ctx->r18 = ADD32(ctx->r18, -0X6C0);
L_80561DFC:
    // 0x80561DFC: bne         $s3, $fp, L_80561CD4
    if (ctx->r19 != ctx->r30) {
        // 0x80561E00: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_80561CD4;
    }
    // 0x80561E00: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80561E04: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x80561E08: sh          $a0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r4;
    // 0x80561E0C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80561E10: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80561E14: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
    // 0x80561E18: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
    // 0x80561E1C: sh          $t7, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r15;
    // 0x80561E20: lh          $t8, 0x72E($s7)
    ctx->r24 = MEM_H(ctx->r23, 0X72E);
    // 0x80561E24: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80561E28: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80561E2C: sh          $t8, -0x16($s1)
    MEM_H(-0X16, ctx->r17) = ctx->r24;
    // 0x80561E30: lh          $t9, 0x730($s7)
    ctx->r25 = MEM_H(ctx->r23, 0X730);
    // 0x80561E34: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80561E38: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    // 0x80561E3C: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    // 0x80561E40: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80561E44: sh          $t0, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r8;
    // 0x80561E48: sh          $zero, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = 0;
    // 0x80561E4C: sh          $zero, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = 0;
    // 0x80561E50: sb          $v0, -0x14($s0)
    MEM_B(-0X14, ctx->r16) = ctx->r2;
    // 0x80561E54: sb          $v0, -0x13($s0)
    MEM_B(-0X13, ctx->r16) = ctx->r2;
    // 0x80561E58: sb          $v0, -0x12($s0)
    MEM_B(-0X12, ctx->r16) = ctx->r2;
    // 0x80561E5C: sb          $a3, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r7;
    // 0x80561E60: sb          $v0, -0x14($s1)
    MEM_B(-0X14, ctx->r17) = ctx->r2;
    // 0x80561E64: sb          $v0, -0x13($s1)
    MEM_B(-0X13, ctx->r17) = ctx->r2;
    // 0x80561E68: sb          $v0, -0x12($s1)
    MEM_B(-0X12, ctx->r17) = ctx->r2;
    // 0x80561E6C: sb          $v0, -0x11($s1)
    MEM_B(-0X11, ctx->r17) = ctx->r2;
    // 0x80561E70: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80561E74: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80561E78: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80561E7C: jal         0x8004921C
    // 0x80561E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x80561E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80561E84: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80561E88: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561E8C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80561E90: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80561E94: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80561E98: sub.s       $f20, $f0, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80561E9C: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x80561EA0: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80561EA4: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80561EA8: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
    // 0x80561EAC: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80561EB0: sub.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80561EB4: swc1        $f10, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f10.u32l;
    // 0x80561EB8: jal         0x80067114
    // 0x80561EBC: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    func_80067114(rdram, ctx);
        goto after_6;
    // 0x80561EBC: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    after_6:
    // 0x80561EC0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80561EC4: jal         0x80066E88
    // 0x80561EC8: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x80561EC8: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    after_7:
    // 0x80561ECC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80561ED0: jal         0x80066DE4
    // 0x80561ED4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x80561ED4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_8:
    // 0x80561ED8: mul.s       $f2, $f28, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80561EDC: sll         $v0, $s5, 6
    ctx->r2 = S32(ctx->r21 << 6);
    // 0x80561EE0: mul.s       $f12, $f28, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80561EE4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80561EE8: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561EEC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80561EF0: sub.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80561EF4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80561EF8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80561EFC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80561F00: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80561F04: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80561F08: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80561F0C: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80561F10: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x80561F14: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80561F18: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80561F1C: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80561F20: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80561F24: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80561F28: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80561F2C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80561F30: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80561F34: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80561F38: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x80561F3C: lh          $t0, 0x72E($s7)
    ctx->r8 = MEM_H(ctx->r23, 0X72E);
    // 0x80561F40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80561F44: sh          $t0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r8;
    // 0x80561F48: lh          $t1, 0x730($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X730);
    // 0x80561F4C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80561F50: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x80561F54: sh          $t1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r9;
    // 0x80561F58: sh          $t2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r10;
    // 0x80561F5C: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80561F60: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x80561F64: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80561F68: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80561F6C: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x80561F70: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x80561F74: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // 0x80561F78: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x80561F7C: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x80561F80: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x80561F84: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80561F88: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80561F8C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80561F90: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80561F94: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80561F98: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80561F9C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80561FA0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80561FA4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80561FA8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80561FAC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80561FB0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80561FB4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80561FB8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80561FBC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80561FC0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80561FC4: jr          $ra
    // 0x80561FC8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80561FC8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void gfxprint_setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EF00: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8007EF04: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007EF08: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007EF0C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007EF10: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007EF14: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EF18: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007EF1C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8007EF20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007EF24: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007EF28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EF2C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007EF30: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EF34: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x8007EF38: ori         $t9, $zero, 0xECF0
    ctx->r25 = 0 | 0XECF0;
    // 0x8007EF3C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007EF40: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EF44: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007EF48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007EF4C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EF50: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8007EF54: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x8007EF58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007EF5C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007EF60: ori         $a3, $a3, 0x4244
    ctx->r7 = ctx->r7 | 0X4244;
    // 0x8007EF64: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x8007EF68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007EF6C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8007EF70: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EF74: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8007EF78: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8007EF7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007EF80: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007EF84: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8007EF88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007EF8C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EF90: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x8007EF94: ori         $t7, $t7, 0xFE23
    ctx->r15 = ctx->r15 | 0XFE23;
    // 0x8007EF98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007EF9C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007EFA0: addiu       $t8, $zero, -0xC07
    ctx->r24 = ADD32(0, -0XC07);
    // 0x8007EFA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007EFA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007EFAC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EFB0: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x8007EFB4: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x8007EFB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007EFBC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007EFC0: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8007EFC4: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x8007EFC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007EFCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007EFD0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EFD4: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007EFD8: addiu       $t6, $t6, -0x64F8
    ctx->r14 = ADD32(ctx->r14, -0X64F8);
    // 0x8007EFDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007EFE0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007EFE4: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8007EFE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007EFEC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007EFF0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EFF4: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007EFF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8007EFFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F000: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F004: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F008: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x8007F00C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007F010: div         $zero, $t8, $t3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r11)));
    // 0x8007F014: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8007F018: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007F01C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F020: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007F024: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007F028: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F02C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F034: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007F038: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F03C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007F040: addiu       $v1, $zero, 0x3FF
    ctx->r3 = ADD32(0, 0X3FF);
    // 0x8007F044: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F048: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F04C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007F050: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F054: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x8007F058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007F05C: lui         $a1, 0xF540
    ctx->r5 = S32(0XF540 << 16);
    // 0x8007F060: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8007F064: bne         $t3, $zero, L_8007F070
    if (ctx->r11 != 0) {
        // 0x8007F068: nop
    
            goto L_8007F070;
    }
    // 0x8007F068: nop

    // 0x8007F06C: break       7
    do_break(2148003948);
L_8007F070:
    // 0x8007F070: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F074: bne         $t3, $at, L_8007F088
    if (ctx->r11 != ctx->r1) {
        // 0x8007F078: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F088;
    }
    // 0x8007F078: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F07C: bne         $t8, $at, L_8007F088
    if (ctx->r24 != ctx->r1) {
        // 0x8007F080: nop
    
            goto L_8007F088;
    }
    // 0x8007F080: nop

    // 0x8007F084: break       6
    do_break(2148003972);
L_8007F088:
    // 0x8007F088: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x8007F08C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007F090: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007F094: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8007F098: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F09C: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x8007F0A0: ori         $t6, $t6, 0xC3FC
    ctx->r14 = ctx->r14 | 0XC3FC;
    // 0x8007F0A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F0A8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F0AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F0B0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007F0B4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F0B8: lui         $a2, 0xF200
    ctx->r6 = S32(0XF200 << 16);
    // 0x8007F0BC: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x8007F0C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F0C4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F0C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F0CC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007F0D0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F0D4: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8007F0D8: addiu       $t7, $t7, -0x65A0
    ctx->r15 = ADD32(ctx->r15, -0X65A0);
    // 0x8007F0DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F0E0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F0E4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007F0E8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007F0EC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F0F0: lui         $t4, 0xE800
    ctx->r12 = S32(0XE800 << 16);
    // 0x8007F0F4: lui         $t5, 0xF000
    ctx->r13 = S32(0XF000 << 16);
    // 0x8007F0F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F0FC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F100: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F104: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007F108: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F10C: lui         $s3, 0x3
    ctx->r19 = S32(0X3 << 16);
    // 0x8007F110: ori         $s3, $s3, 0xC000
    ctx->r19 = ctx->r19 | 0XC000;
    // 0x8007F114: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8007F118: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F11C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F120: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007F124: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007F128: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8007F12C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8007F130: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007F134: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007F138: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8007F13C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8007F140: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F144: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F148: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F14C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007F150: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F154: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8007F158: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F15C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007F160: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F164: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F168: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007F16C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8007F170: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007F174: lui         $t8, 0x70F
    ctx->r24 = S32(0X70F << 16);
    // 0x8007F178: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8007F17C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007F180: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F184: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007F188: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F18C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F190: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F194: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007F198: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F19C: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8007F1A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F1A4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007F1A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F1AC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F1B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007F1B4: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8007F1B8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007F1BC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_8007F1C0:
    // 0x8007F1C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F1C4: andi        $s1, $s0, 0x7
    ctx->r17 = ctx->r16 & 0X7;
    // 0x8007F1C8: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007F1CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F1D0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F1D4: sll         $t6, $t9, 20
    ctx->r14 = S32(ctx->r25 << 20);
    // 0x8007F1D8: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x8007F1DC: or          $t8, $s1, $t6
    ctx->r24 = ctx->r17 | ctx->r14;
    // 0x8007F1E0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F1E4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007F1E8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F1EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007F1F0: or          $t9, $s1, $s3
    ctx->r25 = ctx->r17 | ctx->r19;
    // 0x8007F1F4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F1F8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8007F1FC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F200: ori         $t6, $t9, 0x3FC
    ctx->r14 = ctx->r25 | 0X3FC;
    // 0x8007F204: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007F208: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007F20C: bne         $at, $zero, L_8007F1C0
    if (ctx->r1 != 0) {
        // 0x8007F210: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_8007F1C0;
    }
    // 0x8007F210: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007F214: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F218: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007F21C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007F220: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F224: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F228: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F22C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8007F230: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8007F234: addiu       $t7, $t7, -0x6500
    ctx->r15 = ADD32(ctx->r15, -0X6500);
    // 0x8007F238: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007F23C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F240: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x8007F244: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8007F248: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F24C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F250: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F254: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F258: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F25C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8007F260: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x8007F264: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F268: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F26C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8007F270: ori         $t8, $t8, 0xC010
    ctx->r24 = ctx->r24 | 0XC010;
    // 0x8007F274: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F278: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007F27C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F280: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8007F284: ori         $t8, $t8, 0x201C
    ctx->r24 = ctx->r24 | 0X201C;
    // 0x8007F288: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F28C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F290: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F294: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007F298: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F29C: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8007F2A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F2A4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F2A8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F2AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007F2B0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F2B4: lui         $t6, 0x140
    ctx->r14 = S32(0X140 << 16);
    // 0x8007F2B8: ori         $t6, $t6, 0xC010
    ctx->r14 = ctx->r14 | 0XC010;
    // 0x8007F2BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F2C0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F2C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F2C8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007F2CC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F2D0: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8007F2D4: ori         $t7, $t7, 0x401C
    ctx->r15 = ctx->r15 | 0X401C;
    // 0x8007F2D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F2DC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F2E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007F2E4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007F2E8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F2EC: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007F2F0: addiu       $t6, $t6, -0x6520
    ctx->r14 = ADD32(ctx->r14, -0X6520);
    // 0x8007F2F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F2F8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F2FC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F300: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007F304: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F308: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F30C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F310: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007F314: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007F318: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F31C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007F320: ori         $t9, $t9, 0x140
    ctx->r25 = ctx->r25 | 0X140;
    // 0x8007F324: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F328: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F32C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F330: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007F334: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F338: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8007F33C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F340: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F344: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007F348: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F34C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F350: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8007F354: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8007F358: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F35C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F360: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F364: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007F368: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F36C: lui         $t2, 0x40
    ctx->r10 = S32(0X40 << 16);
    // 0x8007F370: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F374: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F378: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F37C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007F380: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F384: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F388: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F38C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F390: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_8007F394:
    // 0x8007F394: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F398: andi        $t0, $s1, 0x7
    ctx->r8 = ctx->r17 & 0X7;
    // 0x8007F39C: sll         $t0, $t0, 24
    ctx->r8 = S32(ctx->r8 << 24);
    // 0x8007F3A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F3A4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F3A8: or          $t8, $t0, $t2
    ctx->r24 = ctx->r8 | ctx->r10;
    // 0x8007F3AC: ori         $t9, $t8, 0xC010
    ctx->r25 = ctx->r24 | 0XC010;
    // 0x8007F3B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007F3B4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007F3B8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F3BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007F3C0: ori         $t7, $t0, 0x401C
    ctx->r15 = ctx->r8 | 0X401C;
    // 0x8007F3C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F3C8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F3CC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8007F3D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F3D4: bne         $v1, $t3, L_8007F394
    if (ctx->r3 != ctx->r11) {
        // 0x8007F3D8: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_8007F394;
    }
    // 0x8007F3D8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007F3DC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007F3E0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007F3E4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007F3E8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007F3EC: jr          $ra
    // 0x8007F3F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8007F3F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8002E90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E90C: lbu         $v0, 0x12C8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X12C8);
    // 0x8002E910: lhu         $v1, 0x12BE($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12BE);
    // 0x8002E914: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8002E918: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8002E91C: beq         $v0, $zero, L_8002EAFC
    if (ctx->r2 == 0) {
        // 0x8002E920: lwc1        $f12, 0x74($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X74);
            goto L_8002EAFC;
    }
    // 0x8002E920: lwc1        $f12, 0x74($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8002E924: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8002E928: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8002E92C: beq         $a0, $zero, L_8002E99C
    if (ctx->r4 == 0) {
        // 0x8002E930: addu        $a2, $a0, $v0
        ctx->r6 = ADD32(ctx->r4, ctx->r2);
            goto L_8002E99C;
    }
    // 0x8002E930: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x8002E934: addiu       $t0, $zero, 0x4301
    ctx->r8 = ADD32(0, 0X4301);
    // 0x8002E938: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
L_8002E93C:
    // 0x8002E93C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E940: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E944: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8002E948: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002E94C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002E950: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8002E954: lw          $a0, 0x11FC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X11FC);
    // 0x8002E958: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x8002E95C: beq         $t0, $t8, L_8002E990
    if (ctx->r8 == ctx->r24) {
        // 0x8002E960: nop
    
            goto L_8002E990;
    }
    // 0x8002E960: nop

    // 0x8002E964: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8002E968: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002E96C: lwc1        $f16, 0x80($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8002E970: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002E974: nop

    // 0x8002E978: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002E97C: nop

    // 0x8002E980: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002E984: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8002E988: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8002E98C: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
L_8002E990:
    // 0x8002E990: bne         $a2, $v0, L_8002E93C
    if (ctx->r6 != ctx->r2) {
        // 0x8002E994: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_8002E93C;
    }
    // 0x8002E994: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8002E998: beq         $v0, $zero, L_8002EAFC
    if (ctx->r2 == 0) {
        // 0x8002E99C: addiu       $a3, $zero, 0x18
        ctx->r7 = ADD32(0, 0X18);
            goto L_8002EAFC;
    }
L_8002E99C:
    // 0x8002E99C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x8002E9A0: addiu       $t0, $zero, 0x4301
    ctx->r8 = ADD32(0, 0X4301);
L_8002E9A4:
    // 0x8002E9A4: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E9A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E9AC: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8002E9B0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8002E9B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8002E9B8: mflo        $t9
    ctx->r25 = lo;
    // 0x8002E9BC: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8002E9C0: lw          $a0, 0x11FC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X11FC);
    // 0x8002E9C4: lhu         $t2, 0xC($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XC);
    // 0x8002E9C8: beq         $t0, $t2, L_8002E9FC
    if (ctx->r8 == ctx->r10) {
        // 0x8002E9CC: nop
    
            goto L_8002E9FC;
    }
    // 0x8002E9CC: nop

    // 0x8002E9D0: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8002E9D4: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002E9D8: lwc1        $f16, 0x80($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8002E9DC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002E9E0: nop

    // 0x8002E9E4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002E9E8: nop

    // 0x8002E9EC: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002E9F0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8002E9F4: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8002E9F8: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
L_8002E9FC:
    // 0x8002E9FC: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EA04: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8002EA08: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8002EA0C: mflo        $t3
    ctx->r11 = lo;
    // 0x8002EA10: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8002EA14: lw          $a0, 0x11FC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X11FC);
    // 0x8002EA18: lhu         $t5, 0xC($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XC);
    // 0x8002EA1C: beq         $t0, $t5, L_8002EA50
    if (ctx->r8 == ctx->r13) {
        // 0x8002EA20: nop
    
            goto L_8002EA50;
    }
    // 0x8002EA20: nop

    // 0x8002EA24: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8002EA28: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002EA2C: lwc1        $f16, 0x80($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8002EA30: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002EA34: nop

    // 0x8002EA38: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002EA3C: nop

    // 0x8002EA40: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002EA44: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8002EA48: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8002EA4C: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
L_8002EA50:
    // 0x8002EA50: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EA58: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8002EA5C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8002EA60: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EA64: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8002EA68: lw          $a0, 0x11FC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X11FC);
    // 0x8002EA6C: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x8002EA70: beq         $t0, $t8, L_8002EAA4
    if (ctx->r8 == ctx->r24) {
        // 0x8002EA74: nop
    
            goto L_8002EAA4;
    }
    // 0x8002EA74: nop

    // 0x8002EA78: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8002EA7C: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002EA80: lwc1        $f16, 0x80($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8002EA84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002EA88: nop

    // 0x8002EA8C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002EA90: nop

    // 0x8002EA94: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002EA98: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8002EA9C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8002EAA0: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
L_8002EAA4:
    // 0x8002EAA4: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EAA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EAAC: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8002EAB0: mflo        $t9
    ctx->r25 = lo;
    // 0x8002EAB4: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8002EAB8: lw          $a0, 0x11FC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X11FC);
    // 0x8002EABC: lhu         $t2, 0xC($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XC);
    // 0x8002EAC0: beq         $t0, $t2, L_8002EAF4
    if (ctx->r8 == ctx->r10) {
        // 0x8002EAC4: nop
    
            goto L_8002EAF4;
    }
    // 0x8002EAC4: nop

    // 0x8002EAC8: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8002EACC: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002EAD0: lwc1        $f16, 0x80($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8002EAD4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002EAD8: nop

    // 0x8002EADC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002EAE0: nop

    // 0x8002EAE4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002EAE8: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8002EAEC: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8002EAF0: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
L_8002EAF4:
    // 0x8002EAF4: bne         $v0, $zero, L_8002E9A4
    if (ctx->r2 != 0) {
        // 0x8002EAF8: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_8002E9A4;
    }
    // 0x8002EAF8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8002EAFC:
    // 0x8002EAFC: jr          $ra
    // 0x8002EB00: nop

    return;
    // 0x8002EB00: nop

;}
RECOMP_FUNC void func_80078184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078184: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80078188: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007818C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80078190: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80078194: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80078198: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007819C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800781A0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800781A4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800781A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800781AC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800781B0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800781B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800781B8: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x800781BC: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800781C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800781C4: sll         $t0, $v0, 8
    ctx->r8 = S32(ctx->r2 << 8);
    // 0x800781C8: srl         $t1, $t0, 24
    ctx->r9 = S32(U32(ctx->r8) >> 24);
    // 0x800781CC: srl         $t9, $v0, 24
    ctx->r25 = S32(U32(ctx->r2) >> 24);
    // 0x800781D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800781D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800781D8: lw          $v1, 0x4($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X4);
    // 0x800781DC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800781E0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800781E4: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x800781E8: sra         $t4, $t3, 24
    ctx->r12 = S32(SIGNED(ctx->r11) >> 24);
    // 0x800781EC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800781F0: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x800781F4: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800781F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800781FC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80078200: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80078204: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078208: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8007820C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80078210: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80078214: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80078218: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8007821C: mul.s       $f16, $f6, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80078220: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80078224: jal         0x8007A700
    // 0x80078228: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_8007A700(rdram, ctx);
        goto after_0;
    // 0x80078228: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8007822C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80078230: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80078234: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80078238: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007823C: jr          $ra
    // 0x80078240: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80078240: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8069A058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069A058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069A05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A060: jal         0x80699C60
    // 0x8069A064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x8069A064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069A068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069A06C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069A070: jal         0x8069A0F0
    // 0x8069A074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x8069A074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8069A078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A080: jr          $ra
    // 0x8069A084: nop

    return;
    // 0x8069A084: nop

;}
RECOMP_FUNC void func_80033984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003398C: jal         0x80021B44
    // 0x80033990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021B44(rdram, ctx);
        goto after_0;
    // 0x80033990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033994: bne         $v0, $zero, L_800339A4
    if (ctx->r2 != 0) {
        // 0x80033998: nop
    
            goto L_800339A4;
    }
    // 0x80033998: nop

    // 0x8003399C: b           L_800339F0
    // 0x800339A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800339F0;
    // 0x800339A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800339A4:
    // 0x800339A4: jal         0x80033494
    // 0x800339A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033494(rdram, ctx);
        goto after_1;
    // 0x800339A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800339AC: bne         $v0, $zero, L_800339BC
    if (ctx->r2 != 0) {
        // 0x800339B0: nop
    
            goto L_800339BC;
    }
    // 0x800339B0: nop

    // 0x800339B4: b           L_800339F0
    // 0x800339B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800339F0;
    // 0x800339B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800339BC:
    // 0x800339BC: jal         0x80033160
    // 0x800339C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033160(rdram, ctx);
        goto after_2;
    // 0x800339C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800339C4: beq         $v0, $zero, L_800339D4
    if (ctx->r2 == 0) {
        // 0x800339C8: nop
    
            goto L_800339D4;
    }
    // 0x800339C8: nop

    // 0x800339CC: b           L_800339F0
    // 0x800339D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800339F0;
    // 0x800339D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800339D4:
    // 0x800339D4: jal         0x800334EC
    // 0x800339D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800334EC(rdram, ctx);
        goto after_3;
    // 0x800339D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800339DC: bnel        $v0, $zero, L_800339F0
    if (ctx->r2 != 0) {
        // 0x800339E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800339F0;
    }
    goto skip_0;
    // 0x800339E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800339E4: b           L_800339F0
    // 0x800339E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800339F0;
    // 0x800339E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800339EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800339F0:
    // 0x800339F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800339F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800339F8: jr          $ra
    // 0x800339FC: nop

    return;
    // 0x800339FC: nop

;}
RECOMP_FUNC void func_8046B40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B40C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8046B410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046B414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046B418: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046B41C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046B420: lw          $v0, 0xC80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC80);
    // 0x8046B424: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8046B428: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8046B42C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8046B430: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8046B434: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8046B438: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8046B43C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8046B440: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8046B444: addu        $a3, $s0, $t6
    ctx->r7 = ADD32(ctx->r16, ctx->r14);
    // 0x8046B448: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8046B44C: jal         0x8004921C
    // 0x8046B450: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8046B450: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046B454: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8046B458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046B45C: jal         0x8004921C
    // 0x8046B460: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8046B460: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    after_1:
    // 0x8046B464: lh          $t2, 0x82($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X82);
    // 0x8046B468: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8046B46C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8046B470: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x8046B474: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046B478: lbu         $t6, 0x145($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X145);
    // 0x8046B47C: lw          $t8, 0x168($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X168);
    // 0x8046B480: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8046B484: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8046B488: addiu       $t5, $a3, 0x8
    ctx->r13 = ADD32(ctx->r7, 0X8);
    // 0x8046B48C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8046B490: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B494: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8046B498: mflo        $t9
    ctx->r25 = lo;
    // 0x8046B49C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B4A0: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
    // 0x8046B4A4: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046B4A8: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8046B4AC: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(138, 0X2858) << 16);
    // 0x8046B4B0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8046B4B4: sw          $ra, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r31;
    // 0x8046B4B8: addiu       $t8, $t8, -0x4068
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(138, 0X2858));
    // 0x8046B4BC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8046B4C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046B4C4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8046B4C8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B4CC: mflo        $t7
    ctx->r15 = lo;
    // 0x8046B4D0: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8046B4D4: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8046B4D8: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046B4DC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8046B4E0: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8046B4E4: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8046B4E8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B4EC: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8046B4F0: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8046B4F4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8046B4F8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B4FC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8046B500: mflo        $a0
    ctx->r4 = lo;
    // 0x8046B504: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8046B508: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8046B50C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8046B510: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x8046B514: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8046B518: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8046B51C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8046B520: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8046B524: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8046B528: beq         $at, $zero, L_8046B538
    if (ctx->r1 == 0) {
        // 0x8046B52C: addiu       $t5, $t5, 0x8
        ctx->r13 = ADD32(ctx->r13, 0X8);
            goto L_8046B538;
    }
    // 0x8046B52C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B530: b           L_8046B53C
    // 0x8046B534: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
        goto L_8046B53C;
    // 0x8046B534: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8046B538:
    // 0x8046B538: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_8046B53C:
    // 0x8046B53C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x8046B540: bgez        $t1, L_8046B550
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8046B544: sra         $v1, $t1, 3
        ctx->r3 = S32(SIGNED(ctx->r9) >> 3);
            goto L_8046B550;
    }
    // 0x8046B544: sra         $v1, $t1, 3
    ctx->r3 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8046B548: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x8046B54C: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_8046B550:
    // 0x8046B550: bgtz        $v1, L_8046B560
    if (SIGNED(ctx->r3) > 0) {
        // 0x8046B554: or          $t3, $v1, $zero
        ctx->r11 = ctx->r3 | 0;
            goto L_8046B560;
    }
    // 0x8046B554: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8046B558: b           L_8046B560
    // 0x8046B55C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8046B560;
    // 0x8046B55C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8046B560:
    // 0x8046B560: bgtz        $v1, L_8046B570
    if (SIGNED(ctx->r3) > 0) {
        // 0x8046B564: addiu       $t7, $t3, 0x7FF
        ctx->r15 = ADD32(ctx->r11, 0X7FF);
            goto L_8046B570;
    }
    // 0x8046B564: addiu       $t7, $t3, 0x7FF
    ctx->r15 = ADD32(ctx->r11, 0X7FF);
    // 0x8046B568: b           L_8046B574
    // 0x8046B56C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8046B574;
    // 0x8046B56C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8046B570:
    // 0x8046B570: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8046B574:
    // 0x8046B574: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x8046B578: bne         $a2, $zero, L_8046B584
    if (ctx->r6 != 0) {
        // 0x8046B57C: nop
    
            goto L_8046B584;
    }
    // 0x8046B57C: nop

    // 0x8046B580: break       7
    do_break(2152117632);
L_8046B584:
    // 0x8046B584: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8046B588: bne         $a2, $at, L_8046B59C
    if (ctx->r6 != ctx->r1) {
        // 0x8046B58C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8046B59C;
    }
    // 0x8046B58C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8046B590: bne         $t7, $at, L_8046B59C
    if (ctx->r15 != ctx->r1) {
        // 0x8046B594: nop
    
            goto L_8046B59C;
    }
    // 0x8046B594: nop

    // 0x8046B598: break       6
    do_break(2152117656);
L_8046B59C:
    // 0x8046B59C: mflo        $t6
    ctx->r14 = lo;
    // 0x8046B5A0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8046B5A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8046B5A8: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x8046B5AC: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8046B5B0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8046B5B4: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8046B5B8: addiu       $t7, $t1, 0x7
    ctx->r15 = ADD32(ctx->r9, 0X7);
    // 0x8046B5BC: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8046B5C0: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8046B5C4: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8046B5C8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B5CC: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B5D0: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8046B5D4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8046B5D8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8046B5DC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8046B5E0: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8046B5E4: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x8046B5E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8046B5EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8046B5F0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8046B5F4: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B5F8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8046B5FC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8046B600: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8046B604: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8046B608: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8046B60C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8046B610: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8046B614: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8046B618: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8046B61C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8046B620: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B624: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8046B628: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8046B62C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B630: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8046B634: lui         $a2, 0xBC00
    ctx->r6 = S32(0XBC00 << 16);
    // 0x8046B638: ori         $a2, $a2, 0x2
    ctx->r6 = ctx->r6 | 0X2;
    // 0x8046B63C: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x8046B640: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8046B644: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8046B648: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8046B64C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B650: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B654: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8046B658: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8046B65C: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x8046B660: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8046B664: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B668: addiu       $t9, $s0, 0xE98
    ctx->r25 = ADD32(ctx->r16, 0XE98);
    // 0x8046B66C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8046B670: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8046B674: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8046B678: lui         $t7, 0x388
    ctx->r15 = S32(0X388 << 16);
    // 0x8046B67C: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8046B680: addiu       $t6, $s0, 0xE90
    ctx->r14 = ADD32(ctx->r16, 0XE90);
    // 0x8046B684: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8046B688: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8046B68C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8046B690: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B694: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x8046B698: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x8046B69C: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    // 0x8046B6A0: addiu       $a0, $a0, 0xE10
    ctx->r4 = ADD32(ctx->r4, 0XE10);
    // 0x8046B6A4: jal         0x80086F28
    // 0x8046B6A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    gMtxIdent(rdram, ctx);
        goto after_2;
    // 0x8046B6A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8046B6AC: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x8046B6B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8046B6B4: lui         $t7, 0x104
    ctx->r15 = S32(0X104 << 16);
    // 0x8046B6B8: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8046B6BC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8046B6C0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8046B6C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8046B6C8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8046B6CC: ori         $t6, $t6, 0x617F
    ctx->r14 = ctx->r14 | 0X617F;
    // 0x8046B6D0: addiu       $t8, $s0, 0xC88
    ctx->r24 = ADD32(ctx->r16, 0XC88);
    // 0x8046B6D4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8046B6D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8046B6DC: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8046B6E0: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B6E4: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8046B6E8: lui         $t9, 0xB100
    ctx->r25 = S32(0XB100 << 16);
    // 0x8046B6EC: ori         $t9, $t9, 0x406
    ctx->r25 = ctx->r25 | 0X406;
    // 0x8046B6F0: ori         $t7, $t7, 0x6
    ctx->r15 = ctx->r15 | 0X6;
    // 0x8046B6F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8046B6F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8046B6FC: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B700: lui         $t6, 0xB108
    ctx->r14 = S32(0XB108 << 16);
    // 0x8046B704: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8046B708: ori         $t6, $t6, 0xC0E
    ctx->r14 = ctx->r14 | 0XC0E;
    // 0x8046B70C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B710: lui         $t8, 0xA
    ctx->r24 = S32(0XA << 16);
    // 0x8046B714: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8046B718: ori         $t8, $t8, 0x80E
    ctx->r24 = ctx->r24 | 0X80E;
    // 0x8046B71C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8046B720: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x8046B724: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8046B728: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8046B72C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8046B730: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8046B734: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8046B738: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    // 0x8046B73C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8046B740: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8046B744: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x8046B748: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8046B74C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B750: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x8046B754: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B758: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x8046B75C: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x8046B760: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8046B764: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x8046B768: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8046B76C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8046B770: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8046B774: addiu       $t9, $v0, 0xC
    ctx->r25 = ADD32(ctx->r2, 0XC);
    // 0x8046B778: addiu       $a2, $v0, 0x8
    ctx->r6 = ADD32(ctx->r2, 0X8);
    // 0x8046B77C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8046B780: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8046B784: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8046B788: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8046B78C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8046B790: addiu       $a3, $v0, 0xE
    ctx->r7 = ADD32(ctx->r2, 0XE);
    // 0x8046B794: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8046B798: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8046B79C: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x8046B7A0: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8046B7A4: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B7A8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B7AC: addiu       $t7, $v0, 0xA
    ctx->r15 = ADD32(ctx->r2, 0XA);
    // 0x8046B7B0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8046B7B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8046B7B8: sll         $t6, $a2, 8
    ctx->r14 = S32(ctx->r6 << 8);
    // 0x8046B7BC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8046B7C0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8046B7C4: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x8046B7C8: addiu       $t6, $v0, 0x14
    ctx->r14 = ADD32(ctx->r2, 0X14);
    // 0x8046B7CC: addiu       $t0, $v0, 0x10
    ctx->r8 = ADD32(ctx->r2, 0X10);
    // 0x8046B7D0: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x8046B7D4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8046B7D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8046B7DC: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8046B7E0: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8046B7E4: addiu       $t1, $v0, 0x16
    ctx->r9 = ADD32(ctx->r2, 0X16);
    // 0x8046B7E8: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x8046B7EC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8046B7F0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x8046B7F4: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x8046B7F8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B7FC: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B800: addiu       $t9, $v0, 0x12
    ctx->r25 = ADD32(ctx->r2, 0X12);
    // 0x8046B804: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8046B808: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8046B80C: sll         $t8, $t0, 8
    ctx->r24 = S32(ctx->r8 << 8);
    // 0x8046B810: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8046B814: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8046B818: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x8046B81C: addiu       $t8, $v0, 0x1C
    ctx->r24 = ADD32(ctx->r2, 0X1C);
    // 0x8046B820: addiu       $t2, $v0, 0x18
    ctx->r10 = ADD32(ctx->r2, 0X18);
    // 0x8046B824: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x8046B828: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8046B82C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8046B830: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8046B834: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x8046B838: addiu       $t3, $v0, 0x1E
    ctx->r11 = ADD32(ctx->r2, 0X1E);
    // 0x8046B83C: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x8046B840: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8046B844: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8046B848: or          $t7, $t9, $t4
    ctx->r15 = ctx->r25 | ctx->r12;
    // 0x8046B84C: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B850: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8046B854: addiu       $t6, $v0, 0x1A
    ctx->r14 = ADD32(ctx->r2, 0X1A);
    // 0x8046B858: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8046B85C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8046B860: sll         $t7, $t2, 8
    ctx->r15 = S32(ctx->r10 << 8);
    // 0x8046B864: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8046B868: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8046B86C: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x8046B870: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B874: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8046B878: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8046B87C: lui         $t9, 0xBD00
    ctx->r25 = S32(0XBD00 << 16);
    // 0x8046B880: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8046B884: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8046B888: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x8046B88C: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
    // 0x8046B890: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x8046B894: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8046B898: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x8046B89C: sw          $t6, 0xC80($s0)
    MEM_W(0XC80, ctx->r16) = ctx->r14;
    // 0x8046B8A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046B8A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046B8A8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8046B8AC: jr          $ra
    // 0x8046B8B0: nop

    return;
    // 0x8046B8B0: nop

;}
RECOMP_FUNC void func_806F1898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F189C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F18A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F18A4: jal         0x8004700C
    // 0x806F18A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F18A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F18AC: beq         $v0, $zero, L_806F1928
    if (ctx->r2 == 0) {
        // 0x806F18B0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_806F1928;
    }
    // 0x806F18B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806F18B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F18B8: jal         0x80062684
    // 0x806F18BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_1;
    // 0x806F18BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x806F18C0: jal         0x806F16CC
    // 0x806F18C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F16CC(rdram, ctx);
        goto after_2;
    // 0x806F18C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F18C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806F18CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806F18D0: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x806F18D4: bnel        $s0, $t7, L_806F192C
    if (ctx->r16 != ctx->r15) {
        // 0x806F18D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F192C;
    }
    goto skip_0;
    // 0x806F18D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F18DC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806F18E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F18E4: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F18E8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F18EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F18F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F18F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F18F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806F18FC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x806F1900: jal         0x806F1F14
    // 0x806F1904: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_3;
    // 0x806F1904: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x806F1908: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806F190C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806F1910: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806F1914: jal         0x80067BBC
    // 0x806F1918: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806F1918: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x806F191C: addiu       $a0, $zero, 0x216
    ctx->r4 = ADD32(0, 0X216);
    // 0x806F1920: jal         0x80067818
    // 0x806F1924: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F1924: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_806F1928:
    // 0x806F1928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F192C:
    // 0x806F192C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F1934: jr          $ra
    // 0x806F1938: nop

    return;
    // 0x806F1938: nop

;}
RECOMP_FUNC void func_80400C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400C58: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80400C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80400C60: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80400C64: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x80400C68: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80400C6C: lw          $t6, 0xF0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XF0);
    // 0x80400C70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80400C74: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80400C78: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80400C7C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80400C80: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80400C84: lw          $a2, 0x16C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X16C);
    // 0x80400C88: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80400C8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80400C90: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x80400C94: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x80400C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80400C9C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80400CA0: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80400CA4: jal         0x8004921C
    // 0x80400CA8: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80400CA8: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_0:
    // 0x80400CAC: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80400CB0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80400CB4: jal         0x8004921C
    // 0x80400CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80400CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80400CBC: lbu         $t5, 0x1F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1F);
    // 0x80400CC0: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x80400CC4: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x80400CC8: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80400CCC: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80400CD0: lbu         $t7, 0x145($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X145);
    // 0x80400CD4: lw          $t9, 0x168($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X168);
    // 0x80400CD8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400CDC: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80400CE0: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80400CE4: lw          $t4, 0x80($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X80);
    // 0x80400CE8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80400CEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400CF0: mflo        $t6
    ctx->r14 = lo;
    // 0x80400CF4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80400CF8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80400CFC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80400D00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80400D04: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x80400D08: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80400D0C: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x80400D10: ori         $t6, $t6, 0x2C80
    ctx->r14 = ctx->r14 | 0X2C80;
    // 0x80400D14: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400D18: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400D1C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80400D20: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80400D24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400D28: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80400D2C: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x80400D30: ori         $a3, $a3, 0x4340
    ctx->r7 = ctx->r7 | 0X4340;
    // 0x80400D34: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80400D38: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80400D3C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80400D40: mflo        $t8
    ctx->r24 = lo;
    // 0x80400D44: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80400D48: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80400D4C: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x80400D50: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80400D54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400D58: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x80400D5C: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x80400D60: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80400D64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80400D68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80400D6C: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80400D70: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x80400D74: lbu         $t5, 0x3($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X3);
    // 0x80400D78: lbu         $t4, 0x2($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X2);
    // 0x80400D7C: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80400D80: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80400D84: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x80400D88: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x80400D8C: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x80400D90: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80400D94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80400D98: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400D9C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400DA0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80400DA4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80400DA8: lbu         $t6, 0x4($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X4);
    // 0x80400DAC: lbu         $t5, 0x5($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5);
    // 0x80400DB0: lbu         $t4, 0x7($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X7);
    // 0x80400DB4: lbu         $t9, 0x6($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X6);
    // 0x80400DB8: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x80400DBC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80400DC0: or          $t7, $t4, $t8
    ctx->r15 = ctx->r12 | ctx->r24;
    // 0x80400DC4: or          $t4, $t7, $t6
    ctx->r12 = ctx->r15 | ctx->r14;
    // 0x80400DC8: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x80400DCC: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80400DD0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400DD4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80400DD8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80400DDC: lui         $t6, 0xFC30
    ctx->r14 = S32(0XFC30 << 16);
    // 0x80400DE0: lui         $t8, 0x44FE
    ctx->r24 = S32(0X44FE << 16);
    // 0x80400DE4: ori         $t8, $t8, 0x7339
    ctx->r24 = ctx->r24 | 0X7339;
    // 0x80400DE8: ori         $t6, $t6, 0xFE61
    ctx->r14 = ctx->r14 | 0XFE61;
    // 0x80400DEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400DF0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80400DF4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80400DF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80400DFC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E00: addiu       $t4, $zero, 0x204
    ctx->r12 = ADD32(0, 0X204);
    // 0x80400E04: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80400E08: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400E0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80400E10: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80400E14: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80400E18: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x80400E1C: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80400E20: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80400E24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E28: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80400E2C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80400E30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80400E34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E38: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x80400E3C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80400E40: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80400E44: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80400E48: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80400E4C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80400E50: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E54: lui         $t8, 0xF570
    ctx->r24 = S32(0XF570 << 16);
    // 0x80400E58: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80400E5C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80400E60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80400E68: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80400E6C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80400E70: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E74: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80400E78: lui         $t7, 0x71F
    ctx->r15 = S32(0X71F << 16);
    // 0x80400E7C: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x80400E80: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400E84: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x80400E88: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80400E8C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400E90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80400E94: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80400E98: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80400E9C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80400EA0: lui         $t6, 0xF568
    ctx->r14 = S32(0XF568 << 16);
    // 0x80400EA4: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x80400EA8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400EAC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80400EB0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80400EB4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80400EB8: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x80400EBC: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x80400EC0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80400EC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80400EC8: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80400ECC: lw          $t4, 0x134($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X134);
    // 0x80400ED0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400ED4: lui         $t7, 0x8040
    ctx->r15 = S32(RELOC_HI16(8, 0X1BB8) << 16);
    // 0x80400ED8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80400EDC: addiu       $t7, $t7, 0x1BF8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(8, 0X1BB8));
    // 0x80400EE0: lui         $t6, 0x104
    ctx->r14 = S32(0X104 << 16);
    // 0x80400EE4: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80400EE8: addu        $t2, $t5, $t7
    ctx->r10 = ADD32(ctx->r13, ctx->r15);
    // 0x80400EEC: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80400EF0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400EF4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80400EF8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80400EFC: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80400F00: ori         $t8, $t8, 0x144F
    ctx->r24 = ctx->r24 | 0X144F;
    // 0x80400F04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80400F08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80400F0C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80400F10: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400F14: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80400F18: lui         $t5, 0x8040
    ctx->r13 = S32(RELOC_HI16(8, 0X1B90) << 16);
    // 0x80400F1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80400F20: addiu       $t5, $t5, 0x1BD0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(8, 0X1B90));
    // 0x80400F24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400F28: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80400F2C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80400F30: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80400F34: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80400F38: lui         $t7, 0xBD00
    ctx->r15 = S32(0XBD00 << 16);
    // 0x80400F3C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80400F40: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80400F44: lw          $t6, 0x134($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X134);
    // 0x80400F48: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80400F4C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80400F50: slti        $at, $t8, 0x168
    ctx->r1 = SIGNED(ctx->r24) < 0X168 ? 1 : 0;
    // 0x80400F54: bne         $at, $zero, L_80400F64
    if (ctx->r1 != 0) {
        // 0x80400F58: sw          $t8, 0x134($t0)
        MEM_W(0X134, ctx->r8) = ctx->r24;
            goto L_80400F64;
    }
    // 0x80400F58: sw          $t8, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r24;
    // 0x80400F5C: addiu       $t9, $t8, -0x168
    ctx->r25 = ADD32(ctx->r24, -0X168);
    // 0x80400F60: sw          $t9, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r25;
L_80400F64:
    // 0x80400F64: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80400F68: sw          $v1, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r3;
    // 0x80400F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80400F70: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80400F74: jr          $ra
    // 0x80400F78: nop

    return;
    // 0x80400F78: nop

;}
RECOMP_FUNC void func_8043F07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F07C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F084: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043F088: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8043F08C: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X3DE0) << 16);
    // 0x8043F090: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043F094: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043F098: lw          $t8, 0x2CE0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(95, 0X3DE0));
    // 0x8043F09C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043F0A0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043F0A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8043F0A8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8043F0AC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8043F0B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043F0B4: beql        $v1, $zero, L_8043F0E8
    if (ctx->r3 == 0) {
        // 0x8043F0B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F0E8;
    }
    goto skip_0;
    // 0x8043F0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043F0BC: jalr        $v1
    // 0x8043F0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8043F0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043F0C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043F0C8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8043F0CC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8043F0D0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8043F0D4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8043F0D8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8043F0DC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8043F0E0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8043F0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043F0E8:
    // 0x8043F0E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F0EC: jr          $ra
    // 0x8043F0F0: nop

    return;
    // 0x8043F0F0: nop

;}
RECOMP_FUNC void func_800590A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800590A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800590A8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800590AC: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x800590B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800590B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800590B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800590BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800590C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800590C4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800590C8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800590CC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800590D0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800590D4: jal         0x80081C64
    // 0x800590D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x800590D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800590DC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800590E0: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x800590E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800590E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800590EC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800590F0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800590F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800590F8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800590FC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80059100: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80059104: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80059108: lwc1        $f10, 0xB94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB94);
    // 0x8005910C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059110: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059114: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059118: mul.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005911C: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80059120: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80059124: jal         0x80081C64
    // 0x80059128: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80059128: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8005912C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80059130: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80059134: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005913C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80059140: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80059144: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80059148: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005914C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80059150: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059154: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80059158: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005915C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80059160: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80059164: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80059168: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005916C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x80059170: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80059174: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80059178: add.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8005917C: mul.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80059180: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80059184: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x80059188: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x8005918C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80059190: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x80059194: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80059198: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005919C: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800591A0: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800591A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800591A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800591AC: jr          $ra
    // 0x800591B0: nop

    return;
    // 0x800591B0: nop

;}
RECOMP_FUNC void func_80059FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059FD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059FE0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80059FE4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80059FE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80059FEC: bne         $t6, $at, L_80059FFC
    if (ctx->r14 != ctx->r1) {
        // 0x80059FF0: lui         $a3, 0x7F7F
        ctx->r7 = S32(0X7F7F << 16);
            goto L_80059FFC;
    }
    // 0x80059FF0: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x80059FF4: b           L_8005A05C
    // 0x80059FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A05C;
    // 0x80059FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059FFC:
    // 0x80059FFC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005A000: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005A004: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005A008: jal         0x8004613C
    // 0x8005A00C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8005A00C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    after_0:
    // 0x8005A010: bne         $v0, $zero, L_8005A020
    if (ctx->r2 != 0) {
        // 0x8005A014: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005A020;
    }
    // 0x8005A014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005A018: b           L_8005A05C
    // 0x8005A01C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A05C;
    // 0x8005A01C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A020:
    // 0x8005A020: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8005A024: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005A028: bne         $t7, $zero, L_8005A048
    if (ctx->r15 != 0) {
        // 0x8005A02C: nop
    
            goto L_8005A048;
    }
    // 0x8005A02C: nop

    // 0x8005A030: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005A034: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8005A038: jal         0x80071380
    // 0x8005A03C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005A03C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    after_1:
    // 0x8005A040: b           L_8005A05C
    // 0x8005A044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A05C;
    // 0x8005A044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A048:
    // 0x8005A048: jal         0x80048E9C
    // 0x8005A04C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048E9C(rdram, ctx);
        goto after_2;
    // 0x8005A04C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8005A050: jal         0x80044194
    // 0x8005A054: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x8005A054: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8005A058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A05C:
    // 0x8005A05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A068: jr          $ra
    // 0x8005A06C: nop

    return;
    // 0x8005A06C: nop

;}
RECOMP_FUNC void func_80026A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A4C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80026A50: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80026A54: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80026A58: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80026A5C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80026A60: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80026A64: bnel        $at, $zero, L_80026AA8
    if (ctx->r1 != 0) {
        // 0x80026A68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80026AA8;
    }
    goto skip_0;
    // 0x80026A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80026A6C: lbu         $t0, 0x158($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X158);
    // 0x80026A70: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80026A74: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80026A78: sb          $t1, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r9;
    // 0x80026A7C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80026A80: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80026A84: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x80026A88: bnel        $at, $zero, L_80026A9C
    if (ctx->r1 != 0) {
        // 0x80026A8C: lw          $t4, 0x14C($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X14C);
            goto L_80026A9C;
    }
    goto skip_1;
    // 0x80026A8C: lw          $t4, 0x14C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14C);
    skip_1:
    // 0x80026A90: jr          $ra
    // 0x80026A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80026A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026A98: lw          $t4, 0x14C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14C);
L_80026A9C:
    // 0x80026A9C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80026AA0: sw          $t5, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r13;
    // 0x80026AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026AA8:
    // 0x80026AA8: jr          $ra
    // 0x80026AAC: nop

    return;
    // 0x80026AAC: nop

;}
RECOMP_FUNC void func_80038480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038488: jal         0x80021958
    // 0x8003848C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003848C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038490: bne         $v0, $zero, L_800384A0
    if (ctx->r2 != 0) {
        // 0x80038494: nop
    
            goto L_800384A0;
    }
    // 0x80038494: nop

    // 0x80038498: b           L_800384D4
    // 0x8003849C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800384D4;
    // 0x8003849C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800384A0:
    // 0x800384A0: jal         0x800415FC
    // 0x800384A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800384A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800384A8: beq         $v0, $zero, L_800384B8
    if (ctx->r2 == 0) {
        // 0x800384AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800384B8;
    }
    // 0x800384AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800384B0: b           L_800384D4
    // 0x800384B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800384D4;
    // 0x800384B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800384B8:
    // 0x800384B8: jal         0x8003790C
    // 0x800384BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8003790C(rdram, ctx);
        goto after_2;
    // 0x800384BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x800384C0: bnel        $v0, $zero, L_800384D4
    if (ctx->r2 != 0) {
        // 0x800384C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800384D4;
    }
    goto skip_0;
    // 0x800384C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800384C8: b           L_800384D4
    // 0x800384CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800384D4;
    // 0x800384CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800384D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800384D4:
    // 0x800384D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800384D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800384DC: jr          $ra
    // 0x800384E0: nop

    return;
    // 0x800384E0: nop

;}
RECOMP_FUNC void eepmgr_Probe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CDFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CE00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CE04: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007CE08: jal         0x8007CDA0
    // 0x8007CE0C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8007CDA0(rdram, ctx);
        goto after_0;
    // 0x8007CE0C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8007CE10: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007CE14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CE18: jal         0x8008B920
    // 0x8007CE1C: sb          $t6, 0x225($t7)
    MEM_B(0X225, ctx->r15) = ctx->r14;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CE1C: sb          $t6, 0x225($t7)
    MEM_B(0X225, ctx->r15) = ctx->r14;
    after_1:
    // 0x8007CE20: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8007CE24: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8007CE28: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007CE2C: jal         0x80089130
    // 0x8007CE30: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    osEepromProbe_recomp(rdram, ctx);
        goto after_2;
    // 0x8007CE30: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    after_2:
    // 0x8007CE34: jal         0x8008B920
    // 0x8007CE38: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x8007CE38: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8007CE3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007CE40: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8007CE44: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8007CE48: jal         0x8007CDCC
    // 0x8007CE4C: sb          $zero, 0x225($a0)
    MEM_B(0X225, ctx->r4) = 0;
    func_8007CDCC(rdram, ctx);
        goto after_4;
    // 0x8007CE4C: sb          $zero, 0x225($a0)
    MEM_B(0X225, ctx->r4) = 0;
    after_4:
    // 0x8007CE50: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007CE54: lw          $a0, -0x65E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X65E0);
    // 0x8007CE58: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007CE5C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CE60: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8007CE64: bne         $at, $zero, L_8007CECC
    if (ctx->r1 != 0) {
        // 0x8007CE68: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_8007CECC;
    }
    // 0x8007CE68: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007CE6C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8007CE70: subu        $a0, $t0, $t2
    ctx->r4 = SUB32(ctx->r8, ctx->r10);
    // 0x8007CE74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007CE78: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x8007CE7C: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x8007CE80: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8007CE84: jal         0x80082D88
    // 0x8007CE88: subu        $a1, $t1, $t3
    ctx->r5 = SUB32(ctx->r9, ctx->r11);
    __ll_mul_recomp(rdram, ctx);
        goto after_5;
    // 0x8007CE88: subu        $a1, $t1, $t3
    ctx->r5 = SUB32(ctx->r9, ctx->r11);
    after_5:
    // 0x8007CE8C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007CE90: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8007CE94: lw          $a1, -0x53BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X53BC);
    // 0x8007CE98: lw          $a0, -0x53C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53C0);
    // 0x8007CE9C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007CEA0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8007CEA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007CEA8: jal         0x80082C88
    // 0x8007CEAC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_6;
    // 0x8007CEAC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_6:
    // 0x8007CEB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007CEB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CEB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007CEBC: jal         0x80082C88
    // 0x8007CEC0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x8007CEC0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_7:
    // 0x8007CEC4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007CEC8: lw          $a0, -0x65E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X65E0);
L_8007CECC:
    // 0x8007CECC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007CED4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8007CED8: bne         $v0, $zero, L_8007CEF0
    if (ctx->r2 != 0) {
        // 0x8007CEDC: nop
    
            goto L_8007CEF0;
    }
    // 0x8007CEDC: nop

    // 0x8007CEE0: beql        $a0, $zero, L_8007CF30
    if (ctx->r4 == 0) {
        // 0x8007CEE4: lbu         $t4, 0x21C($t9)
        ctx->r12 = MEM_BU(ctx->r25, 0X21C);
            goto L_8007CF30;
    }
    goto skip_0;
    // 0x8007CEE4: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
    skip_0:
    // 0x8007CEE8: b           L_8007CF30
    // 0x8007CEEC: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
        goto L_8007CF30;
    // 0x8007CEEC: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
L_8007CEF0:
    // 0x8007CEF0: bnel        $v0, $at, L_8007CF0C
    if (ctx->r2 != ctx->r1) {
        // 0x8007CEF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007CF0C;
    }
    goto skip_1;
    // 0x8007CEF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8007CEF8: beql        $a0, $zero, L_8007CF30
    if (ctx->r4 == 0) {
        // 0x8007CEFC: lbu         $t4, 0x21C($t9)
        ctx->r12 = MEM_BU(ctx->r25, 0X21C);
            goto L_8007CF30;
    }
    goto skip_2;
    // 0x8007CEFC: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
    skip_2:
    // 0x8007CF00: b           L_8007CF30
    // 0x8007CF04: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
        goto L_8007CF30;
    // 0x8007CF04: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
    // 0x8007CF08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8007CF0C:
    // 0x8007CF0C: bne         $v0, $at, L_8007CF24
    if (ctx->r2 != ctx->r1) {
        // 0x8007CF10: nop
    
            goto L_8007CF24;
    }
    // 0x8007CF10: nop

    // 0x8007CF14: beql        $a0, $zero, L_8007CF30
    if (ctx->r4 == 0) {
        // 0x8007CF18: lbu         $t4, 0x21C($t9)
        ctx->r12 = MEM_BU(ctx->r25, 0X21C);
            goto L_8007CF30;
    }
    goto skip_3;
    // 0x8007CF18: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
    skip_3:
    // 0x8007CF1C: b           L_8007CF30
    // 0x8007CF20: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
        goto L_8007CF30;
    // 0x8007CF20: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
L_8007CF24:
    // 0x8007CF24: b           L_8007CF24
    pause_self(rdram);
    // 0x8007CF28: nop

    // 0x8007CF2C: lbu         $t4, 0x21C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21C);
L_8007CF30:
    // 0x8007CF30: beql        $v0, $t4, L_8007CF44
    if (ctx->r2 == ctx->r12) {
        // 0x8007CF34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007CF44;
    }
    goto skip_4;
    // 0x8007CF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
L_8007CF38:
    // 0x8007CF38: b           L_8007CF38
    pause_self(rdram);
    // 0x8007CF3C: nop

    // 0x8007CF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007CF44:
    // 0x8007CF44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8007CF48: jr          $ra
    // 0x8007CF4C: nop

    return;
    // 0x8007CF4C: nop

;}
RECOMP_FUNC void func_80568F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568F50: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568F60: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80568F64: jal         0x80568710
    // 0x80568F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568F70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80568F74: jal         0x8005FE48
    // 0x80568F78: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x80568F78: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x80568F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568F80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80568F84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80568F88: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    // 0x80568F8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568F90: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568F94: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80568F98: ori         $t9, $t8, 0x18
    ctx->r25 = ctx->r24 | 0X18;
    // 0x80568F9C: sb          $t9, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r25;
    // 0x80568FA0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568FA4: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568FA8: jal         0x80569310
    // 0x80568FAC: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568FAC: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x80568FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568FB8: jr          $ra
    // 0x80568FBC: nop

    return;
    // 0x80568FBC: nop

;}
RECOMP_FUNC void func_806EC234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC23C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x806EC240: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x806EC244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EC248: jal         0x8004590C
    // 0x806EC24C: addiu       $a1, $v0, 0xA00
    ctx->r5 = ADD32(ctx->r2, 0XA00);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x806EC24C: addiu       $a1, $v0, 0xA00
    ctx->r5 = ADD32(ctx->r2, 0XA00);
    after_0:
    // 0x806EC250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EC254: addiu       $t9, $zero, 0x55
    ctx->r25 = ADD32(0, 0X55);
    // 0x806EC258: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x806EC25C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806EC260: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806EC264: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    // 0x806EC268: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x806EC26C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806EC270: sh          $t9, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = ctx->r25;
    // 0x806EC274: sw          $t2, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r10;
    // 0x806EC278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC27C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC280: jr          $ra
    // 0x806EC284: nop

    return;
    // 0x806EC284: nop

;}
RECOMP_FUNC void func_804491F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804491F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804491F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804491F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804491FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449204: bne         $a2, $zero, L_80449234
    if (ctx->r6 != 0) {
        // 0x80449208: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449234;
    }
    // 0x80449208: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044920C: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80449210: lw          $v1, 0x110($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X110);
    // 0x80449214: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80449218: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044921C: bne         $at, $zero, L_80449274
    if (ctx->r1 != 0) {
        // 0x80449220: sw          $t7, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r15;
            goto L_80449274;
    }
    // 0x80449220: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x80449224: jal         0x80446938
    // 0x80449228: nop

    func_80446938(rdram, ctx);
        goto after_0;
    // 0x80449228: nop

    after_0:
    // 0x8044922C: b           L_80449278
    // 0x80449230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449278;
    // 0x80449230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449234:
    // 0x80449234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449238: bnel        $a2, $at, L_80449264
    if (ctx->r6 != ctx->r1) {
        // 0x8044923C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449264;
    }
    goto skip_0;
    // 0x8044923C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449240: jal         0x804468D4
    // 0x80449244: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_1;
    // 0x80449244: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449248: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044924C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449250: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80449254: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449258: b           L_80449274
    // 0x8044925C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449274;
    // 0x8044925C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80449260: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449264:
    // 0x80449264: bnel        $a2, $at, L_80449278
    if (ctx->r6 != ctx->r1) {
        // 0x80449268: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449278;
    }
    goto skip_1;
    // 0x80449268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044926C: jal         0x80446938
    // 0x80449270: nop

    func_80446938(rdram, ctx);
        goto after_2;
    // 0x80449270: nop

    after_2:
L_80449274:
    // 0x80449274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449278:
    // 0x80449278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044927C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449280: jr          $ra
    // 0x80449284: nop

    return;
    // 0x80449284: nop

;}
RECOMP_FUNC void func_805C6BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6BC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C6BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805C6BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C6BD0: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x805C6BD4: nop

    // 0x805C6BD8: bc1fl       L_805C6BEC
    if (!c1cs) {
        // 0x805C6BDC: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_805C6BEC;
    }
    goto skip_0;
    // 0x805C6BDC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x805C6BE0: b           L_805C6C10
    // 0x805C6BE4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_805C6C10;
    // 0x805C6BE4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x805C6BE8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_805C6BEC:
    // 0x805C6BEC: jal         0x80065414
    // 0x805C6BF0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x805C6BF0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x805C6BF4: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x805C6BF8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805C6BFC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805C6C00: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x805C6C04: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x805C6C08: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x805C6C0C: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_805C6C10:
    // 0x805C6C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C6C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805C6C18: jr          $ra
    // 0x805C6C1C: nop

    return;
    // 0x805C6C1C: nop

;}
RECOMP_FUNC void func_8064EB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EB70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064EB74: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8064EB78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064EB7C: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D30) << 16);
    // 0x8064EB80: lwc1        $f6, 0x4730($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D30));
    // 0x8064EB84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064EB88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064EB8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064EB90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064EB94: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064EB98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EB9C: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x8064EBA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EBA4: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x8064EBA8: addiu       $a3, $zero, 0x1E00
    ctx->r7 = ADD32(0, 0X1E00);
    // 0x8064EBAC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064EBB0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8064EBB4: jal         0x8064EA0C
    // 0x8064EBB8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064EBB8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8064EBBC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8064EBC0: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D34) << 16);
    // 0x8064EBC4: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x8064EBC8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8064EBCC: lwc1        $f8, 0x4734($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D34));
    // 0x8064EBD0: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D38) << 16);
    // 0x8064EBD4: lwc1        $f10, 0x4738($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D38));
    // 0x8064EBD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8064EBDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8064EBE0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064EBE4: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x8064EBE8: addiu       $a3, $zero, 0x1E00
    ctx->r7 = ADD32(0, 0X1E00);
    // 0x8064EBEC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8064EBF0: jal         0x8064EA0C
    // 0x8064EBF4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_1;
    // 0x8064EBF4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8064EBF8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EBFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EC00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8064EC04: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EC08: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8064EC0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064EC10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064EC14: jr          $ra
    // 0x8064EC18: nop

    return;
    // 0x8064EC18: nop

;}
RECOMP_FUNC void func_8006A3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A3E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A3EC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8006A3F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006A3F4: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8006A3F8: bne         $v0, $zero, L_8006A408
    if (ctx->r2 != 0) {
        // 0x8006A3FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006A408;
    }
    // 0x8006A3FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8006A400: b           L_8006A498
    // 0x8006A404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A498;
    // 0x8006A404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A408:
    // 0x8006A408: beql        $v0, $zero, L_8006A43C
    if (ctx->r2 == 0) {
        // 0x8006A40C: lw          $a0, 0x14($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X14);
            goto L_8006A43C;
    }
    goto skip_0;
    // 0x8006A40C: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
    skip_0:
    // 0x8006A410: lw          $t7, 0x14($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X14);
    // 0x8006A414: bnel        $t7, $zero, L_8006A43C
    if (ctx->r15 != 0) {
        // 0x8006A418: lw          $a0, 0x14($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X14);
            goto L_8006A43C;
    }
    goto skip_1;
    // 0x8006A418: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
    skip_1:
    // 0x8006A41C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8006A420: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8006A424: jal         0x80064DD0
    // 0x8006A428: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8006A428: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8006A42C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006A430: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A434: sw          $v0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r2;
    // 0x8006A438: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
L_8006A43C:
    // 0x8006A43C: addiu       $a1, $zero, 0x1ED
    ctx->r5 = ADD32(0, 0X1ED);
    // 0x8006A440: bnel        $a0, $zero, L_8006A460
    if (ctx->r4 != 0) {
        // 0x8006A444: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_8006A460;
    }
    goto skip_2;
    // 0x8006A444: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x8006A448: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A44C: jal         0x80071380
    // 0x8006A450: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006A450: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    after_1:
    // 0x8006A454: b           L_8006A498
    // 0x8006A458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A498;
    // 0x8006A458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006A45C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_8006A460:
    // 0x8006A460: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8006A464: jal         0x80050994
    // 0x8006A468: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80050994(rdram, ctx);
        goto after_2;
    // 0x8006A468: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8006A46C: bne         $v0, $zero, L_8006A494
    if (ctx->r2 != 0) {
        // 0x8006A470: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8006A494;
    }
    // 0x8006A470: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006A474: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
    // 0x8006A478: jal         0x80064E84
    // 0x8006A47C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x8006A47C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x8006A480: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006A484: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8006A488: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8006A48C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8006A490: sw          $t0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r8;
L_8006A494:
    // 0x8006A494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A498:
    // 0x8006A498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A49C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A4A0: jr          $ra
    // 0x8006A4A4: nop

    return;
    // 0x8006A4A4: nop

;}
RECOMP_FUNC void func_807B914C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B914C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9154: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807B9158: addiu       $a0, $a0, -0x6DB8
    ctx->r4 = ADD32(ctx->r4, -0X6DB8);
    // 0x807B915C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x807B9160: jal         0x80065728
    // 0x807B9164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807B9164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x807B9168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B916C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9170: jr          $ra
    // 0x807B9174: nop

    return;
    // 0x807B9174: nop

;}
RECOMP_FUNC void func_8064BF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BF74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BF78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064BF7C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064BF80: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064BF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BF88: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064BF8C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8064BF90: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064BF94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064BF98: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8064BF9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064BFA0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064BFA4: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X3244) << 16);
    // 0x8064BFA8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064BFAC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064BFB0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064BFB4: lw          $t2, -0x2CEC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X3244));
    // 0x8064BFB8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064BFBC: jal         0x8064BD3C
    // 0x8064BFC0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064BD3C(rdram, ctx);
        goto after_0;
    // 0x8064BFC0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064BFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064BFC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BFCC: jr          $ra
    // 0x8064BFD0: nop

    return;
    // 0x8064BFD0: nop

;}
RECOMP_FUNC void func_80446A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446A8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446A90: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446A94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446A98: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446A9C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80446AA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446AA4: jr          $ra
    // 0x80446AA8: sw          $t7, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r15;
    return;
    // 0x80446AA8: sw          $t7, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80679F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80679F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80679F48: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80679F4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80679F50: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679F54: beq         $a1, $at, L_80679F70
    if (ctx->r5 == ctx->r1) {
        // 0x80679F58: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_80679F70;
    }
    // 0x80679F58: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80679F5C: jal         0x80067878
    // 0x80679F60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80679F60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80679F64: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80679F68: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80679F6C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80679F70:
    // 0x80679F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80679F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80679F78: jr          $ra
    // 0x80679F7C: nop

    return;
    // 0x80679F7C: nop

;}
RECOMP_FUNC void func_8004EC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EC10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004EC14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004EC18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004EC1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004EC20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004EC24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004EC28: addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // 0x8004EC2C: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8004EC30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004EC34: jal         0x80047AB8
    // 0x8004EC38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004EC38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8004EC3C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8004EC40: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8004EC44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004EC48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004EC4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004EC50: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8004EC54: jal         0x8004E124
    // 0x8004EC58: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    func_8004E124(rdram, ctx);
        goto after_1;
    // 0x8004EC58: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    after_1:
    // 0x8004EC5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004EC60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004EC64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004EC68: jal         0x8004E1E8
    // 0x8004EC6C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E1E8(rdram, ctx);
        goto after_2;
    // 0x8004EC6C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x8004EC70: jal         0x80049018
    // 0x8004EC74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049018(rdram, ctx);
        goto after_3;
    // 0x8004EC74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8004EC78: beq         $v0, $zero, L_8004ECBC
    if (ctx->r2 == 0) {
        // 0x8004EC7C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004ECBC;
    }
    // 0x8004EC7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004EC80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004EC84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004EC88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8004EC8C: jal         0x8004E344
    // 0x8004EC90: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E344(rdram, ctx);
        goto after_4;
    // 0x8004EC90: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_4:
    // 0x8004EC94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004EC98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004EC9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004ECA0: jal         0x8004E3B8
    // 0x8004ECA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E3B8(rdram, ctx);
        goto after_5;
    // 0x8004ECA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_5:
    // 0x8004ECA8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004ECAC: sll         $t8, $t7, 28
    ctx->r24 = S32(ctx->r15 << 28);
    // 0x8004ECB0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8004ECB4: b           L_8004ECF4
    // 0x8004ECB8: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
        goto L_8004ECF4;
    // 0x8004ECB8: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
L_8004ECBC:
    // 0x8004ECBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004ECC0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004ECC4: jal         0x8004E2AC
    // 0x8004ECC8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E2AC(rdram, ctx);
        goto after_6;
    // 0x8004ECC8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x8004ECCC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8004ECD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004ECD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004ECD8: andi        $t0, $v0, 0xF0
    ctx->r8 = ctx->r2 & 0XF0;
    // 0x8004ECDC: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x8004ECE0: or          $t2, $v0, $t1
    ctx->r10 = ctx->r2 | ctx->r9;
    // 0x8004ECE4: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x8004ECE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8004ECEC: jal         0x8004E450
    // 0x8004ECF0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E450(rdram, ctx);
        goto after_7;
    // 0x8004ECF0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
L_8004ECF4:
    // 0x8004ECF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004ECF8: jal         0x8004E57C
    // 0x8004ECFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E57C(rdram, ctx);
        goto after_8;
    // 0x8004ECFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8004ED00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004ED04: jal         0x8004E95C
    // 0x8004ED08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E95C(rdram, ctx);
        goto after_9;
    // 0x8004ED08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8004ED0C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8004ED10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004ED14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004ED18: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x8004ED1C: jal         0x8004AB60
    // 0x8004ED20: lhu         $a2, 0x60($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X60);
    func_8004AB60(rdram, ctx);
        goto after_10;
    // 0x8004ED20: lhu         $a2, 0x60($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X60);
    after_10:
    // 0x8004ED24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004ED28: jal         0x8004E658
    // 0x8004ED2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E658(rdram, ctx);
        goto after_11;
    // 0x8004ED2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8004ED30: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004ED34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004ED38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004ED3C: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8004ED40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004ED44: jal         0x8004A9C4
    // 0x8004ED48: lhu         $a2, 0x18($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X18);
    func_8004A9C4(rdram, ctx);
        goto after_12;
    // 0x8004ED48: lhu         $a2, 0x18($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X18);
    after_12:
    // 0x8004ED4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004ED50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004ED54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004ED58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004ED5C: jr          $ra
    // 0x8004ED60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004ED60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004ED64: nop

    // 0x8004ED68: nop

    // 0x8004ED6C: nop

;}
RECOMP_FUNC void func_806F16CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F16CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F16D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F16D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F16D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F16DC: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F16E0: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F16E4: jal         0x80065ABC
    // 0x806F16E8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F16E8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x806F16EC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806F16F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F16F4: jal         0x80049D74
    // 0x806F16F8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x806F16F8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_1:
    // 0x806F16FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806F1700: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806F1704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F170C: jal         0x8004D150
    // 0x806F1710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x806F1710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x806F1714: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806F1718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F171C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F1720: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F1724: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806F1728: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806F172C: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x806F1730: beql        $t9, $zero, L_806F1744
    if (ctx->r25 == 0) {
        // 0x806F1734: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1744;
    }
    goto skip_0;
    // 0x806F1734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F1738: jal         0x8004D618
    // 0x806F173C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_3;
    // 0x806F173C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_3:
    // 0x806F1740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1744:
    // 0x806F1744: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F174C: jr          $ra
    // 0x806F1750: nop

    return;
    // 0x806F1750: nop

;}
RECOMP_FUNC void func_8069D0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D0E8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8069D0EC: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8069D0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D0F8: beq         $t6, $zero, L_8069D11C
    if (ctx->r14 == 0) {
        // 0x8069D0FC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8069D11C;
    }
    // 0x8069D0FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069D100: jal         0x8069CD84
    // 0x8069D104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069CD84(rdram, ctx);
        goto after_0;
    // 0x8069D104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D10C: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X3A0) << 16);
    // 0x8069D110: addiu       $t7, $t7, -0x2F70
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X3A0));
    // 0x8069D114: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D118: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_8069D11C:
    // 0x8069D11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D124: jr          $ra
    // 0x8069D128: nop

    return;
    // 0x8069D128: nop

;}
RECOMP_FUNC void func_8042227C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042227C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80422280: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(32, 0X7A4) << 16);
    // 0x80422284: addiu       $t6, $t6, 0x1864
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(32, 0X7A4));
    // 0x80422288: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042228C: jr          $ra
    // 0x80422290: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80422290: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804EF754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF75C: jal         0x804EF6D8
    // 0x804EF760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF6D8(rdram, ctx);
        goto after_0;
    // 0x804EF760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF764: jal         0x804EF67C
    // 0x804EF768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804EF67C(rdram, ctx);
        goto after_1;
    // 0x804EF768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804EF76C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF770: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X10C8) << 16);
    // 0x804EF774: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x804EF778: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    // 0x804EF77C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EF780: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804EF784: lwc1        $f0, -0x1A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X10C8));
    // 0x804EF788: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x804EF78C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x804EF790: lbu         $t9, 0x165($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X165);
    // 0x804EF794: jal         0x804EF6FC
    // 0x804EF798: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    func_804EF6FC(rdram, ctx);
        goto after_2;
    // 0x804EF798: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    after_2:
    // 0x804EF79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF7A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF7A4: jr          $ra
    // 0x804EF7A8: nop

    return;
    // 0x804EF7A8: nop

;}
RECOMP_FUNC void func_8070C8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070C8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C8C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8070C8CC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8070C8D0: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8070C8D4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8070C8D8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8070C8DC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8070C8E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070C8E4: jal         0x8070C8FC
    // 0x8070C8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8070C8FC(rdram, ctx);
        goto after_0;
    // 0x8070C8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8070C8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070C8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070C8F4: jr          $ra
    // 0x8070C8F8: nop

    return;
    // 0x8070C8F8: nop

;}
RECOMP_FUNC void func_8002F678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F678: lbu         $t6, 0x18($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X18);
    // 0x8002F67C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002F680: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x8002F684: bne         $t6, $at, L_8002F694
    if (ctx->r14 != ctx->r1) {
        // 0x8002F688: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002F694;
    }
    // 0x8002F688: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002F68C: jr          $ra
    // 0x8002F690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002F690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002F694:
    // 0x8002F694: bnel        $v0, $v1, L_8002F6B0
    if (ctx->r2 != ctx->r3) {
        // 0x8002F698: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8002F6B0;
    }
    goto skip_0;
    // 0x8002F698: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_0:
    // 0x8002F69C: bnel        $a1, $v1, L_8002F6B0
    if (ctx->r5 != ctx->r3) {
        // 0x8002F6A0: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8002F6B0;
    }
    goto skip_1;
    // 0x8002F6A0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_1:
    // 0x8002F6A4: jr          $ra
    // 0x8002F6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002F6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002F6AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8002F6B0:
    // 0x8002F6B0: bne         $v0, $v1, L_8002F6C8
    if (ctx->r2 != ctx->r3) {
        // 0x8002F6B4: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002F6C8;
    }
    // 0x8002F6B4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F6B8: bne         $a1, $v1, L_8002F6C8
    if (ctx->r5 != ctx->r3) {
        // 0x8002F6BC: nop
    
            goto L_8002F6C8;
    }
    // 0x8002F6BC: nop

    // 0x8002F6C0: jr          $ra
    // 0x8002F6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002F6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002F6C8:
    // 0x8002F6C8: beq         $at, $zero, L_8002F6D8
    if (ctx->r1 == 0) {
        // 0x8002F6CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002F6D8;
    }
    // 0x8002F6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F6D0: jr          $ra
    // 0x8002F6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002F6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002F6D8:
    // 0x8002F6D8: sw          $a1, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r5;
    // 0x8002F6DC: jr          $ra
    // 0x8002F6E0: nop

    return;
    // 0x8002F6E0: nop

;}
RECOMP_FUNC void func_8067C020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067C020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067C024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067C028: lhu         $a3, 0xC($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0XC);
    // 0x8067C02C: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(541, 0X1E48) << 16);
    // 0x8067C030: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8067C034: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8067C038: addiu       $a1, $a1, -0x4508
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(541, 0X1E48));
    // 0x8067C03C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067C040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067C044: jal         0x8067BF84
    // 0x8067C048: addiu       $a3, $a3, -0x40D7
    ctx->r7 = ADD32(ctx->r7, -0X40D7);
    func_8067BF84(rdram, ctx);
        goto after_0;
    // 0x8067C048: addiu       $a3, $a3, -0x40D7
    ctx->r7 = ADD32(ctx->r7, -0X40D7);
    after_0:
    // 0x8067C04C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C050: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(541, 0X225C) << 16);
    // 0x8067C054: addiu       $t7, $t7, -0x40F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(541, 0X225C));
    // 0x8067C058: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8067C05C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8067C060: sh          $t8, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r24;
    // 0x8067C064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067C068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067C06C: jr          $ra
    // 0x8067C070: nop

    return;
    // 0x8067C070: nop

;}
RECOMP_FUNC void func_80531FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80531FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80531FE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80531FE8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80531FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80531FF0: jal         0x80530E78
    // 0x80531FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80530E78(rdram, ctx);
        goto after_0;
    // 0x80531FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80531FF8: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    // 0x80531FFC: beql        $v0, $zero, L_80532058
    if (ctx->r2 == 0) {
        // 0x80532000: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80532058;
    }
    goto skip_0;
    // 0x80532000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80532004: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80532008: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8053200C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80532010: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80532014: lwc1        $f4, 0x268($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X268);
    // 0x80532018: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8053201C: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80532020: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80532024: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80532028: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8053202C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80532030: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80532034: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80532038: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8053203C: jal         0x80531924
    // 0x80532040: nop

    func_80531924(rdram, ctx);
        goto after_1;
    // 0x80532040: nop

    after_1:
    // 0x80532044: beq         $v0, $zero, L_80532054
    if (ctx->r2 == 0) {
        // 0x80532048: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80532054;
    }
    // 0x80532048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8053204C: jal         0x805323E8
    // 0x80532050: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805323E8(rdram, ctx);
        goto after_2;
    // 0x80532050: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_80532054:
    // 0x80532054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80532058:
    // 0x80532058: jal         0x8005D87C
    // 0x8053205C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_3;
    // 0x8053205C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80532060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80532064: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80532068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8053206C: jr          $ra
    // 0x80532070: nop

    return;
    // 0x80532070: nop

;}
RECOMP_FUNC void func_806CEB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEB14: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806CEB18: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(604, 0X3338) << 16);
    // 0x806CEB1C: addiu       $t6, $t6, -0x15A8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(604, 0X3338));
    // 0x806CEB20: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806CEB24: jr          $ra
    // 0x806CEB28: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806CEB28: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8006F2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F2B4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8006F2B8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8006F2BC: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8006F2C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006F2C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006F2C8: lw          $t8, 0x7F5C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F5C);
    // 0x8006F2CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006F2D0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006F2D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006F2D8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F2DC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8006F2E0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8006F2E4: beql        $v1, $zero, L_8006F318
    if (ctx->r3 == 0) {
        // 0x8006F2E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F318;
    }
    goto skip_0;
    // 0x8006F2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006F2EC: jalr        $v1
    // 0x8006F2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8006F2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F2F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F2F8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8006F2FC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8006F300: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8006F304: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006F308: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006F30C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8006F310: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8006F314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F318:
    // 0x8006F318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F31C: jr          $ra
    // 0x8006F320: nop

    return;
    // 0x8006F320: nop

;}
RECOMP_FUNC void func_8040E8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E8D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E8D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040E8DC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8040E8E0: jal         0x80067BBC
    // 0x8040E8E4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040E8E4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8040E8E8: addiu       $a0, $zero, 0x288
    ctx->r4 = ADD32(0, 0X288);
    // 0x8040E8EC: jal         0x80067818
    // 0x8040E8F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8040E8F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8040E8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040E8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E8FC: jr          $ra
    // 0x8040E900: nop

    return;
    // 0x8040E900: nop

;}
RECOMP_FUNC void func_8057A2B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A2B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057A2BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057A2C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8057A2C4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057A2C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057A2CC: lwc1        $f2, -0x7638($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7638);
    // 0x8057A2D0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057A2D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A2D8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8057A2DC: jal         0x8004700C
    // 0x8057A2E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8057A2E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8057A2E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A2E8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8057A2EC: beq         $v0, $zero, L_8057A378
    if (ctx->r2 == 0) {
        // 0x8057A2F0: lwc1        $f2, 0x1C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8057A378;
    }
    // 0x8057A2F0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A2F4: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8057A2F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8057A2FC: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x8057A300: beql        $a0, $zero, L_8057A31C
    if (ctx->r4 == 0) {
        // 0x8057A304: lw          $t7, 0x18($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X18);
            goto L_8057A31C;
    }
    goto skip_0;
    // 0x8057A304: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    skip_0:
    // 0x8057A308: beq         $a0, $at, L_8057A350
    if (ctx->r4 == ctx->r1) {
        // 0x8057A30C: nop
    
            goto L_8057A350;
    }
    // 0x8057A30C: nop

    // 0x8057A310: b           L_8057A350
    // 0x8057A314: nop

        goto L_8057A350;
    // 0x8057A314: nop

    // 0x8057A318: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
L_8057A31C:
    // 0x8057A31C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057A320: bnel        $t7, $zero, L_8057A378
    if (ctx->r15 != 0) {
        // 0x8057A324: swc1        $f0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
            goto L_8057A378;
    }
    goto skip_1;
    // 0x8057A324: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x8057A328: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057A32C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1AF8) << 16);
    // 0x8057A330: lwc1        $f4, -0x4AC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1AF8));
    // 0x8057A334: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8057A338: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8057A33C: nop

    // 0x8057A340: bc1fl       L_8057A378
    if (!c1cs) {
        // 0x8057A344: swc1        $f0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
            goto L_8057A378;
    }
    goto skip_2;
    // 0x8057A344: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    skip_2:
    // 0x8057A348: b           L_8057A374
    // 0x8057A34C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8057A374;
    // 0x8057A34C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8057A350:
    // 0x8057A350: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1AFC) << 16);
    // 0x8057A354: lwc1        $f6, -0x4AC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1AFC));
    // 0x8057A358: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8057A35C: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8057A360: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8057A364: nop

    // 0x8057A368: bc1fl       L_8057A378
    if (!c1cs) {
        // 0x8057A36C: swc1        $f0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
            goto L_8057A378;
    }
    goto skip_3;
    // 0x8057A36C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    skip_3:
    // 0x8057A370: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8057A374:
    // 0x8057A374: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
L_8057A378:
    // 0x8057A378: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057A37C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8057A380: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A384: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8057A388: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A38C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8057A390: jal         0x80579F18
    // 0x8057A394: nop

    func_80579F18(rdram, ctx);
        goto after_1;
    // 0x8057A394: nop

    after_1:
    // 0x8057A398: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8057A39C: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x8057A3A0: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8057A3A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A3A8: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x8057A3AC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A3B0: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x8057A3B4: bne         $t9, $at, L_8057A4E4
    if (ctx->r25 != ctx->r1) {
        // 0x8057A3B8: lui         $at, 0x8058
        ctx->r1 = S32(RELOC_HI16(384, 0X1B00) << 16);
            goto L_8057A4E4;
    }
    // 0x8057A3B8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B00) << 16);
    // 0x8057A3BC: lwc1        $f0, -0x4AC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B00));
    // 0x8057A3C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A3C4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8057A3C8: nop

    // 0x8057A3CC: bc1fl       L_8057A3F8
    if (!c1cs) {
        // 0x8057A3D0: lw          $t0, 0x48C($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X48C);
            goto L_8057A3F8;
    }
    goto skip_4;
    // 0x8057A3D0: lw          $t0, 0x48C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X48C);
    skip_4:
    // 0x8057A3D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A3D8: jal         0x80579C6C
    // 0x8057A3DC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C6C(rdram, ctx);
        goto after_2;
    // 0x8057A3DC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8057A3E0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B04) << 16);
    // 0x8057A3E4: lwc1        $f0, -0x4ABC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B04));
    // 0x8057A3E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A3EC: b           L_8057A444
    // 0x8057A3F0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
        goto L_8057A444;
    // 0x8057A3F0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A3F4: lw          $t0, 0x48C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X48C);
L_8057A3F8:
    // 0x8057A3F8: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8057A3FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A400: beql        $t0, $at, L_8057A428
    if (ctx->r8 == ctx->r1) {
        // 0x8057A404: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8057A428;
    }
    goto skip_5;
    // 0x8057A404: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_5:
    // 0x8057A408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A40C: jal         0x80579C6C
    // 0x8057A410: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C6C(rdram, ctx);
        goto after_3;
    // 0x8057A410: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8057A414: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A418: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A41C: addiu       $t1, $zero, 0x65
    ctx->r9 = ADD32(0, 0X65);
    // 0x8057A420: sw          $t1, 0x48C($a1)
    MEM_W(0X48C, ctx->r5) = ctx->r9;
    // 0x8057A424: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8057A428:
    // 0x8057A428: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A42C: jal         0x80579C18
    // 0x8057A430: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C18(rdram, ctx);
        goto after_4;
    // 0x8057A430: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8057A434: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B0C) << 16);
    // 0x8057A438: lwc1        $f0, -0x4AB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B0C));
    // 0x8057A43C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A440: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
L_8057A444:
    // 0x8057A444: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057A448: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057A44C: sw          $zero, 0x488($a1)
    MEM_W(0X488, ctx->r5) = 0;
    // 0x8057A450: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8057A454: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8057A458: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8057A45C: lhu         $v0, 0xC($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XC);
    // 0x8057A460: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x8057A464: bnel        $t3, $at, L_8057A4A4
    if (ctx->r11 != ctx->r1) {
        // 0x8057A468: lw          $t6, 0x484($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X484);
            goto L_8057A4A4;
    }
    goto skip_6;
    // 0x8057A468: lw          $t6, 0x484($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X484);
    skip_6:
    // 0x8057A46C: sw          $t4, 0x484($a1)
    MEM_W(0X484, ctx->r5) = ctx->r12;
    // 0x8057A470: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B10) << 16);
    // 0x8057A474: lwc1        $f16, -0x4AB0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B10));
    // 0x8057A478: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8057A47C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8057A480: nop

    // 0x8057A484: bc1fl       L_8057A494
    if (!c1cs) {
        // 0x8057A488: lw          $t5, 0x8($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X8);
            goto L_8057A494;
    }
    goto skip_7;
    // 0x8057A488: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    skip_7:
    // 0x8057A48C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8057A490: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
L_8057A494:
    // 0x8057A494: swc1        $f2, 0xB28($v1)
    MEM_W(0XB28, ctx->r3) = ctx->f2.u32l;
    // 0x8057A498: b           L_8057A660
    // 0x8057A49C: lhu         $v0, 0xC($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0XC);
        goto L_8057A660;
    // 0x8057A49C: lhu         $v0, 0xC($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0XC);
    // 0x8057A4A0: lw          $t6, 0x484($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X484);
L_8057A4A4:
    // 0x8057A4A4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8057A4A8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B14) << 16);
    // 0x8057A4AC: bnel        $t6, $zero, L_8057A664
    if (ctx->r14 != 0) {
        // 0x8057A4B0: andi        $t0, $v0, 0x20
        ctx->r8 = ctx->r2 & 0X20;
            goto L_8057A664;
    }
    goto skip_8;
    // 0x8057A4B0: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
    skip_8:
    // 0x8057A4B4: sw          $t7, 0x484($a1)
    MEM_W(0X484, ctx->r5) = ctx->r15;
    // 0x8057A4B8: lwc1        $f18, -0x4AAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B14));
    // 0x8057A4BC: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8057A4C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8057A4C4: nop

    // 0x8057A4C8: bc1fl       L_8057A4D8
    if (!c1cs) {
        // 0x8057A4CC: lw          $t8, 0x8($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X8);
            goto L_8057A4D8;
    }
    goto skip_9;
    // 0x8057A4CC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    skip_9:
    // 0x8057A4D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8057A4D4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
L_8057A4D8:
    // 0x8057A4D8: swc1        $f2, 0xB28($v1)
    MEM_W(0XB28, ctx->r3) = ctx->f2.u32l;
    // 0x8057A4DC: b           L_8057A660
    // 0x8057A4E0: lhu         $v0, 0xC($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XC);
        goto L_8057A660;
    // 0x8057A4E0: lhu         $v0, 0xC($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XC);
L_8057A4E4:
    // 0x8057A4E4: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x8057A4E8: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8057A4EC: bne         $t9, $at, L_8057A634
    if (ctx->r25 != ctx->r1) {
        // 0x8057A4F0: lui         $at, 0x8058
        ctx->r1 = S32(RELOC_HI16(384, 0X1B18) << 16);
            goto L_8057A634;
    }
    // 0x8057A4F0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B18) << 16);
    // 0x8057A4F4: lwc1        $f0, -0x4AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B18));
    // 0x8057A4F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A4FC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8057A500: nop

    // 0x8057A504: bc1fl       L_8057A530
    if (!c1cs) {
        // 0x8057A508: lw          $t0, 0x48C($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X48C);
            goto L_8057A530;
    }
    goto skip_10;
    // 0x8057A508: lw          $t0, 0x48C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X48C);
    skip_10:
    // 0x8057A50C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A510: jal         0x80579C6C
    // 0x8057A514: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C6C(rdram, ctx);
        goto after_5;
    // 0x8057A514: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8057A518: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B1C) << 16);
    // 0x8057A51C: lwc1        $f0, -0x4AA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B1C));
    // 0x8057A520: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A524: b           L_8057A57C
    // 0x8057A528: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
        goto L_8057A57C;
    // 0x8057A528: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A52C: lw          $t0, 0x48C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X48C);
L_8057A530:
    // 0x8057A530: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8057A534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A538: beql        $t0, $at, L_8057A560
    if (ctx->r8 == ctx->r1) {
        // 0x8057A53C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8057A560;
    }
    goto skip_11;
    // 0x8057A53C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_11:
    // 0x8057A540: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A544: jal         0x80579C6C
    // 0x8057A548: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C6C(rdram, ctx);
        goto after_6;
    // 0x8057A548: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x8057A54C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A550: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057A554: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8057A558: sw          $t1, 0x48C($a1)
    MEM_W(0X48C, ctx->r5) = ctx->r9;
    // 0x8057A55C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8057A560:
    // 0x8057A560: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057A564: jal         0x80579C18
    // 0x8057A568: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80579C18(rdram, ctx);
        goto after_7;
    // 0x8057A568: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x8057A56C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B24) << 16);
    // 0x8057A570: lwc1        $f0, -0x4A9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B24));
    // 0x8057A574: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A578: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
L_8057A57C:
    // 0x8057A57C: sw          $zero, 0x484($a1)
    MEM_W(0X484, ctx->r5) = 0;
    // 0x8057A580: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x8057A584: lw          $t2, 0x7EA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7EA8);
    // 0x8057A588: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8057A58C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8057A590: lhu         $v0, 0xC($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XC);
    // 0x8057A594: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x8057A598: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057A59C: andi        $t3, $v0, 0x400
    ctx->r11 = ctx->r2 & 0X400;
    // 0x8057A5A0: bnel        $t3, $at, L_8057A5EC
    if (ctx->r11 != ctx->r1) {
        // 0x8057A5A4: lw          $t6, 0x488($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X488);
            goto L_8057A5EC;
    }
    goto skip_12;
    // 0x8057A5A4: lw          $t6, 0x488($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X488);
    skip_12:
    // 0x8057A5A8: sw          $t4, 0x488($a1)
    MEM_W(0X488, ctx->r5) = ctx->r12;
    // 0x8057A5AC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B28) << 16);
    // 0x8057A5B0: lwc1        $f4, -0x4A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B28));
    // 0x8057A5B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057A5B8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057A5BC: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8057A5C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8057A5C4: nop

    // 0x8057A5C8: bc1f        L_8057A5D4
    if (!c1cs) {
        // 0x8057A5CC: nop
    
            goto L_8057A5D4;
    }
    // 0x8057A5CC: nop

    // 0x8057A5D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8057A5D4:
    // 0x8057A5D4: swc1        $f2, -0x7638($at)
    MEM_W(-0X7638, ctx->r1) = ctx->f2.u32l;
    // 0x8057A5D8: lw          $t5, 0x7EA8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7EA8);
    // 0x8057A5DC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057A5E0: b           L_8057A660
    // 0x8057A5E4: lhu         $v0, 0xC($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0XC);
        goto L_8057A660;
    // 0x8057A5E4: lhu         $v0, 0xC($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0XC);
    // 0x8057A5E8: lw          $t6, 0x488($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X488);
L_8057A5EC:
    // 0x8057A5EC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8057A5F0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B2C) << 16);
    // 0x8057A5F4: bne         $t6, $zero, L_8057A62C
    if (ctx->r14 != 0) {
        // 0x8057A5F8: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_8057A62C;
    }
    // 0x8057A5F8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8057A5FC: sw          $t7, 0x488($a1)
    MEM_W(0X488, ctx->r5) = ctx->r15;
    // 0x8057A600: lwc1        $f6, -0x4A94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B2C));
    // 0x8057A604: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057A608: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8057A60C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8057A610: nop

    // 0x8057A614: bc1f        L_8057A620
    if (!c1cs) {
        // 0x8057A618: nop
    
            goto L_8057A620;
    }
    // 0x8057A618: nop

    // 0x8057A61C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8057A620:
    // 0x8057A620: swc1        $f2, -0x7638($at)
    MEM_W(-0X7638, ctx->r1) = ctx->f2.u32l;
    // 0x8057A624: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x8057A628: lhu         $v0, 0xC($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XC);
L_8057A62C:
    // 0x8057A62C: b           L_8057A660
    // 0x8057A630: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
        goto L_8057A660;
    // 0x8057A630: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
L_8057A634:
    // 0x8057A634: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A638: jal         0x80579C6C
    // 0x8057A63C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80579C6C(rdram, ctx);
        goto after_8;
    // 0x8057A63C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_8:
    // 0x8057A640: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057A644: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8057A648: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057A64C: sw          $zero, 0x488($a1)
    MEM_W(0X488, ctx->r5) = 0;
    // 0x8057A650: sw          $zero, 0x484($a1)
    MEM_W(0X484, ctx->r5) = 0;
    // 0x8057A654: lw          $t9, 0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7EA8);
    // 0x8057A658: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057A65C: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
L_8057A660:
    // 0x8057A660: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
L_8057A664:
    // 0x8057A664: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8057A668: bnel        $t0, $at, L_8057A6C0
    if (ctx->r8 != ctx->r1) {
        // 0x8057A66C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057A6C0;
    }
    goto skip_13;
    // 0x8057A66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_13:
    // 0x8057A670: lbu         $t1, 0xB2C($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XB2C);
    // 0x8057A674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8057A678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8057A67C: bne         $t1, $at, L_8057A698
    if (ctx->r9 != ctx->r1) {
        // 0x8057A680: addiu       $a0, $zero, 0xCE
        ctx->r4 = ADD32(0, 0XCE);
            goto L_8057A698;
    }
    // 0x8057A680: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    // 0x8057A684: jal         0x80067818
    // 0x8057A688: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8057A688: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_9:
    // 0x8057A68C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057A690: b           L_8057A6AC
    // 0x8057A694: sb          $zero, -0x7634($at)
    MEM_B(-0X7634, ctx->r1) = 0;
        goto L_8057A6AC;
    // 0x8057A694: sb          $zero, -0x7634($at)
    MEM_B(-0X7634, ctx->r1) = 0;
L_8057A698:
    // 0x8057A698: jal         0x80067818
    // 0x8057A69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8057A69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8057A6A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8057A6A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057A6A8: sb          $t2, -0x7634($at)
    MEM_B(-0X7634, ctx->r1) = ctx->r10;
L_8057A6AC:
    // 0x8057A6AC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8057A6B0: lbu         $t3, -0x7634($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X7634);
    // 0x8057A6B4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8057A6B8: sb          $t3, 0x165($t4)
    MEM_B(0X165, ctx->r12) = ctx->r11;
    // 0x8057A6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057A6C0:
    // 0x8057A6C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8057A6C4: jr          $ra
    // 0x8057A6C8: nop

    return;
    // 0x8057A6C8: nop

;}
RECOMP_FUNC void func_8001A374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A374: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8001A378: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A37C: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8001A380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A384: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x8001A388: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_8001A38C:
    // 0x8001A38C: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A390: mflo        $t6
    ctx->r14 = lo;
    // 0x8001A394: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x8001A398: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x8001A39C: bne         $a1, $t7, L_8001A3CC
    if (ctx->r5 != ctx->r15) {
        // 0x8001A3A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001A3CC;
    }
    // 0x8001A3A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A3A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A3A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A3AC: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8001A3B0: sh          $zero, 0x20($a0)
    MEM_H(0X20, ctx->r4) = 0;
    // 0x8001A3B4: sh          $zero, 0x30($a0)
    MEM_H(0X30, ctx->r4) = 0;
    // 0x8001A3B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001A3BC: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001A3C0: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001A3C4: jr          $ra
    // 0x8001A3C8: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8001A3C8: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
L_8001A3CC:
    // 0x8001A3CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A3D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001A3D4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001A3D8: bne         $at, $zero, L_8001A38C
    if (ctx->r1 != 0) {
        // 0x8001A3DC: nop
    
            goto L_8001A38C;
    }
    // 0x8001A3DC: nop

    // 0x8001A3E0: jr          $ra
    // 0x8001A3E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001A3E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80465038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465038: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046503C: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x80465040: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80465044: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80465048: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8046504C: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80465050: jr          $ra
    // 0x80465054: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x80465054: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8041EF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041EF24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041EF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041EF2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041EF30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041EF34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041EF38: jal         0x8041DB1C
    // 0x8041EF3C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041EF3C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8041EF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EF44: jal         0x8041E9A8
    // 0x8041EF48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041EF48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041EF4C: beql        $v0, $zero, L_8041EFC4
    if (ctx->r2 == 0) {
        // 0x8041EF50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041EFC4;
    }
    goto skip_0;
    // 0x8041EF50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041EF54: lh          $v0, 0x2E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2E);
    // 0x8041EF58: beq         $v0, $zero, L_8041EF68
    if (ctx->r2 == 0) {
        // 0x8041EF5C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8041EF68;
    }
    // 0x8041EF5C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8041EF60: b           L_8041EFA0
    // 0x8041EF64: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
        goto L_8041EFA0;
    // 0x8041EF64: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
L_8041EF68:
    // 0x8041EF68: jal         0x800653D8
    // 0x8041EF6C: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8041EF6C: nop

    after_2:
    // 0x8041EF70: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8041EF74: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8041EF78: addiu       $t9, $t8, 0x3C
    ctx->r25 = ADD32(ctx->r24, 0X3C);
    // 0x8041EF7C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8041EF80: sh          $t9, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r25;
    // 0x8041EF84: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8041EF88: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8041EF8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EF94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EF98: jal         0x8041FE10
    // 0x8041EF9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8041FE10(rdram, ctx);
        goto after_3;
    // 0x8041EF9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_8041EFA0:
    // 0x8041EFA0: jal         0x8041E5E8
    // 0x8041EFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_4;
    // 0x8041EFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041EFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EFAC: jal         0x8041E430
    // 0x8041EFB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041EFB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8041EFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EFB8: jal         0x8041E7D4
    // 0x8041EFBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_6;
    // 0x8041EFBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8041EFC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EFC4:
    // 0x8041EFC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041EFC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041EFCC: jr          $ra
    // 0x8041EFD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8041EFD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002BBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BBF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BBF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BBFC: jal         0x8002BB90
    // 0x8002BC00: nop

    func_8002BB90(rdram, ctx);
        goto after_0;
    // 0x8002BC00: nop

    after_0:
    // 0x8002BC04: jal         0x8002AF54
    // 0x8002BC08: nop

    func_8002AF54(rdram, ctx);
        goto after_1;
    // 0x8002BC08: nop

    after_1:
    // 0x8002BC0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BC10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BC14: jr          $ra
    // 0x8002BC18: nop

    return;
    // 0x8002BC18: nop

;}
RECOMP_FUNC void func_800748B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800748B0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800748B4: sb          $t6, 0x45C($a0)
    MEM_B(0X45C, ctx->r4) = ctx->r14;
    // 0x800748B8: jr          $ra
    // 0x800748BC: nop

    return;
    // 0x800748BC: nop

;}
RECOMP_FUNC void func_8056417C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056417C: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x80564180: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80564184: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80564188: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8056418C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80564190: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80564194: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80564198: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8056419C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805641A0: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x805641A4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x805641A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805641AC: lw          $t6, 0x2EC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2EC);
    // 0x805641B0: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x805641B4: sb          $t8, 0x16B($sp)
    MEM_B(0X16B, ctx->r29) = ctx->r24;
    // 0x805641B8: lh          $a1, 0x502($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X502);
    // 0x805641BC: lh          $a2, 0x500($s4)
    ctx->r6 = MEM_H(ctx->r20, 0X500);
    // 0x805641C0: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x805641C4: bne         $at, $zero, L_80564210
    if (ctx->r1 != 0) {
        // 0x805641C8: nop
    
            goto L_80564210;
    }
    // 0x805641C8: nop

    // 0x805641CC: jal         0x800653D8
    // 0x805641D0: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805641D0: nop

    after_0:
    // 0x805641D4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x805641D8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x805641DC: mfhi        $t9
    ctx->r25 = hi;
    // 0x805641E0: addiu       $t0, $t9, 0x1E
    ctx->r8 = ADD32(ctx->r25, 0X1E);
    // 0x805641E4: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x805641E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805641EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805641F0: jal         0x80565C28
    // 0x805641F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80565C28(rdram, ctx);
        goto after_1;
    // 0x805641F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x805641F8: addiu       $t1, $zero, -0xA
    ctx->r9 = ADD32(0, -0XA);
    // 0x805641FC: sh          $t1, 0x502($s4)
    MEM_H(0X502, ctx->r20) = ctx->r9;
    // 0x80564200: lh          $t2, 0x502($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X502);
    // 0x80564204: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80564208: addiu       $a2, $zero, -0xA
    ctx->r6 = ADD32(0, -0XA);
    // 0x8056420C: sh          $t2, 0x500($s4)
    MEM_H(0X500, ctx->r20) = ctx->r10;
L_80564210:
    // 0x80564210: blez        $a1, L_80564258
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80564214: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80564258;
    }
    // 0x80564214: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80564218: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x8056421C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80564220: addu        $s0, $s4, $t3
    ctx->r16 = ADD32(ctx->r20, ctx->r11);
    // 0x80564224: addiu       $s1, $s4, 0x4E0
    ctx->r17 = ADD32(ctx->r20, 0X4E0);
    // 0x80564228: swc1        $f22, 0x464($s0)
    MEM_W(0X464, ctx->r16) = ctx->f22.u32l;
L_8056422C:
    // 0x8056422C: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80564230: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80564234: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x80564238: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x8056423C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564240: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80564244: beq         $at, $zero, L_80564258
    if (ctx->r1 == 0) {
        // 0x80564248: sb          $t5, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r13;
            goto L_80564258;
    }
    // 0x80564248: sb          $t5, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r13;
    // 0x8056424C: slt         $at, $s2, $a1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80564250: bnel        $at, $zero, L_8056422C
    if (ctx->r1 != 0) {
        // 0x80564254: swc1        $f22, 0x464($s0)
        MEM_W(0X464, ctx->r16) = ctx->f22.u32l;
            goto L_8056422C;
    }
    goto skip_0;
    // 0x80564254: swc1        $f22, 0x464($s0)
    MEM_W(0X464, ctx->r16) = ctx->f22.u32l;
    skip_0:
L_80564258:
    // 0x80564258: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8056425C: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x80564260: beq         $at, $zero, L_805642E0
    if (ctx->r1 == 0) {
        // 0x80564264: addiu       $a0, $s4, 0x4E0
        ctx->r4 = ADD32(ctx->r20, 0X4E0);
            goto L_805642E0;
    }
    // 0x80564264: addiu       $a0, $s4, 0x4E0
    ctx->r4 = ADD32(ctx->r20, 0X4E0);
    // 0x80564268: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8056426C: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80564270: beq         $at, $zero, L_805642E0
    if (ctx->r1 == 0) {
        // 0x80564274: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_805642E0;
    }
    // 0x80564274: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80564278: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8056427C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80564280: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80564284: subu        $v0, $s2, $a1
    ctx->r2 = SUB32(ctx->r18, ctx->r5);
    // 0x80564288: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8056428C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80564290: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x80564294: addu        $s1, $a0, $s2
    ctx->r17 = ADD32(ctx->r4, ctx->r18);
    // 0x80564298: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_8056429C:
    // 0x8056429C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x805642A0: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x805642A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805642A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x805642AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805642B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x805642B4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x805642B8: nop

    // 0x805642BC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805642C0: swc1        $f10, 0x460($s0)
    MEM_W(0X460, ctx->r16) = ctx->f10.u32l;
    // 0x805642C4: lbu         $t6, -0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, -0X1);
    // 0x805642C8: andi        $t8, $t6, 0x7F
    ctx->r24 = ctx->r14 & 0X7F;
    // 0x805642CC: beq         $at, $zero, L_805642E0
    if (ctx->r1 == 0) {
        // 0x805642D0: sb          $t8, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r24;
            goto L_805642E0;
    }
    // 0x805642D0: sb          $t8, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r24;
    // 0x805642D4: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x805642D8: bnel        $at, $zero, L_8056429C
    if (ctx->r1 != 0) {
        // 0x805642DC: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_8056429C;
    }
    goto skip_1;
    // 0x805642DC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_1:
L_805642E0:
    // 0x805642E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805642E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805642E8: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x805642EC: beq         $at, $zero, L_80564338
    if (ctx->r1 == 0) {
        // 0x805642F0: addiu       $v0, $a2, -0x6
        ctx->r2 = ADD32(ctx->r6, -0X6);
            goto L_80564338;
    }
    // 0x805642F0: addiu       $v0, $a2, -0x6
    ctx->r2 = ADD32(ctx->r6, -0X6);
    // 0x805642F4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x805642F8: beq         $at, $zero, L_80564338
    if (ctx->r1 == 0) {
        // 0x805642FC: sll         $t9, $s2, 2
        ctx->r25 = S32(ctx->r18 << 2);
            goto L_80564338;
    }
    // 0x805642FC: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80564300: addu        $s0, $s4, $t9
    ctx->r16 = ADD32(ctx->r20, ctx->r25);
    // 0x80564304: addu        $s1, $a0, $s2
    ctx->r17 = ADD32(ctx->r4, ctx->r18);
    // 0x80564308: swc1        $f0, 0x464($s0)
    MEM_W(0X464, ctx->r16) = ctx->f0.u32l;
L_8056430C:
    // 0x8056430C: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80564310: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80564314: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x80564318: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8056431C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564320: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80564324: beq         $at, $zero, L_80564338
    if (ctx->r1 == 0) {
        // 0x80564328: sb          $t1, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r9;
            goto L_80564338;
    }
    // 0x80564328: sb          $t1, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r9;
    // 0x8056432C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80564330: bnel        $at, $zero, L_8056430C
    if (ctx->r1 != 0) {
        // 0x80564334: swc1        $f0, 0x464($s0)
        MEM_W(0X464, ctx->r16) = ctx->f0.u32l;
            goto L_8056430C;
    }
    goto skip_2;
    // 0x80564334: swc1        $f0, 0x464($s0)
    MEM_W(0X464, ctx->r16) = ctx->f0.u32l;
    skip_2:
L_80564338:
    // 0x80564338: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x8056433C: beq         $at, $zero, L_805643AC
    if (ctx->r1 == 0) {
        // 0x80564340: slt         $at, $s2, $a2
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_805643AC;
    }
    // 0x80564340: slt         $at, $s2, $a2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80564344: beq         $at, $zero, L_805643AC
    if (ctx->r1 == 0) {
        // 0x80564348: sll         $t2, $s2, 2
        ctx->r10 = S32(ctx->r18 << 2);
            goto L_805643AC;
    }
    // 0x80564348: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x8056434C: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80564350: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80564354: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80564358: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(369, 0X2420) << 16);
    // 0x8056435C: addiu       $t6, $t6, 0x5C80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(369, 0X2420));
    // 0x80564360: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80564364: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80564368: addu        $s0, $s4, $t2
    ctx->r16 = ADD32(ctx->r20, ctx->r10);
    // 0x8056436C: addu        $s1, $a0, $s2
    ctx->r17 = ADD32(ctx->r4, ctx->r18);
    // 0x80564370: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
L_80564374:
    // 0x80564374: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80564378: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x8056437C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80564380: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564384: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80564388: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8056438C: swc1        $f6, 0x460($s0)
    MEM_W(0X460, ctx->r16) = ctx->f6.u32l;
    // 0x80564390: lbu         $t8, -0x1($s1)
    ctx->r24 = MEM_BU(ctx->r17, -0X1);
    // 0x80564394: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80564398: beq         $at, $zero, L_805643AC
    if (ctx->r1 == 0) {
        // 0x8056439C: sb          $t9, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r25;
            goto L_805643AC;
    }
    // 0x8056439C: sb          $t9, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r25;
    // 0x805643A0: slt         $at, $s2, $a2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x805643A4: bnel        $at, $zero, L_80564374
    if (ctx->r1 != 0) {
        // 0x805643A8: lwc1        $f4, 0x18($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
            goto L_80564374;
    }
    goto skip_3;
    // 0x805643A8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    skip_3:
L_805643AC:
    // 0x805643AC: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x805643B0: beq         $at, $zero, L_805643E4
    if (ctx->r1 == 0) {
        // 0x805643B4: sll         $t0, $s2, 2
        ctx->r8 = S32(ctx->r18 << 2);
            goto L_805643E4;
    }
    // 0x805643B4: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x805643B8: addu        $s0, $s4, $t0
    ctx->r16 = ADD32(ctx->r20, ctx->r8);
    // 0x805643BC: addu        $s1, $a0, $s2
    ctx->r17 = ADD32(ctx->r4, ctx->r18);
L_805643C0:
    // 0x805643C0: swc1        $f22, 0x464($s0)
    MEM_W(0X464, ctx->r16) = ctx->f22.u32l;
    // 0x805643C4: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x805643C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x805643CC: slti        $at, $s2, 0x1F
    ctx->r1 = SIGNED(ctx->r18) < 0X1F ? 1 : 0;
    // 0x805643D0: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x805643D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805643D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x805643DC: bne         $at, $zero, L_805643C0
    if (ctx->r1 != 0) {
        // 0x805643E0: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_805643C0;
    }
    // 0x805643E0: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
L_805643E4:
    // 0x805643E4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x805643E8: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x805643EC: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    // 0x805643F0: addiu       $s2, $sp, 0xDC
    ctx->r18 = ADD32(ctx->r29, 0XDC);
L_805643F4:
    // 0x805643F4: lwc1        $f8, 0x3E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3E8);
    // 0x805643F8: lwc1        $f10, 0x3EC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3EC);
    // 0x805643FC: lwc1        $f0, 0x504($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X504);
    // 0x80564400: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80564404: jal         0x80067114
    // 0x80564408: add.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f0.fl;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x80564408: add.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f0.fl;
    after_2:
    // 0x8056440C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80564410: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80564414: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564418: bne         $at, $zero, L_805643F4
    if (ctx->r1 != 0) {
        // 0x8056441C: swc1        $f0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
            goto L_805643F4;
    }
    // 0x8056441C: swc1        $f0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80564420: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80564424: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80564428: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x8056442C: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x80564430: addiu       $s2, $sp, 0xDC
    ctx->r18 = ADD32(ctx->r29, 0XDC);
L_80564434:
    // 0x80564434: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80564438: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8056443C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80564440: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80564444: jal         0x80066DE4
    // 0x80564448: nop

    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80564448: nop

    after_3:
    // 0x8056444C: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80564450: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80564454: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80564458: lwc1        $f8, 0x464($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X464);
    // 0x8056445C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80564460: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80564464: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80564468: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8056446C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80564470: bne         $at, $zero, L_80564434
    if (ctx->r1 != 0) {
        // 0x80564474: swc1        $f10, 0x460($s0)
        MEM_W(0X460, ctx->r16) = ctx->f10.u32l;
            goto L_80564434;
    }
    // 0x80564474: swc1        $f10, 0x460($s0)
    MEM_W(0X460, ctx->r16) = ctx->f10.u32l;
    // 0x80564478: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2560) << 16);
    // 0x8056447C: lwc1        $f16, 0x5DC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2560));
    // 0x80564480: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2564) << 16);
    // 0x80564484: lwc1        $f14, 0x5DC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2564));
    // 0x80564488: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2568) << 16);
    // 0x8056448C: lwc1        $f12, 0x5DC8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2568));
    // 0x80564490: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X256C) << 16);
    // 0x80564494: lwc1        $f2, 0x5DCC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X256C));
    // 0x80564498: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8056449C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x805644A0: addiu       $v0, $s4, 0x78
    ctx->r2 = ADD32(ctx->r20, 0X78);
L_805644A4:
    // 0x805644A4: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x805644A8: lwc1        $f8, 0x464($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X464);
    // 0x805644AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x805644B0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805644B4: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x805644B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805644BC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x805644C0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805644C4: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x805644C8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805644CC: nop

    // 0x805644D0: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x805644D4: swc1        $f4, 0x460($s0)
    MEM_W(0X460, ctx->r16) = ctx->f4.u32l;
    // 0x805644D8: lwc1        $f6, 0x468($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X468);
    // 0x805644DC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x805644E0: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805644E4: bne         $at, $zero, L_805644A4
    if (ctx->r1 != 0) {
        // 0x805644E8: swc1        $f4, 0x468($v0)
        MEM_W(0X468, ctx->r2) = ctx->f4.u32l;
            goto L_805644A4;
    }
    // 0x805644E8: swc1        $f4, 0x468($v0)
    MEM_W(0X468, ctx->r2) = ctx->f4.u32l;
    // 0x805644EC: swc1        $f22, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f22.u32l;
    // 0x805644F0: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x805644F4: addiu       $s3, $sp, 0xE4
    ctx->r19 = ADD32(ctx->r29, 0XE4);
    // 0x805644F8: swc1        $f22, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f22.u32l;
    // 0x805644FC: addiu       $v0, $sp, 0x158
    ctx->r2 = ADD32(ctx->r29, 0X158);
    // 0x80564500: lwc1        $f16, 0x3E4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E4);
    // 0x80564504: lwc1        $f14, 0x3EC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3EC);
    // 0x80564508: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8056450C: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x80564510: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80564514: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80564518: beql        $at, $zero, L_80564554
    if (ctx->r1 == 0) {
        // 0x8056451C: lwc1        $f16, 0x3E8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
            goto L_80564554;
    }
    goto skip_4;
    // 0x8056451C: lwc1        $f16, 0x3E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
    skip_4:
    // 0x80564520: lwc1        $f16, 0x3E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
L_80564524:
    // 0x80564524: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80564528: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8056452C: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80564530: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564534: swc1        $f16, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = ctx->f16.u32l;
    // 0x80564538: lwc1        $f16, 0x3E4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E4);
    // 0x8056453C: lwc1        $f14, 0x3EC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3EC);
    // 0x80564540: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80564544: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80564548: bnel        $at, $zero, L_80564524
    if (ctx->r1 != 0) {
        // 0x8056454C: lwc1        $f16, 0x3E8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
            goto L_80564524;
    }
    goto skip_5;
    // 0x8056454C: lwc1        $f16, 0x3E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
    skip_5:
    // 0x80564550: lwc1        $f16, 0x3E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3E8);
L_80564554:
    // 0x80564554: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564558: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8056455C: swc1        $f16, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f16.u32l;
    // 0x80564560: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2570) << 16);
    // 0x80564564: lwc1        $f18, 0x5DD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2570));
    // 0x80564568: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2574) << 16);
    // 0x8056456C: lwc1        $f16, 0x5DD4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2574));
    // 0x80564570: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80564574: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80564578: addiu       $s3, $sp, 0xE0
    ctx->r19 = ADD32(ctx->r29, 0XE0);
    // 0x8056457C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80564580: lbu         $v1, 0x16B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X16B);
    // 0x80564584: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
L_80564588:
    // 0x80564588: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x8056458C: lwc1        $f12, 0x464($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X464);
    // 0x80564590: lwc1        $f10, 0x2F0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x80564594: andi        $t3, $t4, 0x80
    ctx->r11 = ctx->r12 & 0X80;
    // 0x80564598: beq         $t3, $zero, L_805645BC
    if (ctx->r11 == 0) {
        // 0x8056459C: sub.s       $f0, $f10, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f12.fl;
            goto L_805645BC;
    }
    // 0x8056459C: sub.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x805645A0: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x805645A4: nop

    // 0x805645A8: bc1f        L_805645BC
    if (!c1cs) {
        // 0x805645AC: nop
    
            goto L_805645BC;
    }
    // 0x805645AC: nop

    // 0x805645B0: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x805645B4: b           L_805645C8
    // 0x805645B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_805645C8;
    // 0x805645B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_805645BC:
    // 0x805645BC: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805645C0: nop

    // 0x805645C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_805645C8:
    // 0x805645C8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805645CC: nop

    // 0x805645D0: bc1fl       L_805645F0
    if (!c1cs) {
        // 0x805645D4: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_805645F0;
    }
    goto skip_6;
    // 0x805645D4: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_6:
    // 0x805645D8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x805645DC: nop

    // 0x805645E0: bc1fl       L_805645F0
    if (!c1cs) {
        // 0x805645E4: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_805645F0;
    }
    goto skip_7;
    // 0x805645E4: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_7:
    // 0x805645E8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x805645EC: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
L_805645F0:
    // 0x805645F0: lwc1        $f8, 0x2F4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F4);
    // 0x805645F4: swc1        $f4, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f4.u32l;
    // 0x805645F8: lwc1        $f14, 0x464($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X464);
    // 0x805645FC: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    // 0x80564600: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80564604: andi        $t7, $t5, 0x80
    ctx->r15 = ctx->r13 & 0X80;
    // 0x80564608: beq         $t7, $zero, L_8056462C
    if (ctx->r15 == 0) {
        // 0x8056460C: sub.s       $f0, $f8, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f14.fl;
            goto L_8056462C;
    }
    // 0x8056460C: sub.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80564610: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80564614: nop

    // 0x80564618: bc1f        L_8056462C
    if (!c1cs) {
        // 0x8056461C: nop
    
            goto L_8056462C;
    }
    // 0x8056461C: nop

    // 0x80564620: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80564624: b           L_80564638
    // 0x80564628: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_80564638;
    // 0x80564628: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8056462C:
    // 0x8056462C: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80564630: nop

    // 0x80564634: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80564638:
    // 0x80564638: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8056463C: nop

    // 0x80564640: bc1fl       L_80564660
    if (!c1cs) {
        // 0x80564644: add.s       $f6, $f14, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_80564660;
    }
    goto skip_8;
    // 0x80564644: add.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
    skip_8:
    // 0x80564648: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8056464C: nop

    // 0x80564650: bc1fl       L_80564660
    if (!c1cs) {
        // 0x80564654: add.s       $f6, $f14, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_80564660;
    }
    goto skip_9;
    // 0x80564654: add.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
    skip_9:
    // 0x80564658: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x8056465C: add.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
L_80564660:
    // 0x80564660: lwc1        $f10, 0x2F0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x80564664: swc1        $f6, 0x2F4($v0)
    MEM_W(0X2F4, ctx->r2) = ctx->f6.u32l;
    // 0x80564668: lwc1        $f8, 0x2F4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F4);
    // 0x8056466C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80564670: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80564674: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80564678: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8056467C: nop

    // 0x80564680: bnel        $t8, $t0, L_8056469C
    if (ctx->r24 != ctx->r8) {
        // 0x80564684: lbu         $t4, 0x0($s1)
        ctx->r12 = MEM_BU(ctx->r17, 0X0);
            goto L_8056469C;
    }
    goto skip_10;
    // 0x80564684: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    skip_10:
    // 0x80564688: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8056468C: or          $t2, $t1, $v1
    ctx->r10 = ctx->r9 | ctx->r3;
    // 0x80564690: b           L_805646A8
    // 0x80564694: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
        goto L_805646A8;
    // 0x80564694: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x80564698: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
L_8056469C:
    // 0x8056469C: xori        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 ^ 0XFF;
    // 0x805646A0: and         $t5, $t4, $t3
    ctx->r13 = ctx->r12 & ctx->r11;
    // 0x805646A4: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
L_805646A8:
    // 0x805646A8: lwc1        $f10, 0x3E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3E8);
    // 0x805646AC: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x805646B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x805646B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x805646B8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x805646BC: swc1        $f8, 0x3E8($s0)
    MEM_W(0X3E8, ctx->r16) = ctx->f8.u32l;
    // 0x805646C0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x805646C4: jal         0x805640E0
    // 0x805646C8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_805640E0(rdram, ctx);
        goto after_4;
    // 0x805646C8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_4:
    // 0x805646CC: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2578) << 16);
    // 0x805646D0: lwc1        $f2, 0x3E8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3E8);
    // 0x805646D4: lwc1        $f16, 0x5DD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2578));
    // 0x805646D8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X257C) << 16);
    // 0x805646DC: lwc1        $f18, 0x5DDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X257C));
    // 0x805646E0: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x805646E4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2580) << 16);
    // 0x805646E8: lwc1        $f10, 0x5DE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2580));
    // 0x805646EC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x805646F0: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x805646F4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805646F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x805646FC: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80564700: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80564704: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80564708: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8056470C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80564710: add.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80564714: bne         $s2, $at, L_80564588
    if (ctx->r18 != ctx->r1) {
        // 0x80564718: swc1        $f8, 0x3E4($s0)
        MEM_W(0X3E4, ctx->r16) = ctx->f8.u32l;
            goto L_80564588;
    }
    // 0x80564718: swc1        $f8, 0x3E4($s0)
    MEM_W(0X3E4, ctx->r16) = ctx->f8.u32l;
    // 0x8056471C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80564720: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80564724: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80564728: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8056472C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80564730: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80564734: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80564738: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8056473C: jr          $ra
    // 0x80564740: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x80564740: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void func_800275D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800275D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800275D8: jal         0x8001D770
    // 0x800275DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x800275DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800275E0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800275E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800275E8: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x800275EC: jal         0x80067BF8
    // 0x800275F0: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x800275F0: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_1:
    // 0x800275F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800275F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800275FC: jal         0x80067838
    // 0x80027600: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x80027600: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80027604: jal         0x800247E4
    // 0x80027608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800247E4(rdram, ctx);
        goto after_3;
    // 0x80027608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8002760C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027614: jr          $ra
    // 0x80027618: nop

    return;
    // 0x80027618: nop

;}
RECOMP_FUNC void func_80047F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047F38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80047F3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80047F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047F44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80047F48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80047F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80047F50:
    // 0x80047F50: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80047F54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047F58: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80047F5C: beq         $a0, $zero, L_80047F80
    if (ctx->r4 == 0) {
        // 0x80047F60: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80047F80;
    }
    // 0x80047F60: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80047F64: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80047F68: bnel        $v1, $t6, L_80047F84
    if (ctx->r3 != ctx->r14) {
        // 0x80047F6C: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80047F84;
    }
    goto skip_0;
    // 0x80047F6C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    skip_0:
    // 0x80047F70: jalr        $a2
    // 0x80047F74: nop

    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x80047F74: nop

    after_0:
    // 0x80047F78: b           L_80047F90
    // 0x80047F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80047F90;
    // 0x80047F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80047F80:
    // 0x80047F80: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
L_80047F84:
    // 0x80047F84: bne         $at, $zero, L_80047F50
    if (ctx->r1 != 0) {
        // 0x80047F88: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80047F50;
    }
    // 0x80047F88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80047F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80047F90:
    // 0x80047F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047F94: jr          $ra
    // 0x80047F98: nop

    return;
    // 0x80047F98: nop

;}
RECOMP_FUNC void func_80580D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580D14: jal         0x80580C70
    // 0x80580D18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80580D18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80580D1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580D20: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80580D24: beql        $t6, $zero, L_80580D48
    if (ctx->r14 == 0) {
        // 0x80580D28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80580D48;
    }
    goto skip_0;
    // 0x80580D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80580D2C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80580D30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80580D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580D38: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80580D3C: jal         0x80580F6C
    // 0x80580D40: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    func_80580F6C(rdram, ctx);
        goto after_1;
    // 0x80580D40: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    after_1:
    // 0x80580D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80580D48:
    // 0x80580D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580D4C: jr          $ra
    // 0x80580D50: nop

    return;
    // 0x80580D50: nop

;}
RECOMP_FUNC void func_80452F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452F88: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452F8C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452F90: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452F94: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452F98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452F9C: ori         $at, $at, 0x6ECC
    ctx->r1 = ctx->r1 | 0X6ECC;
    // 0x80452FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452FA4: jal         0x80452A64
    // 0x80452FA8: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452FA8: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452FAC: bne         $v0, $zero, L_80452FC4
    if (ctx->r2 != 0) {
        // 0x80452FB0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452FC4;
    }
    // 0x80452FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452FB4: jal         0x80452A14
    // 0x80452FB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452FB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80452FBC: b           L_80452FD0
    // 0x80452FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452FD0;
    // 0x80452FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452FC4:
    // 0x80452FC4: jal         0x8045278C
    // 0x80452FC8: nop

    func_8045278C(rdram, ctx);
        goto after_2;
    // 0x80452FC8: nop

    after_2:
    // 0x80452FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452FD0:
    // 0x80452FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452FD4: jr          $ra
    // 0x80452FD8: nop

    return;
    // 0x80452FD8: nop

;}
RECOMP_FUNC void func_805848AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805848AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805848B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805848B4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805848B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805848BC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805848C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805848C4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805848C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805848CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805848D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805848D4: jr          $ra
    // 0x805848D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805848D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804D83B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D83B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804D83B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D83BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D83C0: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804D83C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804D83C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804D83CC: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x804D83D0: bne         $at, $zero, L_804D8440
    if (ctx->r1 != 0) {
        // 0x804D83D4: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804D8440;
    }
    // 0x804D83D4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804D83D8: jal         0x80047090
    // 0x804D83DC: addiu       $a0, $zero, 0x404A
    ctx->r4 = ADD32(0, 0X404A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804D83DC: addiu       $a0, $zero, 0x404A
    ctx->r4 = ADD32(0, 0X404A);
    after_0:
    // 0x804D83E0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804D83E4: beq         $v0, $at, L_804D8440
    if (ctx->r2 == ctx->r1) {
        // 0x804D83E8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804D8440;
    }
    // 0x804D83E8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804D83EC: lui         $at, 0x404A
    ctx->r1 = S32(0X404A << 16);
    // 0x804D83F0: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x804D83F4: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x804D83F8: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x804D83FC: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // 0x804D8400: jal         0x8004613C
    // 0x804D8404: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804D8404: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x804D8408: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804D840C: lhu         $t9, 0x22($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X22);
    // 0x804D8410: lhu         $t1, 0xE($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XE);
    // 0x804D8414: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x804D8418: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x804D841C: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x804D8420: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x804D8424: sh          $t3, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r11;
    // 0x804D8428: sb          $t4, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r12;
    // 0x804D842C: jal         0x80044194
    // 0x804D8430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804D8430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x804D8434: jal         0x8005FDC4
    // 0x804D8438: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x804D8438: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x804D843C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_804D8440:
    // 0x804D8440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D8448: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804D844C: jr          $ra
    // 0x804D8450: nop

    return;
    // 0x804D8450: nop

;}
RECOMP_FUNC void func_80033FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033FB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033FB8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80033FBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033FC0: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80033FC4: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80033FC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033FCC: jal         0x80053924
    // 0x80033FD0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80033FD0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x80033FD4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80033FD8: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80033FDC: lbu         $t6, 0xAF6($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XAF6);
    // 0x80033FE0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80033FE4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80033FE8: beql        $t6, $zero, L_800340CC
    if (ctx->r14 == 0) {
        // 0x80033FEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800340CC;
    }
    goto skip_0;
    // 0x80033FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80033FF0: lw          $a0, 0x174($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X174);
    // 0x80033FF4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80033FF8: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80033FFC: bnel        $t8, $zero, L_800340CC
    if (ctx->r24 != 0) {
        // 0x80034000: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800340CC;
    }
    goto skip_1;
    // 0x80034000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80034004: beq         $v0, $zero, L_80034050
    if (ctx->r2 == 0) {
        // 0x80034008: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80034050;
    }
    // 0x80034008: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003400C: beq         $v0, $at, L_80034050
    if (ctx->r2 == ctx->r1) {
        // 0x80034010: lbu         $a1, 0x1E($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0X1E);
            goto L_80034050;
    }
    // 0x80034010: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x80034014: andi        $v0, $a1, 0xF8
    ctx->r2 = ctx->r5 & 0XF8;
    // 0x80034018: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8003401C: beq         $v0, $at, L_80034050
    if (ctx->r2 == ctx->r1) {
        // 0x80034020: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80034050;
    }
    // 0x80034020: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80034024: beql        $v0, $at, L_80034054
    if (ctx->r2 == ctx->r1) {
        // 0x80034028: lw          $v1, 0x4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X4);
            goto L_80034054;
    }
    goto skip_2;
    // 0x80034028: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x8003402C: lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X10);
    // 0x80034030: xori        $t9, $v0, 0x28
    ctx->r25 = ctx->r2 ^ 0X28;
    // 0x80034034: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80034038: beq         $v1, $zero, L_80034044
    if (ctx->r3 == 0) {
        // 0x8003403C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80034044;
    }
    // 0x8003403C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80034040: bne         $t9, $t0, L_80034050
    if (ctx->r25 != ctx->r8) {
        // 0x80034044: andi        $t2, $a1, 0x1
        ctx->r10 = ctx->r5 & 0X1;
            goto L_80034050;
    }
L_80034044:
    // 0x80034044: andi        $t2, $a1, 0x1
    ctx->r10 = ctx->r5 & 0X1;
    // 0x80034048: bnel        $t2, $zero, L_800340CC
    if (ctx->r10 != 0) {
        // 0x8003404C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800340CC;
    }
    goto skip_3;
    // 0x8003404C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
L_80034050:
    // 0x80034050: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
L_80034054:
    // 0x80034054: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80034058: beq         $v1, $zero, L_800340AC
    if (ctx->r3 == 0) {
        // 0x8003405C: nop
    
            goto L_800340AC;
    }
    // 0x8003405C: nop

    // 0x80034060: lw          $t3, 0x180($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X180);
    // 0x80034064: bne         $v1, $t3, L_800340AC
    if (ctx->r3 != ctx->r11) {
        // 0x80034068: nop
    
            goto L_800340AC;
    }
    // 0x80034068: nop

    // 0x8003406C: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80034070: addiu       $at, $zero, 0x4507
    ctx->r1 = ADD32(0, 0X4507);
    // 0x80034074: beq         $v0, $at, L_80034094
    if (ctx->r2 == ctx->r1) {
        // 0x80034078: addiu       $at, $zero, 0x4508
        ctx->r1 = ADD32(0, 0X4508);
            goto L_80034094;
    }
    // 0x80034078: addiu       $at, $zero, 0x4508
    ctx->r1 = ADD32(0, 0X4508);
    // 0x8003407C: beq         $v0, $at, L_80034094
    if (ctx->r2 == ctx->r1) {
        // 0x80034080: addiu       $at, $zero, 0x4509
        ctx->r1 = ADD32(0, 0X4509);
            goto L_80034094;
    }
    // 0x80034080: addiu       $at, $zero, 0x4509
    ctx->r1 = ADD32(0, 0X4509);
    // 0x80034084: beq         $v0, $at, L_80034094
    if (ctx->r2 == ctx->r1) {
        // 0x80034088: addiu       $at, $zero, 0x450A
        ctx->r1 = ADD32(0, 0X450A);
            goto L_80034094;
    }
    // 0x80034088: addiu       $at, $zero, 0x450A
    ctx->r1 = ADD32(0, 0X450A);
    // 0x8003408C: bne         $v0, $at, L_800340AC
    if (ctx->r2 != ctx->r1) {
        // 0x80034090: nop
    
            goto L_800340AC;
    }
    // 0x80034090: nop

L_80034094:
    // 0x80034094: lw          $t4, 0x5B8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X5B8);
    // 0x80034098: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8003409C: bne         $at, $zero, L_800340AC
    if (ctx->r1 != 0) {
        // 0x800340A0: nop
    
            goto L_800340AC;
    }
    // 0x800340A0: nop

    // 0x800340A4: b           L_800340CC
    // 0x800340A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800340CC;
    // 0x800340A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800340AC:
    // 0x800340AC: jal         0x8002DD44
    // 0x800340B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8002DD44(rdram, ctx);
        goto after_1;
    // 0x800340B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800340B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800340B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800340BC: lw          $t5, 0x1F4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1F4);
    // 0x800340C0: b           L_800340CC
    // 0x800340C4: sb          $zero, 0xDC($t5)
    MEM_B(0XDC, ctx->r13) = 0;
        goto L_800340CC;
    // 0x800340C4: sb          $zero, 0xDC($t5)
    MEM_B(0XDC, ctx->r13) = 0;
    // 0x800340C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800340CC:
    // 0x800340CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800340D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800340D4: jr          $ra
    // 0x800340D8: nop

    return;
    // 0x800340D8: nop

;}
RECOMP_FUNC void func_80426E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426E54: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80426E58: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80426E5C: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80426E60: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80426E64: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
    // 0x80426E68: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80426E6C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80426E70: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80426E74: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80426E78: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x80426E7C: beq         $t9, $zero, L_80426EF8
    if (ctx->r25 == 0) {
        // 0x80426E80: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80426EF8;
    }
    // 0x80426E80: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80426E84: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80426E88: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
L_80426E8C:
    // 0x80426E8C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80426E90: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80426E94: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80426E98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80426E9C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80426EA0: mflo        $t4
    ctx->r12 = lo;
    // 0x80426EA4: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x80426EA8: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x80426EAC: sh          $t5, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r13;
    // 0x80426EB0: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80426EB4: sh          $t6, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r14;
    // 0x80426EB8: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x80426EBC: sh          $zero, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = 0;
    // 0x80426EC0: sh          $t7, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r15;
    // 0x80426EC4: lh          $t8, -0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, -0X4);
    // 0x80426EC8: sh          $t8, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r24;
    // 0x80426ECC: lh          $t9, -0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, -0X2);
    // 0x80426ED0: sb          $zero, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = 0;
    // 0x80426ED4: sb          $t1, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r9;
    // 0x80426ED8: sb          $zero, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = 0;
    // 0x80426EDC: sb          $zero, -0x4($a2)
    MEM_B(-0X4, ctx->r6) = 0;
    // 0x80426EE0: sh          $t9, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r25;
    // 0x80426EE4: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80426EE8: sltu        $at, $t0, $t3
    ctx->r1 = ctx->r8 < ctx->r11 ? 1 : 0;
    // 0x80426EEC: bnel        $at, $zero, L_80426E8C
    if (ctx->r1 != 0) {
        // 0x80426EF0: lw          $t3, 0x0($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X0);
            goto L_80426E8C;
    }
    goto skip_0;
    // 0x80426EF0: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80426EF4: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
L_80426EF8:
    // 0x80426EF8: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80426EFC: sh          $t2, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r10;
    // 0x80426F00: lh          $t4, 0x1C($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1C);
    // 0x80426F04: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80426F08: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80426F0C: bne         $at, $zero, L_80426F18
    if (ctx->r1 != 0) {
        // 0x80426F10: nop
    
            goto L_80426F18;
    }
    // 0x80426F10: nop

    // 0x80426F14: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
L_80426F18:
    // 0x80426F18: jr          $ra
    // 0x80426F1C: nop

    return;
    // 0x80426F1C: nop

;}
RECOMP_FUNC void func_800656BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656BC: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x800656C0: beq         $at, $zero, L_800656D0
    if (ctx->r1 == 0) {
        // 0x800656C4: nop
    
            goto L_800656D0;
    }
    // 0x800656C4: nop

    // 0x800656C8: jr          $ra
    // 0x800656CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800656CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800656D0:
    // 0x800656D0: divu        $zero, $a1, $a2
    lo = S32(U32(ctx->r5) / U32(ctx->r6)); hi = S32(U32(ctx->r5) % U32(ctx->r6));
    // 0x800656D4: mflo        $t6
    ctx->r14 = lo;
    // 0x800656D8: bne         $a2, $zero, L_800656E4
    if (ctx->r6 != 0) {
        // 0x800656DC: nop
    
            goto L_800656E4;
    }
    // 0x800656DC: nop

    // 0x800656E0: break       7
    do_break(2147899104);
L_800656E4:
    // 0x800656E4: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800656E8: mflo        $t7
    ctx->r15 = lo;
    // 0x800656EC: beq         $a1, $t7, L_800656FC
    if (ctx->r5 == ctx->r15) {
        // 0x800656F0: nop
    
            goto L_800656FC;
    }
    // 0x800656F0: nop

    // 0x800656F4: jr          $ra
    // 0x800656F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800656F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800656FC:
    // 0x800656FC: bne         $a0, $zero, L_8006570C
    if (ctx->r4 != 0) {
        // 0x80065700: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_8006570C;
    }
    // 0x80065700: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80065704: jr          $ra
    // 0x80065708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006570C:
    // 0x8006570C: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x80065710: beq         $t9, $zero, L_80065720
    if (ctx->r25 == 0) {
        // 0x80065714: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80065720;
    }
    // 0x80065714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80065718: jr          $ra
    // 0x8006571C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006571C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065720:
    // 0x80065720: jr          $ra
    // 0x80065724: nop

    return;
    // 0x80065724: nop

;}
RECOMP_FUNC void func_80516D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516D84: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80516D88: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80516D8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80516D90: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(279, 0X548) << 16);
    // 0x80516D94: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80516D98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80516D9C: lw          $t8, 0x6DB8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(279, 0X548));
    // 0x80516DA0: jr          $ra
    // 0x80516DA4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80516DA4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80516DA8: nop

    // 0x80516DAC: nop

;}
RECOMP_FUNC void func_804CE3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CE3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE3D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CE3D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CE3D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804CE3DC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804CE3E0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804CE3E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804CE3E8: bne         $v0, $at, L_804CE3F8
    if (ctx->r2 != ctx->r1) {
        // 0x804CE3EC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_804CE3F8;
    }
    // 0x804CE3EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804CE3F0: jal         0x8002F6E4
    // 0x804CE3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x804CE3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_804CE3F8:
    // 0x804CE3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE3FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CE400: jr          $ra
    // 0x804CE404: nop

    return;
    // 0x804CE404: nop

;}
RECOMP_FUNC void func_807A5F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A5F28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A5F2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A5F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A5F34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A5F38: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x807A5F3C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x807A5F40: jal         0x80065ABC
    // 0x807A5F44: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x807A5F44: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x807A5F48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807A5F4C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x807A5F50: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807A5F54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807A5F58: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807A5F5C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1540) << 16);
    // 0x807A5F60: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x807A5F64: nop

    // 0x807A5F68: bc1fl       L_807A5F78
    if (!c1cs) {
        // 0x807A5F6C: lwc1        $f6, 0x48($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
            goto L_807A5F78;
    }
    goto skip_0;
    // 0x807A5F6C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x807A5F70: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x807A5F74: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
L_807A5F78:
    // 0x807A5F78: lwc1        $f8, 0x7240($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1540));
    // 0x807A5F7C: jal         0x800659EC
    // 0x807A5F80: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x807A5F80: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x807A5F84: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x807A5F88: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1544) << 16);
    // 0x807A5F8C: lwc1        $f16, 0x7244($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1544));
    // 0x807A5F90: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x807A5F94: jal         0x800659EC
    // 0x807A5F98: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_800659EC(rdram, ctx);
        goto after_2;
    // 0x807A5F98: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_2:
    // 0x807A5F9C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x807A5FA0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1548) << 16);
    // 0x807A5FA4: lwc1        $f4, 0x7248($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1548));
    // 0x807A5FA8: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807A5FAC: jal         0x800659EC
    // 0x807A5FB0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800659EC(rdram, ctx);
        goto after_3;
    // 0x807A5FB0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_3:
    // 0x807A5FB4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X154C) << 16);
    // 0x807A5FB8: lwc1        $f12, 0x724C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X154C));
    // 0x807A5FBC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x807A5FC0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1550) << 16);
    // 0x807A5FC4: lwc1        $f8, 0x7250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1550));
    // 0x807A5FC8: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807A5FCC: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807A5FD0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807A5FD4: nop

    // 0x807A5FD8: bc1fl       L_807A5FF0
    if (!c1cs) {
        // 0x807A5FDC: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_807A5FF0;
    }
    goto skip_1;
    // 0x807A5FDC: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x807A5FE0: swc1        $f12, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f12.u32l;
    // 0x807A5FE4: b           L_807A5FF4
    // 0x807A5FE8: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
        goto L_807A5FF4;
    // 0x807A5FE8: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
    // 0x807A5FEC: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
L_807A5FF0:
    // 0x807A5FF0: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
L_807A5FF4:
    // 0x807A5FF4: jal         0x807A5E50
    // 0x807A5FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A5E50(rdram, ctx);
        goto after_4;
    // 0x807A5FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807A5FFC: beql        $v0, $zero, L_807A6010
    if (ctx->r2 == 0) {
        // 0x807A6000: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A6010;
    }
    goto skip_2;
    // 0x807A6000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807A6004: jal         0x800447C8
    // 0x807A6008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x807A6008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807A600C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A6010:
    // 0x807A6010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A6014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807A6018: jr          $ra
    // 0x807A601C: nop

    return;
    // 0x807A601C: nop

;}
RECOMP_FUNC void func_80460954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460954: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80460958: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8046095C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80460960: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80460964: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80460968: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8046096C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80460970:
    // 0x80460970: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80460974: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80460978: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8046097C: nop

    // 0x80460980: bc1fl       L_80460994
    if (!c1cs) {
        // 0x80460984: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80460994;
    }
    goto skip_0;
    // 0x80460984: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80460988: b           L_804609A4
    // 0x8046098C: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
        goto L_804609A4;
    // 0x8046098C: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80460990: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80460994:
    // 0x80460994: nop

    // 0x80460998: bc1f        L_804609A4
    if (!c1cs) {
        // 0x8046099C: nop
    
            goto L_804609A4;
    }
    // 0x8046099C: nop

    // 0x804609A0: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
L_804609A4:
    // 0x804609A4: bne         $v1, $v0, L_80460970
    if (ctx->r3 != ctx->r2) {
        // 0x804609A8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80460970;
    }
    // 0x804609A8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804609AC: jr          $ra
    // 0x804609B0: nop

    return;
    // 0x804609B0: nop

;}
RECOMP_FUNC void func_80566060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566060: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80566064: addiu       $at, $zero, 0x41A6
    ctx->r1 = ADD32(0, 0X41A6);
    // 0x80566068: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(372, 0X2C8) << 16);
    // 0x8056606C: bne         $t6, $at, L_80566080
    if (ctx->r14 != ctx->r1) {
        // 0x80566070: addiu       $v0, $v0, 0x6328
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(372, 0X2C8));
            goto L_80566080;
    }
    // 0x80566070: addiu       $v0, $v0, 0x6328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(372, 0X2C8));
    // 0x80566074: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(372, 0X2C8) << 16);
    // 0x80566078: jr          $ra
    // 0x8056607C: addiu       $v0, $v0, 0x6328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(372, 0X2C8));
    return;
    // 0x8056607C: addiu       $v0, $v0, 0x6328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(372, 0X2C8));
L_80566080:
    // 0x80566080: jr          $ra
    // 0x80566084: nop

    return;
    // 0x80566084: nop

;}
