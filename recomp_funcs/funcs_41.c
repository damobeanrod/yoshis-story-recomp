#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80429DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429DE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80429DE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80429DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80429DEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80429DF0: jal         0x80051194
    // 0x80429DF4: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80429DF4: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80429DF8: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80429DFC: jal         0x8042A3E0
    // 0x80429E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042A3E0(rdram, ctx);
        goto after_1;
    // 0x80429E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80429E04: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80429E08: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(47, 0X290) << 16);
    // 0x80429E0C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80429E10: addiu       $t6, $t6, -0x5FA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(47, 0X290));
    // 0x80429E14: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x80429E18: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(47, 0X9D0) << 16);
    // 0x80429E1C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x80429E20: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x80429E24: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80429E28: addiu       $t8, $t8, -0x5860
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(47, 0X9D0));
    // 0x80429E2C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80429E30: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80429E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80429E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80429E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80429E40: jal         0x8042A5A4
    // 0x80429E44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042A5A4(rdram, ctx);
        goto after_2;
    // 0x80429E44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80429E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80429E4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80429E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80429E54: jr          $ra
    // 0x80429E58: nop

    return;
    // 0x80429E58: nop

;}
RECOMP_FUNC void func_8006F49C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006F4A4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8006F4A8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8006F4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4B0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8006F4B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F4B8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8006F4BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006F4C0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F4C4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8006F4C8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8006F4CC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006F4D0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8006F4D4: lw          $t2, 0x7FDC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7FDC);
    // 0x8006F4D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8006F4DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8006F4E0: jal         0x8006F250
    // 0x8006F4E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006F250(rdram, ctx);
        goto after_0;
    // 0x8006F4E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F4E8: jal         0x8006F2AC
    // 0x8006F4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006F2AC(rdram, ctx);
        goto after_1;
    // 0x8006F4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006F4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F4F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F4F8: jr          $ra
    // 0x8006F4FC: nop

    return;
    // 0x8006F4FC: nop

;}
RECOMP_FUNC void func_806F678C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F678C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F6798: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806F679C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806F67A0: jal         0x80067BBC
    // 0x806F67A4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806F67A4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806F67A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806F67AC: jal         0x80067818
    // 0x806F67B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806F67B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806F67B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F67B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F67BC: jr          $ra
    // 0x806F67C0: nop

    return;
    // 0x806F67C0: nop

;}
RECOMP_FUNC void func_807B9D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9D04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B9D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9D0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9D10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807B9D14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B9D18: jal         0x807B8FC0
    // 0x807B9D1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807B8FC0(rdram, ctx);
        goto after_0;
    // 0x807B9D1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B9D20: jal         0x807B908C
    // 0x807B9D24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807B908C(rdram, ctx);
        goto after_1;
    // 0x807B9D24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x807B9D28: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9D2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B9D30: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x807B9D34: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x807B9D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B9D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9D40: jr          $ra
    // 0x807B9D44: nop

    return;
    // 0x807B9D44: nop

;}
RECOMP_FUNC void func_804216FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804216FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80421704: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80421708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042170C: beq         $t6, $zero, L_80421748
    if (ctx->r14 == 0) {
        // 0x80421710: nop
    
            goto L_80421748;
    }
    // 0x80421710: nop

    // 0x80421714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80421718: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042171C: jalr        $t9
    // 0x80421720: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80421720: nop

    after_0:
    // 0x80421724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80421728: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042172C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80421730: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80421734: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80421738: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042173C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80421740: b           L_80421748
    // 0x80421744: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80421748;
    // 0x80421744: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80421748:
    // 0x80421748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042174C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421750: jr          $ra
    // 0x80421754: nop

    return;
    // 0x80421754: nop

;}
RECOMP_FUNC void func_804CABD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CABD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CABD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CABDC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804CABE0: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(231, 0X1298) << 16);
    // 0x804CABE4: addiu       $t8, $t8, -0x4228
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(231, 0X1298));
    // 0x804CABE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CABEC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804CABF0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804CABF4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804CABF8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804CABFC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804CAC00: beql        $v1, $zero, L_804CAC38
    if (ctx->r3 == 0) {
        // 0x804CAC04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CAC38;
    }
    goto skip_0;
    // 0x804CAC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CAC08: jalr        $v1
    // 0x804CAC0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804CAC0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CAC10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CAC14: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804CAC18: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804CAC1C: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804CAC20: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804CAC24: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804CAC28: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804CAC2C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804CAC30: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804CAC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CAC38:
    // 0x804CAC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAC3C: jr          $ra
    // 0x804CAC40: nop

    return;
    // 0x804CAC40: nop

;}
RECOMP_FUNC void func_80002D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002D0C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80002D10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80002D14: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80002D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002D1C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80002D20: beq         $t6, $v0, L_80002D3C
    if (ctx->r14 == ctx->r2) {
        // 0x80002D24: sw          $a1, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r5;
            goto L_80002D3C;
    }
    // 0x80002D24: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80002D28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002D2C: beq         $t6, $at, L_80002D58
    if (ctx->r14 == ctx->r1) {
        // 0x80002D30: lw          $t8, 0xC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC);
            goto L_80002D58;
    }
    // 0x80002D30: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80002D34: b           L_80002FE0
    // 0x80002D38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80002FE0;
    // 0x80002D38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80002D3C:
    // 0x80002D3C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80002D40: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80002D44: addiu       $t0, $zero, 0x940
    ctx->r8 = ADD32(0, 0X940);
    // 0x80002D48: lbu         $a1, 0x3($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X3);
    // 0x80002D4C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80002D50: b           L_80002D78
    // 0x80002D54: sb          $a1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r5;
        goto L_80002D78;
    // 0x80002D54: sb          $a1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r5;
L_80002D58:
    // 0x80002D58: lbu         $a1, 0x4($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X4);
    // 0x80002D5C: lbu         $v1, 0x3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3);
    // 0x80002D60: addiu       $t0, $zero, 0xAE0
    ctx->r8 = ADD32(0, 0XAE0);
    // 0x80002D64: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80002D68: b           L_80002D78
    // 0x80002D6C: sb          $a1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r5;
        goto L_80002D78;
    // 0x80002D6C: sb          $a1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r5;
    // 0x80002D70: b           L_80002FE0
    // 0x80002D74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80002FE0;
    // 0x80002D74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80002D78:
    // 0x80002D78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80002D7C: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x80002D80: ori         $t7, $t7, 0x5C0
    ctx->r15 = ctx->r15 | 0X5C0;
    // 0x80002D84: beq         $t9, $v0, L_80002F04
    if (ctx->r25 == ctx->r2) {
        // 0x80002D88: lui         $at, 0x3C0
        ctx->r1 = S32(0X3C0 << 16);
            goto L_80002F04;
    }
    // 0x80002D88: lui         $at, 0x3C0
    ctx->r1 = S32(0X3C0 << 16);
    // 0x80002D8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80002D90: beq         $v1, $a1, L_80002E40
    if (ctx->r3 == ctx->r5) {
        // 0x80002D94: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80002E40;
    }
    // 0x80002D94: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80002D98: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
    // 0x80002D9C: subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
    // 0x80002DA0: andi        $t5, $t1, 0xFFFF
    ctx->r13 = ctx->r9 & 0XFFFF;
    // 0x80002DA4: lui         $at, 0x3C0
    ctx->r1 = S32(0X3C0 << 16);
    // 0x80002DA8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80002DAC: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x80002DB0: sll         $t7, $a3, 15
    ctx->r15 = S32(ctx->r7 << 15);
    // 0x80002DB4: ori         $t4, $t4, 0x5C0
    ctx->r12 = ctx->r12 | 0X5C0;
    // 0x80002DB8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80002DBC: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80002DC0: addiu       $t4, $t1, -0x2
    ctx->r12 = ADD32(ctx->r9, -0X2);
    // 0x80002DC4: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80002DC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002DCC: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x80002DD0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80002DD4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002DD8: bgez        $t7, L_80002DE8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80002DDC: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80002DE8;
    }
    // 0x80002DDC: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80002DE0: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80002DE4: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80002DE8:
    // 0x80002DE8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80002DEC: bgez        $t4, L_80002DFC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80002DF0: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_80002DFC;
    }
    // 0x80002DF0: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80002DF4: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x80002DF8: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80002DFC:
    // 0x80002DFC: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x80002E00: bne         $t5, $zero, L_80002E0C
    if (ctx->r13 != 0) {
        // 0x80002E04: nop
    
            goto L_80002E0C;
    }
    // 0x80002E04: nop

    // 0x80002E08: break       7
    do_break(2147495432);
L_80002E0C:
    // 0x80002E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002E10: bne         $t5, $at, L_80002E24
    if (ctx->r13 != ctx->r1) {
        // 0x80002E14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80002E24;
    }
    // 0x80002E14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002E18: bne         $t9, $at, L_80002E24
    if (ctx->r25 != ctx->r1) {
        // 0x80002E1C: nop
    
            goto L_80002E24;
    }
    // 0x80002E1C: nop

    // 0x80002E20: break       6
    do_break(2147495456);
L_80002E24:
    // 0x80002E24: mflo        $t6
    ctx->r14 = lo;
    // 0x80002E28: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80002E2C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80002E30: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x80002E34: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80002E38: b           L_80002E68
    // 0x80002E3C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
        goto L_80002E68;
    // 0x80002E3C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_80002E40:
    // 0x80002E40: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80002E44: lui         $t9, 0xA00
    ctx->r25 = S32(0XA00 << 16);
    // 0x80002E48: andi        $t5, $a3, 0xFFFF
    ctx->r13 = ctx->r7 & 0XFFFF;
    // 0x80002E4C: lui         $at, 0x3C0
    ctx->r1 = S32(0X3C0 << 16);
    // 0x80002E50: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80002E54: ori         $t9, $t9, 0x5C0
    ctx->r25 = ctx->r25 | 0X5C0;
    // 0x80002E58: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80002E5C: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80002E60: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002E64: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
L_80002E68:
    // 0x80002E68: beq         $v0, $zero, L_80002EE0
    if (ctx->r2 == 0) {
        // 0x80002E6C: lui         $t5, 0xA00
        ctx->r13 = S32(0XA00 << 16);
            goto L_80002EE0;
    }
    // 0x80002E6C: lui         $t5, 0xA00
    ctx->r13 = S32(0XA00 << 16);
    // 0x80002E70: addiu       $t7, $v0, 0xF
    ctx->r15 = ADD32(ctx->r2, 0XF);
    // 0x80002E74: andi        $t8, $t7, 0xFFF0
    ctx->r24 = ctx->r15 & 0XFFF0;
    // 0x80002E78: sra         $t4, $t8, 4
    ctx->r12 = S32(SIGNED(ctx->r24) >> 4);
    // 0x80002E7C: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x80002E80: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80002E84: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x80002E88: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80002E8C: ori         $t7, $t6, 0x5C0
    ctx->r15 = ctx->r14 | 0X5C0;
    // 0x80002E90: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80002E94: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80002E98: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80002E9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002EA0: ori         $at, $at, 0xA0
    ctx->r1 = ctx->r1 | 0XA0;
    // 0x80002EA4: addu        $t4, $t8, $at
    ctx->r12 = ADD32(ctx->r24, ctx->r1);
    // 0x80002EA8: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80002EAC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002EB0: lui         $t9, 0xA00
    ctx->r25 = S32(0XA00 << 16);
    // 0x80002EB4: ori         $t9, $t9, 0x3C0
    ctx->r25 = ctx->r25 | 0X3C0;
    // 0x80002EB8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80002EBC: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
    // 0x80002EC0: addiu       $t6, $v0, 0x5C0
    ctx->r14 = ADD32(ctx->r2, 0X5C0);
    // 0x80002EC4: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80002EC8: andi        $t4, $t8, 0xFFFF
    ctx->r12 = ctx->r24 & 0XFFFF;
    // 0x80002ECC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80002ED0: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x80002ED4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80002ED8: b           L_80002F5C
    // 0x80002EDC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_80002F5C;
    // 0x80002EDC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80002EE0:
    // 0x80002EE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80002EE4: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80002EE8: lui         $at, 0x5C0
    ctx->r1 = S32(0X5C0 << 16);
    // 0x80002EEC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80002EF0: ori         $t5, $t5, 0x3C0
    ctx->r13 = ctx->r13 | 0X3C0;
    // 0x80002EF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80002EF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80002EFC: b           L_80002F5C
    // 0x80002F00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_80002F5C;
    // 0x80002F00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80002F04:
    // 0x80002F04: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80002F08: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80002F0C: or          $t4, $v0, $at
    ctx->r12 = ctx->r2 | ctx->r1;
    // 0x80002F10: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002F14: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80002F18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80002F1C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80002F20: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002F24: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x80002F28: ori         $t9, $t9, 0x5C0
    ctx->r25 = ctx->r25 | 0X5C0;
    // 0x80002F2C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80002F30: addiu       $t8, $a1, 0x5C0
    ctx->r24 = ADD32(ctx->r5, 0X5C0);
    // 0x80002F34: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80002F38: sw          $a1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r5;
    // 0x80002F3C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80002F40: lui         $t5, 0xA00
    ctx->r13 = S32(0XA00 << 16);
    // 0x80002F44: ori         $t5, $t5, 0x3C0
    ctx->r13 = ctx->r13 | 0X3C0;
    // 0x80002F48: or          $t4, $t7, $v0
    ctx->r12 = ctx->r15 | ctx->r2;
    // 0x80002F4C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80002F50: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80002F54: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80002F58: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80002F5C:
    // 0x80002F5C: beq         $a1, $zero, L_80002FA8
    if (ctx->r5 == 0) {
        // 0x80002F60: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80002FA8;
    }
    // 0x80002F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80002F64: addiu       $t9, $a2, 0xF
    ctx->r25 = ADD32(ctx->r6, 0XF);
    // 0x80002F68: andi        $t5, $t9, 0xFFF0
    ctx->r13 = ctx->r25 & 0XFFF0;
    // 0x80002F6C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80002F70: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80002F74: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80002F78: addiu       $t9, $a3, 0x5C0
    ctx->r25 = ADD32(ctx->r7, 0X5C0);
    // 0x80002F7C: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x80002F80: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x80002F84: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80002F88: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80002F8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80002F90: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80002F94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002F98: ori         $at, $at, 0xA0
    ctx->r1 = ctx->r1 | 0XA0;
    // 0x80002F9C: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80002FA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80002FA4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80002FA8:
    // 0x80002FA8: addiu       $t9, $a3, 0x3F
    ctx->r25 = ADD32(ctx->r7, 0X3F);
    // 0x80002FAC: andi        $t4, $t9, 0xFFC0
    ctx->r12 = ctx->r25 & 0XFFC0;
    // 0x80002FB0: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x80002FB4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80002FB8: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80002FBC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80002FC0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80002FC4: lui         $at, 0x5C0
    ctx->r1 = S32(0X5C0 << 16);
    // 0x80002FC8: andi        $t4, $t0, 0xFFFF
    ctx->r12 = ctx->r8 & 0XFFFF;
    // 0x80002FCC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80002FD0: ori         $t9, $t7, 0x7FFF
    ctx->r25 = ctx->r15 | 0X7FFF;
    // 0x80002FD4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80002FD8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80002FDC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
L_80002FE0:
    // 0x80002FE0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80002FE4: jr          $ra
    // 0x80002FE8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80002FE8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80002FEC: nop

;}
RECOMP_FUNC void func_800716F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800716FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071700: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071704: addiu       $a0, $a0, -0x6340
    ctx->r4 = ADD32(ctx->r4, -0X6340);
    // 0x80071708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007170C: jal         0x800824B0
    // 0x80071710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071714: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80071718: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007171C: sw          $t6, -0x7AE4($at)
    MEM_W(-0X7AE4, ctx->r1) = ctx->r14;
    // 0x80071720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071728: jr          $ra
    // 0x8007172C: nop

    return;
    // 0x8007172C: nop

    // 0x80071730: nop

    // 0x80071734: nop

    // 0x80071738: nop

    // 0x8007173C: nop

;}
RECOMP_FUNC void func_80447F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447F3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447F40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447F48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447F4C: bne         $a2, $zero, L_80447F8C
    if (ctx->r6 != 0) {
        // 0x80447F50: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447F8C;
    }
    // 0x80447F50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447F54: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80447F58: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x80447F5C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80447F60: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80447F64: bne         $at, $zero, L_80447FCC
    if (ctx->r1 != 0) {
        // 0x80447F68: sw          $t7, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r15;
            goto L_80447FCC;
    }
    // 0x80447F68: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80447F6C: jal         0x80446384
    // 0x80447F70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_0;
    // 0x80447F70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80447F74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447F78: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447F7C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80447F80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447F84: b           L_80447FCC
    // 0x80447F88: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80447FCC;
    // 0x80447F88: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80447F8C:
    // 0x80447F8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447F90: bnel        $a2, $at, L_80447FBC
    if (ctx->r6 != ctx->r1) {
        // 0x80447F94: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447FBC;
    }
    goto skip_0;
    // 0x80447F94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447F98: jal         0x80446384
    // 0x80447F9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_1;
    // 0x80447F9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447FA0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447FA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447FA8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80447FAC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447FB0: b           L_80447FCC
    // 0x80447FB4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80447FCC;
    // 0x80447FB4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80447FB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447FBC:
    // 0x80447FBC: bnel        $a2, $at, L_80447FD0
    if (ctx->r6 != ctx->r1) {
        // 0x80447FC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447FD0;
    }
    goto skip_1;
    // 0x80447FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447FC4: jal         0x804463DC
    // 0x80447FC8: nop

    func_804463DC(rdram, ctx);
        goto after_2;
    // 0x80447FC8: nop

    after_2:
L_80447FCC:
    // 0x80447FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447FD0:
    // 0x80447FD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447FD8: jr          $ra
    // 0x80447FDC: nop

    return;
    // 0x80447FDC: nop

;}
RECOMP_FUNC void func_8078F86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F86C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078F870: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8078F874: beq         $v1, $zero, L_8078F880
    if (ctx->r3 == 0) {
        // 0x8078F878: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8078F880;
    }
    // 0x8078F878: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8078F87C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8078F880:
    // 0x8078F880: jr          $ra
    // 0x8078F884: nop

    return;
    // 0x8078F884: nop

;}
RECOMP_FUNC void func_8006BF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF50: jr          $ra
    // 0x8006BF54: nop

    return;
    // 0x8006BF54: nop

    // 0x8006BF58: nop

    // 0x8006BF5C: nop

;}
RECOMP_FUNC void func_80024FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024FE4: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80024FE8: addiu       $t6, $t6, 0x4E04
    ctx->r14 = ADD32(ctx->r14, 0X4E04);
    // 0x80024FEC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80024FF0: jr          $ra
    // 0x80024FF4: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80024FF4: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8002E4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E4F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E4F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E4F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002E4FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002E500: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E504: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002E508: jal         0x8002AFDC
    // 0x8002E50C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002AFDC(rdram, ctx);
        goto after_0;
    // 0x8002E50C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002E510: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002E514: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002E518: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8002E51C: addiu       $t7, $t7, 0x1F4
    ctx->r15 = ADD32(ctx->r15, 0X1F4);
    // 0x8002E520: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002E524: addiu       $a1, $a1, -0x3148
    ctx->r5 = ADD32(ctx->r5, -0X3148);
    // 0x8002E528: sb          $t6, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r14;
    // 0x8002E52C: sw          $t7, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r15;
    // 0x8002E530: addiu       $t8, $t8, 0x300
    ctx->r24 = ADD32(ctx->r24, 0X300);
    // 0x8002E534: sw          $t8, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r24;
    // 0x8002E538: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002E53C: jal         0x80028118
    // 0x8002E540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80028118(rdram, ctx);
        goto after_1;
    // 0x8002E540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8002E544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002E548: jal         0x800231C8
    // 0x8002E54C: lw          $a1, 0x138($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X138);
    func_800231C8(rdram, ctx);
        goto after_2;
    // 0x8002E54C: lw          $a1, 0x138($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X138);
    after_2:
    // 0x8002E550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002E554: jal         0x800227C4
    // 0x8002E558: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800227C4(rdram, ctx);
        goto after_3;
    // 0x8002E558: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8002E55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E560: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8002E564: jal         0x80036900
    // 0x8002E568: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80036900(rdram, ctx);
        goto after_4;
    // 0x8002E568: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x8002E56C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002E570: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8002E574: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8002E578: sw          $t9, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->r25;
    // 0x8002E57C: swc1        $f0, 0x12E4($s0)
    MEM_W(0X12E4, ctx->r16) = ctx->f0.u32l;
    // 0x8002E580: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8002E584: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x8002E588: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x8002E58C: sw          $zero, 0x12D0($s0)
    MEM_W(0X12D0, ctx->r16) = 0;
    // 0x8002E590: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x8002E594: addiu       $v0, $v0, 0x12C0
    ctx->r2 = ADD32(ctx->r2, 0X12C0);
    // 0x8002E598: slti        $at, $v0, 0x7081
    ctx->r1 = SIGNED(ctx->r2) < 0X7081 ? 1 : 0;
    // 0x8002E59C: bne         $at, $zero, L_8002E5A8
    if (ctx->r1 != 0) {
        // 0x8002E5A0: sw          $zero, 0x11C($s0)
        MEM_W(0X11C, ctx->r16) = 0;
            goto L_8002E5A8;
    }
    // 0x8002E5A0: sw          $zero, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = 0;
    // 0x8002E5A4: addiu       $v0, $zero, 0x7080
    ctx->r2 = ADD32(0, 0X7080);
L_8002E5A8:
    // 0x8002E5A8: sw          $v0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->r2;
    // 0x8002E5AC: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8002E5B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002E5B4: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x8002E5B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E5BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002E5C0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002E5C4: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x8002E5C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002E5CC: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8002E5D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002E5D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002E5D8: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x8002E5DC: jr          $ra
    // 0x8002E5E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002E5E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006823C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006823C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068240: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068244: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
    // 0x80068248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006824C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80068250: beq         $t6, $at, L_800682C4
    if (ctx->r14 == ctx->r1) {
        // 0x80068254: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800682C4;
    }
    // 0x80068254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068258: lw          $v1, 0x14E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14E8);
    // 0x8006825C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068260: beq         $v1, $zero, L_800682A4
    if (ctx->r3 == 0) {
        // 0x80068264: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800682A4;
    }
    // 0x80068264: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80068268: sw          $t7, 0x14E8($v0)
    MEM_W(0X14E8, ctx->r2) = ctx->r15;
    // 0x8006826C: jal         0x80067ACC
    // 0x80068270: lh          $a1, 0x14EA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14EA);
    func_80067ACC(rdram, ctx);
        goto after_0;
    // 0x80068270: lh          $a1, 0x14EA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X14EA);
    after_0:
    // 0x80068274: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068278: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006827C: lw          $t8, 0x14EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14EC);
    // 0x80068280: bnel        $t8, $zero, L_800682C8
    if (ctx->r24 != 0) {
        // 0x80068284: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800682C8;
    }
    goto skip_0;
    // 0x80068284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80068288: jal         0x800677F8
    // 0x8006828C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x8006828C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x80068290: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068294: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068298: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006829C: b           L_800682C4
    // 0x800682A0: sw          $t9, 0x14EC($v0)
    MEM_W(0X14EC, ctx->r2) = ctx->r25;
        goto L_800682C4;
    // 0x800682A0: sw          $t9, 0x14EC($v0)
    MEM_W(0X14EC, ctx->r2) = ctx->r25;
L_800682A4:
    // 0x800682A4: lw          $t0, 0x14EC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14EC);
    // 0x800682A8: beql        $t0, $zero, L_800682C8
    if (ctx->r8 == 0) {
        // 0x800682AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800682C8;
    }
    goto skip_1;
    // 0x800682AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800682B0: jal         0x800677F8
    // 0x800682B4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x800682B4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x800682B8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800682BC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800682C0: sw          $zero, 0x14EC($v0)
    MEM_W(0X14EC, ctx->r2) = 0;
L_800682C4:
    // 0x800682C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800682C8:
    // 0x800682C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800682CC: jr          $ra
    // 0x800682D0: nop

    return;
    // 0x800682D0: nop

;}
RECOMP_FUNC void func_8006ED48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006ED4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006ED50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006ED54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006ED58: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8006ED5C: jal         0x80048F84
    // 0x8006ED60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8006ED60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8006ED64: jal         0x8006E7F0
    // 0x8006ED68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E7F0(rdram, ctx);
        goto after_1;
    // 0x8006ED68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006ED6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006ED70: lwc1        $f4, 0x1188($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1188);
    // 0x8006ED74: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8006ED78: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006ED7C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006ED80: nop

    // 0x8006ED84: bc1fl       L_8006EDE4
    if (!c1cs) {
        // 0x8006ED88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006EDE4;
    }
    goto skip_0;
    // 0x8006ED88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006ED8C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8006ED90: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x8006ED94: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8006ED98: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006ED9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006EDA0: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x8006EDA4: jalr        $t9
    // 0x8006EDA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8006EDA8: nop

    after_2:
    // 0x8006EDAC: jal         0x800447C8
    // 0x8006EDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8006EDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8006EDB4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8006EDB8: jal         0x80067BBC
    // 0x8006EDBC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8006EDBC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8006EDC0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8006EDC4: jal         0x80067818
    // 0x8006EDC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8006EDC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8006EDCC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006EDD0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006EDD4: lw          $t8, 0xABC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XABC);
    // 0x8006EDD8: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8006EDDC: sw          $t0, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = ctx->r8;
    // 0x8006EDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006EDE4:
    // 0x8006EDE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EDE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006EDEC: jr          $ra
    // 0x8006EDF0: nop

    return;
    // 0x8006EDF0: nop

;}
RECOMP_FUNC void func_8003790C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003790C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037918: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003791C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037920: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80037924: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037928: lw          $t6, 0x78($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X78);
    // 0x8003792C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80037930: beql        $t6, $zero, L_80037C18
    if (ctx->r14 == 0) {
        // 0x80037934: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037C18;
    }
    goto skip_0;
    // 0x80037934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80037938: lh          $a0, 0xADE($a3)
    ctx->r4 = MEM_H(ctx->r7, 0XADE);
    // 0x8003793C: jal         0x8006593C
    // 0x80037940: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80037940: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80037944: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80037948: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8003794C: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80037950: lbu         $t7, 0x1F8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1F8);
    // 0x80037954: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80037958: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003795C: beq         $t7, $zero, L_80037A58
    if (ctx->r15 == 0) {
        // 0x80037960: sra         $t5, $t4, 16
        ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
            goto L_80037A58;
    }
    // 0x80037960: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80037964: lwc1        $f14, 0x114($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X114);
    // 0x80037968: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8003796C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80037970: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037974: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80037978: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003797C: bc1t        L_800379C4
    if (c1cs) {
        // 0x80037980: nop
    
            goto L_800379C4;
    }
    // 0x80037980: nop

    // 0x80037984: lwc1        $f4, 0x118($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X118);
    // 0x80037988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003798C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80037990: nop

    // 0x80037994: bc1t        L_800379C4
    if (c1cs) {
        // 0x80037998: nop
    
            goto L_800379C4;
    }
    // 0x80037998: nop

    // 0x8003799C: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x800379A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800379A4: jal         0x80040E24
    // 0x800379A8: sb          $t8, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r24;
    func_80040E24(rdram, ctx);
        goto after_1;
    // 0x800379A8: sb          $t8, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r24;
    after_1:
    // 0x800379AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800379B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800379B4: jal         0x8004115C
    // 0x800379B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_2;
    // 0x800379B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800379BC: b           L_80037C1C
    // 0x800379C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037C1C;
    // 0x800379C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800379C4:
    // 0x800379C4: beql        $t0, $zero, L_80037A00
    if (ctx->r8 == 0) {
        // 0x800379C8: lwc1        $f6, 0x10C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
            goto L_80037A00;
    }
    goto skip_1;
    // 0x800379C8: lwc1        $f6, 0x10C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
    skip_1:
    // 0x800379CC: lbu         $t1, 0xADC($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0XADC);
    // 0x800379D0: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x800379D4: beql        $t1, $t2, L_80037A00
    if (ctx->r9 == ctx->r10) {
        // 0x800379D8: lwc1        $f6, 0x10C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
            goto L_80037A00;
    }
    goto skip_2;
    // 0x800379D8: lwc1        $f6, 0x10C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
    skip_2:
    // 0x800379DC: jal         0x80040FD4
    // 0x800379E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_3;
    // 0x800379E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800379E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800379E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800379EC: jal         0x8004115C
    // 0x800379F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_4;
    // 0x800379F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800379F4: b           L_80037C1C
    // 0x800379F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037C1C;
    // 0x800379F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800379FC: lwc1        $f6, 0x10C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
L_80037A00:
    // 0x80037A00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037A04: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80037A08: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80037A0C: nop

    // 0x80037A10: bc1tl       L_80037C18
    if (c1cs) {
        // 0x80037A14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037C18;
    }
    goto skip_3;
    // 0x80037A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80037A18: lwc1        $f8, 0x11C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X11C);
    // 0x80037A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037A20: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80037A24: nop

    // 0x80037A28: bc1tl       L_80037C18
    if (c1cs) {
        // 0x80037A2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037C18;
    }
    goto skip_4;
    // 0x80037A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80037A30: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x80037A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80037A38: jal         0x80040E24
    // 0x80037A3C: sb          $t3, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r11;
    func_80040E24(rdram, ctx);
        goto after_5;
    // 0x80037A3C: sb          $t3, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r11;
    after_5:
    // 0x80037A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037A44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037A48: jal         0x8004115C
    // 0x80037A4C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_6;
    // 0x80037A4C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80037A50: b           L_80037C1C
    // 0x80037A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037C1C;
    // 0x80037A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037A58:
    // 0x80037A58: beql        $t5, $zero, L_80037AB0
    if (ctx->r13 == 0) {
        // 0x80037A5C: lwc1        $f10, 0x10C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
            goto L_80037AB0;
    }
    goto skip_5;
    // 0x80037A5C: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    skip_5:
    // 0x80037A60: lbu         $t6, 0xADC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XADC);
    // 0x80037A64: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x80037A68: beq         $t6, $t7, L_80037A80
    if (ctx->r14 == ctx->r15) {
        // 0x80037A6C: nop
    
            goto L_80037A80;
    }
    // 0x80037A6C: nop

    // 0x80037A70: jal         0x80040FD4
    // 0x80037A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_7;
    // 0x80037A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80037A78: b           L_80037A98
    // 0x80037A7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80037A98;
    // 0x80037A7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037A80:
    // 0x80037A80: jal         0x80040CE0
    // 0x80037A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040CE0(rdram, ctx);
        goto after_8;
    // 0x80037A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80037A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037A8C: jal         0x80040E24
    // 0x80037A90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80040E24(rdram, ctx);
        goto after_9;
    // 0x80037A90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80037A94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037A98:
    // 0x80037A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037A9C: jal         0x8004115C
    // 0x80037AA0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_10;
    // 0x80037AA0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80037AA4: b           L_80037C1C
    // 0x80037AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037C1C;
    // 0x80037AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037AAC: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
L_80037AB0:
    // 0x80037AB0: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037AB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037AB8: lwc1        $f14, 0x120($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X120);
    // 0x80037ABC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80037AC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037AC4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80037AC8: nop

    // 0x80037ACC: bc1tl       L_80037B20
    if (c1cs) {
        // 0x80037AD0: lwc1        $f12, 0x120($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
            goto L_80037B20;
    }
    goto skip_6;
    // 0x80037AD0: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    skip_6:
    // 0x80037AD4: lwc1        $f18, 0x124($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X124);
    // 0x80037AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037ADC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80037AE0: nop

    // 0x80037AE4: bc1tl       L_80037B20
    if (c1cs) {
        // 0x80037AE8: lwc1        $f12, 0x120($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
            goto L_80037B20;
    }
    goto skip_7;
    // 0x80037AE8: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    skip_7:
    // 0x80037AEC: jal         0x80040E24
    // 0x80037AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80040E24(rdram, ctx);
        goto after_11;
    // 0x80037AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80037AF4: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x80037AF8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80037AFC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80037B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037B04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037B08: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B0C: jal         0x8004115C
    // 0x80037B10: sb          $t8, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r24;
    func_8004115C(rdram, ctx);
        goto after_12;
    // 0x80037B10: sb          $t8, 0xADC($a3)
    MEM_B(0XADC, ctx->r7) = ctx->r24;
    after_12:
    // 0x80037B14: b           L_80037C1C
    // 0x80037B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037C1C;
    // 0x80037B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037B1C: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
L_80037B20:
    // 0x80037B20: jal         0x80066E88
    // 0x80037B24: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80066E88(rdram, ctx);
        goto after_13;
    // 0x80037B24: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_13:
    // 0x80037B28: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037B2C: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80037B30: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80037B34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037B38: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037B3C: lwc1        $f14, 0x128($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X128);
    // 0x80037B40: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80037B44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037B48: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80037B4C: add.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80037B50: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80037B54: nop

    // 0x80037B58: bc1tl       L_80037B78
    if (c1cs) {
        // 0x80037B5C: lwc1        $f6, 0x68($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X68);
            goto L_80037B78;
    }
    goto skip_8;
    // 0x80037B5C: lwc1        $f6, 0x68($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X68);
    skip_8:
    // 0x80037B60: lwc1        $f18, 0x12C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X12C);
    // 0x80037B64: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80037B68: nop

    // 0x80037B6C: bc1fl       L_80037C18
    if (!c1cs) {
        // 0x80037B70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037C18;
    }
    goto skip_9;
    // 0x80037B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_9:
    // 0x80037B74: lwc1        $f6, 0x68($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X68);
L_80037B78:
    // 0x80037B78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037B7C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80037B80: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80037B84: nop

    // 0x80037B88: bc1fl       L_80037BE8
    if (!c1cs) {
        // 0x80037B8C: lbu         $t0, 0x22($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X22);
            goto L_80037BE8;
    }
    goto skip_10;
    // 0x80037B8C: lbu         $t0, 0x22($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X22);
    skip_10:
    // 0x80037B90: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x80037B94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037B98: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037B9C: bne         $t9, $at, L_80037BC4
    if (ctx->r25 != ctx->r1) {
        // 0x80037BA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037BC4;
    }
    // 0x80037BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037BA4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037BA8: lw          $t9, -0x1024($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1024);
    // 0x80037BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037BB0: lbu         $a1, -0xFCB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCB);
    // 0x80037BB4: jalr        $t9
    // 0x80037BB8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x80037BB8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_14:
    // 0x80037BBC: b           L_80037C18
    // 0x80037BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037C18;
    // 0x80037BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037BC4:
    // 0x80037BC4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037BC8: lw          $t9, -0x1020($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1020);
    // 0x80037BCC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037BD0: lbu         $a1, -0xFCA($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCA);
    // 0x80037BD4: jalr        $t9
    // 0x80037BD8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_15;
    // 0x80037BD8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_15:
    // 0x80037BDC: b           L_80037C18
    // 0x80037BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037C18;
    // 0x80037BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037BE4: lbu         $t0, 0x22($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X22);
L_80037BE8:
    // 0x80037BE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037BF0: beq         $t0, $at, L_80037C0C
    if (ctx->r8 == ctx->r1) {
        // 0x80037BF4: lui         $t9, 0x800A
        ctx->r25 = S32(0X800A << 16);
            goto L_80037C0C;
    }
    // 0x80037BF4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037BF8: lw          $t9, -0xFF4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFF4);
    // 0x80037BFC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037C00: lbu         $a1, -0xFBF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFBF);
    // 0x80037C04: jalr        $t9
    // 0x80037C08: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x80037C08: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_16:
L_80037C0C:
    // 0x80037C0C: b           L_80037C18
    // 0x80037C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037C18;
    // 0x80037C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037C18:
    // 0x80037C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037C1C:
    // 0x80037C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037C20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80037C24: jr          $ra
    // 0x80037C28: nop

    return;
    // 0x80037C28: nop

;}
RECOMP_FUNC void func_8040D0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D0EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040D0F0: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(20, 0X1E44) << 16);
    // 0x8040D0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D0F8: addiu       $t6, $t6, -0x1BBC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(20, 0X1E44));
    // 0x8040D0FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8040D100: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // 0x8040D104: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8040D108: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8040D10C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8040D110: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8040D114: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8040D118: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8040D11C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8040D120: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8040D124: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8040D128: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8040D12C: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x8040D130: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8040D134: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x8040D138: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D13C: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x8040D140: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8040D144: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8040D148: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8040D14C: jalr        $t9
    // 0x8040D150: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040D150: nop

    after_0:
    // 0x8040D154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8040D15C: jr          $ra
    // 0x8040D160: nop

    return;
    // 0x8040D160: nop

;}
RECOMP_FUNC void func_80067F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F20: jal         0x80067CE4
    // 0x80067F24: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    func_80067CE4(rdram, ctx);
        goto after_0;
    // 0x80067F24: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_0:
    // 0x80067F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F30: jr          $ra
    // 0x80067F34: nop

    return;
    // 0x80067F34: nop

;}
RECOMP_FUNC void func_807A0FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A0FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A0FB8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807A0FBC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x807A0FC0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807A0FC4: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(841, 0XC58) << 16);
    // 0x807A0FC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A0FCC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x807A0FD0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807A0FD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807A0FD8: lw          $t8, 0x1B98($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(841, 0XC58));
    // 0x807A0FDC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807A0FE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807A0FE4: jal         0x80048490
    // 0x807A0FE8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x807A0FE8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x807A0FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A0FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A0FF4: jr          $ra
    // 0x807A0FF8: nop

    return;
    // 0x807A0FF8: nop

;}
RECOMP_FUNC void func_80463A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80463A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80463A84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80463A88: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80463A8C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80463A90: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X399C) << 16);
    // 0x80463A94: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80463A98: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80463A9C: addiu       $t7, $t7, 0x3F2C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X399C));
    // 0x80463AA0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80463AA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80463AA8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80463AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80463AB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80463AB4: jal         0x80463B20
    // 0x80463AB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80463B20(rdram, ctx);
        goto after_0;
    // 0x80463AB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80463ABC: jal         0x80463A1C
    // 0x80463AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80463A1C(rdram, ctx);
        goto after_1;
    // 0x80463AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80463AC4: bne         $v0, $zero, L_80463AD4
    if (ctx->r2 != 0) {
        // 0x80463AC8: lui         $t9, 0x8046
        ctx->r25 = S32(RELOC_HI16(122, 0X2F1C) << 16);
            goto L_80463AD4;
    }
    // 0x80463AC8: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(122, 0X2F1C) << 16);
    // 0x80463ACC: b           L_80463B0C
    // 0x80463AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80463B0C;
    // 0x80463AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80463AD4:
    // 0x80463AD4: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80463AD8: addiu       $t9, $t9, 0x34AC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(122, 0X2F1C));
    // 0x80463ADC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80463AE0: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x80463AE4: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80463AE8: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x80463AEC: jal         0x80463A64
    // 0x80463AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80463A64(rdram, ctx);
        goto after_2;
    // 0x80463AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80463AF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80463AF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80463AFC: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x80463B00: jal         0x80463314
    // 0x80463B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80463314(rdram, ctx);
        goto after_3;
    // 0x80463B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80463B08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80463B0C:
    // 0x80463B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80463B10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80463B14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80463B18: jr          $ra
    // 0x80463B1C: nop

    return;
    // 0x80463B1C: nop

;}
RECOMP_FUNC void func_8000BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFF4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000BFF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000BFFC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000C000: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000C004: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000C008: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000C00C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000C010: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000C014: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000C018: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000C01C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000C020: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000C024: jal         0x8000BE94
    // 0x8000C028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8000BE94(rdram, ctx);
        goto after_0;
    // 0x8000C028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000C02C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000C030: blez        $s3, L_8000C100
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8000C034: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000C100;
    }
    // 0x8000C034: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000C038: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8000C03C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8000C040: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8000C044: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8000C048: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
L_8000C04C:
    // 0x8000C04C: beql        $s4, $s6, L_8000C104
    if (ctx->r20 == ctx->r22) {
        // 0x8000C050: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8000C104;
    }
    goto skip_0;
    // 0x8000C050: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000C054: beq         $s4, $zero, L_8000C07C
    if (ctx->r20 == 0) {
        // 0x8000C058: nop
    
            goto L_8000C07C;
    }
    // 0x8000C058: nop

    // 0x8000C05C: beq         $s4, $s7, L_8000C08C
    if (ctx->r20 == ctx->r23) {
        // 0x8000C060: nop
    
            goto L_8000C08C;
    }
    // 0x8000C060: nop

    // 0x8000C064: beq         $s4, $fp, L_8000C09C
    if (ctx->r20 == ctx->r30) {
        // 0x8000C068: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000C09C;
    }
    // 0x8000C068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000C06C: beq         $s4, $at, L_8000C0AC
    if (ctx->r20 == ctx->r1) {
        // 0x8000C070: nop
    
            goto L_8000C0AC;
    }
    // 0x8000C070: nop

    // 0x8000C074: b           L_8000C0BC
    // 0x8000C078: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
        goto L_8000C0BC;
    // 0x8000C078: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
L_8000C07C:
    // 0x8000C07C: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000C080: addiu       $s1, $s1, -0x63B4
    ctx->r17 = ADD32(ctx->r17, -0X63B4);
    // 0x8000C084: b           L_8000C0B8
    // 0x8000C088: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
        goto L_8000C0B8;
    // 0x8000C088: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_8000C08C:
    // 0x8000C08C: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000C090: addiu       $s1, $s1, -0x63A4
    ctx->r17 = ADD32(ctx->r17, -0X63A4);
    // 0x8000C094: b           L_8000C0B8
    // 0x8000C098: addiu       $s2, $s5, 0x10
    ctx->r18 = ADD32(ctx->r21, 0X10);
        goto L_8000C0B8;
    // 0x8000C098: addiu       $s2, $s5, 0x10
    ctx->r18 = ADD32(ctx->r21, 0X10);
L_8000C09C:
    // 0x8000C09C: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000C0A0: addiu       $s1, $s1, -0x6394
    ctx->r17 = ADD32(ctx->r17, -0X6394);
    // 0x8000C0A4: b           L_8000C0B8
    // 0x8000C0A8: addiu       $s2, $s5, 0x20
    ctx->r18 = ADD32(ctx->r21, 0X20);
        goto L_8000C0B8;
    // 0x8000C0A8: addiu       $s2, $s5, 0x20
    ctx->r18 = ADD32(ctx->r21, 0X20);
L_8000C0AC:
    // 0x8000C0AC: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8000C0B0: addiu       $s1, $s1, -0x6384
    ctx->r17 = ADD32(ctx->r17, -0X6384);
    // 0x8000C0B4: addiu       $s2, $s5, 0x30
    ctx->r18 = ADD32(ctx->r21, 0X30);
L_8000C0B8:
    // 0x8000C0B8: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
L_8000C0BC:
    // 0x8000C0BC: beql        $at, $zero, L_8000C0F0
    if (ctx->r1 == 0) {
        // 0x8000C0C0: slt         $at, $s0, $s3
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8000C0F0;
    }
    goto skip_1;
    // 0x8000C0C0: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    skip_1:
L_8000C0C4:
    // 0x8000C0C4: jal         0x8000DBD4
    // 0x8000C0C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DBD4(rdram, ctx);
        goto after_1;
    // 0x8000C0C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8000C0CC: beq         $v0, $zero, L_8000C0EC
    if (ctx->r2 == 0) {
        // 0x8000C0D0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000C0EC;
    }
    // 0x8000C0D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C0D4: jal         0x8000DB94
    // 0x8000C0D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DB94(rdram, ctx);
        goto after_2;
    // 0x8000C0D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000C0DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C0E0: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000C0E4: bne         $at, $zero, L_8000C0C4
    if (ctx->r1 != 0) {
        // 0x8000C0E8: nop
    
            goto L_8000C0C4;
    }
    // 0x8000C0E8: nop

L_8000C0EC:
    // 0x8000C0EC: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
L_8000C0F0:
    // 0x8000C0F0: bne         $at, $zero, L_8000C04C
    if (ctx->r1 != 0) {
        // 0x8000C0F4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8000C04C;
    }
    // 0x8000C0F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000C0F8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8000C0FC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8000C100:
    // 0x8000C100: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000C104:
    // 0x8000C104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C108: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C10C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000C110: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000C114: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000C118: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C11C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000C120: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000C124: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000C128: jr          $ra
    // 0x8000C12C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000C12C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80450F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450F94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80450F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450F9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80450FA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80450FA4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80450FA8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450FAC: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80450FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80450FB4: lw          $t6, 0xA5C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XA5C);
    // 0x80450FB8: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80450FBC: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80450FC0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80450FC4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80450FC8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80450FCC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80450FD0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450FD4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450FD8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450FDC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450FE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80450FE4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450FE8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80450FEC: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80450FF0: addiu       $t1, $t0, 0xAE0
    ctx->r9 = ADD32(ctx->r8, 0XAE0);
    // 0x80450FF4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80450FF8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80450FFC: lw          $t2, 0x6A28($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A28);
    // 0x80451000: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80451004: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80451008: bne         $t2, $at, L_80451044
    if (ctx->r10 != ctx->r1) {
        // 0x8045100C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80451044;
    }
    // 0x8045100C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80451010: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80451014: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80451018: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8045101C: jal         0x8044EDC4
    // 0x80451020: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x80451020: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80451024: jal         0x8044F178
    // 0x80451028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F178(rdram, ctx);
        goto after_1;
    // 0x80451028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045102C: jal         0x8044DED8
    // 0x80451030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_2;
    // 0x80451030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80451034: jal         0x8044E684
    // 0x80451038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044E684(rdram, ctx);
        goto after_3;
    // 0x80451038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8045103C: b           L_8045106C
    // 0x80451040: nop

        goto L_8045106C;
    // 0x80451040: nop

L_80451044:
    // 0x80451044: jal         0x8044EEF8
    // 0x80451048: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EEF8(rdram, ctx);
        goto after_4;
    // 0x80451048: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8045104C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80451050: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451054: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80451058: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045105C: sw          $t3, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r11;
    // 0x80451060: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451064: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80451068: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
L_8045106C:
    // 0x8045106C: jal         0x8044FD5C
    // 0x80451070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_5;
    // 0x80451070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80451074: jal         0x80446D70
    // 0x80451078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_6;
    // 0x80451078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8045107C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80451080: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80451084: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80451088: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8045108C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80451090: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80451094: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80451098: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8045109C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x804510A0: sll         $t5, $t5, 8
    ctx->r13 = S32(ctx->r13 << 8);
    // 0x804510A4: addu        $a1, $s1, $t5
    ctx->r5 = ADD32(ctx->r17, ctx->r13);
    // 0x804510A8: jal         0x8044ED68
    // 0x804510AC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_7;
    // 0x804510AC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_7:
    // 0x804510B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x804510B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804510B8: jal         0x8044F384
    // 0x804510BC: sw          $t6, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r14;
    func_8044F384(rdram, ctx);
        goto after_8;
    // 0x804510BC: sw          $t6, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r14;
    after_8:
    // 0x804510C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804510C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804510C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804510CC: jr          $ra
    // 0x804510D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804510D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804BD44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD44C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BD450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BD454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BD458: jal         0x804BD568
    // 0x804BD45C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804BD568(rdram, ctx);
        goto after_0;
    // 0x804BD45C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804BD460: beq         $v0, $zero, L_804BD4C4
    if (ctx->r2 == 0) {
        // 0x804BD464: nop
    
            goto L_804BD4C4;
    }
    // 0x804BD464: nop

    // 0x804BD468: jal         0x804BD5A0
    // 0x804BD46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BD5A0(rdram, ctx);
        goto after_1;
    // 0x804BD46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BD470: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804BD474: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X3D78) << 16);
    // 0x804BD478: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804BD47C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804BD480: addiu       $t6, $t6, -0x958
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X3D78));
    // 0x804BD484: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804BD488: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804BD48C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804BD490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BD494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BD498: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BD49C: jal         0x804BED04
    // 0x804BD4A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804BED04(rdram, ctx);
        goto after_2;
    // 0x804BD4A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804BD4A4: jal         0x804BED60
    // 0x804BD4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BED60(rdram, ctx);
        goto after_3;
    // 0x804BD4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BD4AC: bnel        $v0, $zero, L_804BD4D0
    if (ctx->r2 != 0) {
        // 0x804BD4B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BD4D0;
    }
    goto skip_0;
    // 0x804BD4B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804BD4B4: jal         0x800445A4
    // 0x804BD4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x804BD4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BD4BC: b           L_804BD4D0
    // 0x804BD4C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804BD4D0;
    // 0x804BD4C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BD4C4:
    // 0x804BD4C4: jal         0x800445A4
    // 0x804BD4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804BD4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804BD4CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BD4D0:
    // 0x804BD4D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BD4D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BD4D8: jr          $ra
    // 0x804BD4DC: nop

    return;
    // 0x804BD4DC: nop

;}
RECOMP_FUNC void func_805666C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805666C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805666CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805666D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805666D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805666D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805666DC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x805666E0: addiu       $at, $zero, 0x4159
    ctx->r1 = ADD32(0, 0X4159);
    // 0x805666E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805666E8: beq         $v0, $at, L_8056671C
    if (ctx->r2 == ctx->r1) {
        // 0x805666EC: lw          $v1, 0x1F4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X1F4);
            goto L_8056671C;
    }
    // 0x805666EC: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x805666F0: addiu       $at, $zero, 0x4165
    ctx->r1 = ADD32(0, 0X4165);
    // 0x805666F4: beq         $v0, $at, L_8056671C
    if (ctx->r2 == ctx->r1) {
        // 0x805666F8: addiu       $at, $zero, 0x4171
        ctx->r1 = ADD32(0, 0X4171);
            goto L_8056671C;
    }
    // 0x805666F8: addiu       $at, $zero, 0x4171
    ctx->r1 = ADD32(0, 0X4171);
    // 0x805666FC: beq         $v0, $at, L_8056671C
    if (ctx->r2 == ctx->r1) {
        // 0x80566700: addiu       $at, $zero, 0x415A
        ctx->r1 = ADD32(0, 0X415A);
            goto L_8056671C;
    }
    // 0x80566700: addiu       $at, $zero, 0x415A
    ctx->r1 = ADD32(0, 0X415A);
    // 0x80566704: beq         $v0, $at, L_8056671C
    if (ctx->r2 == ctx->r1) {
        // 0x80566708: addiu       $at, $zero, 0x4166
        ctx->r1 = ADD32(0, 0X4166);
            goto L_8056671C;
    }
    // 0x80566708: addiu       $at, $zero, 0x4166
    ctx->r1 = ADD32(0, 0X4166);
    // 0x8056670C: beq         $v0, $at, L_8056671C
    if (ctx->r2 == ctx->r1) {
        // 0x80566710: addiu       $at, $zero, 0x4172
        ctx->r1 = ADD32(0, 0X4172);
            goto L_8056671C;
    }
    // 0x80566710: addiu       $at, $zero, 0x4172
    ctx->r1 = ADD32(0, 0X4172);
    // 0x80566714: bnel        $v0, $at, L_80566774
    if (ctx->r2 != ctx->r1) {
        // 0x80566718: addiu       $at, $zero, 0x417C
        ctx->r1 = ADD32(0, 0X417C);
            goto L_80566774;
    }
    goto skip_0;
    // 0x80566718: addiu       $at, $zero, 0x417C
    ctx->r1 = ADD32(0, 0X417C);
    skip_0:
L_8056671C:
    // 0x8056671C: lbu         $t6, 0x18($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X18);
    // 0x80566720: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80566724: beql        $t6, $at, L_80566758
    if (ctx->r14 == ctx->r1) {
        // 0x80566728: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80566758;
    }
    goto skip_1;
    // 0x80566728: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_1:
    // 0x8056672C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x80566730: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80566734: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80566738: jal         0x80067BBC
    // 0x8056673C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8056673C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80566740: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    // 0x80566744: jal         0x80067818
    // 0x80566748: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80566748: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8056674C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80566750: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80566754: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80566758:
    // 0x80566758: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x8056675C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80566760: jal         0x805670F4
    // 0x80566764: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80566764: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80566768: b           L_8056679C
    // 0x8056676C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8056679C;
    // 0x8056676C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566770: addiu       $at, $zero, 0x417C
    ctx->r1 = ADD32(0, 0X417C);
L_80566774:
    // 0x80566774: beq         $v0, $at, L_80566788
    if (ctx->r2 == ctx->r1) {
        // 0x80566778: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80566788;
    }
    // 0x80566778: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8056677C: addiu       $at, $zero, 0x417D
    ctx->r1 = ADD32(0, 0X417D);
    // 0x80566780: bnel        $v0, $at, L_8056679C
    if (ctx->r2 != ctx->r1) {
        // 0x80566784: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056679C;
    }
    goto skip_2;
    // 0x80566784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80566788:
    // 0x80566788: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8056678C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80566790: jal         0x805670F4
    // 0x80566794: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_805670F4(rdram, ctx);
        goto after_3;
    // 0x80566794: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80566798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056679C:
    // 0x8056679C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805667A0: jr          $ra
    // 0x805667A4: nop

    return;
    // 0x805667A4: nop

;}
RECOMP_FUNC void func_800243F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800243F8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800243FC: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80024400: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024404: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x80024408: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8002440C: lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X98);
    // 0x80024410: lbu         $a1, 0x17C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X17C);
    // 0x80024414: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x80024418: bnel        $t8, $at, L_8002444C
    if (ctx->r24 != ctx->r1) {
        // 0x8002441C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8002444C;
    }
    goto skip_0;
    // 0x8002441C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80024420: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x80024424: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80024428: bnel        $t9, $zero, L_8002444C
    if (ctx->r25 != 0) {
        // 0x8002442C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8002444C;
    }
    goto skip_1;
    // 0x8002442C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x80024430: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80024434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024438: nop

    // 0x8002443C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80024440: jr          $ra
    // 0x80024444: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80024444: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80024448: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8002444C:
    // 0x8002444C: bne         $a1, $at, L_80024490
    if (ctx->r5 != ctx->r1) {
        // 0x80024450: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80024490;
    }
    // 0x80024450: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80024454: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80024458: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x8002445C: beq         $at, $zero, L_800244D4
    if (ctx->r1 == 0) {
        // 0x80024460: sltu        $at, $v0, $v1
        ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
            goto L_800244D4;
    }
    // 0x80024460: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80024464: beq         $at, $zero, L_800244D4
    if (ctx->r1 == 0) {
        // 0x80024468: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_800244D4;
    }
    // 0x80024468: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8002446C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80024470: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80024474: lwc1        $f10, -0x6244($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6244);
    // 0x80024478: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8002447C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80024480: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80024484: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80024488: jr          $ra
    // 0x8002448C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8002448C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_80024490:
    // 0x80024490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024494: bne         $v0, $at, L_800244D4
    if (ctx->r2 != ctx->r1) {
        // 0x80024498: nop
    
            goto L_800244D4;
    }
    // 0x80024498: nop

    // 0x8002449C: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x800244A0: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800244A4: beq         $at, $zero, L_800244D4
    if (ctx->r1 == 0) {
        // 0x800244A8: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_800244D4;
    }
    // 0x800244A8: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800244AC: beq         $at, $zero, L_800244D4
    if (ctx->r1 == 0) {
        // 0x800244B0: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_800244D4;
    }
    // 0x800244B0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800244B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800244B8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800244BC: lwc1        $f8, -0x6244($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6244);
    // 0x800244C0: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800244C4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800244C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800244CC: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800244D0: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_800244D4:
    // 0x800244D4: jr          $ra
    // 0x800244D8: nop

    return;
    // 0x800244D8: nop

;}
RECOMP_FUNC void func_8006F408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F408: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F40C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006F414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F418: jal         0x80067E78
    // 0x8006F41C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x8006F41C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8006F420: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8006F424: jal         0x80067818
    // 0x8006F428: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8006F428: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8006F42C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8006F430: jal         0x80048F84
    // 0x8006F434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8006F434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8006F438: jal         0x8006E7F0
    // 0x8006F43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E7F0(rdram, ctx);
        goto after_3;
    // 0x8006F43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8006F440: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006F444: lwc1        $f4, 0x118C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X118C);
    // 0x8006F448: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8006F44C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006F450: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006F454: nop

    // 0x8006F458: bc1fl       L_8006F48C
    if (!c1cs) {
        // 0x8006F45C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006F48C;
    }
    goto skip_0;
    // 0x8006F45C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006F460: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8006F464: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x8006F468: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x8006F46C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006F470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006F474: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x8006F478: jalr        $t9
    // 0x8006F47C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8006F47C: nop

    after_4:
    // 0x8006F480: jal         0x800447C8
    // 0x8006F484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x8006F484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006F488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F48C:
    // 0x8006F48C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F494: jr          $ra
    // 0x8006F498: nop

    return;
    // 0x8006F498: nop

;}
RECOMP_FUNC void func_807C49C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C49C0: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(910, 0X8B4) << 16);
    // 0x807C49C4: addiu       $v0, $v0, 0x5274
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(910, 0X8B4));
    // 0x807C49C8: jr          $ra
    // 0x807C49CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807C49CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80519B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519B58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80519B5C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80519B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519B64: addiu       $t6, $zero, 0x69
    ctx->r14 = ADD32(0, 0X69);
    // 0x80519B68: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80519B6C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(291, 0X25D0) << 16);
    // 0x80519B70: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80519B74: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80519B78: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80519B7C: lw          $t8, -0x5DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(291, 0X25D0));
    // 0x80519B80: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
    // 0x80519B84: sw          $a2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r6;
    // 0x80519B88: sw          $a2, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r6;
    // 0x80519B8C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80519B90: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    // 0x80519B94: jal         0x80519078
    // 0x80519B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80519078(rdram, ctx);
        goto after_0;
    // 0x80519B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519B9C: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80519BA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80519BA4: bne         $a1, $zero, L_80519BCC
    if (ctx->r5 != 0) {
        // 0x80519BA8: nop
    
            goto L_80519BCC;
    }
    // 0x80519BA8: nop

    // 0x80519BAC: lw          $t9, 0x168($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X168);
    // 0x80519BB0: addiu       $t0, $zero, 0x19A
    ctx->r8 = ADD32(0, 0X19A);
    // 0x80519BB4: lw          $v0, 0x88($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X88);
    // 0x80519BB8: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x80519BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80519BC0: jal         0x8004590C
    // 0x80519BC4: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x80519BC4: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    after_1:
    // 0x80519BC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80519BCC:
    // 0x80519BCC: jal         0x80517EBC
    // 0x80519BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80517EBC(rdram, ctx);
        goto after_2;
    // 0x80519BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80519BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519BDC: jr          $ra
    // 0x80519BE0: nop

    return;
    // 0x80519BE0: nop

;}
RECOMP_FUNC void func_8066B24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B24C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066B250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B258: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8066B25C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B260: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B264: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8066B268: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8066B26C: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x8066B270: beql        $t8, $zero, L_8066B2A0
    if (ctx->r24 == 0) {
        // 0x8066B274: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8066B2A0;
    }
    goto skip_0;
    // 0x8066B274: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8066B278: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8066B27C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8066B280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B284: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8066B288: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8066B28C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8066B290: sb          $t9, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r25;
    // 0x8066B294: jal         0x8066B970
    // 0x8066B298: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_8066B970(rdram, ctx);
        goto after_0;
    // 0x8066B298: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_0:
    // 0x8066B29C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8066B2A0:
    // 0x8066B2A0: jal         0x8066AD18
    // 0x8066B2A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8066AD18(rdram, ctx);
        goto after_1;
    // 0x8066B2A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8066B2A8: jal         0x8066B1C4
    // 0x8066B2AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B1C4(rdram, ctx);
        goto after_2;
    // 0x8066B2AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8066B2B0: jal         0x8066B050
    // 0x8066B2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_3;
    // 0x8066B2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8066B2B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066B2BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B2C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066B2C4: jr          $ra
    // 0x8066B2C8: nop

    return;
    // 0x8066B2C8: nop

;}
RECOMP_FUNC void func_807919D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807919D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807919D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807919DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807919E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807919E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807919E8: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x807919EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807919F0: jal         0x807903C4
    // 0x807919F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x807919F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807919F8: jal         0x80790A1C
    // 0x807919FC: nop

    func_80790A1C(rdram, ctx);
        goto after_1;
    // 0x807919FC: nop

    after_1:
    // 0x80791A00: beq         $v0, $zero, L_80791A58
    if (ctx->r2 == 0) {
        // 0x80791A04: nop
    
            goto L_80791A58;
    }
    // 0x80791A04: nop

    // 0x80791A08: lw          $v0, 0x1E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1E4);
    // 0x80791A0C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80791A10: beq         $v0, $at, L_80791A58
    if (ctx->r2 == ctx->r1) {
        // 0x80791A14: nop
    
            goto L_80791A58;
    }
    // 0x80791A14: nop

    // 0x80791A18: beq         $v0, $zero, L_80791A58
    if (ctx->r2 == 0) {
        // 0x80791A1C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80791A58;
    }
    // 0x80791A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791A24: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80791A28: jal         0x8079393C
    // 0x80791A2C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791A2C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_2:
    // 0x80791A30: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80791A34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80791A38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80791A3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80791A40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80791A44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80791A48: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80791A4C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80791A50: b           L_80791A78
    // 0x80791A54: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
        goto L_80791A78;
    // 0x80791A54: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_80791A58:
    // 0x80791A58: jal         0x80790714
    // 0x80791A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80790714(rdram, ctx);
        goto after_3;
    // 0x80791A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80791A60: beq         $v0, $zero, L_80791A78
    if (ctx->r2 == 0) {
        // 0x80791A64: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80791A78;
    }
    // 0x80791A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791A6C: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80791A70: jal         0x8079393C
    // 0x80791A74: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8079393C(rdram, ctx);
        goto after_4;
    // 0x80791A74: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_4:
L_80791A78:
    // 0x80791A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791A7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80791A80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791A84: jr          $ra
    // 0x80791A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80791A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800038D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800038D4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800038D8: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800038DC: lw          $t6, 0x1F18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F18);
    // 0x800038E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800038E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800038E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800038EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800038F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800038F4: sw          $t6, 0x1F1C($v0)
    MEM_W(0X1F1C, ctx->r2) = ctx->r14;
    // 0x800038F8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800038FC: jal         0x80003698
    // 0x80003900: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x80003900: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    after_0:
    // 0x80003904: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003908: addiu       $a0, $a0, 0x6C4C
    ctx->r4 = ADD32(ctx->r4, 0X6C4C);
    // 0x8000390C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003910: jal         0x800036F0
    // 0x80003914: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x80003914: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80003918: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000391C: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    // 0x80003920: jal         0x80003698
    // 0x80003924: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80003698(rdram, ctx);
        goto after_2;
    // 0x80003924: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80003928: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000392C: addiu       $a0, $a0, 0x6D5C
    ctx->r4 = ADD32(ctx->r4, 0X6D5C);
    // 0x80003930: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003934: jal         0x800036F0
    // 0x80003938: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_800036F0(rdram, ctx);
        goto after_3;
    // 0x80003938: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8000393C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003940: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    // 0x80003944: jal         0x80003698
    // 0x80003948: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80003698(rdram, ctx);
        goto after_4;
    // 0x80003948: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x8000394C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003950: addiu       $a0, $a0, 0x6E6C
    ctx->r4 = ADD32(ctx->r4, 0X6E6C);
    // 0x80003954: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003958: jal         0x800036F0
    // 0x8000395C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800036F0(rdram, ctx);
        goto after_5;
    // 0x8000395C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_5:
    // 0x80003960: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003964: jal         0x80003718
    // 0x80003968: addiu       $a0, $a0, 0x6C48
    ctx->r4 = ADD32(ctx->r4, 0X6C48);
    func_80003718(rdram, ctx);
        goto after_6;
    // 0x80003968: addiu       $a0, $a0, 0x6C48
    ctx->r4 = ADD32(ctx->r4, 0X6C48);
    after_6:
    // 0x8000396C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003970: jal         0x80003718
    // 0x80003974: addiu       $a0, $a0, 0x6D58
    ctx->r4 = ADD32(ctx->r4, 0X6D58);
    func_80003718(rdram, ctx);
        goto after_7;
    // 0x80003974: addiu       $a0, $a0, 0x6D58
    ctx->r4 = ADD32(ctx->r4, 0X6D58);
    after_7:
    // 0x80003978: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000397C: jal         0x80003718
    // 0x80003980: addiu       $a0, $a0, 0x6E68
    ctx->r4 = ADD32(ctx->r4, 0X6E68);
    func_80003718(rdram, ctx);
        goto after_8;
    // 0x80003980: addiu       $a0, $a0, 0x6E68
    ctx->r4 = ADD32(ctx->r4, 0X6E68);
    after_8:
    // 0x80003984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000398C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003990: jr          $ra
    // 0x80003994: nop

    return;
    // 0x80003994: nop

;}
RECOMP_FUNC void func_807BBCC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBCC0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x807BBCC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807BBCC8: addiu       $t7, $t6, -0x4711
    ctx->r15 = ADD32(ctx->r14, -0X4711);
    // 0x807BBCCC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x807BBCD0: beq         $at, $zero, L_807BBD10
    if (ctx->r1 == 0) {
        // 0x807BBCD4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_807BBD10;
    }
    // 0x807BBCD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807BBCD8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6E90) << 16);
    // 0x807BBCDC: addu        $at, $at, $t7
    gpr jr_addend_807BBCE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807BBCE0: lw          $t7, 0x2B50($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(898, 0X6E90));
    // 0x807BBCE4: jr          $t7
    // 0x807BBCE8: nop

    switch (jr_addend_807BBCE4 >> 2) {
        case 0: goto L_807BBCEC; break;
        case 1: goto L_807BBCF8; break;
        case 2: goto L_807BBD04; break;
        case 3: goto L_807BBD04; break;
        case 4: goto L_807BBD04; break;
        default: switch_error(__func__, 0x807BBCE4, 0x807C2B50);
    }
    // 0x807BBCE8: nop

L_807BBCEC:
    // 0x807BBCEC: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(898, 0XEC) << 16);
    // 0x807BBCF0: jr          $ra
    // 0x807BBCF4: addiu       $v0, $v0, -0x4254
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0XEC));
    return;
    // 0x807BBCF4: addiu       $v0, $v0, -0x4254
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0XEC));
L_807BBCF8:
    // 0x807BBCF8: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(898, 0X854) << 16);
    // 0x807BBCFC: jr          $ra
    // 0x807BBD00: addiu       $v0, $v0, -0x3AEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0X854));
    return;
    // 0x807BBD00: addiu       $v0, $v0, -0x3AEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0X854));
L_807BBD04:
    // 0x807BBD04: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(898, 0XA44) << 16);
    // 0x807BBD08: jr          $ra
    // 0x807BBD0C: addiu       $v0, $v0, -0x38FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0XA44));
    return;
    // 0x807BBD0C: addiu       $v0, $v0, -0x38FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(898, 0XA44));
L_807BBD10:
    // 0x807BBD10: jr          $ra
    // 0x807BBD14: nop

    return;
    // 0x807BBD14: nop

;}
RECOMP_FUNC void func_806CCE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCE38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCE3C: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x806CCE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806CCE44: lh          $t6, 0x86E($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X86E);
    // 0x806CCE48: lh          $t7, 0x870($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X870);
    // 0x806CCE4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x806CCE50: sh          $t8, 0x86E($v1)
    MEM_H(0X86E, ctx->r3) = ctx->r24;
    // 0x806CCE54: lh          $t9, 0x86E($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X86E);
    // 0x806CCE58: slti        $at, $t9, 0x3E8
    ctx->r1 = SIGNED(ctx->r25) < 0X3E8 ? 1 : 0;
    // 0x806CCE5C: bne         $at, $zero, L_806CCE70
    if (ctx->r1 != 0) {
        // 0x806CCE60: nop
    
            goto L_806CCE70;
    }
    // 0x806CCE60: nop

    // 0x806CCE64: sh          $t0, 0x86E($v1)
    MEM_H(0X86E, ctx->r3) = ctx->r8;
    // 0x806CCE68: jr          $ra
    // 0x806CCE6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806CCE6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806CCE70:
    // 0x806CCE70: jr          $ra
    // 0x806CCE74: nop

    return;
    // 0x806CCE74: nop

;}
RECOMP_FUNC void func_804BF0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BF0AC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x804BF0B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804BF0B4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x804BF0B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x804BF0BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804BF0C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804BF0C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BF0C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804BF0CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804BF0D0: lwc1        $f0, 0xE8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x804BF0D4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804BF0D8: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X40E8) << 16);
    // 0x804BF0DC: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x804BF0E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BF0E4: addiu       $t6, $t6, -0x5E8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X40E8));
    // 0x804BF0E8: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x804BF0EC: bc1t        L_804BF104
    if (c1cs) {
        // 0x804BF0F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_804BF104;
    }
    // 0x804BF0F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804BF0F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BF0F8: nop

    // 0x804BF0FC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804BF100: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
L_804BF104:
    // 0x804BF104: beq         $s2, $zero, L_804BF32C
    if (ctx->r18 == 0) {
        // 0x804BF108: lui         $at, 0x42C0
        ctx->r1 = S32(0X42C0 << 16);
            goto L_804BF32C;
    }
    // 0x804BF108: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x804BF10C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x804BF110: lui         $t3, 0x804C
    ctx->r11 = S32(RELOC_HI16(191, 0X3D18) << 16);
    // 0x804BF114: addiu       $t3, $t3, -0x9B8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(191, 0X3D18));
    // 0x804BF118: beq         $v0, $zero, L_804BF128
    if (ctx->r2 == 0) {
        // 0x804BF11C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804BF128;
    }
    // 0x804BF11C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804BF120: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    // 0x804BF124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_804BF128:
    // 0x804BF128: lw          $t8, 0x1F4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1F4);
    // 0x804BF12C: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x804BF130: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x804BF134: lw          $t9, 0x370($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X370);
    // 0x804BF138: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x804BF13C: lw          $t7, 0x168($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X168);
    // 0x804BF140: lw          $t0, 0x168($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X168);
    // 0x804BF144: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x804BF148: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x804BF14C: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x804BF150: lw          $t1, 0x88($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X88);
    // 0x804BF154: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x804BF158: addu        $a1, $t5, $a2
    ctx->r5 = ADD32(ctx->r13, ctx->r6);
    // 0x804BF15C: jal         0x8004590C
    // 0x804BF160: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x804BF160: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    after_0:
    // 0x804BF164: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x804BF168: lw          $t6, 0x1F4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1F4);
    // 0x804BF16C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x804BF170: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x804BF174: lw          $a0, 0x370($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X370);
    // 0x804BF178: jal         0x8004590C
    // 0x804BF17C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x804BF17C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x804BF180: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804BF184: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x804BF188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BF18C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BF190: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x804BF194: nop

    // 0x804BF198: bc1tl       L_804BF1B4
    if (c1cs) {
        // 0x804BF19C: lwc1        $f0, 0x24($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
            goto L_804BF1B4;
    }
    goto skip_0;
    // 0x804BF19C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x804BF1A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BF1A4: nop

    // 0x804BF1A8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x804BF1AC: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x804BF1B0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_804BF1B4:
    // 0x804BF1B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BF1B8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x804BF1BC: nop

    // 0x804BF1C0: bc1t        L_804BF1D8
    if (c1cs) {
        // 0x804BF1C4: nop
    
            goto L_804BF1D8;
    }
    // 0x804BF1C4: nop

    // 0x804BF1C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BF1CC: nop

    // 0x804BF1D0: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x804BF1D4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_804BF1D8:
    // 0x804BF1D8: jal         0x804BE788
    // 0x804BF1DC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_804BE788(rdram, ctx);
        goto after_2;
    // 0x804BF1DC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x804BF1E0: bne         $v0, $zero, L_804BF1F4
    if (ctx->r2 != 0) {
        // 0x804BF1E4: lui         $at, 0x804C
        ctx->r1 = S32(RELOC_HI16(191, 0X421C) << 16);
            goto L_804BF1F4;
    }
    // 0x804BF1E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X421C) << 16);
    // 0x804BF1E8: lh          $t0, 0x36($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X36);
    // 0x804BF1EC: beq         $t0, $zero, L_804BF218
    if (ctx->r8 == 0) {
        // 0x804BF1F0: nop
    
            goto L_804BF218;
    }
    // 0x804BF1F0: nop

L_804BF1F4:
    // 0x804BF1F4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x804BF1F8: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X2714) << 16);
    // 0x804BF1FC: addiu       $t1, $t1, -0x1FBC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2714));
    // 0x804BF200: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x804BF204: lw          $v0, 0x1F4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1F4);
    // 0x804BF208: lwc1        $f6, 0x360($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X360);
    // 0x804BF20C: lwc1        $f8, 0x364($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X364);
    // 0x804BF210: swc1        $f6, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f6.u32l;
    // 0x804BF214: swc1        $f8, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f8.u32l;
L_804BF218:
    // 0x804BF218: lwc1        $f0, -0x4B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X421C));
    // 0x804BF21C: lwc1        $f10, 0x6C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x804BF220: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BF224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BF228: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804BF22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804BF230: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x804BF234: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804BF238: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BF23C: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x804BF240: lwc1        $f6, 0x70($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X70);
    // 0x804BF244: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BF248: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x804BF24C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804BF250: nop

    // 0x804BF254: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804BF258: jal         0x804BEF30
    // 0x804BF25C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    func_804BEF30(rdram, ctx);
        goto after_3;
    // 0x804BF25C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x804BF260: lh          $t3, 0xE4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE4);
    // 0x804BF264: bnel        $t3, $zero, L_804BF314
    if (ctx->r11 != 0) {
        // 0x804BF268: lw          $t9, 0x40($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X40);
            goto L_804BF314;
    }
    goto skip_1;
    // 0x804BF268: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x804BF26C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804BF270: lwc1        $f6, 0x50($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804BF274: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x804BF278: nop

    // 0x804BF27C: bc1fl       L_804BF314
    if (!c1cs) {
        // 0x804BF280: lw          $t9, 0x40($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X40);
            goto L_804BF314;
    }
    goto skip_2;
    // 0x804BF280: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    skip_2:
    // 0x804BF284: lw          $v0, 0x1E0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1E0);
    // 0x804BF288: bne         $v0, $zero, L_804BF30C
    if (ctx->r2 != 0) {
        // 0x804BF28C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_804BF30C;
    }
    // 0x804BF28C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x804BF290: lh          $t4, 0x2A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2A);
    // 0x804BF294: bnel        $t4, $zero, L_804BF314
    if (ctx->r12 != 0) {
        // 0x804BF298: lw          $t9, 0x40($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X40);
            goto L_804BF314;
    }
    goto skip_3;
    // 0x804BF298: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x804BF29C: lh          $t5, 0x36($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X36);
    // 0x804BF2A0: bnel        $t5, $zero, L_804BF314
    if (ctx->r13 != 0) {
        // 0x804BF2A4: lw          $t9, 0x40($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X40);
            goto L_804BF314;
    }
    goto skip_4;
    // 0x804BF2A4: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    skip_4:
    // 0x804BF2A8: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x804BF2AC: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X2714) << 16);
    // 0x804BF2B0: addiu       $t6, $t6, -0x1FBC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X2714));
    // 0x804BF2B4: beq         $t6, $v0, L_804BF310
    if (ctx->r14 == ctx->r2) {
        // 0x804BF2B8: lui         $t7, 0x804C
        ctx->r15 = S32(RELOC_HI16(191, 0X2B78) << 16);
            goto L_804BF310;
    }
    // 0x804BF2B8: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X2B78) << 16);
    // 0x804BF2BC: addiu       $t7, $t7, -0x1B58
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X2B78));
    // 0x804BF2C0: beq         $t7, $v0, L_804BF310
    if (ctx->r15 == ctx->r2) {
        // 0x804BF2C4: lui         $t8, 0x804C
        ctx->r24 = S32(RELOC_HI16(191, 0X21CC) << 16);
            goto L_804BF310;
    }
    // 0x804BF2C4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X21CC) << 16);
    // 0x804BF2C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x804BF2CC: addiu       $t8, $t8, -0x2504
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X21CC));
    // 0x804BF2D0: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x804BF2D4: lw          $v0, 0x1F4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X1F4);
    // 0x804BF2D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804BF2DC: lwc1        $f8, 0x360($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X360);
    // 0x804BF2E0: lwc1        $f10, 0x364($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X364);
    // 0x804BF2E4: swc1        $f8, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f8.u32l;
    // 0x804BF2E8: swc1        $f10, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f10.u32l;
    // 0x804BF2EC: sh          $t0, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r8;
    // 0x804BF2F0: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
    // 0x804BF2F4: jal         0x800653D8
    // 0x804BF2F8: sh          $t1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r9;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804BF2F8: sh          $t1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r9;
    after_4:
    // 0x804BF2FC: andi        $t2, $v0, 0x7F
    ctx->r10 = ctx->r2 & 0X7F;
    // 0x804BF300: addiu       $t3, $t2, 0x78
    ctx->r11 = ADD32(ctx->r10, 0X78);
    // 0x804BF304: b           L_804BF310
    // 0x804BF308: sw          $t3, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r11;
        goto L_804BF310;
    // 0x804BF308: sw          $t3, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r11;
L_804BF30C:
    // 0x804BF30C: sw          $t4, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r12;
L_804BF310:
    // 0x804BF310: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
L_804BF314:
    // 0x804BF314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BF318: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x804BF31C: jalr        $t9
    // 0x804BF320: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x804BF320: nop

    after_5:
    // 0x804BF324: b           L_804BF3C8
    // 0x804BF328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804BF3C8;
    // 0x804BF328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804BF32C:
    // 0x804BF32C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804BF330: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
L_804BF334:
    // 0x804BF334: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x804BF338: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x804BF33C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x804BF340: sw          $t8, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r24;
    // 0x804BF344: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x804BF348: sw          $t7, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r15;
    // 0x804BF34C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x804BF350: bne         $t6, $t0, L_804BF334
    if (ctx->r14 != ctx->r8) {
        // 0x804BF354: sw          $t8, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r24;
            goto L_804BF334;
    }
    // 0x804BF354: sw          $t8, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r24;
    // 0x804BF358: lwc1        $f16, 0x3C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x804BF35C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x804BF360: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x804BF364: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x804BF368: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x804BF36C: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x804BF370: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x804BF374: lwc1        $f4, 0x40($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X40);
    // 0x804BF378: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x804BF37C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x804BF380: lwc1        $f8, 0x44($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X44);
    // 0x804BF384: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x804BF388: lw          $t9, 0xF78($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XF78);
L_804BF38C:
    // 0x804BF38C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x804BF390: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804BF394: jalr        $t9
    // 0x804BF398: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x804BF398: nop

    after_6:
    // 0x804BF39C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x804BF3A0: bnel        $s0, $s2, L_804BF38C
    if (ctx->r16 != ctx->r18) {
        // 0x804BF3A4: lw          $t9, 0xF78($s1)
        ctx->r25 = MEM_W(ctx->r17, 0XF78);
            goto L_804BF38C;
    }
    goto skip_5;
    // 0x804BF3A4: lw          $t9, 0xF78($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XF78);
    skip_5:
    // 0x804BF3A8: jal         0x80067E68
    // 0x804BF3AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80067E68(rdram, ctx);
        goto after_7;
    // 0x804BF3AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x804BF3B0: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x804BF3B4: jal         0x80067818
    // 0x804BF3B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x804BF3B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x804BF3BC: jal         0x800447C8
    // 0x804BF3C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800447C8(rdram, ctx);
        goto after_9;
    // 0x804BF3C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x804BF3C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804BF3C8:
    // 0x804BF3C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804BF3CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804BF3D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x804BF3D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x804BF3D8: jr          $ra
    // 0x804BF3DC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x804BF3DC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_807B91E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B91E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807B91E4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x807B91E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B91EC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x807B91F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B91F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B91F8: lui         $s2, 0x807C
    ctx->r18 = S32(RELOC_HI16(886, 0X1D18) << 16);
    // 0x807B91FC: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x807B9200: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807B9204: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B9208: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B920C: addiu       $s5, $s5, 0x7EA0
    ctx->r21 = ADD32(ctx->r21, 0X7EA0);
    // 0x807B9210: addiu       $s2, $s2, -0x6078
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(886, 0X1D18));
    // 0x807B9214: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x807B9218: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x807B921C: addiu       $s6, $zero, 0x18
    ctx->r22 = ADD32(0, 0X18);
L_807B9220:
    // 0x807B9220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B9224: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_807B9228:
    // 0x807B9228: sh          $zero, 0xFE8($s1)
    MEM_H(0XFE8, ctx->r17) = 0;
    // 0x807B922C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B9230: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B9234: jal         0x80069684
    // 0x807B9238: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80069684(rdram, ctx);
        goto after_0;
    // 0x807B9238: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x807B923C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B9240: bne         $s0, $s3, L_807B9228
    if (ctx->r16 != ctx->r19) {
        // 0x807B9244: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_807B9228;
    }
    // 0x807B9244: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B9248: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x807B924C: bne         $s4, $s6, L_807B9220
    if (ctx->r20 != ctx->r22) {
        // 0x807B9250: addiu       $s5, $s5, 0x28
        ctx->r21 = ADD32(ctx->r21, 0X28);
            goto L_807B9220;
    }
    // 0x807B9250: addiu       $s5, $s5, 0x28
    ctx->r21 = ADD32(ctx->r21, 0X28);
    // 0x807B9254: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x807B9258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B925C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9260: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B9264: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B9268: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B926C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x807B9270: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x807B9274: jr          $ra
    // 0x807B9278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807B9278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807AC864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AC868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC86C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AC870: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x807AC874: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x807AC878: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x807AC87C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x807AC880: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807AC884: lwc1        $f6, 0x46C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x807AC888: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AC88C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807AC890: jal         0x800659EC
    // 0x807AC894: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x807AC894: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x807AC898: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AC89C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x807AC8A0: jal         0x807AC790
    // 0x807AC8A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_807AC790(rdram, ctx);
        goto after_1;
    // 0x807AC8A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807AC8A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AC8AC: jal         0x807AC7E0
    // 0x807AC8B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_807AC7E0(rdram, ctx);
        goto after_2;
    // 0x807AC8B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x807AC8B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x807AC8B8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x807AC8BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x807AC8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC8C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AC8C8: jr          $ra
    // 0x807AC8CC: nop

    return;
    // 0x807AC8CC: nop

;}
RECOMP_FUNC void func_805A431C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A431C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A4320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A4324: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A4328: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A432C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A4330: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x805A4334: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A4338: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A433C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805A4340: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x805A4344: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D94) << 16);
    // 0x805A4348: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x805A434C: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x805A4350: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x805A4354: sw          $t7, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r15;
    // 0x805A4358: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x805A435C: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x805A4360: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x805A4364: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x805A4368: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x805A436C: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x805A4370: lwc1        $f8, 0x5124($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D94));
    // 0x805A4374: jal         0x800653D8
    // 0x805A4378: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805A4378: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x805A437C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x805A4380: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x805A4384: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D98) << 16);
    // 0x805A4388: lwc1        $f18, 0x5128($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D98));
    // 0x805A438C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805A4390: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D9C) << 16);
    // 0x805A4394: lwc1        $f6, 0x512C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D9C));
    // 0x805A4398: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x805A439C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805A43A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805A43A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A43A8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x805A43AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A43B0: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x805A43B4: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    // 0x805A43B8: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x805A43BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A43C0: jal         0x800653D8
    // 0x805A43C4: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805A43C4: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x805A43C8: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x805A43CC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x805A43D0: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1DA0) << 16);
    // 0x805A43D4: lwc1        $f8, 0x5130($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1DA0));
    // 0x805A43D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805A43DC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1DA4) << 16);
    // 0x805A43E0: lwc1        $f16, 0x5134($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1DA4));
    // 0x805A43E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A43E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805A43EC: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x805A43F0: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x805A43F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805A43F8: jal         0x800653D8
    // 0x805A43FC: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805A43FC: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x805A4400: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x805A4404: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x805A4408: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D48) << 16);
    // 0x805A440C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x805A4410: lwc1        $f4, 0x50D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D48));
    // 0x805A4414: jal         0x800653D8
    // 0x805A4418: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x805A4418: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x805A441C: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x805A4420: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x805A4424: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1DA8) << 16);
    // 0x805A4428: lwc1        $f10, 0x5138($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1DA8));
    // 0x805A442C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A4430: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1DAC) << 16);
    // 0x805A4434: lwc1        $f18, 0x513C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1DAC));
    // 0x805A4438: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x805A443C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A4440: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A4444: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
    // 0x805A4448: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805A444C: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
    // 0x805A4450: jal         0x805A3690
    // 0x805A4454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805A3690(rdram, ctx);
        goto after_4;
    // 0x805A4454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x805A4458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A445C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A4460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A4464: jr          $ra
    // 0x805A4468: nop

    return;
    // 0x805A4468: nop

;}
RECOMP_FUNC void func_80462554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462554: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80462558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046255C: lw          $a2, 0x180($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X180);
    // 0x80462560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80462564: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80462568: jal         0x80045A34
    // 0x8046256C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8046256C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80462570: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80462574: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80462578: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8046257C: bne         $v0, $zero, L_8046258C
    if (ctx->r2 != 0) {
        // 0x80462580: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8046258C;
    }
    // 0x80462580: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80462584: b           L_804625C4
    // 0x80462588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804625C4;
    // 0x80462588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046258C:
    // 0x8046258C: bnel        $a2, $zero, L_804625A0
    if (ctx->r6 != 0) {
        // 0x80462590: lw          $v1, 0x1F4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X1F4);
            goto L_804625A0;
    }
    goto skip_0;
    // 0x80462590: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    skip_0:
    // 0x80462594: b           L_804625C4
    // 0x80462598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804625C4;
    // 0x80462598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046259C: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
L_804625A0:
    // 0x804625A0: bnel        $v1, $zero, L_804625B4
    if (ctx->r3 != 0) {
        // 0x804625A4: lwc1        $f4, 0x0($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
            goto L_804625B4;
    }
    goto skip_1;
    // 0x804625A4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x804625A8: b           L_804625C4
    // 0x804625AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804625C4;
    // 0x804625AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804625B0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
L_804625B4:
    // 0x804625B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804625B8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x804625BC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804625C0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
L_804625C4:
    // 0x804625C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804625C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804625CC: jr          $ra
    // 0x804625D0: nop

    return;
    // 0x804625D0: nop

;}
RECOMP_FUNC void func_805AE414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE414: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE418: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE41C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE420: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE424: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE428: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE42C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE430: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE434: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE438: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE43C: jr          $ra
    // 0x805AE440: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE440: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073EFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EFE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073EFEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EFF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073EFF4: jal         0x80047090
    // 0x8073EFF8: addiu       $a0, $zero, 0x4642
    ctx->r4 = ADD32(0, 0X4642);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073EFF8: addiu       $a0, $zero, 0x4642
    ctx->r4 = ADD32(0, 0X4642);
    after_0:
    // 0x8073EFFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073F000: lui         $at, 0x4642
    ctx->r1 = S32(0X4642 << 16);
    // 0x8073F004: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8073F008: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073F00C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073F010: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8073F014: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8073F018: jal         0x8004613C
    // 0x8073F01C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073F01C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8073F020: bne         $v0, $zero, L_8073F030
    if (ctx->r2 != 0) {
        // 0x8073F024: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8073F030;
    }
    // 0x8073F024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073F028: b           L_8073F060
    // 0x8073F02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073F060;
    // 0x8073F02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073F030:
    // 0x8073F030: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x8073F034: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8073F038: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8073F03C: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8073F040: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8073F044: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8073F048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073F04C: jal         0x80047F9C
    // 0x8073F050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8073F050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8073F054: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8073F058: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8073F05C: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
L_8073F060:
    // 0x8073F060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073F064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073F068: jr          $ra
    // 0x8073F06C: nop

    return;
    // 0x8073F06C: nop

;}
RECOMP_FUNC void func_8040EDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EDB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040EDB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040EDB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040EDBC: jal         0x8004700C
    // 0x8040EDC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8040EDC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EDC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8040EDC8: jal         0x8040ED0C
    // 0x8040EDCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8040ED0C(rdram, ctx);
        goto after_1;
    // 0x8040EDCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x8040EDD0: beq         $v0, $zero, L_8040EE1C
    if (ctx->r2 == 0) {
        // 0x8040EDD4: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8040EE1C;
    }
    // 0x8040EDD4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8040EDD8: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8040EDDC: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8040EDE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040EDE4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8040EDE8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040EDEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8040EDF0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8040EDF4: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8040EDF8: lwc1        $f10, 0x88($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8040EDFC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8040EE00: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8040EE04: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8040EE08: lwc1        $f4, 0x8C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8040EE0C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040EE10: jal         0x8002F6E4
    // 0x8040EE14: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x8040EE14: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8040EE18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8040EE1C:
    // 0x8040EE1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040EE20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040EE24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040EE28: jr          $ra
    // 0x8040EE2C: nop

    return;
    // 0x8040EE2C: nop

;}
RECOMP_FUNC void func_800078B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800078B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800078BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800078C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800078C4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800078C8: beq         $a0, $zero, L_800078F0
    if (ctx->r4 == 0) {
        // 0x800078CC: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_800078F0;
    }
    // 0x800078CC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800078D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800078D4: beq         $a0, $v0, L_80007918
    if (ctx->r4 == ctx->r2) {
        // 0x800078D8: lui         $t7, 0x800B
        ctx->r15 = S32(0X800B << 16);
            goto L_80007918;
    }
    // 0x800078D8: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800078DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800078E0: beq         $a0, $at, L_80007930
    if (ctx->r4 == ctx->r1) {
        // 0x800078E4: lui         $t8, 0x800B
        ctx->r24 = S32(0X800B << 16);
            goto L_80007930;
    }
    // 0x800078E4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800078E8: b           L_8000794C
    // 0x800078EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8000794C;
    // 0x800078EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800078F0:
    // 0x800078F0: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800078F4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800078F8: lbu         $t6, 0x76EC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X76EC);
    // 0x800078FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007900: bne         $t6, $at, L_80007910
    if (ctx->r14 != ctx->r1) {
        // 0x80007904: nop
    
            goto L_80007910;
    }
    // 0x80007904: nop

    // 0x80007908: b           L_80007B30
    // 0x8000790C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007B30;
    // 0x8000790C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007910:
    // 0x80007910: b           L_8000794C
    // 0x80007914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8000794C;
    // 0x80007914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80007918:
    // 0x80007918: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8000791C: lbu         $t7, 0x76A6($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X76A6);
    // 0x80007920: bnel        $v0, $t7, L_8000794C
    if (ctx->r2 != ctx->r15) {
        // 0x80007924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000794C;
    }
    goto skip_0;
    // 0x80007924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80007928: b           L_80007B30
    // 0x8000792C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007B30;
    // 0x8000792C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007930:
    // 0x80007930: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80007934: lbu         $t8, 0x7660($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7660);
    // 0x80007938: bnel        $v0, $t8, L_8000794C
    if (ctx->r2 != ctx->r24) {
        // 0x8000793C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000794C;
    }
    goto skip_1;
    // 0x8000793C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80007940: b           L_80007B30
    // 0x80007944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007B30;
    // 0x80007944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80007948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8000794C:
    // 0x8000794C: jal         0x800073F8
    // 0x80007950: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_800073F8(rdram, ctx);
        goto after_0;
    // 0x80007950: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80007954: beq         $v0, $zero, L_80007980
    if (ctx->r2 == 0) {
        // 0x80007958: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80007980;
    }
    // 0x80007958: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000795C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80007960: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80007964: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80007968: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000796C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007970: jal         0x80082210
    // 0x80007974: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80007974: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    after_1:
    // 0x80007978: b           L_80007ADC
    // 0x8000797C: nop

        goto L_80007ADC;
    // 0x8000797C: nop

L_80007980:
    // 0x80007980: jal         0x8000744C
    // 0x80007984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000744C(rdram, ctx);
        goto after_2;
    // 0x80007984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80007988: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8000798C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80007990: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80007994: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80007998: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x8000799C: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x800079A0: addiu       $t4, $t2, 0xF
    ctx->r12 = ADD32(ctx->r10, 0XF);
    // 0x800079A4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800079A8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800079AC: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800079B0: lb          $t6, 0x18($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X18);
    // 0x800079B4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800079B8: lb          $a0, 0x19($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X19);
    // 0x800079BC: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x800079C0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800079C4: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x800079C8: beq         $at, $zero, L_80007A88
    if (ctx->r1 == 0) {
        // 0x800079CC: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_80007A88;
    }
    // 0x800079CC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800079D0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800079D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800079D8: addu        $at, $at, $t9
    gpr jr_addend_800079E0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800079DC: lw          $t9, -0x43DC($at)
    ctx->r25 = ADD32(ctx->r1, -0X43DC);
    // 0x800079E0: jr          $t9
    // 0x800079E4: nop

    switch (jr_addend_800079E0 >> 2) {
        case 0: goto L_800079E8; break;
        case 1: goto L_80007A18; break;
        case 2: goto L_80007A3C; break;
        case 3: goto L_80007A60; break;
        case 4: goto L_80007A60; break;
        default: switch_error(__func__, 0x800079E0, 0x800ABC24);
    }
    // 0x800079E4: nop

L_800079E8:
    // 0x800079E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800079EC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800079F0: jal         0x80005698
    // 0x800079F4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_80005698(rdram, ctx);
        goto after_3;
    // 0x800079F4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x800079F8: bne         $v0, $zero, L_80007A08
    if (ctx->r2 != 0) {
        // 0x800079FC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80007A08;
    }
    // 0x800079FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80007A00: b           L_80007B34
    // 0x80007A04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80007B34;
    // 0x80007A04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80007A08:
    // 0x80007A08: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80007A0C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80007A10: b           L_80007A88
    // 0x80007A14: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
        goto L_80007A88;
    // 0x80007A14: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
L_80007A18:
    // 0x80007A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007A1C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80007A20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007A24: jal         0x80003A5C
    // 0x80007A28: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_80003A5C(rdram, ctx);
        goto after_4;
    // 0x80007A28: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x80007A2C: bne         $v0, $zero, L_80007A88
    if (ctx->r2 != 0) {
        // 0x80007A30: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80007A88;
    }
    // 0x80007A30: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80007A34: b           L_80007B34
    // 0x80007A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80007B34;
    // 0x80007A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80007A3C:
    // 0x80007A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007A40: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80007A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007A48: jal         0x80003A5C
    // 0x80007A4C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_80003A5C(rdram, ctx);
        goto after_5;
    // 0x80007A4C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_5:
    // 0x80007A50: bne         $v0, $zero, L_80007A88
    if (ctx->r2 != 0) {
        // 0x80007A54: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80007A88;
    }
    // 0x80007A54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80007A58: b           L_80007B34
    // 0x80007A5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80007B34;
    // 0x80007A5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80007A60:
    // 0x80007A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007A64: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80007A68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80007A6C: jal         0x80003A5C
    // 0x80007A70: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_80003A5C(rdram, ctx);
        goto after_6;
    // 0x80007A70: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x80007A74: bne         $v0, $zero, L_80007A84
    if (ctx->r2 != 0) {
        // 0x80007A78: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80007A84;
    }
    // 0x80007A78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80007A7C: b           L_80007B34
    // 0x80007A80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80007B34;
    // 0x80007A80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80007A84:
    // 0x80007A84: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
L_80007A88:
    // 0x80007A88: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80007A8C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80007A90: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80007A94: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80007A98: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x80007A9C: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x80007AA0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80007AA4: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80007AA8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80007AAC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80007AB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80007AB4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80007AB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80007ABC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80007AC0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80007AC4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80007AC8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80007ACC: jal         0x80008668
    // 0x80007AD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_80008668(rdram, ctx);
        goto after_7;
    // 0x80007AD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_7:
    // 0x80007AD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80007AD8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80007ADC:
    // 0x80007ADC: beq         $s0, $zero, L_80007B04
    if (ctx->r16 == 0) {
        // 0x80007AE0: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80007B04;
    }
    // 0x80007AE0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80007AE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007AE8: beq         $s0, $at, L_80007B14
    if (ctx->r16 == ctx->r1) {
        // 0x80007AEC: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80007B14;
    }
    // 0x80007AEC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80007AF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007AF4: beq         $s0, $at, L_80007B24
    if (ctx->r16 == ctx->r1) {
        // 0x80007AF8: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80007B24;
    }
    // 0x80007AF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80007AFC: b           L_80007B30
    // 0x80007B00: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_80007B30;
    // 0x80007B00: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80007B04:
    // 0x80007B04: jal         0x8000678C
    // 0x80007B08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8000678C(rdram, ctx);
        goto after_8;
    // 0x80007B08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80007B0C: b           L_80007B30
    // 0x80007B10: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_80007B30;
    // 0x80007B10: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80007B14:
    // 0x80007B14: jal         0x8000675C
    // 0x80007B18: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8000675C(rdram, ctx);
        goto after_9;
    // 0x80007B18: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80007B1C: b           L_80007B30
    // 0x80007B20: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_80007B30;
    // 0x80007B20: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80007B24:
    // 0x80007B24: jal         0x800067BC
    // 0x80007B28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800067BC(rdram, ctx);
        goto after_10;
    // 0x80007B28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80007B2C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80007B30:
    // 0x80007B30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80007B34:
    // 0x80007B34: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80007B38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80007B3C: jr          $ra
    // 0x80007B40: nop

    return;
    // 0x80007B40: nop

;}
RECOMP_FUNC void func_806EB364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EB368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EB36C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806EB370: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806EB374: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(670, 0XEF8) << 16);
    // 0x806EB378: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806EB37C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806EB380: addiu       $t7, $t7, -0x4938
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(670, 0XEF8));
    // 0x806EB384: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806EB388: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806EB38C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806EB390: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806EB394: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806EB398: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806EB39C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806EB3A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806EB3A4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806EB3A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806EB3AC: jal         0x80048378
    // 0x806EB3B0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806EB3B0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806EB3B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EB3B8: jal         0x80045A34
    // 0x806EB3BC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806EB3BC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x806EB3C0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806EB3C4: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x806EB3C8: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x806EB3CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EB3D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EB3D4: jr          $ra
    // 0x806EB3D8: nop

    return;
    // 0x806EB3D8: nop

;}
RECOMP_FUNC void func_80475AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475AB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475AB4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475AB8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475ABC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475AC0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475AC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475AC8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475ACC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475AD0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475AD4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475AD8: jr          $ra
    // 0x80475ADC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475ADC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80475EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475EE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475EE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475EE8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475EEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475EF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475EF4: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E48) << 16);
    // 0x80475EF8: addiu       $a2, $a2, -0x49F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E48));
    // 0x80475EFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80475F00: jal         0x80475B40
    // 0x80475F04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475F04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475F10: jr          $ra
    // 0x80475F14: nop

    return;
    // 0x80475F14: nop

;}
RECOMP_FUNC void func_8002F15C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F15C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F164: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002F168: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F16C: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8002F170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F174: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002F178: jal         0x8002B9E4
    // 0x8002F17C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002F17C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8002F180: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002F184: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F188: swc1        $f4, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f4.u32l;
    // 0x8002F18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F194: jr          $ra
    // 0x8002F198: nop

    return;
    // 0x8002F198: nop

;}
RECOMP_FUNC void func_8079C074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079C074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079C078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079C07C: jal         0x8079BFF4
    // 0x8079C080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079BFF4(rdram, ctx);
        goto after_0;
    // 0x8079C080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079C084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079C088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079C08C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8079C090: jal         0x8079C140
    // 0x8079C094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079C140(rdram, ctx);
        goto after_1;
    // 0x8079C094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8079C098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079C09C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079C0A0: jr          $ra
    // 0x8079C0A4: nop

    return;
    // 0x8079C0A4: nop

;}
RECOMP_FUNC void func_80475510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475510: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475514: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475518: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047551C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475520: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475524: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475528: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047552C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475530: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475534: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475538: jr          $ra
    // 0x8047553C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047553C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80680BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80680BF4: jal         0x80045A34
    // 0x80680BF8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80680BF8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80680BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80680C00: bne         $v0, $zero, L_80680C10
    if (ctx->r2 != 0) {
        // 0x80680C04: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80680C10;
    }
    // 0x80680C04: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80680C08: b           L_80680C1C
    // 0x80680C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680C1C;
    // 0x80680C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680C10:
    // 0x80680C10: jal         0x80680B90
    // 0x80680C14: nop

    func_80680B90(rdram, ctx);
        goto after_1;
    // 0x80680C14: nop

    after_1:
    // 0x80680C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80680C1C:
    // 0x80680C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80680C24: jr          $ra
    // 0x80680C28: nop

    return;
    // 0x80680C28: nop

;}
RECOMP_FUNC void func_80573F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80573F94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80573F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80573F9C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80573FA0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80573FA4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80573FA8: addiu       $at, $zero, 0x4035
    ctx->r1 = ADD32(0, 0X4035);
    // 0x80573FAC: beq         $v0, $at, L_80574050
    if (ctx->r2 == ctx->r1) {
        // 0x80573FB0: lw          $a1, 0xB30($a2)
        ctx->r5 = MEM_W(ctx->r6, 0XB30);
            goto L_80574050;
    }
    // 0x80573FB0: lw          $a1, 0xB30($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XB30);
    // 0x80573FB4: addiu       $at, $zero, 0x468C
    ctx->r1 = ADD32(0, 0X468C);
    // 0x80573FB8: beq         $v0, $at, L_80574050
    if (ctx->r2 == ctx->r1) {
        // 0x80573FBC: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80574050;
    }
    // 0x80573FBC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80573FC0: addiu       $at, $zero, 0x45BC
    ctx->r1 = ADD32(0, 0X45BC);
    // 0x80573FC4: beq         $v0, $at, L_80573FE0
    if (ctx->r2 == ctx->r1) {
        // 0x80573FC8: addiu       $a0, $v0, -0x4030
        ctx->r4 = ADD32(ctx->r2, -0X4030);
            goto L_80573FE0;
    }
    // 0x80573FC8: addiu       $a0, $v0, -0x4030
    ctx->r4 = ADD32(ctx->r2, -0X4030);
    // 0x80573FCC: addiu       $at, $zero, 0x45BF
    ctx->r1 = ADD32(0, 0X45BF);
    // 0x80573FD0: beq         $v0, $at, L_80573FE0
    if (ctx->r2 == ctx->r1) {
        // 0x80573FD4: addiu       $at, $zero, 0x45F3
        ctx->r1 = ADD32(0, 0X45F3);
            goto L_80573FE0;
    }
    // 0x80573FD4: addiu       $at, $zero, 0x45F3
    ctx->r1 = ADD32(0, 0X45F3);
    // 0x80573FD8: bnel        $v0, $at, L_80573FE8
    if (ctx->r2 != ctx->r1) {
        // 0x80573FDC: addu        $t7, $a2, $t6
        ctx->r15 = ADD32(ctx->r6, ctx->r14);
            goto L_80573FE8;
    }
    goto skip_0;
    // 0x80573FDC: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    skip_0:
L_80573FE0:
    // 0x80573FE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80573FE4: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
L_80573FE8:
    // 0x80573FE8: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80573FEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80573FF0: sw          $a0, 0xB34($t7)
    MEM_W(0XB34, ctx->r15) = ctx->r4;
    // 0x80573FF4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80573FF8: sh          $a0, -0x752C($at)
    MEM_H(-0X752C, ctx->r1) = ctx->r4;
    // 0x80573FFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80574000: slti        $at, $a1, 0x1E
    ctx->r1 = SIGNED(ctx->r5) < 0X1E ? 1 : 0;
    // 0x80574004: bnel        $at, $zero, L_80574050
    if (ctx->r1 != 0) {
        // 0x80574008: sw          $a1, 0xB30($a2)
        MEM_W(0XB30, ctx->r6) = ctx->r5;
            goto L_80574050;
    }
    goto skip_1;
    // 0x80574008: sw          $a1, 0xB30($a2)
    MEM_W(0XB30, ctx->r6) = ctx->r5;
    skip_1:
    // 0x8057400C: lw          $t9, 0xC28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC28);
    // 0x80574010: bnel        $t9, $zero, L_80574044
    if (ctx->r25 != 0) {
        // 0x80574014: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80574044;
    }
    goto skip_2;
    // 0x80574014: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_2:
    // 0x80574018: jal         0x80573F08
    // 0x8057401C: nop

    func_80573F08(rdram, ctx);
        goto after_0;
    // 0x8057401C: nop

    after_0:
    // 0x80574020: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80574024: beq         $v0, $zero, L_80574040
    if (ctx->r2 == 0) {
        // 0x80574028: addiu       $a2, $a2, 0x7EA0
        ctx->r6 = ADD32(ctx->r6, 0X7EA0);
            goto L_80574040;
    }
    // 0x80574028: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8057402C: addiu       $a0, $zero, 0xD9
    ctx->r4 = ADD32(0, 0XD9);
    // 0x80574030: jal         0x80067818
    // 0x80574034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80574034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80574038: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8057403C: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
L_80574040:
    // 0x80574040: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80574044:
    // 0x80574044: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80574048: sw          $t0, 0xC28($a2)
    MEM_W(0XC28, ctx->r6) = ctx->r8;
    // 0x8057404C: sw          $a1, 0xB30($a2)
    MEM_W(0XB30, ctx->r6) = ctx->r5;
L_80574050:
    // 0x80574050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80574054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80574058: jr          $ra
    // 0x8057405C: nop

    return;
    // 0x8057405C: nop

;}
RECOMP_FUNC void func_8041F594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041F598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041F59C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F5A0: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8041F5A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8041F5A8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8041F5AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8041F5B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8041F5B4: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x8041F5B8: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8041F5BC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8041F5C0: nop

    // 0x8041F5C4: bc1fl       L_8041F5F4
    if (!c1cs) {
        // 0x8041F5C8: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8041F5F4;
    }
    goto skip_0;
    // 0x8041F5C8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x8041F5CC: lwc1        $f0, 0xE0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8041F5D0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8041F5D4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8041F5D8: nop

    // 0x8041F5DC: bc1fl       L_8041F5F4
    if (!c1cs) {
        // 0x8041F5E0: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8041F5F4;
    }
    goto skip_1;
    // 0x8041F5E0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x8041F5E4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8041F5E8: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8041F5EC: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8041F5F0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_8041F5F4:
    // 0x8041F5F4: addiu       $a0, $a1, 0xC4
    ctx->r4 = ADD32(ctx->r5, 0XC4);
    // 0x8041F5F8: bc1f        L_8041F61C
    if (!c1cs) {
        // 0x8041F5FC: nop
    
            goto L_8041F61C;
    }
    // 0x8041F5FC: nop

    // 0x8041F600: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8041F604: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8041F608: nop

    // 0x8041F60C: bc1f        L_8041F61C
    if (!c1cs) {
        // 0x8041F610: nop
    
            goto L_8041F61C;
    }
    // 0x8041F610: nop

    // 0x8041F614: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8041F618: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
L_8041F61C:
    // 0x8041F61C: jal         0x80048F84
    // 0x8041F620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8041F620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8041F624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041F628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041F62C: jr          $ra
    // 0x8041F630: nop

    return;
    // 0x8041F630: nop

;}
RECOMP_FUNC void func_800611C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800611C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800611C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800611C8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800611CC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800611D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800611D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800611D8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800611DC: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x800611E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800611E4: lh          $s1, 0x184($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X184);
    // 0x800611E8: addiu       $s2, $s3, 0x188
    ctx->r18 = ADD32(ctx->r19, 0X188);
    // 0x800611EC: beql        $s1, $zero, L_80061298
    if (ctx->r17 == 0) {
        // 0x800611F0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80061298;
    }
    goto skip_0;
    // 0x800611F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800611F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800611F8: nop

L_800611FC:
    // 0x800611FC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80061200: beq         $v0, $zero, L_8006128C
    if (ctx->r2 == 0) {
        // 0x80061204: nop
    
            goto L_8006128C;
    }
    // 0x80061204: nop

    // 0x80061208: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x8006120C: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80061210: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80061214: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80061218: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006121C: beq         $t6, $zero, L_8006128C
    if (ctx->r14 == 0) {
        // 0x80061220: sw          $t6, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r14;
            goto L_8006128C;
    }
    // 0x80061220: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x80061224: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80061228: bne         $s3, $t7, L_8006128C
    if (ctx->r19 != ctx->r15) {
        // 0x8006122C: nop
    
            goto L_8006128C;
    }
    // 0x8006122C: nop

    // 0x80061230: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80061234: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x80061238: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8006123C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80061240: nop

    // 0x80061244: bc1fl       L_80061264
    if (!c1cs) {
        // 0x80061248: lw          $t8, 0x40($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X40);
            goto L_80061264;
    }
    goto skip_1;
    // 0x80061248: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x8006124C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80061250: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80061254: nop

    // 0x80061258: bc1t        L_80061284
    if (c1cs) {
        // 0x8006125C: nop
    
            goto L_80061284;
    }
    // 0x8006125C: nop

    // 0x80061260: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
L_80061264:
    // 0x80061264: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80061268: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x8006126C: bne         $t0, $zero, L_80061284
    if (ctx->r8 != 0) {
        // 0x80061270: nop
    
            goto L_80061284;
    }
    // 0x80061270: nop

    // 0x80061274: jal         0x80060274
    // 0x80061278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060274(rdram, ctx);
        goto after_0;
    // 0x80061278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006127C: bne         $v0, $zero, L_8006128C
    if (ctx->r2 != 0) {
        // 0x80061280: nop
    
            goto L_8006128C;
    }
    // 0x80061280: nop

L_80061284:
    // 0x80061284: jal         0x80060F6C
    // 0x80061288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060F6C(rdram, ctx);
        goto after_1;
    // 0x80061288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8006128C:
    // 0x8006128C: bne         $s1, $zero, L_800611FC
    if (ctx->r17 != 0) {
        // 0x80061290: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800611FC;
    }
    // 0x80061290: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80061294: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80061298:
    // 0x80061298: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8006129C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800612A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800612A4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800612A8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800612AC: jr          $ra
    // 0x800612B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800612B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80465C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465C8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80465C90: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x80465C94: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80465C98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80465C9C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80465CA0: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80465CA4: jr          $ra
    // 0x80465CA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x80465CA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_807AF480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AF484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF488: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AF48C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(865, 0X468) << 16);
    // 0x807AF490: lwc1        $f4, -0xA98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(865, 0X468));
    // 0x807AF494: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x807AF498: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x807AF49C: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x807AF4A0: lwc1        $f2, 0x78($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X78);
    // 0x807AF4A4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807AF4A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x807AF4AC: nop

    // 0x807AF4B0: bc1fl       L_807AF4E8
    if (!c1cs) {
        // 0x807AF4B4: swc1        $f0, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
            goto L_807AF4E8;
    }
    goto skip_0;
    // 0x807AF4B4: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x807AF4B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807AF4BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AF4C0: jal         0x807AF508
    // 0x807AF4C4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_807AF508(rdram, ctx);
        goto after_0;
    // 0x807AF4C4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x807AF4C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AF4CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807AF4D0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807AF4D4: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x807AF4D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807AF4DC: sw          $t6, 0x1E0($t7)
    MEM_W(0X1E0, ctx->r15) = ctx->r14;
    // 0x807AF4E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x807AF4E4: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
L_807AF4E8:
    // 0x807AF4E8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AF4EC: swc1        $f0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f0.u32l;
    // 0x807AF4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF4F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AF4F8: jr          $ra
    // 0x807AF4FC: nop

    return;
    // 0x807AF4FC: nop

;}
RECOMP_FUNC void func_807A6E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6E1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6E24: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A6E28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6E2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807A6E30: blez        $v0, L_807A6E40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A6E34: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A6E40;
    }
    // 0x807A6E34: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A6E38: b           L_807A6E50
    // 0x807A6E3C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807A6E50;
    // 0x807A6E3C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807A6E40:
    // 0x807A6E40: jal         0x807A7138
    // 0x807A6E44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A7138(rdram, ctx);
        goto after_0;
    // 0x807A6E44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A6E4C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_807A6E50:
    // 0x807A6E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A6E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6E58: jr          $ra
    // 0x807A6E5C: nop

    return;
    // 0x807A6E5C: nop

;}
RECOMP_FUNC void func_804CF198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF1A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CF1A4: jal         0x80047090
    // 0x804CF1A8: addiu       $a0, $zero, 0x4126
    ctx->r4 = ADD32(0, 0X4126);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804CF1A8: addiu       $a0, $zero, 0x4126
    ctx->r4 = ADD32(0, 0X4126);
    after_0:
    // 0x804CF1AC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804CF1B0: bne         $v0, $at, L_804CF1C0
    if (ctx->r2 != ctx->r1) {
        // 0x804CF1B4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804CF1C0;
    }
    // 0x804CF1B4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804CF1B8: b           L_804CF230
    // 0x804CF1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF230;
    // 0x804CF1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CF1C0:
    // 0x804CF1C0: lui         $at, 0x4126
    ctx->r1 = S32(0X4126 << 16);
    // 0x804CF1C4: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x804CF1C8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804CF1CC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804CF1D0: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x804CF1D4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x804CF1D8: jal         0x8004613C
    // 0x804CF1DC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804CF1DC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804CF1E0: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804CF1E4: bne         $v0, $zero, L_804CF1F4
    if (ctx->r2 != 0) {
        // 0x804CF1E8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804CF1F4;
    }
    // 0x804CF1E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CF1EC: b           L_804CF230
    // 0x804CF1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF230;
    // 0x804CF1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CF1F4:
    // 0x804CF1F4: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804CF1F8: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804CF1FC: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804CF200: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804CF204: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804CF208: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CF20C: jal         0x80047F9C
    // 0x804CF210: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804CF210: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804CF214: jal         0x804CEC28
    // 0x804CF218: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_804CEC28(rdram, ctx);
        goto after_3;
    // 0x804CF218: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804CF21C: bnel        $v0, $zero, L_804CF230
    if (ctx->r2 != 0) {
        // 0x804CF220: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804CF230;
    }
    goto skip_0;
    // 0x804CF220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804CF224: b           L_804CF230
    // 0x804CF228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF230;
    // 0x804CF228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804CF22C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CF230:
    // 0x804CF230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CF238: jr          $ra
    // 0x804CF23C: nop

    return;
    // 0x804CF23C: nop

;}
RECOMP_FUNC void func_80463384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463384: jr          $ra
    // 0x80463388: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80463388: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80780200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780200: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80780204: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80780208: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8078020C: nop

    // 0x80780210: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80780214: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80780218: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8078021C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80780220: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80780224: nop

    // 0x80780228: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8078022C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80780230: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x80780234: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80780238: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8078023C: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80780240: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80780244: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80780248: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8078024C: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80780250: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x80780254: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    // 0x80780258: jr          $ra
    // 0x8078025C: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    return;
    // 0x8078025C: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805594F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805594F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805594FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80559500: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80559504: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80559508: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8055950C: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80559510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80559514: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80559518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8055951C: bc1f        L_8055956C
    if (!c1cs) {
        // 0x80559520: nop
    
            goto L_8055956C;
    }
    // 0x80559520: nop

    // 0x80559524: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80559528: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8055952C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x80559530: jal         0x80047534
    // 0x80559534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80047534(rdram, ctx);
        goto after_0;
    // 0x80559534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80559538: beq         $v0, $zero, L_80559564
    if (ctx->r2 == 0) {
        // 0x8055953C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80559564;
    }
    // 0x8055953C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80559540: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80559544: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80559548: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8055954C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80559550: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80559554: nop

    // 0x80559558: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8055955C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80559560: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80559564:
    // 0x80559564: b           L_805595A4
    // 0x80559568: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
        goto L_805595A4;
    // 0x80559568: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_8055956C:
    // 0x8055956C: jal         0x800474D8
    // 0x80559570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800474D8(rdram, ctx);
        goto after_1;
    // 0x80559570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80559574: beq         $v0, $zero, L_805595A0
    if (ctx->r2 == 0) {
        // 0x80559578: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805595A0;
    }
    // 0x80559578: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8055957C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80559580: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80559584: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80559588: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8055958C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80559590: nop

    // 0x80559594: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80559598: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8055959C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_805595A0:
    // 0x805595A0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_805595A4:
    // 0x805595A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805595A8: addiu       $a2, $zero, 0xF0
    ctx->r6 = ADD32(0, 0XF0);
    // 0x805595AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805595B0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x805595B4: nop

    // 0x805595B8: bc1f        L_805595F8
    if (!c1cs) {
        // 0x805595BC: nop
    
            goto L_805595F8;
    }
    // 0x805595BC: nop

    // 0x805595C0: jal         0x800475EC
    // 0x805595C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800475EC(rdram, ctx);
        goto after_2;
    // 0x805595C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x805595C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805595CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805595D0: beql        $v0, $zero, L_80559630
    if (ctx->r2 == 0) {
        // 0x805595D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80559630;
    }
    goto skip_0;
    // 0x805595D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805595D8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x805595DC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x805595E0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805595E4: nop

    // 0x805595E8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805595EC: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x805595F0: b           L_8055962C
    // 0x805595F4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
        goto L_8055962C;
    // 0x805595F4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_805595F8:
    // 0x805595F8: jal         0x80047590
    // 0x805595FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80047590(rdram, ctx);
        goto after_3;
    // 0x805595FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80559600: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80559604: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80559608: beql        $v0, $zero, L_80559630
    if (ctx->r2 == 0) {
        // 0x8055960C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80559630;
    }
    goto skip_1;
    // 0x8055960C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80559610: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80559614: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80559618: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8055961C: nop

    // 0x80559620: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80559624: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80559628: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_8055962C:
    // 0x8055962C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80559630:
    // 0x80559630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80559634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80559638: jr          $ra
    // 0x8055963C: nop

    return;
    // 0x8055963C: nop

;}
RECOMP_FUNC void func_8041011C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041011C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410120: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80410124: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80410128: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8041012C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410130: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80410134: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80410138: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8041013C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410140: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80410144: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x80410148: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8041014C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80410150: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80410154: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80410158: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041015C: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x80410160: ori         $t4, $t4, 0x2C80
    ctx->r12 = ctx->r12 | 0X2C80;
    // 0x80410164: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80410168: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8041016C: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x80410170: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80410174: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80410178: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041017C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80410180: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x80410184: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80410188: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8041018C: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x80410190: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80410194: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410198: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8041019C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804101A0: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x804101A4: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x804101A8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804101AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804101B0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x804101B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804101B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804101BC: lui         $t1, 0xFC12
    ctx->r9 = S32(0XFC12 << 16);
    // 0x804101C0: ori         $t1, $t1, 0x7E24
    ctx->r9 = ctx->r9 | 0X7E24;
    // 0x804101C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804101C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804101CC: addiu       $t2, $zero, -0x604
    ctx->r10 = ADD32(0, -0X604);
    // 0x804101D0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x804101D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804101D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804101DC: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x804101E0: addiu       $t4, $zero, 0x204
    ctx->r12 = ADD32(0, 0X204);
    // 0x804101E4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x804101E8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x804101EC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x804101F0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804101F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804101F8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x804101FC: lui         $t6, 0xBB00
    ctx->r14 = S32(0XBB00 << 16);
    // 0x80410200: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80410204: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80410208: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x8041020C: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80410210: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80410214: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80410218: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041021C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x80410220: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410224: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410228: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8041022C: jr          $ra
    // 0x80410230: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    return;
    // 0x80410230: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_804C3FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3FF0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(209, 0XC40) << 16);
    // 0x804C3FF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804C3FF8: jr          $ra
    // 0x804C3FFC: addiu       $v0, $v0, 0x4C30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(209, 0XC40));
    return;
    // 0x804C3FFC: addiu       $v0, $v0, 0x4C30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(209, 0XC40));
;}
RECOMP_FUNC void func_8004281C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004281C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80042820: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80042824: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80042828: beql        $t7, $zero, L_80042878
    if (ctx->r15 == 0) {
        // 0x8004282C: sw          $zero, 0x50($a0)
        MEM_W(0X50, ctx->r4) = 0;
            goto L_80042878;
    }
    goto skip_0;
    // 0x8004282C: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    skip_0:
    // 0x80042830: lwc1        $f0, -0x7678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80042834: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042838: lwc1        $f4, 0x310($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X310);
    // 0x8004283C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042840: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80042844: nop

    // 0x80042848: bc1tl       L_80042878
    if (c1cs) {
        // 0x8004284C: sw          $zero, 0x50($a0)
        MEM_W(0X50, ctx->r4) = 0;
            goto L_80042878;
    }
    goto skip_1;
    // 0x8004284C: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    skip_1:
    // 0x80042850: lwc1        $f6, 0x314($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X314);
    // 0x80042854: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80042858: nop

    // 0x8004285C: bc1tl       L_80042878
    if (c1cs) {
        // 0x80042860: sw          $zero, 0x50($a0)
        MEM_W(0X50, ctx->r4) = 0;
            goto L_80042878;
    }
    goto skip_2;
    // 0x80042860: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    skip_2:
    // 0x80042864: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80042868: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004286C: jr          $ra
    // 0x80042870: sw          $v0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r2;
    return;
    // 0x80042870: sw          $v0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r2;
    // 0x80042874: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
L_80042878:
    // 0x80042878: jr          $ra
    // 0x8004287C: nop

    return;
    // 0x8004287C: nop

;}
RECOMP_FUNC void func_800488F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800488F8: lw          $a2, 0x15C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X15C);
    // 0x800488FC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80048900: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x80048904: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80048908: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8004890C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80048910: divu        $zero, $v1, $t6
    lo = S32(U32(ctx->r3) / U32(ctx->r14)); hi = S32(U32(ctx->r3) % U32(ctx->r14));
    // 0x80048914: mflo        $a1
    ctx->r5 = lo;
    // 0x80048918: addiu       $t9, $t9, -0x778C
    ctx->r25 = ADD32(ctx->r25, -0X778C);
    // 0x8004891C: bne         $t6, $zero, L_80048928
    if (ctx->r14 != 0) {
        // 0x80048920: nop
    
            goto L_80048928;
    }
    // 0x80048920: nop

    // 0x80048924: break       7
    do_break(2147780900);
L_80048928:
    // 0x80048928: divu        $zero, $a1, $t7
    lo = S32(U32(ctx->r5) / U32(ctx->r15)); hi = S32(U32(ctx->r5) % U32(ctx->r15));
    // 0x8004892C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80048930: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    // 0x80048934: bne         $t7, $zero, L_80048940
    if (ctx->r15 != 0) {
        // 0x80048938: nop
    
            goto L_80048940;
    }
    // 0x80048938: nop

    // 0x8004893C: break       7
    do_break(2147780924);
L_80048940:
    // 0x80048940: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80048944: jr          $ra
    // 0x80048948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80048948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8004E124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E12C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E130: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E134: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004E138: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004E13C: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004E140: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004E144: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004E148: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E14C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8004E150: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8004E154: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8004E158: beq         $t2, $zero, L_8004E1D8
    if (ctx->r10 == 0) {
        // 0x8004E15C: sh          $t2, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r10;
            goto L_8004E1D8;
    }
    // 0x8004E15C: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    // 0x8004E160: beq         $t2, $at, L_8004E1D8
    if (ctx->r10 == ctx->r1) {
        // 0x8004E164: lbu         $v0, 0x1A($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X1A);
            goto L_8004E1D8;
    }
    // 0x8004E164: lbu         $v0, 0x1A($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1A);
    // 0x8004E168: andi        $v1, $v0, 0xF8
    ctx->r3 = ctx->r2 & 0XF8;
    // 0x8004E16C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E170: beq         $v1, $at, L_8004E1D8
    if (ctx->r3 == ctx->r1) {
        // 0x8004E174: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E1D8;
    }
    // 0x8004E174: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E178: beql        $v1, $at, L_8004E1DC
    if (ctx->r3 == ctx->r1) {
        // 0x8004E17C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E1DC;
    }
    goto skip_0;
    // 0x8004E17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E180: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8004E184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E188: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8004E18C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004E190: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8004E194: nop

    // 0x8004E198: bc1t        L_8004E1B0
    if (c1cs) {
        // 0x8004E19C: nop
    
            goto L_8004E1B0;
    }
    // 0x8004E19C: nop

    // 0x8004E1A0: bne         $t3, $zero, L_8004E1B0
    if (ctx->r11 != 0) {
        // 0x8004E1A4: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_8004E1B0;
    }
    // 0x8004E1A4: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8004E1A8: bnel        $t4, $zero, L_8004E1DC
    if (ctx->r12 != 0) {
        // 0x8004E1AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E1DC;
    }
    goto skip_1;
    // 0x8004E1AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8004E1B0:
    // 0x8004E1B0: jal         0x8004CEC4
    // 0x8004E1B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8004CEC4(rdram, ctx);
        goto after_0;
    // 0x8004E1B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8004E1B8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E1BC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004E1C0: lbu         $t6, 0x14($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X14);
    // 0x8004E1C4: beql        $t6, $zero, L_8004E1DC
    if (ctx->r14 == 0) {
        // 0x8004E1C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E1DC;
    }
    goto skip_2;
    // 0x8004E1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004E1CC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8004E1D0: ori         $t9, $t7, 0xF000
    ctx->r25 = ctx->r15 | 0XF000;
    // 0x8004E1D4: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
L_8004E1D8:
    // 0x8004E1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E1DC:
    // 0x8004E1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E1E0: jr          $ra
    // 0x8004E1E4: nop

    return;
    // 0x8004E1E4: nop

;}
RECOMP_FUNC void func_806AF580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AF584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AF588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AF58C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806AF590: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AF594: jal         0x806AF2BC
    // 0x806AF598: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_806AF2BC(rdram, ctx);
        goto after_0;
    // 0x806AF598: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x806AF59C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806AF5A0: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806AF5A4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AF5A8: sw          $t7, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r15;
    // 0x806AF5AC: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x806AF5B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806AF5B4: sw          $t8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r24;
    // 0x806AF5B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806AF5BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AF5C0: jal         0x80048378
    // 0x806AF5C4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806AF5C4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    after_1:
    // 0x806AF5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF5CC: jal         0x80045A34
    // 0x806AF5D0: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x806AF5D0: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_2:
    // 0x806AF5D4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AF5D8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x806AF5DC: jal         0x806AF3D8
    // 0x806AF5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AF3D8(rdram, ctx);
        goto after_3;
    // 0x806AF5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AF5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AF5E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AF5EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AF5F0: jr          $ra
    // 0x806AF5F4: nop

    return;
    // 0x806AF5F4: nop

;}
RECOMP_FUNC void func_8042FD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FD34: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BB8) << 16);
    // 0x8042FD38: lwc1        $f6, 0x1C98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BB8));
    // 0x8042FD3C: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042FD40: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042FD44: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042FD48: nop

    // 0x8042FD4C: bc1fl       L_8042FD8C
    if (!c1cs) {
        // 0x8042FD50: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8042FD8C;
    }
    goto skip_0;
    // 0x8042FD50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8042FD54: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042FD58: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042FD5C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8042FD60: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042FD64: nop

    // 0x8042FD68: bc1fl       L_8042FD80
    if (!c1cs) {
        // 0x8042FD6C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8042FD80;
    }
    goto skip_1;
    // 0x8042FD6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_1:
    // 0x8042FD70: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8042FD74: b           L_8042FD88
    // 0x8042FD78: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8042FD88;
    // 0x8042FD78: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8042FD7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8042FD80:
    // 0x8042FD80: nop

    // 0x8042FD84: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8042FD88:
    // 0x8042FD88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8042FD8C:
    // 0x8042FD8C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8042FD90: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8042FD94: nop

    // 0x8042FD98: bc1fl       L_8042FDCC
    if (!c1cs) {
        // 0x8042FD9C: swc1        $f2, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
            goto L_8042FDCC;
    }
    goto skip_2;
    // 0x8042FD9C: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    skip_2:
    // 0x8042FDA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FDA4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BBC) << 16);
    // 0x8042FDA8: lwc1        $f16, 0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8042FDAC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8042FDB0: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    // 0x8042FDB4: lwc1        $f6, 0x1C9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BBC));
    // 0x8042FDB8: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8042FDBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042FDC0: jr          $ra
    // 0x8042FDC4: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8042FDC4: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x8042FDC8: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
L_8042FDCC:
    // 0x8042FDCC: jr          $ra
    // 0x8042FDD0: nop

    return;
    // 0x8042FDD0: nop

;}
RECOMP_FUNC void func_80059D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059D64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059D68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059D6C: lwc1        $f6, 0xBD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XBD0);
    // 0x80059D70: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80059D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059D78: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x80059D7C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80059D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059D84: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80059D88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80059D8C: bc1f        L_80059DAC
    if (!c1cs) {
        // 0x80059D90: nop
    
            goto L_80059DAC;
    }
    // 0x80059D90: nop

    // 0x80059D94: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80059D98: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80059D9C: jal         0x80059B78
    // 0x80059DA0: lwc1        $f14, 0x48($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X48);
    func_80059B78(rdram, ctx);
        goto after_0;
    // 0x80059DA0: lwc1        $f14, 0x48($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X48);
    after_0:
    // 0x80059DA4: b           L_80059DE0
    // 0x80059DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80059DE0;
    // 0x80059DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059DAC:
    // 0x80059DAC: lwc1        $f8, 0xBD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XBD4);
    // 0x80059DB0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80059DB4: nop

    // 0x80059DB8: bc1fl       L_80059DDC
    if (!c1cs) {
        // 0x80059DBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80059DDC;
    }
    goto skip_0;
    // 0x80059DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80059DC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80059DC4: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80059DC8: jal         0x80059BB0
    // 0x80059DCC: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    func_80059BB0(rdram, ctx);
        goto after_1;
    // 0x80059DCC: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    after_1:
    // 0x80059DD0: b           L_80059DE0
    // 0x80059DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80059DE0;
    // 0x80059DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059DDC:
    // 0x80059DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059DE0:
    // 0x80059DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059DE4: jr          $ra
    // 0x80059DE8: nop

    return;
    // 0x80059DE8: nop

;}
RECOMP_FUNC void func_804C5430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5438: jal         0x8004700C
    // 0x804C543C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C543C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5440: beq         $v0, $zero, L_804C5478
    if (ctx->r2 == 0) {
        // 0x804C5444: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C5478;
    }
    // 0x804C5444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C5448: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804C544C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804C5450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804C5454: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C5458: nop

    // 0x804C545C: bc1fl       L_804C5470
    if (!c1cs) {
        // 0x804C5460: sw          $t6, 0x138($a0)
        MEM_W(0X138, ctx->r4) = ctx->r14;
            goto L_804C5470;
    }
    goto skip_0;
    // 0x804C5460: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    skip_0:
    // 0x804C5464: b           L_804C5470
    // 0x804C5468: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
        goto L_804C5470;
    // 0x804C5468: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804C546C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
L_804C5470:
    // 0x804C5470: jal         0x804C52D0
    // 0x804C5474: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    func_804C52D0(rdram, ctx);
        goto after_1;
    // 0x804C5474: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    after_1:
L_804C5478:
    // 0x804C5478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C547C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5480: jr          $ra
    // 0x804C5484: nop

    return;
    // 0x804C5484: nop

;}
RECOMP_FUNC void func_8001CB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CB38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CB3C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001CB40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CB44: bne         $a1, $at, L_8001CB54
    if (ctx->r5 != ctx->r1) {
        // 0x8001CB48: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001CB54;
    }
    // 0x8001CB48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CB4C: jal         0x8001CBB8
    // 0x8001CB50: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    func_8001CBB8(rdram, ctx);
        goto after_0;
    // 0x8001CB50: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    after_0:
L_8001CB54:
    // 0x8001CB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CB58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CB5C: jr          $ra
    // 0x8001CB60: nop

    return;
    // 0x8001CB60: nop

;}
RECOMP_FUNC void func_8043E65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E65C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043E660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043E664: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043E668: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8043E66C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8043E670: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8043E674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043E678: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8043E67C: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8043E680: lw          $a2, 0x12C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X12C);
    // 0x8043E684: jal         0x8043E490
    // 0x8043E688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8043E490(rdram, ctx);
        goto after_0;
    // 0x8043E688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8043E68C: jal         0x8003B41C
    // 0x8043E690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003B41C(rdram, ctx);
        goto after_1;
    // 0x8043E690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043E694: jal         0x8005FE48
    // 0x8043E698: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8043E698: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8043E69C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8043E6A0: addiu       $t8, $zero, 0xC12
    ctx->r24 = ADD32(0, 0XC12);
    // 0x8043E6A4: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8043E6A8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8043E6AC: addiu       $t0, $t0, -0x6030
    ctx->r8 = ADD32(ctx->r8, -0X6030);
    // 0x8043E6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043E6B4: sh          $t8, 0x4C($t9)
    MEM_H(0X4C, ctx->r25) = ctx->r24;
    // 0x8043E6B8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8043E6BC: jal         0x8043D154
    // 0x8043E6C0: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
    func_8043D154(rdram, ctx);
        goto after_3;
    // 0x8043E6C0: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
    after_3:
    // 0x8043E6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E6C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043E6CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043E6D0: jr          $ra
    // 0x8043E6D4: nop

    return;
    // 0x8043E6D4: nop

;}
RECOMP_FUNC void func_80409618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409618: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040961C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80409620: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80409624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80409628: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8040962C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80409630: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80409634: jal         0x80047AB8
    // 0x80409638: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80409638: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x8040963C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80409640: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80409644: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80409648: jal         0x80065954
    // 0x8040964C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8040964C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80409650: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80409654: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80409658: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8040965C: nop

    // 0x80409660: addiu       $v0, $v0, -0x140
    ctx->r2 = ADD32(ctx->r2, -0X140);
    // 0x80409664: slti        $at, $v0, -0x2F
    ctx->r1 = SIGNED(ctx->r2) < -0X2F ? 1 : 0;
    // 0x80409668: beq         $at, $zero, L_80409688
    if (ctx->r1 == 0) {
        // 0x8040966C: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_80409688;
    }
    // 0x8040966C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80409670: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80409674: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80409678: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8040967C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80409680: b           L_804096A8
    // 0x80409684: swc1        $f0, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f0.u32l;
        goto L_804096A8;
    // 0x80409684: swc1        $f0, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f0.u32l;
L_80409688:
    // 0x80409688: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x8040968C: bne         $at, $zero, L_804096A8
    if (ctx->r1 != 0) {
        // 0x80409690: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_804096A8;
    }
    // 0x80409690: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80409694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409698: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8040969C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804096A0: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x804096A4: swc1        $f0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f0.u32l;
L_804096A8:
    // 0x804096A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804096AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804096B0: jr          $ra
    // 0x804096B4: nop

    return;
    // 0x804096B4: nop

    // 0x804096B8: jr          $ra
    // 0x804096BC: nop

    return;
    // 0x804096BC: nop

;}
RECOMP_FUNC void func_80471BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471BCC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80471BD0: beq         $v0, $zero, L_80471BE0
    if (ctx->r2 == 0) {
        // 0x80471BD4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80471BE0;
    }
    // 0x80471BD4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80471BD8: jr          $ra
    // 0x80471BDC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    return;
    // 0x80471BDC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80471BE0:
    // 0x80471BE0: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x80471BE4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80471BE8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80471BEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80471BF0: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x80471BF4: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x80471BF8: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80471BFC: bne         $at, $zero, L_80471C08
    if (ctx->r1 != 0) {
        // 0x80471C00: nop
    
            goto L_80471C08;
    }
    // 0x80471C00: nop

    // 0x80471C04: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
L_80471C08:
    // 0x80471C08: jr          $ra
    // 0x80471C0C: nop

    return;
    // 0x80471C0C: nop

;}
RECOMP_FUNC void func_806ED8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED8DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ED8E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ED8E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806ED8E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806ED8EC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ED8F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ED8F4: jal         0x800577D8
    // 0x806ED8F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ED8F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x806ED8FC: jal         0x806ED57C
    // 0x806ED900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED57C(rdram, ctx);
        goto after_1;
    // 0x806ED900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ED904: jal         0x806ED5F0
    // 0x806ED908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED5F0(rdram, ctx);
        goto after_2;
    // 0x806ED908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806ED90C: jal         0x806ED6C4
    // 0x806ED910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_3;
    // 0x806ED910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806ED914: bne         $v0, $zero, L_806ED934
    if (ctx->r2 != 0) {
        // 0x806ED918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ED934;
    }
    // 0x806ED918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED91C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED920: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806ED924: jal         0x806EE584
    // 0x806ED928: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_4;
    // 0x806ED928: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806ED92C: b           L_806EDA78
    // 0x806ED930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDA78;
    // 0x806ED930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED934:
    // 0x806ED934: jal         0x806ED714
    // 0x806ED938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED714(rdram, ctx);
        goto after_5;
    // 0x806ED938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806ED93C: beq         $v0, $zero, L_806ED95C
    if (ctx->r2 == 0) {
        // 0x806ED940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ED95C;
    }
    // 0x806ED940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED948: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806ED94C: jal         0x806EE584
    // 0x806ED950: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_6;
    // 0x806ED950: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806ED954: b           L_806EDA78
    // 0x806ED958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDA78;
    // 0x806ED958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED95C:
    // 0x806ED95C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ED960: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x806ED964: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x806ED968: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806ED96C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806ED970: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806ED974: nop

    // 0x806ED978: bc1f        L_806EDA6C
    if (!c1cs) {
        // 0x806ED97C: nop
    
            goto L_806EDA6C;
    }
    // 0x806ED97C: nop

    // 0x806ED980: jal         0x806EBFB8
    // 0x806ED984: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806EBFB8(rdram, ctx);
        goto after_7;
    // 0x806ED984: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x806ED988: bne         $v0, $zero, L_806ED9FC
    if (ctx->r2 != 0) {
        // 0x806ED98C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ED9FC;
    }
    // 0x806ED98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED998: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806ED99C: jal         0x806EE584
    // 0x806ED9A0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_8;
    // 0x806ED9A0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_8:
    // 0x806ED9A4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806ED9A8: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ED9AC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x806ED9B0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806ED9B4: nop

    // 0x806ED9B8: bc1fl       L_806ED9E4
    if (!c1cs) {
        // 0x806ED9BC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806ED9E4;
    }
    goto skip_0;
    // 0x806ED9BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x806ED9C0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806ED9C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806ED9C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806ED9CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806ED9D0: jal         0x806EC03C
    // 0x806ED9D4: nop

    func_806EC03C(rdram, ctx);
        goto after_9;
    // 0x806ED9D4: nop

    after_9:
    // 0x806ED9D8: b           L_806EDA60
    // 0x806ED9DC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EDA60;
    // 0x806ED9DC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x806ED9E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806ED9E4:
    // 0x806ED9E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806ED9E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806ED9EC: jal         0x806EC03C
    // 0x806ED9F0: nop

    func_806EC03C(rdram, ctx);
        goto after_10;
    // 0x806ED9F0: nop

    after_10:
    // 0x806ED9F4: b           L_806EDA60
    // 0x806ED9F8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EDA60;
    // 0x806ED9F8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
L_806ED9FC:
    // 0x806ED9FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDA00: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EDA04: jal         0x806EE584
    // 0x806EDA08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_11;
    // 0x806EDA08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
    // 0x806EDA0C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806EDA10: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDA14: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806EDA18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EDA1C: nop

    // 0x806EDA20: bc1fl       L_806EDA4C
    if (!c1cs) {
        // 0x806EDA24: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EDA4C;
    }
    goto skip_1;
    // 0x806EDA24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x806EDA28: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806EDA2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EDA30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806EDA34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EDA38: jal         0x806EC03C
    // 0x806EDA3C: nop

    func_806EC03C(rdram, ctx);
        goto after_12;
    // 0x806EDA3C: nop

    after_12:
    // 0x806EDA40: b           L_806EDA60
    // 0x806EDA44: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EDA60;
    // 0x806EDA44: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x806EDA48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EDA4C:
    // 0x806EDA4C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806EDA50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EDA54: jal         0x806EC03C
    // 0x806EDA58: nop

    func_806EC03C(rdram, ctx);
        goto after_13;
    // 0x806EDA58: nop

    after_13:
    // 0x806EDA5C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
L_806EDA60:
    // 0x806EDA60: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDA64: b           L_806EDA74
    // 0x806EDA68: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
        goto L_806EDA74;
    // 0x806EDA68: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
L_806EDA6C:
    // 0x806EDA6C: jal         0x806ED844
    // 0x806EDA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED844(rdram, ctx);
        goto after_14;
    // 0x806EDA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_806EDA74:
    // 0x806EDA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDA78:
    // 0x806EDA78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EDA7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EDA80: jr          $ra
    // 0x806EDA84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806EDA84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806FD7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD7B8: jal         0x806FD700
    // 0x806FD7BC: nop

    func_806FD700(rdram, ctx);
        goto after_0;
    // 0x806FD7BC: nop

    after_0:
    // 0x806FD7C0: beql        $v0, $zero, L_806FD7EC
    if (ctx->r2 == 0) {
        // 0x806FD7C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FD7EC;
    }
    goto skip_0;
    // 0x806FD7C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806FD7C8: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x806FD7CC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x806FD7D0: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x806FD7D4: lhu         $t6, 0x10($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X10);
    // 0x806FD7D8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x806FD7DC: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x806FD7E0: sw          $t8, 0x1E4($v0)
    MEM_W(0X1E4, ctx->r2) = ctx->r24;
    // 0x806FD7E4: sw          $t9, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r25;
    // 0x806FD7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FD7EC:
    // 0x806FD7EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD7F0: jr          $ra
    // 0x806FD7F4: nop

    return;
    // 0x806FD7F4: nop

;}
RECOMP_FUNC void func_806AB0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AB0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AB0A8: jal         0x806AAFDC
    // 0x806AB0AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AAFDC(rdram, ctx);
        goto after_0;
    // 0x806AB0AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AB0B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AB0B4: beq         $v0, $at, L_806AB0D0
    if (ctx->r2 == ctx->r1) {
        // 0x806AB0B8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AB0D0;
    }
    // 0x806AB0B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AB0BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806AB0C0: beq         $v0, $at, L_806AB0E0
    if (ctx->r2 == ctx->r1) {
        // 0x806AB0C4: nop
    
            goto L_806AB0E0;
    }
    // 0x806AB0C4: nop

    // 0x806AB0C8: b           L_806AB0F0
    // 0x806AB0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB0F0;
    // 0x806AB0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB0D0:
    // 0x806AB0D0: jal         0x806AAC8C
    // 0x806AB0D4: nop

    func_806AAC8C(rdram, ctx);
        goto after_1;
    // 0x806AB0D4: nop

    after_1:
    // 0x806AB0D8: b           L_806AB0F0
    // 0x806AB0DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB0F0;
    // 0x806AB0DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB0E0:
    // 0x806AB0E0: jal         0x806AAC8C
    // 0x806AB0E4: nop

    func_806AAC8C(rdram, ctx);
        goto after_2;
    // 0x806AB0E4: nop

    after_2:
    // 0x806AB0E8: b           L_806AB0F0
    // 0x806AB0EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806AB0F0;
    // 0x806AB0EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806AB0F0:
    // 0x806AB0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AB0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AB0F8: jr          $ra
    // 0x806AB0FC: nop

    return;
    // 0x806AB0FC: nop

;}
RECOMP_FUNC void func_80022D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D6C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80022D70: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80022D74: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80022D78: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80022D7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022D80: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x80022D84: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80022D88: bnel        $v0, $t8, L_80022DA0
    if (ctx->r2 != ctx->r24) {
        // 0x80022D8C: sb          $zero, 0xAF6($v1)
        MEM_B(0XAF6, ctx->r3) = 0;
            goto L_80022DA0;
    }
    goto skip_0;
    // 0x80022D8C: sb          $zero, 0xAF6($v1)
    MEM_B(0XAF6, ctx->r3) = 0;
    skip_0:
    // 0x80022D90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022D94: b           L_80022DA0
    // 0x80022D98: sb          $a0, 0xAF6($v1)
    MEM_B(0XAF6, ctx->r3) = ctx->r4;
        goto L_80022DA0;
    // 0x80022D98: sb          $a0, 0xAF6($v1)
    MEM_B(0XAF6, ctx->r3) = ctx->r4;
    // 0x80022D9C: sb          $zero, 0xAF6($v1)
    MEM_B(0XAF6, ctx->r3) = 0;
L_80022DA0:
    // 0x80022DA0: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80022DA4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80022DA8: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80022DAC: bnel        $v0, $t1, L_80022DC0
    if (ctx->r2 != ctx->r9) {
        // 0x80022DB0: sb          $zero, 0xAF5($v1)
        MEM_B(0XAF5, ctx->r3) = 0;
            goto L_80022DC0;
    }
    goto skip_1;
    // 0x80022DB0: sb          $zero, 0xAF5($v1)
    MEM_B(0XAF5, ctx->r3) = 0;
    skip_1:
    // 0x80022DB4: b           L_80022DC0
    // 0x80022DB8: sb          $a0, 0xAF5($v1)
    MEM_B(0XAF5, ctx->r3) = ctx->r4;
        goto L_80022DC0;
    // 0x80022DB8: sb          $a0, 0xAF5($v1)
    MEM_B(0XAF5, ctx->r3) = ctx->r4;
    // 0x80022DBC: sb          $zero, 0xAF5($v1)
    MEM_B(0XAF5, ctx->r3) = 0;
L_80022DC0:
    // 0x80022DC0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80022DC4: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80022DC8: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x80022DCC: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x80022DD0: bnel        $v0, $t4, L_80022DE4
    if (ctx->r2 != ctx->r12) {
        // 0x80022DD4: sb          $zero, 0xAF8($v1)
        MEM_B(0XAF8, ctx->r3) = 0;
            goto L_80022DE4;
    }
    goto skip_2;
    // 0x80022DD4: sb          $zero, 0xAF8($v1)
    MEM_B(0XAF8, ctx->r3) = 0;
    skip_2:
    // 0x80022DD8: b           L_80022DE4
    // 0x80022DDC: sb          $a0, 0xAF8($v1)
    MEM_B(0XAF8, ctx->r3) = ctx->r4;
        goto L_80022DE4;
    // 0x80022DDC: sb          $a0, 0xAF8($v1)
    MEM_B(0XAF8, ctx->r3) = ctx->r4;
    // 0x80022DE0: sb          $zero, 0xAF8($v1)
    MEM_B(0XAF8, ctx->r3) = 0;
L_80022DE4:
    // 0x80022DE4: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80022DE8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80022DEC: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80022DF0: bnel        $v0, $t7, L_80022E04
    if (ctx->r2 != ctx->r15) {
        // 0x80022DF4: sb          $zero, 0xAF7($v1)
        MEM_B(0XAF7, ctx->r3) = 0;
            goto L_80022E04;
    }
    goto skip_3;
    // 0x80022DF4: sb          $zero, 0xAF7($v1)
    MEM_B(0XAF7, ctx->r3) = 0;
    skip_3:
    // 0x80022DF8: jr          $ra
    // 0x80022DFC: sb          $a0, 0xAF7($v1)
    MEM_B(0XAF7, ctx->r3) = ctx->r4;
    return;
    // 0x80022DFC: sb          $a0, 0xAF7($v1)
    MEM_B(0XAF7, ctx->r3) = ctx->r4;
    // 0x80022E00: sb          $zero, 0xAF7($v1)
    MEM_B(0XAF7, ctx->r3) = 0;
L_80022E04:
    // 0x80022E04: jr          $ra
    // 0x80022E08: nop

    return;
    // 0x80022E08: nop

;}
RECOMP_FUNC void func_8046088C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046088C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460894: jal         0x80062748
    // 0x80460898: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x80460898: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x8046089C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804608A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804608A4: jr          $ra
    // 0x804608A8: nop

    return;
    // 0x804608A8: nop

;}
RECOMP_FUNC void func_804210D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804210D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804210D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804210D8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804210DC: addiu       $at, $zero, 0x40B5
    ctx->r1 = ADD32(0, 0X40B5);
    // 0x804210E0: beq         $v0, $at, L_804210F8
    if (ctx->r2 == ctx->r1) {
        // 0x804210E4: addiu       $at, $zero, 0x40B6
        ctx->r1 = ADD32(0, 0X40B6);
            goto L_804210F8;
    }
    // 0x804210E4: addiu       $at, $zero, 0x40B6
    ctx->r1 = ADD32(0, 0X40B6);
    // 0x804210E8: beq         $v0, $at, L_80421108
    if (ctx->r2 == ctx->r1) {
        // 0x804210EC: nop
    
            goto L_80421108;
    }
    // 0x804210EC: nop

    // 0x804210F0: b           L_80421114
    // 0x804210F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80421114;
    // 0x804210F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804210F8:
    // 0x804210F8: jal         0x8042247C
    // 0x804210FC: nop

    func_8042247C(rdram, ctx);
        goto after_0;
    // 0x804210FC: nop

    after_0:
    // 0x80421100: b           L_80421114
    // 0x80421104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80421114;
    // 0x80421104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80421108:
    // 0x80421108: jal         0x804215E8
    // 0x8042110C: nop

    func_804215E8(rdram, ctx);
        goto after_1;
    // 0x8042110C: nop

    after_1:
    // 0x80421110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80421114:
    // 0x80421114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421118: jr          $ra
    // 0x8042111C: nop

    return;
    // 0x8042111C: nop

;}
RECOMP_FUNC void func_8045B8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B8B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B8C0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8045B8C4: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(107, 0X2250) << 16);
    // 0x8045B8C8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8045B8CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8045B8D0: addiu       $t6, $t6, -0x2520
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(107, 0X2250));
    // 0x8045B8D4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8045B8D8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045B8DC: jal         0x8045B8A0
    // 0x8045B8E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045B8A0(rdram, ctx);
        goto after_0;
    // 0x8045B8E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045B8E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B8E8: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(107, 0X974) << 16);
    // 0x8045B8EC: addiu       $t8, $t8, -0x3DFC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(107, 0X974));
    // 0x8045B8F0: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8045B8F4: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
    // 0x8045B8F8: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x8045B8FC: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8045B900: beq         $v0, $at, L_8045B948
    if (ctx->r2 == ctx->r1) {
        // 0x8045B904: addiu       $at, $zero, 0x4109
        ctx->r1 = ADD32(0, 0X4109);
            goto L_8045B948;
    }
    // 0x8045B904: addiu       $at, $zero, 0x4109
    ctx->r1 = ADD32(0, 0X4109);
    // 0x8045B908: beq         $v0, $at, L_8045B95C
    if (ctx->r2 == ctx->r1) {
        // 0x8045B90C: addiu       $at, $zero, 0x410A
        ctx->r1 = ADD32(0, 0X410A);
            goto L_8045B95C;
    }
    // 0x8045B90C: addiu       $at, $zero, 0x410A
    ctx->r1 = ADD32(0, 0X410A);
    // 0x8045B910: beq         $v0, $at, L_8045B970
    if (ctx->r2 == ctx->r1) {
        // 0x8045B914: addiu       $at, $zero, 0x410B
        ctx->r1 = ADD32(0, 0X410B);
            goto L_8045B970;
    }
    // 0x8045B914: addiu       $at, $zero, 0x410B
    ctx->r1 = ADD32(0, 0X410B);
    // 0x8045B918: beq         $v0, $at, L_8045B984
    if (ctx->r2 == ctx->r1) {
        // 0x8045B91C: addiu       $at, $zero, 0x469C
        ctx->r1 = ADD32(0, 0X469C);
            goto L_8045B984;
    }
    // 0x8045B91C: addiu       $at, $zero, 0x469C
    ctx->r1 = ADD32(0, 0X469C);
    // 0x8045B920: beq         $v0, $at, L_8045B948
    if (ctx->r2 == ctx->r1) {
        // 0x8045B924: addiu       $at, $zero, 0x469D
        ctx->r1 = ADD32(0, 0X469D);
            goto L_8045B948;
    }
    // 0x8045B924: addiu       $at, $zero, 0x469D
    ctx->r1 = ADD32(0, 0X469D);
    // 0x8045B928: beq         $v0, $at, L_8045B95C
    if (ctx->r2 == ctx->r1) {
        // 0x8045B92C: addiu       $at, $zero, 0x469E
        ctx->r1 = ADD32(0, 0X469E);
            goto L_8045B95C;
    }
    // 0x8045B92C: addiu       $at, $zero, 0x469E
    ctx->r1 = ADD32(0, 0X469E);
    // 0x8045B930: beq         $v0, $at, L_8045B970
    if (ctx->r2 == ctx->r1) {
        // 0x8045B934: addiu       $at, $zero, 0x469F
        ctx->r1 = ADD32(0, 0X469F);
            goto L_8045B970;
    }
    // 0x8045B934: addiu       $at, $zero, 0x469F
    ctx->r1 = ADD32(0, 0X469F);
    // 0x8045B938: beq         $v0, $at, L_8045B984
    if (ctx->r2 == ctx->r1) {
        // 0x8045B93C: nop
    
            goto L_8045B984;
    }
    // 0x8045B93C: nop

    // 0x8045B940: b           L_8045B998
    // 0x8045B944: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
        goto L_8045B998;
    // 0x8045B944: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
L_8045B948:
    // 0x8045B948: jal         0x8045B9F8
    // 0x8045B94C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045B9F8(rdram, ctx);
        goto after_1;
    // 0x8045B94C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8045B950: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B954: b           L_8045B994
    // 0x8045B958: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
        goto L_8045B994;
    // 0x8045B958: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8045B95C:
    // 0x8045B95C: jal         0x8045BA68
    // 0x8045B960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045BA68(rdram, ctx);
        goto after_2;
    // 0x8045B960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8045B964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B968: b           L_8045B994
    // 0x8045B96C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
        goto L_8045B994;
    // 0x8045B96C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8045B970:
    // 0x8045B970: jal         0x8045BAD8
    // 0x8045B974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045BAD8(rdram, ctx);
        goto after_3;
    // 0x8045B974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x8045B978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B97C: b           L_8045B994
    // 0x8045B980: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
        goto L_8045B994;
    // 0x8045B980: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8045B984:
    // 0x8045B984: jal         0x8045BB48
    // 0x8045B988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045BB48(rdram, ctx);
        goto after_4;
    // 0x8045B988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x8045B98C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B990: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8045B994:
    // 0x8045B994: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
L_8045B998:
    // 0x8045B998: beq         $v0, $at, L_8045B9E4
    if (ctx->r2 == ctx->r1) {
        // 0x8045B99C: addiu       $at, $zero, 0x4109
        ctx->r1 = ADD32(0, 0X4109);
            goto L_8045B9E4;
    }
    // 0x8045B99C: addiu       $at, $zero, 0x4109
    ctx->r1 = ADD32(0, 0X4109);
    // 0x8045B9A0: beq         $v0, $at, L_8045B9E4
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9A4: addiu       $at, $zero, 0x410A
        ctx->r1 = ADD32(0, 0X410A);
            goto L_8045B9E4;
    }
    // 0x8045B9A4: addiu       $at, $zero, 0x410A
    ctx->r1 = ADD32(0, 0X410A);
    // 0x8045B9A8: beq         $v0, $at, L_8045B9E4
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9AC: addiu       $at, $zero, 0x410B
        ctx->r1 = ADD32(0, 0X410B);
            goto L_8045B9E4;
    }
    // 0x8045B9AC: addiu       $at, $zero, 0x410B
    ctx->r1 = ADD32(0, 0X410B);
    // 0x8045B9B0: beq         $v0, $at, L_8045B9E4
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9B4: addiu       $at, $zero, 0x469C
        ctx->r1 = ADD32(0, 0X469C);
            goto L_8045B9E4;
    }
    // 0x8045B9B4: addiu       $at, $zero, 0x469C
    ctx->r1 = ADD32(0, 0X469C);
    // 0x8045B9B8: beq         $v0, $at, L_8045B9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9BC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8045B9DC;
    }
    // 0x8045B9BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8045B9C0: addiu       $at, $zero, 0x469D
    ctx->r1 = ADD32(0, 0X469D);
    // 0x8045B9C4: beq         $v0, $at, L_8045B9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9C8: addiu       $at, $zero, 0x469E
        ctx->r1 = ADD32(0, 0X469E);
            goto L_8045B9DC;
    }
    // 0x8045B9C8: addiu       $at, $zero, 0x469E
    ctx->r1 = ADD32(0, 0X469E);
    // 0x8045B9CC: beq         $v0, $at, L_8045B9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8045B9D0: addiu       $at, $zero, 0x469F
        ctx->r1 = ADD32(0, 0X469F);
            goto L_8045B9DC;
    }
    // 0x8045B9D0: addiu       $at, $zero, 0x469F
    ctx->r1 = ADD32(0, 0X469F);
    // 0x8045B9D4: bnel        $v0, $at, L_8045B9E8
    if (ctx->r2 != ctx->r1) {
        // 0x8045B9D8: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_8045B9E8;
    }
    goto skip_0;
    // 0x8045B9D8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_0:
L_8045B9DC:
    // 0x8045B9DC: b           L_8045B9E8
    // 0x8045B9E0: sw          $t0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r8;
        goto L_8045B9E8;
    // 0x8045B9E0: sw          $t0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r8;
L_8045B9E4:
    // 0x8045B9E4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8045B9E8:
    // 0x8045B9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045B9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B9F0: jr          $ra
    // 0x8045B9F4: nop

    return;
    // 0x8045B9F4: nop

;}
RECOMP_FUNC void func_800331A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800331A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800331A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800331AC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800331B0: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x800331B4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800331B8: nop

    // 0x800331BC: bc1fl       L_800331F4
    if (!c1cs) {
        // 0x800331C0: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_800331F4;
    }
    goto skip_0;
    // 0x800331C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x800331C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800331C8: nop

    // 0x800331CC: bc1fl       L_80033230
    if (!c1cs) {
        // 0x800331D0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80033230;
    }
    goto skip_1;
    // 0x800331D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x800331D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800331D8:
    // 0x800331D8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800331DC: nop

    // 0x800331E0: bc1tl       L_800331D8
    if (c1cs) {
        // 0x800331E4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800331D8;
    }
    goto skip_2;
    // 0x800331E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800331E8: b           L_80033230
    // 0x800331EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80033230;
    // 0x800331EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800331F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_800331F4:
    // 0x800331F4: nop

    // 0x800331F8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800331FC: nop

    // 0x80033200: bc1fl       L_80033230
    if (!c1cs) {
        // 0x80033204: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80033230;
    }
    goto skip_3;
    // 0x80033204: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_3:
    // 0x80033208: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003320C: nop

    // 0x80033210: bc1fl       L_80033230
    if (!c1cs) {
        // 0x80033214: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80033230;
    }
    goto skip_4;
    // 0x80033214: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_4:
    // 0x80033218: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8003321C:
    // 0x8003321C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80033220: nop

    // 0x80033224: bc1tl       L_8003321C
    if (c1cs) {
        // 0x80033228: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8003321C;
    }
    goto skip_5;
    // 0x80033228: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    skip_5:
    // 0x8003322C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80033230:
    // 0x80033230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033234: nop

    // 0x80033238: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8003323C: nop

    // 0x80033240: bc1fl       L_80033254
    if (!c1cs) {
        // 0x80033244: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80033254;
    }
    goto skip_6;
    // 0x80033244: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_6:
    // 0x80033248: b           L_8003328C
    // 0x8003324C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_8003328C;
    // 0x8003324C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80033250: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80033254:
    // 0x80033254: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80033258: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8003325C: nop

    // 0x80033260: bc1fl       L_80033290
    if (!c1cs) {
        // 0x80033264: lw          $v0, 0x174($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X174);
            goto L_80033290;
    }
    goto skip_7;
    // 0x80033264: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    skip_7:
    // 0x80033268: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003326C: nop

    // 0x80033270: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80033274: nop

    // 0x80033278: bc1fl       L_8003328C
    if (!c1cs) {
        // 0x8003327C: add.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_8003328C;
    }
    goto skip_8;
    // 0x8003327C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    skip_8:
    // 0x80033280: b           L_8003328C
    // 0x80033284: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8003328C;
    // 0x80033284: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80033288: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
L_8003328C:
    // 0x8003328C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
L_80033290:
    // 0x80033290: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80033294: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80033298: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8003329C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800332A0: lw          $a1, 0x2C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X2C);
    // 0x800332A4: lw          $t1, 0x34($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X34);
    // 0x800332A8: lw          $t9, 0x70($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X70);
    // 0x800332AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800332B0: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800332B4: lh          $v1, -0x16EC($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X16EC);
    // 0x800332B8: lw          $a3, 0x3C($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X3C);
    // 0x800332BC: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800332C0: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800332C4: beq         $a1, $zero, L_8003344C
    if (ctx->r5 == 0) {
        // 0x800332C8: lwc1        $f2, 0x4($t9)
        ctx->f2.u32l = MEM_W(ctx->r25, 0X4);
            goto L_8003344C;
    }
    // 0x800332C8: lwc1        $f2, 0x4($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800332CC: andi        $t1, $a1, 0x3
    ctx->r9 = ctx->r5 & 0X3;
    // 0x800332D0: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800332D4: beq         $t1, $zero, L_80033340
    if (ctx->r9 == 0) {
        // 0x800332D8: addu        $a2, $t1, $a1
        ctx->r6 = ADD32(ctx->r9, ctx->r5);
            goto L_80033340;
    }
    // 0x800332D8: addu        $a2, $t1, $a1
    ctx->r6 = ADD32(ctx->r9, ctx->r5);
    // 0x800332DC: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x800332E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800332E4: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800332E8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800332EC: nop

    // 0x800332F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800332F4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800332F8: beql        $a2, $a1, L_80033330
    if (ctx->r6 == ctx->r5) {
        // 0x800332FC: swc1        $f18, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
            goto L_80033330;
    }
    goto skip_9;
    // 0x800332FC: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    skip_9:
    // 0x80033300: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_80033304:
    // 0x80033304: lh          $t2, 0x8($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X8);
    // 0x80033308: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003330C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80033310: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80033314: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80033318: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x8003331C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80033320: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80033324: bnel        $a2, $a1, L_80033304
    if (ctx->r6 != ctx->r5) {
        // 0x80033328: swc1        $f18, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
            goto L_80033304;
    }
    goto skip_10;
    // 0x80033328: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    skip_10:
    // 0x8003332C: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_80033330:
    // 0x80033330: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80033334: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80033338: beql        $a1, $zero, L_80033448
    if (ctx->r5 == 0) {
        // 0x8003333C: lw          $t4, 0x0($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X0);
            goto L_80033448;
    }
    goto skip_11;
    // 0x8003333C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    skip_11:
L_80033340:
    // 0x80033340: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80033344: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80033348: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8003334C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80033350: nop

    // 0x80033354: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80033358: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003335C: beql        $a1, $zero, L_800333E8
    if (ctx->r5 == 0) {
        // 0x80033360: swc1        $f18, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
            goto L_800333E8;
    }
    goto skip_12;
    // 0x80033360: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    skip_12:
    // 0x80033364: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_80033368:
    // 0x80033368: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x8003336C: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80033370: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80033374: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80033378: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8003337C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x80033380: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80033384: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80033388: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8003338C: lh          $t8, -0xA($a3)
    ctx->r24 = MEM_H(ctx->r7, -0XA);
    // 0x80033390: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80033394: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80033398: nop

    // 0x8003339C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800333A0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800333A4: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x800333A8: lh          $t2, -0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, -0X4);
    // 0x800333AC: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800333B0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800333B4: nop

    // 0x800333B8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800333BC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800333C0: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x800333C4: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x800333C8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800333CC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800333D0: nop

    // 0x800333D4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800333D8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800333DC: bnel        $a1, $zero, L_80033368
    if (ctx->r5 != 0) {
        // 0x800333E0: swc1        $f18, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
            goto L_80033368;
    }
    goto skip_13;
    // 0x800333E0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    skip_13:
    // 0x800333E4: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_800333E8:
    // 0x800333E8: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x800333EC: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800333F0: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x800333F4: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800333F8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800333FC: nop

    // 0x80033400: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80033404: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80033408: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8003340C: lh          $t8, -0xA($a3)
    ctx->r24 = MEM_H(ctx->r7, -0XA);
    // 0x80033410: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80033414: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80033418: nop

    // 0x8003341C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80033420: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80033424: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x80033428: lh          $t2, -0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, -0X4);
    // 0x8003342C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80033430: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80033434: nop

    // 0x80033438: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003343C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80033440: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80033444: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
L_80033448:
    // 0x80033448: lw          $t1, 0x34($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X34);
L_8003344C:
    // 0x8003344C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80033450: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80033454: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80033458: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003345C: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x80033460: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80033464: lh          $a3, 0x6($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X6);
    // 0x80033468: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8003346C: subu        $a2, $v1, $a3
    ctx->r6 = SUB32(ctx->r3, ctx->r7);
    // 0x80033470: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80033474: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80033478: bgtz        $a2, L_8003348C
    if (SIGNED(ctx->r6) > 0) {
        // 0x8003347C: slti        $at, $a2, 0x2
        ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_8003348C;
    }
    // 0x8003347C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80033480: bne         $at, $zero, L_8003348C
    if (ctx->r1 != 0) {
        // 0x80033484: addu        $t5, $a3, $a2
        ctx->r13 = ADD32(ctx->r7, ctx->r6);
            goto L_8003348C;
    }
    // 0x80033484: addu        $t5, $a3, $a2
    ctx->r13 = ADD32(ctx->r7, ctx->r6);
    // 0x80033488: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
L_8003348C:
    // 0x8003348C: jr          $ra
    // 0x80033490: nop

    return;
    // 0x80033490: nop

;}
RECOMP_FUNC void func_804368A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804368A0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804368A4: addiu       $at, $zero, 0x407A
    ctx->r1 = ADD32(0, 0X407A);
    // 0x804368A8: beq         $v0, $at, L_804368C8
    if (ctx->r2 == ctx->r1) {
        // 0x804368AC: addiu       $at, $zero, 0x407B
        ctx->r1 = ADD32(0, 0X407B);
            goto L_804368C8;
    }
    // 0x804368AC: addiu       $at, $zero, 0x407B
    ctx->r1 = ADD32(0, 0X407B);
    // 0x804368B0: beq         $v0, $at, L_804368D4
    if (ctx->r2 == ctx->r1) {
        // 0x804368B4: addiu       $at, $zero, 0x40F9
        ctx->r1 = ADD32(0, 0X40F9);
            goto L_804368D4;
    }
    // 0x804368B4: addiu       $at, $zero, 0x40F9
    ctx->r1 = ADD32(0, 0X40F9);
    // 0x804368B8: beq         $v0, $at, L_804368E0
    if (ctx->r2 == ctx->r1) {
        // 0x804368BC: nop
    
            goto L_804368E0;
    }
    // 0x804368BC: nop

    // 0x804368C0: b           L_804368EC
    // 0x804368C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804368EC;
    // 0x804368C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804368C8:
    // 0x804368C8: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(77, 0X130) << 16);
    // 0x804368CC: jr          $ra
    // 0x804368D0: addiu       $v0, $v0, 0x69D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X130));
    return;
    // 0x804368D0: addiu       $v0, $v0, 0x69D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X130));
L_804368D4:
    // 0x804368D4: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(77, 0X1CC0) << 16);
    // 0x804368D8: jr          $ra
    // 0x804368DC: addiu       $v0, $v0, -0x7AA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X1CC0));
    return;
    // 0x804368DC: addiu       $v0, $v0, -0x7AA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X1CC0));
L_804368E0:
    // 0x804368E0: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(77, 0X1E5C) << 16);
    // 0x804368E4: jr          $ra
    // 0x804368E8: addiu       $v0, $v0, -0x7904
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X1E5C));
    return;
    // 0x804368E8: addiu       $v0, $v0, -0x7904
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(77, 0X1E5C));
L_804368EC:
    // 0x804368EC: jr          $ra
    // 0x804368F0: nop

    return;
    // 0x804368F0: nop

;}
RECOMP_FUNC void func_8007BE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BE70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BE74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BE78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007BE7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007BE80: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8007BE84: jal         0x80084820
    // 0x8007BE88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x8007BE88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007BE8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007BE90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8007BE94: jal         0x80084820
    // 0x8007BE98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x8007BE98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8007BE9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007BEA0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8007BEA4: addiu       $t7, $t7, -0x4118
    ctx->r15 = ADD32(ctx->r15, -0X4118);
    // 0x8007BEA8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8007BEAC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8007BEB0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007BEB4: lbu         $t8, 0x8($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X8);
    // 0x8007BEB8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007BEBC: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8007BEC0: sb          $t9, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r25;
    // 0x8007BEC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BEC8: sw          $t0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r8;
    // 0x8007BECC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007BED0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8007BED4: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x8007BED8: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8007BEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BEE0: jr          $ra
    // 0x8007BEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007BEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void pad_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB90: jr          $ra
    // 0x8007FB94: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    return;
    // 0x8007FB94: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_804BAB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAB60: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(188, 0X10) << 16);
    // 0x804BAB64: addiu       $v0, $v0, -0x5490
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(188, 0X10));
    // 0x804BAB68: jr          $ra
    // 0x804BAB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804BAB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804EED90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EED90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EED94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EED98: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804EED9C: addiu       $at, $zero, 0x413A
    ctx->r1 = ADD32(0, 0X413A);
    // 0x804EEDA0: beq         $v0, $at, L_804EEDC0
    if (ctx->r2 == ctx->r1) {
        // 0x804EEDA4: addiu       $at, $zero, 0x413B
        ctx->r1 = ADD32(0, 0X413B);
            goto L_804EEDC0;
    }
    // 0x804EEDA4: addiu       $at, $zero, 0x413B
    ctx->r1 = ADD32(0, 0X413B);
    // 0x804EEDA8: beq         $v0, $at, L_804EEDCC
    if (ctx->r2 == ctx->r1) {
        // 0x804EEDAC: addiu       $at, $zero, 0x413C
        ctx->r1 = ADD32(0, 0X413C);
            goto L_804EEDCC;
    }
    // 0x804EEDAC: addiu       $at, $zero, 0x413C
    ctx->r1 = ADD32(0, 0X413C);
    // 0x804EEDB0: beq         $v0, $at, L_804EEDD8
    if (ctx->r2 == ctx->r1) {
        // 0x804EEDB4: lui         $a0, 0x804F
        ctx->r4 = S32(RELOC_HI16(267, 0X1390) << 16);
            goto L_804EEDD8;
    }
    // 0x804EEDB4: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(267, 0X1390) << 16);
    // 0x804EEDB8: b           L_804EEDF8
    // 0x804EEDBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804EEDF8;
    // 0x804EEDBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804EEDC0:
    // 0x804EEDC0: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(267, 0X754) << 16);
    // 0x804EEDC4: b           L_804EEDF8
    // 0x804EEDC8: addiu       $v0, $v0, -0xB1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0X754));
        goto L_804EEDF8;
    // 0x804EEDC8: addiu       $v0, $v0, -0xB1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0X754));
L_804EEDCC:
    // 0x804EEDCC: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(267, 0XAE8) << 16);
    // 0x804EEDD0: b           L_804EEDF8
    // 0x804EEDD4: addiu       $v0, $v0, -0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0XAE8));
        goto L_804EEDF8;
    // 0x804EEDD4: addiu       $v0, $v0, -0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0XAE8));
L_804EEDD8:
    // 0x804EEDD8: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(267, 0X13A0) << 16);
    // 0x804EEDDC: addiu       $a1, $a1, 0x130
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(267, 0X13A0));
    // 0x804EEDE0: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(267, 0X1390));
    // 0x804EEDE4: jal         0x8004667C
    // 0x804EEDE8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804EEDE8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x804EEDEC: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(267, 0XEA8) << 16);
    // 0x804EEDF0: b           L_804EEDF8
    // 0x804EEDF4: addiu       $v0, $v0, -0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0XEA8));
        goto L_804EEDF8;
    // 0x804EEDF4: addiu       $v0, $v0, -0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(267, 0XEA8));
L_804EEDF8:
    // 0x804EEDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EEDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EEE00: jr          $ra
    // 0x804EEE04: nop

    return;
    // 0x804EEE04: nop

;}
RECOMP_FUNC void func_8005B300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B300: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005B304: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8005B308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B30C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8005B310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B314: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8005B318: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005B31C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8005B320: jal         0x8005B270
    // 0x8005B324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005B270(rdram, ctx);
        goto after_0;
    // 0x8005B324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005B328: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8005B32C: sh          $v0, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r2;
    // 0x8005B330: jal         0x8005B270
    // 0x8005B334: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_8005B270(rdram, ctx);
        goto after_1;
    // 0x8005B334: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8005B338: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005B33C: sh          $v0, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r2;
    // 0x8005B340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B348: jr          $ra
    // 0x8005B34C: nop

    return;
    // 0x8005B34C: nop

;}
RECOMP_FUNC void func_8001B7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B7B4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001B7B8: lbu         $t6, -0x6D00($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D00);
    // 0x8001B7BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B7C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B7C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B7C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001B7CC: bne         $t6, $zero, L_8001B83C
    if (ctx->r14 != 0) {
        // 0x8001B7D0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8001B83C;
    }
    // 0x8001B7D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001B7D4: jal         0x8001B2E0
    // 0x8001B7D8: nop

    func_8001B2E0(rdram, ctx);
        goto after_0;
    // 0x8001B7D8: nop

    after_0:
    // 0x8001B7DC: beq         $v0, $zero, L_8001B83C
    if (ctx->r2 == 0) {
        // 0x8001B7E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001B83C;
    }
    // 0x8001B7E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001B7E4: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x8001B7E8: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x8001B7EC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x8001B7F0: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8001B7F4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001B7F8: nop

    // 0x8001B7FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001B800: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x8001B804: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8001B808: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x8001B80C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001B810: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001B814: jal         0x8001B17C
    // 0x8001B818: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_8001B17C(rdram, ctx);
        goto after_1;
    // 0x8001B818: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_1:
    // 0x8001B81C: jal         0x8001B3AC
    // 0x8001B820: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001B3AC(rdram, ctx);
        goto after_2;
    // 0x8001B820: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8001B824: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001B828: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B82C: bltz        $v0, L_8001B83C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001B830: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B83C;
    }
    // 0x8001B830: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B834: jal         0x8001B200
    // 0x8001B838: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    func_8001B200(rdram, ctx);
        goto after_3;
    // 0x8001B838: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    after_3:
L_8001B83C:
    // 0x8001B83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B844: jr          $ra
    // 0x8001B848: nop

    return;
    // 0x8001B848: nop

;}
RECOMP_FUNC void func_8064F108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F108: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F10C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F110: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F114: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F118: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F11C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F120: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F124: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F128: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F12C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F130: jr          $ra
    // 0x8064F134: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F134: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8007CA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CA94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007CA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CA9C: jal         0x800825F0
    // 0x8007CAA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8007CAA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8007CAA4: jal         0x8008B920
    // 0x8007CAA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CAA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007CAAC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007CAB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007CAB4: jal         0x80086880
    // 0x8007CAB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_2;
    // 0x8007CAB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007CABC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007CAC0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8007CAC4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8007CAC8: addiu       $t7, $t7, -0x1C60
    ctx->r15 = ADD32(ctx->r15, -0X1C60);
    // 0x8007CACC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007CAD0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8007CAD4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8007CAD8: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x8007CADC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8007CAE0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8007CAE4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007CAE8: bne         $t0, $zero, L_8007CAF8
    if (ctx->r8 != 0) {
        // 0x8007CAEC: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8007CAF8;
    }
    // 0x8007CAEC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007CAF0: beq         $t1, $zero, L_8007CB50
    if (ctx->r9 == 0) {
        // 0x8007CAF4: nop
    
            goto L_8007CB50;
    }
    // 0x8007CAF4: nop

L_8007CAF8:
    // 0x8007CAF8: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8007CAFC: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    // 0x8007CB00: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8007CB04: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x8007CB08: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8007CB0C: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8007CB10: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8007CB14: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8007CB18: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8007CB1C: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8007CB20: addu        $t8, $at, $t4
    ctx->r24 = ADD32(ctx->r1, ctx->r12);
    // 0x8007CB24: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8007CB28: subu        $t2, $t8, $t0
    ctx->r10 = SUB32(ctx->r24, ctx->r8);
    // 0x8007CB2C: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x8007CB30: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8007CB34: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x8007CB38: subu        $t3, $t9, $t1
    ctx->r11 = SUB32(ctx->r25, ctx->r9);
    // 0x8007CB3C: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x8007CB40: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8007CB44: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x8007CB48: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8007CB4C: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
L_8007CB50:
    // 0x8007CB50: jal         0x8007C974
    // 0x8007CB54: nop

    func_8007C974(rdram, ctx);
        goto after_3;
    // 0x8007CB54: nop

    after_3:
    // 0x8007CB58: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8007CB5C: addiu       $a2, $a2, -0x65F0
    ctx->r6 = ADD32(ctx->r6, -0X65F0);
    // 0x8007CB60: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8007CB64: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8007CB68: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8007CB6C: addiu       $t8, $t8, -0x1C60
    ctx->r24 = ADD32(ctx->r24, -0X1C60);
    // 0x8007CB70: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007CB74: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007CB78: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007CB7C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8007CB80: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8007CB84: sh          $t9, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r25;
    // 0x8007CB88: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007CB8C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007CB90: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8007CB94: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x8007CB98: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x8007CB9C: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8007CBA0: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8007CBA4: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x8007CBA8: jal         0x800825F0
    // 0x8007CBAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x8007CBAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8007CBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CBB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007CBB8: jr          $ra
    // 0x8007CBBC: nop

    return;
    // 0x8007CBBC: nop

;}
RECOMP_FUNC void func_8004A930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A930: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004A934: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A938: jr          $ra
    // 0x8004A93C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8004A93C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8078FA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FA44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078FA48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078FA4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078FA50: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8078FA54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078FA58: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8078FA5C: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x8078FA60: beql        $t7, $zero, L_8078FABC
    if (ctx->r15 == 0) {
        // 0x8078FA64: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_8078FABC;
    }
    goto skip_0;
    // 0x8078FA64: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x8078FA68: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x8078FA6C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8078FA70: bnel        $at, $zero, L_8078FAA4
    if (ctx->r1 != 0) {
        // 0x8078FA74: lwc1        $f6, 0xC8($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_8078FAA4;
    }
    goto skip_1;
    // 0x8078FA74: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    skip_1:
    // 0x8078FA78: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8078FA7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8078FA80: jal         0x8005FA48
    // 0x8078FA84: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
    func_8005FA48(rdram, ctx);
        goto after_0;
    // 0x8078FA84: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
    after_0:
    // 0x8078FA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078FA8C: jal         0x8078FD04
    // 0x8078FA90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8078FD04(rdram, ctx);
        goto after_1;
    // 0x8078FA90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8078FA94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8078FA98: nop

    // 0x8078FA9C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8078FAA0: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
L_8078FAA4:
    // 0x8078FAA4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDC0) << 16);
    // 0x8078FAA8: lwc1        $f10, -0xB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDC0));
    // 0x8078FAAC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8078FAB0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8078FAB4: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x8078FAB8: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_8078FABC:
    // 0x8078FABC: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8078FAC0: jal         0x80065ABC
    // 0x8078FAC4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x8078FAC4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x8078FAC8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8078FACC: jal         0x8078F86C
    // 0x8078FAD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078F86C(rdram, ctx);
        goto after_3;
    // 0x8078FAD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078FAD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078FAD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078FADC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078FAE0: jr          $ra
    // 0x8078FAE4: nop

    return;
    // 0x8078FAE4: nop

;}
RECOMP_FUNC void func_80057BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057BAC: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80057BB0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80057BB4: beq         $at, $zero, L_80057BC8
    if (ctx->r1 == 0) {
        // 0x80057BB8: nop
    
            goto L_80057BC8;
    }
    // 0x80057BB8: nop

    // 0x80057BBC: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80057BC0: bgtzl       $t7, L_80057BD4
    if (SIGNED(ctx->r15) > 0) {
        // 0x80057BC4: lw          $t8, 0x10($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X10);
            goto L_80057BD4;
    }
    goto skip_0;
    // 0x80057BC4: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    skip_0:
L_80057BC8:
    // 0x80057BC8: jr          $ra
    // 0x80057BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057BD0: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
L_80057BD4:
    // 0x80057BD4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80057BD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057BDC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80057BE0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80057BE4: beq         $v1, $zero, L_80057BF4
    if (ctx->r3 == 0) {
        // 0x80057BE8: nop
    
            goto L_80057BF4;
    }
    // 0x80057BE8: nop

    // 0x80057BEC: bne         $v1, $at, L_80057BFC
    if (ctx->r3 != ctx->r1) {
        // 0x80057BF0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80057BFC;
    }
    // 0x80057BF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80057BF4:
    // 0x80057BF4: jr          $ra
    // 0x80057BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057BFC:
    // 0x80057BFC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80057C00: jr          $ra
    // 0x80057C04: nop

    return;
    // 0x80057C04: nop

;}
RECOMP_FUNC void func_8003AF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AF90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AF94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AF98: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8003AF9C: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8003AFA0: jal         0x80058958
    // 0x8003AFA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80058958(rdram, ctx);
        goto after_0;
    // 0x8003AFA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003AFA8: beq         $v0, $zero, L_8003AFE4
    if (ctx->r2 == 0) {
        // 0x8003AFAC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8003AFE4;
    }
    // 0x8003AFAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003AFB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8003AFB4: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8003AFB8: lw          $t6, 0x13B8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13B8);
    // 0x8003AFBC: lbu         $v0, 0x5D($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X5D);
    // 0x8003AFC0: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x8003AFC4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8003AFC8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8003AFCC: lw          $t7, 0x13B8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X13B8);
    // 0x8003AFD0: lbu         $v0, 0x5D($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X5D);
    // 0x8003AFD4: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x8003AFD8: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x8003AFDC: b           L_8003AFF4
    // 0x8003AFE0: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
        goto L_8003AFF4;
    // 0x8003AFE0: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
L_8003AFE4:
    // 0x8003AFE4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8003AFE8: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x8003AFEC: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8003AFF0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8003AFF4:
    // 0x8003AFF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AFF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AFFC: jr          $ra
    // 0x8003B000: nop

    return;
    // 0x8003B000: nop

;}
RECOMP_FUNC void func_8040C7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C7A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8040C7A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C7AC: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8040C7B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040C7B4: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(20, 0X1DF8) << 16);
    // 0x8040C7B8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8040C7BC: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8040C7C0: addiu       $t7, $t7, -0x1C08
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(20, 0X1DF8));
    // 0x8040C7C4: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8040C7C8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8040C7CC: lwc1        $f8, 0x80($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X80);
    // 0x8040C7D0: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(20, 0X1E04) << 16);
    // 0x8040C7D4: addiu       $t1, $t1, -0x1BFC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(20, 0X1E04));
    // 0x8040C7D8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8040C7DC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8040C7E0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8040C7E4: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x8040C7E8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8040C7EC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8040C7F0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8040C7F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040C7F8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8040C7FC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8040C800: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8040C804: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8040C808: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8040C80C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8040C810: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8040C814: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8040C818: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040C81C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8040C820: jal         0x8040E254
    // 0x8040C824: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8040E254(rdram, ctx);
        goto after_0;
    // 0x8040C824: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8040C828: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8040C82C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040C830: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8040C834: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8040C838: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040C83C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8040C840: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8040C844: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040C848: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8040C84C: swc1        $f16, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f16.u32l;
    // 0x8040C850: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
    // 0x8040C854: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8040C858: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8040C85C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040C860: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8040C864: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8040C868: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040C86C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8040C870: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8040C874: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8040C878: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040C87C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040C880: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8040C884: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8040C888: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x8040C88C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8040C890: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x8040C894: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8040C898: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x8040C89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C8A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8040C8A4: jr          $ra
    // 0x8040C8A8: nop

    return;
    // 0x8040C8A8: nop

;}
RECOMP_FUNC void func_806F2680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F268C: jal         0x80047090
    // 0x806F2690: addiu       $a0, $zero, 0x4654
    ctx->r4 = ADD32(0, 0X4654);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806F2690: addiu       $a0, $zero, 0x4654
    ctx->r4 = ADD32(0, 0X4654);
    after_0:
    // 0x806F2694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F2698: lui         $at, 0x4654
    ctx->r1 = S32(0X4654 << 16);
    // 0x806F269C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806F26A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806F26A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806F26A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806F26AC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x806F26B0: jal         0x8004613C
    // 0x806F26B4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806F26B4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x806F26B8: bne         $v0, $zero, L_806F26C8
    if (ctx->r2 != 0) {
        // 0x806F26BC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806F26C8;
    }
    // 0x806F26BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806F26C0: b           L_806F26F0
    // 0x806F26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F26F0;
    // 0x806F26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F26C8:
    // 0x806F26C8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x806F26CC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x806F26D0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x806F26D4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806F26D8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806F26DC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x806F26E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F26E4: jal         0x80047F9C
    // 0x806F26E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806F26E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806F26EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_806F26F0:
    // 0x806F26F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F26F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F26F8: jr          $ra
    // 0x806F26FC: nop

    return;
    // 0x806F26FC: nop

;}
RECOMP_FUNC void func_806B273C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B273C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2740: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2744: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2748: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B274C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2750: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2754: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2758: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B275C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2760: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2764: jr          $ra
    // 0x806B2768: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2768: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805A6600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6600: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A6604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A6608: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A660C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A6610: lhu         $s1, 0xC($a0)
    ctx->r17 = MEM_HU(ctx->r4, 0XC);
    // 0x805A6614: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A6618: addiu       $s1, $s1, -0x4507
    ctx->r17 = ADD32(ctx->r17, -0X4507);
    // 0x805A661C: jal         0x805A64A8
    // 0x805A6620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_805A64A8(rdram, ctx);
        goto after_0;
    // 0x805A6620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x805A6624: beq         $v0, $zero, L_805A671C
    if (ctx->r2 == 0) {
        // 0x805A6628: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_805A671C;
    }
    // 0x805A6628: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x805A662C: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x805A6630: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(417, 0X14C0) << 16);
    // 0x805A6634: addiu       $t9, $t9, 0x6780
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(417, 0X14C0));
    // 0x805A6638: lw          $t7, 0x88($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X88);
    // 0x805A663C: lui         $t2, 0x805A
    ctx->r10 = S32(RELOC_HI16(417, 0X1318) << 16);
    // 0x805A6640: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x805A6644: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x805A6648: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x805A664C: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x805A6650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805A6654: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x805A6658: addiu       $t2, $t2, 0x65D8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(417, 0X1318));
    // 0x805A665C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x805A6660: addiu       $t5, $t5, 0x7EA0
    ctx->r13 = ADD32(ctx->r13, 0X7EA0);
    // 0x805A6664: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x805A6668: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805A666C: sb          $t1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r9;
    // 0x805A6670: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x805A6674: sh          $t3, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r11;
    // 0x805A6678: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x805A667C: lw          $t6, 0x5BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5BC);
    // 0x805A6680: lui         $a1, 0x805A
    ctx->r5 = S32(RELOC_HI16(417, 0X1544) << 16);
    // 0x805A6684: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805A6688: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x805A668C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x805A6690: lbu         $a1, 0x6804($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(417, 0X1544));
    // 0x805A6694: jal         0x805A6730
    // 0x805A6698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A6730(rdram, ctx);
        goto after_1;
    // 0x805A6698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A669C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805A66A0: lw          $t8, 0x5BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5BC);
    // 0x805A66A4: bne         $t8, $zero, L_805A66C0
    if (ctx->r24 != 0) {
        // 0x805A66A8: nop
    
            goto L_805A66C0;
    }
    // 0x805A66A8: nop

    // 0x805A66AC: jal         0x8005FD1C
    // 0x805A66B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x805A66B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A66B4: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x805A66B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805A66BC: sb          $zero, 0x74($t0)
    MEM_B(0X74, ctx->r8) = 0;
L_805A66C0:
    // 0x805A66C0: jal         0x805A65C0
    // 0x805A66C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A65C0(rdram, ctx);
        goto after_3;
    // 0x805A66C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A66C8: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X1588) << 16);
    // 0x805A66CC: lwc1        $f4, 0x6848($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X1588));
    // 0x805A66D0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805A66D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A66D8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x805A66DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A66E0: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x805A66E4: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x805A66E8: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x805A66EC: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x805A66F0: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x805A66F4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x805A66F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x805A66FC: sll         $t2, $s1, 9
    ctx->r10 = S32(ctx->r17 << 9);
    // 0x805A6700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6704: jal         0x8004590C
    // 0x805A6708: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x805A6708: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_4:
    // 0x805A670C: sw          $s1, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r17;
    // 0x805A6710: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A6714: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A6718: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
L_805A671C:
    // 0x805A671C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A6720: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A6724: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A6728: jr          $ra
    // 0x805A672C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805A672C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80450AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450AD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80450AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450ADC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80450AE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80450AE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80450AE8: jal         0x80444A40
    // 0x80450AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80444A40(rdram, ctx);
        goto after_0;
    // 0x80450AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80450AF0: jal         0x80450A74
    // 0x80450AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80450A74(rdram, ctx);
        goto after_1;
    // 0x80450AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80450AF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80450AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80450B00: jal         0x80457164
    // 0x80450B04: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80457164(rdram, ctx);
        goto after_2;
    // 0x80450B04: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x80450B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450B10: jr          $ra
    // 0x80450B14: nop

    return;
    // 0x80450B14: nop

;}
RECOMP_FUNC void func_8051EED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051EED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EEDC: lw          $t6, 0x198($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X198);
    // 0x8051EEE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8051EEE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8051EEE8: lw          $v1, 0x16C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X16C);
    // 0x8051EEEC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8051EEF0: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8051EEF4: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x8051EEF8: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x8051EEFC: bnel        $at, $zero, L_8051EF20
    if (ctx->r1 != 0) {
        // 0x8051EF00: sb          $v0, 0x10($v1)
        MEM_B(0X10, ctx->r3) = ctx->r2;
            goto L_8051EF20;
    }
    goto skip_0;
    // 0x8051EF00: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    skip_0:
    // 0x8051EF04: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8051EF08: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8051EF0C: jal         0x8006E0FC
    // 0x8051EF10: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x8051EF10: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8051EF14: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8051EF18: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8051EF1C: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
L_8051EF20:
    // 0x8051EF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051EF24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051EF28: jr          $ra
    // 0x8051EF2C: nop

    return;
    // 0x8051EF2C: nop

;}
RECOMP_FUNC void func_8046932C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046932C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80469330: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80469334: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80469338: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8046933C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80469340: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80469344: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80469348: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8046934C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80469350: jal         0x80062818
    // 0x80469354: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    func_80062818(rdram, ctx);
        goto after_0;
    // 0x80469354: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80469358: jal         0x804690B8
    // 0x8046935C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_804690B8(rdram, ctx);
        goto after_1;
    // 0x8046935C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80469360: jal         0x80469028
    // 0x80469364: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80469028(rdram, ctx);
        goto after_2;
    // 0x80469364: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80469368: lhu         $t6, 0x0($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X0);
    // 0x8046936C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80469370: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80469374: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x80469378: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
    // 0x8046937C: addiu       $s4, $zero, 0x50
    ctx->r20 = ADD32(0, 0X50);
    // 0x80469380: addiu       $s3, $zero, 0x4001
    ctx->r19 = ADD32(0, 0X4001);
L_80469384:
    // 0x80469384: lw          $a1, 0x188($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X188);
    // 0x80469388: beql        $a1, $zero, L_804693A8
    if (ctx->r5 == 0) {
        // 0x8046938C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804693A8;
    }
    goto skip_0;
    // 0x8046938C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80469390: lhu         $t8, 0xC($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XC);
    // 0x80469394: bnel        $s3, $t8, L_804693A8
    if (ctx->r19 != ctx->r24) {
        // 0x80469398: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804693A8;
    }
    goto skip_1;
    // 0x80469398: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x8046939C: jal         0x80469100
    // 0x804693A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80469100(rdram, ctx);
        goto after_3;
    // 0x804693A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x804693A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804693A8:
    // 0x804693A8: bne         $s0, $s4, L_80469384
    if (ctx->r16 != ctx->r20) {
        // 0x804693AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80469384;
    }
    // 0x804693AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804693B0: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x804693B4: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x804693B8: beq         $t9, $zero, L_804693CC
    if (ctx->r25 == 0) {
        // 0x804693BC: andi        $t1, $v0, 0xFFFE
        ctx->r9 = ctx->r2 & 0XFFFE;
            goto L_804693CC;
    }
    // 0x804693BC: andi        $t1, $v0, 0xFFFE
    ctx->r9 = ctx->r2 & 0XFFFE;
    // 0x804693C0: ori         $t0, $v0, 0x1
    ctx->r8 = ctx->r2 | 0X1;
    // 0x804693C4: b           L_804693D0
    // 0x804693C8: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
        goto L_804693D0;
    // 0x804693C8: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
L_804693CC:
    // 0x804693CC: sh          $t1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r9;
L_804693D0:
    // 0x804693D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x804693D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804693D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804693DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x804693E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x804693E4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x804693E8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x804693EC: jr          $ra
    // 0x804693F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804693F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
