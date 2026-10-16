#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8043D040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D040: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8043D044: addiu       $at, $zero, 0x406B
    ctx->r1 = ADD32(0, 0X406B);
    // 0x8043D048: beq         $v0, $at, L_8043D060
    if (ctx->r2 == ctx->r1) {
        // 0x8043D04C: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8043D060;
    }
    // 0x8043D04C: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8043D050: beq         $v0, $at, L_8043D06C
    if (ctx->r2 == ctx->r1) {
        // 0x8043D054: nop
    
            goto L_8043D06C;
    }
    // 0x8043D054: nop

    // 0x8043D058: jr          $ra
    // 0x8043D05C: nop

    return;
    // 0x8043D05C: nop

L_8043D060:
    // 0x8043D060: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1000) << 16);
    // 0x8043D064: jr          $ra
    // 0x8043D068: addiu       $v0, $v0, -0x1FC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(92, 0X1000));
    return;
    // 0x8043D068: addiu       $v0, $v0, -0x1FC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(92, 0X1000));
L_8043D06C:
    // 0x8043D06C: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1884) << 16);
    // 0x8043D070: addiu       $v0, $v0, -0x173C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(92, 0X1884));
    // 0x8043D074: jr          $ra
    // 0x8043D078: nop

    return;
    // 0x8043D078: nop

;}
RECOMP_FUNC void func_80409CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409CD0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80409CD4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80409CD8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80409CDC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409CE0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80409CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80409CE8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80409CEC:
    // 0x80409CEC: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80409CF0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80409CF4: bnel        $t6, $zero, L_80409D58
    if (ctx->r14 != 0) {
        // 0x80409CF8: lw          $t2, 0x58($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X58);
            goto L_80409D58;
    }
    goto skip_0;
    // 0x80409CF8: lw          $t2, 0x58($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X58);
    skip_0:
    // 0x80409CFC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409D00: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409D04: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409D08: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E1C) << 16);
    // 0x80409D0C: lwc1        $f4, -0x5814($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E1C));
    // 0x80409D10: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80409D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409D18: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X1F38) << 16);
    // 0x80409D1C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80409D20: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80409D24: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80409D28: addiu       $t0, $t0, -0x66F8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(11, 0X1F38));
    // 0x80409D2C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80409D30: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80409D34: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80409D38: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x80409D3C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409D40: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80409D44: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80409D48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409D4C: b           L_80409E98
    // 0x80409D50: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
        goto L_80409E98;
    // 0x80409D50: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80409D54: lw          $t2, 0x58($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X58);
L_80409D58:
    // 0x80409D58: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409D5C: bnel        $t2, $zero, L_80409DC0
    if (ctx->r10 != 0) {
        // 0x80409D60: lw          $t8, 0x58($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X58);
            goto L_80409DC0;
    }
    goto skip_1;
    // 0x80409D60: lw          $t8, 0x58($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X58);
    skip_1:
    // 0x80409D64: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409D68: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409D6C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409D70: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E20) << 16);
    // 0x80409D74: lwc1        $f8, -0x5810($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E20));
    // 0x80409D78: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80409D7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80409D80: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X1F38) << 16);
    // 0x80409D84: addiu       $t6, $t6, -0x66F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X1F38));
    // 0x80409D88: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80409D8C: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80409D90: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80409D94: sw          $t5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r13;
    // 0x80409D98: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80409D9C: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x80409DA0: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x80409DA4: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80409DA8: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80409DAC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80409DB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409DB4: b           L_80409E98
    // 0x80409DB8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
        goto L_80409E98;
    // 0x80409DB8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80409DBC: lw          $t8, 0x58($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X58);
L_80409DC0:
    // 0x80409DC0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409DC4: bnel        $t8, $zero, L_80409E28
    if (ctx->r24 != 0) {
        // 0x80409DC8: lw          $t4, 0x58($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X58);
            goto L_80409E28;
    }
    goto skip_2;
    // 0x80409DC8: lw          $t4, 0x58($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X58);
    skip_2:
    // 0x80409DCC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409DD0: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409DD4: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409DD8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E24) << 16);
    // 0x80409DDC: lwc1        $f16, -0x580C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E24));
    // 0x80409DE0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80409DE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80409DE8: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(11, 0X1F38) << 16);
    // 0x80409DEC: addiu       $t2, $t2, -0x66F8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(11, 0X1F38));
    // 0x80409DF0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80409DF4: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80409DF8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80409DFC: sw          $t1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r9;
    // 0x80409E00: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x80409E04: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x80409E08: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    // 0x80409E0C: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80409E10: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80409E14: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80409E18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409E1C: b           L_80409E98
    // 0x80409E20: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
        goto L_80409E98;
    // 0x80409E20: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x80409E24: lw          $t4, 0x58($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X58);
L_80409E28:
    // 0x80409E28: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409E2C: bne         $t4, $zero, L_80409E8C
    if (ctx->r12 != 0) {
        // 0x80409E30: nop
    
            goto L_80409E8C;
    }
    // 0x80409E30: nop

    // 0x80409E34: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409E38: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409E3C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409E40: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E28) << 16);
    // 0x80409E44: lwc1        $f4, -0x5808($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E28));
    // 0x80409E48: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80409E4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409E50: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X1F38) << 16);
    // 0x80409E54: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(11, 0X1F38));
    // 0x80409E58: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80409E5C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80409E60: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80409E64: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x80409E68: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x80409E6C: sw          $t5, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r13;
    // 0x80409E70: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x80409E74: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409E78: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80409E7C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80409E80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409E84: b           L_80409E98
    // 0x80409E88: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
        goto L_80409E98;
    // 0x80409E88: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
L_80409E8C:
    // 0x80409E8C: bne         $v0, $v1, L_80409CEC
    if (ctx->r2 != ctx->r3) {
        // 0x80409E90: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_80409CEC;
    }
    // 0x80409E90: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80409E98:
    // 0x80409E98: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80409E9C: jr          $ra
    // 0x80409EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80409EA0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80446180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446180: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446184: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446188: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044618C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446190: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80446194: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446198: jr          $ra
    // 0x8044619C: sw          $t7, 0x6CA4($at)
    MEM_W(0X6CA4, ctx->r1) = ctx->r15;
    return;
    // 0x8044619C: sw          $t7, 0x6CA4($at)
    MEM_W(0X6CA4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8040DFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040DFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040DFE0: jal         0x8040DCF0
    // 0x8040DFE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040DFE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040DFE8: bne         $v0, $zero, L_8040E000
    if (ctx->r2 != 0) {
        // 0x8040DFEC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040E000;
    }
    // 0x8040DFEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040DFF0: jal         0x800445A4
    // 0x8040DFF4: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040DFF4: nop

    after_1:
    // 0x8040DFF8: b           L_8040E028
    // 0x8040DFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040E028;
    // 0x8040DFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E000:
    // 0x8040E000: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E004: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8040E008: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040E00C: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x8040E010: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8040E014: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040E018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E01C: jal         0x8040E254
    // 0x8040E020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040E020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040E024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E028:
    // 0x8040E028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E02C: jr          $ra
    // 0x8040E030: nop

    return;
    // 0x8040E030: nop

;}
RECOMP_FUNC void func_804A23E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A23E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804A23E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A23E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A23EC: jal         0x804A2910
    // 0x804A23F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A23F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804A23F4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x804A23F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804A23FC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804A2400: jal         0x80048F84
    // 0x804A2404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804A2404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804A2408: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804A240C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A2410: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x804A2414: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804A2418: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804A241C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804A2420: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804A2424: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x804A2428: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A242C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x804A2430: nop

    // 0x804A2434: bc1fl       L_804A24E8
    if (!c1cs) {
        // 0x804A2438: lw          $t8, 0x1E0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1E0);
            goto L_804A24E8;
    }
    goto skip_0;
    // 0x804A2438: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x804A243C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804A2440: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X31AC) << 16);
    // 0x804A2444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2448: swc1        $f18, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f18.u32l;
    // 0x804A244C: lwc1        $f4, 0x35EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X31AC));
    // 0x804A2450: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x804A2454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A2458: swc1        $f4, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f4.u32l;
    // 0x804A245C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A2460: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x804A2464: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A2468: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804A246C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x804A2470: jal         0x804A27A0
    // 0x804A2474: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A2474: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    after_2:
    // 0x804A2478: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x804A247C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x804A2480: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x804A2484: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x804A2488: jal         0x8004613C
    // 0x804A248C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x804A248C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_3:
    // 0x804A2490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804A2498: jal         0x80047F9C
    // 0x804A249C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x804A249C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
    // 0x804A24A0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x804A24A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A24A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A24AC: sb          $v0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r2;
    // 0x804A24B0: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A24B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A24B8: sw          $v1, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r3;
    // 0x804A24BC: jal         0x804A13E8
    // 0x804A24C0: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    func_804A13E8(rdram, ctx);
        goto after_5;
    // 0x804A24C0: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    after_5:
    // 0x804A24C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804A24C8: jal         0x80067E98
    // 0x804A24CC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_80067E98(rdram, ctx);
        goto after_6;
    // 0x804A24CC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x804A24D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x804A24D4: jal         0x80067818
    // 0x804A24D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x804A24D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x804A24DC: b           L_804A2524
    // 0x804A24E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A2524;
    // 0x804A24E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A24E4: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
L_804A24E8:
    // 0x804A24E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A24EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804A24F0: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x804A24F4: bne         $at, $zero, L_804A2520
    if (ctx->r1 != 0) {
        // 0x804A24F8: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_804A2520;
    }
    // 0x804A24F8: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x804A24FC: jal         0x804A13E8
    // 0x804A2500: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_804A13E8(rdram, ctx);
        goto after_8;
    // 0x804A2500: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_8:
    // 0x804A2504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804A2508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A250C: jal         0x80067ED8
    // 0x804A2510: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_9;
    // 0x804A2510: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_9:
    // 0x804A2514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804A2518: jal         0x80067818
    // 0x804A251C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x804A251C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_804A2520:
    // 0x804A2520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A2524:
    // 0x804A2524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A2528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804A252C: jr          $ra
    // 0x804A2530: nop

    return;
    // 0x804A2530: nop

;}
RECOMP_FUNC void func_8043D1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D1D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043D1D8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B68) << 16);
    // 0x8043D1DC: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8043D1E0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8043D1E4: lwc1        $f4, -0x1458($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B68));
    // 0x8043D1E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8043D1EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043D1F0: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x8043D1F4: jr          $ra
    // 0x8043D1F8: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8043D1F8: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_806994E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806994E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806994E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806994E8: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806994EC: addiu       $t7, $t6, -0x4584
    ctx->r15 = ADD32(ctx->r14, -0X4584);
    // 0x806994F0: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x806994F4: beq         $at, $zero, L_806995A8
    if (ctx->r1 == 0) {
        // 0x806994F8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_806995A8;
    }
    // 0x806994F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806994FC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(562, 0X1650) << 16);
    // 0x80699500: addu        $at, $at, $t7
    gpr jr_addend_80699508 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80699504: lw          $t7, -0x54E0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(562, 0X1650));
    // 0x80699508: jr          $t7
    // 0x8069950C: nop

    switch (jr_addend_80699508 >> 2) {
        case 0: goto L_80699510; break;
        case 1: goto L_80699520; break;
        case 2: goto L_80699530; break;
        case 3: goto L_80699540; break;
        case 4: goto L_80699550; break;
        case 5: goto L_80699560; break;
        case 6: goto L_80699570; break;
        case 7: goto L_80699580; break;
        case 8: goto L_80699590; break;
        case 9: goto L_806995A0; break;
        default: switch_error(__func__, 0x80699508, 0x8069AB20);
    }
    // 0x8069950C: nop

L_80699510:
    // 0x80699510: jal         0x80699EF8
    // 0x80699514: nop

    func_80699EF8(rdram, ctx);
        goto after_0;
    // 0x80699514: nop

    after_0:
    // 0x80699518: b           L_806995AC
    // 0x8069951C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069951C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699520:
    // 0x80699520: jal         0x80699F30
    // 0x80699524: nop

    func_80699F30(rdram, ctx);
        goto after_1;
    // 0x80699524: nop

    after_1:
    // 0x80699528: b           L_806995AC
    // 0x8069952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699530:
    // 0x80699530: jal         0x80699F60
    // 0x80699534: nop

    func_80699F60(rdram, ctx);
        goto after_2;
    // 0x80699534: nop

    after_2:
    // 0x80699538: b           L_806995AC
    // 0x8069953C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069953C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699540:
    // 0x80699540: jal         0x80699F90
    // 0x80699544: nop

    func_80699F90(rdram, ctx);
        goto after_3;
    // 0x80699544: nop

    after_3:
    // 0x80699548: b           L_806995AC
    // 0x8069954C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069954C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699550:
    // 0x80699550: jal         0x80699FC8
    // 0x80699554: nop

    func_80699FC8(rdram, ctx);
        goto after_4;
    // 0x80699554: nop

    after_4:
    // 0x80699558: b           L_806995AC
    // 0x8069955C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069955C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699560:
    // 0x80699560: jal         0x80699FF8
    // 0x80699564: nop

    func_80699FF8(rdram, ctx);
        goto after_5;
    // 0x80699564: nop

    after_5:
    // 0x80699568: b           L_806995AC
    // 0x8069956C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069956C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699570:
    // 0x80699570: jal         0x8069A028
    // 0x80699574: nop

    func_8069A028(rdram, ctx);
        goto after_6;
    // 0x80699574: nop

    after_6:
    // 0x80699578: b           L_806995AC
    // 0x8069957C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069957C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699580:
    // 0x80699580: jal         0x8069A058
    // 0x80699584: nop

    func_8069A058(rdram, ctx);
        goto after_7;
    // 0x80699584: nop

    after_7:
    // 0x80699588: b           L_806995AC
    // 0x8069958C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069958C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80699590:
    // 0x80699590: jal         0x8069A088
    // 0x80699594: nop

    func_8069A088(rdram, ctx);
        goto after_8;
    // 0x80699594: nop

    after_8:
    // 0x80699598: b           L_806995AC
    // 0x8069959C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806995AC;
    // 0x8069959C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806995A0:
    // 0x806995A0: jal         0x8069A0B8
    // 0x806995A4: nop

    func_8069A0B8(rdram, ctx);
        goto after_9;
    // 0x806995A4: nop

    after_9:
L_806995A8:
    // 0x806995A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806995AC:
    // 0x806995AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806995B0: jr          $ra
    // 0x806995B4: nop

    return;
    // 0x806995B4: nop

;}
RECOMP_FUNC void func_8058454C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058454C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584550: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584554: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584558: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058455C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584560: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584564: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584568: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058456C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584570: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584574: jr          $ra
    // 0x80584578: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584578: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8041E694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041E698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E69C: jal         0x8004700C
    // 0x8041E6A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8041E6A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041E6A4: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8041E6A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041E6AC: beq         $v0, $zero, L_8041E6CC
    if (ctx->r2 == 0) {
        // 0x8041E6B0: lw          $v1, -0x7CE8($v1)
        ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
            goto L_8041E6CC;
    }
    // 0x8041E6B0: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x8041E6B4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8041E6B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E6BC: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8041E6C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8041E6C4: b           L_8041E6E0
    // 0x8041E6C8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
        goto L_8041E6E0;
    // 0x8041E6C8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
L_8041E6CC:
    // 0x8041E6CC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8041E6D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041E6D4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8041E6D8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8041E6DC: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
L_8041E6E0:
    // 0x8041E6E0: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8041E6E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8041E6E8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8041E6EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E6F0: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8041E6F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041E6F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8041E6FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041E700: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x8041E704: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8041E708: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8041E70C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8041E710: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8041E714: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8041E718: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8041E71C: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x8041E720: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x8041E724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041E72C: jr          $ra
    // 0x8041E730: nop

    return;
    // 0x8041E730: nop

;}
RECOMP_FUNC void func_80438EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438EC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438EC4: lw          $t6, 0xAAC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAAC);
    // 0x80438EC8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80438ECC: slti        $at, $t7, 0x32
    ctx->r1 = SIGNED(ctx->r15) < 0X32 ? 1 : 0;
    // 0x80438ED0: bne         $at, $zero, L_80438EDC
    if (ctx->r1 != 0) {
        // 0x80438ED4: sw          $t7, 0xAAC($v0)
        MEM_W(0XAAC, ctx->r2) = ctx->r15;
            goto L_80438EDC;
    }
    // 0x80438ED4: sw          $t7, 0xAAC($v0)
    MEM_W(0XAAC, ctx->r2) = ctx->r15;
    // 0x80438ED8: sw          $zero, 0xAAC($v0)
    MEM_W(0XAAC, ctx->r2) = 0;
L_80438EDC:
    // 0x80438EDC: jr          $ra
    // 0x80438EE0: nop

    return;
    // 0x80438EE0: nop

;}
RECOMP_FUNC void func_8004E658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E658: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8004E65C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8004E660: lw          $t6, 0xA68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XA68);
    // 0x8004E664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E66C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8004E670: lw          $v0, 0x70($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X70);
    // 0x8004E674: beql        $v0, $zero, L_8004E6FC
    if (ctx->r2 == 0) {
        // 0x8004E678: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E6FC;
    }
    goto skip_0;
    // 0x8004E678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004E67C: lbu         $t8, 0x1D($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1D);
    // 0x8004E680: beql        $t8, $zero, L_8004E6FC
    if (ctx->r24 == 0) {
        // 0x8004E684: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E6FC;
    }
    goto skip_1;
    // 0x8004E684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004E688: lw          $t9, 0xD8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XD8);
    // 0x8004E68C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004E690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004E694: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8004E698: beql        $t0, $zero, L_8004E6FC
    if (ctx->r8 == 0) {
        // 0x8004E69C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E6FC;
    }
    goto skip_2;
    // 0x8004E69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8004E6A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E6A4: lwc1        $f0, 0xC8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8004E6A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004E6AC: nop

    // 0x8004E6B0: bc1fl       L_8004E6C0
    if (!c1cs) {
        // 0x8004E6B4: lwc1        $f4, 0x8C($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
            goto L_8004E6C0;
    }
    goto skip_3;
    // 0x8004E6B4: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    skip_3:
    // 0x8004E6B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8004E6BC: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
L_8004E6C0:
    // 0x8004E6C0: lwc1        $f6, 0x8F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X8F0);
    // 0x8004E6C4: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8004E6C8: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8004E6CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004E6D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004E6D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E6D8: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x8004E6DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8004E6E0: jalr        $v0
    // 0x8004E6E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8004E6E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004E6E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004E6EC: lbu         $t2, 0x1D($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1D);
    // 0x8004E6F0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8004E6F4: sb          $t3, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r11;
    // 0x8004E6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E6FC:
    // 0x8004E6FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E700: jr          $ra
    // 0x8004E704: nop

    return;
    // 0x8004E704: nop

;}
RECOMP_FUNC void func_807605DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807605DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807605E0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807605E4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807605E8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807605EC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807605F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807605F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807605F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807605FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760600: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760604: jr          $ra
    // 0x80760608: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760608: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80675488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067548C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675490: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80675494: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80675498: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(532, 0X620) << 16);
    // 0x8067549C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806754A0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806754A4: addiu       $t7, $t7, 0x5570
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(532, 0X620));
    // 0x806754A8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806754AC: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(532, 0X318) << 16);
    // 0x806754B0: addiu       $t9, $t9, 0x5268
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(532, 0X318));
    // 0x806754B4: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    // 0x806754B8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806754BC: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806754C0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806754C4: jal         0x80675470
    // 0x806754C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80675470(rdram, ctx);
        goto after_0;
    // 0x806754C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806754CC: jal         0x8005FDC4
    // 0x806754D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x806754D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806754D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806754D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806754DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806754E0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806754E4: jr          $ra
    // 0x806754E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806754E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80682CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682CE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682CE8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682CEC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682CF0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682CF4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682CF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682CFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682D00: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682D04: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682D08: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682D0C: jr          $ra
    // 0x80682D10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682D10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80519078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051907C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519080: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80519084: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(291, 0X2558) << 16);
    // 0x80519088: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051908C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80519090: lw          $v0, -0x5E38($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(291, 0X2558));
    // 0x80519094: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80519098: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8051909C: beql        $v1, $zero, L_805190B0
    if (ctx->r3 == 0) {
        // 0x805190A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805190B0;
    }
    goto skip_0;
    // 0x805190A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805190A4: jalr        $v1
    // 0x805190A8: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805190A8: nop

    after_0:
    // 0x805190AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805190B0:
    // 0x805190B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805190B4: jr          $ra
    // 0x805190B8: nop

    return;
    // 0x805190B8: nop

;}
RECOMP_FUNC void func_805847BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805847BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805847C0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805847C4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805847C8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805847CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805847D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805847D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805847D8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805847DC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805847E0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805847E4: jr          $ra
    // 0x805847E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805847E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044BA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BA4C: jal         0x8044B740
    // 0x8044BA50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BA50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8044BA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BA5C: jr          $ra
    // 0x8044BA60: nop

    return;
    // 0x8044BA60: nop

;}
RECOMP_FUNC void func_804A50F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A50F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A50F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A50FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A5100: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A5104: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A5108: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A510C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5110: lw          $v1, 0x6EDC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EDC);
    // 0x804A5114: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A5118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A511C: bne         $v1, $zero, L_804A514C
    if (ctx->r3 != 0) {
        // 0x804A5120: nop
    
            goto L_804A514C;
    }
    // 0x804A5120: nop

    // 0x804A5124: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A5128: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A512C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A5130: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A5134: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A5138: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A513C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A5140: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A5144: b           L_804A5154
    // 0x804A5148: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A5154;
    // 0x804A5148: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A514C:
    // 0x804A514C: jal         0x804A4DD4
    // 0x804A5150: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_804A4DD4(rdram, ctx);
        goto after_0;
    // 0x804A5150: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_0:
L_804A5154:
    // 0x804A5154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A5158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A515C: jr          $ra
    // 0x804A5160: nop

    return;
    // 0x804A5160: nop

;}
RECOMP_FUNC void func_807BA308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA308: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807BA30C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x807BA310: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(889, 0XA0) << 16);
    // 0x807BA314: sb          $v1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r3;
    // 0x807BA318: addiu       $t6, $t6, -0x5C70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(889, 0XA0));
    // 0x807BA31C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807BA320: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x807BA324: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x807BA328: lui         $t4, 0x807C
    ctx->r12 = S32(RELOC_HI16(889, 0X10) << 16);
    // 0x807BA32C: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x807BA330: bne         $t9, $at, L_807BA34C
    if (ctx->r25 != ctx->r1) {
        // 0x807BA334: addiu       $t4, $t4, -0x5D00
        ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(889, 0X10));
            goto L_807BA34C;
    }
    // 0x807BA334: addiu       $t4, $t4, -0x5D00
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(889, 0X10));
    // 0x807BA338: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807BA33C: lw          $t0, -0x76C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76C0);
    // 0x807BA340: addiu       $t1, $t0, 0x3
    ctx->r9 = ADD32(ctx->r8, 0X3);
    // 0x807BA344: b           L_807BA370
    // 0x807BA348: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_807BA370;
    // 0x807BA348: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_807BA34C:
    // 0x807BA34C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807BA350: lw          $v0, -0x7250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7250);
    // 0x807BA354: lui         $t3, 0x807C
    ctx->r11 = S32(RELOC_HI16(889, 0XA4) << 16);
    // 0x807BA358: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x807BA35C: beq         $at, $zero, L_807BA370
    if (ctx->r1 == 0) {
        // 0x807BA360: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_807BA370;
    }
    // 0x807BA360: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x807BA364: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x807BA368: lh          $t3, -0x5C6C($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(889, 0XA4));
    // 0x807BA36C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_807BA370:
    // 0x807BA370: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x807BA374: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x807BA378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807BA37C: jr          $ra
    // 0x807BA380: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
    return;
    // 0x807BA380: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
    // 0x807BA384: nop

    // 0x807BA388: nop

    // 0x807BA38C: nop

;}
RECOMP_FUNC void func_806D7830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D7830: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D7834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D7838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D783C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806D7840: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x806D7844: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D7848: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806D784C: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x806D7850: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x806D7854: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x806D7858: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D785C: jal         0x80045A34
    // 0x806D7860: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D7860: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x806D7864: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806D7868: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806D786C: bne         $v0, $zero, L_806D7884
    if (ctx->r2 != 0) {
        // 0x806D7870: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_806D7884;
    }
    // 0x806D7870: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806D7874: jal         0x800445A4
    // 0x806D7878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D7878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D787C: b           L_806D7A10
    // 0x806D7880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D7A10;
    // 0x806D7880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D7884:
    // 0x806D7884: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
    // 0x806D7888: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x806D788C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806D7890: beq         $v1, $zero, L_806D795C
    if (ctx->r3 == 0) {
        // 0x806D7894: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_806D795C;
    }
    // 0x806D7894: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806D7898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D789C: beq         $v1, $at, L_806D78C4
    if (ctx->r3 == ctx->r1) {
        // 0x806D78A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D78C4;
    }
    // 0x806D78A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D78A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D78A8: beq         $v1, $at, L_806D78F8
    if (ctx->r3 == ctx->r1) {
        // 0x806D78AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D78F8;
    }
    // 0x806D78AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D78B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806D78B4: beq         $v1, $at, L_806D7928
    if (ctx->r3 == ctx->r1) {
        // 0x806D78B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D7928;
    }
    // 0x806D78B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D78BC: b           L_806D7988
    // 0x806D78C0: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
        goto L_806D7988;
    // 0x806D78C0: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
L_806D78C4:
    // 0x806D78C4: jal         0x8004590C
    // 0x806D78C8: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x806D78C8: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    after_2:
    // 0x806D78CC: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x806D78D0: addiu       $t8, $zero, 0x2242
    ctx->r24 = ADD32(0, 0X2242);
    // 0x806D78D4: addiu       $t1, $zero, 0x2244
    ctx->r9 = ADD32(0, 0X2244);
    // 0x806D78D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806D78DC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x806D78E0: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x806D78E4: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x806D78E8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x806D78EC: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x806D78F0: b           L_806D7984
    // 0x806D78F4: sw          $t4, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r12;
        goto L_806D7984;
    // 0x806D78F4: sw          $t4, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r12;
L_806D78F8:
    // 0x806D78F8: jal         0x8004590C
    // 0x806D78FC: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x806D78FC: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    after_3:
    // 0x806D7900: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806D7904: addiu       $t5, $zero, 0x4222
    ctx->r13 = ADD32(0, 0X4222);
    // 0x806D7908: addiu       $t9, $zero, 0x2244
    ctx->r25 = ADD32(0, 0X2244);
    // 0x806D790C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806D7910: sh          $t5, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r13;
    // 0x806D7914: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x806D7918: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x806D791C: sh          $t9, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r25;
    // 0x806D7920: b           L_806D7984
    // 0x806D7924: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_806D7984;
    // 0x806D7924: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_806D7928:
    // 0x806D7928: jal         0x8004590C
    // 0x806D792C: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x806D792C: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    after_4:
    // 0x806D7930: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x806D7934: addiu       $t2, $zero, 0x2224
    ctx->r10 = ADD32(0, 0X2224);
    // 0x806D7938: addiu       $t4, $zero, 0x4244
    ctx->r12 = ADD32(0, 0X4244);
    // 0x806D793C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x806D7940: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x806D7944: sh          $t2, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r10;
    // 0x806D7948: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806D794C: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x806D7950: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x806D7954: b           L_806D7984
    // 0x806D7958: sw          $t7, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r15;
        goto L_806D7984;
    // 0x806D7958: sw          $t7, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r15;
L_806D795C:
    // 0x806D795C: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x806D7960: addiu       $t8, $zero, 0x2422
    ctx->r24 = ADD32(0, 0X2422);
    // 0x806D7964: addiu       $t1, $zero, 0x2444
    ctx->r9 = ADD32(0, 0X2444);
    // 0x806D7968: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806D796C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D7970: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x806D7974: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x806D7978: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x806D797C: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x806D7980: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
L_806D7984:
    // 0x806D7984: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
L_806D7988:
    // 0x806D7988: lui         $t4, 0x806E
    ctx->r12 = S32(RELOC_HI16(622, 0X1B0C) << 16);
    // 0x806D798C: addiu       $t4, $t4, -0x7944
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(622, 0X1B0C));
    // 0x806D7990: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x806D7994: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D7998: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806D799C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x806D79A0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806D79A4: sw          $t7, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r15;
    // 0x806D79A8: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x806D79AC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x806D79B0: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x806D79B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806D79B8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x806D79BC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x806D79C0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806D79C4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D79C8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B74) << 16);
    // 0x806D79CC: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D79D0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x806D79D4: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D79D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D79DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D79E0: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x806D79E4: lwc1        $f16, -0x78DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B74));
    // 0x806D79E8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1AFC) << 16);
    // 0x806D79EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D79F0: swc1        $f16, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f16.u32l;
    // 0x806D79F4: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806D79F8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x806D79FC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x806D7A00: lwc1        $f18, -0x7954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1AFC));
    // 0x806D7A04: jal         0x806D7A20
    // 0x806D7A08: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    func_806D7A20(rdram, ctx);
        goto after_5;
    // 0x806D7A08: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    after_5:
    // 0x806D7A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D7A10:
    // 0x806D7A10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D7A14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D7A18: jr          $ra
    // 0x806D7A1C: nop

    return;
    // 0x806D7A1C: nop

;}
RECOMP_FUNC void func_8067BEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BEF4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8067BEF8: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8067BEFC: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x8067BF00: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067BF04: jr          $ra
    // 0x8067BF08: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8067BF08: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8079C140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079C140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079C144: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8079C148: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8079C14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079C150: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079C154: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8079C158: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8079C15C: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(829, 0XAFC) << 16);
    // 0x8079C160: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079C164: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8079C168: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8079C16C: lw          $t9, -0x3D94($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(829, 0XAFC));
    // 0x8079C170: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8079C174: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8079C178: jal         0x8079B7F4
    // 0x8079C17C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079B7F4(rdram, ctx);
        goto after_0;
    // 0x8079C17C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079C180: jal         0x8079B954
    // 0x8079C184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8079B954(rdram, ctx);
        goto after_1;
    // 0x8079C184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8079C188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079C18C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079C190: jr          $ra
    // 0x8079C194: nop

    return;
    // 0x8079C194: nop

    // 0x8079C198: nop

    // 0x8079C19C: nop

;}
RECOMP_FUNC void func_8005FA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FA94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FA9C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FAA0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FAA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FAA8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FAAC: lbu         $t7, 0x76($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X76);
    // 0x8005FAB0: beql        $t7, $zero, L_8005FAD4
    if (ctx->r15 == 0) {
        // 0x8005FAB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FAD4;
    }
    goto skip_0;
    // 0x8005FAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FAB8: jal         0x8005F9F4
    // 0x8005FABC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8005F9F4(rdram, ctx);
        goto after_0;
    // 0x8005FABC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FAC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005FAC4: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8005FAC8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005FACC: sb          $zero, 0x76($t9)
    MEM_B(0X76, ctx->r25) = 0;
    // 0x8005FAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FAD4:
    // 0x8005FAD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FAD8: jr          $ra
    // 0x8005FADC: nop

    return;
    // 0x8005FADC: nop

;}
RECOMP_FUNC void func_80683074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80683074: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80683078: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8068307C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80683080: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80683084: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80683088: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8068308C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683090: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683094: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683098: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068309C: jr          $ra
    // 0x806830A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806830A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80057C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057C08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057C10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80057C14: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x80057C18: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80057C1C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80057C20: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80057C24: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80057C28: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80057C2C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80057C30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80057C34: beq         $t8, $zero, L_80057C44
    if (ctx->r24 == 0) {
        // 0x80057C38: srl         $t1, $t0, 28
        ctx->r9 = S32(U32(ctx->r8) >> 28);
            goto L_80057C44;
    }
    // 0x80057C38: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x80057C3C: b           L_80057C8C
    // 0x80057C40: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
        goto L_80057C8C;
    // 0x80057C40: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80057C44:
    // 0x80057C44: beq         $t1, $zero, L_80057C64
    if (ctx->r9 == 0) {
        // 0x80057C48: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80057C64;
    }
    // 0x80057C48: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80057C4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80057C50: addiu       $a0, $a0, 0xB60
    ctx->r4 = ADD32(ctx->r4, 0XB60);
    // 0x80057C54: jal         0x80071380
    // 0x80057C58: addiu       $a1, $zero, 0xD6
    ctx->r5 = ADD32(0, 0XD6);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80057C58: addiu       $a1, $zero, 0xD6
    ctx->r5 = ADD32(0, 0XD6);
    after_0:
    // 0x80057C5C: b           L_80057C8C
    // 0x80057C60: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
        goto L_80057C8C;
    // 0x80057C60: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80057C64:
    // 0x80057C64: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80057C68: lh          $t3, 0x6($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X6);
    // 0x80057C6C: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80057C70: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x80057C74: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80057C78: sh          $t4, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r12;
    // 0x80057C7C: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // 0x80057C80: jal         0x8006515C
    // 0x80057C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006515C(rdram, ctx);
        goto after_1;
    // 0x80057C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80057C88: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
L_80057C8C:
    // 0x80057C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057C90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057C94: jr          $ra
    // 0x80057C98: nop

    return;
    // 0x80057C98: nop

;}
RECOMP_FUNC void func_804422D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804422D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804422D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804422D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804422DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804422E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804422E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x804422E8: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804422EC: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x804422F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804422F4: bnel        $t6, $at, L_80442370
    if (ctx->r14 != ctx->r1) {
        // 0x804422F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80442370;
    }
    goto skip_0;
    // 0x804422F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804422FC: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x80442300: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80442304: bnel        $t7, $at, L_80442370
    if (ctx->r15 != ctx->r1) {
        // 0x80442308: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80442370;
    }
    goto skip_1;
    // 0x80442308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8044230C: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x80442310: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80442314: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80442318: bnel        $t8, $at, L_80442370
    if (ctx->r24 != ctx->r1) {
        // 0x8044231C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80442370;
    }
    goto skip_2;
    // 0x8044231C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80442320: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80442324: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x80442328: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8044232C: lw          $t9, -0x72E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72E8);
    // 0x80442330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80442334: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x80442338: jalr        $t9
    // 0x8044233C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8044233C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80442340: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80442344: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80442348: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8044234C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80442350: jal         0x80067D5C
    // 0x80442354: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x80442354: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_1:
    // 0x80442358: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8044235C: jal         0x80067818
    // 0x80442360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80442360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80442364: jal         0x800447C8
    // 0x80442368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x80442368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8044236C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80442370:
    // 0x80442370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80442374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80442378: jr          $ra
    // 0x8044237C: nop

    return;
    // 0x8044237C: nop

;}
RECOMP_FUNC void func_807C3EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3EB8: jr          $ra
    // 0x807C3EBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807C3EBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B2DC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005B2E0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8005B2E4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8005B2E8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005B2EC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8005B2F0: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8005B2F4: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x8005B2F8: jr          $ra
    // 0x8005B2FC: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8005B2FC: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_806D68E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D68E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D68E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D68E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D68EC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806D68F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D68F4: jal         0x8004700C
    // 0x806D68F8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D68F8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D68FC: beq         $v0, $zero, L_806D6A64
    if (ctx->r2 == 0) {
        // 0x806D6900: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_806D6A64;
    }
    // 0x806D6900: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x806D6904: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x806D6908: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806D690C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(619, 0X2F4) << 16);
    // 0x806D6910: bne         $t7, $zero, L_806D69D0
    if (ctx->r15 != 0) {
        // 0x806D6914: nop
    
            goto L_806D69D0;
    }
    // 0x806D6914: nop

    // 0x806D6918: lwc1        $f4, 0x6B44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(619, 0X2F4));
    // 0x806D691C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806D6920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D6924: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x806D6928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D692C: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x806D6930: jal         0x80048F84
    // 0x806D6934: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D6934: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x806D6938: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x806D693C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806D6940: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x806D6944: lhu         $t8, 0x4C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4C);
    // 0x806D6948: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x806D694C: bnel        $t9, $zero, L_806D698C
    if (ctx->r25 != 0) {
        // 0x806D6950: lw          $t1, 0x8($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X8);
            goto L_806D698C;
    }
    goto skip_0;
    // 0x806D6950: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
    skip_0:
    // 0x806D6954: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806D6958: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806D695C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D6960: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806D6964: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x806D6968: nop

    // 0x806D696C: bc1fl       L_806D698C
    if (!c1cs) {
        // 0x806D6970: lw          $t1, 0x8($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X8);
            goto L_806D698C;
    }
    goto skip_1;
    // 0x806D6970: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
    skip_1:
    // 0x806D6974: sh          $t0, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r8;
    // 0x806D6978: jal         0x8004A73C
    // 0x806D697C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8004A73C(rdram, ctx);
        goto after_2;
    // 0x806D697C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x806D6980: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806D6984: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x806D6988: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
L_806D698C:
    // 0x806D698C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D6990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D6994: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x806D6998: beq         $t2, $zero, L_806D69D0
    if (ctx->r10 == 0) {
        // 0x806D699C: nop
    
            goto L_806D69D0;
    }
    // 0x806D699C: nop

    // 0x806D69A0: jal         0x80048F84
    // 0x806D69A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x806D69A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x806D69A8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x806D69AC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806D69B0: lbu         $t4, 0x11($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X11);
    // 0x806D69B4: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x806D69B8: beq         $at, $zero, L_806D69D0
    if (ctx->r1 == 0) {
        // 0x806D69BC: lui         $at, 0x806D
        ctx->r1 = S32(RELOC_HI16(619, 0X2F8) << 16);
            goto L_806D69D0;
    }
    // 0x806D69BC: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(619, 0X2F8) << 16);
    // 0x806D69C0: lwc1        $f18, 0x6B48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(619, 0X2F8));
    // 0x806D69C4: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806D69C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806D69CC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_806D69D0:
    // 0x806D69D0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806D69D4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806D69D8: lw          $t5, 0xF10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XF10);
    // 0x806D69DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x806D69E0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x806D69E4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x806D69E8: lw          $t8, 0xF14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XF14);
    // 0x806D69EC: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x806D69F0: bnel        $at, $zero, L_806D6A68
    if (ctx->r1 != 0) {
        // 0x806D69F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D6A68;
    }
    goto skip_2;
    // 0x806D69F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D69F8: lbu         $t0, 0x18($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X18);
    // 0x806D69FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D6A00: bnel        $t0, $at, L_806D6A68
    if (ctx->r8 != ctx->r1) {
        // 0x806D6A04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D6A68;
    }
    goto skip_3;
    // 0x806D6A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806D6A08: lbu         $t1, 0x30($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X30);
    // 0x806D6A0C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x806D6A10: bnel        $t1, $at, L_806D6A68
    if (ctx->r9 != ctx->r1) {
        // 0x806D6A14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D6A68;
    }
    goto skip_4;
    // 0x806D6A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806D6A18: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
    // 0x806D6A1C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806D6A20: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x806D6A24: lbu         $t3, 0xF8($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XF8);
    // 0x806D6A28: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x806D6A2C: beql        $t3, $zero, L_806D6A68
    if (ctx->r11 == 0) {
        // 0x806D6A30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D6A68;
    }
    goto skip_5;
    // 0x806D6A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x806D6A34: lw          $t9, 0xF78($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF78);
    // 0x806D6A38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806D6A3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D6A40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806D6A44: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x806D6A48: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x806D6A4C: jalr        $t9
    // 0x806D6A50: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x806D6A50: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x806D6A54: jal         0x806D6860
    // 0x806D6A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D6860(rdram, ctx);
        goto after_5;
    // 0x806D6A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806D6A5C: jal         0x800447C8
    // 0x806D6A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x806D6A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_806D6A64:
    // 0x806D6A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D6A68:
    // 0x806D6A68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D6A6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D6A70: jr          $ra
    // 0x806D6A74: nop

    return;
    // 0x806D6A74: nop

;}
RECOMP_FUNC void func_807360A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807360A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807360A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807360A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807360AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807360B0: jal         0x80049D74
    // 0x807360B4: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x807360B4: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_0:
    // 0x807360B8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807360BC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x807360C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807360C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807360C8: jal         0x8004D150
    // 0x807360CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x807360CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x807360D0: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x807360D4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807360D8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x807360DC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x807360E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807360E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807360E8: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x807360EC: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x807360F0: beq         $t9, $zero, L_80736108
    if (ctx->r25 == 0) {
        // 0x807360F4: nop
    
            goto L_80736108;
    }
    // 0x807360F4: nop

    // 0x807360F8: jal         0x8073605C
    // 0x807360FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073605C(rdram, ctx);
        goto after_2;
    // 0x807360FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80736100: b           L_80736204
    // 0x80736104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80736204;
    // 0x80736104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80736108:
    // 0x80736108: jal         0x8004D150
    // 0x8073610C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x8073610C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80736110: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80736114: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80736118: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x8073611C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80736120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80736124: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80736128: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8073612C: lbu         $t3, 0x44($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X44);
    // 0x80736130: beq         $t3, $zero, L_80736148
    if (ctx->r11 == 0) {
        // 0x80736134: nop
    
            goto L_80736148;
    }
    // 0x80736134: nop

    // 0x80736138: jal         0x8073605C
    // 0x8073613C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073605C(rdram, ctx);
        goto after_4;
    // 0x8073613C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80736140: b           L_80736204
    // 0x80736144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80736204;
    // 0x80736144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80736148:
    // 0x80736148: jal         0x8004D150
    // 0x8073614C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_5;
    // 0x8073614C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x80736150: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    // 0x80736154: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80736158: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x8073615C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80736160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80736164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736168: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8073616C: lbu         $t7, 0x5C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5C);
    // 0x80736170: beq         $t7, $zero, L_80736188
    if (ctx->r15 == 0) {
        // 0x80736174: nop
    
            goto L_80736188;
    }
    // 0x80736174: nop

    // 0x80736178: jal         0x8073605C
    // 0x8073617C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073605C(rdram, ctx);
        goto after_6;
    // 0x8073617C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80736180: b           L_80736204
    // 0x80736184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80736204;
    // 0x80736184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80736188:
    // 0x80736188: jal         0x8004D150
    // 0x8073618C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_7;
    // 0x8073618C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80736190: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x80736194: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80736198: lw          $v0, 0x40($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X40);
    // 0x8073619C: lbu         $t0, 0x2C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2C);
    // 0x807361A0: beql        $t0, $zero, L_807361BC
    if (ctx->r8 == 0) {
        // 0x807361A4: lbu         $t1, 0x18($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X18);
            goto L_807361BC;
    }
    goto skip_0;
    // 0x807361A4: lbu         $t1, 0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18);
    skip_0:
    // 0x807361A8: jal         0x8073605C
    // 0x807361AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073605C(rdram, ctx);
        goto after_8;
    // 0x807361AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x807361B0: b           L_80736204
    // 0x807361B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80736204;
    // 0x807361B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807361B8: lbu         $t1, 0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18);
L_807361BC:
    // 0x807361BC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x807361C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807361C4: andi        $t2, $t1, 0xF8
    ctx->r10 = ctx->r9 & 0XF8;
    // 0x807361C8: bnel        $t2, $at, L_807361EC
    if (ctx->r10 != ctx->r1) {
        // 0x807361CC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_807361EC;
    }
    goto skip_1;
    // 0x807361CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x807361D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807361D4: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x807361D8: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x807361DC: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x807361E0: b           L_80736204
    // 0x807361E4: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
        goto L_80736204;
    // 0x807361E4: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x807361E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_807361EC:
    // 0x807361EC: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x807361F0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B14) << 16);
    // 0x807361F4: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x807361F8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807361FC: lwc1        $f4, -0x6A8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B14));
    // 0x80736200: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
L_80736204:
    // 0x80736204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80736208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073620C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736210: jr          $ra
    // 0x80736214: nop

    return;
    // 0x80736214: nop

;}
RECOMP_FUNC void func_806E02AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E02AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E02B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E02B4: jal         0x806DF4BC
    // 0x806E02B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806DF4BC(rdram, ctx);
        goto after_0;
    // 0x806E02B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E02BC: jal         0x80045BD8
    // 0x806E02C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x806E02C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806E02C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E02C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E02CC: jr          $ra
    // 0x806E02D0: nop

    return;
    // 0x806E02D0: nop

;}
RECOMP_FUNC void func_806AB72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB72C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AB730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806AB734: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806AB738: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806AB73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AB740: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806AB744: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AB748: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806AB74C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806AB750: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806AB754: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806AB758: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806AB75C: lui         $t2, 0x806B
    ctx->r10 = S32(RELOC_HI16(592, 0X2FC0) << 16);
    // 0x806AB760: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806AB764: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806AB768: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806AB76C: lw          $t2, -0x2460($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(592, 0X2FC0));
    // 0x806AB770: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806AB774: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806AB778: jal         0x806AAC08
    // 0x806AB77C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AAC08(rdram, ctx);
        goto after_0;
    // 0x806AB77C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AB780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AB784: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AB788: beql        $v1, $zero, L_806AB7A4
    if (ctx->r3 == 0) {
        // 0x806AB78C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AB7A4;
    }
    goto skip_0;
    // 0x806AB78C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806AB790: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x806AB794: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x806AB798: jal         0x806AAC8C
    // 0x806AB79C: sh          $t3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r11;
    func_806AAC8C(rdram, ctx);
        goto after_1;
    // 0x806AB79C: sh          $t3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r11;
    after_1:
    // 0x806AB7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806AB7A4:
    // 0x806AB7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AB7A8: jr          $ra
    // 0x806AB7AC: nop

    return;
    // 0x806AB7AC: nop

;}
RECOMP_FUNC void func_80448838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044883C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448840: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448848: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044884C: bne         $a2, $zero, L_8044887C
    if (ctx->r6 != 0) {
        // 0x80448850: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8044887C;
    }
    // 0x80448850: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448854: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80448858: lw          $v1, 0x108($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X108);
    // 0x8044885C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80448860: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80448864: bne         $at, $zero, L_804488BC
    if (ctx->r1 != 0) {
        // 0x80448868: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_804488BC;
    }
    // 0x80448868: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x8044886C: jal         0x80446640
    // 0x80448870: nop

    func_80446640(rdram, ctx);
        goto after_0;
    // 0x80448870: nop

    after_0:
    // 0x80448874: b           L_804488C0
    // 0x80448878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804488C0;
    // 0x80448878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044887C:
    // 0x8044887C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448880: bnel        $a2, $at, L_804488AC
    if (ctx->r6 != ctx->r1) {
        // 0x80448884: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804488AC;
    }
    goto skip_0;
    // 0x80448884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448888: jal         0x804465DC
    // 0x8044888C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_1;
    // 0x8044888C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448890: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448894: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448898: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8044889C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804488A0: b           L_804488BC
    // 0x804488A4: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804488BC;
    // 0x804488A4: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x804488A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804488AC:
    // 0x804488AC: bnel        $a2, $at, L_804488C0
    if (ctx->r6 != ctx->r1) {
        // 0x804488B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804488C0;
    }
    goto skip_1;
    // 0x804488B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804488B4: jal         0x80446640
    // 0x804488B8: nop

    func_80446640(rdram, ctx);
        goto after_2;
    // 0x804488B8: nop

    after_2:
L_804488BC:
    // 0x804488BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804488C0:
    // 0x804488C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804488C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804488C8: jr          $ra
    // 0x804488CC: nop

    return;
    // 0x804488CC: nop

;}
RECOMP_FUNC void func_807159A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807159A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807159AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807159B0: jal         0x80715864
    // 0x807159B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80715864(rdram, ctx);
        goto after_0;
    // 0x807159B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807159B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807159BC: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0X1670) << 16);
    // 0x807159C0: addiu       $t6, $t6, 0x5E90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0X1670));
    // 0x807159C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807159C8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807159CC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x807159D0: sw          $t6, 0x5F8($v0)
    MEM_W(0X5F8, ctx->r2) = ctx->r14;
    // 0x807159D4: sh          $t7, 0x5FC($v0)
    MEM_H(0X5FC, ctx->r2) = ctx->r15;
    // 0x807159D8: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x807159DC: addiu       $at, $zero, 0x4677
    ctx->r1 = ADD32(0, 0X4677);
    // 0x807159E0: beq         $v1, $at, L_807159F8
    if (ctx->r3 == ctx->r1) {
        // 0x807159E4: addiu       $at, $zero, 0x4678
        ctx->r1 = ADD32(0, 0X4678);
            goto L_807159F8;
    }
    // 0x807159E4: addiu       $at, $zero, 0x4678
    ctx->r1 = ADD32(0, 0X4678);
    // 0x807159E8: beq         $v1, $at, L_80715A00
    if (ctx->r3 == ctx->r1) {
        // 0x807159EC: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80715A00;
    }
    // 0x807159EC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x807159F0: b           L_80715A08
    // 0x807159F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80715A08;
    // 0x807159F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807159F8:
    // 0x807159F8: b           L_80715A04
    // 0x807159FC: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
        goto L_80715A04;
    // 0x807159FC: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
L_80715A00:
    // 0x80715A00: sw          $t8, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->r24;
L_80715A04:
    // 0x80715A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715A08:
    // 0x80715A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715A0C: jr          $ra
    // 0x80715A10: nop

    return;
    // 0x80715A10: nop

;}
RECOMP_FUNC void func_805CADA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CADA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805CADA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CADAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805CADB0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805CADB4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805CADB8: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x805CADBC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805CADC0: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(453, 0X6F0) << 16);
    // 0x805CADC4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805CADC8: addiu       $t7, $t7, -0x50C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(453, 0X6F0));
    // 0x805CADCC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805CADD0: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CADD4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805CADD8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x805CADDC: bne         $t8, $zero, L_805CAE10
    if (ctx->r24 != 0) {
        // 0x805CADE0: addiu       $v1, $v0, 0xD
        ctx->r3 = ADD32(ctx->r2, 0XD);
            goto L_805CAE10;
    }
    // 0x805CADE0: addiu       $v1, $v0, 0xD
    ctx->r3 = ADD32(ctx->r2, 0XD);
    // 0x805CADE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x805CADE8: jal         0x80045A34
    // 0x805CADEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805CADEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CADF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805CADF4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805CADF8: bne         $v0, $zero, L_805CAE10
    if (ctx->r2 != 0) {
        // 0x805CADFC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805CAE10;
    }
    // 0x805CADFC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805CAE00: jal         0x800445A4
    // 0x805CAE04: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805CAE04: nop

    after_1:
    // 0x805CAE08: b           L_805CAE64
    // 0x805CAE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CAE64;
    // 0x805CAE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CAE10:
    // 0x805CAE10: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CAE14: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x805CAE18: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x805CAE1C: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x805CAE20: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805CAE24: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x805CAE28: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805CAE2C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x805CAE30: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805CAE34: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x805CAE38: sb          $t0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r8;
    // 0x805CAE3C: jal         0x805CAD08
    // 0x805CAE40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805CAD08(rdram, ctx);
        goto after_2;
    // 0x805CAE40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x805CAE44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805CAE48: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x805CAE4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805CAE50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805CAE54: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x805CAE58: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x805CAE5C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x805CAE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805CAE64:
    // 0x805CAE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CAE68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805CAE6C: jr          $ra
    // 0x805CAE70: nop

    return;
    // 0x805CAE70: nop

;}
RECOMP_FUNC void func_804A5254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A5254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A5258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A525C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A5260: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A5264: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A5268: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A526C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5270: lw          $v1, 0x6ED8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6ED8);
    // 0x804A5274: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A5278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A527C: bne         $v1, $zero, L_804A52AC
    if (ctx->r3 != 0) {
        // 0x804A5280: nop
    
            goto L_804A52AC;
    }
    // 0x804A5280: nop

    // 0x804A5284: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A5288: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A528C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A5290: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A5294: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A5298: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A529C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A52A0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A52A4: b           L_804A52B4
    // 0x804A52A8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A52B4;
    // 0x804A52A8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A52AC:
    // 0x804A52AC: jal         0x804A4DA4
    // 0x804A52B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_804A4DA4(rdram, ctx);
        goto after_0;
    // 0x804A52B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
L_804A52B4:
    // 0x804A52B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A52B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A52BC: jr          $ra
    // 0x804A52C0: nop

    return;
    // 0x804A52C0: nop

;}
RECOMP_FUNC void func_80078C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C20: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80078C24: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80078C28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80078C2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078C30: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80078C34: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80078C38: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80078C3C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80078C40: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80078C44: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80078C48: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x80078C4C: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x80078C50: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80078C54: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x80078C58: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80078C5C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80078C60: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80078C64: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80078C68: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80078C6C: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x80078C70: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80078C74: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x80078C78: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80078C7C: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80078C80: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80078C84: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80078C88: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x80078C8C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80078C90: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x80078C94: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80078C98: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80078C9C: jal         0x80077338
    // 0x80078CA0: lbu         $a2, 0x18($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X18);
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80078CA0: lbu         $a2, 0x18($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X18);
    after_0:
    // 0x80078CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078CA8: jal         0x800733D8
    // 0x80078CAC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800733D8(rdram, ctx);
        goto after_1;
    // 0x80078CAC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x80078CB0: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
    // 0x80078CB4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80078CB8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80078CBC: beq         $t8, $zero, L_80078CD4
    if (ctx->r24 == 0) {
        // 0x80078CC0: addiu       $t5, $t9, 0x8
        ctx->r13 = ADD32(ctx->r25, 0X8);
            goto L_80078CD4;
    }
    // 0x80078CC0: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80078CC4: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x80078CC8: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80078CCC: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x80078CD0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
L_80078CD4:
    // 0x80078CD4: lw          $t4, 0x10($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X10);
    // 0x80078CD8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80078CDC: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x80078CE0: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80078CE4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80078CE8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x80078CEC: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x80078CF0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80078CF4: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80078CF8: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80078CFC: lbu         $a3, 0x5($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X5);
    // 0x80078D00: lbu         $t1, 0x9($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X9);
    // 0x80078D04: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078D08: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80078D0C: lbu         $a2, 0x4($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4);
    // 0x80078D10: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80078D14: mflo        $t7
    ctx->r15 = lo;
    // 0x80078D18: sllv        $t8, $t7, $a3
    ctx->r24 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x80078D1C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80078D20: sra         $t5, $t9, 1
    ctx->r13 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80078D24: multu       $t1, $t5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078D28: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    // 0x80078D2C: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x80078D30: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80078D34: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80078D38: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80078D3C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80078D40: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80078D44: mflo        $t7
    ctx->r15 = lo;
    // 0x80078D48: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80078D4C: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80078D50: subu        $t3, $t5, $t6
    ctx->r11 = SUB32(ctx->r13, ctx->r14);
    // 0x80078D54: jal         0x8007E200
    // 0x80078D58: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_8007E200(rdram, ctx);
        goto after_2;
    // 0x80078D58: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_2:
    // 0x80078D5C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80078D60: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80078D64: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80078D68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80078D6C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80078D70: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80078D74: jr          $ra
    // 0x80078D78: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80078D78: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8079327C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079327C: jr          $ra
    // 0x80793280: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80793280: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8069D05C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D05C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069D068: jal         0x8069CD84
    // 0x8069D06C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8069CD84(rdram, ctx);
        goto after_0;
    // 0x8069D06C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8069D070: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8069D074: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(571, 0X2C0) << 16);
    // 0x8069D078: addiu       $t6, $t6, -0x3050
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(571, 0X2C0));
    // 0x8069D07C: sw          $t6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r14;
    // 0x8069D080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D088: jr          $ra
    // 0x8069D08C: nop

    return;
    // 0x8069D08C: nop

;}
RECOMP_FUNC void func_804E7C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7C10: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804E7C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804E7C18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804E7C1C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x804E7C20: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(261, 0X684) << 16);
    // 0x804E7C24: addiu       $t8, $t8, 0x7EE4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(261, 0X684));
    // 0x804E7C28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804E7C2C: addiu       $t1, $t8, 0x3C
    ctx->r9 = ADD32(ctx->r24, 0X3C);
    // 0x804E7C30: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x804E7C34: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
L_804E7C38:
    // 0x804E7C38: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x804E7C3C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x804E7C40: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x804E7C44: sw          $t0, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r8;
    // 0x804E7C48: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x804E7C4C: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x804E7C50: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x804E7C54: bne         $t8, $t1, L_804E7C38
    if (ctx->r24 != ctx->r9) {
        // 0x804E7C58: sw          $t0, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r8;
            goto L_804E7C38;
    }
    // 0x804E7C58: sw          $t0, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r8;
    // 0x804E7C5C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x804E7C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804E7C64: jal         0x804E7BC4
    // 0x804E7C68: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    func_804E7BC4(rdram, ctx);
        goto after_0;
    // 0x804E7C68: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    after_0:
    // 0x804E7C6C: beql        $v0, $zero, L_804E7CC0
    if (ctx->r2 == 0) {
        // 0x804E7C70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804E7CC0;
    }
    goto skip_0;
    // 0x804E7C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804E7C74: jal         0x804E7A94
    // 0x804E7C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804E7A94(rdram, ctx);
        goto after_1;
    // 0x804E7C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804E7C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804E7C80: bnel        $v0, $at, L_804E7C94
    if (ctx->r2 != ctx->r1) {
        // 0x804E7C84: lw          $t2, 0x14C($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X14C);
            goto L_804E7C94;
    }
    goto skip_1;
    // 0x804E7C84: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    skip_1:
    // 0x804E7C88: jal         0x800447C8
    // 0x804E7C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x804E7C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804E7C90: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
L_804E7C94:
    // 0x804E7C94: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x804E7C98: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x804E7C9C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x804E7CA0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x804E7CA4: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x804E7CA8: sb          $t5, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r13;
    // 0x804E7CAC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x804E7CB0: sb          $t6, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r14;
    // 0x804E7CB4: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x804E7CB8: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    // 0x804E7CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804E7CC0:
    // 0x804E7CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804E7CC4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x804E7CC8: jr          $ra
    // 0x804E7CCC: nop

    return;
    // 0x804E7CCC: nop

;}
RECOMP_FUNC void func_805AC918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC91C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AC920: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805AC924: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805AC928: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805AC92C: jal         0x805AC884
    // 0x805AC930: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805AC930: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805AC934: jal         0x805AC528
    // 0x805AC938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805AC938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805AC93C: jal         0x805AC68C
    // 0x805AC940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805AC68C(rdram, ctx);
        goto after_2;
    // 0x805AC940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805AC944: beq         $v0, $zero, L_805AC968
    if (ctx->r2 == 0) {
        // 0x805AC948: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805AC968;
    }
    // 0x805AC948: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AC94C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x805AC950: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x805AC954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AC958: jal         0x805AD274
    // 0x805AC95C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_805AD274(rdram, ctx);
        goto after_3;
    // 0x805AC95C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x805AC960: b           L_805ACA14
    // 0x805AC964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805ACA14;
    // 0x805AC964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AC968:
    // 0x805AC968: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x805AC96C: beq         $v0, $zero, L_805AC97C
    if (ctx->r2 == 0) {
        // 0x805AC970: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805AC97C;
    }
    // 0x805AC970: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805AC974: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x805AC978: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805AC97C:
    // 0x805AC97C: bnel        $v0, $zero, L_805AC9F8
    if (ctx->r2 != 0) {
        // 0x805AC980: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_805AC9F8;
    }
    goto skip_0;
    // 0x805AC980: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    skip_0:
    // 0x805AC984: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x805AC988: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(441, 0X11D0) << 16);
    // 0x805AC98C: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x805AC990: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805AC994: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805AC998: lh          $t9, -0x2C40($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(441, 0X11D0));
    // 0x805AC99C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AC9A0: sh          $t9, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r25;
    // 0x805AC9A4: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x805AC9A8: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
    // 0x805AC9AC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805AC9B0: sw          $t1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r9;
    // 0x805AC9B4: lh          $v0, 0x144($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X144);
    // 0x805AC9B8: bnel        $v0, $zero, L_805AC9D0
    if (ctx->r2 != 0) {
        // 0x805AC9BC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_805AC9D0;
    }
    goto skip_1;
    // 0x805AC9BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
    // 0x805AC9C0: jal         0x805AC744
    // 0x805AC9C4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_805AC744(rdram, ctx);
        goto after_4;
    // 0x805AC9C4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // 0x805AC9C8: lh          $v0, 0x144($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X144);
    // 0x805AC9CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_805AC9D0:
    // 0x805AC9D0: bne         $v0, $at, L_805AC9E0
    if (ctx->r2 != ctx->r1) {
        // 0x805AC9D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805AC9E0;
    }
    // 0x805AC9D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AC9D8: jal         0x805AC744
    // 0x805AC9DC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_805AC744(rdram, ctx);
        goto after_5;
    // 0x805AC9DC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_5:
L_805AC9E0:
    // 0x805AC9E0: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x805AC9E4: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x805AC9E8: bnel        $at, $zero, L_805AC9F8
    if (ctx->r1 != 0) {
        // 0x805AC9EC: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_805AC9F8;
    }
    goto skip_2;
    // 0x805AC9EC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    skip_2:
    // 0x805AC9F0: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x805AC9F4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
L_805AC9F8:
    // 0x805AC9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC9FC: jal         0x80048F84
    // 0x805ACA00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x805ACA00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x805ACA04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACA08: jal         0x80048F84
    // 0x805ACA0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x805ACA0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x805ACA10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACA14:
    // 0x805ACA14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805ACA18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805ACA1C: jr          $ra
    // 0x805ACA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805ACA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8059EC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EC18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059EC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059EC20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8059EC24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8059EC28: jal         0x80047090
    // 0x8059EC2C: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8059EC2C: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    after_0:
    // 0x8059EC30: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8059EC34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8059EC38: beq         $v0, $at, L_8059EC78
    if (ctx->r2 == ctx->r1) {
        // 0x8059EC3C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8059EC78;
    }
    // 0x8059EC3C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8059EC40: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x8059EC44: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8059EC48: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8059EC4C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8059EC50: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x8059EC54: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x8059EC58: jal         0x8004613C
    // 0x8059EC5C: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8059EC5C: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x8059EC60: beq         $v0, $zero, L_8059EC78
    if (ctx->r2 == 0) {
        // 0x8059EC64: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8059EC78;
    }
    // 0x8059EC64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8059EC68: jal         0x80044194
    // 0x8059EC6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8059EC6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8059EC70: b           L_8059EC7C
    // 0x8059EC74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8059EC7C;
    // 0x8059EC74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8059EC78:
    // 0x8059EC78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8059EC7C:
    // 0x8059EC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059EC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059EC84: jr          $ra
    // 0x8059EC88: nop

    return;
    // 0x8059EC88: nop

;}
RECOMP_FUNC void func_806F5BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F5BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5BC8: jal         0x8005780C
    // 0x806F5BCC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x806F5BCC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806F5BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F5BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F5BD8: jr          $ra
    // 0x806F5BDC: nop

    return;
    // 0x806F5BDC: nop

;}
RECOMP_FUNC void func_8079209C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079209C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807920A0: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x807920A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807920A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807920AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x807920B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807920B4: bne         $t6, $at, L_80792138
    if (ctx->r14 != ctx->r1) {
        // 0x807920B8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80792138;
    }
    // 0x807920B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807920BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807920C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807920C4: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(817, 0X1B40) << 16);
    // 0x807920C8: addiu       $t7, $t7, 0x1E90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(817, 0X1B40));
    // 0x807920CC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x807920D0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807920D4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807920D8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AE0) << 16);
    // 0x807920DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x807920E0: lwc1        $f6, 0x7E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AE0));
    // 0x807920E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807920E8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x807920EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807920F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x807920F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807920F8: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x807920FC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80792100: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80792104: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80792108: jal         0x8006CB1C
    // 0x8079210C: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    func_8006CB1C(rdram, ctx);
        goto after_0;
    // 0x8079210C: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x80792110: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80792114: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80792118: jal         0x8006CB2C
    // 0x8079211C: nop

    func_8006CB2C(rdram, ctx);
        goto after_1;
    // 0x8079211C: nop

    after_1:
    // 0x80792120: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x80792124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792128: jal         0x807907AC
    // 0x8079212C: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    func_807907AC(rdram, ctx);
        goto after_2;
    // 0x8079212C: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    after_2:
    // 0x80792130: b           L_80792164
    // 0x80792134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80792164;
    // 0x80792134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80792138:
    // 0x80792138: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079213C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80792140: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80792144: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80792148: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x8079214C: jal         0x80065ABC
    // 0x80792150: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x80792150: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x80792154: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80792158: jal         0x80790714
    // 0x8079215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_4;
    // 0x8079215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80792160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80792164:
    // 0x80792164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80792168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079216C: jr          $ra
    // 0x80792170: nop

    return;
    // 0x80792170: nop

;}
RECOMP_FUNC void func_805CA798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA798: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805CA79C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805CA7A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805CA7A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805CA7A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805CA7AC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805CA7B0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805CA7B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805CA7B8: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(450, 0X300) << 16);
    // 0x805CA7BC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805CA7C0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805CA7C4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805CA7C8: lw          $t1, -0x5820($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(450, 0X300));
    // 0x805CA7CC: jr          $ra
    // 0x805CA7D0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805CA7D0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x805CA7D4: nop

    // 0x805CA7D8: nop

    // 0x805CA7DC: nop

;}
RECOMP_FUNC void func_80789190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789190: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80789194: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80789198: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8078919C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x807891A0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x807891A4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x807891A8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x807891AC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x807891B0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x807891B4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x807891B8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x807891BC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x807891C0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807891C4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807891C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807891CC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x807891D0: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x807891D4: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x807891D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x807891DC: lwc1        $f4, 0x52C8($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X52C8);
    // 0x807891E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807891E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807891E8: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x807891EC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x807891F0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x807891F4: addiu       $s5, $zero, 0x16A
    ctx->r21 = ADD32(0, 0X16A);
    // 0x807891F8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x807891FC: or          $fp, $s6, $zero
    ctx->r30 = ctx->r22 | 0;
    // 0x80789200: mul.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80789204: nop

    // 0x80789208: mul.s       $f26, $f10, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8078920C: nop

L_80789210:
    // 0x80789210: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x80789214: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x80789218: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8078921C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80789220: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80789224: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
L_80789228:
    // 0x80789228: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8078922C: sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // 0x80789230: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x80789234: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80789238: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8078923C: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80789240: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80789244: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80789248: sh          $t7, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r15;
    // 0x8078924C: sh          $v0, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r2;
    // 0x80789250: jal         0x8078743C
    // 0x80789254: sh          $v0, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r2;
    func_8078743C(rdram, ctx);
        goto after_0;
    // 0x80789254: sh          $v0, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r2;
    after_0:
    // 0x80789258: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8078925C: swc1        $f0, 0x4990($s1)
    MEM_W(0X4990, ctx->r17) = ctx->f0.u32l;
    // 0x80789260: swc1        $f0, 0x4F38($s1)
    MEM_W(0X4F38, ctx->r17) = ctx->f0.u32l;
    // 0x80789264: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80789268: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8078926C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80789270: swc1        $f22, 0x43E0($s2)
    MEM_W(0X43E0, ctx->r18) = ctx->f22.u32l;
    // 0x80789274: bne         $s4, $s5, L_80789228
    if (ctx->r20 != ctx->r21) {
        // 0x80789278: swc1        $f22, 0x43E4($s2)
        MEM_W(0X43E4, ctx->r18) = ctx->f22.u32l;
            goto L_80789228;
    }
    // 0x80789278: swc1        $f22, 0x43E4($s2)
    MEM_W(0X43E4, ctx->r18) = ctx->f22.u32l;
    // 0x8078927C: addiu       $s7, $s7, 0x16A0
    ctx->r23 = ADD32(ctx->r23, 0X16A0);
    // 0x80789280: addiu       $at, $zero, 0x43E0
    ctx->r1 = ADD32(0, 0X43E0);
    // 0x80789284: bne         $s7, $at, L_80789210
    if (ctx->r23 != ctx->r1) {
        // 0x80789288: addiu       $fp, $fp, 0x16A0
        ctx->r30 = ADD32(ctx->r30, 0X16A0);
            goto L_80789210;
    }
    // 0x80789288: addiu       $fp, $fp, 0x16A0
    ctx->r30 = ADD32(ctx->r30, 0X16A0);
    // 0x8078928C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80789290: swc1        $f4, 0x52CC($s6)
    MEM_W(0X52CC, ctx->r22) = ctx->f4.u32l;
    // 0x80789294: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80789298: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8078929C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x807892A0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x807892A4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x807892A8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x807892AC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x807892B0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x807892B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x807892B8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x807892BC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x807892C0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x807892C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x807892C8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807892CC: jr          $ra
    // 0x807892D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x807892D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80454D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80454D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80454D58: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13908) << 16);
    // 0x80454D5C: jal         0x804547C0
    // 0x80454D60: lw          $a1, 0x7CE8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13908));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x80454D60: lw          $a1, 0x7CE8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13908));
    after_0:
    // 0x80454D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80454D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80454D6C: jr          $ra
    // 0x80454D70: nop

    return;
    // 0x80454D70: nop

;}
RECOMP_FUNC void func_80516F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516F5C: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(282, 0X260) << 16);
    // 0x80516F60: lw          $v0, 0x7090($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(282, 0X260));
    // 0x80516F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516F6C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80516F70: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80516F74: beql        $v1, $zero, L_80516FA8
    if (ctx->r3 == 0) {
        // 0x80516F78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80516FA8;
    }
    goto skip_0;
    // 0x80516F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80516F7C: jalr        $v1
    // 0x80516F80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80516F80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80516F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80516F88: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80516F8C: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80516F90: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80516F94: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80516F98: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80516F9C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80516FA0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80516FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80516FA8:
    // 0x80516FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516FAC: jr          $ra
    // 0x80516FB0: nop

    return;
    // 0x80516FB0: nop

;}
RECOMP_FUNC void func_80027BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027BCC: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80027BD0: lw          $v1, 0x15C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X15C);
    // 0x80027BD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80027BD8: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80027BDC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80027BE0: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80027BE4: bnel        $at, $zero, L_80027C54
    if (ctx->r1 != 0) {
        // 0x80027BE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80027C54;
    }
    goto skip_0;
    // 0x80027BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80027BEC: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80027BF0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80027BF4: lw          $a1, 0x14C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14C);
    // 0x80027BF8: xori        $v0, $v0, 0x18
    ctx->r2 = ctx->r2 ^ 0X18;
    // 0x80027BFC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80027C00: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80027C04: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x80027C08: lw          $t0, -0x3A30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3A30);
    // 0x80027C0C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80027C10: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x80027C14: bne         $a1, $t0, L_80027C48
    if (ctx->r5 != ctx->r8) {
        // 0x80027C18: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_80027C48;
    }
    // 0x80027C18: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x80027C1C: lw          $t1, -0x3A28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3A28);
    // 0x80027C20: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x80027C24: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80027C28: bne         $t2, $zero, L_80027C38
    if (ctx->r10 != 0) {
        // 0x80027C2C: nop
    
            goto L_80027C38;
    }
    // 0x80027C2C: nop

    // 0x80027C30: b           L_80027C54
    // 0x80027C34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80027C54;
    // 0x80027C34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80027C38:
    // 0x80027C38: jal         0x80027B90
    // 0x80027C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80027B90(rdram, ctx);
        goto after_0;
    // 0x80027C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027C40: b           L_80027C4C
    // 0x80027C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80027C4C;
    // 0x80027C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80027C48:
    // 0x80027C48: sw          $t3, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r11;
L_80027C4C:
    // 0x80027C4C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027C54:
    // 0x80027C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027C5C: jr          $ra
    // 0x80027C60: nop

    return;
    // 0x80027C60: nop

;}
RECOMP_FUNC void func_800498D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800498D4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x800498D8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800498DC: lw          $t2, 0x70($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X70);
    // 0x800498E0: lw          $a2, 0x2C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X2C);
    // 0x800498E4: lw          $v1, 0x3C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X3C);
    // 0x800498E8: lw          $a3, 0x30($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X30);
    // 0x800498EC: lw          $t0, 0x34($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X34);
    // 0x800498F0: lw          $t1, 0x38($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X38);
    // 0x800498F4: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800498F8: lwc1        $f2, 0x4($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800498FC: beq         $a2, $zero, L_80049C4C
    if (ctx->r6 == 0) {
        // 0x80049900: lwc1        $f12, 0x8($t2)
        ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
            goto L_80049C4C;
    }
    // 0x80049900: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80049904: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80049908: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004990C: beq         $a0, $zero, L_800499DC
    if (ctx->r4 == 0) {
        // 0x80049910: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_800499DC;
    }
    // 0x80049910: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x80049914: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80049918: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8004991C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049920: nop

    // 0x80049924: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049928: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004992C: beql        $v0, $a2, L_80049998
    if (ctx->r2 == ctx->r6) {
        // 0x80049930: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80049998;
    }
    goto skip_0;
    // 0x80049930: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_0:
    // 0x80049934: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80049938:
    // 0x80049938: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x8004993C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80049940: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80049944: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80049948: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004994C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80049950: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049954: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80049958: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004995C: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80049960: lh          $t8, -0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X2);
    // 0x80049964: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80049968: nop

    // 0x8004996C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049970: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049974: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80049978: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8004997C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049980: nop

    // 0x80049984: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049988: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004998C: bnel        $v0, $a2, L_80049938
    if (ctx->r2 != ctx->r6) {
        // 0x80049990: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80049938;
    }
    goto skip_1;
    // 0x80049990: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_1:
    // 0x80049994: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80049998:
    // 0x80049998: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x8004999C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800499A0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800499A4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800499A8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800499AC: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x800499B0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800499B4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800499B8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x800499BC: lh          $t8, -0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X2);
    // 0x800499C0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800499C4: nop

    // 0x800499C8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800499CC: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800499D0: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800499D4: beq         $a2, $zero, L_80049C4C
    if (ctx->r6 == 0) {
        // 0x800499D8: nop
    
            goto L_80049C4C;
    }
    // 0x800499D8: nop

L_800499DC:
    // 0x800499DC: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800499E0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800499E4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800499E8: nop

    // 0x800499EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800499F0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800499F4: beql        $a2, $zero, L_80049B38
    if (ctx->r6 == 0) {
        // 0x800499F8: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80049B38;
    }
    goto skip_2;
    // 0x800499F8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_2:
    // 0x800499FC: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80049A00:
    // 0x80049A00: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80049A04: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80049A08: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80049A0C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80049A10: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80049A14: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80049A18: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A1C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80049A20: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049A24: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x80049A28: lh          $t4, -0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X14);
    // 0x80049A2C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80049A30: nop

    // 0x80049A34: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A38: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049A3C: swc1        $f16, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f16.u32l;
    // 0x80049A40: lh          $t5, -0x12($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X12);
    // 0x80049A44: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80049A48: nop

    // 0x80049A4C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A50: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049A54: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80049A58: lh          $t6, -0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X10);
    // 0x80049A5C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049A60: nop

    // 0x80049A64: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A68: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049A6C: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x80049A70: lh          $t7, -0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, -0XE);
    // 0x80049A74: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80049A78: nop

    // 0x80049A7C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A80: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049A84: swc1        $f16, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f16.u32l;
    // 0x80049A88: lh          $t8, -0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, -0XC);
    // 0x80049A8C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80049A90: nop

    // 0x80049A94: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049A98: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049A9C: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x80049AA0: lh          $t9, -0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, -0XA);
    // 0x80049AA4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80049AA8: nop

    // 0x80049AAC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049AB0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049AB4: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x80049AB8: lh          $t3, -0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, -0X8);
    // 0x80049ABC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80049AC0: nop

    // 0x80049AC4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049AC8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049ACC: swc1        $f16, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f16.u32l;
    // 0x80049AD0: lh          $t4, -0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X6);
    // 0x80049AD4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80049AD8: nop

    // 0x80049ADC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049AE0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049AE4: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x80049AE8: lh          $t5, -0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X4);
    // 0x80049AEC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80049AF0: nop

    // 0x80049AF4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049AF8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049AFC: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80049B00: lh          $t6, -0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X2);
    // 0x80049B04: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049B08: nop

    // 0x80049B0C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B10: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049B14: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80049B18: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80049B1C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80049B20: nop

    // 0x80049B24: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B28: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049B2C: bnel        $a2, $zero, L_80049A00
    if (ctx->r6 != 0) {
        // 0x80049B30: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80049A00;
    }
    goto skip_3;
    // 0x80049B30: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_3:
    // 0x80049B34: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80049B38:
    // 0x80049B38: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80049B3C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80049B40: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80049B44: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80049B48: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80049B4C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80049B50: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B54: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049B58: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x80049B5C: lh          $t4, -0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X14);
    // 0x80049B60: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80049B64: nop

    // 0x80049B68: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B6C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049B70: swc1        $f16, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f16.u32l;
    // 0x80049B74: lh          $t5, -0x12($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X12);
    // 0x80049B78: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80049B7C: nop

    // 0x80049B80: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B84: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049B88: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80049B8C: lh          $t6, -0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X10);
    // 0x80049B90: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049B94: nop

    // 0x80049B98: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049B9C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049BA0: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x80049BA4: lh          $t7, -0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, -0XE);
    // 0x80049BA8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80049BAC: nop

    // 0x80049BB0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049BB4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049BB8: swc1        $f16, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f16.u32l;
    // 0x80049BBC: lh          $t8, -0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, -0XC);
    // 0x80049BC0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80049BC4: nop

    // 0x80049BC8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049BCC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049BD0: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x80049BD4: lh          $t9, -0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, -0XA);
    // 0x80049BD8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80049BDC: nop

    // 0x80049BE0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049BE4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049BE8: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x80049BEC: lh          $t3, -0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, -0X8);
    // 0x80049BF0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80049BF4: nop

    // 0x80049BF8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049BFC: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049C00: swc1        $f16, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f16.u32l;
    // 0x80049C04: lh          $t4, -0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X6);
    // 0x80049C08: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80049C0C: nop

    // 0x80049C10: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049C14: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80049C18: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x80049C1C: lh          $t5, -0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X4);
    // 0x80049C20: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80049C24: nop

    // 0x80049C28: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049C2C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80049C30: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80049C34: lh          $t6, -0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X2);
    // 0x80049C38: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80049C3C: nop

    // 0x80049C40: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049C44: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80049C48: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
L_80049C4C:
    // 0x80049C4C: jr          $ra
    // 0x80049C50: nop

    return;
    // 0x80049C50: nop

;}
RECOMP_FUNC void func_8002C01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C020: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C024: addiu       $a1, $a1, -0x2868
    ctx->r5 = ADD32(ctx->r5, -0X2868);
    // 0x8002C028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C02C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002C030: jal         0x80028118
    // 0x8002C034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C03C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C040: nop

    // 0x8002C044: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C048: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C04C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C050: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8002C054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C05C: jr          $ra
    // 0x8002C060: nop

    return;
    // 0x8002C060: nop

;}
RECOMP_FUNC void func_807B927C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B927C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9284: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807B9288: addiu       $a0, $a0, -0x71A8
    ctx->r4 = ADD32(ctx->r4, -0X71A8);
    // 0x807B928C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x807B9290: jal         0x80065728
    // 0x807B9294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807B9294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x807B9298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B929C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B92A0: jr          $ra
    // 0x807B92A4: nop

    return;
    // 0x807B92A4: nop

;}
RECOMP_FUNC void func_800664B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800664B4: blez        $a1, L_80066714
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800664B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80066714;
    }
    // 0x800664B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800664BC: andi        $a2, $a1, 0x3
    ctx->r6 = ctx->r5 & 0X3;
    // 0x800664C0: beql        $a2, $zero, L_80066578
    if (ctx->r6 == 0) {
        // 0x800664C4: mtc1        $a1, $f18
        ctx->f18.u32l = ctx->r5;
            goto L_80066578;
    }
    goto skip_0;
    // 0x800664C4: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    skip_0:
    // 0x800664C8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800664CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800664D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800664D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800664D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800664DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800664E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800664E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800664E8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800664EC: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800664F0: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800664F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800664F8: mul.s       $f12, $f10, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800664FC: nop

    // 0x80066500: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066504: beq         $v1, $v0, L_80066544
    if (ctx->r3 == ctx->r2) {
        // 0x80066508: nop
    
            goto L_80066544;
    }
    // 0x80066508: nop

L_8006650C:
    // 0x8006650C: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066510: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066514: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066518: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8006651C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80066520: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80066524: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80066528: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8006652C: mul.s       $f12, $f10, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80066530: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80066534: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066538: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8006653C: bne         $v1, $v0, L_8006650C
    if (ctx->r3 != ctx->r2) {
        // 0x80066540: swc1        $f4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
            goto L_8006650C;
    }
    // 0x80066540: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
L_80066544:
    // 0x80066544: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066548: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8006654C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066550: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80066554: nop

    // 0x80066558: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8006655C: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80066560: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80066564: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80066568: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8006656C: beq         $v0, $a1, L_80066714
    if (ctx->r2 == ctx->r5) {
        // 0x80066570: nop
    
            goto L_80066714;
    }
    // 0x80066570: nop

    // 0x80066574: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
L_80066578:
    // 0x80066578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006657C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80066580: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80066584: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066588: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006658C: div.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80066590: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80066594: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80066598: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006659C: nop

    // 0x800665A0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800665A4: beq         $v0, $a1, L_80066668
    if (ctx->r2 == ctx->r5) {
        // 0x800665A8: nop
    
            goto L_80066668;
    }
    // 0x800665A8: nop

L_800665AC:
    // 0x800665AC: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800665B0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800665B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800665B8: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800665BC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800665C0: add.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800665C4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800665C8: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800665CC: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800665D0: swc1        $f4, -0x2C($a0)
    MEM_W(-0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800665D4: swc1        $f6, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800665D8: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800665DC: swc1        $f8, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f8.u32l;
    // 0x800665E0: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800665E4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800665E8: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800665EC: sub.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800665F0: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800665F4: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800665F8: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800665FC: swc1        $f6, -0x24($a0)
    MEM_W(-0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80066600: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80066604: swc1        $f8, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80066608: swc1        $f12, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f12.u32l;
    // 0x8006660C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066610: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066614: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80066618: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8006661C: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80066620: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80066624: swc1        $f4, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->f4.u32l;
    // 0x80066628: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006662C: swc1        $f6, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80066630: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80066634: swc1        $f8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80066638: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006663C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066640: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80066644: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80066648: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8006664C: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80066650: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80066654: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066658: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8006665C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066660: bne         $v0, $a1, L_800665AC
    if (ctx->r2 != ctx->r5) {
        // 0x80066664: swc1        $f6, -0xC($a0)
        MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
            goto L_800665AC;
    }
    // 0x80066664: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
L_80066668:
    // 0x80066668: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8006666C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066670: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80066674: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80066678: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8006667C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066680: add.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80066684: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80066688: swc1        $f6, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f6.u32l;
    // 0x8006668C: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80066690: swc1        $f4, -0x2C($a0)
    MEM_W(-0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80066694: swc1        $f8, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80066698: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8006669C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800666A0: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800666A4: sub.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800666A8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800666AC: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800666B0: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800666B4: swc1        $f6, -0x24($a0)
    MEM_W(-0X24, ctx->r4) = ctx->f6.u32l;
    // 0x800666B8: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800666BC: swc1        $f8, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800666C0: swc1        $f12, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f12.u32l;
    // 0x800666C4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800666C8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800666CC: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800666D0: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800666D4: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800666D8: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800666DC: swc1        $f4, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800666E0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800666E4: swc1        $f6, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800666E8: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800666EC: swc1        $f8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800666F0: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800666F4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800666F8: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800666FC: nop

    // 0x80066700: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80066704: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80066708: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8006670C: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80066710: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
L_80066714:
    // 0x80066714: jr          $ra
    // 0x80066718: nop

    return;
    // 0x80066718: nop

;}
RECOMP_FUNC void func_806F2C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2C1C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F2C20: blez        $v0, L_806F2C54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806F2C24: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806F2C54;
    }
    // 0x806F2C24: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806F2C28: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x806F2C2C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F2C30: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F2C34: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F2C38: jal         0x80065ABC
    // 0x806F2C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F2C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F2C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2C44: jal         0x806F2B30
    // 0x806F2C48: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_806F2B30(rdram, ctx);
        goto after_1;
    // 0x806F2C48: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x806F2C4C: b           L_806F2C74
    // 0x806F2C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F2C74;
    // 0x806F2C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F2C54:
    // 0x806F2C54: jal         0x806F2B8C
    // 0x806F2C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F2B8C(rdram, ctx);
        goto after_2;
    // 0x806F2C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x806F2C5C: jal         0x800447C8
    // 0x806F2C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x806F2C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x806F2C64: addiu       $t7, $zero, 0x4B0
    ctx->r15 = ADD32(0, 0X4B0);
    // 0x806F2C68: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F2C6C: sw          $t7, -0x6C78($at)
    MEM_W(-0X6C78, ctx->r1) = ctx->r15;
    // 0x806F2C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F2C74:
    // 0x806F2C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2C78: jr          $ra
    // 0x806F2C7C: nop

    return;
    // 0x806F2C7C: nop

;}
RECOMP_FUNC void func_80067878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006787C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067884: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067888: jal         0x800677CC
    // 0x8006788C: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    func_800677CC(rdram, ctx);
        goto after_0;
    // 0x8006788C: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_0:
    // 0x80067890: beq         $v0, $zero, L_800678A0
    if (ctx->r2 == 0) {
        // 0x80067894: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800678A0;
    }
    // 0x80067894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067898: jal         0x80011990
    // 0x8006789C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    func_80011990(rdram, ctx);
        goto after_1;
    // 0x8006789C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_1:
L_800678A0:
    // 0x800678A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678A8: jr          $ra
    // 0x800678AC: nop

    return;
    // 0x800678AC: nop

;}
RECOMP_FUNC void func_8043F46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F46C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043F470: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043F474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043F478: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F47C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043F480: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8043F484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F488: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8043F48C: jal         0x80442188
    // 0x8043F490: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F490: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F494: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E84) << 16);
    // 0x8043F498: lwc1        $f2, 0x3D84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E84));
    // 0x8043F49C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8043F4A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043F4A4: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x8043F4A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F4AC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8043F4B0: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8043F4B4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043F4B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8043F4BC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E88) << 16);
    // 0x8043F4C0: swc1        $f2, 0x1C24($v0)
    MEM_W(0X1C24, ctx->r2) = ctx->f2.u32l;
    // 0x8043F4C4: swc1        $f2, 0x1C28($v0)
    MEM_W(0X1C28, ctx->r2) = ctx->f2.u32l;
    // 0x8043F4C8: lwc1        $f4, 0x3D88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E88));
    // 0x8043F4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F4D0: swc1        $f12, 0x1C88($v0)
    MEM_W(0X1C88, ctx->r2) = ctx->f12.u32l;
    // 0x8043F4D4: swc1        $f12, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f12.u32l;
    // 0x8043F4D8: jal         0x8043F310
    // 0x8043F4DC: swc1        $f4, 0x1C74($v0)
    MEM_W(0X1C74, ctx->r2) = ctx->f4.u32l;
    func_8043F310(rdram, ctx);
        goto after_1;
    // 0x8043F4DC: swc1        $f4, 0x1C74($v0)
    MEM_W(0X1C74, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8043F4E0: jal         0x8043F42C
    // 0x8043F4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F42C(rdram, ctx);
        goto after_2;
    // 0x8043F4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043F4E8: jal         0x8043F1A0
    // 0x8043F4EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F1A0(rdram, ctx);
        goto after_3;
    // 0x8043F4EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043F4F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F4F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043F4F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043F4FC: jr          $ra
    // 0x8043F500: nop

    return;
    // 0x8043F500: nop

;}
RECOMP_FUNC void func_806FD4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD4FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806FD508: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806FD50C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806FD510: jal         0x80067BBC
    // 0x806FD514: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806FD514: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806FD518: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806FD51C: jal         0x80067818
    // 0x806FD520: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806FD520: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806FD524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD52C: jr          $ra
    // 0x806FD530: nop

    return;
    // 0x806FD530: nop

;}
RECOMP_FUNC void func_806FB3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FB3BC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x806FB3C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FB3C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FB3C8: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x806FB3CC: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x806FB3D0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806FB3D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806FB3D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806FB3DC: jal         0x8004921C
    // 0x806FB3E0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x806FB3E0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    after_0:
    // 0x806FB3E4: sh          $v0, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r2;
    // 0x806FB3E8: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    // 0x806FB3EC: jal         0x8004921C
    // 0x806FB3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x806FB3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806FB3F4: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    // 0x806FB3F8: sh          $v0, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r2;
    // 0x806FB3FC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x806FB400: lw          $t8, 0x168($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X168);
    // 0x806FB404: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x806FB408: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    // 0x806FB40C: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x806FB410: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x806FB414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FB418: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x806FB41C: lw          $t6, 0x16C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X16C);
    // 0x806FB420: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x806FB424: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x806FB428: lw          $t8, 0x1F4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1F4);
    // 0x806FB42C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x806FB430: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x806FB434: addiu       $s0, $s0, -0x2A0
    ctx->r16 = ADD32(ctx->r16, -0X2A0);
    // 0x806FB438: sw          $s0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r16;
    // 0x806FB43C: jal         0x80077338
    // 0x806FB440: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x806FB440: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    after_2:
    // 0x806FB444: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    // 0x806FB448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806FB44C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806FB450: jal         0x8007711C
    // 0x806FB454: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x806FB454: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    after_3:
    // 0x806FB458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FB45C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x806FB460: jal         0x806FB184
    // 0x806FB464: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    func_806FB184(rdram, ctx);
        goto after_4;
    // 0x806FB464: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    after_4:
    // 0x806FB468: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB46C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x806FB470: ori         $t7, $t7, 0x81FF
    ctx->r15 = ctx->r15 | 0X81FF;
    // 0x806FB474: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806FB478: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB47C: sw          $s0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r16;
    // 0x806FB480: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806FB484: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB488: lui         $ra, 0xFD50
    ctx->r31 = S32(0XFD50 << 16);
    // 0x806FB48C: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x806FB490: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FB494: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x806FB498: sw          $ra, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r31;
    // 0x806FB49C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x806FB4A0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x806FB4A4: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x806FB4A8: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x806FB4AC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB4B0: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x806FB4B4: ori         $t6, $t6, 0x5F
    ctx->r14 = ctx->r14 | 0X5F;
    // 0x806FB4B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB4BC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB4C0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x806FB4C4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806FB4C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FB4CC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB4D0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x806FB4D4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB4D8: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB4DC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FB4E0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806FB4E4: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB4E8: lh          $v0, 0xC2($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XC2);
    // 0x806FB4EC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806FB4F0: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x806FB4F4: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x806FB4F8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x806FB4FC: lh          $t9, 0xC0($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC0);
    // 0x806FB500: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x806FB504: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x806FB508: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806FB50C: sra         $t4, $t4, 3
    ctx->r12 = S32(SIGNED(ctx->r12) >> 3);
    // 0x806FB510: andi        $t4, $t4, 0x1FF
    ctx->r12 = ctx->r12 & 0X1FF;
    // 0x806FB514: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x806FB518: mflo        $t1
    ctx->r9 = lo;
    // 0x806FB51C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x806FB520: sra         $t1, $t1, 1
    ctx->r9 = S32(SIGNED(ctx->r9) >> 1);
    // 0x806FB524: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x806FB528: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x806FB52C: beq         $at, $zero, L_806FB53C
    if (ctx->r1 == 0) {
        // 0x806FB530: nop
    
            goto L_806FB53C;
    }
    // 0x806FB530: nop

    // 0x806FB534: b           L_806FB53C
    // 0x806FB538: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
        goto L_806FB53C;
    // 0x806FB538: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_806FB53C:
    // 0x806FB53C: bgez        $t2, L_806FB54C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x806FB540: sra         $a1, $t2, 3
        ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
            goto L_806FB54C;
    }
    // 0x806FB540: sra         $a1, $t2, 3
    ctx->r5 = S32(SIGNED(ctx->r10) >> 3);
    // 0x806FB544: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x806FB548: sra         $a1, $at, 3
    ctx->r5 = S32(SIGNED(ctx->r1) >> 3);
L_806FB54C:
    // 0x806FB54C: bgtz        $a1, L_806FB55C
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB550: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_806FB55C;
    }
    // 0x806FB550: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x806FB554: b           L_806FB55C
    // 0x806FB558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FB55C;
    // 0x806FB558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FB55C:
    // 0x806FB55C: bgtz        $a1, L_806FB56C
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB560: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_806FB56C;
    }
    // 0x806FB560: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x806FB564: b           L_806FB570
    // 0x806FB568: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_806FB570;
    // 0x806FB568: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_806FB56C:
    // 0x806FB56C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_806FB570:
    // 0x806FB570: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x806FB574: bne         $s0, $zero, L_806FB580
    if (ctx->r16 != 0) {
        // 0x806FB578: nop
    
            goto L_806FB580;
    }
    // 0x806FB578: nop

    // 0x806FB57C: break       7
    do_break(2154804604);
L_806FB580:
    // 0x806FB580: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FB584: bne         $s0, $at, L_806FB598
    if (ctx->r16 != ctx->r1) {
        // 0x806FB588: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FB598;
    }
    // 0x806FB588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FB58C: bne         $t6, $at, L_806FB598
    if (ctx->r14 != ctx->r1) {
        // 0x806FB590: nop
    
            goto L_806FB598;
    }
    // 0x806FB590: nop

    // 0x806FB594: break       6
    do_break(2154804628);
L_806FB598:
    // 0x806FB598: mflo        $t7
    ctx->r15 = lo;
    // 0x806FB59C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x806FB5A0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x806FB5A4: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x806FB5A8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x806FB5AC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806FB5B0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x806FB5B4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x806FB5B8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB5BC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x806FB5C0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x806FB5C4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FB5C8: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x806FB5CC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806FB5D0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806FB5D4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB5D8: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x806FB5DC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
    // 0x806FB5E0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FB5E4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB5E8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x806FB5EC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x806FB5F0: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB5F4: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x806FB5F8: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x806FB5FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB600: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB604: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FB608: lh          $t9, 0xC2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC2);
    // 0x806FB60C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FB610: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x806FB614: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x806FB618: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806FB61C: lh          $t7, 0xC0($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC0);
    // 0x806FB620: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x806FB624: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x806FB628: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x806FB62C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x806FB630: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x806FB634: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x806FB638: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x806FB63C: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB640: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X2610) << 16);
    // 0x806FB644: addiu       $t9, $t9, -0x3DC0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(700, 0X2610));
    // 0x806FB648: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FB64C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB650: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x806FB654: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x806FB658: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB65C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x806FB660: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x806FB664: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB668: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB66C: ori         $t6, $t6, 0x30BF
    ctx->r14 = ctx->r14 | 0X30BF;
    // 0x806FB670: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FB674: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806FB678: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x806FB67C: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x806FB680: addiu       $t7, $t9, 0x1E0
    ctx->r15 = ADD32(ctx->r25, 0X1E0);
    // 0x806FB684: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x806FB688: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB68C: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X2708) << 16);
    // 0x806FB690: addiu       $t9, $t9, -0x3CC8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(700, 0X2708));
    // 0x806FB694: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806FB698: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB69C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x806FB6A0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x806FB6A4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB6A8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x806FB6AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806FB6B0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB6B4: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB6B8: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x806FB6BC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x806FB6C0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FB6C4: addiu       $t9, $t6, 0x800
    ctx->r25 = ADD32(ctx->r14, 0X800);
    // 0x806FB6C8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x806FB6CC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB6D0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x806FB6D4: ori         $t9, $t9, 0x25F
    ctx->r25 = ctx->r25 | 0X25F;
    // 0x806FB6D8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB6DC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB6E0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x806FB6E4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FB6E8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x806FB6EC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x806FB6F0: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB6F4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x806FB6F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x806FB6FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806FB700: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB704: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806FB708: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FB70C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB710: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x806FB714: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806FB718: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806FB71C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x806FB720: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806FB724: beq         $at, $zero, L_806FB734
    if (ctx->r1 == 0) {
        // 0x806FB728: or          $t2, $t9, $zero
        ctx->r10 = ctx->r25 | 0;
            goto L_806FB734;
    }
    // 0x806FB728: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x806FB72C: b           L_806FB734
    // 0x806FB730: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
        goto L_806FB734;
    // 0x806FB730: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_806FB734:
    // 0x806FB734: bgtz        $a1, L_806FB744
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB738: nop
    
            goto L_806FB744;
    }
    // 0x806FB738: nop

    // 0x806FB73C: b           L_806FB744
    // 0x806FB740: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FB744;
    // 0x806FB740: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FB744:
    // 0x806FB744: bgtz        $a1, L_806FB754
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB748: addiu       $t6, $a2, 0x7FF
        ctx->r14 = ADD32(ctx->r6, 0X7FF);
            goto L_806FB754;
    }
    // 0x806FB748: addiu       $t6, $a2, 0x7FF
    ctx->r14 = ADD32(ctx->r6, 0X7FF);
    // 0x806FB74C: b           L_806FB754
    // 0x806FB750: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_806FB754;
    // 0x806FB750: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_806FB754:
    // 0x806FB754: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x806FB758: bne         $s0, $zero, L_806FB764
    if (ctx->r16 != 0) {
        // 0x806FB75C: nop
    
            goto L_806FB764;
    }
    // 0x806FB75C: nop

    // 0x806FB760: break       7
    do_break(2154805088);
L_806FB764:
    // 0x806FB764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FB768: bne         $s0, $at, L_806FB77C
    if (ctx->r16 != ctx->r1) {
        // 0x806FB76C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FB77C;
    }
    // 0x806FB76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FB770: bne         $t6, $at, L_806FB77C
    if (ctx->r14 != ctx->r1) {
        // 0x806FB774: nop
    
            goto L_806FB77C;
    }
    // 0x806FB774: nop

    // 0x806FB778: break       6
    do_break(2154805112);
L_806FB77C:
    // 0x806FB77C: mflo        $t9
    ctx->r25 = lo;
    // 0x806FB780: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x806FB784: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x806FB788: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x806FB78C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x806FB790: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x806FB794: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x806FB798: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x806FB79C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB7A0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x806FB7A4: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x806FB7A8: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FB7AC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB7B0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806FB7B4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FB7B8: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB7BC: addiu       $t8, $zero, 0x25F
    ctx->r24 = ADD32(0, 0X25F);
    // 0x806FB7C0: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x806FB7C4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x806FB7C8: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB7CC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x806FB7D0: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x806FB7D4: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB7D8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x806FB7DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806FB7E0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806FB7E4: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x806FB7E8: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x806FB7EC: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x806FB7F0: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB7F4: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(700, 0X2720) << 16);
    // 0x806FB7F8: addiu       $t7, $t7, -0x3CB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(700, 0X2720));
    // 0x806FB7FC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806FB800: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x806FB804: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x806FB808: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x806FB80C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB810: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x806FB814: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x806FB818: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FB81C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB820: sw          $ra, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r31;
    // 0x806FB824: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x806FB828: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x806FB82C: addiu       $t7, $t9, 0x1000
    ctx->r15 = ADD32(ctx->r25, 0X1000);
    // 0x806FB830: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x806FB834: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB838: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x806FB83C: ori         $t7, $t7, 0x25F
    ctx->r15 = ctx->r15 | 0X25F;
    // 0x806FB840: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FB844: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB848: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x806FB84C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FB850: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x806FB854: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x806FB858: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB85C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x806FB860: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806FB864: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB868: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806FB86C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806FB870: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB874: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x806FB878: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806FB87C: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x806FB880: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB884: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x806FB888: beq         $at, $zero, L_806FB898
    if (ctx->r1 == 0) {
        // 0x806FB88C: or          $t2, $t7, $zero
        ctx->r10 = ctx->r15 | 0;
            goto L_806FB898;
    }
    // 0x806FB88C: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x806FB890: b           L_806FB898
    // 0x806FB894: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
        goto L_806FB898;
    // 0x806FB894: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_806FB898:
    // 0x806FB898: bgtz        $a1, L_806FB8A8
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB89C: nop
    
            goto L_806FB8A8;
    }
    // 0x806FB89C: nop

    // 0x806FB8A0: b           L_806FB8A8
    // 0x806FB8A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_806FB8A8;
    // 0x806FB8A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806FB8A8:
    // 0x806FB8A8: bgtz        $a1, L_806FB8B8
    if (SIGNED(ctx->r5) > 0) {
        // 0x806FB8AC: addiu       $t9, $a2, 0x7FF
        ctx->r25 = ADD32(ctx->r6, 0X7FF);
            goto L_806FB8B8;
    }
    // 0x806FB8AC: addiu       $t9, $a2, 0x7FF
    ctx->r25 = ADD32(ctx->r6, 0X7FF);
    // 0x806FB8B0: b           L_806FB8B8
    // 0x806FB8B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_806FB8B8;
    // 0x806FB8B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_806FB8B8:
    // 0x806FB8B8: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x806FB8BC: bne         $s0, $zero, L_806FB8C8
    if (ctx->r16 != 0) {
        // 0x806FB8C0: nop
    
            goto L_806FB8C8;
    }
    // 0x806FB8C0: nop

    // 0x806FB8C4: break       7
    do_break(2154805444);
L_806FB8C8:
    // 0x806FB8C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806FB8CC: bne         $s0, $at, L_806FB8E0
    if (ctx->r16 != ctx->r1) {
        // 0x806FB8D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806FB8E0;
    }
    // 0x806FB8D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806FB8D4: bne         $t9, $at, L_806FB8E0
    if (ctx->r25 != ctx->r1) {
        // 0x806FB8D8: nop
    
            goto L_806FB8E0;
    }
    // 0x806FB8D8: nop

    // 0x806FB8DC: break       6
    do_break(2154805468);
L_806FB8E0:
    // 0x806FB8E0: mflo        $t7
    ctx->r15 = lo;
    // 0x806FB8E4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x806FB8E8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x806FB8EC: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x806FB8F0: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x806FB8F4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x806FB8F8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x806FB8FC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x806FB900: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB904: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x806FB908: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x806FB90C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x806FB910: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x806FB914: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806FB918: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB91C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x806FB920: addiu       $t8, $zero, 0x25F
    ctx->r24 = ADD32(0, 0X25F);
    // 0x806FB924: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x806FB928: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x806FB92C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x806FB930: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x806FB934: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB938: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x806FB93C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x806FB940: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x806FB944: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x806FB948: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x806FB94C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806FB950: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB954: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x806FB958: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(700, 0X2738) << 16);
    // 0x806FB95C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x806FB960: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x806FB964: addiu       $t6, $t6, -0x3C98
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(700, 0X2738));
    // 0x806FB968: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x806FB96C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x806FB970: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x806FB974: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x806FB978: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806FB97C: sw          $t9, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r25;
    // 0x806FB980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FB984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FB988: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x806FB98C: jr          $ra
    // 0x806FB990: nop

    return;
    // 0x806FB990: nop

;}
RECOMP_FUNC void func_8000DA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DA50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000DA54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000DA58: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000DA5C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000DA60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000DA64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000DA68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000DA6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000DA70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000DA74: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8000DA78: lw          $s2, 0x34($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X34);
    // 0x8000DA7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DA80: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8000DA84: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8000DA88: sb          $zero, 0x80($s2)
    MEM_B(0X80, ctx->r18) = 0;
    // 0x8000DA8C: sw          $a2, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r6;
    // 0x8000DA90: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x8000DA94: andi        $t2, $t1, 0xBF
    ctx->r10 = ctx->r9 & 0XBF;
    // 0x8000DA98: sb          $t1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r9;
    // 0x8000DA9C: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
    // 0x8000DAA0: sh          $zero, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = 0;
    // 0x8000DAA4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_8000DAA8:
    // 0x8000DAA8: lw          $t3, 0x50($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X50);
    // 0x8000DAAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000DAB0: beql        $t3, $zero, L_8000DAC4
    if (ctx->r11 == 0) {
        // 0x8000DAB4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8000DAC4;
    }
    goto skip_0;
    // 0x8000DAB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8000DAB8: jal         0x8000D81C
    // 0x8000DABC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000D81C(rdram, ctx);
        goto after_0;
    // 0x8000DABC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000DAC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8000DAC4:
    // 0x8000DAC4: bne         $s0, $s3, L_8000DAA8
    if (ctx->r16 != ctx->r19) {
        // 0x8000DAC8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000DAA8;
    }
    // 0x8000DAC8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000DACC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000DAD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000DAD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000DAD8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DADC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000DAE0: jr          $ra
    // 0x8000DAE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000DAE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805A33FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A33FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A3400: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x805A3404: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x805A3408: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A340C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805A3410: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x805A3414: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A3418: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805A341C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A3420: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805A3424: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x805A3428: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805A342C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805A3430: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A3434: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x805A3438: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A343C: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x805A3440: addiu       $t3, $zero, 0x2C00
    ctx->r11 = ADD32(0, 0X2C00);
    // 0x805A3444: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x805A3448: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805A344C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805A3450: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805A3454: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A3458: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x805A345C: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x805A3460: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x805A3464: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805A3468: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x805A346C: ori         $a3, $a3, 0x4340
    ctx->r7 = ctx->r7 | 0X4340;
    // 0x805A3470: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x805A3474: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x805A3478: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A347C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x805A3480: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x805A3484: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A3488: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805A348C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x805A3490: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A3494: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A3498: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x805A349C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x805A34A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A34A4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805A34A8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x805A34AC: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x805A34B0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x805A34B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A34B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A34BC: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x805A34C0: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x805A34C4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x805A34C8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805A34CC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805A34D0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805A34D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805A34D8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x805A34DC: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x805A34E0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x805A34E4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805A34E8: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x805A34EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x805A34F0: jr          $ra
    // 0x805A34F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x805A34F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8043B670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B670: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8043B674: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(83, 0X248) << 16);
    // 0x8043B678: addiu       $t6, $t6, -0x5758
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(83, 0X248));
    // 0x8043B67C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8043B680: jr          $ra
    // 0x8043B684: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8043B684: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806ED198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED1A0: jal         0x80056904
    // 0x806ED1A4: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x806ED1A4: nop

    after_0:
    // 0x806ED1A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED1AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED1B0: jr          $ra
    // 0x806ED1B4: nop

    return;
    // 0x806ED1B4: nop

;}
RECOMP_FUNC void func_8073EB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EB18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073EB1C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8073EB20: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8073EB24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EB28: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8073EB2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8073EB30: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8073EB34: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8073EB38: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8073EB3C: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(748, 0X235C) << 16);
    // 0x8073EB40: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073EB44: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8073EB48: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8073EB4C: lw          $t2, 0xB4C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(748, 0X235C));
    // 0x8073EB50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8073EB54: jal         0x8073E8B0
    // 0x8073EB58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8073E8B0(rdram, ctx);
        goto after_0;
    // 0x8073EB58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8073EB5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EB60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EB64: jr          $ra
    // 0x8073EB68: nop

    return;
    // 0x8073EB68: nop

;}
RECOMP_FUNC void func_804C8950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8950: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804C8954: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C8958: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804C895C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804C8960: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C8964: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804C8968: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C896C: lwc1        $f20, 0x4($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C8970: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x804C8974: jal         0x80066DE4
    // 0x804C8978: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x804C8978: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804C897C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x804C8980: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804C8984: jal         0x80066E88
    // 0x804C8988: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804C8988: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804C898C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C8990: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804C8994: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804C8998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C899C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804C89A0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x804C89A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804C89A8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804C89AC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x804C89B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C89B4: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x804C89B8: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x804C89BC: nop

    // 0x804C89C0: bc1fl       L_804C89D4
    if (!c1cs) {
        // 0x804C89C4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_804C89D4;
    }
    goto skip_0;
    // 0x804C89C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x804C89C8: b           L_804C89EC
    // 0x804C89CC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
        goto L_804C89EC;
    // 0x804C89CC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x804C89D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_804C89D4:
    // 0x804C89D4: nop

    // 0x804C89D8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x804C89DC: nop

    // 0x804C89E0: bc1fl       L_804C89F0
    if (!c1cs) {
        // 0x804C89E4: swc1        $f20, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->f20.u32l;
            goto L_804C89F0;
    }
    goto skip_1;
    // 0x804C89E4: swc1        $f20, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f20.u32l;
    skip_1:
    // 0x804C89E8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_804C89EC:
    // 0x804C89EC: swc1        $f20, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f20.u32l;
L_804C89F0:
    // 0x804C89F0: jal         0x80049018
    // 0x804C89F4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x804C89F4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x804C89F8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804C89FC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x804C8A00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C8A04: mul.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x804C8A08: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X908) << 16);
    // 0x804C8A0C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804C8A10: lwc1        $f18, -0x6DB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X908));
    // 0x804C8A14: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x804C8A18: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804C8A1C: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x804C8A20: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C8A24: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804C8A28: lw          $t9, 0x59C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X59C);
    // 0x804C8A2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804C8A30: lwc1        $f18, 0x3C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x804C8A34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C8A38: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804C8A3C: lwc1        $f10, 0x104($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X104);
    // 0x804C8A40: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804C8A44: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x804C8A48: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x804C8A4C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804C8A50: lw          $t0, 0x59C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X59C);
    // 0x804C8A54: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x804C8A58: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x804C8A5C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804C8A60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804C8A64: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x804C8A68: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804C8A6C: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x804C8A70: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x804C8A74: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804C8A78: nop

    // 0x804C8A7C: bc1fl       L_804C8A98
    if (!c1cs) {
        // 0x804C8A80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804C8A98;
    }
    goto skip_2;
    // 0x804C8A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x804C8A84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804C8A88: nop

    // 0x804C8A8C: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x804C8A90: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x804C8A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804C8A98:
    // 0x804C8A98: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804C8A9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804C8AA0: jr          $ra
    // 0x804C8AA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x804C8AA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_806CED04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CED04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CED08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CED0C: jal         0x806CEC44
    // 0x806CED10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806CEC44(rdram, ctx);
        goto after_0;
    // 0x806CED10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806CED14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CED18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CED1C: jal         0x806CED40
    // 0x806CED20: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_806CED40(rdram, ctx);
        goto after_1;
    // 0x806CED20: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_1:
    // 0x806CED24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CED28: jal         0x806CEAFC
    // 0x806CED2C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_806CEAFC(rdram, ctx);
        goto after_2;
    // 0x806CED2C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x806CED30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CED34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CED38: jr          $ra
    // 0x806CED3C: nop

    return;
    // 0x806CED3C: nop

;}
RECOMP_FUNC void func_80046D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046D94: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80046D98: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80046D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046DA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046DA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046DA8: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80046DAC: lh          $a1, 0x184($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X184);
    // 0x80046DB0: jal         0x80046C58
    // 0x80046DB4: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    func_80046C58(rdram, ctx);
        goto after_0;
    // 0x80046DB4: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    after_0:
    // 0x80046DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046DC0: jr          $ra
    // 0x80046DC4: nop

    return;
    // 0x80046DC4: nop

;}
RECOMP_FUNC void func_806D1BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D1BC8: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D1BCC: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D1BD0: lw          $t6, 0xE88($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XE88);
    // 0x806D1BD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D1BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D1BDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D1BE0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x806D1BE4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D1BE8: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x806D1BEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D1BF0: lw          $v1, 0xD8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XD8);
    // 0x806D1BF4: bne         $t7, $at, L_806D1C0C
    if (ctx->r15 != ctx->r1) {
        // 0x806D1BF8: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_806D1C0C;
    }
    // 0x806D1BF8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x806D1BFC: jal         0x800447C8
    // 0x806D1C00: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806D1C00: nop

    after_0:
    // 0x806D1C04: b           L_806D1D90
    // 0x806D1C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D1D90;
    // 0x806D1C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1C0C:
    // 0x806D1C0C: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x806D1C10: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D1C14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D1C18: bnel        $t8, $zero, L_806D1CB0
    if (ctx->r24 != 0) {
        // 0x806D1C1C: lwc1        $f0, 0x8($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
            goto L_806D1CB0;
    }
    goto skip_0;
    // 0x806D1C1C: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    skip_0:
    // 0x806D1C20: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D1C24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D1C28: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D1C2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806D1C30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806D1C34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806D1C38: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x806D1C3C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806D1C40: nop

    // 0x806D1C44: bc1fl       L_806D1D3C
    if (!c1cs) {
        // 0x806D1C48: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D1D3C;
    }
    goto skip_1;
    // 0x806D1C48: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x806D1C4C: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x806D1C50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D1C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D1C58: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x806D1C5C: sw          $t2, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r10;
    // 0x806D1C60: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    // 0x806D1C64: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D1C68: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D1C6C: sw          $t4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r12;
    // 0x806D1C70: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806D1C74: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1720) << 16);
    // 0x806D1C78: bc1f        L_806D1CA4
    if (!c1cs) {
        // 0x806D1C7C: nop
    
            goto L_806D1CA4;
    }
    // 0x806D1C7C: nop

    // 0x806D1C80: lwc1        $f2, 0x2CE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1720));
    // 0x806D1C84: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806D1C88: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x806D1C8C: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806D1C90: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x806D1C94: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x806D1C98: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x806D1C9C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x806D1CA0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
L_806D1CA4:
    // 0x806D1CA4: b           L_806D1D38
    // 0x806D1CA8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_806D1D38;
    // 0x806D1CA8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x806D1CAC: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
L_806D1CB0:
    // 0x806D1CB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D1CB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D1CB8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806D1CBC: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x806D1CC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806D1CC4: nop

    // 0x806D1CC8: bc1fl       L_806D1D3C
    if (!c1cs) {
        // 0x806D1CCC: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D1D3C;
    }
    goto skip_2;
    // 0x806D1CCC: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_2:
    // 0x806D1CD0: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x806D1CD4: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D1CD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D1CDC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806D1CE0: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x806D1CE4: nop

    // 0x806D1CE8: bc1fl       L_806D1D3C
    if (!c1cs) {
        // 0x806D1CEC: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D1D3C;
    }
    goto skip_3;
    // 0x806D1CEC: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_3:
    // 0x806D1CF0: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x806D1CF4: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x806D1CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D1CFC: bne         $t5, $zero, L_806D1D38
    if (ctx->r13 != 0) {
        // 0x806D1D00: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806D1D38;
    }
    // 0x806D1D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D1D04: sw          $t6, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r14;
    // 0x806D1D08: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x806D1D0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806D1D10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806D1D14: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806D1D18: jal         0x806D2BCC
    // 0x806D1D1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806D2BCC(rdram, ctx);
        goto after_1;
    // 0x806D1D1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x806D1D20: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D1D24: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D1D28: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806D1D2C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806D1D30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x806D1D34: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
L_806D1D38:
    // 0x806D1D38: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
L_806D1D3C:
    // 0x806D1D3C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x806D1D40: bne         $t7, $zero, L_806D1D8C
    if (ctx->r15 != 0) {
        // 0x806D1D44: swc1        $f2, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
            goto L_806D1D8C;
    }
    // 0x806D1D44: swc1        $f2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
    // 0x806D1D48: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(610, 0X1670) << 16);
    // 0x806D1D4C: lui         $v1, 0x806D
    ctx->r3 = S32(RELOC_HI16(610, 0X1678) << 16);
    // 0x806D1D50: addiu       $v1, $v1, 0x2C38
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(610, 0X1678));
    // 0x806D1D54: addiu       $v0, $v0, 0x2C30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(610, 0X1670));
L_806D1D58:
    // 0x806D1D58: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D1D5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x806D1D60: bne         $v0, $v1, L_806D1D58
    if (ctx->r2 != ctx->r3) {
        // 0x806D1D64: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_806D1D58;
    }
    // 0x806D1D64: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806D1D68: lw          $t8, 0xA68($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XA68);
    // 0x806D1D6C: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X1670) << 16);
    // 0x806D1D70: addiu       $a1, $a1, 0x2C30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X1670));
    // 0x806D1D74: lw          $t1, 0x10($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X10);
    // 0x806D1D78: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D1D7C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D1D80: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x806D1D84: jalr        $t9
    // 0x806D1D88: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x806D1D88: nop

    after_2:
L_806D1D8C:
    // 0x806D1D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1D90:
    // 0x806D1D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D1D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D1D98: jr          $ra
    // 0x806D1D9C: nop

    return;
    // 0x806D1D9C: nop

;}
RECOMP_FUNC void func_806B079C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B079C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B07A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B07A4: lwc1        $f6, 0x104($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X104);
    // 0x806B07A8: lwc1        $f4, 0xC8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x806B07AC: lwc1        $f10, 0x110($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X110);
    // 0x806B07B0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806B07B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B07B8: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x806B07BC: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806B07C0: lwc1        $f18, 0x40($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X40);
    // 0x806B07C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806B07C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806B07CC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806B07D0: jal         0x806B038C
    // 0x806B07D4: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    func_806B038C(rdram, ctx);
        goto after_0;
    // 0x806B07D4: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    after_0:
    // 0x806B07D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B07DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B07E0: jr          $ra
    // 0x806B07E4: nop

    return;
    // 0x806B07E4: nop

;}
RECOMP_FUNC void func_80447680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447684: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80447688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044768C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447690: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447694: bne         $a2, $zero, L_804476E0
    if (ctx->r6 != 0) {
        // 0x80447698: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_804476E0;
    }
    // 0x80447698: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044769C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x804476A0: lw          $v0, 0x68($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X68);
    // 0x804476A4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x804476A8: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804476AC: beq         $at, $zero, L_804476BC
    if (ctx->r1 == 0) {
        // 0x804476B0: subu        $t7, $a1, $a3
        ctx->r15 = SUB32(ctx->r5, ctx->r7);
            goto L_804476BC;
    }
    // 0x804476B0: subu        $t7, $a1, $a3
    ctx->r15 = SUB32(ctx->r5, ctx->r7);
    // 0x804476B4: b           L_80447724
    // 0x804476B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_80447724;
    // 0x804476B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_804476BC:
    // 0x804476BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804476C0: jal         0x8044610C
    // 0x804476C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044610C(rdram, ctx);
        goto after_0;
    // 0x804476C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804476C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804476CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804476D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x804476D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804476D8: b           L_80447724
    // 0x804476DC: sw          $t8, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r24;
        goto L_80447724;
    // 0x804476DC: sw          $t8, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r24;
L_804476E0:
    // 0x804476E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804476E4: bne         $a2, $at, L_8044770C
    if (ctx->r6 != ctx->r1) {
        // 0x804476E8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8044770C;
    }
    // 0x804476E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804476EC: jal         0x8044610C
    // 0x804476F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044610C(rdram, ctx);
        goto after_1;
    // 0x804476F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804476F4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804476F8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804476FC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80447700: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80447704: b           L_80447724
    // 0x80447708: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80447724;
    // 0x80447708: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044770C:
    // 0x8044770C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80447710: bne         $a2, $at, L_80447724
    if (ctx->r6 != ctx->r1) {
        // 0x80447714: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80447724;
    }
    // 0x80447714: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447718: jal         0x80446170
    // 0x8044771C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80446170(rdram, ctx);
        goto after_2;
    // 0x8044771C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80447720: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80447724:
    // 0x80447724: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80447728: jal         0x804475C0
    // 0x8044772C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_804475C0(rdram, ctx);
        goto after_3;
    // 0x8044772C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80447730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80447734: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044773C: jr          $ra
    // 0x80447740: nop

    return;
    // 0x80447740: nop

;}
RECOMP_FUNC void func_80033760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033760: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033764: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80033768: lwc1        $f4, 0x68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X68);
    // 0x8003376C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80033770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033774: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80033778: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003377C: lwc1        $f2, 0x188($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X188);
    // 0x80033780: lwc1        $f12, 0x18C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18C);
    // 0x80033784: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80033788: nop

    // 0x8003378C: bc1fl       L_800337E0
    if (!c1cs) {
        // 0x80033790: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800337E0;
    }
    goto skip_0;
    // 0x80033790: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80033794: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80033798: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8003379C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800337A0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800337A4: jal         0x80066E88
    // 0x800337A8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800337A8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800337AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800337B0: lwc1        $f6, 0x6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C);
    // 0x800337B4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800337B8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800337BC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800337C0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800337C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800337C8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800337CC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800337D0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800337D4: b           L_80033854
    // 0x800337D8: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
        goto L_80033854;
    // 0x800337D8: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800337DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_800337E0:
    // 0x800337E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800337E4: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x800337E8: nop

    // 0x800337EC: bc1f        L_80033800
    if (!c1cs) {
        // 0x800337F0: nop
    
            goto L_80033800;
    }
    // 0x800337F0: nop

    // 0x800337F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800337F8: b           L_80033808
    // 0x800337FC: lwc1        $f12, 0x70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X70);
        goto L_80033808;
    // 0x800337FC: lwc1        $f12, 0x70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X70);
L_80033800:
    // 0x80033800: lwc1        $f4, 0x74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X74);
    // 0x80033804: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
L_80033808:
    // 0x80033808: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003380C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033810: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80033814: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80033818: nop

    // 0x8003381C: bc1fl       L_80033830
    if (!c1cs) {
        // 0x80033820: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80033830;
    }
    goto skip_1;
    // 0x80033820: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x80033824: b           L_80033854
    // 0x80033828: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80033854;
    // 0x80033828: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8003382C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80033830:
    // 0x80033830: nop

    // 0x80033834: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80033838: nop

    // 0x8003383C: bc1fl       L_80033850
    if (!c1cs) {
        // 0x80033840: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80033850;
    }
    goto skip_2;
    // 0x80033840: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x80033844: b           L_80033850
    // 0x80033848: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_80033850;
    // 0x80033848: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x8003384C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80033850:
    // 0x80033850: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80033854:
    // 0x80033854: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80033858: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8003385C: bc1fl       L_8003387C
    if (!c1cs) {
        // 0x80033860: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_8003387C;
    }
    goto skip_3;
    // 0x80033860: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_3:
    // 0x80033864: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80033868: nop

    // 0x8003386C: bc1fl       L_8003387C
    if (!c1cs) {
        // 0x80033870: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_8003387C;
    }
    goto skip_4;
    // 0x80033870: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_4:
    // 0x80033874: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80033878: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_8003387C:
    // 0x8003387C: nop

    // 0x80033880: bc1fl       L_80033894
    if (!c1cs) {
        // 0x80033884: swc1        $f2, 0x188($v0)
        MEM_W(0X188, ctx->r2) = ctx->f2.u32l;
            goto L_80033894;
    }
    goto skip_5;
    // 0x80033884: swc1        $f2, 0x188($v0)
    MEM_W(0X188, ctx->r2) = ctx->f2.u32l;
    skip_5:
    // 0x80033888: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8003388C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80033890: swc1        $f2, 0x188($v0)
    MEM_W(0X188, ctx->r2) = ctx->f2.u32l;
L_80033894:
    // 0x80033894: swc1        $f12, 0x18C($v0)
    MEM_W(0X18C, ctx->r2) = ctx->f12.u32l;
    // 0x80033898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003389C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800338A0: jr          $ra
    // 0x800338A4: nop

    return;
    // 0x800338A4: nop

;}
RECOMP_FUNC void func_804E9A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9A28: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804E9A2C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804E9A30: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804E9A34: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(264, 0X7BC) << 16);
    // 0x804E9A38: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804E9A3C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804E9A40: addiu       $t7, $t7, -0x5ED4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(264, 0X7BC));
    // 0x804E9A44: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804E9A48: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804E9A4C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804E9A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804E9A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804E9A58: jal         0x804E9F98
    // 0x804E9A5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804E9F98(rdram, ctx);
        goto after_0;
    // 0x804E9A5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804E9A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9A68: jr          $ra
    // 0x804E9A6C: nop

    return;
    // 0x804E9A6C: nop

;}
RECOMP_FUNC void func_804B94D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B94D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804B94D8: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x804B94DC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x804B94E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B94E4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x804B94E8: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x804B94EC: jr          $ra
    // 0x804B94F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x804B94F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_804BF568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BF568: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804BF56C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BF570: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804BF574: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804BF578: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BF57C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804BF580: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804BF584: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804BF588: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804BF58C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804BF590: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X4124) << 16);
    // 0x804BF594: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804BF598: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BF59C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804BF5A0: lw          $t1, -0x5AC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(191, 0X4124));
    // 0x804BF5A4: jr          $ra
    // 0x804BF5A8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804BF5A8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804BF5AC: nop

;}
RECOMP_FUNC void func_80530FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530FA4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80530FA8: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80530FAC: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80530FB0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80530FB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80530FB8: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80530FBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80530FC0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80530FC4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80530FC8: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x80530FCC: lui         $t1, 0xFFFC
    ctx->r9 = S32(0XFFFC << 16);
    // 0x80530FD0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80530FD4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80530FD8: ori         $t1, $t1, 0xF279
    ctx->r9 = ctx->r9 | 0XF279;
    // 0x80530FDC: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80530FE0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80530FE4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80530FE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80530FEC: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x80530FF0: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x80530FF4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80530FF8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80530FFC: ori         $t4, $t4, 0xAC80
    ctx->r12 = ctx->r12 | 0XAC80;
    // 0x80531000: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x80531004: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80531008: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8053100C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80531010: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80531014: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x80531018: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8053101C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80531020: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x80531024: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80531028: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8053102C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80531030: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80531034: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80531038: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8053103C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80531040: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80531044: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80531048: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8053104C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80531050: addiu       $t1, $zero, 0x2204
    ctx->r9 = ADD32(0, 0X2204);
    // 0x80531054: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x80531058: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8053105C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80531060: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80531064: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80531068: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8053106C: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80531070: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x80531074: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80531078: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8053107C: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80531080: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x80531084: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80531088: jr          $ra
    // 0x8053108C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x8053108C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_80055370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055370: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80055374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055378: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005537C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80055380: jal         0x80047090
    // 0x80055384: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80055384: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x80055388: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005538C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80055390: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80055394: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055398: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005539C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800553A0: jal         0x8004613C
    // 0x800553A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x800553A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x800553A8: bne         $v0, $zero, L_800553B8
    if (ctx->r2 != 0) {
        // 0x800553AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800553B8;
    }
    // 0x800553AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800553B0: b           L_800553E4
    // 0x800553B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800553E4;
    // 0x800553B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800553B8:
    // 0x800553B8: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x800553BC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x800553C0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x800553C4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x800553C8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800553CC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x800553D0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800553D4: jal         0x80047F9C
    // 0x800553D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x800553D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800553DC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800553E0: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
L_800553E4:
    // 0x800553E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800553E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800553EC: jr          $ra
    // 0x800553F0: nop

    return;
    // 0x800553F0: nop

;}
RECOMP_FUNC void func_807ACC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACC5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807ACC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ACC64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807ACC68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807ACC6C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26AC) << 16);
    // 0x807ACC70: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807ACC74: swc1        $f4, 0x470($v0)
    MEM_W(0X470, ctx->r2) = ctx->f4.u32l;
    // 0x807ACC78: lwc1        $f6, -0x12F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26AC));
    // 0x807ACC7C: addiu       $a0, $v0, 0x3E8
    ctx->r4 = ADD32(ctx->r2, 0X3E8);
    // 0x807ACC80: swc1        $f6, 0x474($v0)
    MEM_W(0X474, ctx->r2) = ctx->f6.u32l;
    // 0x807ACC84: jal         0x80086F28
    // 0x807ACC88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gMtxIdent(rdram, ctx);
        goto after_0;
    // 0x807ACC88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807ACC8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807ACC90: jal         0x80086F28
    // 0x807ACC94: addiu       $a0, $v0, 0x428
    ctx->r4 = ADD32(ctx->r2, 0X428);
    gMtxIdent(rdram, ctx);
        goto after_1;
    // 0x807ACC94: addiu       $a0, $v0, 0x428
    ctx->r4 = ADD32(ctx->r2, 0X428);
    after_1:
    // 0x807ACC98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807ACC9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x807ACCA0: sw          $zero, 0x468($v0)
    MEM_W(0X468, ctx->r2) = 0;
    // 0x807ACCA4: swc1        $f8, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f8.u32l;
    // 0x807ACCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ACCAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807ACCB0: jr          $ra
    // 0x807ACCB4: nop

    return;
    // 0x807ACCB4: nop

;}
RECOMP_FUNC void func_807BAA7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAA7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BAA80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAA84: jal         0x8004700C
    // 0x807BAA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807BAA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BAA8C: bne         $v0, $zero, L_807BAA9C
    if (ctx->r2 != 0) {
        // 0x807BAA90: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807BAA9C;
    }
    // 0x807BAA90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BAA94: b           L_807BAAEC
    // 0x807BAA98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAAEC;
    // 0x807BAA98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BAA9C:
    // 0x807BAA9C: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x807BAAA0: bnel        $t6, $zero, L_807BAACC
    if (ctx->r14 != 0) {
        // 0x807BAAA4: lwc1        $f8, 0x84($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
            goto L_807BAACC;
    }
    goto skip_0;
    // 0x807BAAA4: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x807BAAA8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807BAAAC: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807BAAB0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807BAAB4: nop

    // 0x807BAAB8: bc1fl       L_807BAAEC
    if (!c1cs) {
        // 0x807BAABC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807BAAEC;
    }
    goto skip_1;
    // 0x807BAABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x807BAAC0: b           L_807BAAEC
    // 0x807BAAC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAAEC;
    // 0x807BAAC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807BAAC8: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
L_807BAACC:
    // 0x807BAACC: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807BAAD0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x807BAAD4: nop

    // 0x807BAAD8: bc1fl       L_807BAAEC
    if (!c1cs) {
        // 0x807BAADC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807BAAEC;
    }
    goto skip_2;
    // 0x807BAADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x807BAAE0: b           L_807BAAEC
    // 0x807BAAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAAEC;
    // 0x807BAAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807BAAE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BAAEC:
    // 0x807BAAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAAF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BAAF4: jr          $ra
    // 0x807BAAF8: nop

    return;
    // 0x807BAAF8: nop

;}
RECOMP_FUNC void func_804E9B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9B28: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804E9B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804E9B30: beq         $t6, $zero, L_804E9B6C
    if (ctx->r14 == 0) {
        // 0x804E9B34: nop
    
            goto L_804E9B6C;
    }
    // 0x804E9B34: nop

    // 0x804E9B38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E9B3C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804E9B40: jalr        $t9
    // 0x804E9B44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804E9B44: nop

    after_0:
    // 0x804E9B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E9B4C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804E9B50: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804E9B54: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804E9B58: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804E9B5C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804E9B60: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804E9B64: b           L_804E9B6C
    // 0x804E9B68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804E9B6C;
    // 0x804E9B68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804E9B6C:
    // 0x804E9B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9B74: jr          $ra
    // 0x804E9B78: nop

    return;
    // 0x804E9B78: nop

;}
RECOMP_FUNC void func_804C1D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C1D9C: jal         0x80045A34
    // 0x804C1DA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C1DA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x804C1DA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C1DA8: bne         $v0, $zero, L_804C1DB8
    if (ctx->r2 != 0) {
        // 0x804C1DAC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C1DB8;
    }
    // 0x804C1DAC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C1DB0: b           L_804C1DC4
    // 0x804C1DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C1DC4;
    // 0x804C1DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C1DB8:
    // 0x804C1DB8: jal         0x804C1D7C
    // 0x804C1DBC: nop

    func_804C1D7C(rdram, ctx);
        goto after_1;
    // 0x804C1DBC: nop

    after_1:
    // 0x804C1DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C1DC4:
    // 0x804C1DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1DCC: jr          $ra
    // 0x804C1DD0: nop

    return;
    // 0x804C1DD0: nop

;}
RECOMP_FUNC void func_80699F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699F68: jal         0x80699C60
    // 0x80699F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x80699F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80699F70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80699F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699F78: jal         0x8069A0F0
    // 0x80699F7C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x80699F7C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80699F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699F88: jr          $ra
    // 0x80699F8C: nop

    return;
    // 0x80699F8C: nop

;}
RECOMP_FUNC void func_80011990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011994: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80011998: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001199C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800119A0: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x800119A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800119A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800119AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800119B0: addiu       $s3, $zero, 0x32
    ctx->r19 = ADD32(0, 0X32);
    // 0x800119B4: addiu       $s2, $s2, -0x5AD0
    ctx->r18 = ADD32(ctx->r18, -0X5AD0);
    // 0x800119B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800119BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800119C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
L_800119C4:
    // 0x800119C4: slti        $at, $s0, 0x77
    ctx->r1 = SIGNED(ctx->r16) < 0X77 ? 1 : 0;
    // 0x800119C8: beq         $at, $zero, L_80011A00
    if (ctx->r1 == 0) {
        // 0x800119CC: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_80011A00;
    }
    // 0x800119CC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800119D0: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x800119D4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800119D8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800119DC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800119E0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800119E4: jal         0x8001B8FC
    // 0x800119E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8001B8FC(rdram, ctx);
        goto after_0;
    // 0x800119E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800119EC: bne         $s0, $s3, L_80011A00
    if (ctx->r16 != ctx->r19) {
        // 0x800119F0: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80011A00;
    }
    // 0x800119F0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800119F4: addiu       $s0, $zero, 0x1C
    ctx->r16 = ADD32(0, 0X1C);
    // 0x800119F8: b           L_800119C4
    // 0x800119FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800119C4;
    // 0x800119FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80011A00:
    // 0x80011A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80011A04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80011A08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80011A0C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80011A10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80011A14: jr          $ra
    // 0x80011A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80011A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806AFFC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AFFC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806AFFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AFFD0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806AFFD4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x806AFFD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AFFDC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806AFFE0: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x806AFFE4: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x806AFFE8: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x806AFFEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806AFFF0: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806AFFF4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x806AFFF8: jal         0x80065954
    // 0x806AFFFC: sub.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x806AFFFC: sub.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f6.fl;
    after_0:
    // 0x806B0000: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806B0004: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B0008: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806B000C: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806B0010: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806B0014: nop

    // 0x806B0018: bc1fl       L_806B002C
    if (!c1cs) {
        // 0x806B001C: lwc1        $f0, 0x58($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
            goto L_806B002C;
    }
    goto skip_0;
    // 0x806B001C: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    skip_0:
    // 0x806B0020: b           L_806B004C
    // 0x806B0024: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
        goto L_806B004C;
    // 0x806B0024: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
    // 0x806B0028: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
L_806B002C:
    // 0x806B002C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806B0030: nop

    // 0x806B0034: bc1fl       L_806B0048
    if (!c1cs) {
        // 0x806B0038: sub.s       $f2, $f0, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_806B0048;
    }
    goto skip_1;
    // 0x806B0038: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
    // 0x806B003C: b           L_806B0048
    // 0x806B0040: add.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f12.fl;
        goto L_806B0048;
    // 0x806B0040: add.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x806B0044: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
L_806B0048:
    // 0x806B0048: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
L_806B004C:
    // 0x806B004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B0054: jr          $ra
    // 0x806B0058: nop

    return;
    // 0x806B0058: nop

;}
RECOMP_FUNC void func_8000B8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B8E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000B8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B8E8: bne         $a0, $at, L_8000B8F8
    if (ctx->r4 != ctx->r1) {
        // 0x8000B8EC: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8000B8F8;
    }
    // 0x8000B8EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000B8F0: b           L_8000B9B0
    // 0x8000B8F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B9B0;
    // 0x8000B8F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B8F8:
    // 0x8000B8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B8FC: jal         0x800066A8
    // 0x8000B900: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800066A8(rdram, ctx);
        goto after_0;
    // 0x8000B900: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000B904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B908: bne         $v0, $zero, L_8000B92C
    if (ctx->r2 != 0) {
        // 0x8000B90C: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B92C;
    }
    // 0x8000B90C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B910: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000B914: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000B918: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000B91C: addu        $t6, $a0, $at
    ctx->r14 = ADD32(ctx->r4, ctx->r1);
    // 0x8000B920: sw          $t6, 0x1E98($a3)
    MEM_W(0X1E98, ctx->r7) = ctx->r14;
    // 0x8000B924: b           L_8000B9B0
    // 0x8000B928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B9B0;
    // 0x8000B928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B92C:
    // 0x8000B92C: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000B930: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000B934: lw          $t7, 0x1D78($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1D78);
    // 0x8000B938: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8000B93C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8000B940: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000B944: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8000B948: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8000B94C: sll         $t0, $a0, 8
    ctx->r8 = S32(ctx->r4 << 8);
    // 0x8000B950: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x8000B954: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000B958: bne         $at, $zero, L_8000B970
    if (ctx->r1 != 0) {
        // 0x8000B95C: lui         $at, 0x400
        ctx->r1 = S32(0X400 << 16);
            goto L_8000B970;
    }
    // 0x8000B95C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8000B960: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8000B964: sw          $t2, 0x1E98($a3)
    MEM_W(0X1E98, ctx->r7) = ctx->r10;
    // 0x8000B968: b           L_8000B9B0
    // 0x8000B96C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B9B0;
    // 0x8000B96C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B970:
    // 0x8000B970: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8000B974: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B978: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8000B97C: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x8000B980: beq         $at, $zero, L_8000B990
    if (ctx->r1 == 0) {
        // 0x8000B984: addu        $t4, $v1, $t3
        ctx->r12 = ADD32(ctx->r3, ctx->r11);
            goto L_8000B990;
    }
    // 0x8000B984: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8000B988: b           L_8000B9B0
    // 0x8000B98C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B9B0;
    // 0x8000B98C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B990:
    // 0x8000B990: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x8000B994: sll         $t5, $a0, 8
    ctx->r13 = S32(ctx->r4 << 8);
    // 0x8000B998: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8000B99C: bne         $a1, $zero, L_8000B9B0
    if (ctx->r5 != 0) {
        // 0x8000B9A0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000B9B0;
    }
    // 0x8000B9A0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000B9A4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8000B9A8: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8000B9AC: sw          $t7, 0x1E98($a3)
    MEM_W(0X1E98, ctx->r7) = ctx->r15;
L_8000B9B0:
    // 0x8000B9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B9B8: jr          $ra
    // 0x8000B9BC: nop

    return;
    // 0x8000B9BC: nop

;}
RECOMP_FUNC void func_804497B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804497B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804497BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804497C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804497C4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804497C8: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804497CC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804497D0: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13394) << 16);
    // 0x804497D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804497D8: lw          $v1, 0x6CBC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CBC);
    // 0x804497DC: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x804497E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804497E4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804497E8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x804497EC: lw          $t0, 0x7774($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13394));
    // 0x804497F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804497F4: beql        $t0, $zero, L_80449808
    if (ctx->r8 == 0) {
        // 0x804497F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80449808;
    }
    goto skip_0;
    // 0x804497F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804497FC: jalr        $t0
    // 0x80449800: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x80449800: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80449804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80449808:
    // 0x80449808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044980C: jr          $ra
    // 0x80449810: nop

    return;
    // 0x80449810: nop

;}
RECOMP_FUNC void func_80709860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709860: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80709864: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(718, 0X1320) << 16);
    // 0x80709868: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(718, 0X1320));
    // 0x8070986C: beq         $v1, $zero, L_80709880
    if (ctx->r3 == 0) {
        // 0x80709870: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80709880;
    }
    // 0x80709870: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80709874: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80709878: jr          $ra
    // 0x8070987C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8070987C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80709880:
    // 0x80709880: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80709884: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x80709888: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x8070988C: bne         $at, $zero, L_8070989C
    if (ctx->r1 != 0) {
        // 0x80709890: sw          $v1, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r3;
            goto L_8070989C;
    }
    // 0x80709890: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80709894: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x80709898: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_8070989C:
    // 0x8070989C: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x807098A0: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x807098A4: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x807098A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807098AC: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x807098B0: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x807098B4: sw          $t3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r11;
    // 0x807098B8: jr          $ra
    // 0x807098BC: nop

    return;
    // 0x807098BC: nop

;}
RECOMP_FUNC void func_804230A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804230A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804230A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804230A8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804230AC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804230B0: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X31E4) << 16);
    // 0x804230B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804230B8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804230BC: lw          $t8, 0x5BE4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X31E4));
    // 0x804230C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804230C4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804230C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804230CC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804230D0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804230D4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804230D8: beql        $v1, $zero, L_8042310C
    if (ctx->r3 == 0) {
        // 0x804230DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042310C;
    }
    goto skip_0;
    // 0x804230DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804230E0: jalr        $v1
    // 0x804230E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804230E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804230E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804230EC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804230F0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804230F4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804230F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804230FC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80423100: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80423104: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80423108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042310C:
    // 0x8042310C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423110: jr          $ra
    // 0x80423114: nop

    return;
    // 0x80423114: nop

;}
RECOMP_FUNC void func_804BB604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB60C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804BB610: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804BB614: beql        $t6, $zero, L_804BB654
    if (ctx->r14 == 0) {
        // 0x804BB618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BB654;
    }
    goto skip_0;
    // 0x804BB618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BB61C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BB620: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804BB624: jalr        $t9
    // 0x804BB628: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804BB628: nop

    after_0:
    // 0x804BB62C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB630: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804BB634: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804BB638: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804BB63C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804BB640: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804BB644: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804BB648: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804BB64C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x804BB650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB654:
    // 0x804BB654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB658: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x804BB65C: jr          $ra
    // 0x804BB660: nop

    return;
    // 0x804BB660: nop

    // 0x804BB664: nop

    // 0x804BB668: nop

    // 0x804BB66C: nop

;}
RECOMP_FUNC void func_806F3450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F3454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F3458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F345C: lui         $a0, 0x806F
    ctx->r4 = S32(RELOC_HI16(682, 0XB00) << 16);
    // 0x806F3460: lui         $a1, 0x806F
    ctx->r5 = S32(RELOC_HI16(682, 0XB10) << 16);
    // 0x806F3464: addiu       $a1, $a1, 0x3F60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(682, 0XB10));
    // 0x806F3468: addiu       $a0, $a0, 0x3F50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(682, 0XB00));
    // 0x806F346C: jal         0x8004667C
    // 0x806F3470: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806F3470: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x806F3474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F3478: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(682, 0X7C0) << 16);
    // 0x806F347C: addiu       $t6, $t6, 0x3C10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(682, 0X7C0));
    // 0x806F3480: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F3484: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(682, 0X49C) << 16);
    // 0x806F3488: sw          $t6, -0x72E8($at)
    MEM_W(-0X72E8, ctx->r1) = ctx->r14;
    // 0x806F348C: addiu       $v0, $v0, 0x38EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(682, 0X49C));
    // 0x806F3490: jr          $ra
    // 0x806F3494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806F3494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8067E94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E94C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067E950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067E954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067E958: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067E95C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067E960: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(544, 0X118C) << 16);
    // 0x8067E964: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8067E968: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8067E96C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8067E970: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8067E974: nop

    // 0x8067E978: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8067E97C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8067E980: beq         $v0, $zero, L_8067E998
    if (ctx->r2 == 0) {
        // 0x8067E984: nop
    
            goto L_8067E998;
    }
    // 0x8067E984: nop

    // 0x8067E988: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(544, 0X1188) << 16);
    // 0x8067E98C: lwc1        $f8, -0xFB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X1188));
    // 0x8067E990: b           L_8067E9A0
    // 0x8067E994: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
        goto L_8067E9A0;
    // 0x8067E994: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
L_8067E998:
    // 0x8067E998: lwc1        $f10, -0xFB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X118C));
    // 0x8067E99C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_8067E9A0:
    // 0x8067E9A0: sw          $t7, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r15;
    // 0x8067E9A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8067E9A8: jal         0x8067E728
    // 0x8067E9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E728(rdram, ctx);
        goto after_0;
    // 0x8067E9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8067E9B0: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8067E9B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8067E9B8: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(544, 0X1148) << 16);
    // 0x8067E9BC: addiu       $t8, $t8, -0xFF8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(544, 0X1148));
    // 0x8067E9C0: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8067E9C4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8067E9C8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8067E9CC: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8067E9D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8067E9D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8067E9D8: sw          $t0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r8;
    // 0x8067E9DC: jal         0x80048378
    // 0x8067E9E0: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8067E9E0: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    after_1:
    // 0x8067E9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E9E8: jal         0x80045A34
    // 0x8067E9EC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8067E9EC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_2:
    // 0x8067E9F0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8067E9F4: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8067E9F8: jal         0x8067E780
    // 0x8067E9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E780(rdram, ctx);
        goto after_3;
    // 0x8067E9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8067EA00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067EA04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067EA08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067EA0C: jr          $ra
    // 0x8067EA10: nop

    return;
    // 0x8067EA10: nop

;}
RECOMP_FUNC void func_805CEF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CEF60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805CEF64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CEF68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805CEF6C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805CEF70: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(459, 0X324) << 16);
    // 0x805CEF74: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805CEF78: addiu       $t6, $t6, -0xDCC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(459, 0X324));
    // 0x805CEF7C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805CEF80: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805CEF84: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x805CEF88: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805CEF8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805CEF90: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x805CEF94: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805CEF98: addiu       $a2, $a0, 0xC4
    ctx->r6 = ADD32(ctx->r4, 0XC4);
    // 0x805CEF9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805CEFA0: jal         0x80048378
    // 0x805CEFA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x805CEFA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x805CEFA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805CEFAC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x805CEFB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805CEFB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805CEFB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805CEFBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805CEFC0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(459, 0X340) << 16);
    // 0x805CEFC4: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFC8: swc1        $f0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFCC: swc1        $f0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFD0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x805CEFD4: swc1        $f6, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f6.u32l;
    // 0x805CEFD8: lwc1        $f8, -0xDB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(459, 0X340));
    // 0x805CEFDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805CEFE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805CEFE4: swc1        $f0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFE8: swc1        $f0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFEC: swc1        $f0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFF0: swc1        $f0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f0.u32l;
    // 0x805CEFF4: jal         0x805CF180
    // 0x805CEFF8: swc1        $f8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f8.u32l;
    func_805CF180(rdram, ctx);
        goto after_1;
    // 0x805CEFF8: swc1        $f8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x805CEFFC: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(459, 0X310) << 16);
    // 0x805CF000: addiu       $v0, $v0, -0xDE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(459, 0X310));
    // 0x805CF004: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x805CF008: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x805CF00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805CF010: jalr        $t9
    // 0x805CF014: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805CF014: nop

    after_2:
    // 0x805CF018: lw          $t0, 0x15C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X15C);
    // 0x805CF01C: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x805CF020: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805CF024: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x805CF028: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x805CF02C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805CF030: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x805CF034: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x805CF038: jal         0x80067BBC
    // 0x805CF03C: sh          $t5, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r13;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805CF03C: sh          $t5, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r13;
    after_3:
    // 0x805CF040: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    // 0x805CF044: jal         0x80067818
    // 0x805CF048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805CF048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805CF04C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805CF050: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805CF054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805CF058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805CF05C: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x805CF060: jr          $ra
    // 0x805CF064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805CF064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805DCC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DCC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DCC38: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805DCC3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805DCC40: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805DCC44: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x805DCC48: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805DCC4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DCC50: jal         0x80045A34
    // 0x805DCC54: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805DCC54: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_0:
    // 0x805DCC58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DCC5C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x805DCC60: beq         $v0, $zero, L_805DCC80
    if (ctx->r2 == 0) {
        // 0x805DCC64: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805DCC80;
    }
    // 0x805DCC64: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805DCC68: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x805DCC6C: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x805DCC70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805DCC74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805DCC78: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x805DCC7C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
L_805DCC80:
    // 0x805DCC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DCC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DCC88: jr          $ra
    // 0x805DCC8C: nop

    return;
    // 0x805DCC8C: nop

;}
RECOMP_FUNC void func_804241A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804241A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804241A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804241AC: jal         0x804233F4
    // 0x804241B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_804233F4(rdram, ctx);
        goto after_0;
    // 0x804241B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x804241B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x804241B8: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X2F0C) << 16);
    // 0x804241BC: addiu       $a1, $a1, 0x590C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X2F0C));
    // 0x804241C0: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x804241C4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x804241C8: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x804241CC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x804241D0: addiu       $t7, $v0, 0x28
    ctx->r15 = ADD32(ctx->r2, 0X28);
    // 0x804241D4: addiu       $t8, $v0, 0x90
    ctx->r24 = ADD32(ctx->r2, 0X90);
    // 0x804241D8: addiu       $t9, $v0, 0x9C
    ctx->r25 = ADD32(ctx->r2, 0X9C);
    // 0x804241DC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x804241E0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x804241E4: jal         0x80423EF8
    // 0x804241E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80423EF8(rdram, ctx);
        goto after_1;
    // 0x804241E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x804241EC: jal         0x804235A8
    // 0x804241F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804235A8(rdram, ctx);
        goto after_2;
    // 0x804241F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x804241F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804241F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804241FC: jr          $ra
    // 0x80424200: nop

    return;
    // 0x80424200: nop

;}
RECOMP_FUNC void func_80737E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80737EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737EA4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80737EA8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80737EAC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80737EB0: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(736, 0X3A24) << 16);
    // 0x80737EB4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80737EB8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80737EBC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80737EC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80737EC4: lw          $t8, -0x6B7C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(736, 0X3A24));
    // 0x80737EC8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80737ECC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80737ED0: jal         0x80048490
    // 0x80737ED4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80737ED4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80737ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80737EE0: jr          $ra
    // 0x80737EE4: nop

    return;
    // 0x80737EE4: nop

;}
RECOMP_FUNC void func_800563D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800563D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800563DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800563E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800563E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800563E8: jal         0x80047090
    // 0x800563EC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x800563EC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x800563F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800563F4: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x800563F8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800563FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80056400: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80056404: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80056408: jal         0x8004613C
    // 0x8005640C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8005640C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x80056410: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x80056414: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x80056418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005641C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80056420: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80056424: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80056428: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x8005642C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80056430: jal         0x80047F9C
    // 0x80056434: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80056434: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80056438: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8005643C: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x80056440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80056448: jr          $ra
    // 0x8005644C: nop

    return;
    // 0x8005644C: nop

;}
RECOMP_FUNC void func_80011A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011A78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80011A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011A84: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x80011A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011A8C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011A90: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80011A94: jal         0x8001B7B0
    // 0x80011A98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8001B7B0(rdram, ctx);
        goto after_0;
    // 0x80011A98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80011A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80011AA4: jr          $ra
    // 0x80011AA8: nop

    return;
    // 0x80011AA8: nop

;}
RECOMP_FUNC void func_804374A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804374A8: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
    // 0x804374AC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F6C) << 16);
    // 0x804374B0: lwc1        $f10, -0x77F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F6C));
    // 0x804374B4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x804374B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804374BC: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x804374C0: lw          $t6, 0x70($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X70);
    // 0x804374C4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804374C8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x804374CC: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x804374D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804374D4: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804374D8: nop

    // 0x804374DC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x804374E0: jr          $ra
    // 0x804374E4: add.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f12.fl;
    return;
    // 0x804374E4: add.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f12.fl;
;}
RECOMP_FUNC void func_8006A4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A4B4: bne         $a1, $zero, L_8006A4C4
    if (ctx->r5 != 0) {
        // 0x8006A4B8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8006A4C4;
    }
    // 0x8006A4B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006A4BC: b           L_8006A524
    // 0x8006A4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A524;
    // 0x8006A4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A4C4:
    // 0x8006A4C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A4C8: addiu       $a1, $zero, 0x20B
    ctx->r5 = ADD32(0, 0X20B);
    // 0x8006A4CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006A4D0: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8006A4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A4D8: beq         $t7, $zero, L_8006A4F4
    if (ctx->r15 == 0) {
        // 0x8006A4DC: nop
    
            goto L_8006A4F4;
    }
    // 0x8006A4DC: nop

    // 0x8006A4E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A4E4: jal         0x80071380
    // 0x8006A4E8: addiu       $a0, $a0, 0xFB0
    ctx->r4 = ADD32(ctx->r4, 0XFB0);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006A4E8: addiu       $a0, $a0, 0xFB0
    ctx->r4 = ADD32(ctx->r4, 0XFB0);
    after_0:
    // 0x8006A4EC: b           L_8006A524
    // 0x8006A4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A524;
    // 0x8006A4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A4F4:
    // 0x8006A4F4: jal         0x80069FE4
    // 0x8006A4F8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A4F8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x8006A4FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006A500: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A504: bne         $v0, $zero, L_8006A520
    if (ctx->r2 != 0) {
        // 0x8006A508: sw          $v0, 0x18($t8)
        MEM_W(0X18, ctx->r24) = ctx->r2;
            goto L_8006A520;
    }
    // 0x8006A508: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x8006A50C: addiu       $a0, $a0, 0xFC0
    ctx->r4 = ADD32(ctx->r4, 0XFC0);
    // 0x8006A510: jal         0x80071380
    // 0x8006A514: addiu       $a1, $zero, 0x216
    ctx->r5 = ADD32(0, 0X216);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8006A514: addiu       $a1, $zero, 0x216
    ctx->r5 = ADD32(0, 0X216);
    after_2:
    // 0x8006A518: b           L_8006A524
    // 0x8006A51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A524;
    // 0x8006A51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A520:
    // 0x8006A520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A524:
    // 0x8006A524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A52C: jr          $ra
    // 0x8006A530: nop

    return;
    // 0x8006A530: nop

;}
RECOMP_FUNC void func_80032564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003256C: lw          $a2, 0x164($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X164);
    // 0x80032570: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x80032574: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80032578: jal         0x800324C8
    // 0x8003257C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800324C8(rdram, ctx);
        goto after_0;
    // 0x8003257C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80032580: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80032584: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80032588: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003258C: lhu         $v0, 0x1C($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X1C);
    // 0x80032590: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x80032594: beq         $t9, $zero, L_800325C8
    if (ctx->r25 == 0) {
        // 0x80032598: andi        $t1, $v0, 0x100
        ctx->r9 = ctx->r2 & 0X100;
            goto L_800325C8;
    }
    // 0x80032598: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x8003259C: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x800325A0: addiu       $t0, $zero, 0x67
    ctx->r8 = ADD32(0, 0X67);
    // 0x800325A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800325A8: bne         $v0, $zero, L_800325B8
    if (ctx->r2 != 0) {
        // 0x800325AC: nop
    
            goto L_800325B8;
    }
    // 0x800325AC: nop

    // 0x800325B0: b           L_800325E8
    // 0x800325B4: sb          $t0, 0x18($a2)
    MEM_B(0X18, ctx->r6) = ctx->r8;
        goto L_800325E8;
    // 0x800325B4: sb          $t0, 0x18($a2)
    MEM_B(0X18, ctx->r6) = ctx->r8;
L_800325B8:
    // 0x800325B8: jalr        $v0
    // 0x800325BC: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800325BC: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_1:
    // 0x800325C0: b           L_800325EC
    // 0x800325C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800325EC;
    // 0x800325C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800325C8:
    // 0x800325C8: beq         $t1, $zero, L_800325E0
    if (ctx->r9 == 0) {
        // 0x800325CC: nop
    
            goto L_800325E0;
    }
    // 0x800325CC: nop

    // 0x800325D0: jal         0x8003E304
    // 0x800325D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8003E304(rdram, ctx);
        goto after_2;
    // 0x800325D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x800325D8: b           L_800325EC
    // 0x800325DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800325EC;
    // 0x800325DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800325E0:
    // 0x800325E0: jal         0x8003E240
    // 0x800325E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8003E240(rdram, ctx);
        goto after_3;
    // 0x800325E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_800325E8:
    // 0x800325E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800325EC:
    // 0x800325EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800325F0: jr          $ra
    // 0x800325F4: nop

    return;
    // 0x800325F4: nop

;}
RECOMP_FUNC void func_8006ECF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ECFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED00: jal         0x8006E7F0
    // 0x8006ED04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006E7F0(rdram, ctx);
        goto after_0;
    // 0x8006ED04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006ED08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006ED0C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8006ED10: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8006ED14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006ED18: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8006ED1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006ED20: jal         0x8006F070
    // 0x8006ED24: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    func_8006F070(rdram, ctx);
        goto after_1;
    // 0x8006ED24: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    after_1:
    // 0x8006ED28: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8006ED2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006ED30: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8006ED34: swc1        $f4, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f4.u32l;
    // 0x8006ED38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED40: jr          $ra
    // 0x8006ED44: nop

    return;
    // 0x8006ED44: nop

;}
RECOMP_FUNC void func_80743004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80743004: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80743008: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8074300C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80743010: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80743014: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80743018: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8074301C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80743020: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80743024: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80743028: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8074302C: jr          $ra
    // 0x80743030: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80743030: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
