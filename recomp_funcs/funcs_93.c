#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8002C3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C3B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002C3B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C3BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C3C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C3C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002C3C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002C3CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002C3D0: lw          $t6, 0xD0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD0);
    // 0x8002C3D4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8002C3D8: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8002C3DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002C3E0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002C3E4: nop

    // 0x8002C3E8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8002C3EC: lbu         $t9, 0x18($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X18);
    // 0x8002C3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C3F4: jal         0x8002BF0C
    // 0x8002C3F8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    func_8002BF0C(rdram, ctx);
        goto after_0;
    // 0x8002C3F8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    after_0:
    // 0x8002C3FC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C400: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002C404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002C40C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C410: lw          $t9, -0x18EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X18EC);
    // 0x8002C414: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8002C418: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C41C: jalr        $t9
    // 0x8002C420: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002C420: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8002C424: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8002C428: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002C42C: sb          $t0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r8;
    // 0x8002C430: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C434: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8002C438: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8002C43C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002C440: lbu         $t2, -0x1934($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1934);
    // 0x8002C444: addiu       $t3, $t3, -0x1924
    ctx->r11 = ADD32(ctx->r11, -0X1924);
    // 0x8002C448: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x8002C44C: sb          $t2, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r10;
    // 0x8002C450: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8002C454: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C45C: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
    // 0x8002C460: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    // 0x8002C464: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8002C468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002C46C: jal         0x8001DC5C
    // 0x8002C470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001DC5C(rdram, ctx);
        goto after_2;
    // 0x8002C470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8002C474: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002C478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C47C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002C480: jal         0x8002BB90
    // 0x8002C484: sw          $t5, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r13;
    func_8002BB90(rdram, ctx);
        goto after_3;
    // 0x8002C484: sw          $t5, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r13;
    after_3:
    // 0x8002C488: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002C48C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8002C490: addiu       $t7, $t7, -0x18F0
    ctx->r15 = ADD32(ctx->r15, -0X18F0);
    // 0x8002C494: bne         $t6, $t7, L_8002C4AC
    if (ctx->r14 != ctx->r15) {
        // 0x8002C498: nop
    
            goto L_8002C4AC;
    }
    // 0x8002C498: nop

    // 0x8002C49C: jal         0x8002AF3C
    // 0x8002C4A0: nop

    func_8002AF3C(rdram, ctx);
        goto after_4;
    // 0x8002C4A0: nop

    after_4:
    // 0x8002C4A4: b           L_8002C4B8
    // 0x8002C4A8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_8002C4B8;
    // 0x8002C4A8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8002C4AC:
    // 0x8002C4AC: jal         0x8002AF54
    // 0x8002C4B0: nop

    func_8002AF54(rdram, ctx);
        goto after_5;
    // 0x8002C4B0: nop

    after_5:
    // 0x8002C4B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8002C4B8:
    // 0x8002C4B8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002C4BC: addiu       $t9, $t9, -0x18FC
    ctx->r25 = ADD32(ctx->r25, -0X18FC);
    // 0x8002C4C0: bnel        $t8, $t9, L_8002C4D4
    if (ctx->r24 != ctx->r25) {
        // 0x8002C4C4: sb          $zero, 0x1AC($s0)
        MEM_B(0X1AC, ctx->r16) = 0;
            goto L_8002C4D4;
    }
    goto skip_0;
    // 0x8002C4C4: sb          $zero, 0x1AC($s0)
    MEM_B(0X1AC, ctx->r16) = 0;
    skip_0:
    // 0x8002C4C8: jal         0x8002AE54
    // 0x8002C4CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002AE54(rdram, ctx);
        goto after_6;
    // 0x8002C4CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8002C4D0: sb          $zero, 0x1AC($s0)
    MEM_B(0X1AC, ctx->r16) = 0;
L_8002C4D4:
    // 0x8002C4D4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8002C4D8: sb          $zero, 0x1B4($s0)
    MEM_B(0X1B4, ctx->r16) = 0;
    // 0x8002C4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C4E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002C4E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002C4E8: jr          $ra
    // 0x8002C4EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C4EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804C3B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3B08: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C3B0C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804C3B10: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C3B14: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(206, 0X1438) << 16);
    // 0x804C3B18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C3B1C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C3B20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C3B24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C3B28: lw          $t8, 0x3EB8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(206, 0X1438));
    // 0x804C3B2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C3B30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C3B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C3B38: jal         0x80048490
    // 0x804C3B3C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C3B3C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804C3B40: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C3B44: jal         0x80048378
    // 0x804C3B48: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804C3B48: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804C3B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C3B54: jr          $ra
    // 0x804C3B58: nop

    return;
    // 0x804C3B58: nop

;}
RECOMP_FUNC void func_80429C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429C3C: jr          $ra
    // 0x80429C40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80429C40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80045328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004532C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045330: lbu         $t6, 0x164($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X164);
    // 0x80045334: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80045338: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004533C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80045340: lw          $t9, 0x560($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X560);
    // 0x80045344: jalr        $t9
    // 0x80045348: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80045348: nop

    after_0:
    // 0x8004534C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045354: jr          $ra
    // 0x80045358: nop

    return;
    // 0x80045358: nop

;}
RECOMP_FUNC void func_805D1868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1868: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805D186C: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(468, 0X2A0) << 16);
    // 0x805D1870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1874: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x805D1878: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x805D187C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x805D1880: addiu       $t7, $t7, 0x19B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(468, 0X2A0));
    // 0x805D1884: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x805D1888: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805D188C: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x805D1890: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x805D1894: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x805D1898: lhu         $t0, 0xC($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0XC);
    // 0x805D189C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805D18A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805D18A4: bnel        $t0, $at, L_805D1960
    if (ctx->r8 != ctx->r1) {
        // 0x805D18A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D1960;
    }
    goto skip_0;
    // 0x805D18A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D18AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x805D18B0: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805D18B4: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x805D18B8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805D18BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D18C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805D18C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D18C8: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805D18CC: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x805D18D0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x805D18D4: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805D18D8: lwc1        $f10, 0x58($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X58);
    // 0x805D18DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805D18E0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x805D18E4: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x805D18E8: lwc1        $f4, 0x5C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x805D18EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805D18F0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x805D18F4: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805D18F8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x805D18FC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x805D1900: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805D1904: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x805D1908: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805D190C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x805D1910: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805D1914: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x805D1918: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x805D191C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x805D1920: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x805D1924: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x805D1928: lw          $t9, 0x10($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X10);
    // 0x805D192C: jalr        $t9
    // 0x805D1930: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805D1930: nop

    after_0:
    // 0x805D1934: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x805D1938: jal         0x805D17F4
    // 0x805D193C: addiu       $a1, $zero, 0x452E
    ctx->r5 = ADD32(0, 0X452E);
    func_805D17F4(rdram, ctx);
        goto after_1;
    // 0x805D193C: addiu       $a1, $zero, 0x452E
    ctx->r5 = ADD32(0, 0X452E);
    after_1:
    // 0x805D1940: jal         0x800447C8
    // 0x805D1944: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x805D1944: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x805D1948: jal         0x80067E68
    // 0x805D194C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x805D194C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x805D1950: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x805D1954: jal         0x80067818
    // 0x805D1958: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805D1958: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805D195C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D1960:
    // 0x805D1960: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x805D1964: jr          $ra
    // 0x805D1968: nop

    return;
    // 0x805D1968: nop

;}
RECOMP_FUNC void func_807B2470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B2470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B2474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B2478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B247C: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x807B2480: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B2484: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39A0) << 16);
    // 0x807B2488: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x807B248C: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x807B2490: lwc1        $f16, 0x34F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39A0));
    // 0x807B2494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B2498: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x807B249C: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x807B24A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x807B24A4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39A4) << 16);
    // 0x807B24A8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x807B24AC: lwc1        $f4, 0xA8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x807B24B0: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807B24B4: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x807B24B8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x807B24BC: nop

    // 0x807B24C0: bc1tl       L_807B24E8
    if (c1cs) {
        // 0x807B24C4: lwc1        $f12, 0x144($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X144);
            goto L_807B24E8;
    }
    goto skip_0;
    // 0x807B24C4: lwc1        $f12, 0x144($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X144);
    skip_0:
    // 0x807B24C8: lwc1        $f18, 0x34F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39A4));
    // 0x807B24CC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x807B24D0: nop

    // 0x807B24D4: bc1tl       L_807B24E8
    if (c1cs) {
        // 0x807B24D8: lwc1        $f12, 0x144($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X144);
            goto L_807B24E8;
    }
    goto skip_1;
    // 0x807B24D8: lwc1        $f12, 0x144($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X144);
    skip_1:
    // 0x807B24DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B24E0: nop

    // 0x807B24E4: lwc1        $f12, 0x144($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X144);
L_807B24E8:
    // 0x807B24E8: lwc1        $f6, 0x148($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X148);
    // 0x807B24EC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39A8) << 16);
    // 0x807B24F0: lwc1        $f18, 0x34F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39A8));
    // 0x807B24F4: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x807B24F8: nop

    // 0x807B24FC: bc1fl       L_807B26A4
    if (!c1cs) {
        // 0x807B2500: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807B26A4;
    }
    goto skip_2;
    // 0x807B2500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x807B2504: lwc1        $f8, 0x16C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x807B2508: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807B250C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807B2510: sub.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x807B2514: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x807B2518: nop

    // 0x807B251C: bc1fl       L_807B2530
    if (!c1cs) {
        // 0x807B2520: neg.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
            goto L_807B2530;
    }
    goto skip_3;
    // 0x807B2520: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    skip_3:
    // 0x807B2524: b           L_807B2544
    // 0x807B2528: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
        goto L_807B2544;
    // 0x807B2528: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x807B252C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
L_807B2530:
    // 0x807B2530: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x807B2534: nop

    // 0x807B2538: bc1fl       L_807B2548
    if (!c1cs) {
        // 0x807B253C: lwc1        $f12, 0xDC($a2)
        ctx->f12.u32l = MEM_W(ctx->r6, 0XDC);
            goto L_807B2548;
    }
    goto skip_4;
    // 0x807B253C: lwc1        $f12, 0xDC($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0XDC);
    skip_4:
    // 0x807B2540: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
L_807B2544:
    // 0x807B2544: lwc1        $f12, 0xDC($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0XDC);
L_807B2548:
    // 0x807B2548: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x807B254C: nop

    // 0x807B2550: bc1tl       L_807B2588
    if (c1cs) {
        // 0x807B2554: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_807B2588;
    }
    goto skip_5;
    // 0x807B2554: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x807B2558: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x807B255C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807B2560: bc1tl       L_807B2588
    if (c1cs) {
        // 0x807B2564: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_807B2588;
    }
    goto skip_6;
    // 0x807B2564: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x807B2568: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x807B256C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x807B2570: nop

    // 0x807B2574: bc1tl       L_807B2588
    if (c1cs) {
        // 0x807B2578: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_807B2588;
    }
    goto skip_7;
    // 0x807B2578: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x807B257C: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x807B2580: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x807B2584: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_807B2588:
    // 0x807B2588: swc1        $f6, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f6.u32l;
    // 0x807B258C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807B2590: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807B2594: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x807B2598: nop

    // 0x807B259C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B25A0: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x807B25A4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B25A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x807B25AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x807B25B0: bc1f        L_807B2648
    if (!c1cs) {
        // 0x807B25B4: nop
    
            goto L_807B2648;
    }
    // 0x807B25B4: nop

    // 0x807B25B8: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x807B25BC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x807B25C0: bnel        $t6, $at, L_807B25F8
    if (ctx->r14 != ctx->r1) {
        // 0x807B25C4: lw          $v0, 0x1F4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1F4);
            goto L_807B25F8;
    }
    goto skip_8;
    // 0x807B25C4: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    skip_8:
    // 0x807B25C8: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x807B25CC: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x807B25D0: jal         0x800481B4
    // 0x807B25D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_800481B4(rdram, ctx);
        goto after_0;
    // 0x807B25D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_0:
    // 0x807B25D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B25DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B25E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807B25E4: jal         0x807B2D04
    // 0x807B25E8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_807B2D04(rdram, ctx);
        goto after_1;
    // 0x807B25E8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_1:
    // 0x807B25EC: b           L_807B26A4
    // 0x807B25F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B26A4;
    // 0x807B25F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B25F4: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
L_807B25F8:
    // 0x807B25F8: swc1        $f12, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f12.u32l;
    // 0x807B25FC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39AC) << 16);
    // 0x807B2600: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x807B2604: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x807B2608: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x807B260C: lwc1        $f8, 0x34FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39AC));
    // 0x807B2610: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    // 0x807B2614: jal         0x80081E8C
    // 0x807B2618: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    fatan2(rdram, ctx);
        goto after_2;
    // 0x807B2618: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x807B261C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39B0) << 16);
    // 0x807B2620: lwc1        $f4, 0x3500($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39B0));
    // 0x807B2624: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x807B2628: jal         0x80066E88
    // 0x807B262C: nop

    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x807B262C: nop

    after_3:
    // 0x807B2630: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807B2634: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B2638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B263C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807B2640: b           L_807B26A4
    // 0x807B2644: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
        goto L_807B26A4;
    // 0x807B2644: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
L_807B2648:
    // 0x807B2648: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x807B264C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39B4) << 16);
    // 0x807B2650: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x807B2654: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x807B2658: lwc1        $f4, 0x3504($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39B4));
    // 0x807B265C: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x807B2660: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807B2664: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x807B2668: nop

    // 0x807B266C: bc1f        L_807B2698
    if (!c1cs) {
        // 0x807B2670: nop
    
            goto L_807B2698;
    }
    // 0x807B2670: nop

    // 0x807B2674: lwc1        $f2, 0xC8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC8);
    // 0x807B2678: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807B267C: nop

    // 0x807B2680: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x807B2684: nop

    // 0x807B2688: bc1fl       L_807B2698
    if (!c1cs) {
        // 0x807B268C: swc1        $f12, 0x40($a2)
        MEM_W(0X40, ctx->r6) = ctx->f12.u32l;
            goto L_807B2698;
    }
    goto skip_9;
    // 0x807B268C: swc1        $f12, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f12.u32l;
    skip_9:
    // 0x807B2690: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x807B2694: swc1        $f12, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f12.u32l;
L_807B2698:
    // 0x807B2698: b           L_807B26A4
    // 0x807B269C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807B26A4;
    // 0x807B269C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B26A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B26A4:
    // 0x807B26A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B26A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B26AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807B26B0: jr          $ra
    // 0x807B26B4: nop

    return;
    // 0x807B26B4: nop

;}
RECOMP_FUNC void func_80530AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530AFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530B04: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80530B08: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(339, 0X400) << 16);
    // 0x80530B0C: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x80530B10: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80530B14: addiu       $t6, $t6, 0xD20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(339, 0X400));
    // 0x80530B18: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80530B1C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80530B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80530B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80530B28: jal         0x80530C4C
    // 0x80530B2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80530C4C(rdram, ctx);
        goto after_0;
    // 0x80530B2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80530B30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530B34: jal         0x80045A34
    // 0x80530B38: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80530B38: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80530B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530B40: addiu       $at, $zero, 0x41E3
    ctx->r1 = ADD32(0, 0X41E3);
    // 0x80530B44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80530B48: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80530B4C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80530B50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80530B54: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80530B58: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80530B5C: beq         $v1, $at, L_80530B74
    if (ctx->r3 == ctx->r1) {
        // 0x80530B60: addiu       $at, $zero, 0x41E4
        ctx->r1 = ADD32(0, 0X41E4);
            goto L_80530B74;
    }
    // 0x80530B60: addiu       $at, $zero, 0x41E4
    ctx->r1 = ADD32(0, 0X41E4);
    // 0x80530B64: beql        $v1, $at, L_80530B90
    if (ctx->r3 == ctx->r1) {
        // 0x80530B68: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80530B90;
    }
    goto skip_0;
    // 0x80530B68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_0:
    // 0x80530B6C: b           L_80530BA4
    // 0x80530B70: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
        goto L_80530BA4;
    // 0x80530B70: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
L_80530B74:
    // 0x80530B74: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80530B78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80530B7C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80530B80: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80530B84: b           L_80530BA0
    // 0x80530B88: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_80530BA0;
    // 0x80530B88: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80530B8C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80530B90:
    // 0x80530B90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80530B94: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80530B98: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80530B9C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_80530BA0:
    // 0x80530BA0: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
L_80530BA4:
    // 0x80530BA4: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80530BA8: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x80530BAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80530BB0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80530BB4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80530BB8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80530BBC: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80530BC0: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80530BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530BCC: jr          $ra
    // 0x80530BD0: nop

    return;
    // 0x80530BD0: nop

;}
RECOMP_FUNC void func_80470DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470DE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80470DEC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80470DF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80470DF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80470DF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80470DFC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80470E00: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80470E04: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(149, 0X1210) << 16);
    // 0x80470E08: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80470E0C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80470E10: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80470E14: lw          $t1, 0xE20($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(149, 0X1210));
    // 0x80470E18: jr          $ra
    // 0x80470E1C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80470E1C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805D1D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1D84: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805D1D88: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805D1D8C: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(471, 0X238C) << 16);
    // 0x805D1D90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805D1D94: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805D1D98: lw          $t8, 0x3DBC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(471, 0X238C));
    // 0x805D1D9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805D1DA0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805D1DA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805D1DA8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805D1DAC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805D1DB0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805D1DB4: beql        $v1, $zero, L_805D1DEC
    if (ctx->r3 == 0) {
        // 0x805D1DB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D1DEC;
    }
    goto skip_0;
    // 0x805D1DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D1DBC: jalr        $v1
    // 0x805D1DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805D1DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D1DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D1DC8: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x805D1DCC: lw          $t2, 0x15C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X15C);
    // 0x805D1DD0: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x805D1DD4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x805D1DD8: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x805D1DDC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x805D1DE0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x805D1DE4: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x805D1DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D1DEC:
    // 0x805D1DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1DF0: jr          $ra
    // 0x805D1DF4: nop

    return;
    // 0x805D1DF4: nop

;}
RECOMP_FUNC void func_806AB470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB470: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x806AB474: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x806AB478: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x806AB47C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806AB480: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806AB484: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806AB488: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806AB48C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806AB490: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806AB494: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806AB498: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806AB49C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806AB4A0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806AB4A4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806AB4A8: lui         $s7, 0x459E
    ctx->r23 = S32(0X459E << 16);
    // 0x806AB4AC: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(592, 0X3000) << 16);
    // 0x806AB4B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806AB4B4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x806AB4B8: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AB4BC: lwc1        $f22, -0x2420($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(592, 0X3000));
    // 0x806AB4C0: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x806AB4C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806AB4C8: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x806AB4CC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
L_806AB4D0:
    // 0x806AB4D0: jal         0x80047090
    // 0x806AB4D4: addiu       $a0, $zero, 0x459E
    ctx->r4 = ADD32(0, 0X459E);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806AB4D4: addiu       $a0, $zero, 0x459E
    ctx->r4 = ADD32(0, 0X459E);
    after_0:
    // 0x806AB4D8: bne         $s6, $v0, L_806AB4E8
    if (ctx->r22 != ctx->r2) {
        // 0x806AB4DC: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_806AB4E8;
    }
    // 0x806AB4DC: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x806AB4E0: b           L_806AB60C
    // 0x806AB4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB60C;
    // 0x806AB4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB4E8:
    // 0x806AB4E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806AB4EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806AB4F0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806AB4F4: jal         0x8004613C
    // 0x806AB4F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806AB4F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x806AB4FC: beq         $v0, $zero, L_806AB540
    if (ctx->r2 == 0) {
        // 0x806AB500: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806AB540;
    }
    // 0x806AB500: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806AB504: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x806AB508: andi        $t7, $s3, 0x3FF
    ctx->r15 = ctx->r19 & 0X3FF;
    // 0x806AB50C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x806AB510: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806AB514: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806AB518: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x806AB51C: addu        $s1, $s4, $t1
    ctx->r17 = ADD32(ctx->r20, ctx->r9);
    // 0x806AB520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806AB524: jal         0x80047F9C
    // 0x806AB528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806AB528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806AB52C: sb          $fp, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r30;
    // 0x806AB530: jal         0x806AB424
    // 0x806AB534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AB424(rdram, ctx);
        goto after_3;
    // 0x806AB534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AB538: b           L_806AB548
    // 0x806AB53C: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
        goto L_806AB548;
    // 0x806AB53C: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
L_806AB540:
    // 0x806AB540: b           L_806AB60C
    // 0x806AB544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB60C;
    // 0x806AB544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB548:
    // 0x806AB548: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806AB54C: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x806AB550: bne         $at, $zero, L_806AB4D0
    if (ctx->r1 != 0) {
        // 0x806AB554: sw          $s0, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r16;
            goto L_806AB4D0;
    }
    // 0x806AB554: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
    // 0x806AB558: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(592, 0X3004) << 16);
    // 0x806AB55C: lui         $s7, 0x459D
    ctx->r23 = S32(0X459D << 16);
    // 0x806AB560: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x806AB564: lwc1        $f24, -0x241C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(592, 0X3004));
    // 0x806AB568: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_806AB56C:
    // 0x806AB56C: jal         0x80047090
    // 0x806AB570: addiu       $a0, $zero, 0x459D
    ctx->r4 = ADD32(0, 0X459D);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x806AB570: addiu       $a0, $zero, 0x459D
    ctx->r4 = ADD32(0, 0X459D);
    after_4:
    // 0x806AB574: bne         $s6, $v0, L_806AB584
    if (ctx->r22 != ctx->r2) {
        // 0x806AB578: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_806AB584;
    }
    // 0x806AB578: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x806AB57C: b           L_806AB60C
    // 0x806AB580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB60C;
    // 0x806AB580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB584:
    // 0x806AB584: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806AB588: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806AB58C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806AB590: jal         0x8004613C
    // 0x806AB594: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x806AB594: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x806AB598: beq         $v0, $zero, L_806AB5F8
    if (ctx->r2 == 0) {
        // 0x806AB59C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806AB5F8;
    }
    // 0x806AB59C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806AB5A0: lhu         $t4, 0xE($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XE);
    // 0x806AB5A4: andi        $t3, $s3, 0x3FF
    ctx->r11 = ctx->r19 & 0X3FF;
    // 0x806AB5A8: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x806AB5AC: andi        $t5, $t4, 0xFC00
    ctx->r13 = ctx->r12 & 0XFC00;
    // 0x806AB5B0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x806AB5B4: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x806AB5B8: addu        $s1, $s4, $t8
    ctx->r17 = ADD32(ctx->r20, ctx->r24);
    // 0x806AB5BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806AB5C0: jal         0x80047F9C
    // 0x806AB5C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806AB5C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x806AB5C8: sb          $fp, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r30;
    // 0x806AB5CC: jal         0x806AB424
    // 0x806AB5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AB424(rdram, ctx);
        goto after_7;
    // 0x806AB5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806AB5D4: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x806AB5D8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x806AB5DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x806AB5E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806AB5E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AB5E8: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x806AB5EC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x806AB5F0: b           L_806AB600
    // 0x806AB5F4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_806AB600;
    // 0x806AB5F4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_806AB5F8:
    // 0x806AB5F8: b           L_806AB60C
    // 0x806AB5FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AB60C;
    // 0x806AB5FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB600:
    // 0x806AB600: bne         $v0, $at, L_806AB56C
    if (ctx->r2 != ctx->r1) {
        // 0x806AB604: sw          $s0, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->r16;
            goto L_806AB56C;
    }
    // 0x806AB604: sw          $s0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r16;
    // 0x806AB608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806AB60C:
    // 0x806AB60C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x806AB610: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806AB614: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806AB618: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806AB61C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806AB620: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806AB624: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806AB628: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806AB62C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806AB630: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806AB634: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806AB638: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x806AB63C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x806AB640: jr          $ra
    // 0x806AB644: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x806AB644: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8003D4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D4E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D4E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D4EC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003D4F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8003D4F4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003D4F8: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    // 0x8003D4FC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003D500: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x8003D504: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003D508: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003D50C: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x8003D510: lwc1        $f10, 0x70($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8003D514: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x8003D518: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003D51C: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x8003D520: jal         0x8003D090
    // 0x8003D524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003D090(rdram, ctx);
        goto after_0;
    // 0x8003D524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003D528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003D52C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D530: nop

    // 0x8003D534: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8003D538: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x8003D53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D544: jr          $ra
    // 0x8003D548: nop

    return;
    // 0x8003D548: nop

;}
RECOMP_FUNC void func_804C2114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C2118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C211C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C2120: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C2124: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C2128: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C212C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x804C2130: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C2134: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x804C2138: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C213C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C2140: jal         0x80066E88
    // 0x804C2144: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804C2144: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x804C2148: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804C214C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x804C2150: jal         0x80066DE4
    // 0x804C2154: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804C2154: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x804C2158: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x804C215C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804C2160: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x804C2164: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x804C2168: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x804C216C: lw          $t6, 0x59C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X59C);
    // 0x804C2170: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804C2174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C2178: lwc1        $f18, 0x3C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x804C217C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804C2180: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804C2184: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C2188: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x804C218C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C2190: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C2194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C2198: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(203, 0X114C) << 16);
    // 0x804C219C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804C21A0: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x804C21A4: lw          $t7, 0x59C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X59C);
    // 0x804C21A8: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804C21AC: lwc1        $f8, 0x40($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X40);
    // 0x804C21B0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x804C21B4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804C21B8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x804C21BC: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C21C0: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x804C21C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804C21C8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x804C21CC: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x804C21D0: lwc1        $f16, 0x28BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(203, 0X114C));
    // 0x804C21D4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C21D8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804C21DC: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x804C21E0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x804C21E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C21E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C21EC: jr          $ra
    // 0x804C21F0: nop

    return;
    // 0x804C21F0: nop

;}
RECOMP_FUNC void func_807AD1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD1CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AD1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AD1D4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807AD1D8: slti        $at, $v0, 0xB4
    ctx->r1 = SIGNED(ctx->r2) < 0XB4 ? 1 : 0;
    // 0x807AD1DC: beq         $at, $zero, L_807AD2D4
    if (ctx->r1 == 0) {
        // 0x807AD1E0: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_807AD2D4;
    }
    // 0x807AD1E0: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x807AD1E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807AD1E8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807AD1EC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26BC) << 16);
    // 0x807AD1F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807AD1F4: lwc1        $f8, -0x12E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26BC));
    // 0x807AD1F8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x807AD1FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AD200: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x807AD204: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807AD208: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807AD20C: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x807AD210: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x807AD214: nop

    // 0x807AD218: bc1fl       L_807AD2AC
    if (!c1cs) {
        // 0x807AD21C: lw          $t1, 0x16C($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X16C);
            goto L_807AD2AC;
    }
    goto skip_0;
    // 0x807AD21C: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    skip_0:
    // 0x807AD220: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x807AD224: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x807AD228: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x807AD22C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x807AD230: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x807AD234: nop

    // 0x807AD238: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x807AD23C: beql        $t9, $zero, L_807AD28C
    if (ctx->r25 == 0) {
        // 0x807AD240: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_807AD28C;
    }
    goto skip_1;
    // 0x807AD240: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x807AD244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AD248: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807AD24C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x807AD250: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x807AD254: nop

    // 0x807AD258: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x807AD25C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x807AD260: nop

    // 0x807AD264: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x807AD268: bne         $t9, $zero, L_807AD280
    if (ctx->r25 != 0) {
        // 0x807AD26C: nop
    
            goto L_807AD280;
    }
    // 0x807AD26C: nop

    // 0x807AD270: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x807AD274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807AD278: b           L_807AD298
    // 0x807AD27C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_807AD298;
    // 0x807AD27C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_807AD280:
    // 0x807AD280: b           L_807AD298
    // 0x807AD284: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_807AD298;
    // 0x807AD284: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x807AD288: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_807AD28C:
    // 0x807AD28C: nop

    // 0x807AD290: bltz        $t9, L_807AD280
    if (SIGNED(ctx->r25) < 0) {
        // 0x807AD294: nop
    
            goto L_807AD280;
    }
    // 0x807AD294: nop

L_807AD298:
    // 0x807AD298: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x807AD29C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x807AD2A0: b           L_807AD2B0
    // 0x807AD2A4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
        goto L_807AD2B0;
    // 0x807AD2A4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x807AD2A8: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
L_807AD2AC:
    // 0x807AD2AC: sb          $zero, 0x10($t1)
    MEM_B(0X10, ctx->r9) = 0;
L_807AD2B0:
    // 0x807AD2B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807AD2B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AD2B8: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807AD2BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AD2C0: jal         0x800659EC
    // 0x807AD2C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x807AD2C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x807AD2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AD2CC: b           L_807AD2DC
    // 0x807AD2D0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
        goto L_807AD2DC;
    // 0x807AD2D0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_807AD2D4:
    // 0x807AD2D4: jal         0x80044658
    // 0x807AD2D8: nop

    func_80044658(rdram, ctx);
        goto after_1;
    // 0x807AD2D8: nop

    after_1:
L_807AD2DC:
    // 0x807AD2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AD2E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AD2E4: jr          $ra
    // 0x807AD2E8: nop

    return;
    // 0x807AD2E8: nop

;}
RECOMP_FUNC void func_80022F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022F64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022F68: lwc1        $f4, -0x348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X348);
    // 0x80022F6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022F70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80022F74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022F78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022F7C: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80022F80: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022F84: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022F88: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x80022F8C: lwc1        $f8, -0x344($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X344);
    // 0x80022F90: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80022F94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022F98: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80022F9C: jr          $ra
    // 0x80022FA0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80022FA0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8042C194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042C198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042C19C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042C1A0: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x8042C1A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8042C1A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8042C1AC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8042C1B0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x8042C1B4: jal         0x80067D5C
    // 0x8042C1B8: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8042C1B8: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    after_0:
    // 0x8042C1BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C1C0: jal         0x80067818
    // 0x8042C1C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8042C1C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8042C1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042C1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042C1D0: jr          $ra
    // 0x8042C1D4: nop

    return;
    // 0x8042C1D4: nop

;}
RECOMP_FUNC void func_805D2764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D276C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D2770: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D2774: jal         0x805D264C
    // 0x805D2778: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805D264C(rdram, ctx);
        goto after_0;
    // 0x805D2778: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805D277C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2780: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X254C) << 16);
    // 0x805D2784: lwc1        $f6, 0x3F7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X254C));
    // 0x805D2788: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805D278C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805D2790: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x805D2794: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805D2798: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(471, 0XD14) << 16);
    // 0x805D279C: addiu       $t7, $t7, 0x2744
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(471, 0XD14));
    // 0x805D27A0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805D27A4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D27A8: bnel        $t6, $at, L_805D27B8
    if (ctx->r14 != ctx->r1) {
        // 0x805D27AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D27B8;
    }
    goto skip_0;
    // 0x805D27AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D27B0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x805D27B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D27B8:
    // 0x805D27B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D27BC: jr          $ra
    // 0x805D27C0: nop

    return;
    // 0x805D27C0: nop

;}
RECOMP_FUNC void func_804CC7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC7F4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804CC7F8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804CC7FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804CC800: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804CC804: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804CC808: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804CC80C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804CC810: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804CC814: lui         $t1, 0x804D
    ctx->r9 = S32(RELOC_HI16(237, 0X1C70) << 16);
    // 0x804CC818: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804CC81C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CC820: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804CC824: lw          $t1, -0x1F20($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(237, 0X1C70));
    // 0x804CC828: jr          $ra
    // 0x804CC82C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804CC82C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8044194C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044194C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80441950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441958: jal         0x8004700C
    // 0x8044195C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044195C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80441960: beq         $v0, $zero, L_80441A24
    if (ctx->r2 == 0) {
        // 0x80441964: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_80441A24;
    }
    // 0x80441964: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80441968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044196C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80441970: jal         0x8043FBA8
    // 0x80441974: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8043FBA8(rdram, ctx);
        goto after_1;
    // 0x80441974: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80441978: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8044197C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80441980: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80441984: lwc1        $f4, 0x1C84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C84);
    // 0x80441988: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EDC) << 16);
    // 0x8044198C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441990: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80441994: swc1        $f8, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f8.u32l;
    // 0x80441998: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8044199C: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x804419A0: lwc1        $f10, 0x3DDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EDC));
    // 0x804419A4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x804419A8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804419AC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x804419B0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x804419B4: lwc1        $f8, 0x1C84($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C84);
    // 0x804419B8: lwc1        $f16, 0x40($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X40);
    // 0x804419BC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x804419C0: jal         0x8043F33C
    // 0x804419C4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    func_8043F33C(rdram, ctx);
        goto after_2;
    // 0x804419C4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x804419C8: jal         0x8043FDF0
    // 0x804419CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_3;
    // 0x804419CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804419D0: jal         0x8043F150
    // 0x804419D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_4;
    // 0x804419D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804419D8: jal         0x8044045C
    // 0x804419DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_5;
    // 0x804419DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804419E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804419E4: jal         0x8043EF80
    // 0x804419E8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_8043EF80(rdram, ctx);
        goto after_6;
    // 0x804419E8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_6:
    // 0x804419EC: jal         0x8043F360
    // 0x804419F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_7;
    // 0x804419F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804419F4: beq         $v0, $zero, L_80441A1C
    if (ctx->r2 == 0) {
        // 0x804419F8: nop
    
            goto L_80441A1C;
    }
    // 0x804419F8: nop

    // 0x804419FC: jal         0x80440950
    // 0x80441A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_8;
    // 0x80441A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80441A04: jal         0x8043FA00
    // 0x80441A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FA00(rdram, ctx);
        goto after_9;
    // 0x80441A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80441A0C: bnel        $v0, $zero, L_80441A28
    if (ctx->r2 != 0) {
        // 0x80441A10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80441A28;
    }
    goto skip_0;
    // 0x80441A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80441A14: b           L_80441A28
    // 0x80441A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441A28;
    // 0x80441A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441A1C:
    // 0x80441A1C: jal         0x8043F93C
    // 0x80441A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_10;
    // 0x80441A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80441A24:
    // 0x80441A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441A28:
    // 0x80441A28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441A2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80441A30: jr          $ra
    // 0x80441A34: nop

    return;
    // 0x80441A34: nop

;}
RECOMP_FUNC void func_80799880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80799884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799888: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8079988C: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(826, 0X2528) << 16);
    // 0x80799890: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80799894: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80799898: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8079989C: addiu       $t6, $t6, -0x4FB8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(826, 0X2528));
    // 0x807998A0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807998A4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807998A8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807998AC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807998B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807998B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807998B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807998BC: jal         0x80799944
    // 0x807998C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80799944(rdram, ctx);
        goto after_0;
    // 0x807998C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807998C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807998C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807998CC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x807998D0: beql        $v0, $zero, L_80799938
    if (ctx->r2 == 0) {
        // 0x807998D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80799938;
    }
    goto skip_0;
    // 0x807998D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807998D8: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807998DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807998E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807998E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807998E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807998EC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x807998F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807998F4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2674) << 16);
    // 0x807998F8: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x807998FC: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80799900: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80799904: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80799908: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8079990C: lwc1        $f8, 0x8C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80799910: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x80799914: lwc1        $f10, -0x4E6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2674));
    // 0x80799918: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2678) << 16);
    // 0x8079991C: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x80799920: lwc1        $f16, -0x4E68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2678));
    // 0x80799924: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80799928: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8079992C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x80799930: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    // 0x80799934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799938:
    // 0x80799938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079993C: jr          $ra
    // 0x80799940: nop

    return;
    // 0x80799940: nop

;}
RECOMP_FUNC void Math_FAtanContFracF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081D6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081D70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80081D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081D78: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80081D7C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80081D80: bc1fl       L_80081D94
    if (!c1cs) {
        // 0x80081D84: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80081D94;
    }
    goto skip_0;
    // 0x80081D84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80081D88: b           L_80081DB4
    // 0x80081D8C: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
        goto L_80081DB4;
    // 0x80081D8C: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80081D90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80081D94:
    // 0x80081D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081D98: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80081D9C: nop

    // 0x80081DA0: bc1f        L_80081DB4
    if (!c1cs) {
        // 0x80081DA4: nop
    
            goto L_80081DB4;
    }
    // 0x80081DA4: nop

    // 0x80081DA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80081DAC: b           L_80081DB4
    // 0x80081DB0: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
        goto L_80081DB4;
    // 0x80081DB0: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
L_80081DB4:
    // 0x80081DB4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80081DB8: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80081DBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80081DC0: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
L_80081DC4:
    // 0x80081DC4: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80081DC8: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80081DCC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80081DD0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081DD4: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80081DD8: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80081DDC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80081DE0: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80081DE4: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80081DE8: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80081DEC: div.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80081DF0: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80081DF4: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80081DF8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80081DFC: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80081E00: add.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80081E04: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80081E08: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80081E0C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80081E10: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80081E14: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80081E18: add.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80081E1C: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80081E20: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80081E24: div.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80081E28: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80081E2C: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80081E30: add.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80081E34: bne         $v1, $zero, L_80081DC4
    if (ctx->r3 != 0) {
        // 0x80081E38: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_80081DC4;
    }
    // 0x80081E38: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80081E3C: blez        $v0, L_80081E5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80081E40: nop
    
            goto L_80081E5C;
    }
    // 0x80081E40: nop

    // 0x80081E44: add.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80081E48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081E4C: lwc1        $f6, 0x3180($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3180);
    // 0x80081E50: div.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80081E54: jr          $ra
    // 0x80081E58: sub.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f18.fl;
    return;
    // 0x80081E58: sub.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f18.fl;
L_80081E5C:
    // 0x80081E5C: bgezl       $v0, L_80081E80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80081E60: add.s       $f6, $f16, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
            goto L_80081E80;
    }
    goto skip_1;
    // 0x80081E60: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    skip_1:
    // 0x80081E64: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80081E68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081E6C: lwc1        $f8, 0x3184($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3184);
    // 0x80081E70: div.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80081E74: jr          $ra
    // 0x80081E78: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    return;
    // 0x80081E78: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80081E7C: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
L_80081E80:
    // 0x80081E80: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80081E84: jr          $ra
    // 0x80081E88: nop

    return;
    // 0x80081E88: nop

;}
RECOMP_FUNC void func_80067930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006793C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067940: jal         0x800677CC
    // 0x80067944: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    func_800677CC(rdram, ctx);
        goto after_0;
    // 0x80067944: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_0:
    // 0x80067948: bne         $v0, $zero, L_80067958
    if (ctx->r2 != 0) {
        // 0x8006794C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80067958;
    }
    // 0x8006794C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80067950: b           L_80067960
    // 0x80067954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80067960;
    // 0x80067954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80067958:
    // 0x80067958: jal         0x80011928
    // 0x8006795C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    func_80011928(rdram, ctx);
        goto after_1;
    // 0x8006795C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_1:
L_80067960:
    // 0x80067960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067968: jr          $ra
    // 0x8006796C: nop

    return;
    // 0x8006796C: nop

;}
RECOMP_FUNC void func_8064A468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A470: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8064A474: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8064A478: addiu       $at, $zero, 0x4542
    ctx->r1 = ADD32(0, 0X4542);
    // 0x8064A47C: beq         $v0, $at, L_8064A498
    if (ctx->r2 == ctx->r1) {
        // 0x8064A480: lw          $v1, 0x88($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X88);
            goto L_8064A498;
    }
    // 0x8064A480: lw          $v1, 0x88($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X88);
    // 0x8064A484: addiu       $at, $zero, 0x4543
    ctx->r1 = ADD32(0, 0X4543);
    // 0x8064A488: beq         $v0, $at, L_8064A498
    if (ctx->r2 == ctx->r1) {
        // 0x8064A48C: addiu       $at, $zero, 0x4544
        ctx->r1 = ADD32(0, 0X4544);
            goto L_8064A498;
    }
    // 0x8064A48C: addiu       $at, $zero, 0x4544
    ctx->r1 = ADD32(0, 0X4544);
    // 0x8064A490: bnel        $v0, $at, L_8064A4A4
    if (ctx->r2 != ctx->r1) {
        // 0x8064A494: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A4A4;
    }
    goto skip_0;
    // 0x8064A494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8064A498:
    // 0x8064A498: jal         0x8004590C
    // 0x8064A49C: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8064A49C: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    after_0:
    // 0x8064A4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A4A4:
    // 0x8064A4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A4A8: jr          $ra
    // 0x8064A4AC: nop

    return;
    // 0x8064A4AC: nop

;}
RECOMP_FUNC void func_805213C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805213C0: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(306, 0X84) << 16);
    // 0x805213C4: addiu       $v0, $v0, 0x1444
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(306, 0X84));
    // 0x805213C8: jr          $ra
    // 0x805213CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805213CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80445A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445A3C: jal         0x800677F8
    // 0x80445A40: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445A40: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_0:
    // 0x80445A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445A4C: jr          $ra
    // 0x80445A50: nop

    return;
    // 0x80445A50: nop

;}
RECOMP_FUNC void func_8051787C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051787C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517884: jal         0x80517590
    // 0x80517888: nop

    func_80517590(rdram, ctx);
        goto after_0;
    // 0x80517888: nop

    after_0:
    // 0x8051788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517894: jr          $ra
    // 0x80517898: nop

    return;
    // 0x80517898: nop

;}
RECOMP_FUNC void func_8079EC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EC38: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC3C: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x8079EC40: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8079EC44: sb          $zero, 0xD($t6)
    MEM_B(0XD, ctx->r14) = 0;
    // 0x8079EC48: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC4C: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x8079EC50: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC54: jr          $ra
    // 0x8079EC58: sb          $t9, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r25;
    return;
    // 0x8079EC58: sb          $t9, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_80527370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527378: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052737C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6174) << 16);
    // 0x80527380: lwc1        $f6, -0x3F8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6174));
    // 0x80527384: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527388: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8052738C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6178) << 16);
    // 0x80527390: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80527394: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80527398: nop

    // 0x8052739C: bc1tl       L_80527404
    if (c1cs) {
        // 0x805273A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527404;
    }
    goto skip_0;
    // 0x805273A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x805273A4: lwc1        $f8, -0x3F88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6178));
    // 0x805273A8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805273AC: nop

    // 0x805273B0: bc1tl       L_80527404
    if (c1cs) {
        // 0x805273B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527404;
    }
    goto skip_1;
    // 0x805273B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x805273B8: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x805273BC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x805273C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805273C4: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x805273C8: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x805273CC: bgez        $v0, L_805273E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805273D0: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_805273E4;
    }
    // 0x805273D0: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x805273D4: jal         0x80526C4C
    // 0x805273D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80526C4C(rdram, ctx);
        goto after_0;
    // 0x805273D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805273DC: b           L_80527418
    // 0x805273E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527418;
    // 0x805273E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805273E4:
    // 0x805273E4: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x805273E8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805273EC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x805273F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805273F4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805273F8: b           L_80527414
    // 0x805273FC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527414;
    // 0x805273FC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527400: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80527404:
    // 0x80527404: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80527408: nop

    // 0x8052740C: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80527410: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80527414:
    // 0x80527414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527418:
    // 0x80527418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052741C: jr          $ra
    // 0x80527420: nop

    return;
    // 0x80527420: nop

;}
RECOMP_FUNC void func_80465268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046526C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465270: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80465274: jal         0x80045A34
    // 0x80465278: addiu       $a1, $zero, 0x1F28
    ctx->r5 = ADD32(0, 0X1F28);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80465278: addiu       $a1, $zero, 0x1F28
    ctx->r5 = ADD32(0, 0X1F28);
    after_0:
    // 0x8046527C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80465280: beq         $v0, $zero, L_80465298
    if (ctx->r2 == 0) {
        // 0x80465284: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80465298;
    }
    // 0x80465284: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80465288: jal         0x8046523C
    // 0x8046528C: nop

    func_8046523C(rdram, ctx);
        goto after_1;
    // 0x8046528C: nop

    after_1:
    // 0x80465290: jal         0x80465058
    // 0x80465294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80465058(rdram, ctx);
        goto after_2;
    // 0x80465294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80465298:
    // 0x80465298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046529C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804652A0: jr          $ra
    // 0x804652A4: nop

    return;
    // 0x804652A4: nop

;}
RECOMP_FUNC void func_80446C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446C80: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446C84: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80446C88: jr          $ra
    // 0x80446C8C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    return;
    // 0x80446C8C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_806650A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806650A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806650AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806650B0: jal         0x8004700C
    // 0x806650B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806650B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806650B8: beq         $v0, $zero, L_80665100
    if (ctx->r2 == 0) {
        // 0x806650BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80665100;
    }
    // 0x806650BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806650C0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806650C4: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806650C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806650CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806650D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806650D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806650D8: nop

    // 0x806650DC: bc1fl       L_806650F0
    if (!c1cs) {
        // 0x806650E0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_806650F0;
    }
    goto skip_0;
    // 0x806650E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x806650E4: b           L_80665100
    // 0x806650E8: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
        goto L_80665100;
    // 0x806650E8: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x806650EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_806650F0:
    // 0x806650F0: nop

    // 0x806650F4: bc1fl       L_80665104
    if (!c1cs) {
        // 0x806650F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80665104;
    }
    goto skip_1;
    // 0x806650F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806650FC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_80665100:
    // 0x80665100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80665104:
    // 0x80665104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80665108: jr          $ra
    // 0x8066510C: nop

    return;
    // 0x8066510C: nop

;}
RECOMP_FUNC void func_8005B270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B270: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005B274: lwc1        $f4, 0xC80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC80);
    // 0x8005B278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B27C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B280: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8005B284: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8005B288: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005B28C: bc1tl       L_8005B2B8
    if (c1cs) {
        // 0x8005B290: lui         $at, 0x4480
        ctx->r1 = S32(0X4480 << 16);
            goto L_8005B2B8;
    }
    goto skip_0;
    // 0x8005B290: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    skip_0:
    // 0x8005B294: lwc1        $f6, 0xC84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC84);
    // 0x8005B298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005B29C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8005B2A0: nop

    // 0x8005B2A4: bc1tl       L_8005B2B8
    if (c1cs) {
        // 0x8005B2A8: lui         $at, 0x4480
        ctx->r1 = S32(0X4480 << 16);
            goto L_8005B2B8;
    }
    goto skip_1;
    // 0x8005B2A8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    skip_1:
    // 0x8005B2AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005B2B0: nop

    // 0x8005B2B4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
L_8005B2B8:
    // 0x8005B2B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005B2BC: jal         0x80081FE0
    // 0x8005B2C0: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x8005B2C0: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    after_0:
    // 0x8005B2C4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005B2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B2D0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005B2D4: jr          $ra
    // 0x8005B2D8: nop

    return;
    // 0x8005B2D8: nop

;}
RECOMP_FUNC void func_804C9658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9658: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C965C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C9660: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x804C9664: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C9668: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C966C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x804C9670: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804C9674: andi        $t7, $t6, 0xF000
    ctx->r15 = ctx->r14 & 0XF000;
    // 0x804C9678: beq         $t7, $zero, L_804C9698
    if (ctx->r15 == 0) {
        // 0x804C967C: sub.s       $f12, $f2, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_804C9698;
    }
    // 0x804C967C: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x804C9680: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C9684: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x804C9688: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x804C968C: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x804C9690: b           L_804C970C
    // 0x804C9694: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
        goto L_804C970C;
    // 0x804C9694: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_804C9698:
    // 0x804C9698: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C969C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x804C96A0: jal         0x80065954
    // 0x804C96A4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x804C96A4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804C96A8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7E8) << 16);
    // 0x804C96AC: lwc1        $f8, -0x64D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7E8));
    // 0x804C96B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C96B4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804C96B8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x804C96BC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804C96C0: bc1fl       L_804C96E0
    if (!c1cs) {
        // 0x804C96C4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_804C96E0;
    }
    goto skip_0;
    // 0x804C96C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x804C96C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C96CC: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x804C96D0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x804C96D4: b           L_804C970C
    // 0x804C96D8: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
        goto L_804C970C;
    // 0x804C96D8: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x804C96DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_804C96E0:
    // 0x804C96E0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7F0) << 16);
    // 0x804C96E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x804C96E8: nop

    // 0x804C96EC: bc1f        L_804C9704
    if (!c1cs) {
        // 0x804C96F0: nop
    
            goto L_804C9704;
    }
    // 0x804C96F0: nop

    // 0x804C96F4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7EC) << 16);
    // 0x804C96F8: lwc1        $f10, -0x64D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7EC));
    // 0x804C96FC: b           L_804C970C
    // 0x804C9700: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
        goto L_804C970C;
    // 0x804C9700: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
L_804C9704:
    // 0x804C9704: lwc1        $f16, -0x64D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7F0));
    // 0x804C9708: swc1        $f16, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f16.u32l;
L_804C970C:
    // 0x804C970C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C9710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C9714: jr          $ra
    // 0x804C9718: nop

    return;
    // 0x804C9718: nop

;}
RECOMP_FUNC void func_80424310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424318: jal         0x804241A4
    // 0x8042431C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804241A4(rdram, ctx);
        goto after_0;
    // 0x8042431C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424320: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80424324: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80424328: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042432C: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80424330: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80424334: nop

    // 0x80424338: bc1fl       L_80424384
    if (!c1cs) {
        // 0x8042433C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80424384;
    }
    goto skip_0;
    // 0x8042433C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x80424340: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80424344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042434C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80424350: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424354: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80424358: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042435C: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80424360: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80424364: nop

    // 0x80424368: bc1fl       L_804243E0
    if (!c1cs) {
        // 0x8042436C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804243E0;
    }
    goto skip_1;
    // 0x8042436C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80424370: jal         0x80424550
    // 0x80424374: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    func_80424550(rdram, ctx);
        goto after_1;
    // 0x80424374: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    after_1:
    // 0x80424378: b           L_804243E0
    // 0x8042437C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804243E0;
    // 0x8042437C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80424380: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80424384:
    // 0x80424384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042438C: bc1f        L_804243D4
    if (!c1cs) {
        // 0x80424390: nop
    
            goto L_804243D4;
    }
    // 0x80424390: nop

    // 0x80424394: lwc1        $f10, 0xEC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80424398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042439C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804243A0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x804243A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804243A8: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x804243AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804243B0: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804243B4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804243B8: nop

    // 0x804243BC: bc1fl       L_804243E0
    if (!c1cs) {
        // 0x804243C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804243E0;
    }
    goto skip_2;
    // 0x804243C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804243C4: jal         0x80424550
    // 0x804243C8: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    func_80424550(rdram, ctx);
        goto after_2;
    // 0x804243C8: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    after_2:
    // 0x804243CC: b           L_804243E0
    // 0x804243D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804243E0;
    // 0x804243D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804243D4:
    // 0x804243D4: jal         0x80424550
    // 0x804243D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80424550(rdram, ctx);
        goto after_3;
    // 0x804243D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804243DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804243E0:
    // 0x804243E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804243E4: jr          $ra
    // 0x804243E8: nop

    return;
    // 0x804243E8: nop

;}
RECOMP_FUNC void func_804CAC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAC44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CAC48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAC4C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804CAC50: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804CAC54: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804CAC58: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(231, 0X1290) << 16);
    // 0x804CAC5C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804CAC60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804CAC64: addiu       $t7, $t7, -0x4230
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(231, 0X1290));
    // 0x804CAC68: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804CAC6C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804CAC70: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804CAC74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CAC78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CAC7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CAC80: jal         0x804CACA0
    // 0x804CAC84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CACA0(rdram, ctx);
        goto after_0;
    // 0x804CAC84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804CAC88: jal         0x804CABD4
    // 0x804CAC8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804CABD4(rdram, ctx);
        goto after_1;
    // 0x804CAC8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804CAC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CAC94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAC98: jr          $ra
    // 0x804CAC9C: nop

    return;
    // 0x804CAC9C: nop

;}
RECOMP_FUNC void func_806DF32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF32C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF334: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF338: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806DF33C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x806DF340: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x806DF344: beql        $t7, $zero, L_806DF370
    if (ctx->r15 == 0) {
        // 0x806DF348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF370;
    }
    goto skip_0;
    // 0x806DF348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806DF34C: lw          $t8, -0x7534($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7534);
    // 0x806DF350: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806DF354: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x806DF358: jal         0x80044658
    // 0x806DF35C: sw          $t9, -0x7534($at)
    MEM_W(-0X7534, ctx->r1) = ctx->r25;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x806DF35C: sw          $t9, -0x7534($at)
    MEM_W(-0X7534, ctx->r1) = ctx->r25;
    after_0:
    // 0x806DF360: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806DF364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806DF368: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806DF36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DF370:
    // 0x806DF370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF374: jr          $ra
    // 0x806DF378: nop

    return;
    // 0x806DF378: nop

;}
RECOMP_FUNC void func_80435868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435868: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043586C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80435870: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80435874: addiu       $v1, $v0, 0xE90
    ctx->r3 = ADD32(ctx->r2, 0XE90);
L_80435878:
    // 0x80435878: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8043587C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80435880: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80435884: nop

    // 0x80435888: bc1f        L_80435898
    if (!c1cs) {
        // 0x8043588C: nop
    
            goto L_80435898;
    }
    // 0x8043588C: nop

    // 0x80435890: jr          $ra
    // 0x80435894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80435894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80435898:
    // 0x80435898: bgez        $a1, L_80435878
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8043589C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80435878;
    }
    // 0x8043589C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x804358A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804358A4: jr          $ra
    // 0x804358A8: nop

    return;
    // 0x804358A8: nop

;}
RECOMP_FUNC void func_80024668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024668: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8002466C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80024670: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80024674: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80024678: jr          $ra
    // 0x8002467C: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x8002467C: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80026BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026BF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026BFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026C00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026C04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80026C08: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80026C0C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80026C10: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80026C14: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80026C18: jal         0x80024680
    // 0x80026C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80026C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80026C20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80026C24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80026C28: bne         $v0, $at, L_80026C38
    if (ctx->r2 != ctx->r1) {
        // 0x80026C2C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80026C38;
    }
    // 0x80026C2C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80026C30: jal         0x80026B80
    // 0x80026C34: nop

    func_80026B80(rdram, ctx);
        goto after_1;
    // 0x80026C34: nop

    after_1:
L_80026C38:
    // 0x80026C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026C44: jr          $ra
    // 0x80026C48: nop

    return;
    // 0x80026C48: nop

;}
RECOMP_FUNC void func_80777164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777164: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80777168: lui         $t6, 0x8077
    ctx->r14 = S32(RELOC_HI16(772, 0X524) << 16);
    // 0x8077716C: addiu       $t6, $t6, 0x6FF4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(772, 0X524));
    // 0x80777170: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80777174: jr          $ra
    // 0x80777178: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x80777178: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80776FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776FFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80777000: lui         $at, 0xC1A8
    ctx->r1 = S32(0XC1A8 << 16);
    // 0x80777004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80777008: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8077700C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80777010: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80777014: nop

    // 0x80777018: bc1tl       L_8077712C
    if (c1cs) {
        // 0x8077701C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8077712C;
    }
    goto skip_0;
    // 0x8077701C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80777020: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80777024: nop

    // 0x80777028: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8077702C: nop

    // 0x80777030: bc1fl       L_80777044
    if (!c1cs) {
        // 0x80777034: lwc1        $f6, 0x4($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80777044;
    }
    goto skip_1;
    // 0x80777034: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x80777038: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x8077703C: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80777040: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
L_80777044:
    // 0x80777044: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80777048: nop

    // 0x8077704C: bc1tl       L_8077712C
    if (c1cs) {
        // 0x80777050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8077712C;
    }
    goto skip_2;
    // 0x80777050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80777054: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80777058: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(772, 0X858) << 16);
    // 0x8077705C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80777060: nop

    // 0x80777064: bc1tl       L_8077712C
    if (c1cs) {
        // 0x80777068: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8077712C;
    }
    goto skip_3;
    // 0x80777068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8077706C: lwc1        $f10, 0x7328($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X858));
    // 0x80777070: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80777074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80777078: mul.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8077707C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80777080: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80777084: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80777088: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8077708C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80777090: nop

    // 0x80777094: bc1fl       L_807770A8
    if (!c1cs) {
        // 0x80777098: c.lt.s      $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
            goto L_807770A8;
    }
    goto skip_4;
    // 0x80777098: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    skip_4:
    // 0x8077709C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807770A0: nop

    // 0x807770A4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
L_807770A8:
    // 0x807770A8: nop

    // 0x807770AC: bc1fl       L_807770BC
    if (!c1cs) {
        // 0x807770B0: lwc1        $f4, 0x0($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
            goto L_807770BC;
    }
    goto skip_5;
    // 0x807770B0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x807770B4: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x807770B8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
L_807770BC:
    // 0x807770BC: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x807770C0: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x807770C4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x807770C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807770CC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x807770D0: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x807770D4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x807770D8: bnel        $t6, $at, L_8077712C
    if (ctx->r14 != ctx->r1) {
        // 0x807770DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8077712C;
    }
    goto skip_6;
    // 0x807770DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x807770E0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807770E4: mul.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x807770E8: jal         0x80065954
    // 0x807770EC: nop

    func_80065954(rdram, ctx);
        goto after_0;
    // 0x807770EC: nop

    after_0:
    // 0x807770F0: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(772, 0X85C) << 16);
    // 0x807770F4: lwc1        $f10, 0x732C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X85C));
    // 0x807770F8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807770FC: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80777100: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80777104: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80777108: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8077710C: bc1fl       L_8077712C
    if (!c1cs) {
        // 0x80777110: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8077712C;
    }
    goto skip_7;
    // 0x80777110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80777114: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x80777118: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8077711C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x80777120: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80777124: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x80777128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8077712C:
    // 0x8077712C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80777130: jr          $ra
    // 0x80777134: nop

    return;
    // 0x80777134: nop

;}
RECOMP_FUNC void func_8077FC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FC84: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8077FC88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8077FC8C: lw          $t6, 0x264($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X264);
    // 0x8077FC90: beq         $t6, $zero, L_8077FCC4
    if (ctx->r14 == 0) {
        // 0x8077FC94: nop
    
            goto L_8077FCC4;
    }
    // 0x8077FC94: nop

    // 0x8077FC98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8077FC9C: jal         0x8077FB48
    // 0x8077FCA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077FB48(rdram, ctx);
        goto after_0;
    // 0x8077FCA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077FCA4: beq         $v0, $zero, L_8077FCCC
    if (ctx->r2 == 0) {
        // 0x8077FCA8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8077FCCC;
    }
    // 0x8077FCA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077FCAC: jal         0x807800BC
    // 0x8077FCB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807800BC(rdram, ctx);
        goto after_1;
    // 0x8077FCB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8077FCB4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8077FCB8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8077FCBC: b           L_8077FCCC
    // 0x8077FCC0: sw          $t7, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r15;
        goto L_8077FCCC;
    // 0x8077FCC0: sw          $t7, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r15;
L_8077FCC4:
    // 0x8077FCC4: jal         0x8005D87C
    // 0x8077FCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8005D87C(rdram, ctx);
        goto after_2;
    // 0x8077FCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8077FCCC:
    // 0x8077FCCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FCD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FCD4: jr          $ra
    // 0x8077FCD8: nop

    return;
    // 0x8077FCD8: nop

;}
RECOMP_FUNC void func_804757E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804757E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804757E4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804757E8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804757EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804757F0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804757F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804757F8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804757FC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475800: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475804: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475808: jr          $ra
    // 0x8047580C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047580C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B0A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B0A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0A78: lbu         $t6, 0x30($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X30);
    // 0x806B0A7C: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x806B0A80: bnel        $t6, $at, L_806B0AA0
    if (ctx->r14 != ctx->r1) {
        // 0x806B0A84: sb          $zero, 0x17C($a0)
        MEM_B(0X17C, ctx->r4) = 0;
            goto L_806B0AA0;
    }
    goto skip_0;
    // 0x806B0A84: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    skip_0:
    // 0x806B0A88: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x806B0A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806B0A90: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x806B0A94: bne         $at, $zero, L_806B0AC0
    if (ctx->r1 != 0) {
        // 0x806B0A98: nop
    
            goto L_806B0AC0;
    }
    // 0x806B0A98: nop

    // 0x806B0A9C: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
L_806B0AA0:
    // 0x806B0AA0: jal         0x806B1198
    // 0x806B0AA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_806B1198(rdram, ctx);
        goto after_0;
    // 0x806B0AA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806B0AA8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806B0AAC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x806B0AB0: addiu       $t8, $t8, 0x33B4
    ctx->r24 = ADD32(ctx->r24, 0X33B4);
    // 0x806B0AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806B0AB8: b           L_806B0AC0
    // 0x806B0ABC: sw          $t8, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r24;
        goto L_806B0AC0;
    // 0x806B0ABC: sw          $t8, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r24;
L_806B0AC0:
    // 0x806B0AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B0AC8: jr          $ra
    // 0x806B0ACC: nop

    return;
    // 0x806B0ACC: nop

;}
RECOMP_FUNC void func_806D8C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8C34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D8C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D8C3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D8C40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D8C44: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D8C48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D8C4C: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x806D8C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D8C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D8C58: jal         0x80048F84
    // 0x806D8C5C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806D8C5C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D8C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D8C64: jal         0x80048F84
    // 0x806D8C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D8C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806D8C6C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806D8C70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D8C74: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806D8C78: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806D8C7C: nop

    // 0x806D8C80: bc1fl       L_806D8CE8
    if (!c1cs) {
        // 0x806D8C84: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806D8CE8;
    }
    goto skip_0;
    // 0x806D8C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x806D8C88: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x806D8C8C: bnel        $t7, $zero, L_806D8CE8
    if (ctx->r15 != 0) {
        // 0x806D8C90: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806D8CE8;
    }
    goto skip_1;
    // 0x806D8C90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x806D8C94: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x806D8C98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D8C9C: bnel        $t8, $at, L_806D8CC0
    if (ctx->r24 != ctx->r1) {
        // 0x806D8CA0: lw          $t0, 0x174($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X174);
            goto L_806D8CC0;
    }
    goto skip_2;
    // 0x806D8CA0: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    skip_2:
    // 0x806D8CA4: jal         0x806D88D0
    // 0x806D8CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D88D0(rdram, ctx);
        goto after_2;
    // 0x806D8CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D8CAC: jal         0x80044658
    // 0x806D8CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_3;
    // 0x806D8CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D8CB4: b           L_806D8D18
    // 0x806D8CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D8D18;
    // 0x806D8CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D8CBC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
L_806D8CC0:
    // 0x806D8CC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D8CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D8CC8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806D8CCC: jal         0x8005FCA8
    // 0x806D8CD0: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    func_8005FCA8(rdram, ctx);
        goto after_4;
    // 0x806D8CD0: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    after_4:
    // 0x806D8CD4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x806D8CD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806D8CDC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x806D8CE0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806D8CE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_806D8CE8:
    // 0x806D8CE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D8CEC: nop

    // 0x806D8CF0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806D8CF4: nop

    // 0x806D8CF8: bc1fl       L_806D8D18
    if (!c1cs) {
        // 0x806D8CFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D8D18;
    }
    goto skip_3;
    // 0x806D8CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806D8D00: lw          $t4, 0x180($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X180);
    // 0x806D8D04: bnel        $t4, $zero, L_806D8D18
    if (ctx->r12 != 0) {
        // 0x806D8D08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D8D18;
    }
    goto skip_4;
    // 0x806D8D08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806D8D0C: jal         0x806D89B8
    // 0x806D8D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D89B8(rdram, ctx);
        goto after_5;
    // 0x806D8D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806D8D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D8D18:
    // 0x806D8D18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D8D1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D8D20: jr          $ra
    // 0x806D8D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806D8D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806E0818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0818: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806E081C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806E0820: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(646, 0X2A0) << 16);
    // 0x806E0824: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806E0828: addiu       $t7, $t7, 0xA50
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(646, 0X2A0));
    // 0x806E082C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806E0830: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(646, 0X48) << 16);
    // 0x806E0834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806E0838: addiu       $t9, $t9, 0x7F8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(646, 0X48));
    // 0x806E083C: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806E0840: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806E0844: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806E0848: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E084C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806E0850: jr          $ra
    // 0x806E0854: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    return;
    // 0x806E0854: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_804A46F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A46F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A46F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A46F8: jal         0x804A49CC
    // 0x804A46FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A49CC(rdram, ctx);
        goto after_0;
    // 0x804A46FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A4700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A4704: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x804A4708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804A470C: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x804A4710: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x804A4714: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804A4718: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804A471C: nop

    // 0x804A4720: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804A4724: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804A4728: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804A472C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x804A4730: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x804A4734: jal         0x804A3BA0
    // 0x804A4738: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_804A3BA0(rdram, ctx);
        goto after_1;
    // 0x804A4738: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x804A473C: bne         $v0, $zero, L_804A4750
    if (ctx->r2 != 0) {
        // 0x804A4740: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A4750;
    }
    // 0x804A4740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A4744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A4748: jal         0x804A491C
    // 0x804A474C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804A491C(rdram, ctx);
        goto after_2;
    // 0x804A474C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
L_804A4750:
    // 0x804A4750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A4754: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804A4758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A475C: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x804A4760: jr          $ra
    // 0x804A4764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804A4764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8051552C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051552C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80515530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80515534: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80515538: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8051553C: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80515540: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80515544: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80515548: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8051554C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80515550: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80515554: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80515558: lw          $t9, 0xAC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XAC);
    // 0x8051555C: jalr        $t9
    // 0x80515560: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80515560: nop

    after_0:
    // 0x80515564: bne         $v0, $zero, L_8051557C
    if (ctx->r2 != 0) {
        // 0x80515568: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_8051557C;
    }
    // 0x80515568: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8051556C: jal         0x805154F8
    // 0x80515570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805154F8(rdram, ctx);
        goto after_1;
    // 0x80515570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80515574: b           L_80515708
    // 0x80515578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80515708;
    // 0x80515578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051557C:
    // 0x8051557C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80515580: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80515584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80515588: sb          $t8, 0x31($t1)
    MEM_B(0X31, ctx->r9) = ctx->r24;
    // 0x8051558C: jal         0x80047F9C
    // 0x80515590: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80515590: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x80515594: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE40) << 16);
    // 0x80515598: lwc1        $f6, 0x62E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE40));
    // 0x8051559C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x805155A0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805155A4: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1140) << 16);
    // 0x805155A8: swc1        $f6, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f6.u32l;
    // 0x805155AC: lwc1        $f8, 0x65E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X1140));
    // 0x805155B0: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x805155B4: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1144) << 16);
    // 0x805155B8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x805155BC: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(276, 0X113C) << 16);
    // 0x805155C0: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x805155C4: lui         $a2, 0x8051
    ctx->r6 = S32(RELOC_HI16(276, 0X1148) << 16);
    // 0x805155C8: swc1        $f10, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f10.u32l;
    // 0x805155CC: lwc1        $f16, 0x65E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X1144));
    // 0x805155D0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x805155D4: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE4C) << 16);
    // 0x805155D8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x805155DC: swc1        $f18, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f18.u32l;
    // 0x805155E0: lw          $v0, 0x65DC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(276, 0X113C));
    // 0x805155E4: bltz        $v0, L_80515680
    if (SIGNED(ctx->r2) < 0) {
        // 0x805155E8: negu        $a1, $v0
        ctx->r5 = SUB32(0, ctx->r2);
            goto L_80515680;
    }
    // 0x805155E8: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // 0x805155EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x805155F0: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x805155F4: lw          $t5, 0x3EC($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3EC);
    // 0x805155F8: lui         $t0, 0x8051
    ctx->r8 = S32(RELOC_HI16(276, 0XB50) << 16);
    // 0x805155FC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80515600: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80515604: lbu         $v1, 0x598($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X598);
    // 0x80515608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051560C: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x80515610: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80515614: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80515618: lw          $t0, 0x5FF0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(276, 0XB50));
    // 0x8051561C: lui         $a2, 0x8051
    ctx->r6 = S32(RELOC_HI16(276, 0X1148) << 16);
    // 0x80515620: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE48) << 16);
    // 0x80515624: bne         $t0, $zero, L_80515658
    if (ctx->r8 != 0) {
        // 0x80515628: addu        $t8, $t0, $t9
        ctx->r24 = ADD32(ctx->r8, ctx->r25);
            goto L_80515658;
    }
    // 0x80515628: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x8051562C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80515630: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE44) << 16);
    // 0x80515634: lwc1        $f4, 0x62E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE44));
    // 0x80515638: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8051563C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80515640: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x80515644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80515648: jal         0x8005CEBC
    // 0x8051564C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x8051564C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80515650: b           L_805156A0
    // 0x80515654: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_805156A0;
    // 0x80515654: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80515658:
    // 0x80515658: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051565C: lwc1        $f6, 0x62E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE48));
    // 0x80515660: lhu         $a1, 0x0($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X0);
    // 0x80515664: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80515668: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8051566C: lw          $a2, 0x65E8($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(276, 0X1148));
    // 0x80515670: jal         0x8005CEBC
    // 0x80515674: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x80515674: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80515678: b           L_805156A0
    // 0x8051567C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_805156A0;
    // 0x8051567C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80515680:
    // 0x80515680: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80515684: lwc1        $f8, 0x62EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE4C));
    // 0x80515688: lw          $a2, 0x65E8($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(276, 0X1148));
    // 0x8051568C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80515690: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80515694: jal         0x8005CEBC
    // 0x80515698: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_5;
    // 0x80515698: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8051569C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_805156A0:
    // 0x805156A0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x805156A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805156A8: beq         $a1, $zero, L_805156B8
    if (ctx->r5 == 0) {
        // 0x805156AC: nop
    
            goto L_805156B8;
    }
    // 0x805156AC: nop

    // 0x805156B0: sb          $t1, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r9;
    // 0x805156B4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_805156B8:
    // 0x805156B8: bne         $a1, $zero, L_805156D0
    if (ctx->r5 != 0) {
        // 0x805156BC: nop
    
            goto L_805156D0;
    }
    // 0x805156BC: nop

    // 0x805156C0: jal         0x805154F8
    // 0x805156C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805154F8(rdram, ctx);
        goto after_6;
    // 0x805156C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x805156C8: b           L_80515708
    // 0x805156CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80515708;
    // 0x805156CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805156D0:
    // 0x805156D0: jal         0x80047F9C
    // 0x805156D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x805156D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x805156D8: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE50) << 16);
    // 0x805156DC: lwc1        $f10, 0x62F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE50));
    // 0x805156E0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805156E4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x805156E8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x805156EC: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805156F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805156F4: swc1        $f0, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f0.u32l;
    // 0x805156F8: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x805156FC: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    // 0x80515700: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80515704: sb          $t4, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r12;
L_80515708:
    // 0x80515708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8051570C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80515710: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80515714: jr          $ra
    // 0x80515718: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80515718: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805CEF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CEF10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CEF14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CEF18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CEF1C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(459, 0X3D0) << 16);
    // 0x805CEF20: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(459, 0X3E0) << 16);
    // 0x805CEF24: addiu       $a1, $a1, -0xD10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(459, 0X3E0));
    // 0x805CEF28: addiu       $a0, $a0, -0xD20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(459, 0X3D0));
    // 0x805CEF2C: jal         0x8004667C
    // 0x805CEF30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805CEF30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x805CEF34: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805CEF38: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(459, 0X298) << 16);
    // 0x805CEF3C: addiu       $a2, $a2, -0xE58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(459, 0X298));
    // 0x805CEF40: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805CEF44: jal         0x80057B28
    // 0x805CEF48: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805CEF48: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_1:
    // 0x805CEF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CEF50: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(459, 0X50) << 16);
    // 0x805CEF54: addiu       $v0, $v0, -0x10A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(459, 0X50));
    // 0x805CEF58: jr          $ra
    // 0x805CEF5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CEF5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006C77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C77C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C784: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8006C788: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8006C78C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8006C790: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8006C794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C798: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8006C79C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8006C7A0: beq         $v0, $a0, L_8006C7E4
    if (ctx->r2 == ctx->r4) {
        // 0x8006C7A4: lw          $t6, 0x59C($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X59C);
            goto L_8006C7E4;
    }
    // 0x8006C7A4: lw          $t6, 0x59C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X59C);
L_8006C7A8:
    // 0x8006C7A8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8006C7AC: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8006C7B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006C7B4: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8006C7B8: lw          $t8, 0x59C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X59C);
    // 0x8006C7BC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006C7C0: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8006C7C4: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8006C7C8: lw          $t0, 0x59C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X59C);
    // 0x8006C7CC: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8006C7D0: lwc1        $f18, 0x1C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8006C7D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006C7D8: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8006C7DC: bne         $v0, $a0, L_8006C7A8
    if (ctx->r2 != ctx->r4) {
        // 0x8006C7E0: lw          $t6, 0x59C($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X59C);
            goto L_8006C7A8;
    }
    // 0x8006C7E0: lw          $t6, 0x59C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X59C);
L_8006C7E4:
    // 0x8006C7E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8006C7E8: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8006C7EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006C7F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006C7F4: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8006C7F8: lw          $t8, 0x59C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X59C);
    // 0x8006C7FC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006C800: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8006C804: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8006C808: lw          $t0, 0x59C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X59C);
    // 0x8006C80C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8006C810: lwc1        $f18, 0x1C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8006C814: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006C818: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8006C81C: lw          $t2, 0x59C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X59C);
    // 0x8006C820: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8006C824: lw          $t3, 0x28($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X28);
    // 0x8006C828: jal         0x8006C3C4
    // 0x8006C82C: sw          $t3, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r11;
    func_8006C3C4(rdram, ctx);
        goto after_0;
    // 0x8006C82C: sw          $t3, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r11;
    after_0:
    // 0x8006C830: jal         0x8006CB3C
    // 0x8006C834: nop

    func_8006CB3C(rdram, ctx);
        goto after_1;
    // 0x8006C834: nop

    after_1:
    // 0x8006C838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C83C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C840: jr          $ra
    // 0x8006C844: nop

    return;
    // 0x8006C844: nop

;}
RECOMP_FUNC void func_8007FE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FE20: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FE28: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FE2C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FE30: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8007FE34: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8007FE38: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FE3C: jal         0x800818E8
    // 0x8007FE40: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FE40: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FE44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FE48: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8007FE4C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8007FE50: jal         0x80080824
    // 0x8007FE54: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80080824(rdram, ctx);
        goto after_1;
    // 0x8007FE54: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_1:
    // 0x8007FE58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FE5C: jal         0x800817A0
    // 0x8007FE60: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FE60: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FE68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FE6C: jr          $ra
    // 0x8007FE70: nop

    return;
    // 0x8007FE70: nop

;}
RECOMP_FUNC void func_80048B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048B2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048B30: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80048B34: jalr        $t9
    // 0x80048B38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80048B38: nop

    after_0:
    // 0x80048B3C: bne         $v0, $zero, L_80048B4C
    if (ctx->r2 != 0) {
        // 0x80048B40: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80048B4C;
    }
    // 0x80048B40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80048B44: jal         0x80048AE0
    // 0x80048B48: nop

    func_80048AE0(rdram, ctx);
        goto after_1;
    // 0x80048B48: nop

    after_1:
L_80048B4C:
    // 0x80048B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048B54: jr          $ra
    // 0x80048B58: nop

    return;
    // 0x80048B58: nop

;}
RECOMP_FUNC void func_80519E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519E3C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80519E40: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(291, 0X60C) << 16);
    // 0x80519E44: addiu       $t6, $t6, -0x7D84
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(291, 0X60C));
    // 0x80519E48: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80519E4C: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(291, 0X63C) << 16);
    // 0x80519E50: addiu       $t9, $t9, -0x7D54
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(291, 0X63C));
    // 0x80519E54: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80519E58: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x80519E5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80519E60: jr          $ra
    // 0x80519E64: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x80519E64: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_805233E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805233E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805233E8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805233EC: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x805233F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805233F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805233F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805233FC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80523400: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80523404: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80523408: bne         $t7, $at, L_80523420
    if (ctx->r15 != ctx->r1) {
        // 0x8052340C: addiu       $a1, $zero, 0x24
        ctx->r5 = ADD32(0, 0X24);
            goto L_80523420;
    }
    // 0x8052340C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80523410: jal         0x800447C8
    // 0x80523414: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80523414: nop

    after_0:
    // 0x80523418: b           L_80523550
    // 0x8052341C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523550;
    // 0x8052341C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523420:
    // 0x80523420: jal         0x80045A34
    // 0x80523424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80523424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80523428: bne         $v0, $zero, L_80523440
    if (ctx->r2 != 0) {
        // 0x8052342C: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_80523440;
    }
    // 0x8052342C: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x80523430: jal         0x800445A4
    // 0x80523434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80523434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80523438: b           L_80523550
    // 0x8052343C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523550;
    // 0x8052343C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523440:
    // 0x80523440: lw          $t9, 0x16C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X16C);
    // 0x80523444: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(321, 0X1E3C) << 16);
    // 0x80523448: addiu       $t8, $t8, 0x40EC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(321, 0X1E3C));
    // 0x8052344C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80523450: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80523454: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x80523458: sb          $t0, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r8;
    // 0x8052345C: jal         0x8005FD1C
    // 0x80523460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_3;
    // 0x80523460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80523464: lw          $t1, 0x174($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X174);
    // 0x80523468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8052346C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80523470: jal         0x80522A8C
    // 0x80523474: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    func_80522A8C(rdram, ctx);
        goto after_4;
    // 0x80523474: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    after_4:
    // 0x80523478: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x8052347C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80523480: sw          $t3, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r11;
    // 0x80523484: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    // 0x80523488: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8052348C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80523490: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80523494: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80523498: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8052349C: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x805234A0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x805234A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805234A8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x805234AC: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x805234B0: addiu       $a0, $zero, 0x4146
    ctx->r4 = ADD32(0, 0X4146);
    // 0x805234B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805234B8: jal         0x80047090
    // 0x805234BC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x805234BC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x805234C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805234C4: lui         $at, 0x4146
    ctx->r1 = S32(0X4146 << 16);
    // 0x805234C8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x805234CC: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x805234D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805234D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805234D8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805234DC: jal         0x8004613C
    // 0x805234E0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x805234E0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_6:
    // 0x805234E4: bne         $v0, $zero, L_805234FC
    if (ctx->r2 != 0) {
        // 0x805234E8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_805234FC;
    }
    // 0x805234E8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x805234EC: jal         0x800445A4
    // 0x805234F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x805234F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x805234F4: b           L_80523550
    // 0x805234F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523550;
    // 0x805234F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805234FC:
    // 0x805234FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80523500: jal         0x80047F9C
    // 0x80523504: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80523504: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80523508: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8052350C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80523510: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EA0) << 16);
    // 0x80523514: sb          $v0, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r2;
    // 0x80523518: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8052351C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80523520: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80523524: sb          $v0, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r2;
    // 0x80523528: lwc1        $f16, 0x4150($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EA0));
    // 0x8052352C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EA4) << 16);
    // 0x80523530: swc1        $f16, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f16.u32l;
    // 0x80523534: lwc1        $f18, 0x4154($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EA4));
    // 0x80523538: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8052353C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80523540: swc1        $f18, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f18.u32l;
    // 0x80523544: jal         0x80523830
    // 0x80523548: swc1        $f4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f4.u32l;
    func_80523830(rdram, ctx);
        goto after_9;
    // 0x80523548: swc1        $f4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f4.u32l;
    after_9:
    // 0x8052354C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523550:
    // 0x80523550: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80523554: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80523558: jr          $ra
    // 0x8052355C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8052355C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80019160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019168: jal         0x800199B0
    // 0x8001916C: nop

    func_800199B0(rdram, ctx);
        goto after_0;
    // 0x8001916C: nop

    after_0:
    // 0x80019170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019174: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80019178: sb          $zero, -0x6D00($at)
    MEM_B(-0X6D00, ctx->r1) = 0;
    // 0x8001917C: jr          $ra
    // 0x80019180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80019180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003431C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003431C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034324: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034328: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003432C: jal         0x800340F8
    // 0x80034330: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800340F8(rdram, ctx);
        goto after_0;
    // 0x80034330: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80034338: beq         $v0, $zero, L_80034348
    if (ctx->r2 == 0) {
        // 0x8003433C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80034348;
    }
    // 0x8003433C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80034340: b           L_800343B0
    // 0x80034344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800343B0;
    // 0x80034344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034348:
    // 0x80034348: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003434C: lwc1        $f4, 0xA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA8);
    // 0x80034350: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80034354: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80034358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003435C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80034360: nop

    // 0x80034364: bc1f        L_800343B0
    if (!c1cs) {
        // 0x80034368: nop
    
            goto L_800343B0;
    }
    // 0x80034368: nop

    // 0x8003436C: lbu         $t6, -0x766B($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X766B);
    // 0x80034370: beq         $t6, $zero, L_800343B0
    if (ctx->r14 == 0) {
        // 0x80034374: nop
    
            goto L_800343B0;
    }
    // 0x80034374: nop

    // 0x80034378: lbu         $t7, 0xF7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XF7);
    // 0x8003437C: beq         $t7, $zero, L_800343B0
    if (ctx->r15 == 0) {
        // 0x80034380: nop
    
            goto L_800343B0;
    }
    // 0x80034380: nop

    // 0x80034384: lw          $t8, 0x104($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X104);
    // 0x80034388: beq         $t8, $zero, L_800343A0
    if (ctx->r24 == 0) {
        // 0x8003438C: nop
    
            goto L_800343A0;
    }
    // 0x8003438C: nop

    // 0x80034390: jal         0x8002DF30
    // 0x80034394: nop

    func_8002DF30(rdram, ctx);
        goto after_1;
    // 0x80034394: nop

    after_1:
    // 0x80034398: b           L_800343B0
    // 0x8003439C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800343B0;
    // 0x8003439C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800343A0:
    // 0x800343A0: jal         0x8002DE68
    // 0x800343A4: nop

    func_8002DE68(rdram, ctx);
        goto after_2;
    // 0x800343A4: nop

    after_2:
    // 0x800343A8: b           L_800343B0
    // 0x800343AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800343B0;
    // 0x800343AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800343B0:
    // 0x800343B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800343B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800343B8: jr          $ra
    // 0x800343BC: nop

    return;
    // 0x800343BC: nop

;}
RECOMP_FUNC void func_807AF714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF714: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807AF718: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AF71C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807AF720: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AF724: bne         $v0, $at, L_807AF7D0
    if (ctx->r2 != ctx->r1) {
        // 0x807AF728: lui         $at, 0xC1C0
        ctx->r1 = S32(0XC1C0 << 16);
            goto L_807AF7D0;
    }
    // 0x807AF728: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x807AF72C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AF730: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x807AF734: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807AF738: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x807AF73C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x807AF740: nop

    // 0x807AF744: bc1fl       L_807AF788
    if (!c1cs) {
        // 0x807AF748: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_807AF788;
    }
    goto skip_0;
    // 0x807AF748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x807AF74C: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x807AF750: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807AF754: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x807AF758: beq         $v0, $zero, L_807AF7D0
    if (ctx->r2 == 0) {
        // 0x807AF75C: nop
    
            goto L_807AF7D0;
    }
    // 0x807AF75C: nop

    // 0x807AF760: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF764: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF768: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF76C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AF770: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807AF774: bne         $t8, $at, L_807AF7D0
    if (ctx->r24 != ctx->r1) {
        // 0x807AF778: nop
    
            goto L_807AF7D0;
    }
    // 0x807AF778: nop

    // 0x807AF77C: jr          $ra
    // 0x807AF780: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    return;
    // 0x807AF780: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x807AF784: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_807AF788:
    // 0x807AF788: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807AF78C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x807AF790: nop

    // 0x807AF794: bc1f        L_807AF7D0
    if (!c1cs) {
        // 0x807AF798: nop
    
            goto L_807AF7D0;
    }
    // 0x807AF798: nop

    // 0x807AF79C: lw          $t0, -0x77F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X77F0);
    // 0x807AF7A0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x807AF7A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x807AF7A8: beq         $v0, $zero, L_807AF7D0
    if (ctx->r2 == 0) {
        // 0x807AF7AC: nop
    
            goto L_807AF7D0;
    }
    // 0x807AF7AC: nop

    // 0x807AF7B0: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF7B4: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF7B8: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF7BC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x807AF7C0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x807AF7C4: bne         $t2, $at, L_807AF7D0
    if (ctx->r10 != ctx->r1) {
        // 0x807AF7C8: nop
    
            goto L_807AF7D0;
    }
    // 0x807AF7C8: nop

    // 0x807AF7CC: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
L_807AF7D0:
    // 0x807AF7D0: jr          $ra
    // 0x807AF7D4: nop

    return;
    // 0x807AF7D4: nop

;}
RECOMP_FUNC void func_8057F6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F6FC: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8057F700: jal         0x80067818
    // 0x8057F704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x8057F704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8057F708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F70C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F710: jr          $ra
    // 0x8057F714: nop

    return;
    // 0x8057F714: nop

;}
RECOMP_FUNC void func_8073F638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F638: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073F63C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8073F640: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8073F644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073F648: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8073F64C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8073F650: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8073F654: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x8073F658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8073F65C:
    // 0x8073F65C: jal         0x8073F4BC
    // 0x8073F660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8073F4BC(rdram, ctx);
        goto after_0;
    // 0x8073F660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8073F664: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8073F668: bnel        $s0, $s2, L_8073F65C
    if (ctx->r16 != ctx->r18) {
        // 0x8073F66C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8073F65C;
    }
    goto skip_0;
    // 0x8073F66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8073F670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8073F674: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073F678: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8073F67C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8073F680: jr          $ra
    // 0x8073F684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8073F684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8078DF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DF20: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(808, 0X938) << 16);
    // 0x8078DF24: addiu       $v0, $v0, -0x17A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(808, 0X938));
    // 0x8078DF28: jr          $ra
    // 0x8078DF2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8078DF2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80035AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035AE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035AF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80035AF4: jal         0x800653D8
    // 0x80035AF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80035AF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80035AFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80035B00: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80035B04: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80035B08: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80035B0C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80035B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80035B14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80035B18: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80035B1C: lw          $t0, -0x1550($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1550);
    // 0x80035B20: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80035B24: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80035B28: lbu         $a2, 0x0($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X0);
    // 0x80035B2C: bne         $a2, $at, L_80035B44
    if (ctx->r6 != ctx->r1) {
        // 0x80035B30: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80035B44;
    }
    // 0x80035B30: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80035B34: jal         0x80035834
    // 0x80035B38: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    func_80035834(rdram, ctx);
        goto after_1;
    // 0x80035B38: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    after_1:
    // 0x80035B3C: b           L_80035BB4
    // 0x80035B40: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
        goto L_80035BB4;
    // 0x80035B40: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
L_80035B44:
    // 0x80035B44: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80035B48: bne         $v1, $at, L_80035B58
    if (ctx->r3 != ctx->r1) {
        // 0x80035B4C: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80035B58;
    }
    // 0x80035B4C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80035B50: b           L_80035BB4
    // 0x80035B54: sw          $t2, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r10;
        goto L_80035BB4;
    // 0x80035B54: sw          $t2, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r10;
L_80035B58:
    // 0x80035B58: lw          $t3, 0x50($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X50);
    // 0x80035B5C: sltiu       $at, $t3, 0x168
    ctx->r1 = ctx->r11 < 0X168 ? 1 : 0;
    // 0x80035B60: bnel        $at, $zero, L_80035B78
    if (ctx->r1 != 0) {
        // 0x80035B64: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80035B78;
    }
    goto skip_0;
    // 0x80035B64: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_0:
    // 0x80035B68: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    // 0x80035B6C: b           L_80035BB4
    // 0x80035B70: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
        goto L_80035BB4;
    // 0x80035B70: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x80035B74: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
L_80035B78:
    // 0x80035B78: bne         $v1, $at, L_80035BB4
    if (ctx->r3 != ctx->r1) {
        // 0x80035B7C: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_80035BB4;
    }
    // 0x80035B7C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80035B80: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80035B84: lw          $t4, 0xF10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XF10);
    // 0x80035B88: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80035B8C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80035B90: lw          $v0, 0xF14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XF14);
    // 0x80035B94: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80035B98: bne         $at, $zero, L_80035BA8
    if (ctx->r1 != 0) {
        // 0x80035B9C: nop
    
            goto L_80035BA8;
    }
    // 0x80035B9C: nop

    // 0x80035BA0: b           L_80035BB4
    // 0x80035BA4: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
        goto L_80035BB4;
    // 0x80035BA4: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
L_80035BA8:
    // 0x80035BA8: bnel        $v0, $zero, L_80035BB8
    if (ctx->r2 != 0) {
        // 0x80035BAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035BB8;
    }
    goto skip_1;
    // 0x80035BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80035BB0: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
L_80035BB4:
    // 0x80035BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035BB8:
    // 0x80035BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80035BBC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80035BC0: jr          $ra
    // 0x80035BC4: nop

    return;
    // 0x80035BC4: nop

;}
RECOMP_FUNC void func_8067B4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067B4D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8067B4DC: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8067B4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067B4E4: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8067B4E8: jal         0x8067B194
    // 0x8067B4EC: addiu       $a2, $v0, 0x17
    ctx->r6 = ADD32(ctx->r2, 0X17);
    func_8067B194(rdram, ctx);
        goto after_0;
    // 0x8067B4EC: addiu       $a2, $v0, 0x17
    ctx->r6 = ADD32(ctx->r2, 0X17);
    after_0:
    // 0x8067B4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067B4F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067B4F8: jr          $ra
    // 0x8067B4FC: nop

    return;
    // 0x8067B4FC: nop

;}
RECOMP_FUNC void func_8047380C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047380C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80473810: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x80473814: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80473818: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8047381C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80473820: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80473824: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80473828: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8047382C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80473830: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80473834: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80473838: nop

    // 0x8047383C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80473840: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80473844: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80473848: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8047384C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80473850: nop

    // 0x80473854: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80473858: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8047385C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x80473860: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80473864: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x80473868: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8047386C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x80473870: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80473874: jr          $ra
    // 0x80473878: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80473878: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_804322E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804322E0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(59, 0X328) << 16);
    // 0x804322E4: addiu       $v0, $v0, 0x2608
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(59, 0X328));
    // 0x804322E8: jr          $ra
    // 0x804322EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804322EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80535324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535324: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80535328: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(348, 0XAFC) << 16);
    // 0x8053532C: addiu       $t6, $t6, 0x510C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(348, 0XAFC));
    // 0x80535330: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80535334: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(348, 0XBB8) << 16);
    // 0x80535338: addiu       $t9, $t9, 0x51C8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(348, 0XBB8));
    // 0x8053533C: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80535340: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x80535344: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80535348: jr          $ra
    // 0x8053534C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x8053534C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_806EDA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDA88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EDA8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDA90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDA94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDA98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDA9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EDAA0: jal         0x800577D8
    // 0x806EDAA4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDAA4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EDAA8: jal         0x806ED57C
    // 0x806EDAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED57C(rdram, ctx);
        goto after_1;
    // 0x806EDAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EDAB0: jal         0x806ED5F0
    // 0x806EDAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED5F0(rdram, ctx);
        goto after_2;
    // 0x806EDAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EDAB8: jal         0x806ED6C4
    // 0x806EDABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_3;
    // 0x806EDABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EDAC0: bne         $v0, $zero, L_806EDAE0
    if (ctx->r2 != 0) {
        // 0x806EDAC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDAE0;
    }
    // 0x806EDAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDAC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDACC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EDAD0: jal         0x806EE584
    // 0x806EDAD4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_4;
    // 0x806EDAD4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EDAD8: b           L_806EDBAC
    // 0x806EDADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDBAC;
    // 0x806EDADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDAE0:
    // 0x806EDAE0: jal         0x806ED714
    // 0x806EDAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED714(rdram, ctx);
        goto after_5;
    // 0x806EDAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EDAE8: beq         $v0, $zero, L_806EDB08
    if (ctx->r2 == 0) {
        // 0x806EDAEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDB08;
    }
    // 0x806EDAEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDAF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDAF4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EDAF8: jal         0x806EE584
    // 0x806EDAFC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_6;
    // 0x806EDAFC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EDB00: b           L_806EDBAC
    // 0x806EDB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDBAC;
    // 0x806EDB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDB08:
    // 0x806EDB08: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806EDB0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806EDB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDB18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EDB1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EDB20: bc1f        L_806EDBA0
    if (!c1cs) {
        // 0x806EDB24: nop
    
            goto L_806EDBA0;
    }
    // 0x806EDB24: nop

    // 0x806EDB28: jal         0x806EE584
    // 0x806EDB2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_7;
    // 0x806EDB2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EDB30: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806EDB34: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDB38: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806EDB3C: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x806EDB40: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EDB44: nop

    // 0x806EDB48: bc1fl       L_806EDB78
    if (!c1cs) {
        // 0x806EDB4C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EDB78;
    }
    goto skip_0;
    // 0x806EDB4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x806EDB50: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x806EDB54: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EDB58: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806EDB5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EDB60: jal         0x806EC03C
    // 0x806EDB64: nop

    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EDB64: nop

    after_8:
    // 0x806EDB68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EDB6C: b           L_806EDB90
    // 0x806EDB70: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
        goto L_806EDB90;
    // 0x806EDB70: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x806EDB74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EDB78:
    // 0x806EDB78: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806EDB7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EDB80: jal         0x806EC03C
    // 0x806EDB84: nop

    func_806EC03C(rdram, ctx);
        goto after_9;
    // 0x806EDB84: nop

    after_9:
    // 0x806EDB88: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806EDB8C: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
L_806EDB90:
    // 0x806EDB90: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDB94: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806EDB98: b           L_806EDBA8
    // 0x806EDB9C: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
        goto L_806EDBA8;
    // 0x806EDB9C: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
L_806EDBA0:
    // 0x806EDBA0: jal         0x806ED844
    // 0x806EDBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED844(rdram, ctx);
        goto after_10;
    // 0x806EDBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_806EDBA8:
    // 0x806EDBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDBAC:
    // 0x806EDBAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDBB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EDBB4: jr          $ra
    // 0x806EDBB8: nop

    return;
    // 0x806EDBB8: nop

;}
RECOMP_FUNC void func_80704CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704CB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80704CB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80704CBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80704CC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80704CC4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80704CC8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704CCC: addiu       $a2, $a0, 0xC4
    ctx->r6 = ADD32(ctx->r4, 0XC4);
    // 0x80704CD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80704CD4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80704CD8: jal         0x80048F84
    // 0x80704CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80704CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80704CE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80704CE4: jal         0x80048F84
    // 0x80704CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80704CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80704CEC: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80704CF0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80704CF4: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(709, 0X3748) << 16);
    // 0x80704CF8: beq         $v1, $zero, L_80704D08
    if (ctx->r3 == 0) {
        // 0x80704CFC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80704D08;
    }
    // 0x80704CFC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80704D00: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x80704D04: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80704D08:
    // 0x80704D08: bnel        $v1, $zero, L_80704DA4
    if (ctx->r3 != 0) {
        // 0x80704D0C: lhu         $t6, 0xC($s1)
        ctx->r14 = MEM_HU(ctx->r17, 0XC);
            goto L_80704DA4;
    }
    goto skip_0;
    // 0x80704D0C: lhu         $t6, 0xC($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XC);
    skip_0:
    // 0x80704D10: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80704D14: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(709, 0X3758) << 16);
    // 0x80704D18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80704D1C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80704D20: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80704D24: lw          $t7, 0x6BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(709, 0X3748));
    // 0x80704D28: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80704D2C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80704D30: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80704D34: lw          $t8, 0x6BC8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(709, 0X3758));
    // 0x80704D38: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x80704D3C: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x80704D40: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
    // 0x80704D44: bne         $t1, $at, L_80704DA0
    if (ctx->r9 != ctx->r1) {
        // 0x80704D48: sw          $t8, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r24;
            goto L_80704DA0;
    }
    // 0x80704D48: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x80704D4C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80704D50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80704D54: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3740) << 16);
    // 0x80704D58: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80704D5C: lw          $t3, 0x138($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X138);
    // 0x80704D60: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80704D64: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80704D68: lwc1        $f6, 0x6BB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3740));
    // 0x80704D6C: addiu       $at, $zero, 0x461F
    ctx->r1 = ADD32(0, 0X461F);
    // 0x80704D70: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x80704D74: lhu         $t5, 0xC($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XC);
    // 0x80704D78: bne         $t5, $at, L_80704DA0
    if (ctx->r13 != ctx->r1) {
        // 0x80704D7C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80704DA0;
    }
    // 0x80704D7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80704D80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80704D84: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80704D88: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80704D8C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80704D90: nop

    // 0x80704D94: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80704D98: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80704D9C: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_80704DA0:
    // 0x80704DA0: lhu         $t6, 0xC($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XC);
L_80704DA4:
    // 0x80704DA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80704DA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80704DAC: addiu       $at, $zero, 0x461F
    ctx->r1 = ADD32(0, 0X461F);
    // 0x80704DB0: bnel        $t6, $at, L_80704DC4
    if (ctx->r14 != ctx->r1) {
        // 0x80704DB4: lwc1        $f6, 0x0($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80704DC4;
    }
    goto skip_1;
    // 0x80704DB4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80704DB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80704DBC: nop

    // 0x80704DC0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
L_80704DC4:
    // 0x80704DC4: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80704DC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80704DCC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80704DD0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38B0) << 16);
    // 0x80704DD4: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80704DD8: nop

    // 0x80704DDC: bc1tl       L_80704DF4
    if (c1cs) {
        // 0x80704DE0: swc1        $f2, 0x1C($a2)
        MEM_W(0X1C, ctx->r6) = ctx->f2.u32l;
            goto L_80704DF4;
    }
    goto skip_2;
    // 0x80704DE0: swc1        $f2, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f2.u32l;
    skip_2:
    // 0x80704DE4: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80704DE8: bne         $t7, $zero, L_80704E70
    if (ctx->r15 != 0) {
        // 0x80704DEC: nop
    
            goto L_80704E70;
    }
    // 0x80704DEC: nop

    // 0x80704DF0: swc1        $f2, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f2.u32l;
L_80704DF4:
    // 0x80704DF4: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x80704DF8: swc1        $f2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f2.u32l;
    // 0x80704DFC: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80704E00: lwc1        $f10, 0x6D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38B0));
    // 0x80704E04: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38B4) << 16);
    // 0x80704E08: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
    // 0x80704E0C: lwc1        $f16, 0x6D24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38B4));
    // 0x80704E10: swc1        $f16, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f16.u32l;
    // 0x80704E14: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x80704E18: jal         0x80067BBC
    // 0x80704E1C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80704E1C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_2:
    // 0x80704E20: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80704E24: jal         0x80067818
    // 0x80704E28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80704E28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80704E2C: jal         0x807041F8
    // 0x80704E30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807041F8(rdram, ctx);
        goto after_4;
    // 0x80704E30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80704E34: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80704E38: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80704E3C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80704E40: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80704E44: lhu         $t9, 0xC($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XC);
    // 0x80704E48: addiu       $at, $zero, 0x4607
    ctx->r1 = ADD32(0, 0X4607);
    // 0x80704E4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80704E50: bne         $t9, $at, L_80704E60
    if (ctx->r25 != ctx->r1) {
        // 0x80704E54: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80704E60;
    }
    // 0x80704E54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80704E58: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80704E5C: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
L_80704E60:
    // 0x80704E60: jal         0x80705A5C
    // 0x80704E64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80705A5C(rdram, ctx);
        goto after_5;
    // 0x80704E64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x80704E68: b           L_80704E84
    // 0x80704E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80704E84;
    // 0x80704E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80704E70:
    // 0x80704E70: jal         0x8070384C
    // 0x80704E74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8070384C(rdram, ctx);
        goto after_6;
    // 0x80704E74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80704E78: jal         0x80703F10
    // 0x80704E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80703F10(rdram, ctx);
        goto after_7;
    // 0x80704E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80704E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80704E84:
    // 0x80704E84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80704E88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80704E8C: jr          $ra
    // 0x80704E90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80704E90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80408710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408710: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80408714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80408718: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040871C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80408720: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80408724: lw          $a2, 0x16C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X16C);
    // 0x80408728: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x8040872C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80408730: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80408734: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x80408738: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x8040873C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80408740: jal         0x8004921C
    // 0x80408744: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80408744: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    after_0:
    // 0x80408748: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8040874C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80408750: jal         0x8004921C
    // 0x80408754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80408754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80408758: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8040875C: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80408760: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80408764: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80408768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040876C: lbu         $t4, 0x145($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X145);
    // 0x80408770: lw          $t6, 0x168($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X168);
    // 0x80408774: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80408778: lw          $s1, 0x1F4($a3)
    ctx->r17 = MEM_W(ctx->r7, 0X1F4);
    // 0x8040877C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x80408780: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408784: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80408788: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8040878C: mflo        $t9
    ctx->r25 = lo;
    // 0x80408790: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80408794: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80408798: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040879C: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x804087A0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x804087A4: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x804087A8: ori         $t9, $t9, 0x2CF0
    ctx->r25 = ctx->r25 | 0X2CF0;
    // 0x804087AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804087B0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x804087B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x804087B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804087BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804087C0: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x804087C4: lui         $a1, 0xF0A
    ctx->r5 = S32(0XF0A << 16);
    // 0x804087C8: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x804087CC: ori         $t4, $t4, 0x3
    ctx->r12 = ctx->r12 | 0X3;
    // 0x804087D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804087D4: mflo        $t5
    ctx->r13 = lo;
    // 0x804087D8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x804087DC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x804087E0: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x804087E4: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x804087E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804087EC: addu        $t2, $t5, $t7
    ctx->r10 = ADD32(ctx->r13, ctx->r15);
    // 0x804087F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804087F4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x804087F8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x804087FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408800: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80408804: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80408808: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x8040880C: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80408810: sll         $t5, $t6, 24
    ctx->r13 = S32(ctx->r14 << 24);
    // 0x80408814: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80408818: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8040881C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80408820: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80408824: ori         $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 | 0XFF;
    // 0x80408828: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8040882C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80408830: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80408834: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80408838: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8040883C: lbu         $t5, 0x4($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X4);
    // 0x80408840: lbu         $t7, 0x6($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X6);
    // 0x80408844: lbu         $t9, 0x5($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X5);
    // 0x80408848: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x8040884C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80408850: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x80408854: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80408858: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8040885C: ori         $t8, $t6, 0xC8
    ctx->r24 = ctx->r14 | 0XC8;
    // 0x80408860: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80408864: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040886C: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80408870: ori         $t7, $t7, 0xB9FF
    ctx->r15 = ctx->r15 | 0XB9FF;
    // 0x80408874: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408878: lui         $t9, 0xFF72
    ctx->r25 = S32(0XFF72 << 16);
    // 0x8040887C: ori         $t9, $t9, 0x5B2D
    ctx->r25 = ctx->r25 | 0X5B2D;
    // 0x80408880: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80408884: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80408888: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8040888C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408890: addiu       $t5, $zero, 0x204
    ctx->r13 = ADD32(0, 0X204);
    // 0x80408894: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x80408898: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8040889C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x804088A0: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x804088A4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x804088A8: lui         $t6, 0xBB00
    ctx->r14 = S32(0XBB00 << 16);
    // 0x804088AC: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x804088B0: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x804088B4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804088B8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804088BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804088C0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x804088C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804088C8: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x804088CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804088D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804088D4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x804088D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804088DC: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x804088E0: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x804088E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804088E8: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x804088EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804088F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804088F4: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x804088F8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x804088FC: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80408900: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408904: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80408908: lui         $t8, 0x77F
    ctx->r24 = S32(0X77F << 16);
    // 0x8040890C: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x80408910: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408914: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80408918: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8040891C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408920: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80408924: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80408928: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8040892C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80408930: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x80408934: ori         $t7, $t7, 0x1000
    ctx->r15 = ctx->r15 | 0X1000;
    // 0x80408938: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8040893C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80408940: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80408944: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80408948: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x8040894C: ori         $t4, $t4, 0xC0FC
    ctx->r12 = ctx->r12 | 0XC0FC;
    // 0x80408950: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80408954: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80408958: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x8040895C: lw          $a1, 0x16C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X16C);
    // 0x80408960: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80408968: jal         0x804093A8
    // 0x8040896C: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    func_804093A8(rdram, ctx);
        goto after_2;
    // 0x8040896C: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    after_2:
    // 0x80408970: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408974: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x80408978: ori         $a3, $a3, 0x40FF
    ctx->r7 = ctx->r7 | 0X40FF;
    // 0x8040897C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408984: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80408988: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8040898C: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(11, 0X2B90) << 16);
    // 0x80408990: addiu       $a1, $a1, -0x5AA0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(11, 0X2B90));
    // 0x80408994: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408998: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
    // 0x8040899C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x804089A0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804089A4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x804089A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804089AC: addiu       $v1, $s1, 0xE0
    ctx->r3 = ADD32(ctx->r17, 0XE0);
    // 0x804089B0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804089B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804089B8: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x804089BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804089C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804089C4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x804089C8: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x804089CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804089D0: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x804089D4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804089D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804089DC: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x804089E0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x804089E4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x804089E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804089EC: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x804089F0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x804089F4: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
L_804089F8:
    // 0x804089F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804089FC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A00: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80408A04: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80408A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408A0C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408A14: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80408A18: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80408A1C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A20: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x80408A24: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80408A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408A2C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80408A30: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A34: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408A38: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80408A3C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80408A40: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A44: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x80408A48: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80408A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408A50: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80408A54: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408A5C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80408A60: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80408A64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A68: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x80408A6C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80408A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408A74: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80408A78: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80408A7C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80408A80: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80408A84: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408A88: bne         $t0, $t1, L_804089F8
    if (ctx->r8 != ctx->r9) {
        // 0x80408A8C: addiu       $v1, $v1, 0xE0
        ctx->r3 = ADD32(ctx->r3, 0XE0);
            goto L_804089F8;
    }
    // 0x80408A8C: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x80408A90: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80408A94: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80408A98: ori         $t5, $t5, 0x185F
    ctx->r13 = ctx->r13 | 0X185F;
    // 0x80408A9C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408AA0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80408AA4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80408AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408AAC: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X2C08) << 16);
    // 0x80408AB0: addiu       $t6, $t6, -0x5A28
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X2C08));
    // 0x80408AB4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80408AB8: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80408ABC: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80408AC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80408AC4: sw          $s0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r16;
    // 0x80408AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80408ACC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80408AD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80408AD4: jr          $ra
    // 0x80408AD8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80408AD8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80001164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001164: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80001168: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000116C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80001170: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80001174: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80001178: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x8000117C: andi        $t4, $a3, 0xFFFF
    ctx->r12 = ctx->r7 & 0XFFFF;
    // 0x80001180: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80001184: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80001188: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8000118C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80001190: jr          $ra
    // 0x80001194: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    return;
    // 0x80001194: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_807AAD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AAD20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AAD24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AAD28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AAD2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AAD30: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AAD34: jal         0x807A9D84
    // 0x807AAD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A9D84(rdram, ctx);
        goto after_0;
    // 0x807AAD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807AAD3C: jal         0x807AA78C
    // 0x807AAD40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AA78C(rdram, ctx);
        goto after_1;
    // 0x807AAD40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807AAD44: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x807AAD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAD4C: jal         0x807AA878
    // 0x807AAD50: lw          $a1, 0x50($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X50);
    func_807AA878(rdram, ctx);
        goto after_2;
    // 0x807AAD50: lw          $a1, 0x50($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X50);
    after_2:
    // 0x807AAD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAD58: jal         0x807AA908
    // 0x807AAD5C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807AA908(rdram, ctx);
        goto after_3;
    // 0x807AAD5C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x807AAD60: beql        $v0, $zero, L_807AAD8C
    if (ctx->r2 == 0) {
        // 0x807AAD64: lw          $v0, 0xD8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XD8);
            goto L_807AAD8C;
    }
    goto skip_0;
    // 0x807AAD64: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
    skip_0:
    // 0x807AAD68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x807AAD6C: sw          $zero, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = 0;
    // 0x807AAD70: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x807AAD74: jal         0x80067BBC
    // 0x807AAD78: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x807AAD78: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    after_4:
    // 0x807AAD7C: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    // 0x807AAD80: jal         0x80067818
    // 0x807AAD84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x807AAD84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x807AAD88: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_807AAD8C:
    // 0x807AAD8C: beq         $v0, $zero, L_807AADA0
    if (ctx->r2 == 0) {
        // 0x807AAD90: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_807AADA0;
    }
    // 0x807AAD90: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x807AAD94: sw          $t8, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r24;
    // 0x807AAD98: b           L_807AAE8C
    // 0x807AAD9C: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
        goto L_807AAE8C;
    // 0x807AAD9C: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
L_807AADA0:
    // 0x807AADA0: lh          $t9, 0xDC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XDC);
    // 0x807AADA4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C20) << 16);
    // 0x807AADA8: bne         $t9, $zero, L_807AAE28
    if (ctx->r25 != 0) {
        // 0x807AADAC: nop
    
            goto L_807AAE28;
    }
    // 0x807AADAC: nop

    // 0x807AADB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807AADB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807AADB8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C18) << 16);
    // 0x807AADBC: lwc1        $f14, -0x47A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C18));
    // 0x807AADC0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C1C) << 16);
    // 0x807AADC4: lwc1        $f6, -0x47A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C1C));
    // 0x807AADC8: lwc1        $f4, 0xCC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AADCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807AADD0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x807AADD4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AADD8: swc1        $f8, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f8.u32l;
    // 0x807AADDC: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AADE0: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x807AADE4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807AADE8: nop

    // 0x807AADEC: bc1tl       L_807AAE1C
    if (c1cs) {
        // 0x807AADF0: sh          $t0, 0xDC($s0)
        MEM_H(0XDC, ctx->r16) = ctx->r8;
            goto L_807AAE1C;
    }
    goto skip_1;
    // 0x807AADF0: sh          $t0, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = ctx->r8;
    skip_1:
    // 0x807AADF4: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807AADF8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x807AADFC: nop

    // 0x807AAE00: bc1tl       L_807AAE90
    if (c1cs) {
        // 0x807AAE04: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_807AAE90;
    }
    goto skip_2;
    // 0x807AAE04: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    skip_2:
    // 0x807AAE08: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807AAE0C: nop

    // 0x807AAE10: bc1tl       L_807AAE90
    if (c1cs) {
        // 0x807AAE14: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_807AAE90;
    }
    goto skip_3;
    // 0x807AAE14: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    skip_3:
    // 0x807AAE18: sh          $t0, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = ctx->r8;
L_807AAE1C:
    // 0x807AAE1C: sw          $t1, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r9;
    // 0x807AAE20: b           L_807AAE8C
    // 0x807AAE24: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
        goto L_807AAE8C;
    // 0x807AAE24: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
L_807AAE28:
    // 0x807AAE28: lwc1        $f14, -0x47A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C20));
    // 0x807AAE2C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C24) << 16);
    // 0x807AAE30: lwc1        $f18, -0x479C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C24));
    // 0x807AAE34: lwc1        $f16, 0xCC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAE38: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807AAE3C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x807AAE40: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x807AAE44: swc1        $f4, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f4.u32l;
    // 0x807AAE48: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAE4C: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807AAE50: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x807AAE54: nop

    // 0x807AAE58: bc1tl       L_807AAE84
    if (c1cs) {
        // 0x807AAE5C: sh          $zero, 0xDC($s0)
        MEM_H(0XDC, ctx->r16) = 0;
            goto L_807AAE84;
    }
    goto skip_4;
    // 0x807AAE5C: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
    skip_4:
    // 0x807AAE60: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x807AAE64: nop

    // 0x807AAE68: bc1tl       L_807AAE90
    if (c1cs) {
        // 0x807AAE6C: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_807AAE90;
    }
    goto skip_5;
    // 0x807AAE6C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    skip_5:
    // 0x807AAE70: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x807AAE74: nop

    // 0x807AAE78: bc1tl       L_807AAE90
    if (c1cs) {
        // 0x807AAE7C: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_807AAE90;
    }
    goto skip_6;
    // 0x807AAE7C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    skip_6:
    // 0x807AAE80: sh          $zero, 0xDC($s0)
    MEM_H(0XDC, ctx->r16) = 0;
L_807AAE84:
    // 0x807AAE84: sw          $t2, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r10;
    // 0x807AAE88: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
L_807AAE8C:
    // 0x807AAE8C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
L_807AAE90:
    // 0x807AAE90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AAE94: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x807AAE98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807AAE9C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807AAEA0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x807AAEA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807AAEA8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x807AAEAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AAEB0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x807AAEB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807AAEB8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807AAEBC: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x807AAEC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AAEC4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x807AAEC8: swc1        $f8, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f8.u32l;
    // 0x807AAECC: jal         0x807AA96C
    // 0x807AAED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807AA96C(rdram, ctx);
        goto after_6;
    // 0x807AAED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x807AAED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AAED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AAEDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AAEE0: jr          $ra
    // 0x807AAEE4: nop

    return;
    // 0x807AAEE4: nop

;}
RECOMP_FUNC void func_804A50C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A50C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A50C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A50CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A50D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A50D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A50D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A50DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A50E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A50E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A50E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A50EC: jr          $ra
    // 0x804A50F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A50F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044A7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A7AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A7B4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044A7B8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044A7BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A7C0: jal         0x8044A558
    // 0x8044A7C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044A7C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8044A7C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A7CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044A7D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A7D4: bne         $v0, $zero, L_8044A7EC
    if (ctx->r2 != 0) {
        // 0x8044A7D8: nop
    
            goto L_8044A7EC;
    }
    // 0x8044A7D8: nop

    // 0x8044A7DC: jal         0x80445F60
    // 0x8044A7E0: nop

    func_80445F60(rdram, ctx);
        goto after_1;
    // 0x8044A7E0: nop

    after_1:
    // 0x8044A7E4: b           L_8044A810
    // 0x8044A7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A810;
    // 0x8044A7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A7EC:
    // 0x8044A7EC: bne         $v0, $at, L_8044A804
    if (ctx->r2 != ctx->r1) {
        // 0x8044A7F0: nop
    
            goto L_8044A804;
    }
    // 0x8044A7F0: nop

    // 0x8044A7F4: jal         0x80445F98
    // 0x8044A7F8: nop

    func_80445F98(rdram, ctx);
        goto after_2;
    // 0x8044A7F8: nop

    after_2:
    // 0x8044A7FC: b           L_8044A810
    // 0x8044A800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A810;
    // 0x8044A800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A804:
    // 0x8044A804: jal         0x80445FD4
    // 0x8044A808: nop

    func_80445FD4(rdram, ctx);
        goto after_3;
    // 0x8044A808: nop

    after_3:
    // 0x8044A80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A810:
    // 0x8044A810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A814: jr          $ra
    // 0x8044A818: nop

    return;
    // 0x8044A818: nop

;}
RECOMP_FUNC void func_804220FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804220FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80422100: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80422104: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1778) << 16);
    // 0x80422108: lwc1        $f22, 0x2838($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1778));
    // 0x8042210C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80422110: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80422114: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80422118: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8042211C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80422120: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80422124: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80422128: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8042212C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80422130: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80422134: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80422138: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8042213C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80422140: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80422144: lw          $s5, 0x880($a1)
    ctx->r21 = MEM_W(ctx->r5, 0X880);
    // 0x80422148: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8042214C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80422150: addiu       $s7, $zero, 0xF0
    ctx->r23 = ADD32(0, 0XF0);
    // 0x80422154: addiu       $fp, $zero, 0x3FF
    ctx->r30 = ADD32(0, 0X3FF);
    // 0x80422158: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_8042215C:
    // 0x8042215C: addiu       $t6, $s5, -0x30
    ctx->r14 = ADD32(ctx->r21, -0X30);
    // 0x80422160: divu        $zero, $t6, $s7
    lo = S32(U32(ctx->r14) / U32(ctx->r23)); hi = S32(U32(ctx->r14) % U32(ctx->r23));
    // 0x80422164: mfhi        $s5
    ctx->r21 = hi;
    // 0x80422168: addiu       $a0, $zero, 0x40B6
    ctx->r4 = ADD32(0, 0X40B6);
    // 0x8042216C: bne         $s7, $zero, L_80422178
    if (ctx->r23 != 0) {
        // 0x80422170: nop
    
            goto L_80422178;
    }
    // 0x80422170: nop

    // 0x80422174: break       7
    do_break(2151817588);
L_80422178:
    // 0x80422178: jal         0x80047090
    // 0x8042217C: nop

    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8042217C: nop

    after_0:
    // 0x80422180: bne         $fp, $v0, L_80422190
    if (ctx->r30 != ctx->r2) {
        // 0x80422184: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80422190;
    }
    // 0x80422184: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80422188: b           L_80422244
    // 0x8042218C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80422244;
    // 0x8042218C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80422190:
    // 0x80422190: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80422194: lui         $at, 0x40B6
    ctx->r1 = S32(0X40B6 << 16);
    // 0x80422198: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8042219C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x804221A0: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x804221A4: lw          $a2, 0x40($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X40);
    // 0x804221A8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x804221AC: jal         0x8004613C
    // 0x804221B0: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804221B0: nop

    after_1:
    // 0x804221B4: bne         $v0, $zero, L_804221C4
    if (ctx->r2 != 0) {
        // 0x804221B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804221C4;
    }
    // 0x804221B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804221BC: b           L_80422244
    // 0x804221C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80422244;
    // 0x804221C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804221C4:
    // 0x804221C4: jal         0x804215E8
    // 0x804221C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804215E8(rdram, ctx);
        goto after_2;
    // 0x804221C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804221CC: bne         $v0, $zero, L_804221DC
    if (ctx->r2 != 0) {
        // 0x804221D0: addiu       $t7, $s3, 0x10
        ctx->r15 = ADD32(ctx->r19, 0X10);
            goto L_804221DC;
    }
    // 0x804221D0: addiu       $t7, $s3, 0x10
    ctx->r15 = ADD32(ctx->r19, 0X10);
    // 0x804221D4: b           L_80422244
    // 0x804221D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80422244;
    // 0x804221D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804221DC:
    // 0x804221DC: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x804221E0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804221E4: addiu       $t8, $s3, 0x790
    ctx->r24 = ADD32(ctx->r19, 0X790);
    // 0x804221E8: addiu       $t9, $s3, 0x884
    ctx->r25 = ADD32(ctx->r19, 0X884);
    // 0x804221EC: addiu       $t0, $s2, 0x2
    ctx->r8 = ADD32(ctx->r18, 0X2);
    // 0x804221F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804221F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804221F8: sw          $s5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r21;
    // 0x804221FC: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80422200: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x80422204: sw          $s6, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r22;
    // 0x80422208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8042220C: jal         0x80047F9C
    // 0x80422210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80422210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80422214: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80422218: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x8042221C: jal         0x8005FDC4
    // 0x80422220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x80422220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80422224: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80422228: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8042222C: addiu       $s6, $s6, 0x3
    ctx->r22 = ADD32(ctx->r22, 0X3);
    // 0x80422230: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80422234: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80422238: bne         $s2, $at, L_8042215C
    if (ctx->r18 != ctx->r1) {
        // 0x8042223C: add.s       $f20, $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_8042215C;
    }
    // 0x8042223C: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80422240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80422244:
    // 0x80422244: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80422248: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8042224C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80422250: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80422254: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80422258: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8042225C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80422260: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80422264: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80422268: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8042226C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80422270: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80422274: jr          $ra
    // 0x80422278: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80422278: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800581AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800581AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800581B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800581B4: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800581B8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800581BC: blez        $t6, L_800581E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800581C0: nop
    
            goto L_800581E0;
    }
    // 0x800581C0: nop

    // 0x800581C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800581C8:
    // 0x800581C8: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800581CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800581D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800581D4: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800581D8: bnel        $at, $zero, L_800581C8
    if (ctx->r1 != 0) {
        // 0x800581DC: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_800581C8;
    }
    goto skip_0;
    // 0x800581DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_0:
L_800581E0:
    // 0x800581E0: jr          $ra
    // 0x800581E4: nop

    return;
    // 0x800581E4: nop

    // 0x800581E8: nop

    // 0x800581EC: nop

;}
RECOMP_FUNC void func_805154F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805154F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805154FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80515500: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80515504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80515508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051550C: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x80515510: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80515514: jal         0x8002ADE4
    // 0x80515518: sb          $t6, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r14;
    func_8002ADE4(rdram, ctx);
        goto after_0;
    // 0x80515518: sb          $t6, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r14;
    after_0:
    // 0x8051551C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80515524: jr          $ra
    // 0x80515528: nop

    return;
    // 0x80515528: nop

;}
RECOMP_FUNC void func_8001F2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F2DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001F2E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F2E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F2E8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001F2EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8001F2F0: lw          $t7, 0x1A4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1A4);
    // 0x8001F2F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001F2F8: bnel        $t7, $zero, L_8001F464
    if (ctx->r15 != 0) {
        // 0x8001F2FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001F464;
    }
    goto skip_0;
    // 0x8001F2FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8001F300: lbu         $t9, 0x18($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X18);
    // 0x8001F304: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F30C: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8001F310: beq         $at, $zero, L_8001F460
    if (ctx->r1 == 0) {
        // 0x8001F314: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_8001F460;
    }
    // 0x8001F314: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8001F318: lw          $t0, 0x138($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X138);
    // 0x8001F31C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8001F320: addiu       $t4, $t4, -0x66B0
    ctx->r12 = ADD32(ctx->r12, -0X66B0);
    // 0x8001F324: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001F328: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8001F32C: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x8001F330: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    // 0x8001F334: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
L_8001F338:
    // 0x8001F338: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8001F33C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8001F340: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8001F344: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8001F348: sh          $t9, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r25;
    // 0x8001F34C: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x8001F350: andi        $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 & 0XF8;
    // 0x8001F354: bne         $t1, $a0, L_8001F390
    if (ctx->r9 != ctx->r4) {
        // 0x8001F358: nop
    
            goto L_8001F390;
    }
    // 0x8001F358: nop

    // 0x8001F35C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8001F360: jal         0x8003262C
    // 0x8001F364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_8003262C(rdram, ctx);
        goto after_0;
    // 0x8001F364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8001F368: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8001F36C: lw          $t8, -0x7538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7538);
    // 0x8001F370: beq         $t8, $zero, L_8001F380
    if (ctx->r24 == 0) {
        // 0x8001F374: nop
    
            goto L_8001F380;
    }
    // 0x8001F374: nop

    // 0x8001F378: b           L_8001F464
    // 0x8001F37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F380:
    // 0x8001F380: jal         0x8002D34C
    // 0x8001F384: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8002D34C(rdram, ctx);
        goto after_1;
    // 0x8001F384: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8001F388: b           L_8001F464
    // 0x8001F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F390:
    // 0x8001F390: bnel        $t2, $a0, L_8001F458
    if (ctx->r10 != ctx->r4) {
        // 0x8001F394: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001F458;
    }
    goto skip_1;
    // 0x8001F394: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8001F398: lbu         $a2, 0x1($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1);
    // 0x8001F39C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8001F3A0: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8001F3A4: andi        $a2, $a2, 0x3F
    ctx->r6 = ctx->r6 & 0X3F;
    // 0x8001F3A8: beq         $v1, $zero, L_8001F3D8
    if (ctx->r3 == 0) {
        // 0x8001F3AC: andi        $a2, $a2, 0xFF
        ctx->r6 = ctx->r6 & 0XFF;
            goto L_8001F3D8;
    }
    // 0x8001F3AC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001F3B0: beq         $a2, $zero, L_8001F3D8
    if (ctx->r6 == 0) {
        // 0x8001F3B4: sll         $t6, $t6, 3
        ctx->r14 = S32(ctx->r14 << 3);
            goto L_8001F3D8;
    }
    // 0x8001F3B4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001F3B8: beq         $t3, $a2, L_8001F3D8
    if (ctx->r11 == ctx->r6) {
        // 0x8001F3BC: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8001F3D8;
    }
    // 0x8001F3BC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001F3C0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001F3C4: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8001F3C8: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8001F3CC: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x8001F3D0: bnel        $v0, $t6, L_8001F458
    if (ctx->r2 != ctx->r14) {
        // 0x8001F3D4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001F458;
    }
    goto skip_2;
    // 0x8001F3D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
L_8001F3D8:
    // 0x8001F3D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8001F3DC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8001F3E0: jal         0x8003262C
    // 0x8001F3E4: sb          $a2, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r6;
    func_8003262C(rdram, ctx);
        goto after_2;
    // 0x8001F3E4: sb          $a2, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r6;
    after_2:
    // 0x8001F3E8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8001F3EC: lw          $t7, -0x7538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7538);
    // 0x8001F3F0: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001F3F4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8001F3F8: beq         $t7, $zero, L_8001F408
    if (ctx->r15 == 0) {
        // 0x8001F3FC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8001F408;
    }
    // 0x8001F3FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8001F400: b           L_8001F464
    // 0x8001F404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F408:
    // 0x8001F408: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001F40C: jal         0x8002E5E4
    // 0x8001F410: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8002E5E4(rdram, ctx);
        goto after_3;
    // 0x8001F410: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8001F414: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8001F418: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8001F41C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001F420: beq         $v0, $at, L_8001F43C
    if (ctx->r2 == ctx->r1) {
        // 0x8001F424: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8001F43C;
    }
    // 0x8001F424: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8001F428: beql        $v0, $at, L_8001F44C
    if (ctx->r2 == ctx->r1) {
        // 0x8001F42C: sb          $zero, 0x1A8($s0)
        MEM_B(0X1A8, ctx->r16) = 0;
            goto L_8001F44C;
    }
    goto skip_3;
    // 0x8001F42C: sb          $zero, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = 0;
    skip_3:
    // 0x8001F430: sb          $zero, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = 0;
    // 0x8001F434: b           L_8001F464
    // 0x8001F438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F43C:
    // 0x8001F43C: sb          $t9, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = ctx->r25;
    // 0x8001F440: b           L_8001F464
    // 0x8001F444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F448: sb          $zero, 0x1A8($s0)
    MEM_B(0X1A8, ctx->r16) = 0;
L_8001F44C:
    // 0x8001F44C: b           L_8001F464
    // 0x8001F450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F464;
    // 0x8001F450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001F458:
    // 0x8001F458: bne         $v1, $t5, L_8001F338
    if (ctx->r3 != ctx->r13) {
        // 0x8001F45C: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_8001F338;
    }
    // 0x8001F45C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
L_8001F460:
    // 0x8001F460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F464:
    // 0x8001F464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F46C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001F470: jr          $ra
    // 0x8001F474: nop

    return;
    // 0x8001F474: nop

;}
RECOMP_FUNC void func_80427A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427A9C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80427AA0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80427AA4: sb          $v0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r2;
    // 0x80427AA8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80427AAC: sb          $v0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r2;
    // 0x80427AB0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80427AB4: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80427AB8: jr          $ra
    // 0x80427ABC: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    return;
    // 0x80427ABC: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_806CDC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDC08: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x806CDC0C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806CDC10: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x806CDC14: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x806CDC18: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x806CDC1C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x806CDC20: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x806CDC24: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x806CDC28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806CDC2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x806CDC30: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806CDC34: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x806CDC38: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x806CDC3C: bne         $s6, $t6, L_806CDDD8
    if (ctx->r22 != ctx->r14) {
        // 0x806CDC40: addiu       $t7, $zero, 0x4034
        ctx->r15 = ADD32(0, 0X4034);
            goto L_806CDDD8;
    }
    // 0x806CDC40: addiu       $t7, $zero, 0x4034
    ctx->r15 = ADD32(0, 0X4034);
    // 0x806CDC44: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x806CDC48: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x806CDC4C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806CDC50: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806CDC54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CDC58: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x806CDC5C: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806CDC60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806CDC64: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806CDC68: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x806CDC6C: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806CDC70: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x806CDC74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806CDC78: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x806CDC7C: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x806CDC80: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x806CDC84: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x806CDC88: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x806CDC8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x806CDC90: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x806CDC94: jalr        $t9
    // 0x806CDC98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806CDC98: nop

    after_0:
    // 0x806CDC9C: beq         $v0, $zero, L_806CDCB4
    if (ctx->r2 == 0) {
        // 0x806CDCA0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806CDCB4;
    }
    // 0x806CDCA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806CDCA4: lw          $a2, 0x1DC($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X1DC);
    // 0x806CDCA8: lw          $a1, 0x1D8($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X1D8);
    // 0x806CDCAC: jal         0x80048BE8
    // 0x806CDCB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_1;
    // 0x806CDCB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_1:
L_806CDCB4:
    // 0x806CDCB4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806CDCB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CDCBC: lwc1        $f18, 0x84($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X84);
    // 0x806CDCC0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806CDCC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CDCC8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806CDCCC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x806CDCD0: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x806CDCD4: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x806CDCD8: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x806CDCDC: lwc1        $f6, 0x88($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X88);
    // 0x806CDCE0: sh          $v0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r2;
    // 0x806CDCE4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806CDCE8: sh          $v0, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r2;
    // 0x806CDCEC: sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // 0x806CDCF0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x806CDCF4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x806CDCF8: sh          $t3, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r11;
    // 0x806CDCFC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806CDD00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDD04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x806CDD08: jal         0x8006A99C
    // 0x806CDD0C: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x806CDD0C: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x806CDD10: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x806CDD14: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
    // 0x806CDD18: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x806CDD1C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806CDD20: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x806CDD24: nop

    // 0x806CDD28: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDD2C: jal         0x8006A99C
    // 0x806CDD30: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_3;
    // 0x806CDD30: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x806CDD34: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x806CDD38: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x806CDD3C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x806CDD40: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806CDD44: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x806CDD48: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806CDD4C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x806CDD50: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x806CDD54: jal         0x8006AFA0
    // 0x806CDD58: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_8006AFA0(rdram, ctx);
        goto after_4;
    // 0x806CDD58: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_4:
    // 0x806CDD5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806CDD60: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x806CDD64: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x806CDD68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806CDD6C:
    // 0x806CDD6C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x806CDD70: addu        $a0, $s5, $s0
    ctx->r4 = ADD32(ctx->r21, ctx->r16);
    // 0x806CDD74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDD78: beq         $s4, $v0, L_806CDD98
    if (ctx->r20 == ctx->r2) {
        // 0x806CDD7C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_806CDD98;
    }
    // 0x806CDD7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806CDD80: addu        $a1, $s3, $s2
    ctx->r5 = ADD32(ctx->r19, ctx->r18);
    // 0x806CDD84: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x806CDD88: andi        $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 & 0XF800;
    // 0x806CDD8C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806CDD90: jal         0x8006B1C8
    // 0x806CDD94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_5;
    // 0x806CDD94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
L_806CDD98:
    // 0x806CDD98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806CDD9C: bne         $s0, $s6, L_806CDD6C
    if (ctx->r16 != ctx->r22) {
        // 0x806CDDA0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_806CDD6C;
    }
    // 0x806CDDA0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x806CDDA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806CDDA8: bnel        $s2, $s6, L_806CDD6C
    if (ctx->r18 != ctx->r22) {
        // 0x806CDDAC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_806CDD6C;
    }
    goto skip_0;
    // 0x806CDDAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x806CDDB0: jal         0x800447C8
    // 0x806CDDB4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x806CDDB4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_6:
    // 0x806CDDB8: lw          $a0, 0x34($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X34);
    // 0x806CDDBC: jal         0x80067BBC
    // 0x806CDDC0: lw          $a1, 0x38($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x806CDDC0: lw          $a1, 0x38($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X38);
    after_7:
    // 0x806CDDC4: jal         0x80067E68
    // 0x806CDDC8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80067E68(rdram, ctx);
        goto after_8;
    // 0x806CDDC8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_8:
    // 0x806CDDCC: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806CDDD0: jal         0x80067818
    // 0x806CDDD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x806CDDD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_806CDDD8:
    // 0x806CDDD8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x806CDDDC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806CDDE0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806CDDE4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x806CDDE8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x806CDDEC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x806CDDF0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x806CDDF4: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x806CDDF8: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x806CDDFC: jr          $ra
    // 0x806CDE00: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x806CDE00: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80437178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043717C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437180: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437184: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80437188: lbu         $t6, 0xF4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF4);
    // 0x8043718C: bnel        $t6, $zero, L_804371B0
    if (ctx->r14 != 0) {
        // 0x80437190: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804371B0;
    }
    goto skip_0;
    // 0x80437190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80437194: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80437198: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8043719C: beql        $t8, $zero, L_804371B0
    if (ctx->r24 == 0) {
        // 0x804371A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804371B0;
    }
    goto skip_1;
    // 0x804371A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804371A4: jal         0x8002F9D4
    // 0x804371A8: nop

    func_8002F9D4(rdram, ctx);
        goto after_0;
    // 0x804371A8: nop

    after_0:
    // 0x804371AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804371B0:
    // 0x804371B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804371B4: jr          $ra
    // 0x804371B8: nop

    return;
    // 0x804371B8: nop

;}
RECOMP_FUNC void func_80075020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80075024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80075028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007502C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80075030: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80075034: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80075038: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007503C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075040: jal         0x80084820
    // 0x80075044: addiu       $a1, $zero, 0x460
    ctx->r5 = ADD32(0, 0X460);
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80075044: addiu       $a1, $zero, 0x460
    ctx->r5 = ADD32(0, 0X460);
    after_0:
    // 0x80075048: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007504C: addiu       $a3, $s0, 0x58
    ctx->r7 = ADD32(ctx->r16, 0X58);
    // 0x80075050: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80075054: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
    // 0x80075058: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007505C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80075060: jal         0x8008AE20
    // 0x80075064: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80075064: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80075068: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007506C: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x80075070: jal         0x80075120
    // 0x80075074: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    func_80075120(rdram, ctx);
        goto after_2;
    // 0x80075074: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    after_2:
    // 0x80075078: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8007507C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80075080: jal         0x8008AE20
    // 0x80075084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80075084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80075088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007508C: jal         0x8007451C
    // 0x80075090: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8007451C(rdram, ctx);
        goto after_4;
    // 0x80075090: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80075094: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80075098: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x8007509C: jal         0x8008AE20
    // 0x800750A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800750A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800750A4: jal         0x800745B4
    // 0x800750A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800745B4(rdram, ctx);
        goto after_6;
    // 0x800750A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800750AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800750B0: addiu       $a1, $s0, 0x2A8
    ctx->r5 = ADD32(ctx->r16, 0X2A8);
    // 0x800750B4: jal         0x80081AF0
    // 0x800750B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PadSetup_Init(rdram, ctx);
        goto after_7;
    // 0x800750B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800750BC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800750C0: sb          $t7, 0x2A9($s0)
    MEM_B(0X2A9, ctx->r16) = ctx->r15;
    // 0x800750C4: jal         0x8008DC30
    // 0x800750C8: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    osContSetCh_recomp(rdram, ctx);
        goto after_8;
    // 0x800750C8: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    after_8:
    // 0x800750CC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800750D0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800750D4: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x800750D8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800750DC: addiu       $a2, $a2, 0x4E04
    ctx->r6 = ADD32(ctx->r6, 0X4E04);
    // 0x800750E0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800750E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800750E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800750EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800750F0: jal         0x80085B10
    // 0x800750F4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x800750F4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_9:
    // 0x800750F8: jal         0x80090CC0
    // 0x800750FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x800750FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80075100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80075104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80075108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007510C: jr          $ra
    // 0x80075110: nop

    return;
    // 0x80075110: nop

    // 0x80075114: nop

    // 0x80075118: nop

    // 0x8007511C: nop

;}
RECOMP_FUNC void func_80048214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048214: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80048218: lwc1        $f14, 0x8A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X8A4);
    // 0x8004821C: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80048220: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80048224: lwc1        $f2, 0xC8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80048228: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004822C: lwc1        $f12, 0xCC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x80048230: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80048234: bc1tl       L_8004829C
    if (c1cs) {
        // 0x80048238: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_0;
    // 0x80048238: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_0:
    // 0x8004823C: lwc1        $f16, 0x8A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X8A8);
    // 0x80048240: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80048244: nop

    // 0x80048248: bc1tl       L_8004829C
    if (c1cs) {
        // 0x8004824C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_1;
    // 0x8004824C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_1:
    // 0x80048250: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80048254: nop

    // 0x80048258: bc1tl       L_8004829C
    if (c1cs) {
        // 0x8004825C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_2;
    // 0x8004825C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_2:
    // 0x80048260: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80048264: nop

    // 0x80048268: bc1tl       L_8004829C
    if (c1cs) {
        // 0x8004826C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_3;
    // 0x8004826C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_3:
    // 0x80048270: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80048274: nop

    // 0x80048278: bc1tl       L_8004829C
    if (c1cs) {
        // 0x8004827C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_4;
    // 0x8004827C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_4:
    // 0x80048280: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80048284: nop

    // 0x80048288: bc1tl       L_8004829C
    if (c1cs) {
        // 0x8004828C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004829C;
    }
    goto skip_5;
    // 0x8004828C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_5:
    // 0x80048290: jr          $ra
    // 0x80048294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80048294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048298: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_8004829C:
    // 0x8004829C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800482A0: lwc1        $f16, 0x8AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X8AC);
    // 0x800482A4: bc1fl       L_800482B4
    if (!c1cs) {
        // 0x800482A8: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_800482B4;
    }
    goto skip_6;
    // 0x800482A8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_6:
    // 0x800482AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800482B0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_800482B4:
    // 0x800482B4: nop

    // 0x800482B8: bc1fl       L_800482C8
    if (!c1cs) {
        // 0x800482BC: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_800482C8;
    }
    goto skip_7;
    // 0x800482BC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_7:
    // 0x800482C0: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800482C4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_800482C8:
    // 0x800482C8: nop

    // 0x800482CC: bc1fl       L_800482DC
    if (!c1cs) {
        // 0x800482D0: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_800482DC;
    }
    goto skip_8;
    // 0x800482D0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_8:
    // 0x800482D4: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x800482D8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_800482DC:
    // 0x800482DC: nop

    // 0x800482E0: bc1fl       L_800482F0
    if (!c1cs) {
        // 0x800482E4: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_800482F0;
    }
    goto skip_9;
    // 0x800482E4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_9:
    // 0x800482E8: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x800482EC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_800482F0:
    // 0x800482F0: nop

    // 0x800482F4: bc1fl       L_80048304
    if (!c1cs) {
        // 0x800482F8: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80048304;
    }
    goto skip_10;
    // 0x800482F8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_10:
    // 0x800482FC: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80048300: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80048304:
    // 0x80048304: nop

    // 0x80048308: bc1fl       L_80048318
    if (!c1cs) {
        // 0x8004830C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80048318;
    }
    goto skip_11;
    // 0x8004830C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_11:
    // 0x80048310: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80048314: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80048318:
    // 0x80048318: jr          $ra
    // 0x8004831C: nop

    return;
    // 0x8004831C: nop

;}
RECOMP_FUNC void func_8067E32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E32C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8067E330: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(544, 0X10B8) << 16);
    // 0x8067E334: addiu       $t9, $t9, -0x1088
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(544, 0X10B8));
    // 0x8067E338: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067E33C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8067E340: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8067E344: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8067E348: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8067E34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067E350: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E354: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8067E358: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8067E35C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8067E360: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8067E364: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8067E368: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8067E36C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8067E370: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8067E374: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8067E378: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8067E37C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8067E380: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8067E384: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x8067E388: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8067E38C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8067E390: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x8067E394: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8067E398: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8067E39C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8067E3A0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8067E3A4: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x8067E3A8: bnel        $at, $zero, L_8067E3E0
    if (ctx->r1 != 0) {
        // 0x8067E3AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8067E3E0;
    }
    goto skip_0;
    // 0x8067E3AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8067E3B0: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x8067E3B4: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x8067E3B8: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x8067E3BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8067E3C0: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x8067E3C4: bne         $at, $zero, L_8067E3D4
    if (ctx->r1 != 0) {
        // 0x8067E3C8: nop
    
            goto L_8067E3D4;
    }
    // 0x8067E3C8: nop

    // 0x8067E3CC: b           L_8067E3E0
    // 0x8067E3D0: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
        goto L_8067E3E0;
    // 0x8067E3D0: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_8067E3D4:
    // 0x8067E3D4: b           L_8067E3E0
    // 0x8067E3D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8067E3E0;
    // 0x8067E3D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067E3DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067E3E0:
    // 0x8067E3E0: jr          $ra
    // 0x8067E3E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8067E3E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806B252C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B252C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2530: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2534: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2538: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B253C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2540: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2544: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2548: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B254C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2550: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2554: jr          $ra
    // 0x806B2558: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2558: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001B5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B5DC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001B5E0: addiu       $v1, $v1, 0x660
    ctx->r3 = ADD32(ctx->r3, 0X660);
    // 0x8001B5E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B5E8: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
L_8001B5EC:
    // 0x8001B5EC: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B5F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B5F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001B5F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B5FC: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8001B600: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B604: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8001B608: bne         $at, $zero, L_8001B5EC
    if (ctx->r1 != 0) {
        // 0x8001B60C: sw          $zero, 0x40($t7)
        MEM_W(0X40, ctx->r15) = 0;
            goto L_8001B5EC;
    }
    // 0x8001B60C: sw          $zero, 0x40($t7)
    MEM_W(0X40, ctx->r15) = 0;
    // 0x8001B610: jr          $ra
    // 0x8001B614: nop

    return;
    // 0x8001B614: nop

;}
RECOMP_FUNC void func_8000CFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CFA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CFAC: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8000CFB0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x8000CFB4: lw          $t8, 0x20($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X20);
    // 0x8000CFB8: sw          $t8, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r24;
    // 0x8000CFBC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8000CFC0: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    // 0x8000CFC4: lw          $t8, 0x28($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X28);
    // 0x8000CFC8: jr          $ra
    // 0x8000CFCC: sw          $t8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r24;
    return;
    // 0x8000CFCC: sw          $t8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805347F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805347F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805347F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805347F8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x805347FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80534800: beq         $t6, $zero, L_8053483C
    if (ctx->r14 == 0) {
        // 0x80534804: nop
    
            goto L_8053483C;
    }
    // 0x80534804: nop

    // 0x80534808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8053480C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80534810: jalr        $t9
    // 0x80534814: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80534814: nop

    after_0:
    // 0x80534818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8053481C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80534820: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80534824: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80534828: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8053482C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80534830: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80534834: b           L_8053483C
    // 0x80534838: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8053483C;
    // 0x80534838: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8053483C:
    // 0x8053483C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534844: jr          $ra
    // 0x80534848: nop

    return;
    // 0x80534848: nop

;}
RECOMP_FUNC void func_807B3B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3B88: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x807B3B8C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x807B3B90: addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // 0x807B3B94: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x807B3B98: beq         $at, $zero, L_807B3BB8
    if (ctx->r1 == 0) {
        // 0x807B3B9C: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_807B3BB8;
    }
    // 0x807B3B9C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x807B3BA0: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x807B3BA4: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x807B3BA8: lwc1        $f6, 0x6C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x807B3BAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B3BB0: b           L_807B3BCC
    // 0x807B3BB4: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
        goto L_807B3BCC;
    // 0x807B3BB4: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_807B3BB8:
    // 0x807B3BB8: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x807B3BBC: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    // 0x807B3BC0: lwc1        $f16, 0x70($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X70);
    // 0x807B3BC4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B3BC8: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
L_807B3BCC:
    // 0x807B3BCC: lwc1        $f4, 0x70($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X70);
    // 0x807B3BD0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X258) << 16);
    // 0x807B3BD4: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x807B3BD8: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x807B3BDC: lwc1        $f8, 0x3CE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X258));
    // 0x807B3BE0: lwc1        $f6, 0x6C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x807B3BE4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X268) << 16);
    // 0x807B3BE8: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x807B3BEC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B3BF0: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x807B3BF4: lwc1        $f18, 0x3CF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X268));
    // 0x807B3BF8: lwc1        $f16, 0x70($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X70);
    // 0x807B3BFC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B3C00: jr          $ra
    // 0x807B3C04: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x807B3C04: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8003E240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003E244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E248: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x8003E24C: addiu       $t6, $zero, 0x67
    ctx->r14 = ADD32(0, 0X67);
    // 0x8003E250: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E254: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003E258: beq         $t7, $at, L_8003E278
    if (ctx->r15 == ctx->r1) {
        // 0x8003E25C: sb          $t6, 0x18($a0)
        MEM_B(0X18, ctx->r4) = ctx->r14;
            goto L_8003E278;
    }
    // 0x8003E25C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003E260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E264: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8003E268: jal         0x8003D894
    // 0x8003E26C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8003D894(rdram, ctx);
        goto after_0;
    // 0x8003E26C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E270: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8003E278:
    // 0x8003E278: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003E27C: addiu       $t8, $t8, -0x1E40
    ctx->r24 = ADD32(ctx->r24, -0X1E40);
    // 0x8003E280: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8003E284: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003E288: jal         0x8003E120
    // 0x8003E28C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8003E120(rdram, ctx);
        goto after_1;
    // 0x8003E28C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003E290: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003E294: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003E298: lwc1        $f0, 0x23C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X23C);
    // 0x8003E29C: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003E2A0: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003E2A4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E2A8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003E2AC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8003E2B0: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8003E2B4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003E2B8: addiu       $t9, $t9, -0x71F4
    ctx->r25 = ADD32(ctx->r25, -0X71F4);
    // 0x8003E2BC: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8003E2C0: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8003E2C4: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8003E2C8: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8003E2CC: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8003E2D0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8003E2D4: sw          $zero, 0x44($t1)
    MEM_W(0X44, ctx->r9) = 0;
    // 0x8003E2D8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8003E2DC: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
    // 0x8003E2E0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003E2E4: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x8003E2E8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003E2EC: jal         0x8005FE48
    // 0x8003E2F0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8003E2F0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    after_2:
    // 0x8003E2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E2F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E2FC: jr          $ra
    // 0x8003E300: nop

    return;
    // 0x8003E300: nop

;}
RECOMP_FUNC void func_807AA96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA96C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AA970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AA974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AA978: lw          $t6, 0xF0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XF0);
    // 0x807AA97C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807AA980: beql        $t6, $zero, L_807AAA04
    if (ctx->r14 == 0) {
        // 0x807AA984: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AAA04;
    }
    goto skip_0;
    // 0x807AA984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807AA988: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807AA98C: lwc1        $f8, 0xC4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x807AA990: swc1        $f4, 0xCC($a1)
    MEM_W(0XCC, ctx->r5) = ctx->f4.u32l;
    // 0x807AA994: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807AA998: swc1        $f8, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->f8.u32l;
    // 0x807AA99C: swc1        $f6, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f6.u32l;
    // 0x807AA9A0: jal         0x8005FD1C
    // 0x807AA9A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x807AA9A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x807AA9A8: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x807AA9AC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x807AA9B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AA9B4: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x807AA9B8: jal         0x8005FD1C
    // 0x807AA9BC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x807AA9BC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_1:
    // 0x807AA9C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x807AA9C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x807AA9C8: lw          $t0, 0x174($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X174);
    // 0x807AA9CC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x807AA9D0: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x807AA9D4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x807AA9D8: jal         0x80067BBC
    // 0x807AA9DC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x807AA9DC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x807AA9E0: addiu       $a0, $zero, 0x26C
    ctx->r4 = ADD32(0, 0X26C);
    // 0x807AA9E4: jal         0x80067818
    // 0x807AA9E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807AA9E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807AA9EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AA9F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AA9F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807AA9F8: jal         0x807AB278
    // 0x807AA9FC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_807AB278(rdram, ctx);
        goto after_4;
    // 0x807AA9FC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x807AAA00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AAA04:
    // 0x807AAA04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AAA08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AAA0C: jr          $ra
    // 0x807AAA10: nop

    return;
    // 0x807AAA10: nop

;}
RECOMP_FUNC void func_8005D518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D51C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005D520: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x8005D524: addiu       $s2, $s2, -0x7DC8
    ctx->r18 = ADD32(ctx->r18, -0X7DC8);
    // 0x8005D528: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D52C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8005D530: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005D534: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D538: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D53C: addiu       $a1, $a1, -0x7C20
    ctx->r5 = ADD32(ctx->r5, -0X7C20);
    // 0x8005D540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005D544: jal         0x80058110
    // 0x8005D548: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80058110(rdram, ctx);
        goto after_0;
    // 0x8005D548: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8005D54C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005D550: addiu       $a0, $a0, -0x7DB0
    ctx->r4 = ADD32(ctx->r4, -0X7DB0);
    // 0x8005D554: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x8005D558: jal         0x80065728
    // 0x8005D55C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8005D55C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005D560: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x8005D564: addiu       $s1, $s1, -0x7DB0
    ctx->r17 = ADD32(ctx->r17, -0X7DB0);
    // 0x8005D568: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005D56C: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_8005D570:
    // 0x8005D570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005D574: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005D578: jal         0x80057B28
    // 0x8005D57C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80057B28(rdram, ctx);
        goto after_2;
    // 0x8005D57C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x8005D580: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005D584: bne         $s0, $s3, L_8005D570
    if (ctx->r16 != ctx->r19) {
        // 0x8005D588: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_8005D570;
    }
    // 0x8005D588: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x8005D58C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005D590: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D594: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D598: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D59C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005D5A0: jr          $ra
    // 0x8005D5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8044DB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DB30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044DB34: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8044DB38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044DB3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044DB40: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044DB44: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044DB48: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044DB4C: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x8044DB50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044DB54: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044DB58: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x8044DB5C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044DB60: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8044DB64: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8044DB68: beq         $t9, $zero, L_8044DBAC
    if (ctx->r25 == 0) {
        // 0x8044DB6C: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8044DBAC;
    }
    // 0x8044DB6C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8044DB70: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8044DB74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044DB78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044DB7C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8044DB80: addu        $a1, $t4, $a1
    ctx->r5 = ADD32(ctx->r12, ctx->r5);
    // 0x8044DB84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044DB88: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8044DB8C: jal         0x8044D1F4
    // 0x8044DB90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044DB90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8044DB94: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044DB98: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8044DB9C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8044DBA0: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8044DBA4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8044DBA8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8044DBAC:
    // 0x8044DBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044DBB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044DBB4: jr          $ra
    // 0x8044DBB8: nop

    return;
    // 0x8044DBB8: nop

;}
RECOMP_FUNC void func_805A27E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A27E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A27EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A27F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A27F4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A27F8: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x805A27FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A2800: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805A2804: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x805A2808: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x805A280C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x805A2810: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x805A2814: jal         0x80045A34
    // 0x805A2818: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A2818: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A281C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805A2820: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805A2824: bne         $v0, $zero, L_805A283C
    if (ctx->r2 != 0) {
        // 0x805A2828: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_805A283C;
    }
    // 0x805A2828: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A282C: jal         0x800445A4
    // 0x805A2830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805A2830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A2834: b           L_805A29DC
    // 0x805A2838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A29DC;
    // 0x805A2838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A283C:
    // 0x805A283C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x805A2840: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1D48) << 16);
    // 0x805A2844: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805A2848: addiu       $t8, $t8, 0x30B8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(411, 0X1D48));
    // 0x805A284C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805A2850: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A2854: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x805A2858: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x805A285C: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x805A2860: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805A2864: sw          $t0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r8;
    // 0x805A2868: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x805A286C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x805A2870: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x805A2874: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x805A2878: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A287C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x805A2880: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x805A2884: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x805A2888: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x805A288C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805A2890: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x805A2894: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A2898: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
    // 0x805A289C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x805A28A0: beq         $v1, $zero, L_805A296C
    if (ctx->r3 == 0) {
        // 0x805A28A4: swc1        $f8, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
            goto L_805A296C;
    }
    // 0x805A28A4: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x805A28A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A28AC: beq         $v1, $at, L_805A28D4
    if (ctx->r3 == ctx->r1) {
        // 0x805A28B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A28D4;
    }
    // 0x805A28B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A28B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805A28B8: beq         $v1, $at, L_805A2908
    if (ctx->r3 == ctx->r1) {
        // 0x805A28BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A2908;
    }
    // 0x805A28BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A28C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A28C4: beq         $v1, $at, L_805A2938
    if (ctx->r3 == ctx->r1) {
        // 0x805A28C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A2938;
    }
    // 0x805A28C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A28CC: b           L_805A2994
    // 0x805A28D0: nop

        goto L_805A2994;
    // 0x805A28D0: nop

L_805A28D4:
    // 0x805A28D4: jal         0x8004590C
    // 0x805A28D8: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x805A28D8: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    after_2:
    // 0x805A28DC: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x805A28E0: addiu       $t2, $zero, 0x2242
    ctx->r10 = ADD32(0, 0X2242);
    // 0x805A28E4: addiu       $t5, $zero, 0x2244
    ctx->r13 = ADD32(0, 0X2244);
    // 0x805A28E8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805A28EC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x805A28F0: sh          $t2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r10;
    // 0x805A28F4: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x805A28F8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805A28FC: sh          $t5, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r13;
    // 0x805A2900: b           L_805A2994
    // 0x805A2904: sw          $t8, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r24;
        goto L_805A2994;
    // 0x805A2904: sw          $t8, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r24;
L_805A2908:
    // 0x805A2908: jal         0x8004590C
    // 0x805A290C: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x805A290C: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    after_3:
    // 0x805A2910: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x805A2914: addiu       $t9, $zero, 0x4222
    ctx->r25 = ADD32(0, 0X4222);
    // 0x805A2918: addiu       $t3, $zero, 0x2244
    ctx->r11 = ADD32(0, 0X2244);
    // 0x805A291C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805A2920: sh          $t9, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r25;
    // 0x805A2924: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x805A2928: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x805A292C: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    // 0x805A2930: b           L_805A2994
    // 0x805A2934: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_805A2994;
    // 0x805A2934: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_805A2938:
    // 0x805A2938: jal         0x8004590C
    // 0x805A293C: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x805A293C: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    after_4:
    // 0x805A2940: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805A2944: addiu       $t6, $zero, 0x2224
    ctx->r14 = ADD32(0, 0X2224);
    // 0x805A2948: addiu       $t8, $zero, 0x4244
    ctx->r24 = ADD32(0, 0X4244);
    // 0x805A294C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x805A2950: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x805A2954: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x805A2958: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x805A295C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x805A2960: sh          $t8, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = ctx->r24;
    // 0x805A2964: b           L_805A2994
    // 0x805A2968: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
        goto L_805A2994;
    // 0x805A2968: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
L_805A296C:
    // 0x805A296C: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x805A2970: addiu       $t2, $zero, 0x2422
    ctx->r10 = ADD32(0, 0X2422);
    // 0x805A2974: addiu       $t5, $zero, 0x2444
    ctx->r13 = ADD32(0, 0X2444);
    // 0x805A2978: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805A297C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805A2980: sh          $t2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r10;
    // 0x805A2984: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x805A2988: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805A298C: sh          $t5, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r13;
    // 0x805A2990: sw          $t0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r8;
L_805A2994:
    // 0x805A2994: jal         0x8005FD1C
    // 0x805A2998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_5;
    // 0x805A2998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805A299C: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805A29A0: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(411, 0X9A0) << 16);
    // 0x805A29A4: addiu       $t1, $t1, 0x1D10
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(411, 0X9A0));
    // 0x805A29A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805A29AC: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x805A29B0: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x805A29B4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805A29B8: jal         0x80067BBC
    // 0x805A29BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x805A29BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x805A29C0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x805A29C4: jal         0x80067F78
    // 0x805A29C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_7;
    // 0x805A29C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x805A29CC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x805A29D0: jal         0x805A1B90
    // 0x805A29D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1B90(rdram, ctx);
        goto after_8;
    // 0x805A29D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x805A29D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A29DC:
    // 0x805A29DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A29E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A29E4: jr          $ra
    // 0x805A29E8: nop

    return;
    // 0x805A29E8: nop

;}
RECOMP_FUNC void func_807800BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807800BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807800C0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x807800C4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807800C8: lui         $t7, 0x8078
    ctx->r15 = S32(RELOC_HI16(781, 0X7E8) << 16);
    // 0x807800CC: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x807800D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807800D4: lw          $t7, 0xF8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(781, 0X7E8));
    // 0x807800D8: jr          $ra
    // 0x807800DC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x807800DC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8005B10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B10C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B114: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005B118: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005B11C: jal         0x800648DC
    // 0x8005B120: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800648DC(rdram, ctx);
        goto after_0;
    // 0x8005B120: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8005B124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B12C: jr          $ra
    // 0x8005B130: nop

    return;
    // 0x8005B130: nop

;}
RECOMP_FUNC void func_8006E57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E584: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E588: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006E58C: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8006E590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006E594: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006E598: lbu         $t7, 0xA8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA8);
    // 0x8006E59C: bnel        $t7, $at, L_8006E5B8
    if (ctx->r15 != ctx->r1) {
        // 0x8006E5A0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8006E5B8;
    }
    goto skip_0;
    // 0x8006E5A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8006E5A4: jal         0x8006E2B0
    // 0x8006E5A8: nop

    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E5A8: nop

    after_0:
    // 0x8006E5AC: b           L_8006E5D0
    // 0x8006E5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006E5D0;
    // 0x8006E5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E5B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8006E5B8:
    // 0x8006E5B8: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    // 0x8006E5BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006E5C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006E5C4: jal         0x800504D0
    // 0x8006E5C8: nop

    func_800504D0(rdram, ctx);
        goto after_1;
    // 0x8006E5C8: nop

    after_1:
    // 0x8006E5CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E5D0:
    // 0x8006E5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E5D4: jr          $ra
    // 0x8006E5D8: nop

    return;
    // 0x8006E5D8: nop

;}
RECOMP_FUNC void func_8046523C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046523C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465244: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465248: sw          $zero, 0x1F18($v0)
    MEM_W(0X1F18, ctx->r2) = 0;
    // 0x8046524C: sw          $zero, 0x1F1C($v0)
    MEM_W(0X1F1C, ctx->r2) = 0;
    // 0x80465250: jal         0x804650B4
    // 0x80465254: sw          $zero, 0x1F20($v0)
    MEM_W(0X1F20, ctx->r2) = 0;
    func_804650B4(rdram, ctx);
        goto after_0;
    // 0x80465254: sw          $zero, 0x1F20($v0)
    MEM_W(0X1F20, ctx->r2) = 0;
    after_0:
    // 0x80465258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046525C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80465260: jr          $ra
    // 0x80465264: nop

    return;
    // 0x80465264: nop

;}
RECOMP_FUNC void func_8041EBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041EBA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041EBA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041EBA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041EBAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041EBB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041EBB4: jal         0x8041DB1C
    // 0x8041EBB8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041EBB8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8041EBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EBC0: jal         0x8041E9A8
    // 0x8041EBC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041EBC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041EBC8: beql        $v0, $zero, L_8041ECBC
    if (ctx->r2 == 0) {
        // 0x8041EBCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041ECBC;
    }
    goto skip_0;
    // 0x8041EBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041EBD0: jal         0x8041E564
    // 0x8041EBD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8041E564(rdram, ctx);
        goto after_2;
    // 0x8041EBD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8041EBD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8041EBDC: bnel        $v0, $at, L_8041EC28
    if (ctx->r2 != ctx->r1) {
        // 0x8041EBE0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8041EC28;
    }
    goto skip_1;
    // 0x8041EBE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8041EBE4: jal         0x800653D8
    // 0x8041EBE8: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x8041EBE8: nop

    after_3:
    // 0x8041EBEC: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8041EBF0: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x8041EBF4: addiu       $t8, $t7, 0x3C
    ctx->r24 = ADD32(ctx->r15, 0X3C);
    // 0x8041EBF8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8041EBFC: sh          $t8, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r24;
    // 0x8041EC00: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8041EC04: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8041EC08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EC10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EC14: jal         0x8041FE10
    // 0x8041EC18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8041FE10(rdram, ctx);
        goto after_4;
    // 0x8041EC18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8041EC1C: b           L_8041ECA4
    // 0x8041EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8041ECA4;
    // 0x8041EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EC24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8041EC28:
    // 0x8041EC28: bnel        $v0, $at, L_8041ECA4
    if (ctx->r2 != ctx->r1) {
        // 0x8041EC2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041ECA4;
    }
    goto skip_2;
    // 0x8041EC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8041EC30: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8041EC34: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3504) << 16);
    // 0x8041EC38: lwc1        $f10, 0xB64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3504));
    // 0x8041EC3C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8041EC40: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8041EC44: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8041EC48: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x8041EC4C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8041EC50: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8041EC54: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(29, 0X32EC) << 16);
    // 0x8041EC58: addiu       $t2, $t2, 0x94C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(29, 0X32EC));
    // 0x8041EC5C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8041EC60: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8041EC64: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x8041EC68: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8041EC6C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8041EC70: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x8041EC74: lw          $t9, 0x74($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X74);
    // 0x8041EC78: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8041EC7C: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x8041EC80: jalr        $t9
    // 0x8041EC84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8041EC84: nop

    after_5:
    // 0x8041EC88: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8041EC8C: jal         0x80067BBC
    // 0x8041EC90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8041EC90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8041EC94: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8041EC98: jal         0x80067818
    // 0x8041EC9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8041EC9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8041ECA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8041ECA4:
    // 0x8041ECA4: jal         0x8041E430
    // 0x8041ECA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_8;
    // 0x8041ECA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x8041ECAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041ECB0: jal         0x8041E7D4
    // 0x8041ECB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_9;
    // 0x8041ECB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x8041ECB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041ECBC:
    // 0x8041ECBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041ECC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041ECC4: jr          $ra
    // 0x8041ECC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041ECC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8040B5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B5EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B5F0: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(14, 0X1344) << 16);
    // 0x8040B5F4: addiu       $v0, $v0, -0x415C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(14, 0X1344));
    // 0x8040B5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B5FC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8040B600: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8040B604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040B608: jalr        $t9
    // 0x8040B60C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040B60C: nop

    after_0:
    // 0x8040B610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B614: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8040B618: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8040B61C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8040B620: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8040B624: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8040B628: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8040B62C: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x8040B630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B638: jr          $ra
    // 0x8040B63C: nop

    return;
    // 0x8040B63C: nop

;}
RECOMP_FUNC void func_8057BFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BFE8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8057BFEC: beq         $v0, $zero, L_8057C0B4
    if (ctx->r2 == 0) {
        // 0x8057BFF0: nop
    
            goto L_8057C0B4;
    }
    // 0x8057BFF0: nop

    // 0x8057BFF4: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8057BFF8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057BFFC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8057C000: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057C004: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057C008: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8057C00C: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057C010: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8057C014: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8057C018: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8057C01C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057C020: bc1fl       L_8057C034
    if (!c1cs) {
        // 0x8057C024: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8057C034;
    }
    goto skip_0;
    // 0x8057C024: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8057C028: b           L_8057C04C
    // 0x8057C02C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8057C04C;
    // 0x8057C02C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8057C030: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8057C034:
    // 0x8057C034: nop

    // 0x8057C038: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8057C03C: nop

    // 0x8057C040: bc1fl       L_8057C050
    if (!c1cs) {
        // 0x8057C044: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8057C050;
    }
    goto skip_1;
    // 0x8057C044: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_1:
    // 0x8057C048: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8057C04C:
    // 0x8057C04C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_8057C050:
    // 0x8057C050: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057C054: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x8057C058: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8057C05C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8057C060: nop

    // 0x8057C064: bc1fl       L_8057C078
    if (!c1cs) {
        // 0x8057C068: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8057C078;
    }
    goto skip_2;
    // 0x8057C068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x8057C06C: b           L_8057C090
    // 0x8057C070: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8057C090;
    // 0x8057C070: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8057C074: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8057C078:
    // 0x8057C078: nop

    // 0x8057C07C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8057C080: nop

    // 0x8057C084: bc1fl       L_8057C094
    if (!c1cs) {
        // 0x8057C088: lwc1        $f16, 0xC8($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8057C094;
    }
    goto skip_3;
    // 0x8057C088: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    skip_3:
    // 0x8057C08C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8057C090:
    // 0x8057C090: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
L_8057C094:
    // 0x8057C094: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x8057C098: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0X1010) << 16);
    // 0x8057C09C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8057C0A0: nop

    // 0x8057C0A4: bc1f        L_8057C0B4
    if (!c1cs) {
        // 0x8057C0A8: nop
    
            goto L_8057C0B4;
    }
    // 0x8057C0A8: nop

    // 0x8057C0AC: lwc1        $f4, -0x34E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0X1010));
    // 0x8057C0B0: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
L_8057C0B4:
    // 0x8057C0B4: jr          $ra
    // 0x8057C0B8: nop

    return;
    // 0x8057C0B8: nop

;}
RECOMP_FUNC void func_80434380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80434384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80434388: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043438C: jal         0x80433C0C
    // 0x80434390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80433C0C(rdram, ctx);
        goto after_0;
    // 0x80434390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80434394: jal         0x80433BD8
    // 0x80434398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433BD8(rdram, ctx);
        goto after_1;
    // 0x80434398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043439C: jal         0x80433D20
    // 0x804343A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433D20(rdram, ctx);
        goto after_2;
    // 0x804343A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804343A4: jal         0x80433E8C
    // 0x804343A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433E8C(rdram, ctx);
        goto after_3;
    // 0x804343A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804343AC: jal         0x8043409C
    // 0x804343B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043409C(rdram, ctx);
        goto after_4;
    // 0x804343B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804343B4: jal         0x80434164
    // 0x804343B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434164(rdram, ctx);
        goto after_5;
    // 0x804343B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804343BC: jal         0x80434120
    // 0x804343C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434120(rdram, ctx);
        goto after_6;
    // 0x804343C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804343C4: beq         $v0, $zero, L_804343DC
    if (ctx->r2 == 0) {
        // 0x804343C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804343DC;
    }
    // 0x804343C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804343CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804343D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804343D4: jal         0x80434634
    // 0x804343D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80434634(rdram, ctx);
        goto after_7;
    // 0x804343D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_804343DC:
    // 0x804343DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804343E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804343E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804343E8: jr          $ra
    // 0x804343EC: nop

    return;
    // 0x804343EC: nop

;}
RECOMP_FUNC void func_804344E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804344E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804344E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804344E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804344EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804344F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804344F4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804344F8: addiu       $t7, $v0, 0x3D0
    ctx->r15 = ADD32(ctx->r2, 0X3D0);
    // 0x804344FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80434500: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80434504: jal         0x80434490
    // 0x80434508: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80434490(rdram, ctx);
        goto after_0;
    // 0x80434508: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043450C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80434510: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80434514: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(71, 0X990) << 16);
    // 0x80434518: sw          $t8, 0x7A0($v0)
    MEM_W(0X7A0, ctx->r2) = ctx->r24;
    // 0x8043451C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80434520: addiu       $t9, $t9, 0x4440
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(71, 0X990));
    // 0x80434524: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x80434528: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x8043452C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80434534: jr          $ra
    // 0x80434538: nop

    return;
    // 0x80434538: nop

;}
