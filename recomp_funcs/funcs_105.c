#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80741640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80741644: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80741648: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8074164C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80741650: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80741654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80741658: jal         0x80740EE0
    // 0x8074165C: lw          $s1, 0x1F4($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X1F4);
    func_80740EE0(rdram, ctx);
        goto after_0;
    // 0x8074165C: lw          $s1, 0x1F4($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X1F4);
    after_0:
    // 0x80741660: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80741664: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80741668: sltiu       $at, $t7, 0x23
    ctx->r1 = ctx->r15 < 0X23 ? 1 : 0;
    // 0x8074166C: bnel        $at, $zero, L_8074178C
    if (ctx->r1 != 0) {
        // 0x80741670: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8074178C;
    }
    goto skip_0;
    // 0x80741670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80741674: lbu         $t8, -0x71F5($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X71F5);
    // 0x80741678: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8074167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741680: bne         $v0, $t8, L_807416AC
    if (ctx->r2 != ctx->r24) {
        // 0x80741684: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807416AC;
    }
    // 0x80741684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80741688: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x8074168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741690: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80741694: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x80741698: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8074169C: jal         0x80741E44
    // 0x807416A0: sw          $v0, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r2;
    func_80741E44(rdram, ctx);
        goto after_1;
    // 0x807416A0: sw          $v0, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r2;
    after_1:
    // 0x807416A4: b           L_8074178C
    // 0x807416A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8074178C;
    // 0x807416A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807416AC:
    // 0x807416AC: jal         0x80741E44
    // 0x807416B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80741E44(rdram, ctx);
        goto after_2;
    // 0x807416B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x807416B4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x807416B8: lw          $t1, -0x720C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X720C);
    // 0x807416BC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x807416C0: beq         $t2, $zero, L_80741754
    if (ctx->r10 == 0) {
        // 0x807416C4: nop
    
            goto L_80741754;
    }
    // 0x807416C4: nop

    // 0x807416C8: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x807416CC: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x807416D0: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x807416D4: beq         $t3, $zero, L_807416F4
    if (ctx->r11 == 0) {
        // 0x807416D8: lui         $a2, 0x41A0
        ctx->r6 = S32(0X41A0 << 16);
            goto L_807416F4;
    }
    // 0x807416D8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x807416DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807416E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x807416E4: jal         0x80741E44
    // 0x807416E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80741E44(rdram, ctx);
        goto after_3;
    // 0x807416E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x807416EC: b           L_8074178C
    // 0x807416F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8074178C;
    // 0x807416F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807416F4:
    // 0x807416F4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11F0) << 16);
    // 0x807416F8: lwc1        $f4, 0x2050($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11F0));
    // 0x807416FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80741700: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80741704: jal         0x8005CEBC
    // 0x80741708: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x80741708: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8074170C: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    // 0x80741710: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x80741714: jal         0x80047F9C
    // 0x80741718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80741718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8074171C: lw          $t5, 0x3C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X3C);
    // 0x80741720: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80741724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741728: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8074172C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80741730: jal         0x80741E44
    // 0x80741734: sb          $t4, 0x31($t5)
    MEM_B(0X31, ctx->r13) = ctx->r12;
    func_80741E44(rdram, ctx);
        goto after_6;
    // 0x80741734: sb          $t4, 0x31($t5)
    MEM_B(0X31, ctx->r13) = ctx->r12;
    after_6:
    // 0x80741738: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x8074173C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741740: jal         0x80741E44
    // 0x80741744: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80741E44(rdram, ctx);
        goto after_7;
    // 0x80741744: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80741748: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8074174C: b           L_80741788
    // 0x80741750: sw          $t6, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r14;
        goto L_80741788;
    // 0x80741750: sw          $t6, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r14;
L_80741754:
    // 0x80741754: jal         0x80068D24
    // 0x80741758: nop

    func_80068D24(rdram, ctx);
        goto after_8;
    // 0x80741758: nop

    after_8:
    // 0x8074175C: lui         $a0, 0x4672
    ctx->r4 = S32(0X4672 << 16);
    // 0x80741760: lui         $a3, 0xBD4C
    ctx->r7 = S32(0XBD4C << 16);
    // 0x80741764: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80741768: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8074176C: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x80741770: jal         0x8004613C
    // 0x80741774: lui         $a2, 0xC2B8
    ctx->r6 = S32(0XC2B8 << 16);
    func_8004613C(rdram, ctx);
        goto after_9;
    // 0x80741774: lui         $a2, 0xC2B8
    ctx->r6 = S32(0XC2B8 << 16);
    after_9:
    // 0x80741778: sw          $v0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r2;
    // 0x8074177C: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x80741780: jal         0x80047F9C
    // 0x80741784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x80741784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_80741788:
    // 0x80741788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8074178C:
    // 0x8074178C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80741790: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80741794: jr          $ra
    // 0x80741798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80741798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80052B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052B0C: jal         0x800528A8
    // 0x80052B10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800528A8(rdram, ctx);
        goto after_0;
    // 0x80052B10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80052B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80052B18: bne         $v0, $zero, L_80052B28
    if (ctx->r2 != 0) {
        // 0x80052B1C: sw          $v0, 0x174($a0)
        MEM_W(0X174, ctx->r4) = ctx->r2;
            goto L_80052B28;
    }
    // 0x80052B1C: sw          $v0, 0x174($a0)
    MEM_W(0X174, ctx->r4) = ctx->r2;
    // 0x80052B20: b           L_80052B4C
    // 0x80052B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052B4C;
    // 0x80052B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052B28:
    // 0x80052B28: jal         0x80052AA4
    // 0x80052B2C: nop

    func_80052AA4(rdram, ctx);
        goto after_1;
    // 0x80052B2C: nop

    after_1:
    // 0x80052B30: bnel        $v0, $zero, L_80052B4C
    if (ctx->r2 != 0) {
        // 0x80052B34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80052B4C;
    }
    goto skip_0;
    // 0x80052B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80052B38: jal         0x800528C8
    // 0x80052B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800528C8(rdram, ctx);
        goto after_2;
    // 0x80052B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80052B40: b           L_80052B4C
    // 0x80052B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052B4C;
    // 0x80052B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052B4C:
    // 0x80052B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052B54: jr          $ra
    // 0x80052B58: nop

    return;
    // 0x80052B58: nop

;}
RECOMP_FUNC void func_804472A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804472A0: jr          $ra
    // 0x804472A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804472A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8069C994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C994: jr          $ra
    // 0x8069C998: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8069C998: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8040CD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CD58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040CD5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040CD60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040CD64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8040CD68: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F04) << 16);
    // 0x8040CD6C: lwc1        $f6, -0x1AFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F04));
    // 0x8040CD70: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8040CD74: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8040CD78: lwc1        $f14, 0x40($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8040CD7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8040CD80: lwc1        $f12, 0x3C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040CD84: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8040CD88: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8040CD8C: jal         0x8003BA24
    // 0x8040CD90: nop

    func_8003BA24(rdram, ctx);
        goto after_0;
    // 0x8040CD90: nop

    after_0:
    // 0x8040CD94: beq         $v0, $zero, L_8040CE6C
    if (ctx->r2 == 0) {
        // 0x8040CD98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8040CE6C;
    }
    // 0x8040CD98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8040CD9C: jal         0x8004700C
    // 0x8040CDA0: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8040CDA0: nop

    after_1:
    // 0x8040CDA4: beq         $v0, $zero, L_8040CDD4
    if (ctx->r2 == 0) {
        // 0x8040CDA8: lui         $at, 0x8041
        ctx->r1 = S32(RELOC_HI16(20, 0X1F08) << 16);
            goto L_8040CDD4;
    }
    // 0x8040CDA8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F08) << 16);
    // 0x8040CDAC: lwc1        $f0, -0x1AF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F08));
    // 0x8040CDB0: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8040CDB4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8040CDB8: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x8040CDBC: lwc1        $f18, 0x70($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8040CDC0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8040CDC4: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8040CDC8: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8040CDCC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8040CDD0: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
L_8040CDD4:
    // 0x8040CDD4: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8040CDD8: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040CDDC: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8040CDE0: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8040CDE4: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x8040CDE8: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    // 0x8040CDEC: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8040CDF0: jal         0x800653D8
    // 0x8040CDF4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8040CDF4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8040CDF8: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8040CDFC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8040CE00: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8040CE04: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8040CE08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040CE0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8040CE10: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040CE14: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8040CE18: jal         0x80066DE4
    // 0x8040CE1C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8040CE1C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8040CE20: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8040CE24: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8040CE28: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8040CE2C: jal         0x80066E88
    // 0x8040CE30: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8040CE30: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8040CE34: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8040CE38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040CE3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040CE40: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040CE44: jal         0x80044194
    // 0x8040CE48: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x8040CE48: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x8040CE4C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8040CE50: jal         0x80067BBC
    // 0x8040CE54: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8040CE54: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x8040CE58: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    // 0x8040CE5C: jal         0x80067818
    // 0x8040CE60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8040CE60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8040CE64: b           L_8040CE88
    // 0x8040CE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040CE88;
    // 0x8040CE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040CE6C:
    // 0x8040CE6C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8040CE70: jal         0x80067BBC
    // 0x8040CE74: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x8040CE74: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_8:
    // 0x8040CE78: addiu       $a0, $zero, 0x215
    ctx->r4 = ADD32(0, 0X215);
    // 0x8040CE7C: jal         0x80067818
    // 0x8040CE80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8040CE80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8040CE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040CE88:
    // 0x8040CE88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8040CE8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8040CE90: jr          $ra
    // 0x8040CE94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8040CE94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804D88E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D88E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D88E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D88EC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804D88F0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804D88F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804D88F8: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(255, 0X87C) << 16);
    // 0x804D88FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D8900: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804D8904: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804D8908: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804D890C: lw          $t8, -0x7454($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(255, 0X87C));
    // 0x804D8910: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804D8914: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804D8918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D891C: jal         0x80048490
    // 0x804D8920: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804D8920: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804D8924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D8928: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804D892C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804D8930: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804D8934: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804D8938: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804D893C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x804D8940: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804D8944: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804D8948: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x804D894C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D8954: jr          $ra
    // 0x804D8958: nop

    return;
    // 0x804D8958: nop

;}
RECOMP_FUNC void func_807155F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807155F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807155FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715600: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80715604: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80715608: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(730, 0X1548) << 16);
    // 0x8071560C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80715610: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80715614: addiu       $t7, $t7, 0x5D68
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(730, 0X1548));
    // 0x80715618: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8071561C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80715620: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80715624: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80715628: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8071562C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80715630: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80715634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80715638: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8071563C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80715640: jal         0x80048378
    // 0x80715644: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80715644: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80715648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8071564C: jal         0x80045A34
    // 0x80715650: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80715650: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    after_1:
    // 0x80715654: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80715658: bne         $v0, $zero, L_80715670
    if (ctx->r2 != 0) {
        // 0x8071565C: sw          $v0, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = ctx->r2;
            goto L_80715670;
    }
    // 0x8071565C: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x80715660: jal         0x800445A4
    // 0x80715664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80715664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80715668: b           L_8071567C
    // 0x8071566C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8071567C;
    // 0x8071566C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80715670:
    // 0x80715670: lw          $t1, 0x1F4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1F4);
    // 0x80715674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80715678: sh          $zero, 0x5FE($t1)
    MEM_H(0X5FE, ctx->r9) = 0;
L_8071567C:
    // 0x8071567C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715684: jr          $ra
    // 0x80715688: nop

    return;
    // 0x80715688: nop

;}
RECOMP_FUNC void func_8004F44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F44C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004F454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F458: lh          $t6, 0x52($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X52);
    // 0x8004F45C: lh          $t0, 0x54($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X54);
    // 0x8004F460: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8004F464: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8004F468: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8004F46C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8004F470: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8004F474: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004F478: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8004F47C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8004F480: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8004F484: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8004F488: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004F48C: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8004F490: lh          $t5, 0x4($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4);
    // 0x8004F494: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8004F498: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8004F49C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004F4A0: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x8004F4A4: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
    // 0x8004F4A8: sh          $t4, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r12;
    // 0x8004F4AC: sh          $t5, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r13;
    // 0x8004F4B0: sub.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8004F4B4: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x8004F4B8: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    // 0x8004F4BC: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8004F4C0: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8004F4C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004F4C8: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x8004F4CC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x8004F4D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8004F4D4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x8004F4D8: jal         0x80081C64
    // 0x8004F4DC: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8004F4DC: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8004F4E0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F4E4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8004F4E8: nop

    // 0x8004F4EC: sh          $t7, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r15;
    // 0x8004F4F0: jal         0x80081C64
    // 0x8004F4F4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8004F4F4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8004F4F8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F4FC: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8004F500: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8004F504: jal         0x80081C64
    // 0x8004F508: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
    Math_FFloorF(rdram, ctx);
        goto after_2;
    // 0x8004F508: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
    after_2:
    // 0x8004F50C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F510: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8004F514: nop

    // 0x8004F518: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x8004F51C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8004F520: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x8004F524: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004F528: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004F52C: jal         0x80081C64
    // 0x8004F530: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    Math_FFloorF(rdram, ctx);
        goto after_3;
    // 0x8004F530: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x8004F534: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F538: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8004F53C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8004F540: nop

    // 0x8004F544: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
    // 0x8004F548: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x8004F54C: jal         0x80081C64
    // 0x8004F550: sh          $t5, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r13;
    Math_FFloorF(rdram, ctx);
        goto after_4;
    // 0x8004F550: sh          $t5, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r13;
    after_4:
    // 0x8004F554: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F558: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8004F55C: nop

    // 0x8004F560: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x8004F564: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004F568: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004F56C: jal         0x80081C64
    // 0x8004F570: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    Math_FFloorF(rdram, ctx);
        goto after_5;
    // 0x8004F570: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_5:
    // 0x8004F574: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004F578: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    // 0x8004F57C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8004F580: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
    // 0x8004F584: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x8004F588: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x8004F58C: sh          $t1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r9;
    // 0x8004F590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004F59C: jr          $ra
    // 0x8004F5A0: nop

    return;
    // 0x8004F5A0: nop

;}
RECOMP_FUNC void func_804A4D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4D74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4D78: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4D7C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4D80: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4D84: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4D88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4D8C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4D90: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4D94: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4D98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4D9C: jr          $ra
    // 0x804A4DA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4DA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806720C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806720C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806720C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806720C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806720CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806720D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806720D4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806720D8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x806720DC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x806720E0: jal         0x80671D4C
    // 0x806720E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x806720E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x806720E8: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x806720EC: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x806720F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x806720F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806720F8: blez        $t7, L_80672128
    if (SIGNED(ctx->r15) <= 0) {
        // 0x806720FC: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80672128;
    }
    // 0x806720FC: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80672100: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80672104: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672108: jal         0x80671954
    // 0x8067210C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x8067210C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_1:
    // 0x80672110: beq         $v0, $zero, L_8067211C
    if (ctx->r2 == 0) {
        // 0x80672114: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8067211C;
    }
    // 0x80672114: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80672118: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8067211C:
    // 0x8067211C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80672120: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80672124: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80672128:
    // 0x80672128: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8067212C: beq         $at, $zero, L_80672140
    if (ctx->r1 == 0) {
        // 0x80672130: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80672140;
    }
    // 0x80672130: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80672134: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672138: jal         0x80671C98
    // 0x8067213C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x8067213C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
L_80672140:
    // 0x80672140: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80672144: bne         $at, $zero, L_80672160
    if (ctx->r1 != 0) {
        // 0x80672148: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80672160;
    }
    // 0x80672148: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8067214C: jal         0x80672C80
    // 0x80672150: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80672150: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80672154: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80672158: jal         0x80067818
    // 0x8067215C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067215C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80672160:
    // 0x80672160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80672164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80672168: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8067216C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80672170: jr          $ra
    // 0x80672174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80672174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8042A060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042A064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042A068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042A06C: jal         0x80429E5C
    // 0x8042A070: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80429E5C(rdram, ctx);
        goto after_0;
    // 0x8042A070: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8042A074: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8042A078: jal         0x80064E84
    // 0x8042A07C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8042A07C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8042A080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042A084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042A088: jr          $ra
    // 0x8042A08C: nop

    return;
    // 0x8042A08C: nop

;}
RECOMP_FUNC void func_8005CBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CBE8: lhu         $t6, 0x2C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2C);
    // 0x8005CBEC: addiu       $at, $zero, 0x4024
    ctx->r1 = ADD32(0, 0X4024);
    // 0x8005CBF0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005CBF4: bne         $t6, $at, L_8005CC00
    if (ctx->r14 != ctx->r1) {
        // 0x8005CBF8: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_8005CC00;
    }
    // 0x8005CBF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005CBFC: sb          $zero, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = 0;
L_8005CC00:
    // 0x8005CC00: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x8005CC04: beql        $a0, $zero, L_8005CC1C
    if (ctx->r4 == 0) {
        // 0x8005CC08: lw          $a0, 0x1C($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X1C);
            goto L_8005CC1C;
    }
    goto skip_0;
    // 0x8005CC08: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
    skip_0:
    // 0x8005CC0C: jal         0x80064E84
    // 0x8005CC10: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8005CC10: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005CC14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005CC18: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
L_8005CC1C:
    // 0x8005CC1C: beql        $a0, $zero, L_8005CC34
    if (ctx->r4 == 0) {
        // 0x8005CC20: lw          $t7, 0x0($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X0);
            goto L_8005CC34;
    }
    goto skip_1;
    // 0x8005CC20: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x8005CC24: jal         0x80064E84
    // 0x8005CC28: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8005CC28: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8005CC2C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005CC30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
L_8005CC34:
    // 0x8005CC34: beql        $t7, $zero, L_8005CC70
    if (ctx->r15 == 0) {
        // 0x8005CC38: lw          $a0, 0x28($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X28);
            goto L_8005CC70;
    }
    goto skip_2;
    // 0x8005CC38: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    skip_2:
    // 0x8005CC3C: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    // 0x8005CC40: beql        $a0, $zero, L_8005CC58
    if (ctx->r4 == 0) {
        // 0x8005CC44: lw          $a0, 0x24($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X24);
            goto L_8005CC58;
    }
    goto skip_3;
    // 0x8005CC44: lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24);
    skip_3:
    // 0x8005CC48: jal         0x80064E84
    // 0x8005CC4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8005CC4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8005CC50: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005CC54: lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24);
L_8005CC58:
    // 0x8005CC58: beql        $a0, $zero, L_8005CC70
    if (ctx->r4 == 0) {
        // 0x8005CC5C: lw          $a0, 0x28($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X28);
            goto L_8005CC70;
    }
    goto skip_4;
    // 0x8005CC5C: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    skip_4:
    // 0x8005CC60: jal         0x80064E84
    // 0x8005CC64: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x8005CC64: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x8005CC68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005CC6C: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
L_8005CC70:
    // 0x8005CC70: beql        $a0, $zero, L_8005CC84
    if (ctx->r4 == 0) {
        // 0x8005CC74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005CC84;
    }
    goto skip_5;
    // 0x8005CC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8005CC78: jal         0x8005AB10
    // 0x8005CC7C: nop

    func_8005AB10(rdram, ctx);
        goto after_4;
    // 0x8005CC7C: nop

    after_4:
    // 0x8005CC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005CC84:
    // 0x8005CC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CC88: jr          $ra
    // 0x8005CC8C: nop

    return;
    // 0x8005CC8C: nop

;}
RECOMP_FUNC void func_80438FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438FEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80438FF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80438FF4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80438FF8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80438FFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80439000: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80439004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80439008: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043900C: lui         $s3, 0x8044
    ctx->r19 = S32(RELOC_HI16(80, 0X19B0) << 16);
    // 0x80439010: addiu       $s3, $s3, -0x5B90
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(80, 0X19B0));
    // 0x80439014: lw          $v0, 0xAAC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAAC);
    // 0x80439018: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x8043901C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80439020: addu        $s1, $v1, $t6
    ctx->r17 = ADD32(ctx->r3, ctx->r14);
    // 0x80439024: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80439028: beq         $at, $zero, L_80439070
    if (ctx->r1 == 0) {
        // 0x8043902C: addiu       $s1, $s1, 0x974
        ctx->r17 = ADD32(ctx->r17, 0X974);
            goto L_80439070;
    }
    // 0x8043902C: addiu       $s1, $s1, 0x974
    ctx->r17 = ADD32(ctx->r17, 0X974);
    // 0x80439030: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80439034: addu        $s2, $v1, $s0
    ctx->r18 = ADD32(ctx->r3, ctx->r16);
L_80439038:
    // 0x80439038: lw          $v1, 0xD10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XD10);
    // 0x8043903C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80439040: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80439044: mflo        $t7
    ctx->r15 = lo;
    // 0x80439048: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x8043904C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80439050: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80439054: jal         0x80438EE4
    // 0x80439058: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_80438EE4(rdram, ctx);
        goto after_0;
    // 0x80439058: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_0:
    // 0x8043905C: addiu       $s0, $s0, 0xC8
    ctx->r16 = ADD32(ctx->r16, 0XC8);
    // 0x80439060: slti        $at, $s0, 0x48
    ctx->r1 = SIGNED(ctx->r16) < 0X48 ? 1 : 0;
    // 0x80439064: addiu       $s2, $s2, 0xC8
    ctx->r18 = ADD32(ctx->r18, 0XC8);
    // 0x80439068: bne         $at, $zero, L_80439038
    if (ctx->r1 != 0) {
        // 0x8043906C: addiu       $s1, $s1, 0x18C
        ctx->r17 = ADD32(ctx->r17, 0X18C);
            goto L_80439038;
    }
    // 0x8043906C: addiu       $s1, $s1, 0x18C
    ctx->r17 = ADD32(ctx->r17, 0X18C);
L_80439070:
    // 0x80439070: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80439074: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80439078: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8043907C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80439080: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80439084: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80439088: jr          $ra
    // 0x8043908C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8043908C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806B1198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B119C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B11A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B11A4: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(598, 0X1070) << 16);
    // 0x806B11A8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806B11AC: addiu       $t7, $t7, 0x1000
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(598, 0X1070));
    // 0x806B11B0: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806B11B4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806B11B8: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1778) << 16);
    // 0x806B11BC: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x806B11C0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x806B11C4: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806B11C8: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x806B11CC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x806B11D0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x806B11D4: lwc1        $f4, 0x1708($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1778));
    // 0x806B11D8: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X177C) << 16);
    // 0x806B11DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B11E0: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x806B11E4: lwc1        $f8, 0x170C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X177C));
    // 0x806B11E8: lwc1        $f6, 0x6C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x806B11EC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806B11F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B11F4: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x806B11F8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B11FC: lw          $t8, 0x138($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X138);
    // 0x806B1200: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x806B1204: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806B1208: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x806B120C: jal         0x806B15A4
    // 0x806B1210: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    func_806B15A4(rdram, ctx);
        goto after_0;
    // 0x806B1210: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x806B1214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B1218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B121C: jr          $ra
    // 0x806B1220: nop

    return;
    // 0x806B1220: nop

;}
RECOMP_FUNC void func_8043E330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E338: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8043E33C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8043E340: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043E344: jal         0x80065ABC
    // 0x8043E348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8043E348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E34C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E350: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8043E354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E35C: jr          $ra
    // 0x8043E360: nop

    return;
    // 0x8043E360: nop

;}
RECOMP_FUNC void func_80050D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050D7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050D80: jal         0x80064E84
    // 0x80050D84: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80050D84: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x80050D88: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80050D8C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80050D90: jal         0x80064E84
    // 0x80050D94: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80050D94: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    after_1:
    // 0x80050D98: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80050D9C: sw          $zero, 0x34($t7)
    MEM_W(0X34, ctx->r15) = 0;
    // 0x80050DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050DA8: jr          $ra
    // 0x80050DAC: nop

    return;
    // 0x80050DAC: nop

;}
RECOMP_FUNC void func_8002381C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002381C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023824: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023828: lwc1        $f0, -0x2E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E0);
    // 0x8002382C: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80023830: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80023834: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80023838: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002383C: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80023840: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80023844: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80023848: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002384C: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80023850: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80023854: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80023858: lwc1        $f10, 0xCC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8002385C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x80023860: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023864: jal         0x800232E0
    // 0x80023868: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    func_800232E0(rdram, ctx);
        goto after_0;
    // 0x80023868: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    after_0:
    // 0x8002386C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023874: jr          $ra
    // 0x80023878: nop

    return;
    // 0x80023878: nop

;}
RECOMP_FUNC void func_8006863C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006863C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068640: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80068644: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068648: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8006864C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068650: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x80068654: sll         $t6, $a0, 7
    ctx->r14 = S32(ctx->r4 << 7);
    // 0x80068658: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006865C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80068660: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80068664: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x80068668: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8006866C: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80068670: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80068674: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006867C: addiu       $t8, $t7, 0x3F8
    ctx->r24 = ADD32(ctx->r15, 0X3F8);
    // 0x80068680: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80068684: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80068688: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8006868C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068690: addiu       $t1, $t0, 0x47C
    ctx->r9 = ADD32(ctx->r8, 0X47C);
    // 0x80068694: addiu       $t4, $t3, 0x638
    ctx->r12 = ADD32(ctx->r11, 0X638);
    // 0x80068698: addiu       $t7, $t6, 0x974
    ctx->r15 = ADD32(ctx->r14, 0X974);
    // 0x8006869C: sw          $a0, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->r4;
    // 0x800686A0: sw          $t8, 0x3F4($v0)
    MEM_W(0X3F4, ctx->r2) = ctx->r24;
    // 0x800686A4: sw          $t1, 0x478($v0)
    MEM_W(0X478, ctx->r2) = ctx->r9;
    // 0x800686A8: sw          $t4, 0x634($v0)
    MEM_W(0X634, ctx->r2) = ctx->r12;
    // 0x800686AC: jal         0x80044CA0
    // 0x800686B0: sw          $t7, 0x970($v0)
    MEM_W(0X970, ctx->r2) = ctx->r15;
    func_80044CA0(rdram, ctx);
        goto after_0;
    // 0x800686B0: sw          $t7, 0x970($v0)
    MEM_W(0X970, ctx->r2) = ctx->r15;
    after_0:
    // 0x800686B4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800686B8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800686BC: lw          $v1, 0x3EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3EC);
    // 0x800686C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800686C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800686C8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800686CC: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x800686D0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800686D4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800686D8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800686DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800686E0: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800686E4: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x800686E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800686EC: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800686F0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800686F4: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x800686F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800686FC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80068700: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80068704: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80068708: addiu       $t9, $a0, 0x9E0
    ctx->r25 = ADD32(ctx->r4, 0X9E0);
    // 0x8006870C: addiu       $t2, $t1, 0x8D4
    ctx->r10 = ADD32(ctx->r9, 0X8D4);
    // 0x80068710: addiu       $t3, $a0, 0xA6C
    ctx->r11 = ADD32(ctx->r4, 0XA6C);
    // 0x80068714: addiu       $t6, $t5, 0x13BC
    ctx->r14 = ADD32(ctx->r13, 0X13BC);
    // 0x80068718: sw          $t9, 0x9DC($v0)
    MEM_W(0X9DC, ctx->r2) = ctx->r25;
    // 0x8006871C: sw          $t2, 0x8D0($v0)
    MEM_W(0X8D0, ctx->r2) = ctx->r10;
    // 0x80068720: sw          $t3, 0xA68($v0)
    MEM_W(0XA68, ctx->r2) = ctx->r11;
    // 0x80068724: jr          $ra
    // 0x80068728: sw          $t6, 0x13B8($v0)
    MEM_W(0X13B8, ctx->r2) = ctx->r14;
    return;
    // 0x80068728: sw          $t6, 0x13B8($v0)
    MEM_W(0X13B8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8043DEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DEEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043DEF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043DEF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043DEF8: jal         0x8043DCF4
    // 0x8043DEFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043DCF4(rdram, ctx);
        goto after_0;
    // 0x8043DEFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043DF00: jal         0x8043DDF8
    // 0x8043DF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043DDF8(rdram, ctx);
        goto after_1;
    // 0x8043DF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043DF08: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8043DF0C: jal         0x80048F84
    // 0x8043DF10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8043DF10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8043DF14: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8043DF18: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8043DF1C: jal         0x80065ABC
    // 0x8043DF20: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8043DF20: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8043DF24: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8043DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DF2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043DF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043DF34: jr          $ra
    // 0x8043DF38: nop

    return;
    // 0x8043DF38: nop

;}
RECOMP_FUNC void func_80447D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447D38: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80447D3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80447D40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80447D44: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80447D48: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80447D4C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447D50: addiu       $t9, $zero, 0x1B6C
    ctx->r25 = ADD32(0, 0X1B6C);
    // 0x80447D54: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80447D58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80447D5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80447D60: lwc1        $f4, 0x6B24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6B24);
    // 0x80447D64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80447D68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80447D6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80447D70: swc1        $f8, 0x6B24($v1)
    MEM_W(0X6B24, ctx->r3) = ctx->f8.u32l;
    // 0x80447D74: lwc1        $f10, 0x6B24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X6B24);
    // 0x80447D78: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80447D7C: nop

    // 0x80447D80: bc1fl       L_80447E08
    if (!c1cs) {
        // 0x80447D84: addiu       $v1, $v0, 0xC
        ctx->r3 = ADD32(ctx->r2, 0XC);
            goto L_80447E08;
    }
    goto skip_0;
    // 0x80447D84: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
    skip_0:
    // 0x80447D88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80447D8C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447D90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447D94: swc1        $f18, 0x6B24($at)
    MEM_W(0X6B24, ctx->r1) = ctx->f18.u32l;
    // 0x80447D98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447D9C: ori         $at, $at, 0x6D94
    ctx->r1 = ctx->r1 | 0X6D94;
    // 0x80447DA0: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80447DA4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80447DA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80447DAC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80447DB0: bne         $at, $zero, L_80447DBC
    if (ctx->r1 != 0) {
        // 0x80447DB4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80447DBC;
    }
    // 0x80447DB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80447DB8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80447DBC:
    // 0x80447DBC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447DC0: ori         $at, $at, 0x6D98
    ctx->r1 = ctx->r1 | 0X6D98;
    // 0x80447DC4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80447DC8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80447DCC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80447DD0: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80447DD4: bne         $at, $zero, L_80447DE0
    if (ctx->r1 != 0) {
        // 0x80447DD8: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_80447DE0;
    }
    // 0x80447DD8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80447DDC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80447DE0:
    // 0x80447DE0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447DE4: ori         $at, $at, 0x6D9C
    ctx->r1 = ctx->r1 | 0X6D9C;
    // 0x80447DE8: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80447DEC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80447DF0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80447DF4: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x80447DF8: bne         $at, $zero, L_80447E04
    if (ctx->r1 != 0) {
        // 0x80447DFC: sw          $t4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r12;
            goto L_80447E04;
    }
    // 0x80447DFC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80447E00: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80447E04:
    // 0x80447E04: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
L_80447E08:
    // 0x80447E08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80447E0C: subu        $t0, $t9, $a3
    ctx->r8 = SUB32(ctx->r25, ctx->r7);
    // 0x80447E10: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80447E14: slti        $at, $t7, 0x3C0
    ctx->r1 = SIGNED(ctx->r15) < 0X3C0 ? 1 : 0;
    // 0x80447E18: beq         $at, $zero, L_80447E24
    if (ctx->r1 == 0) {
        // 0x80447E1C: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80447E24;
    }
    // 0x80447E1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80447E20: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80447E24:
    // 0x80447E24: jr          $ra
    // 0x80447E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80447E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80531BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80531BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531BCC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x80531BD0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80531BD4: bne         $t7, $zero, L_80531C18
    if (ctx->r15 != 0) {
        // 0x80531BD8: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_80531C18;
    }
    // 0x80531BD8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80531BDC: jal         0x8004700C
    // 0x80531BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80531BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80531BE4: beq         $v0, $zero, L_80531C18
    if (ctx->r2 == 0) {
        // 0x80531BE8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80531C18;
    }
    // 0x80531BE8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80531BEC: lw          $v0, 0x1F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1F4);
    // 0x80531BF0: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x80531BF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80531BF8: sb          $t9, 0x1B4($v0)
    MEM_B(0X1B4, ctx->r2) = ctx->r25;
    // 0x80531BFC: lw          $t0, 0x260($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X260);
    // 0x80531C00: lbu         $a0, 0x15($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X15);
    // 0x80531C04: jal         0x80062DD4
    // 0x80531C08: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x80531C08: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80531C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80531C10: jal         0x80531FB8
    // 0x80531C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80531FB8(rdram, ctx);
        goto after_2;
    // 0x80531C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80531C18:
    // 0x80531C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80531C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80531C20: jr          $ra
    // 0x80531C24: nop

    return;
    // 0x80531C24: nop

;}
RECOMP_FUNC void func_807A5E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A5E24: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807A5E28: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x807A5E2C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x807A5E30: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x807A5E34: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x807A5E38: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807A5E3C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807A5E40: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807A5E44: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807A5E48: jr          $ra
    // 0x807A5E4C: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    return;
    // 0x807A5E4C: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
;}
RECOMP_FUNC void func_80020ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020ADC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020AE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020AE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80020AEC: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80020AF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020AF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020AF8: bne         $t6, $at, L_80020B24
    if (ctx->r14 != ctx->r1) {
        // 0x80020AFC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80020B24;
    }
    // 0x80020AFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80020B00: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80020B04: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80020B08: bnel        $t7, $at, L_80020B28
    if (ctx->r15 != ctx->r1) {
        // 0x80020B0C: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80020B28;
    }
    goto skip_0;
    // 0x80020B0C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    skip_0:
    // 0x80020B10: lwc1        $f4, 0xAC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80020B14: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80020B18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80020B1C: nop

    // 0x80020B20: bc1t        L_80020B68
    if (c1cs) {
        // 0x80020B24: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80020B68;
    }
L_80020B24:
    // 0x80020B24: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
L_80020B28:
    // 0x80020B28: jal         0x80047AB8
    // 0x80020B2C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80020B2C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80020B30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020B34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80020B38: jal         0x80020844
    // 0x80020B3C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80020844(rdram, ctx);
        goto after_1;
    // 0x80020B3C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80020B40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020B44: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80020B48: jal         0x80020888
    // 0x80020B4C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80020888(rdram, ctx);
        goto after_2;
    // 0x80020B4C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80020B50: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80020B54: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80020B58: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80020B5C: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x80020B60: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80020B64: swc1        $f8, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f8.u32l;
L_80020B68:
    // 0x80020B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020B6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020B70: jr          $ra
    // 0x80020B74: nop

    return;
    // 0x80020B74: nop

;}
RECOMP_FUNC void func_804CF13C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF13C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CF140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF144: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CF148: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804CF14C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CF150: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(240, 0X1A84) << 16);
    // 0x804CF154: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CF158: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804CF15C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CF160: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CF164: lw          $t8, -0x2CC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(240, 0X1A84));
    // 0x804CF168: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CF16C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CF170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CF174: jal         0x80048490
    // 0x804CF178: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804CF178: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804CF17C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804CF180: jal         0x80048378
    // 0x804CF184: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804CF184: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804CF188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF18C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CF190: jr          $ra
    // 0x804CF194: nop

    return;
    // 0x804CF194: nop

;}
RECOMP_FUNC void func_80027EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027EDC: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80027EE0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80027EE4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027EE8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80027EEC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027EF0: addiu       $t8, $t8, 0x7EA8
    ctx->r24 = ADD32(ctx->r24, 0X7EA8);
    // 0x80027EF4: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x80027EF8: jr          $ra
    // 0x80027EFC: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x80027EFC: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80521C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521C08: jal         0x80047090
    // 0x80521C0C: addiu       $a0, $zero, 0x41DA
    ctx->r4 = ADD32(0, 0X41DA);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80521C0C: addiu       $a0, $zero, 0x41DA
    ctx->r4 = ADD32(0, 0X41DA);
    after_0:
    // 0x80521C10: lui         $at, 0x41DA
    ctx->r1 = S32(0X41DA << 16);
    // 0x80521C14: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80521C18: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80521C1C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80521C20: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80521C24: jal         0x8004613C
    // 0x80521C28: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80521C28: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_1:
    // 0x80521C2C: bne         $v0, $zero, L_80521C3C
    if (ctx->r2 != 0) {
        // 0x80521C30: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80521C3C;
    }
    // 0x80521C30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80521C34: b           L_80521C40
    // 0x80521C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80521C40;
    // 0x80521C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80521C3C:
    // 0x80521C3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80521C40:
    // 0x80521C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521C48: jr          $ra
    // 0x80521C4C: nop

    return;
    // 0x80521C4C: nop

;}
RECOMP_FUNC void func_807B96B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B96B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B96BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B96C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B96C4: jal         0x807B8D30
    // 0x807B96C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B96C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B96CC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x807B96D0: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x807B96D4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807B96D8: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x807B96DC: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x807B96E0: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x807B96E4: bne         $t7, $at, L_807B974C
    if (ctx->r15 != ctx->r1) {
        // 0x807B96E8: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_807B974C;
    }
    // 0x807B96E8: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x807B96EC: jal         0x80067818
    // 0x807B96F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B96F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B96F4: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x807B96F8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B96FC: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x807B9700: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9704: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807B9708: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x807B970C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9710: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x807B9714: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x807B9718: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B971C: lui         $a3, 0x807C
    ctx->r7 = S32(RELOC_HI16(886, 0X1D4C) << 16);
    // 0x807B9720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9724: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x807B9728: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B972C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9730: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9734: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x807B9738: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x807B973C: jal         0x807B9E2C
    // 0x807B9740: lbu         $a3, -0x6044($a3)
    ctx->r7 = MEM_BU(ctx->r7, (int16_t)RELOC_LO16(886, 0X1D4C));
    func_807B9E2C(rdram, ctx);
        goto after_2;
    // 0x807B9740: lbu         $a3, -0x6044($a3)
    ctx->r7 = MEM_BU(ctx->r7, (int16_t)RELOC_LO16(886, 0X1D4C));
    after_2:
    // 0x807B9744: b           L_807B979C
    // 0x807B9748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807B979C;
    // 0x807B9748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B974C:
    // 0x807B974C: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807B9750: bne         $t4, $at, L_807B9798
    if (ctx->r12 != ctx->r1) {
        // 0x807B9754: addiu       $a0, $zero, 0x205
        ctx->r4 = ADD32(0, 0X205);
            goto L_807B9798;
    }
    // 0x807B9754: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9758: jal         0x80067818
    // 0x807B975C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807B975C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x807B9760: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x807B9764: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9768: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x807B976C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9770: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x807B9774: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x807B9778: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B977C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x807B9780: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x807B9784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B978C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807B9790: jal         0x807B9E2C
    // 0x807B9794: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807B9E2C(rdram, ctx);
        goto after_4;
    // 0x807B9794: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
L_807B9798:
    // 0x807B9798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B979C:
    // 0x807B979C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B97A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B97A4: jr          $ra
    // 0x807B97A8: nop

    return;
    // 0x807B97A8: nop

;}
RECOMP_FUNC void func_80530834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530834: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80530838: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8053083C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80530840: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(336, 0X3E8) << 16);
    // 0x80530844: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80530848: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8053084C: lw          $t8, 0x878($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(336, 0X3E8));
    // 0x80530850: jr          $ra
    // 0x80530854: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80530854: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80530858: nop

    // 0x8053085C: nop

;}
RECOMP_FUNC void func_8040AF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AF20: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8040AF24: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8040AF28: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(14, 0X1370) << 16);
    // 0x8040AF2C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8040AF30: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8040AF34: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8040AF38: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8040AF3C: lwc1        $f22, -0x4130($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(14, 0X1370));
    // 0x8040AF40: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8040AF44: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8040AF48: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8040AF4C: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(14, 0X1374) << 16);
    // 0x8040AF50: lui         $s1, 0x8041
    ctx->r17 = S32(RELOC_HI16(14, 0XF98) << 16);
    // 0x8040AF54: lui         $s2, 0x8041
    ctx->r18 = S32(RELOC_HI16(14, 0XF88) << 16);
    // 0x8040AF58: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x8040AF5C: lui         $s5, 0x8041
    ctx->r21 = S32(RELOC_HI16(14, 0XFA8) << 16);
    // 0x8040AF60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040AF64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8040AF68: addiu       $s5, $s5, -0x44F8
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(14, 0XFA8));
    // 0x8040AF6C: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x8040AF70: addiu       $s2, $s2, -0x4518
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(14, 0XF88));
    // 0x8040AF74: addiu       $s1, $s1, -0x4508
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(14, 0XF98));
    // 0x8040AF78: lwc1        $f20, -0x412C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(14, 0X1374));
    // 0x8040AF7C: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
L_8040AF80:
    // 0x8040AF80: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040AF84: lw          $t6, 0xA68($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XA68);
    // 0x8040AF88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8040AF8C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8040AF90: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040AF94: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8040AF98: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8040AF9C: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8040AFA0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8040AFA4: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8040AFA8: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8040AFAC: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040AFB0: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8040AFB4: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8040AFB8: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8040AFBC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8040AFC0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8040AFC4: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040AFC8: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x8040AFCC: swc1        $f22, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f22.u32l;
    // 0x8040AFD0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8040AFD4: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8040AFD8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8040AFDC: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8040AFE0: jalr        $t9
    // 0x8040AFE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040AFE4: nop

    after_0:
    // 0x8040AFE8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8040AFEC: bne         $s1, $s5, L_8040AF80
    if (ctx->r17 != ctx->r21) {
        // 0x8040AFF0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8040AF80;
    }
    // 0x8040AFF0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8040AFF4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8040AFF8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8040AFFC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8040B000: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8040B004: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8040B008: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8040B00C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8040B010: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8040B014: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8040B018: jr          $ra
    // 0x8040B01C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8040B01C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8052E698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E698: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8052E69C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052E6A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8052E6A4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8052E6A8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052E6AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052E6B0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8052E6B4: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052E6B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052E6BC: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052E6C0: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052E6C4: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8052E6C8: lw          $t9, 0x116C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X116C);
    // 0x8052E6CC: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8052E6D0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8052E6D4: nop

    // 0x8052E6D8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8052E6DC: bltzl       $t1, L_8052E9DC
    if (SIGNED(ctx->r9) < 0) {
        // 0x8052E6E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052E9DC;
    }
    goto skip_0;
    // 0x8052E6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8052E6E4: lw          $t2, 0x1160($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1160);
    // 0x8052E6E8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8052E6EC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8052E6F0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8052E6F4: beql        $at, $zero, L_8052E9DC
    if (ctx->r1 == 0) {
        // 0x8052E6F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052E9DC;
    }
    goto skip_1;
    // 0x8052E6F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052E6FC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052E700: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8052E704: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052E708: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052E70C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052E710: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8052E714: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052E718: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8052E71C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8052E720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052E724: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8052E728: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8052E72C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052E730: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8052E734: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8052E738: add.s       $f2, $f14, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x8052E73C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8052E740: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8052E744: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052E748: nop

    // 0x8052E74C: cvt.w.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8052E750: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052E754: nop

    // 0x8052E758: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052E75C: beql        $t5, $zero, L_8052E7AC
    if (ctx->r13 == 0) {
        // 0x8052E760: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_8052E7AC;
    }
    goto skip_2;
    // 0x8052E760: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x8052E764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052E768: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052E76C: sub.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8052E770: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052E774: nop

    // 0x8052E778: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8052E77C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052E780: nop

    // 0x8052E784: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052E788: bne         $t5, $zero, L_8052E7A0
    if (ctx->r13 != 0) {
        // 0x8052E78C: nop
    
            goto L_8052E7A0;
    }
    // 0x8052E78C: nop

    // 0x8052E790: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8052E794: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052E798: b           L_8052E7B8
    // 0x8052E79C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8052E7B8;
    // 0x8052E79C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8052E7A0:
    // 0x8052E7A0: b           L_8052E7B8
    // 0x8052E7A4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8052E7B8;
    // 0x8052E7A4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8052E7A8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_8052E7AC:
    // 0x8052E7AC: nop

    // 0x8052E7B0: bltz        $t5, L_8052E7A0
    if (SIGNED(ctx->r13) < 0) {
        // 0x8052E7B4: nop
    
            goto L_8052E7A0;
    }
    // 0x8052E7B4: nop

L_8052E7B8:
    // 0x8052E7B8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8052E7BC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8052E7C0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8052E7C4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8052E7C8: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052E7CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052E7D0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8052E7D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052E7D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052E7DC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8052E7E0: addu        $a2, $t0, $t8
    ctx->r6 = ADD32(ctx->r8, ctx->r24);
    // 0x8052E7E4: lwc1        $f18, 0xF6C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XF6C);
    // 0x8052E7E8: sub.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052E7EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052E7F0: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052E7F4: lwc1        $f8, 0xF70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XF70);
    // 0x8052E7F8: sub.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8052E7FC: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8052E800: nop

    // 0x8052E804: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8052E808: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8052E80C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8052E810: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8052E814: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8052E818: nop

    // 0x8052E81C: bc1f        L_8052E9D8
    if (!c1cs) {
        // 0x8052E820: nop
    
            goto L_8052E9D8;
    }
    // 0x8052E820: nop

    // 0x8052E824: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8052E828: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052E82C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8052E830: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2414) << 16);
    // 0x8052E834: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8052E838: blez        $t1, L_8052E898
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8052E83C: swc1        $f10, 0xF6C($a2)
        MEM_W(0XF6C, ctx->r6) = ctx->f10.u32l;
            goto L_8052E898;
    }
    // 0x8052E83C: swc1        $f10, 0xF6C($a2)
    MEM_W(0XF6C, ctx->r6) = ctx->f10.u32l;
    // 0x8052E840: lwc1        $f14, 0x1D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2414));
    // 0x8052E844: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052E848: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052E84C: nop

    // 0x8052E850: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_8052E854:
    // 0x8052E854: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8052E858: lwc1        $f2, 0xF68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF68);
    // 0x8052E85C: lwc1        $f8, 0xF6C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052E860: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8052E864: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8052E868: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8052E86C: nop

    // 0x8052E870: bc1fl       L_8052E890
    if (!c1cs) {
        // 0x8052E874: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8052E890;
    }
    goto skip_3;
    // 0x8052E874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_3:
    // 0x8052E878: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8052E87C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8052E880: sub.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8052E884: b           L_8052E890
    // 0x8052E888: swc1        $f10, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f10.u32l;
        goto L_8052E890;
    // 0x8052E888: swc1        $f10, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f10.u32l;
    // 0x8052E88C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8052E890:
    // 0x8052E890: bgtzl       $v1, L_8052E854
    if (SIGNED(ctx->r3) > 0) {
        // 0x8052E894: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8052E854;
    }
    goto skip_4;
    // 0x8052E894: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_4:
L_8052E898:
    // 0x8052E898: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052E89C: lwc1        $f8, 0xF70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XF70);
    // 0x8052E8A0: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8052E8A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052E8A8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2418) << 16);
    // 0x8052E8AC: lwc1        $f14, 0x1D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2418));
    // 0x8052E8B0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8052E8B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052E8B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052E8BC: addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // 0x8052E8C0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8052E8C4: swc1        $f8, 0xF70($a2)
    MEM_W(0XF70, ctx->r6) = ctx->f8.u32l;
    // 0x8052E8C8: lw          $a0, 0x1160($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1160);
    // 0x8052E8CC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8052E8D0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8052E8D4: beq         $at, $zero, L_8052E92C
    if (ctx->r1 == 0) {
        // 0x8052E8D8: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8052E92C;
    }
    // 0x8052E8D8: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
L_8052E8DC:
    // 0x8052E8DC: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8052E8E0: lwc1        $f2, 0xF70($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF70);
    // 0x8052E8E4: lwc1        $f6, 0xF6C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052E8E8: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8052E8EC: add.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8052E8F0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8052E8F4: nop

    // 0x8052E8F8: bc1fl       L_8052E920
    if (!c1cs) {
        // 0x8052E8FC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8052E920;
    }
    goto skip_5;
    // 0x8052E8FC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_5:
    // 0x8052E900: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8052E904: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8052E908: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052E90C: swc1        $f8, 0xF70($v0)
    MEM_W(0XF70, ctx->r2) = ctx->f8.u32l;
    // 0x8052E910: lw          $a0, 0x1160($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1160);
    // 0x8052E914: b           L_8052E920
    // 0x8052E918: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
        goto L_8052E920;
    // 0x8052E918: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8052E91C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8052E920:
    // 0x8052E920: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8052E924: bnel        $at, $zero, L_8052E8DC
    if (ctx->r1 != 0) {
        // 0x8052E928: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8052E8DC;
    }
    goto skip_6;
    // 0x8052E928: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    skip_6:
L_8052E92C:
    // 0x8052E92C: lwc1        $f6, 0xF68($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF68);
    // 0x8052E930: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8052E934: lwc1        $f2, 0x1158($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X1158);
    // 0x8052E938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052E93C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8052E940: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052E944: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8052E948: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8052E94C: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8052E950: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8052E954: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8052E958: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8052E95C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8052E960: nop

    // 0x8052E964: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8052E968: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8052E96C: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8052E970: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8052E974: nop

    // 0x8052E978: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8052E97C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8052E980: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8052E984: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8052E988: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8052E98C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8052E990: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8052E994: nop

    // 0x8052E998: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8052E99C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8052E9A0: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8052E9A4: nop

    // 0x8052E9A8: bc1f        L_8052E9D8
    if (!c1cs) {
        // 0x8052E9AC: nop
    
            goto L_8052E9D8;
    }
    // 0x8052E9AC: nop

    // 0x8052E9B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8052E9B4: sb          $t3, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r11;
    // 0x8052E9B8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8052E9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052E9C0: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8052E9C4: jalr        $t9
    // 0x8052E9C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8052E9C8: nop

    after_0:
    // 0x8052E9CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8052E9D0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8052E9D4: swc1        $f16, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->f16.u32l;
L_8052E9D8:
    // 0x8052E9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052E9DC:
    // 0x8052E9DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8052E9E0: jr          $ra
    // 0x8052E9E4: nop

    return;
    // 0x8052E9E4: nop

;}
RECOMP_FUNC void func_80446650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446650: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446654: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446658: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044665C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446660: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x80446664: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446668: jr          $ra
    // 0x8044666C: sw          $t7, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r15;
    return;
    // 0x8044666C: sw          $t7, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_804086FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804086FC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80408700: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x80408704: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80408708: jr          $ra
    // 0x8040870C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    return;
    // 0x8040870C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
;}
RECOMP_FUNC void func_8058469C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058469C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805846A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805846A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805846A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805846AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805846B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805846B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805846B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805846BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805846C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805846C4: jr          $ra
    // 0x805846C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805846C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807C40C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C40C8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C40CC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C40D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C40D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C40D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C40DC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807C40E0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C40E4: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(907, 0X1460) << 16);
    // 0x807C40E8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C40EC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C40F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C40F4: lw          $t1, 0x47C0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(907, 0X1460));
    // 0x807C40F8: jr          $ra
    // 0x807C40FC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C40FC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80052B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052B64: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80052B68: beql        $t6, $zero, L_80052B94
    if (ctx->r14 == 0) {
        // 0x80052B6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80052B94;
    }
    goto skip_0;
    // 0x80052B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80052B70: jal         0x80052AE4
    // 0x80052B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80052AE4(rdram, ctx);
        goto after_0;
    // 0x80052B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80052B78: bne         $v0, $zero, L_80052B90
    if (ctx->r2 != 0) {
        // 0x80052B7C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80052B90;
    }
    // 0x80052B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80052B80: jal         0x800528C8
    // 0x80052B84: nop

    func_800528C8(rdram, ctx);
        goto after_1;
    // 0x80052B84: nop

    after_1:
    // 0x80052B88: b           L_80052B94
    // 0x80052B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052B94;
    // 0x80052B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052B90:
    // 0x80052B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052B94:
    // 0x80052B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052B9C: jr          $ra
    // 0x80052BA0: nop

    return;
    // 0x80052BA0: nop

;}
RECOMP_FUNC void func_8044459C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044459C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804445A0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804445A4: lw          $v0, 0xFB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XFB8);
    // 0x804445A8: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x804445AC: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x804445B0: ori         $a0, $a0, 0x3FFF
    ctx->r4 = ctx->r4 | 0X3FFF;
    // 0x804445B4: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
    // 0x804445B8: and         $t8, $t6, $a0
    ctx->r24 = ctx->r14 & ctx->r4;
    // 0x804445BC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x804445C0: bgez        $t0, L_804445DC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x804445C4: sw          $t8, 0xF54($v1)
        MEM_W(0XF54, ctx->r3) = ctx->r24;
            goto L_804445DC;
    }
    // 0x804445C4: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
    // 0x804445C8: ori         $t2, $t8, 0x40
    ctx->r10 = ctx->r24 | 0X40;
    // 0x804445CC: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
    // 0x804445D0: ori         $t4, $t2, 0x1000
    ctx->r12 = ctx->r10 | 0X1000;
    // 0x804445D4: b           L_804445F8
    // 0x804445D8: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
        goto L_804445F8;
    // 0x804445D8: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
L_804445DC:
    // 0x804445DC: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    // 0x804445E0: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x804445E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x804445E8: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x804445EC: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
    // 0x804445F0: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x804445F4: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
L_804445F8:
    // 0x804445F8: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x804445FC: bgezl       $t0, L_80444620
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80444600: lw          $t5, 0xF54($v1)
        ctx->r13 = MEM_W(ctx->r3, 0XF54);
            goto L_80444620;
    }
    goto skip_0;
    // 0x80444600: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    skip_0:
    // 0x80444604: lw          $t1, 0xF54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XF54);
    // 0x80444608: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x8044460C: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
    // 0x80444610: ori         $t4, $t2, 0x2000
    ctx->r12 = ctx->r10 | 0X2000;
    // 0x80444614: b           L_80444638
    // 0x80444618: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
        goto L_80444638;
    // 0x80444618: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
    // 0x8044461C: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
L_80444620:
    // 0x80444620: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80444624: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80444628: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x8044462C: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
    // 0x80444630: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80444634: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
L_80444638:
    // 0x80444638: lhu         $t9, 0x13B4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X13B4);
    // 0x8044463C: sw          $zero, 0xCD0($v1)
    MEM_W(0XCD0, ctx->r3) = 0;
    // 0x80444640: sw          $zero, 0xCD4($v1)
    MEM_W(0XCD4, ctx->r3) = 0;
    // 0x80444644: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x80444648: sw          $zero, 0xCD8($v1)
    MEM_W(0XCD8, ctx->r3) = 0;
    // 0x8044464C: sw          $zero, 0xCDC($v1)
    MEM_W(0XCDC, ctx->r3) = 0;
    // 0x80444650: sw          $zero, 0xCE0($v1)
    MEM_W(0XCE0, ctx->r3) = 0;
    // 0x80444654: beq         $t0, $zero, L_80444838
    if (ctx->r8 == 0) {
        // 0x80444658: sw          $zero, 0xCEC($v1)
        MEM_W(0XCEC, ctx->r3) = 0;
            goto L_80444838;
    }
    // 0x80444658: sw          $zero, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = 0;
    // 0x8044465C: lhu         $t1, 0x13A8($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X13A8);
    // 0x80444660: lhu         $t4, 0x13AE($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X13AE);
    // 0x80444664: lhu         $t2, 0x13AA($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X13AA);
    // 0x80444668: lhu         $t5, 0x13B0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X13B0);
    // 0x8044466C: lhu         $t3, 0x13AC($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X13AC);
    // 0x80444670: sw          $t4, 0xCDC($v1)
    MEM_W(0XCDC, ctx->r3) = ctx->r12;
    // 0x80444674: lw          $t6, 0xCDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XCDC);
    // 0x80444678: sw          $t1, 0xCD0($v1)
    MEM_W(0XCD0, ctx->r3) = ctx->r9;
    // 0x8044467C: sw          $t1, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = ctx->r9;
    // 0x80444680: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80444684: sw          $t5, 0xCE0($v1)
    MEM_W(0XCE0, ctx->r3) = ctx->r13;
    // 0x80444688: lw          $t9, 0xCE0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XCE0);
    // 0x8044468C: lw          $v0, 0x13B0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X13B0);
    // 0x80444690: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80444694: sw          $t1, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = ctx->r9;
    // 0x80444698: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8044469C: sw          $t4, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = ctx->r12;
    // 0x804446A0: sw          $t2, 0xCD4($v1)
    MEM_W(0XCD4, ctx->r3) = ctx->r10;
    // 0x804446A4: sw          $t7, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = ctx->r15;
    // 0x804446A8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804446AC: sll         $t2, $v0, 21
    ctx->r10 = S32(ctx->r2 << 21);
    // 0x804446B0: sw          $t0, 0xCEC($v1)
    MEM_W(0XCEC, ctx->r3) = ctx->r8;
    // 0x804446B4: bgez        $t2, L_804446CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x804446B8: sw          $t3, 0xCD8($v1)
        MEM_W(0XCD8, ctx->r3) = ctx->r11;
            goto L_804446CC;
    }
    // 0x804446B8: sw          $t3, 0xCD8($v1)
    MEM_W(0XCD8, ctx->r3) = ctx->r11;
    // 0x804446BC: lw          $t3, 0xF54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF54);
    // 0x804446C0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x804446C4: b           L_804446DC
    // 0x804446C8: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
        goto L_804446DC;
    // 0x804446C8: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
L_804446CC:
    // 0x804446CC: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    // 0x804446D0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x804446D4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x804446D8: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
L_804446DC:
    // 0x804446DC: sll         $t8, $v0, 19
    ctx->r24 = S32(ctx->r2 << 19);
    // 0x804446E0: bgez        $t8, L_804446F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x804446E4: sll         $t4, $v0, 18
        ctx->r12 = S32(ctx->r2 << 18);
            goto L_804446F8;
    }
    // 0x804446E4: sll         $t4, $v0, 18
    ctx->r12 = S32(ctx->r2 << 18);
    // 0x804446E8: lw          $t9, 0xF54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF54);
    // 0x804446EC: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x804446F0: b           L_80444708
    // 0x804446F4: sw          $t0, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r8;
        goto L_80444708;
    // 0x804446F4: sw          $t0, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r8;
L_804446F8:
    // 0x804446F8: lw          $t1, 0xF54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XF54);
    // 0x804446FC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80444700: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80444704: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
L_80444708:
    // 0x80444708: bgez        $t4, L_80444720
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8044470C: sll         $t0, $v0, 22
        ctx->r8 = S32(ctx->r2 << 22);
            goto L_80444720;
    }
    // 0x8044470C: sll         $t0, $v0, 22
    ctx->r8 = S32(ctx->r2 << 22);
    // 0x80444710: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    // 0x80444714: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80444718: b           L_80444730
    // 0x8044471C: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
        goto L_80444730;
    // 0x8044471C: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
L_80444720:
    // 0x80444720: lw          $t7, 0xF54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XF54);
    // 0x80444724: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80444728: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8044472C: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
L_80444730:
    // 0x80444730: bgezl       $t0, L_8044474C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80444734: lw          $t3, 0xF54($v1)
        ctx->r11 = MEM_W(ctx->r3, 0XF54);
            goto L_8044474C;
    }
    goto skip_1;
    // 0x80444734: lw          $t3, 0xF54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF54);
    skip_1:
    // 0x80444738: lw          $t1, 0xF54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XF54);
    // 0x8044473C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80444740: b           L_80444758
    // 0x80444744: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
        goto L_80444758;
    // 0x80444744: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
    // 0x80444748: lw          $t3, 0xF54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF54);
L_8044474C:
    // 0x8044474C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80444750: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80444754: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
L_80444758:
    // 0x80444758: lbu         $t5, 0x13B2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B2);
    // 0x8044475C: sll         $t2, $v0, 20
    ctx->r10 = S32(ctx->r2 << 20);
    // 0x80444760: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80444764: beql        $t6, $zero, L_80444780
    if (ctx->r14 == 0) {
        // 0x80444768: lw          $t9, 0xF54($v1)
        ctx->r25 = MEM_W(ctx->r3, 0XF54);
            goto L_80444780;
    }
    goto skip_2;
    // 0x80444768: lw          $t9, 0xF54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF54);
    skip_2:
    // 0x8044476C: lw          $t7, 0xF54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XF54);
    // 0x80444770: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80444774: b           L_8044478C
    // 0x80444778: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
        goto L_8044478C;
    // 0x80444778: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
    // 0x8044477C: lw          $t9, 0xF54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF54);
L_80444780:
    // 0x80444780: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80444784: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80444788: sw          $t0, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r8;
L_8044478C:
    // 0x8044478C: bgez        $t2, L_804447A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80444790: sll         $t8, $v0, 17
        ctx->r24 = S32(ctx->r2 << 17);
            goto L_804447A4;
    }
    // 0x80444790: sll         $t8, $v0, 17
    ctx->r24 = S32(ctx->r2 << 17);
    // 0x80444794: lw          $t3, 0xF54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF54);
    // 0x80444798: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8044479C: b           L_804447B4
    // 0x804447A0: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
        goto L_804447B4;
    // 0x804447A0: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
L_804447A4:
    // 0x804447A4: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    // 0x804447A8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x804447AC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x804447B0: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
L_804447B4:
    // 0x804447B4: bgezl       $t8, L_804447D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x804447B8: lw          $t1, 0xF54($v1)
        ctx->r9 = MEM_W(ctx->r3, 0XF54);
            goto L_804447D0;
    }
    goto skip_3;
    // 0x804447B8: lw          $t1, 0xF54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XF54);
    skip_3:
    // 0x804447BC: lw          $t9, 0xF54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF54);
    // 0x804447C0: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x804447C4: b           L_804447DC
    // 0x804447C8: sw          $t0, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r8;
        goto L_804447DC;
    // 0x804447C8: sw          $t0, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r8;
    // 0x804447CC: lw          $t1, 0xF54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XF54);
L_804447D0:
    // 0x804447D0: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x804447D4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x804447D8: sw          $t2, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r10;
L_804447DC:
    // 0x804447DC: lh          $t4, 0x13B2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X13B2);
    // 0x804447E0: bgezl       $t4, L_804447FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x804447E4: lw          $t7, 0xF54($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XF54);
            goto L_804447FC;
    }
    goto skip_4;
    // 0x804447E4: lw          $t7, 0xF54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XF54);
    skip_4:
    // 0x804447E8: lw          $t5, 0xF54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XF54);
    // 0x804447EC: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x804447F0: b           L_80444808
    // 0x804447F4: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
        goto L_80444808;
    // 0x804447F4: sw          $t6, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r14;
    // 0x804447F8: lw          $t7, 0xF54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XF54);
L_804447FC:
    // 0x804447FC: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80444800: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80444804: sw          $t8, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r24;
L_80444808:
    // 0x80444808: lw          $t1, 0x13B4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X13B4);
    // 0x8044480C: lw          $t9, 0xF54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF54);
    // 0x80444810: lbu         $t5, 0x13B3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B3);
    // 0x80444814: srl         $t2, $t1, 29
    ctx->r10 = S32(U32(ctx->r9) >> 29);
    // 0x80444818: sll         $t3, $t2, 14
    ctx->r11 = S32(ctx->r10 << 14);
    // 0x8044481C: and         $t0, $t9, $a0
    ctx->r8 = ctx->r25 & ctx->r4;
    // 0x80444820: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80444824: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80444828: srl         $t6, $t5, 6
    ctx->r14 = S32(U32(ctx->r13) >> 6);
    // 0x8044482C: sw          $t4, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r12;
    // 0x80444830: sw          $t6, 0xAA0($v1)
    MEM_W(0XAA0, ctx->r3) = ctx->r14;
    // 0x80444834: sw          $t7, 0xFB4($v1)
    MEM_W(0XFB4, ctx->r3) = ctx->r15;
L_80444838:
    // 0x80444838: jr          $ra
    // 0x8044483C: nop

    return;
    // 0x8044483C: nop

;}
RECOMP_FUNC void func_804CF240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF240: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CF244: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF248: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804CF24C: jr          $ra
    // 0x804CF250: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x804CF250: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8000B164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B164: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000B168: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8000B16C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000B170: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000B174: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8000B178: nop

    // 0x8000B17C: bc1fl       L_8000B1B4
    if (!c1cs) {
        // 0x8000B180: lbu         $t9, 0x1($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1);
            goto L_8000B1B4;
    }
    goto skip_0;
    // 0x8000B180: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    skip_0:
    // 0x8000B184: lwc1        $f2, -0x42E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42E8);
    // 0x8000B188: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8000B18C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8000B190: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8000B194: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8000B198: bc1f        L_8000B1A8
    if (!c1cs) {
        // 0x8000B19C: nop
    
            goto L_8000B1A8;
    }
    // 0x8000B19C: nop

    // 0x8000B1A0: b           L_8000B1F4
    // 0x8000B1A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000B1F4;
    // 0x8000B1A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000B1A8:
    // 0x8000B1A8: b           L_8000B1F4
    // 0x8000B1AC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8000B1F4;
    // 0x8000B1AC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8000B1B0: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
L_8000B1B4:
    // 0x8000B1B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000B1B8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8000B1BC: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x8000B1C0: lwc1        $f6, -0x42E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42E4);
    // 0x8000B1C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000B1C8: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8000B1CC: nop

    // 0x8000B1D0: bc1fl       L_8000B1E8
    if (!c1cs) {
        // 0x8000B1D4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8000B1E8;
    }
    goto skip_1;
    // 0x8000B1D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x8000B1D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000B1DC: b           L_8000B1F4
    // 0x8000B1E0: lwc1        $f0, -0x42E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X42E0);
        goto L_8000B1F4;
    // 0x8000B1E0: lwc1        $f0, -0x42E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X42E0);
    // 0x8000B1E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8000B1E8:
    // 0x8000B1E8: nop

    // 0x8000B1EC: mul.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8000B1F0: nop

L_8000B1F4:
    // 0x8000B1F4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8000B1F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000B1FC: nop

    // 0x8000B200: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000B204: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000B208: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000B20C: jr          $ra
    // 0x8000B210: sh          $t2, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r10;
    return;
    // 0x8000B210: sh          $t2, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_804BDB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDB70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BDB74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804BDB78: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X227C) << 16);
    // 0x804BDB7C: addiu       $t7, $t7, -0x2454
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X227C));
    // 0x804BDB80: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x804BDB84: lw          $t6, 0x350($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X350);
    // 0x804BDB88: slti        $at, $t6, 0x11
    ctx->r1 = SIGNED(ctx->r14) < 0X11 ? 1 : 0;
    // 0x804BDB8C: bne         $at, $zero, L_804BDBA4
    if (ctx->r1 != 0) {
        // 0x804BDB90: nop
    
            goto L_804BDBA4;
    }
    // 0x804BDB90: nop

    // 0x804BDB94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804BDB98: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    // 0x804BDB9C: sw          $t7, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r15;
    // 0x804BDBA0: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
L_804BDBA4:
    // 0x804BDBA4: jr          $ra
    // 0x804BDBA8: nop

    return;
    // 0x804BDBA8: nop

;}
RECOMP_FUNC void func_805AA478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA480: jal         0x805AA510
    // 0x805AA484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AA510(rdram, ctx);
        goto after_0;
    // 0x805AA484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA488: beq         $v0, $zero, L_805AA4F8
    if (ctx->r2 == 0) {
        // 0x805AA48C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805AA4F8;
    }
    // 0x805AA48C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA490: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805AA494: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA498: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805AA49C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805AA4A0: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x805AA4A4: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA4A8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805AA4AC: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(432, 0XAA0) << 16);
    // 0x805AA4B0: sw          $a3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r7;
    // 0x805AA4B4: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA4B8: addiu       $t0, $t0, -0x5270
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(432, 0XAA0));
    // 0x805AA4BC: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x805AA4C0: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x805AA4C4: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x805AA4C8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805AA4CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805AA4D0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x805AA4D4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805AA4D8: sw          $a3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r7;
    // 0x805AA4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AA4E0: jal         0x805AABAC
    // 0x805AA4E4: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    func_805AABAC(rdram, ctx);
        goto after_1;
    // 0x805AA4E4: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_1:
    // 0x805AA4E8: jal         0x805AA338
    // 0x805AA4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AA338(rdram, ctx);
        goto after_2;
    // 0x805AA4EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805AA4F0: b           L_805AA504
    // 0x805AA4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AA504;
    // 0x805AA4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA4F8:
    // 0x805AA4F8: jal         0x800445A4
    // 0x805AA4FC: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x805AA4FC: nop

    after_3:
    // 0x805AA500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA504:
    // 0x805AA504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA508: jr          $ra
    // 0x805AA50C: nop

    return;
    // 0x805AA50C: nop

;}
RECOMP_FUNC void func_8077FEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FEF4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8077FEF8: lui         $t6, 0x8078
    ctx->r14 = S32(RELOC_HI16(781, 0XDC) << 16);
    // 0x8077FEFC: addiu       $t6, $t6, -0x614
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(781, 0XDC));
    // 0x8077FF00: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8077FF04: jr          $ra
    // 0x8077FF08: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x8077FF08: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80438628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043862C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80438630: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80438634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438638: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043863C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80438640: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80438644: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80438648: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043864C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80438650: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(77, 0X1F58) << 16);
    // 0x80438654: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80438658: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043865C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80438660: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80438664: lw          $t2, -0x7808($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(77, 0X1F58));
    // 0x80438668: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043866C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80438670: jal         0x80436C50
    // 0x80438674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80436C50(rdram, ctx);
        goto after_0;
    // 0x80438674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80438678: jal         0x80436CAC
    // 0x8043867C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80436CAC(rdram, ctx);
        goto after_1;
    // 0x8043867C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80438680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438688: jr          $ra
    // 0x8043868C: nop

    return;
    // 0x8043868C: nop

;}
RECOMP_FUNC void func_80039030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039038: jal         0x8004700C
    // 0x8003903C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003903C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80039040: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80039044: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80039048: jal         0x80066DE4
    // 0x8003904C: lwc1        $f12, 0x194($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X194);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8003904C: lwc1        $f12, 0x194($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X194);
    after_1:
    // 0x80039050: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80039054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039058: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003905C: lwc1        $f8, -0x7670($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7670);
    // 0x80039060: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80039064: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80039068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003906C: nop

    // 0x80039070: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80039074: jal         0x800659EC
    // 0x80039078: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800659EC(rdram, ctx);
        goto after_2;
    // 0x80039078: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8003907C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80039080: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80039084: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80039088: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x8003908C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80039090: lw          $t0, 0x70($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X70);
    // 0x80039094: jal         0x80066DE4
    // 0x80039098: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80039098: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003909C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800390A0: jal         0x80066E88
    // 0x800390A4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x800390A4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800390A8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800390AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800390B0: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800390B4: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800390B8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800390BC: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x800390C0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800390C4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800390C8: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800390CC: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800390D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800390D4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800390D8: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800390DC: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800390E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800390E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800390E8: jr          $ra
    // 0x800390EC: nop

    return;
    // 0x800390EC: nop

;}
RECOMP_FUNC void func_8044BFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BFA8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8044BFAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044BFB0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8044BFB4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8044BFB8: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8044BFBC: lh          $t0, 0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X4);
    // 0x8044BFC0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8044BFC4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8044BFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044BFCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8044BFD0: blez        $t0, L_8044C010
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8044BFD4: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8044C010;
    }
    // 0x8044BFD4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_8044BFD8:
    // 0x8044BFD8: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x8044BFDC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8044BFE0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8044BFE4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8044BFE8: beql        $at, $zero, L_8044C000
    if (ctx->r1 == 0) {
        // 0x8044BFEC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8044C000;
    }
    goto skip_0;
    // 0x8044BFEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8044BFF0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8044BFF4: b           L_8044C010
    // 0x8044BFF8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_8044C010;
    // 0x8044BFF8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8044BFFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8044C000:
    // 0x8044C000: bne         $v1, $t0, L_8044BFD8
    if (ctx->r3 != ctx->r8) {
        // 0x8044C004: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_8044BFD8;
    }
    // 0x8044C004: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8044C008: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8044C00C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8044C010:
    // 0x8044C010: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8044C014: bne         $at, $zero, L_8044C048
    if (ctx->r1 != 0) {
        // 0x8044C018: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_8044C048;
    }
    // 0x8044C018: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8044C01C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8044C020: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C024: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x8044C028: mflo        $t7
    ctx->r15 = lo;
    // 0x8044C02C: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
    // 0x8044C030: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x8044C034: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x8044C038: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8044C03C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8044C040: b           L_8044C1B8
    // 0x8044C044: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
        goto L_8044C1B8;
    // 0x8044C044: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_8044C048:
    // 0x8044C048: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x8044C04C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8044C050: addiu       $a1, $v1, 0x2
    ctx->r5 = ADD32(ctx->r3, 0X2);
    // 0x8044C054: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x8044C058: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8044C05C: bgez        $a2, L_8044C068
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8044C060: or          $t4, $a1, $zero
        ctx->r12 = ctx->r5 | 0;
            goto L_8044C068;
    }
    // 0x8044C060: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x8044C064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8044C068:
    // 0x8044C068: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8044C06C: bne         $at, $zero, L_8044C078
    if (ctx->r1 != 0) {
        // 0x8044C070: addiu       $t3, $zero, 0x14
        ctx->r11 = ADD32(0, 0X14);
            goto L_8044C078;
    }
    // 0x8044C070: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8044C074: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
L_8044C078:
    // 0x8044C078: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8044C07C: bne         $at, $zero, L_8044C088
    if (ctx->r1 != 0) {
        // 0x8044C080: nop
    
            goto L_8044C088;
    }
    // 0x8044C080: nop

    // 0x8044C084: addiu       $t4, $t0, -0x1
    ctx->r12 = ADD32(ctx->r8, -0X1);
L_8044C088:
    // 0x8044C088: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C08C: mflo        $t8
    ctx->r24 = lo;
    // 0x8044C090: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x8044C094: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8044C098: lbu         $t6, 0x12($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X12);
    // 0x8044C09C: bne         $t6, $zero, L_8044C0AC
    if (ctx->r14 != 0) {
        // 0x8044C0A0: nop
    
            goto L_8044C0AC;
    }
    // 0x8044C0A0: nop

    // 0x8044C0A4: bne         $v1, $t1, L_8044C0CC
    if (ctx->r3 != ctx->r9) {
        // 0x8044C0A8: nop
    
            goto L_8044C0CC;
    }
    // 0x8044C0A8: nop

L_8044C0AC:
    // 0x8044C0AC: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C0B0: mflo        $t7
    ctx->r15 = lo;
    // 0x8044C0B4: addu        $s0, $t7, $a3
    ctx->r16 = ADD32(ctx->r15, ctx->r7);
    // 0x8044C0B8: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x8044C0BC: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8044C0C0: sw          $s0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r16;
    // 0x8044C0C4: b           L_8044C1B8
    // 0x8044C0C8: sw          $s0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r16;
        goto L_8044C1B8;
    // 0x8044C0C8: sw          $s0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r16;
L_8044C0CC:
    // 0x8044C0CC: multu       $a2, $t3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C0D0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8044C0D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8044C0D8: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8044C0DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8044C0E0: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x8044C0E4: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x8044C0E8: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C0EC: mflo        $t6
    ctx->r14 = lo;
    // 0x8044C0F0: addu        $s0, $t6, $a3
    ctx->r16 = ADD32(ctx->r14, ctx->r7);
    // 0x8044C0F4: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x8044C0F8: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044C100: mflo        $t8
    ctx->r24 = lo;
    // 0x8044C104: addu        $v0, $t8, $a3
    ctx->r2 = ADD32(ctx->r24, ctx->r7);
    // 0x8044C108: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x8044C10C: lbu         $t9, 0x12($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X12);
    // 0x8044C110: bnel        $t9, $zero, L_8044C120
    if (ctx->r25 != 0) {
        // 0x8044C114: addiu       $a2, $sp, 0x78
        ctx->r6 = ADD32(ctx->r29, 0X78);
            goto L_8044C120;
    }
    goto skip_1;
    // 0x8044C114: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    skip_1:
    // 0x8044C118: bne         $a2, $v1, L_8044C16C
    if (ctx->r6 != ctx->r3) {
        // 0x8044C11C: addiu       $a2, $sp, 0x78
        ctx->r6 = ADD32(ctx->r29, 0X78);
            goto L_8044C16C;
    }
    // 0x8044C11C: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
L_8044C120:
    // 0x8044C120: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8044C124: sw          $v1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r3;
    // 0x8044C128: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8044C12C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8044C130: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8044C134: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8044C138: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8044C13C: jal         0x8044BE84
    // 0x8044C140: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    func_8044BE84(rdram, ctx);
        goto after_0;
    // 0x8044C140: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_0:
    // 0x8044C144: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x8044C148: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8044C14C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8044C150: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8044C154: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8044C158: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8044C15C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8044C160: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8044C164: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8044C168: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8044C16C:
    // 0x8044C16C: lbu         $t7, 0x12($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12);
    // 0x8044C170: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8044C174: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8044C178: bne         $t7, $zero, L_8044C188
    if (ctx->r15 != 0) {
        // 0x8044C17C: addiu       $a2, $sp, 0x64
        ctx->r6 = ADD32(ctx->r29, 0X64);
            goto L_8044C188;
    }
    // 0x8044C17C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8044C180: bne         $t1, $t4, L_8044C1B8
    if (ctx->r9 != ctx->r12) {
        // 0x8044C184: nop
    
            goto L_8044C1B8;
    }
    // 0x8044C184: nop

L_8044C188:
    // 0x8044C188: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8044C18C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8044C190: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8044C194: jal         0x8044BE84
    // 0x8044C198: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    func_8044BE84(rdram, ctx);
        goto after_1;
    // 0x8044C198: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_1:
    // 0x8044C19C: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x8044C1A0: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8044C1A4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8044C1A8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8044C1AC: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8044C1B0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8044C1B4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
L_8044C1B8:
    // 0x8044C1B8: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8044C1BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8044C1C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8044C1C4: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x8044C1C8: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8044C1CC: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8044C1D0: mflo        $t9
    ctx->r25 = lo;
    // 0x8044C1D4: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x8044C1D8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8044C1DC: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8044C1E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8044C1E4: bgez        $t7, L_8044C1F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8044C1E8: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8044C1F8;
    }
    // 0x8044C1E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044C1EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044C1F0: nop

    // 0x8044C1F4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8044C1F8:
    // 0x8044C1F8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8044C1FC: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8044C200: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8044C204: bc1tl       L_8044C23C
    if (c1cs) {
        // 0x8044C208: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8044C23C;
    }
    goto skip_2;
    // 0x8044C208: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x8044C20C: beq         $at, $zero, L_8044C230
    if (ctx->r1 == 0) {
        // 0x8044C210: nop
    
            goto L_8044C230;
    }
    // 0x8044C210: nop

    // 0x8044C214: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x8044C218: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8044C21C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044C220: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044C224: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8044C228: b           L_8044C23C
    // 0x8044C22C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
        goto L_8044C23C;
    // 0x8044C22C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_8044C230:
    // 0x8044C230: b           L_8044C23C
    // 0x8044C234: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8044C23C;
    // 0x8044C234: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8044C238: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8044C23C:
    // 0x8044C23C: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8044C240: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8044C244: jal         0x8044BBB0
    // 0x8044C248: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_8044BBB0(rdram, ctx);
        goto after_2;
    // 0x8044C248: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
    // 0x8044C24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044C250: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8044C254: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8044C258: jr          $ra
    // 0x8044C25C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8044C25C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_804D84B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D84B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804D84BC: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x804D84C0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x804D84C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804D84C8: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x804D84CC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x804D84D0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x804D84D4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x804D84D8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x804D84DC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x804D84E0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804D84E4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804D84E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x804D84EC: lw          $s6, 0x174($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X174);
    // 0x804D84F0: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x804D84F4: addiu       $s7, $a0, 0xC4
    ctx->r23 = ADD32(ctx->r4, 0XC4);
    // 0x804D84F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x804D84FC: jal         0x80048F84
    // 0x804D8500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x804D8500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x804D8504: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x804D8508: jal         0x80048F84
    // 0x804D850C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804D850C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804D8510: lwc1        $f4, 0x50($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804D8514: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x804D8518: lui         $t0, 0x804E
    ctx->r8 = S32(RELOC_HI16(255, 0X6F8) << 16);
    // 0x804D851C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804D8520: addiu       $t0, $t0, -0x75D8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(255, 0X6F8));
    // 0x804D8524: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x804D8528: nop

    // 0x804D852C: div         $zero, $a0, $a3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r7)));
    // 0x804D8530: bne         $a3, $zero, L_804D853C
    if (ctx->r7 != 0) {
        // 0x804D8534: nop
    
            goto L_804D853C;
    }
    // 0x804D8534: nop

    // 0x804D8538: break       7
    do_break(2152564024);
L_804D853C:
    // 0x804D853C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804D8540: bne         $a3, $at, L_804D8554
    if (ctx->r7 != ctx->r1) {
        // 0x804D8544: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804D8554;
    }
    // 0x804D8544: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804D8548: bne         $a0, $at, L_804D8554
    if (ctx->r4 != ctx->r1) {
        // 0x804D854C: nop
    
            goto L_804D8554;
    }
    // 0x804D854C: nop

    // 0x804D8550: break       6
    do_break(2152564048);
L_804D8554:
    // 0x804D8554: mflo        $a1
    ctx->r5 = lo;
    // 0x804D8558: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x804D855C: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x804D8560: bne         $at, $zero, L_804D856C
    if (ctx->r1 != 0) {
        // 0x804D8564: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_804D856C;
    }
    // 0x804D8564: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x804D8568: addiu       $a2, $v0, -0x12
    ctx->r6 = ADD32(ctx->r2, -0X12);
L_804D856C:
    // 0x804D856C: div         $zero, $a0, $a3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r7)));
    // 0x804D8570: lh          $v1, 0x144($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X144);
    // 0x804D8574: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x804D8578: mfhi        $v0
    ctx->r2 = hi;
    // 0x804D857C: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x804D8580: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x804D8584: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x804D8588: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x804D858C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x804D8590: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x804D8594: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x804D8598: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x804D859C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x804D85A0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x804D85A4: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804D85A8: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x804D85AC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x804D85B0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x804D85B4: subu        $t9, $a3, $v0
    ctx->r25 = SUB32(ctx->r7, ctx->r2);
    // 0x804D85B8: bne         $a3, $zero, L_804D85C4
    if (ctx->r7 != 0) {
        // 0x804D85BC: nop
    
            goto L_804D85C4;
    }
    // 0x804D85BC: nop

    // 0x804D85C0: break       7
    do_break(2152564160);
L_804D85C4:
    // 0x804D85C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804D85C8: bne         $a3, $at, L_804D85DC
    if (ctx->r7 != ctx->r1) {
        // 0x804D85CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804D85DC;
    }
    // 0x804D85CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804D85D0: bne         $a0, $at, L_804D85DC
    if (ctx->r4 != ctx->r1) {
        // 0x804D85D4: nop
    
            goto L_804D85DC;
    }
    // 0x804D85D4: nop

    // 0x804D85D8: break       6
    do_break(2152564184);
L_804D85DC:
    // 0x804D85DC: mflo        $t3
    ctx->r11 = lo;
    // 0x804D85E0: lui         $at, 0x804E
    ctx->r1 = S32(RELOC_HI16(255, 0X8C0) << 16);
    // 0x804D85E4: lwc1        $f16, -0x7410($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(255, 0X8C0));
    // 0x804D85E8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804D85EC: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x804D85F0: lui         $at, 0x804E
    ctx->r1 = S32(RELOC_HI16(255, 0X8C4) << 16);
    // 0x804D85F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804D85F8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x804D85FC: mflo        $t1
    ctx->r9 = lo;
    // 0x804D8600: addu        $t2, $t3, $t1
    ctx->r10 = ADD32(ctx->r11, ctx->r9);
    // 0x804D8604: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x804D8608: nop

    // 0x804D860C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804D8610: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804D8614: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x804D8618: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x804D861C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804D8620: nop

    // 0x804D8624: bc1f        L_804D8654
    if (!c1cs) {
        // 0x804D8628: nop
    
            goto L_804D8654;
    }
    // 0x804D8628: nop

    // 0x804D862C: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x804D8630: lwc1        $f6, -0x740C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(255, 0X8C4));
    // 0x804D8634: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804D8638: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804D863C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804D8640: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x804D8644: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x804D8648: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804D864C: swc1        $f4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f4.u32l;
    // 0x804D8650: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
L_804D8654:
    // 0x804D8654: jal         0x80049D74
    // 0x804D8658: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x804D8658: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    after_2:
    // 0x804D865C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x804D8660: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x804D8664: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x804D8668: lui         $s5, 0x8005
    ctx->r21 = S32(0X8005 << 16);
    // 0x804D866C: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x804D8670: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804D8674: addiu       $s3, $s3, 0x5284
    ctx->r19 = ADD32(ctx->r19, 0X5284);
    // 0x804D8678: addiu       $s5, $s5, -0x3108
    ctx->r21 = ADD32(ctx->r21, -0X3108);
    // 0x804D867C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_804D8680:
    // 0x804D8680: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x804D8684: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x804D8688: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x804D868C: sub.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x804D8690: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x804D8694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804D8698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804D869C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x804D86A0: jal         0x8004D150
    // 0x804D86A4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x804D86A4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x804D86A8: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x804D86AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804D86B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804D86B4: lw          $t5, 0x40($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X40);
    // 0x804D86B8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x804D86BC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x804D86C0: beql        $t7, $zero, L_804D86D8
    if (ctx->r15 == 0) {
        // 0x804D86C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_804D86D8;
    }
    goto skip_0;
    // 0x804D86C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x804D86C8: jal         0x8004D618
    // 0x804D86CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x804D86CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x804D86D0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x804D86D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_804D86D8:
    // 0x804D86D8: sltiu       $at, $s0, 0x3
    ctx->r1 = ctx->r16 < 0X3 ? 1 : 0;
    // 0x804D86DC: bne         $at, $zero, L_804D8680
    if (ctx->r1 != 0) {
        // 0x804D86E0: sub.s       $f20, $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
            goto L_804D8680;
    }
    // 0x804D86E0: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x804D86E4: lw          $t8, 0x68($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X68);
    // 0x804D86E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804D86EC: bnel        $t8, $at, L_804D873C
    if (ctx->r24 != ctx->r1) {
        // 0x804D86F0: lwc1        $f8, 0x50($s2)
        ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
            goto L_804D873C;
    }
    goto skip_1;
    // 0x804D86F0: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
    skip_1:
    // 0x804D86F4: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804D86F8: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x804D86FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804D8700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804D8704: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x804D8708: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x804D870C: swc1        $f16, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f16.u32l;
    // 0x804D8710: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804D8714: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804D8718: nop

    // 0x804D871C: bc1fl       L_804D8778
    if (!c1cs) {
        // 0x804D8720: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804D8778;
    }
    goto skip_2;
    // 0x804D8720: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x804D8724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804D8728: nop

    // 0x804D872C: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x804D8730: b           L_804D8774
    // 0x804D8734: swc1        $f10, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f10.u32l;
        goto L_804D8774;
    // 0x804D8734: swc1        $f10, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f10.u32l;
    // 0x804D8738: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
L_804D873C:
    // 0x804D873C: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x804D8740: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804D8744: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804D8748: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x804D874C: swc1        $f16, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f16.u32l;
    // 0x804D8750: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804D8754: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804D8758: nop

    // 0x804D875C: bc1fl       L_804D8778
    if (!c1cs) {
        // 0x804D8760: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804D8778;
    }
    goto skip_3;
    // 0x804D8760: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x804D8764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804D8768: nop

    // 0x804D876C: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x804D8770: swc1        $f10, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f10.u32l;
L_804D8774:
    // 0x804D8774: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804D8778:
    // 0x804D8778: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804D877C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804D8780: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x804D8784: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x804D8788: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x804D878C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x804D8790: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x804D8794: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x804D8798: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x804D879C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x804D87A0: jr          $ra
    // 0x804D87A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804D87A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804C537C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C537C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x804C5380: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x804C5384: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804C5388: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x804C538C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x804C5390: sltu        $at, $t8, $t7
    ctx->r1 = ctx->r24 < ctx->r15 ? 1 : 0;
    // 0x804C5394: beq         $at, $zero, L_804C53BC
    if (ctx->r1 == 0) {
        // 0x804C5398: nop
    
            goto L_804C53BC;
    }
    // 0x804C5398: nop

    // 0x804C539C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x804C53A0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x804C53A4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x804C53A8: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x804C53AC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x804C53B0: beq         $t0, $t1, L_804C53BC
    if (ctx->r8 == ctx->r9) {
        // 0x804C53B4: nop
    
            goto L_804C53BC;
    }
    // 0x804C53B4: nop

    // 0x804C53B8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_804C53BC:
    // 0x804C53BC: jr          $ra
    // 0x804C53C0: nop

    return;
    // 0x804C53C0: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086600: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80086604: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80086608: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8008660C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80086610: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80086614: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80086618: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008661C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80086620: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80086624: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80086628: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008662C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80086630: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80086634: jal         0x800863D0
    // 0x80086638: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x80086638: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8008663C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80086640: jal         0x80086DA0
    // 0x80086644: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80086644: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80086648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008664C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80086650: jr          $ra
    // 0x80086654: nop

    return;
    // 0x80086654: nop

;}
RECOMP_FUNC void func_80566674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056667C: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80566680: beql        $v0, $zero, L_805666B8
    if (ctx->r2 == 0) {
        // 0x80566684: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805666B8;
    }
    goto skip_0;
    // 0x80566684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80566688: jalr        $v0
    // 0x8056668C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8056668C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566690: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566694: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80566698: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8056669C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805666A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x805666A4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805666A8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x805666AC: b           L_805666B8
    // 0x805666B0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_805666B8;
    // 0x805666B0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x805666B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805666B8:
    // 0x805666B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805666BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805666C0: jr          $ra
    // 0x805666C4: nop

    return;
    // 0x805666C4: nop

;}
RECOMP_FUNC void func_806F8390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8390: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F8394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F839C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806F83A0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F83A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F83A8: bnel        $t6, $at, L_806F8438
    if (ctx->r14 != ctx->r1) {
        // 0x806F83AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F8438;
    }
    goto skip_0;
    // 0x806F83AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F83B0: jal         0x806F8278
    // 0x806F83B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_806F8278(rdram, ctx);
        goto after_0;
    // 0x806F83B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F83B8: beq         $v0, $zero, L_806F8434
    if (ctx->r2 == 0) {
        // 0x806F83BC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_806F8434;
    }
    // 0x806F83BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806F83C0: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F83C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806F83C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x806F83CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x806F83D0: jal         0x8002F7AC
    // 0x806F83D4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8002F7AC(rdram, ctx);
        goto after_1;
    // 0x806F83D4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x806F83D8: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(694, 0XFC8) << 16);
    // 0x806F83DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806F83E0: addiu       $t9, $t9, -0x7828
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(694, 0XFC8));
    // 0x806F83E4: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x806F83E8: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x806F83EC: jal         0x8005FE48
    // 0x806F83F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806F83F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F83F4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806F83F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806F83FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F8400: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806F8404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F8408: sb          $zero, 0x74($t1)
    MEM_B(0X74, ctx->r9) = 0;
    // 0x806F840C: sw          $zero, 0x5F4($v0)
    MEM_W(0X5F4, ctx->r2) = 0;
    // 0x806F8410: swc1        $f4, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->f4.u32l;
    // 0x806F8414: lh          $t2, 0x144($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X144);
    // 0x806F8418: bnel        $t2, $at, L_806F842C
    if (ctx->r10 != ctx->r1) {
        // 0x806F841C: addiu       $a0, $zero, 0x217
        ctx->r4 = ADD32(0, 0X217);
            goto L_806F842C;
    }
    goto skip_1;
    // 0x806F841C: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    skip_1:
    // 0x806F8420: jal         0x806F824C
    // 0x806F8424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F824C(rdram, ctx);
        goto after_3;
    // 0x806F8424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F8428: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
L_806F842C:
    // 0x806F842C: jal         0x80067818
    // 0x806F8430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806F8430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_806F8434:
    // 0x806F8434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F8438:
    // 0x806F8438: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F843C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F8440: jr          $ra
    // 0x806F8444: nop

    return;
    // 0x806F8444: nop

;}
RECOMP_FUNC void func_804C6E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6E50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C6E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C6E58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C6E5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804C6E60: jal         0x80047090
    // 0x804C6E64: addiu       $a0, $zero, 0x412D
    ctx->r4 = ADD32(0, 0X412D);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804C6E64: addiu       $a0, $zero, 0x412D
    ctx->r4 = ADD32(0, 0X412D);
    after_0:
    // 0x804C6E68: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804C6E6C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804C6E70: beq         $v0, $at, L_804C6EDC
    if (ctx->r2 == ctx->r1) {
        // 0x804C6E74: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_804C6EDC;
    }
    // 0x804C6E74: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x804C6E78: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804C6E7C: lui         $at, 0x412D
    ctx->r1 = S32(0X412D << 16);
    // 0x804C6E80: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x804C6E84: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(221, 0X3B0) << 16);
    // 0x804C6E88: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x804C6E8C: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x804C6E90: addiu       $a0, $a0, 0x7010
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(221, 0X3B0));
    // 0x804C6E94: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x804C6E98: jal         0x80046804
    // 0x804C6E9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804C6E9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804C6EA0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804C6EA4: beq         $v0, $zero, L_804C6EDC
    if (ctx->r2 == 0) {
        // 0x804C6EA8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804C6EDC;
    }
    // 0x804C6EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C6EAC: beq         $v1, $zero, L_804C6ECC
    if (ctx->r3 == 0) {
        // 0x804C6EB0: nop
    
            goto L_804C6ECC;
    }
    // 0x804C6EB0: nop

    // 0x804C6EB4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804C6EB8: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x804C6EBC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804C6EC0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x804C6EC4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804C6EC8: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_804C6ECC:
    // 0x804C6ECC: jal         0x80044194
    // 0x804C6ED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804C6ED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x804C6ED4: b           L_804C6EE0
    // 0x804C6ED8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_804C6EE0;
    // 0x804C6ED8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_804C6EDC:
    // 0x804C6EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C6EE0:
    // 0x804C6EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C6EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C6EE8: jr          $ra
    // 0x804C6EEC: nop

    return;
    // 0x804C6EEC: nop

;}
RECOMP_FUNC void func_807C6334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6334: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807C6338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C633C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C6340: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807C6344: jal         0x8004700C
    // 0x807C6348: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C6348: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x807C634C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x807C6350: beq         $v0, $zero, L_807C6538
    if (ctx->r2 == 0) {
        // 0x807C6354: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_807C6538;
    }
    // 0x807C6354: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C6358: lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X18);
    // 0x807C635C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x807C6360: bne         $a1, $a0, L_807C63B0
    if (ctx->r5 != ctx->r4) {
        // 0x807C6364: nop
    
            goto L_807C63B0;
    }
    // 0x807C6364: nop

    // 0x807C6368: lw          $t6, 0x10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X10);
    // 0x807C636C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C6370: bne         $t6, $zero, L_807C63A8
    if (ctx->r14 != 0) {
        // 0x807C6374: nop
    
            goto L_807C63A8;
    }
    // 0x807C6374: nop

    // 0x807C6378: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C637C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x807C6380: beq         $v1, $at, L_807C63A8
    if (ctx->r3 == ctx->r1) {
        // 0x807C6384: nop
    
            goto L_807C63A8;
    }
    // 0x807C6384: nop

    // 0x807C6388: beq         $a1, $v1, L_807C63A8
    if (ctx->r5 == ctx->r3) {
        // 0x807C638C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_807C63A8;
    }
    // 0x807C638C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x807C6390: beq         $v1, $at, L_807C63A8
    if (ctx->r3 == ctx->r1) {
        // 0x807C6394: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_807C63A8;
    }
    // 0x807C6394: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x807C6398: beq         $v1, $at, L_807C63A8
    if (ctx->r3 == ctx->r1) {
        // 0x807C639C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_807C63A8;
    }
    // 0x807C639C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x807C63A0: bne         $v1, $at, L_807C63B0
    if (ctx->r3 != ctx->r1) {
        // 0x807C63A4: nop
    
            goto L_807C63B0;
    }
    // 0x807C63A4: nop

L_807C63A8:
    // 0x807C63A8: b           L_807C6538
    // 0x807C63AC: sw          $t7, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r15;
        goto L_807C6538;
    // 0x807C63AC: sw          $t7, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r15;
L_807C63B0:
    // 0x807C63B0: bne         $a1, $a0, L_807C6428
    if (ctx->r5 != ctx->r4) {
        // 0x807C63B4: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_807C6428;
    }
    // 0x807C63B4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807C63B8: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x807C63BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807C63C0: bne         $t8, $zero, L_807C6420
    if (ctx->r24 != 0) {
        // 0x807C63C4: nop
    
            goto L_807C6420;
    }
    // 0x807C63C4: nop

    // 0x807C63C8: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C63CC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x807C63D0: beq         $v1, $zero, L_807C6420
    if (ctx->r3 == 0) {
        // 0x807C63D4: nop
    
            goto L_807C6420;
    }
    // 0x807C63D4: nop

    // 0x807C63D8: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C63DC: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_807C6420;
    }
    // 0x807C63DC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x807C63E0: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C63E4: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_807C6420;
    }
    // 0x807C63E4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x807C63E8: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C63EC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_807C6420;
    }
    // 0x807C63EC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x807C63F0: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C63F4: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_807C6420;
    }
    // 0x807C63F4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x807C63F8: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C63FC: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_807C6420;
    }
    // 0x807C63FC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x807C6400: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C6404: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_807C6420;
    }
    // 0x807C6404: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x807C6408: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C640C: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_807C6420;
    }
    // 0x807C640C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x807C6410: beq         $v1, $at, L_807C6420
    if (ctx->r3 == ctx->r1) {
        // 0x807C6414: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_807C6420;
    }
    // 0x807C6414: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x807C6418: bne         $v1, $at, L_807C6428
    if (ctx->r3 != ctx->r1) {
        // 0x807C641C: nop
    
            goto L_807C6428;
    }
    // 0x807C641C: nop

L_807C6420:
    // 0x807C6420: b           L_807C6538
    // 0x807C6424: sw          $t9, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r25;
        goto L_807C6538;
    // 0x807C6424: sw          $t9, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r25;
L_807C6428:
    // 0x807C6428: lw          $t0, -0x72D8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X72D8);
    // 0x807C642C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C6430: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C6434: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x807C6438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C643C: bnel        $t1, $at, L_807C6458
    if (ctx->r9 != ctx->r1) {
        // 0x807C6440: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_807C6458;
    }
    goto skip_0;
    // 0x807C6440: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x807C6444: jal         0x807C66CC
    // 0x807C6448: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807C66CC(rdram, ctx);
        goto after_1;
    // 0x807C6448: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x807C644C: b           L_807C653C
    // 0x807C6450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C653C;
    // 0x807C6450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C6454: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_807C6458:
    // 0x807C6458: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x807C645C: beq         $v0, $zero, L_807C6468
    if (ctx->r2 == 0) {
        // 0x807C6460: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_807C6468;
    }
    // 0x807C6460: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x807C6464: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
L_807C6468:
    // 0x807C6468: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x807C646C: beq         $v0, $zero, L_807C647C
    if (ctx->r2 == 0) {
        // 0x807C6470: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_807C647C;
    }
    // 0x807C6470: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x807C6474: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x807C6478: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_807C647C:
    // 0x807C647C: bnel        $v0, $zero, L_807C64D0
    if (ctx->r2 != 0) {
        // 0x807C6480: lw          $t9, 0x8($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X8);
            goto L_807C64D0;
    }
    goto skip_1;
    // 0x807C6480: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    skip_1:
    // 0x807C6484: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x807C6488: lh          $t5, 0x144($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X144);
    // 0x807C648C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807C6490: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x807C6494: sh          $t7, 0x144($a3)
    MEM_H(0X144, ctx->r7) = ctx->r15;
    // 0x807C6498: lh          $t8, 0x144($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X144);
    // 0x807C649C: bnel        $t8, $zero, L_807C64D0
    if (ctx->r24 != 0) {
        // 0x807C64A0: lw          $t9, 0x8($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X8);
            goto L_807C64D0;
    }
    goto skip_2;
    // 0x807C64A0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    skip_2:
    // 0x807C64A4: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x807C64A8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x807C64AC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807C64B0: jal         0x80067BBC
    // 0x807C64B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x807C64B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x807C64B8: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x807C64BC: jal         0x80067818
    // 0x807C64C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807C64C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807C64C4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x807C64C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C64CC: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
L_807C64D0:
    // 0x807C64D0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X968) << 16);
    // 0x807C64D4: bnel        $t9, $zero, L_807C64F0
    if (ctx->r25 != 0) {
        // 0x807C64D8: lwc1        $f6, 0x14($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
            goto L_807C64F0;
    }
    goto skip_3;
    // 0x807C64D8: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    skip_3:
    // 0x807C64DC: lwc1        $f4, 0x6758($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X968));
    // 0x807C64E0: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x807C64E4: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x807C64E8: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
    // 0x807C64EC: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
L_807C64F0:
    // 0x807C64F0: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x807C64F4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807C64F8: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x807C64FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807C6500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807C6504: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x807C6508: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x807C650C: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x807C6510: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x807C6514: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807C6518: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x807C651C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x807C6520: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807C6524: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807C6528: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x807C652C: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x807C6530: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807C6534: swc1        $f18, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f18.u32l;
L_807C6538:
    // 0x807C6538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C653C:
    // 0x807C653C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807C6540: jr          $ra
    // 0x807C6544: nop

    return;
    // 0x807C6544: nop

;}
RECOMP_FUNC void func_804F4484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4484: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x804F4488: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804F448C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804F4490: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804F4494: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F4498: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F449C: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804F44A0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x804F44A4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x804F44A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F44AC: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804F44B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x804F44B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F44B8: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804F44BC: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x804F44C0: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x804F44C4: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x804F44C8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x804F44CC: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x804F44D0: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x804F44D4: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    // 0x804F44D8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x804F44DC: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804F44E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x804F44E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F44E8: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x804F44EC: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804F44F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804F44F4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x804F44F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F44FC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x804F4500: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x804F4504: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x804F4508: addiu       $t7, $zero, 0x2A
    ctx->r15 = ADD32(0, 0X2A);
    // 0x804F450C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x804F4510: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x804F4514: lui         $t8, 0x8050
    ctx->r24 = S32(RELOC_HI16(273, 0X948C) << 16);
    // 0x804F4518: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x804F451C: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x804F4520: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x804F4524: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x804F4528: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x804F452C: lui         $v1, 0x8050
    ctx->r3 = S32(RELOC_HI16(273, 0X948E) << 16);
    // 0x804F4530: addiu       $v1, $v1, -0x28E2
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(273, 0X948E));
    // 0x804F4534: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x804F4538: lhu         $t8, -0x28E4($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(273, 0X948C));
    // 0x804F453C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804F4540: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x804F4544: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x804F4548: sh          $t8, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r24;
L_804F454C:
    // 0x804F454C: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x804F4550: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804F4554: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804F4558: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x804F455C: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x804F4560: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x804F4564: sh          $t0, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r8;
    // 0x804F4568: lhu         $t1, -0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, -0X4);
    // 0x804F456C: sh          $t1, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r9;
    // 0x804F4570: lhu         $t2, -0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, -0X2);
    // 0x804F4574: bne         $a0, $a1, L_804F454C
    if (ctx->r4 != ctx->r5) {
        // 0x804F4578: sh          $t2, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r10;
            goto L_804F454C;
    }
    // 0x804F4578: sh          $t2, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r10;
    // 0x804F457C: jal         0x804F536C
    // 0x804F4580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F536C(rdram, ctx);
        goto after_0;
    // 0x804F4580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804F4584: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208C0) << 16);
    // 0x804F4588: lwc1        $f4, 0x4B50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208C0));
    // 0x804F458C: addiu       $s1, $s0, 0x98
    ctx->r17 = ADD32(ctx->r16, 0X98);
    // 0x804F4590: addiu       $a3, $s0, 0x80
    ctx->r7 = ADD32(ctx->r16, 0X80);
    // 0x804F4594: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x804F4598: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x804F459C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x804F45A0: addiu       $s2, $s0, 0x68
    ctx->r18 = ADD32(ctx->r16, 0X68);
    // 0x804F45A4: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x804F45A8: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x804F45AC: sw          $zero, 0x10($a3)
    MEM_W(0X10, ctx->r7) = 0;
    // 0x804F45B0: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x804F45B4: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x804F45B8: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x804F45BC: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x804F45C0: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X207E8) << 16);
    // 0x804F45C4: addiu       $a1, $a1, 0x4A78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X207E8));
    // 0x804F45C8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804F45CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804F45D0: jal         0x804F4C88
    // 0x804F45D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804F4C88(rdram, ctx);
        goto after_1;
    // 0x804F45D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x804F45D8: lw          $t4, 0xC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0XC);
    // 0x804F45DC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x804F45E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x804F45E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x804F45E8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x804F45EC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804F45F0: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(273, 0X207AC) << 16);
    // 0x804F45F4: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20840) << 16);
    // 0x804F45F8: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x804F45FC: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x804F4600: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804F4604: lhu         $t8, 0x4A3C($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(273, 0X207AC));
    // 0x804F4608: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x804F460C: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20840));
    // 0x804F4610: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804F4614: jal         0x804F4C88
    // 0x804F4618: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
    func_804F4C88(rdram, ctx);
        goto after_2;
    // 0x804F4618: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
    after_2:
    // 0x804F461C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x804F4620: lui         $t5, 0x8051
    ctx->r13 = S32(RELOC_HI16(273, 0X207BC) << 16);
    // 0x804F4624: lui         $t9, 0x8051
    ctx->r25 = S32(RELOC_HI16(273, 0X207B4) << 16);
    // 0x804F4628: lw          $t1, 0xC($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XC);
    // 0x804F462C: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x804F4630: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20850) << 16);
    // 0x804F4634: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x804F4638: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x804F463C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x804F4640: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20850));
    // 0x804F4644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804F4648: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x804F464C: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x804F4650: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x804F4654: lhu         $t5, 0x4A4C($t5)
    ctx->r13 = MEM_HU(ctx->r13, (int16_t)RELOC_LO16(273, 0X207BC));
    // 0x804F4658: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x804F465C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804F4660: sh          $t5, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r13;
    // 0x804F4664: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x804F4668: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x804F466C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x804F4670: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804F4674: lhu         $t9, 0x4A44($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(273, 0X207B4));
    // 0x804F4678: jal         0x804F4C88
    // 0x804F467C: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    func_804F4C88(rdram, ctx);
        goto after_3;
    // 0x804F467C: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    after_3:
    // 0x804F4680: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x804F4684: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x804F4688: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(273, 0X207C4) << 16);
    // 0x804F468C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x804F4690: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x804F4694: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x804F4698: lui         $t1, 0x8051
    ctx->r9 = S32(RELOC_HI16(273, 0X207CC) << 16);
    // 0x804F469C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x804F46A0: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x804F46A4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x804F46A8: lhu         $t6, 0x4A54($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(273, 0X207C4));
    // 0x804F46AC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x804F46B0: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x804F46B4: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x804F46B8: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x804F46BC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804F46C0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x804F46C4: lhu         $t1, 0x4A5C($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(273, 0X207CC));
    // 0x804F46C8: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x804F46CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804F46D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804F46D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804F46D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F46DC: jr          $ra
    // 0x804F46E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x804F46E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80434A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434A28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80434A2C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80434A30: lw          $a2, -0x7CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CE8);
    // 0x80434A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434A38: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434A3C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AD8) << 16);
    // 0x80434A40: lwc1        $f4, 0x6588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AD8));
    // 0x80434A44: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80434A48: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80434A4C: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80434A50: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80434A54: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80434A58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80434A5C: addiu       $v0, $a1, 0x5CC
    ctx->r2 = ADD32(ctx->r5, 0X5CC);
    // 0x80434A60: addiu       $v1, $a1, 0x89C
    ctx->r3 = ADD32(ctx->r5, 0X89C);
    // 0x80434A64: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80434A68: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80434A6C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80434A70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80434A74: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80434A78: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80434A7C: jal         0x80081C64
    // 0x80434A80: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80434A80: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80434A84: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80434A88: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80434A8C: lw          $a1, 0x3F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3F4);
    // 0x80434A90: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80434A94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80434A98: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80434A9C: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80434AA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80434AA4: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80434AA8: lw          $t6, 0x478($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X478);
    // 0x80434AAC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2ADC) << 16);
    // 0x80434AB0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80434AB4: lwc1        $f8, 0xAC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x80434AB8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80434ABC: lwc1        $f10, 0x658C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2ADC));
    // 0x80434AC0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80434AC4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80434AC8: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80434ACC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80434AD0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80434AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80434AD8: nop

    // 0x80434ADC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80434AE0: jal         0x80081C64
    // 0x80434AE4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80434AE4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80434AE8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80434AEC: lw          $a1, -0x7D6C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D6C);
    // 0x80434AF0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80434AF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80434AF8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80434AFC: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80434B00: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80434B04: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80434B08: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80434B0C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80434B10: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80434B14: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80434B18: lwc1        $f6, 0xB0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x80434B1C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80434B20: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80434B24: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80434B28: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    // 0x80434B2C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80434B30: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80434B34: div.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80434B38: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x80434B3C: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80434B40: swc1        $f10, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f10.u32l;
    // 0x80434B44: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80434B48: nop

L_80434B4C:
    // 0x80434B4C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434B50: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80434B54: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80434B58: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80434B5C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434B60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80434B64: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80434B68: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80434B6C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80434B70: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80434B74: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80434B78: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80434B7C: sub.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80434B80: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80434B84: bgez        $a0, L_80434B4C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80434B88: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80434B4C;
    }
    // 0x80434B88: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80434B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434B90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80434B94: jr          $ra
    // 0x80434B98: nop

    return;
    // 0x80434B98: nop

;}
RECOMP_FUNC void func_80077084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007708C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80077090: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077094: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80077098: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007709C: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800770A0: lw          $t8, -0x7A1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7A1C);
    // 0x800770A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800770A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800770AC: beq         $a1, $t8, L_80077104
    if (ctx->r5 == ctx->r24) {
        // 0x800770B0: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80077104;
    }
    // 0x800770B0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800770B4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800770B8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800770BC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800770C0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800770C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800770C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800770CC: jal         0x80077038
    // 0x800770D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80077038(rdram, ctx);
        goto after_0;
    // 0x800770D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x800770D4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800770D8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800770DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800770E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800770E4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800770E8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800770EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800770F0: jal         0x80076D0C
    // 0x800770F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_80076D0C(rdram, ctx);
        goto after_1;
    // 0x800770F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x800770F8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800770FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077100: sw          $t3, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->r11;
L_80077104:
    // 0x80077104: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80077108: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007710C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80077110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80077114: jr          $ra
    // 0x80077118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80077118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800678D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800678D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800678D8: jal         0x80011C3C
    // 0x800678DC: nop

    func_80011C3C(rdram, ctx);
        goto after_0;
    // 0x800678DC: nop

    after_0:
    // 0x800678E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678E8: jr          $ra
    // 0x800678EC: nop

    return;
    // 0x800678EC: nop

;}
RECOMP_FUNC void func_8078F524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F524: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8078F528: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x8078F52C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8078F530: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8078F534: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8078F538: beq         $at, $zero, L_8078F57C
    if (ctx->r1 == 0) {
        // 0x8078F53C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8078F57C;
    }
    // 0x8078F53C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8078F540: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x8078F544: bne         $at, $zero, L_8078F55C
    if (ctx->r1 != 0) {
        // 0x8078F548: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_8078F55C;
    }
L_8078F548:
    // 0x8078F548: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x8078F54C: sltu        $at, $t8, $v1
    ctx->r1 = ctx->r24 < ctx->r3 ? 1 : 0;
    // 0x8078F550: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8078F554: beq         $at, $zero, L_8078F548
    if (ctx->r1 == 0) {
        // 0x8078F558: sw          $t8, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r24;
            goto L_8078F548;
    }
    // 0x8078F558: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
L_8078F55C:
    // 0x8078F55C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8078F560: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8078F564: bgez        $t0, L_8078F578
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8078F568: andi        $t1, $t0, 0x7
        ctx->r9 = ctx->r8 & 0X7;
            goto L_8078F578;
    }
    // 0x8078F568: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x8078F56C: beq         $t1, $zero, L_8078F578
    if (ctx->r9 == 0) {
        // 0x8078F570: nop
    
            goto L_8078F578;
    }
    // 0x8078F570: nop

    // 0x8078F574: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8078F578:
    // 0x8078F578: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_8078F57C:
    // 0x8078F57C: jr          $ra
    // 0x8078F580: nop

    return;
    // 0x8078F580: nop

;}
RECOMP_FUNC void func_80786A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80786A40: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80786A44: addiu       $at, $zero, 0x4671
    ctx->r1 = ADD32(0, 0X4671);
    // 0x80786A48: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(787, 0X2E20) << 16);
    // 0x80786A4C: beq         $v0, $at, L_80786A64
    if (ctx->r2 == ctx->r1) {
        // 0x80786A50: addiu       $at, $zero, 0x46B0
        ctx->r1 = ADD32(0, 0X46B0);
            goto L_80786A64;
    }
    // 0x80786A50: addiu       $at, $zero, 0x46B0
    ctx->r1 = ADD32(0, 0X46B0);
    // 0x80786A54: beq         $v0, $at, L_80786B48
    if (ctx->r2 == ctx->r1) {
        // 0x80786A58: nop
    
            goto L_80786B48;
    }
    // 0x80786A58: nop

    // 0x80786A5C: b           L_80786B54
    // 0x80786A60: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(787, 0X2B58) << 16);
        goto L_80786B54;
    // 0x80786A60: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(787, 0X2B58) << 16);
L_80786A64:
    // 0x80786A64: lw          $t6, -0x67A0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(787, 0X2E20));
    // 0x80786A68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80786A6C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80786A70: bne         $t6, $zero, L_80786B3C
    if (ctx->r14 != 0) {
        // 0x80786A74: lui         $t7, 0x8079
        ctx->r15 = S32(RELOC_HI16(787, 0X3220) << 16);
            goto L_80786B3C;
    }
    // 0x80786A74: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(787, 0X3220) << 16);
    // 0x80786A78: addiu       $t7, $t7, -0x63A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(787, 0X3220));
    // 0x80786A7C: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(787, 0X16B0) << 16);
    // 0x80786A80: sw          $t7, 0xED0($a0)
    MEM_W(0XED0, ctx->r4) = ctx->r15;
    // 0x80786A84: addiu       $t8, $t8, -0x7F10
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(787, 0X16B0));
    // 0x80786A88: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X3224) << 16);
    // 0x80786A8C: sw          $t8, -0x639C($at)
    MEM_W((int16_t)RELOC_LO16(787, 0X3224), ctx->r1) = ctx->r24;
    // 0x80786A90: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(787, 0X176C) << 16);
    // 0x80786A94: addiu       $t9, $t9, -0x7E54
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(787, 0X176C));
    // 0x80786A98: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X3228) << 16);
    // 0x80786A9C: sw          $t9, -0x6398($at)
    MEM_W((int16_t)RELOC_LO16(787, 0X3228), ctx->r1) = ctx->r25;
    // 0x80786AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80786AA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80786AA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80786AAC:
    // 0x80786AAC: lw          $t0, 0xED0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XED0);
    // 0x80786AB0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80786AB4: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80786AB8: lw          $t2, 0xED0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XED0);
    // 0x80786ABC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80786AC0: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80786AC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80786AC8: bne         $v0, $a1, L_80786AAC
    if (ctx->r2 != ctx->r5) {
        // 0x80786ACC: sw          $zero, 0x38($t3)
        MEM_W(0X38, ctx->r11) = 0;
            goto L_80786AAC;
    }
    // 0x80786ACC: sw          $zero, 0x38($t3)
    MEM_W(0X38, ctx->r11) = 0;
    // 0x80786AD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80786AD4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80786AD8: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x80786ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80786AE0:
    // 0x80786AE0: lw          $t4, 0xED0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XED0);
    // 0x80786AE4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80786AE8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80786AEC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80786AF0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80786AF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80786AF8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80786AFC: bne         $v0, $a1, L_80786AE0
    if (ctx->r2 != ctx->r5) {
        // 0x80786B00: sw          $a2, 0xC($t7)
        MEM_W(0XC, ctx->r15) = ctx->r6;
            goto L_80786AE0;
    }
    // 0x80786B00: sw          $a2, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r6;
    // 0x80786B04: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80786B08: bnel        $v1, $a3, L_80786AE0
    if (ctx->r3 != ctx->r7) {
        // 0x80786B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80786AE0;
    }
    goto skip_0;
    // 0x80786B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80786B10: lw          $t8, 0xED0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XED0);
    // 0x80786B14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80786B18: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2E20) << 16);
    // 0x80786B1C: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x80786B20: lw          $t9, 0xED0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XED0);
    // 0x80786B24: sb          $zero, 0x40($t9)
    MEM_B(0X40, ctx->r25) = 0;
    // 0x80786B28: lw          $t0, 0xED0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XED0);
    // 0x80786B2C: sb          $zero, 0x41($t0)
    MEM_B(0X41, ctx->r8) = 0;
    // 0x80786B30: lw          $t1, 0xED0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XED0);
    // 0x80786B34: sb          $zero, 0x42($t1)
    MEM_B(0X42, ctx->r9) = 0;
    // 0x80786B38: sw          $t2, -0x67A0($at)
    MEM_W((int16_t)RELOC_LO16(787, 0X2E20), ctx->r1) = ctx->r10;
L_80786B3C:
    // 0x80786B3C: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(787, 0X2B58) << 16);
    // 0x80786B40: jr          $ra
    // 0x80786B44: addiu       $v0, $v0, -0x6A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(787, 0X2B58));
    return;
    // 0x80786B44: addiu       $v0, $v0, -0x6A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(787, 0X2B58));
L_80786B48:
    // 0x80786B48: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(787, 0X2D7C) << 16);
    // 0x80786B4C: jr          $ra
    // 0x80786B50: addiu       $v0, $v0, -0x6844
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(787, 0X2D7C));
    return;
    // 0x80786B50: addiu       $v0, $v0, -0x6844
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(787, 0X2D7C));
L_80786B54:
    // 0x80786B54: addiu       $v0, $v0, -0x6A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(787, 0X2B58));
    // 0x80786B58: jr          $ra
    // 0x80786B5C: nop

    return;
    // 0x80786B5C: nop

;}
RECOMP_FUNC void func_8073E498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E498: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073E49C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073E4A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8073E4A4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073E4A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073E4AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073E4B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8073E4B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073E4B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8073E4BC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073E4C0: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(745, 0X1438) << 16);
    // 0x8073E4C4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073E4C8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073E4CC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073E4D0: lw          $t1, -0x19F8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(745, 0X1438));
    // 0x8073E4D4: jr          $ra
    // 0x8073E4D8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073E4D8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8073E4DC: nop

;}
RECOMP_FUNC void func_80676B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676B18: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676B1C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X2600) << 16);
    // 0x80676B20: lwc1        $f2, 0x3F4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3F4);
    // 0x80676B24: lwc1        $f4, 0x3FC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3FC);
    // 0x80676B28: lwc1        $f8, 0x3F8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3F8);
    // 0x80676B2C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80676B30: swc1        $f6, 0x3FC($v0)
    MEM_W(0X3FC, ctx->r2) = ctx->f6.u32l;
    // 0x80676B34: lwc1        $f0, 0x3FC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3FC);
    // 0x80676B38: lwc1        $f16, 0x7CC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X2600));
    // 0x80676B3C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X2604) << 16);
    // 0x80676B40: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80676B44: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80676B48: lwc1        $f16, 0x400($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X400);
    // 0x80676B4C: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80676B50: swc1        $f4, 0x3F4($v0)
    MEM_W(0X3F4, ctx->r2) = ctx->f4.u32l;
    // 0x80676B54: lwc1        $f8, 0x7CC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X2604));
    // 0x80676B58: lwc1        $f6, 0x3F4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3F4);
    // 0x80676B5C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80676B60: nop

    // 0x80676B64: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80676B68: swc1        $f10, 0x3F4($v0)
    MEM_W(0X3F4, ctx->r2) = ctx->f10.u32l;
    // 0x80676B6C: jr          $ra
    // 0x80676B70: swc1        $f18, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80676B70: swc1        $f18, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80673C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673C34: jal         0x80673808
    // 0x80673C38: nop

    func_80673808(rdram, ctx);
        goto after_0;
    // 0x80673C38: nop

    after_0:
    // 0x80673C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673C44: jr          $ra
    // 0x80673C48: nop

    return;
    // 0x80673C48: nop

;}
RECOMP_FUNC void func_8043453C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043453C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434540: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80434544: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // 0x80434548: addiu       $v1, $v0, 0xB6C
    ctx->r3 = ADD32(ctx->r2, 0XB6C);
L_8043454C:
    // 0x8043454C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434550: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80434554: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80434558: bgez        $a1, L_8043454C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8043455C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8043454C;
    }
    // 0x8043455C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434560: jr          $ra
    // 0x80434564: sw          $zero, 0xF2C($v0)
    MEM_W(0XF2C, ctx->r2) = 0;
    return;
    // 0x80434564: sw          $zero, 0xF2C($v0)
    MEM_W(0XF2C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8001CE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CE28: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001CE2C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8001CE30: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8001CE34: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x8001CE38: beq         $v1, $zero, L_8001CE84
    if (ctx->r3 == 0) {
        // 0x8001CE3C: andi        $a0, $v1, 0x3
        ctx->r4 = ctx->r3 & 0X3;
            goto L_8001CE84;
    }
    // 0x8001CE3C: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8001CE40: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8001CE44: beq         $a0, $zero, L_8001CE64
    if (ctx->r4 == 0) {
        // 0x8001CE48: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8001CE64;
    }
    // 0x8001CE48: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8001CE4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001CE50:
    // 0x8001CE50: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001CE54: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x8001CE58: bne         $v0, $v1, L_8001CE50
    if (ctx->r2 != ctx->r3) {
        // 0x8001CE5C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001CE50;
    }
    // 0x8001CE5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001CE60: beq         $v1, $zero, L_8001CE84
    if (ctx->r3 == 0) {
        // 0x8001CE64: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001CE84;
    }
L_8001CE64:
    // 0x8001CE64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001CE68:
    // 0x8001CE68: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001CE6C: sb          $a0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r4;
    // 0x8001CE70: sb          $a0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r4;
    // 0x8001CE74: sb          $a0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r4;
    // 0x8001CE78: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001CE7C: bne         $v1, $zero, L_8001CE68
    if (ctx->r3 != 0) {
        // 0x8001CE80: sb          $a0, -0x4($a1)
        MEM_B(-0X4, ctx->r5) = ctx->r4;
            goto L_8001CE68;
    }
    // 0x8001CE80: sb          $a0, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r4;
L_8001CE84:
    // 0x8001CE84: jr          $ra
    // 0x8001CE88: nop

    return;
    // 0x8001CE88: nop

;}
RECOMP_FUNC void func_8000ECB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ECB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ECBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000ECC0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000ECC4: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x8000ECC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ECCC: bne         $at, $zero, L_8000ECE0
    if (ctx->r1 != 0) {
        // 0x8000ECD0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000ECE0;
    }
    // 0x8000ECD0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000ECD4: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // 0x8000ECD8: b           L_8000ED2C
    // 0x8000ECDC: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
        goto L_8000ED2C;
    // 0x8000ECDC: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
L_8000ECE0:
    // 0x8000ECE0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8000ECE4: bne         $v0, $at, L_8000ECFC
    if (ctx->r2 != ctx->r1) {
        // 0x8000ECE8: addiu       $a2, $a0, 0x48
        ctx->r6 = ADD32(ctx->r4, 0X48);
            goto L_8000ECFC;
    }
    // 0x8000ECE8: addiu       $a2, $a0, 0x48
    ctx->r6 = ADD32(ctx->r4, 0X48);
    // 0x8000ECEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000ECF0: sh          $zero, 0x24($a0)
    MEM_H(0X24, ctx->r4) = 0;
    // 0x8000ECF4: b           L_8000ED2C
    // 0x8000ECF8: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
        goto L_8000ED2C;
    // 0x8000ECF8: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
L_8000ECFC:
    // 0x8000ECFC: addiu       $a3, $a0, 0x84
    ctx->r7 = ADD32(ctx->r4, 0X84);
    // 0x8000ED00: jal         0x8000EC48
    // 0x8000ED04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000EC48(rdram, ctx);
        goto after_0;
    // 0x8000ED04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000ED08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000ED0C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8000ED10: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000ED14: bne         $t8, $zero, L_8000ED2C
    if (ctx->r24 != 0) {
        // 0x8000ED18: sh          $v0, 0x24($a0)
        MEM_H(0X24, ctx->r4) = ctx->r2;
            goto L_8000ED2C;
    }
    // 0x8000ED18: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // 0x8000ED1C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8000ED20: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x8000ED24: b           L_8000ED38
    // 0x8000ED28: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
        goto L_8000ED38;
    // 0x8000ED28: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_8000ED2C:
    // 0x8000ED2C: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x8000ED30: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8000ED34: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_8000ED38:
    // 0x8000ED38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ED3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000ED40: jr          $ra
    // 0x8000ED44: nop

    return;
    // 0x8000ED44: nop

;}
RECOMP_FUNC void func_8064CC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CC04: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064CC08: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064CC0C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8064CC10: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064CC14: jr          $ra
    // 0x8064CC18: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8064CC18: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8006BBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBEC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006BBF0: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8006BBF4: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8006BBF8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x8006BBFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BC00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006BC04: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006BC0C: mflo        $v1
    ctx->r3 = lo;
    // 0x8006BC10: blezl       $v1, L_8006BC68
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006BC14: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_8006BC68;
    }
    goto skip_0;
    // 0x8006BC14: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
L_8006BC18:
    // 0x8006BC18: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BC1C: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x8006BC20: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8006BC24: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8006BC28: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8006BC2C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8006BC30: beql        $t1, $zero, L_8006BC58
    if (ctx->r9 == 0) {
        // 0x8006BC34: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8006BC58;
    }
    goto skip_1;
    // 0x8006BC34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8006BC38: sb          $a1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r5;
    // 0x8006BC3C: lh          $t4, 0x0($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X0);
    // 0x8006BC40: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x8006BC44: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BC48: mflo        $v1
    ctx->r3 = lo;
    // 0x8006BC4C: nop

    // 0x8006BC50: nop

    // 0x8006BC54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006BC58:
    // 0x8006BC58: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006BC5C: bne         $at, $zero, L_8006BC18
    if (ctx->r1 != 0) {
        // 0x8006BC60: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006BC18;
    }
    // 0x8006BC60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006BC64: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_8006BC68:
    // 0x8006BC68: jr          $ra
    // 0x8006BC6C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006BC6C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8076066C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076066C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760670: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760674: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760678: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076067C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760680: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760684: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760688: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076068C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760690: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760694: jr          $ra
    // 0x80760698: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760698: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8000576C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000576C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80005778: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000577C: jal         0x80005CF0
    // 0x80005780: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80005CF0(rdram, ctx);
        goto after_0;
    // 0x80005780: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005784: beq         $v0, $zero, L_800057A8
    if (ctx->r2 == 0) {
        // 0x80005788: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_800057A8;
    }
    // 0x80005788: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000578C: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x80005790: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80005794: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80005798: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x8000579C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x800057A0: b           L_800057AC
    // 0x800057A4: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
        goto L_800057AC;
    // 0x800057A4: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_800057A8:
    // 0x800057A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800057AC:
    // 0x800057AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800057B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800057B4: jr          $ra
    // 0x800057B8: nop

    return;
    // 0x800057B8: nop

;}
RECOMP_FUNC void func_8044D810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D810: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8044D814: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D818: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8044D81C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8044D820: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8044D824: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8044D828: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8044D82C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8044D830: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8044D834: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8044D838: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8044D83C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044D840: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8044D844: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x8044D848: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x8044D84C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x8044D850: lw          $s2, 0x1F4($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044D854: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D858: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8044D85C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8044D860: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D864: lw          $fp, 0xA60($s2)
    ctx->r30 = MEM_W(ctx->r18, 0XA60);
    // 0x8044D868: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8044D86C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8044D870: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8044D874: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x8044D878: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x8044D87C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
L_8044D880:
    // 0x8044D880: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8044D884: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8044D888: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8044D88C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x8044D890: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8044D894: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D898: beq         $s0, $zero, L_8044D970
    if (ctx->r16 == 0) {
        // 0x8044D89C: addiu       $v0, $s2, 0xA64
        ctx->r2 = ADD32(ctx->r18, 0XA64);
            goto L_8044D970;
    }
    // 0x8044D89C: addiu       $v0, $s2, 0xA64
    ctx->r2 = ADD32(ctx->r18, 0XA64);
    // 0x8044D8A0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8044D8A4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8044D8A8: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8044D8AC: beq         $a2, $zero, L_8044D8FC
    if (ctx->r6 == 0) {
        // 0x8044D8B0: addu        $s4, $t4, $s3
        ctx->r20 = ADD32(ctx->r12, ctx->r19);
            goto L_8044D8FC;
    }
    // 0x8044D8B0: addu        $s4, $t4, $s3
    ctx->r20 = ADD32(ctx->r12, ctx->r19);
    // 0x8044D8B4: addiu       $s1, $fp, 0x1
    ctx->r17 = ADD32(ctx->r30, 0X1);
    // 0x8044D8B8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8044D8BC: lw          $a3, 0x5A0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X5A0);
    // 0x8044D8C0: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x8044D8C4: addu        $s6, $v0, $t7
    ctx->r22 = ADD32(ctx->r2, ctx->r15);
    // 0x8044D8C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8044D8CC: jal         0x8044D140
    // 0x8044D8D0: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    func_8044D140(rdram, ctx);
        goto after_0;
    // 0x8044D8D0: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    after_0:
    // 0x8044D8D4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044D8D8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8044D8DC: jal         0x8044CCE4
    // 0x8044D8E0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_8044CCE4(rdram, ctx);
        goto after_1;
    // 0x8044D8E0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x8044D8E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044D8E8: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8044D8EC: jal         0x8044C360
    // 0x8044D8F0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_8044C360(rdram, ctx);
        goto after_2;
    // 0x8044D8F0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x8044D8F4: sw          $s7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r23;
    // 0x8044D8F8: sw          $s1, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r17;
L_8044D8FC:
    // 0x8044D8FC: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x8044D900: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8044D904: lw          $t3, 0x4E0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X4E0);
    // 0x8044D908: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8044D90C: lw          $t4, 0xF0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D910: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044D914: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x8044D918: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8044D91C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D920: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8044D924: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8044D928: jal         0x8044D1F4
    // 0x8044D92C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8044D1F4(rdram, ctx);
        goto after_3;
    // 0x8044D92C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x8044D930: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8044D934: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8044D938: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8044D93C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x8044D940: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8044D944: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8044D948: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8044D94C: beql        $t1, $zero, L_8044D95C
    if (ctx->r9 == 0) {
        // 0x8044D950: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_8044D95C;
    }
    goto skip_0;
    // 0x8044D950: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x8044D954: sw          $fp, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r30;
    // 0x8044D958: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
L_8044D95C:
    // 0x8044D95C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8044D960: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8044D964: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8044D968: bne         $s3, $at, L_8044D880
    if (ctx->r19 != ctx->r1) {
        // 0x8044D96C: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_8044D880;
    }
    // 0x8044D96C: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_8044D970:
    // 0x8044D970: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8044D974: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044D978: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8044D97C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8044D980: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8044D984: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8044D988: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8044D98C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8044D990: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8044D994: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8044D998: jr          $ra
    // 0x8044D99C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8044D99C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_805ADBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADBE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADBE8: lui         $at, 0x805C
    ctx->r1 = S32(RELOC_HI16(444, 0X183F0) << 16);
    // 0x805ADBEC: lwc1        $f0, 0x5AF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(444, 0X183F0));
    // 0x805ADBF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADBF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADBF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADBFC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADC00: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADC04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADC08: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x805ADC0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADC10: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADC14: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADC18: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805ADC1C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADC20: jal         0x805AD70C
    // 0x805ADC24: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADC24: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADC28: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADC2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADC30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADC34: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805ADC38: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADC3C: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805ADC40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADC44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADC48: jr          $ra
    // 0x805ADC4C: nop

    return;
    // 0x805ADC4C: nop

;}
RECOMP_FUNC void func_807AFEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AFEEC: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(871, 0X322C) << 16);
    // 0x807AFEF0: lui         $v1, 0x807B
    ctx->r3 = S32(RELOC_HI16(871, 0X328C) << 16);
    // 0x807AFEF4: addiu       $v0, $v0, 0x2D7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(871, 0X322C));
    // 0x807AFEF8: addiu       $v1, $v1, 0x2DDC
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(871, 0X328C));
    // 0x807AFEFC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x807AFF00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807AFF04: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
L_807AFF08:
    // 0x807AFF08: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x807AFF0C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x807AFF10: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x807AFF14: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x807AFF18: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x807AFF1C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807AFF20: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x807AFF24: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x807AFF28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807AFF2C: lwc1        $f2, 0x64($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807AFF30: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x807AFF34: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x807AFF38: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x807AFF3C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807AFF40: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807AFF44: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x807AFF48: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807AFF4C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807AFF50: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x807AFF54: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x807AFF58: nop

    // 0x807AFF5C: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x807AFF60: sh          $t6, -0x18($a1)
    MEM_H(-0X18, ctx->r5) = ctx->r14;
    // 0x807AFF64: lh          $t7, -0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X16);
    // 0x807AFF68: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x807AFF6C: sh          $zero, -0x14($a1)
    MEM_H(-0X14, ctx->r5) = 0;
    // 0x807AFF70: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x807AFF74: sh          $t3, -0x16($a1)
    MEM_H(-0X16, ctx->r5) = ctx->r11;
    // 0x807AFF78: lh          $t4, -0x12($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X12);
    // 0x807AFF7C: lh          $a3, -0x12($v0)
    ctx->r7 = MEM_H(ctx->r2, -0X12);
    // 0x807AFF80: lh          $t8, -0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X10);
    // 0x807AFF84: lh          $t6, -0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X10);
    // 0x807AFF88: subu        $t5, $t4, $a3
    ctx->r13 = SUB32(ctx->r12, ctx->r7);
    // 0x807AFF8C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x807AFF90: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x807AFF94: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x807AFF98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807AFF9C: lwc1        $f2, 0x64($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807AFFA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807AFFA4: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807AFFA8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807AFFAC: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807AFFB0: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x807AFFB4: nop

    // 0x807AFFB8: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x807AFFBC: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x807AFFC0: sh          $t4, -0x12($a1)
    MEM_H(-0X12, ctx->r5) = ctx->r12;
    // 0x807AFFC4: lh          $t5, -0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X10);
    // 0x807AFFC8: sh          $zero, -0xE($a1)
    MEM_H(-0XE, ctx->r5) = 0;
    // 0x807AFFCC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x807AFFD0: nop

    // 0x807AFFD4: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x807AFFD8: sh          $t7, -0x10($a1)
    MEM_H(-0X10, ctx->r5) = ctx->r15;
    // 0x807AFFDC: lh          $t2, -0xC($v1)
    ctx->r10 = MEM_H(ctx->r3, -0XC);
    // 0x807AFFE0: lh          $a3, -0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, -0XC);
    // 0x807AFFE4: lh          $t6, -0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, -0XA);
    // 0x807AFFE8: lh          $t4, -0xA($v1)
    ctx->r12 = MEM_H(ctx->r3, -0XA);
    // 0x807AFFEC: subu        $t3, $t2, $a3
    ctx->r11 = SUB32(ctx->r10, ctx->r7);
    // 0x807AFFF0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x807AFFF4: subu        $t8, $t4, $t6
    ctx->r24 = SUB32(ctx->r12, ctx->r14);
    // 0x807AFFF8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x807AFFFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B0000: lwc1        $f2, 0x64($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0004: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B0008: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B000C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B0010: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807B0014: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x807B0018: nop

    // 0x807B001C: addu        $t2, $a3, $t7
    ctx->r10 = ADD32(ctx->r7, ctx->r15);
    // 0x807B0020: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x807B0024: sh          $t2, -0xC($a1)
    MEM_H(-0XC, ctx->r5) = ctx->r10;
    // 0x807B0028: lh          $t3, -0xA($v0)
    ctx->r11 = MEM_H(ctx->r2, -0XA);
    // 0x807B002C: sh          $zero, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = 0;
    // 0x807B0030: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x807B0034: nop

    // 0x807B0038: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x807B003C: sh          $t5, -0xA($a1)
    MEM_H(-0XA, ctx->r5) = ctx->r13;
    // 0x807B0040: lh          $t1, -0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X6);
    // 0x807B0044: lh          $a3, -0x6($v0)
    ctx->r7 = MEM_H(ctx->r2, -0X6);
    // 0x807B0048: lh          $t4, -0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X4);
    // 0x807B004C: lh          $t2, -0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, -0X4);
    // 0x807B0050: subu        $t7, $t1, $a3
    ctx->r15 = SUB32(ctx->r9, ctx->r7);
    // 0x807B0054: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807B0058: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x807B005C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x807B0060: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B0064: lwc1        $f2, 0x64($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0068: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B006C: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807B0070: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B0074: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807B0078: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x807B007C: nop

    // 0x807B0080: addu        $t1, $a3, $t5
    ctx->r9 = ADD32(ctx->r7, ctx->r13);
    // 0x807B0084: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x807B0088: sh          $t1, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r9;
    // 0x807B008C: lh          $t7, -0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X4);
    // 0x807B0090: sh          $zero, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = 0;
    // 0x807B0094: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x807B0098: nop

    // 0x807B009C: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x807B00A0: bne         $a2, $t0, L_807AFF08
    if (ctx->r6 != ctx->r8) {
        // 0x807B00A4: sh          $t3, -0x4($a1)
        MEM_H(-0X4, ctx->r5) = ctx->r11;
            goto L_807AFF08;
    }
    // 0x807B00A4: sh          $t3, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r11;
    // 0x807B00A8: jr          $ra
    // 0x807B00AC: nop

    return;
    // 0x807B00AC: nop

;}
RECOMP_FUNC void func_804A52F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A52F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A52F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A52FC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A5300: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A5304: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A5308: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A530C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A5310: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A5314: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A5318: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A531C: jr          $ra
    // 0x804A5320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A5320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8069C864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069C868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069C86C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069C870: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x8069C874: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8069C878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069C87C: bnel        $t6, $at, L_8069C8A8
    if (ctx->r14 != ctx->r1) {
        // 0x8069C880: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8069C8A8;
    }
    goto skip_0;
    // 0x8069C880: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8069C884: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8069C888: jal         0x80067BBC
    // 0x8069C88C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8069C88C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8069C890: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8069C894: jal         0x80067F78
    // 0x8069C898: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8069C898: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8069C89C: b           L_8069C8C0
    // 0x8069C8A0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8069C8C0;
    // 0x8069C8A0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8069C8A4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8069C8A8:
    // 0x8069C8A8: jal         0x80067BBC
    // 0x8069C8AC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8069C8AC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8069C8B0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8069C8B4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8069C8B8: jal         0x800678F0
    // 0x8069C8BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8069C8BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_8069C8C0:
    // 0x8069C8C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069C8C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069C8C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069C8CC: jr          $ra
    // 0x8069C8D0: nop

    return;
    // 0x8069C8D0: nop

;}
RECOMP_FUNC void func_80780940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780940: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80780944: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80780948: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8078094C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80780950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80780954: jal         0x80780260
    // 0x80780958: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    func_80780260(rdram, ctx);
        goto after_0;
    // 0x80780958: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    after_0:
    // 0x8078095C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80780960: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80780964: jal         0x80048F84
    // 0x80780968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80780968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8078096C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80780970: jal         0x80048F84
    // 0x80780974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80780974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80780978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078097C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80780980: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X665C) << 16);
    // 0x80780984: lwc1        $f4, 0x684C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X665C));
    // 0x80780988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078098C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80780990: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x80780994: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80780998: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8078099C: nop

    // 0x807809A0: bc1fl       L_807809B4
    if (!c1cs) {
        // 0x807809A4: swc1        $f20, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
            goto L_807809B4;
    }
    goto skip_0;
    // 0x807809A4: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x807809A8: jal         0x807813F0
    // 0x807809AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_807813F0(rdram, ctx);
        goto after_3;
    // 0x807809AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x807809B0: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
L_807809B4:
    // 0x807809B4: swc1        $f20, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f20.u32l;
    // 0x807809B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807809BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807809C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807809C4: jr          $ra
    // 0x807809C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807809C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80035E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035E30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035E34: jal         0x800351BC
    // 0x80035E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800351BC(rdram, ctx);
        goto after_0;
    // 0x80035E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80035E3C: bne         $v0, $zero, L_80035E4C
    if (ctx->r2 != 0) {
        // 0x80035E40: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80035E4C;
    }
    // 0x80035E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035E44: b           L_80035EC8
    // 0x80035E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80035EC8;
    // 0x80035E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035E4C:
    // 0x80035E4C: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80035E50: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80035E54: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80035E58: beql        $at, $zero, L_80035E7C
    if (ctx->r1 == 0) {
        // 0x80035E5C: lbu         $t9, 0x30($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X30);
            goto L_80035E7C;
    }
    goto skip_0;
    // 0x80035E5C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    skip_0:
    // 0x80035E60: lbu         $t7, 0x1F8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1F8);
    // 0x80035E64: bnel        $t7, $zero, L_80035E7C
    if (ctx->r15 != 0) {
        // 0x80035E68: lbu         $t9, 0x30($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X30);
            goto L_80035E7C;
    }
    goto skip_1;
    // 0x80035E68: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    skip_1:
    // 0x80035E6C: lw          $t8, 0x12EC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X12EC);
    // 0x80035E70: beql        $t8, $zero, L_80035EAC
    if (ctx->r24 == 0) {
        // 0x80035E74: lw          $t0, 0x78($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X78);
            goto L_80035EAC;
    }
    goto skip_2;
    // 0x80035E74: lw          $t0, 0x78($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X78);
    skip_2:
    // 0x80035E78: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
L_80035E7C:
    // 0x80035E7C: beq         $t9, $zero, L_80035EA0
    if (ctx->r25 == 0) {
        // 0x80035E80: lui         $t9, 0x800A
        ctx->r25 = S32(0X800A << 16);
            goto L_80035EA0;
    }
    // 0x80035E80: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80035E84: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80035E88: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80035E8C: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80035E90: jalr        $t9
    // 0x80035E94: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80035E94: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80035E98: b           L_80035EC8
    // 0x80035E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80035EC8;
    // 0x80035E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035EA0:
    // 0x80035EA0: b           L_80035EC8
    // 0x80035EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035EC8;
    // 0x80035EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035EA8: lw          $t0, 0x78($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X78);
L_80035EAC:
    // 0x80035EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035EB0: beq         $t0, $zero, L_80035EC8
    if (ctx->r8 == 0) {
        // 0x80035EB4: nop
    
            goto L_80035EC8;
    }
    // 0x80035EB4: nop

    // 0x80035EB8: jal         0x80035DA8
    // 0x80035EBC: nop

    func_80035DA8(rdram, ctx);
        goto after_2;
    // 0x80035EBC: nop

    after_2:
    // 0x80035EC0: b           L_80035ECC
    // 0x80035EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035ECC;
    // 0x80035EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035EC8:
    // 0x80035EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035ECC:
    // 0x80035ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035ED0: jr          $ra
    // 0x80035ED4: nop

    return;
    // 0x80035ED4: nop

;}
RECOMP_FUNC void func_8040AE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AE28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040AE2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8040AE30: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8040AE34: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8040AE38: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8040AE3C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8040AE40: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8040AE44: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8040AE48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040AE4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8040AE50: lw          $s6, 0x174($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X174);
    // 0x8040AE54: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040AE58: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8040AE5C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8040AE60: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8040AE64: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x8040AE68: jal         0x80049D74
    // 0x8040AE6C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8040AE6C: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    after_0:
    // 0x8040AE70: beq         $s0, $zero, L_8040AEF4
    if (ctx->r16 == 0) {
        // 0x8040AE74: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_8040AEF4;
    }
    // 0x8040AE74: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8040AE78: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8040AE7C: lui         $s5, 0x8041
    ctx->r21 = S32(RELOC_HI16(14, 0XF78) << 16);
    // 0x8040AE80: addiu       $s5, $s5, -0x4528
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(14, 0XF78));
    // 0x8040AE84: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8040AE88: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x8040AE8C: addiu       $s3, $zero, 0x38
    ctx->r19 = ADD32(0, 0X38);
    // 0x8040AE90: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8040AE94: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
L_8040AE98:
    // 0x8040AE98: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x8040AE9C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8040AEA0: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8040AEA4: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x8040AEA8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8040AEAC: beq         $v1, $zero, L_8040AEEC
    if (ctx->r3 == 0) {
        // 0x8040AEB0: nop
    
            goto L_8040AEEC;
    }
    // 0x8040AEB0: nop

    // 0x8040AEB4: beq         $s2, $v1, L_8040AEEC
    if (ctx->r18 == ctx->r3) {
        // 0x8040AEB8: nop
    
            goto L_8040AEEC;
    }
    // 0x8040AEB8: nop

    // 0x8040AEBC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8040AEC0: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8040AEC4: beq         $s3, $v1, L_8040AEEC
    if (ctx->r19 == ctx->r3) {
        // 0x8040AEC8: nop
    
            goto L_8040AEEC;
    }
    // 0x8040AEC8: nop

    // 0x8040AECC: beq         $s4, $v1, L_8040AEEC
    if (ctx->r20 == ctx->r3) {
        // 0x8040AED0: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_8040AEEC;
    }
    // 0x8040AED0: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8040AED4: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x8040AED8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8040AEDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8040AEE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8040AEE4: jalr        $t9
    // 0x8040AEE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040AEE8: nop

    after_1:
L_8040AEEC:
    // 0x8040AEEC: bnel        $s0, $zero, L_8040AE98
    if (ctx->r16 != 0) {
        // 0x8040AEF0: lw          $t8, 0x0($s6)
        ctx->r24 = MEM_W(ctx->r22, 0X0);
            goto L_8040AE98;
    }
    goto skip_0;
    // 0x8040AEF0: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    skip_0:
L_8040AEF4:
    // 0x8040AEF4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8040AEF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8040AEFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8040AF00: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8040AF04: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8040AF08: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8040AF0C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8040AF10: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8040AF14: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8040AF18: jr          $ra
    // 0x8040AF1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040AF1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806B2BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2BBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2BC0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2BC4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2BC8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2BCC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2BD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2BD4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2BD8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2BDC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2BE0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2BE4: jr          $ra
    // 0x806B2BE8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2BE8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040EB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EB28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040EB2C: bne         $a1, $at, L_8040EB50
    if (ctx->r5 != ctx->r1) {
        // 0x8040EB30: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040EB50;
    }
    // 0x8040EB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EB34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040EB38: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EB3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EB40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040EB44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8040EB48: jal         0x8040F0B8
    // 0x8040EB4C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040EB4C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    after_0:
L_8040EB50:
    // 0x8040EB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EB54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EB58: jr          $ra
    // 0x8040EB5C: nop

    return;
    // 0x8040EB5C: nop

;}
RECOMP_FUNC void func_804A2714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2714: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A2718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A271C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A2720: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(173, 0X30A0) << 16);
    // 0x804A2724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804A2728: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x804A272C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804A2730: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804A2734: lw          $a3, 0x16C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X16C);
    // 0x804A2738: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x804A273C: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x804A2740: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x804A2744: sltiu       $at, $v0, 0xFF
    ctx->r1 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x804A2748: bnel        $at, $zero, L_804A2790
    if (ctx->r1 != 0) {
        // 0x804A274C: sb          $v0, 0x10($a3)
        MEM_B(0X10, ctx->r7) = ctx->r2;
            goto L_804A2790;
    }
    goto skip_0;
    // 0x804A274C: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    skip_0:
    // 0x804A2750: lbu         $t7, 0xF5C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF5C);
    // 0x804A2754: lbu         $t9, 0xF5D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF5D);
    // 0x804A2758: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804A275C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804A2760: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804A2764: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x804A2768: lbu         $a2, 0x34E0($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(173, 0X30A0));
    // 0x804A276C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804A2770: jal         0x8006E0FC
    // 0x804A2774: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x804A2774: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x804A2778: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804A277C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x804A2780: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804A2784: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804A2788: sb          $t1, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r9;
    // 0x804A278C: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_804A2790:
    // 0x804A2790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A2794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A2798: jr          $ra
    // 0x804A279C: nop

    return;
    // 0x804A279C: nop

;}
RECOMP_FUNC void func_80037280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037288: jal         0x80021958
    // 0x8003728C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003728C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037290: bne         $v0, $zero, L_800372A0
    if (ctx->r2 != 0) {
        // 0x80037294: nop
    
            goto L_800372A0;
    }
    // 0x80037294: nop

    // 0x80037298: b           L_800372DC
    // 0x8003729C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800372DC;
    // 0x8003729C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800372A0:
    // 0x800372A0: jal         0x80041714
    // 0x800372A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041714(rdram, ctx);
        goto after_1;
    // 0x800372A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800372A8: beq         $v0, $zero, L_800372B8
    if (ctx->r2 == 0) {
        // 0x800372AC: nop
    
            goto L_800372B8;
    }
    // 0x800372AC: nop

    // 0x800372B0: b           L_800372DC
    // 0x800372B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800372DC;
    // 0x800372B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800372B8:
    // 0x800372B8: jal         0x80037244
    // 0x800372BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80037244(rdram, ctx);
        goto after_2;
    // 0x800372BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800372C0: bne         $v0, $zero, L_800372D0
    if (ctx->r2 != 0) {
        // 0x800372C4: nop
    
            goto L_800372D0;
    }
    // 0x800372C4: nop

    // 0x800372C8: b           L_800372DC
    // 0x800372CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800372DC;
    // 0x800372CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800372D0:
    // 0x800372D0: jal         0x80036EDC
    // 0x800372D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036EDC(rdram, ctx);
        goto after_3;
    // 0x800372D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800372D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800372DC:
    // 0x800372DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800372E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800372E4: jr          $ra
    // 0x800372E8: nop

    return;
    // 0x800372E8: nop

;}
RECOMP_FUNC void func_804CAE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAE5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CAE60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAE64: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x804CAE68: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x804CAE6C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804CAE70: jal         0x80065ABC
    // 0x804CAE74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x804CAE74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CAE78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CAE7C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x804CAE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CAE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAE88: jr          $ra
    // 0x804CAE8C: nop

    return;
    // 0x804CAE8C: nop

;}
RECOMP_FUNC void func_80798D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798D80: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80798D84: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80798D88: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80798D8C: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(826, 0X2464) << 16);
    // 0x80798D90: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80798D94: addiu       $t7, $t7, -0x507C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(826, 0X2464));
    // 0x80798D98: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80798D9C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80798DA0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80798DA4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80798DA8: jr          $ra
    // 0x80798DAC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    return;
    // 0x80798DAC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8044F28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044F28C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044F290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044F294: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044F298: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F29C: addu        $v1, $a1, $at
    ctx->r3 = ADD32(ctx->r5, ctx->r1);
    // 0x8044F2A0: lw          $v0, 0x6A40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A40);
    // 0x8044F2A4: bltz        $v0, L_8044F2EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8044F2A8: slti        $at, $v0, 0xC
        ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
            goto L_8044F2EC;
    }
    // 0x8044F2A8: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8044F2AC: beq         $at, $zero, L_8044F2EC
    if (ctx->r1 == 0) {
        // 0x8044F2B0: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8044F2EC;
    }
    // 0x8044F2B0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8044F2B4: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X1360C) << 16);
    // 0x8044F2B8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8044F2BC: lw          $t9, 0x79EC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X1360C));
    // 0x8044F2C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8044F2C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8044F2C8: jalr        $t9
    // 0x8044F2CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8044F2CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8044F2D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044F2D4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F2D8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8044F2DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F2E0: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x8044F2E4: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8044F2E8: sw          $t7, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r15;
L_8044F2EC:
    // 0x8044F2EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8044F2F0: bnel        $v0, $at, L_8044F338
    if (ctx->r2 != ctx->r1) {
        // 0x8044F2F4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8044F338;
    }
    goto skip_0;
    // 0x8044F2F4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_0:
    // 0x8044F2F8: lw          $a0, 0x6A90($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6A90);
    // 0x8044F2FC: beql        $a0, $zero, L_8044F338
    if (ctx->r4 == 0) {
        // 0x8044F300: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8044F338;
    }
    goto skip_1;
    // 0x8044F300: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_1:
    // 0x8044F304: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8044F308: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8044F30C: jal         0x80050A2C
    // 0x8044F310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80050A2C(rdram, ctx);
        goto after_1;
    // 0x8044F310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8044F314: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F318: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044F31C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8044F320: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F324: addiu       $t8, $zero, -0x64
    ctx->r24 = ADD32(0, -0X64);
    // 0x8044F328: sw          $zero, 0x6A90($v1)
    MEM_W(0X6A90, ctx->r3) = 0;
    // 0x8044F32C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8044F330: sw          $t8, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r24;
    // 0x8044F334: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8044F338:
    // 0x8044F338: bnel        $v0, $at, L_8044F378
    if (ctx->r2 != ctx->r1) {
        // 0x8044F33C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F378;
    }
    goto skip_2;
    // 0x8044F33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8044F340: lw          $a0, 0x6A8C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6A8C);
    // 0x8044F344: beql        $a0, $zero, L_8044F378
    if (ctx->r4 == 0) {
        // 0x8044F348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F378;
    }
    goto skip_3;
    // 0x8044F348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8044F34C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8044F350: jal         0x80050A2C
    // 0x8044F354: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80050A2C(rdram, ctx);
        goto after_2;
    // 0x8044F354: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8044F358: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F35C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044F360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F364: addiu       $t0, $zero, -0x64
    ctx->r8 = ADD32(0, -0X64);
    // 0x8044F368: sw          $zero, 0x6A8C($v1)
    MEM_W(0X6A8C, ctx->r3) = 0;
    // 0x8044F36C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8044F370: sw          $t0, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r8;
    // 0x8044F374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044F378:
    // 0x8044F378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044F37C: jr          $ra
    // 0x8044F380: nop

    return;
    // 0x8044F380: nop

;}
RECOMP_FUNC void func_8006B620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B620: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006B624: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x8006B628: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8006B62C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006B630: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B634: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B638: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8006B63C: lh          $s0, 0x26($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X26);
    // 0x8006B640: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8006B644: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8006B648: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8006B64C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B650: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006B654: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B658: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006B65C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006B660: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006B664: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x8006B668: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8006B66C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006B670: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8006B674: beq         $t0, $zero, L_8006B6D8
    if (ctx->r8 == 0) {
        // 0x8006B678: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_8006B6D8;
    }
    // 0x8006B678: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B67C: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x8006B680: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    // 0x8006B684: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
L_8006B688:
    // 0x8006B688: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8006B68C: beq         $a3, $zero, L_8006B6B4
    if (ctx->r7 == 0) {
        // 0x8006B690: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_8006B6B4;
    }
    // 0x8006B690: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8006B694:
    // 0x8006B694: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8006B698: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B69C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006B6A0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006B6A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006B6A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8006B6AC: bne         $a1, $zero, L_8006B694
    if (ctx->r5 != 0) {
        // 0x8006B6B0: sh          $t4, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r12;
            goto L_8006B694;
    }
    // 0x8006B6B0: sh          $t4, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r12;
L_8006B6B4:
    // 0x8006B6B4: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8006B6B8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B6BC: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B6C0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8006B6C4: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8006B6C8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B6CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006B6D0: bne         $t0, $zero, L_8006B688
    if (ctx->r8 != 0) {
        // 0x8006B6D4: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8006B688;
    }
    // 0x8006B6D4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8006B6D8:
    // 0x8006B6D8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8006B6DC: jr          $ra
    // 0x8006B6E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006B6E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006E654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E654: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E65C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E660: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8006E664: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E668: jal         0x8006E2B0
    // 0x8006E66C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E66C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006E670: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8006E674: addiu       $t8, $t8, 0x7E38
    ctx->r24 = ADD32(ctx->r24, 0X7E38);
    // 0x8006E678: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8006E67C: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8006E680: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006E684: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006E688: lh          $a2, 0x7E44($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7E44);
    // 0x8006E68C: lh          $a1, 0x7E40($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7E40);
    // 0x8006E690: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8006E694: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006E698: jal         0x80050258
    // 0x8006E69C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80050258(rdram, ctx);
        goto after_1;
    // 0x8006E69C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x8006E6A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006E6A4: lh          $v0, 0x7E40($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7E40);
    // 0x8006E6A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006E6AC: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8006E6B0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8006E6B4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006E6B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006E6BC: sh          $v0, 0x7E40($at)
    MEM_H(0X7E40, ctx->r1) = ctx->r2;
    // 0x8006E6C0: bgez        $v0, L_8006E6D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006E6C4: sra         $t9, $v0, 5
        ctx->r25 = S32(SIGNED(ctx->r2) >> 5);
            goto L_8006E6D0;
    }
    // 0x8006E6C4: sra         $t9, $v0, 5
    ctx->r25 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8006E6C8: addiu       $at, $v0, 0x1F
    ctx->r1 = ADD32(ctx->r2, 0X1F);
    // 0x8006E6CC: sra         $t9, $at, 5
    ctx->r25 = S32(SIGNED(ctx->r1) >> 5);
L_8006E6D0:
    // 0x8006E6D0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8006E6D4: bnel        $t9, $at, L_8006E6FC
    if (ctx->r25 != ctx->r1) {
        // 0x8006E6D8: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_8006E6FC;
    }
    goto skip_0;
    // 0x8006E6D8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8006E6DC: lh          $t0, 0x7E44($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7E44);
    // 0x8006E6E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006E6E4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8006E6E8: addiu       $t1, $t0, 0x20
    ctx->r9 = ADD32(ctx->r8, 0X20);
    // 0x8006E6EC: sh          $t1, 0x7E44($at)
    MEM_H(0X7E44, ctx->r1) = ctx->r9;
    // 0x8006E6F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006E6F4: sh          $t2, 0x7E40($at)
    MEM_H(0X7E40, ctx->r1) = ctx->r10;
    // 0x8006E6F8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_8006E6FC:
    // 0x8006E6FC: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x8006E700: addiu       $t3, $t3, -0x18E8
    ctx->r11 = ADD32(ctx->r11, -0X18E8);
    // 0x8006E704: sw          $t3, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r11;
    // 0x8006E708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E70C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006E710: jr          $ra
    // 0x8006E714: nop

    return;
    // 0x8006E714: nop

;}
RECOMP_FUNC void func_8002D0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D0B4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002D0B8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002D0BC: lw          $t6, 0x62C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X62C);
    // 0x8002D0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D0C8: beq         $t6, $zero, L_8002D0F4
    if (ctx->r14 == 0) {
        // 0x8002D0CC: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8002D0F4;
    }
    // 0x8002D0CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8002D0D0: lw          $a1, -0x6580($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6580);
    // 0x8002D0D4: jal         0x80048BD8
    // 0x8002D0D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048BD8(rdram, ctx);
        goto after_0;
    // 0x8002D0D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002D0DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002D0E0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002D0E4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002D0E8: lw          $t7, 0x1D8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1D8);
    // 0x8002D0EC: lw          $t9, 0x1DC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1DC);
    // 0x8002D0F0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_8002D0F4:
    // 0x8002D0F4: lw          $t0, 0xAB0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XAB0);
    // 0x8002D0F8: lw          $t1, 0xAB4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XAB4);
    // 0x8002D0FC: lw          $t2, 0xAB8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAB8);
    // 0x8002D100: lw          $t3, 0xABC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XABC);
    // 0x8002D104: lw          $t4, 0xAC0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XAC0);
    // 0x8002D108: lw          $t5, 0xB30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XB30);
    // 0x8002D10C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002D110: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8002D114: addiu       $a1, $a1, -0x762C
    ctx->r5 = ADD32(ctx->r5, -0X762C);
    // 0x8002D118: addiu       $a0, $a0, -0x75B0
    ctx->r4 = ADD32(ctx->r4, -0X75B0);
    // 0x8002D11C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8002D120: sw          $t0, 0xAC4($v0)
    MEM_W(0XAC4, ctx->r2) = ctx->r8;
    // 0x8002D124: sw          $t1, 0xAC8($v0)
    MEM_W(0XAC8, ctx->r2) = ctx->r9;
    // 0x8002D128: sw          $t2, 0xACC($v0)
    MEM_W(0XACC, ctx->r2) = ctx->r10;
    // 0x8002D12C: sw          $t3, 0xAD0($v0)
    MEM_W(0XAD0, ctx->r2) = ctx->r11;
    // 0x8002D130: sw          $t4, 0xAD4($v0)
    MEM_W(0XAD4, ctx->r2) = ctx->r12;
    // 0x8002D134: jal         0x80065528
    // 0x8002D138: sw          $t5, 0xBAC($v0)
    MEM_W(0XBAC, ctx->r2) = ctx->r13;
    func_80065528(rdram, ctx);
        goto after_1;
    // 0x8002D138: sw          $t5, 0xBAC($v0)
    MEM_W(0XBAC, ctx->r2) = ctx->r13;
    after_1:
    // 0x8002D13C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002D140: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8002D144: addiu       $a1, $a1, -0x724C
    ctx->r5 = ADD32(ctx->r5, -0X724C);
    // 0x8002D148: addiu       $a0, $a0, -0x722C
    ctx->r4 = ADD32(ctx->r4, -0X722C);
    // 0x8002D14C: jal         0x80065528
    // 0x8002D150: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80065528(rdram, ctx);
        goto after_2;
    // 0x8002D150: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_2:
    // 0x8002D154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D15C: jr          $ra
    // 0x8002D160: nop

    return;
    // 0x8002D160: nop

;}
RECOMP_FUNC void func_80519594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051959C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x805195A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805195A4: bnel        $t6, $zero, L_805195E0
    if (ctx->r14 != 0) {
        // 0x805195A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805195E0;
    }
    goto skip_0;
    // 0x805195A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805195AC: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x805195B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x805195B4: beql        $v0, $zero, L_805195C8
    if (ctx->r2 == 0) {
        // 0x805195B8: lw          $a0, 0x34($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X34);
            goto L_805195C8;
    }
    goto skip_1;
    // 0x805195B8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    skip_1:
    // 0x805195BC: bnel        $v0, $at, L_805195E0
    if (ctx->r2 != ctx->r1) {
        // 0x805195C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805195E0;
    }
    goto skip_2;
    // 0x805195C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805195C4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
L_805195C8:
    // 0x805195C8: jal         0x80067BBC
    // 0x805195CC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805195CC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x805195D0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x805195D4: jal         0x80067818
    // 0x805195D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805195D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805195DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805195E0:
    // 0x805195E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805195E4: jr          $ra
    // 0x805195E8: nop

    return;
    // 0x805195E8: nop

;}
RECOMP_FUNC void func_80672298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067229C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806722A0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806722A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806722A8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x806722AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806722B0: jal         0x80671D4C
    // 0x806722B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x806722B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x806722B8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806722BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806722C0: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x806722C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806722C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806722CC: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x806722D0: bne         $at, $zero, L_806722F0
    if (ctx->r1 != 0) {
        // 0x806722D4: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_806722F0;
    }
    // 0x806722D4: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x806722D8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x806722DC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806722E0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x806722E4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x806722E8: jal         0x80672C80
    // 0x806722EC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x806722EC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_806722F0:
    // 0x806722F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806722F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806722F8: jr          $ra
    // 0x806722FC: nop

    return;
    // 0x806722FC: nop

;}
RECOMP_FUNC void csleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800821A0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800821A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800821A8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800821AC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800821B0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800821B4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800821B8: jal         0x8008AE20
    // 0x800821BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800821BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800821C0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800821C4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800821C8: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x800821CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800821D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800821D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800821D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800821DC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800821E0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800821E4: jal         0x8008F6D0
    // 0x800821E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_1;
    // 0x800821E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x800821EC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800821F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800821F4: jal         0x800824B0
    // 0x800821F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800821F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800821FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80082200: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80082204: jr          $ra
    // 0x80082208: nop

    return;
    // 0x80082208: nop

;}
RECOMP_FUNC void func_807A9C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A9C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A9CA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A9CA4: jal         0x807A9D4C
    // 0x807A9CA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807A9D4C(rdram, ctx);
        goto after_0;
    // 0x807A9CA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807A9CAC: beq         $v0, $zero, L_807A9D30
    if (ctx->r2 == 0) {
        // 0x807A9CB0: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_807A9D30;
    }
    // 0x807A9CB0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807A9CB4: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x807A9CB8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807A9CBC: lui         $t7, 0x807B
    ctx->r15 = S32(RELOC_HI16(853, 0X1BA0) << 16);
    // 0x807A9CC0: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x807A9CC4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x807A9CC8: addiu       $t7, $t7, -0x4820
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(853, 0X1BA0));
    // 0x807A9CCC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A9CD0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807A9CD4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x807A9CD8: jal         0x807A9E00
    // 0x807A9CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A9E00(rdram, ctx);
        goto after_1;
    // 0x807A9CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807A9CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A9CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A9CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807A9CEC: jal         0x807AB278
    // 0x807A9CF0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_807AB278(rdram, ctx);
        goto after_2;
    // 0x807A9CF0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x807A9CF4: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x807A9CF8: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(853, 0X454) << 16);
    // 0x807A9CFC: addiu       $t9, $t9, -0x5F6C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(853, 0X454));
    // 0x807A9D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A9D04: jal         0x807A9C80
    // 0x807A9D08: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_807A9C80(rdram, ctx);
        goto after_3;
    // 0x807A9D08: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x807A9D0C: jal         0x807AB428
    // 0x807A9D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AB428(rdram, ctx);
        goto after_4;
    // 0x807A9D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807A9D14: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x807A9D18: bne         $v0, $zero, L_807A9D38
    if (ctx->r2 != 0) {
        // 0x807A9D1C: sw          $v0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r2;
            goto L_807A9D38;
    }
    // 0x807A9D1C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x807A9D20: jal         0x800445A4
    // 0x807A9D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x807A9D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807A9D28: b           L_807A9D3C
    // 0x807A9D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807A9D3C;
    // 0x807A9D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A9D30:
    // 0x807A9D30: jal         0x800445A4
    // 0x807A9D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x807A9D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_807A9D38:
    // 0x807A9D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A9D3C:
    // 0x807A9D3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A9D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807A9D44: jr          $ra
    // 0x807A9D48: nop

    return;
    // 0x807A9D48: nop

;}
RECOMP_FUNC void func_8064AACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064AAD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064AAD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064AAD8: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064AADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064AAE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AAE4: blez        $v0, L_8064AAF8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064AAE8: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064AAF8;
    }
    // 0x8064AAE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064AAEC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064AAF0: b           L_8064AB24
    // 0x8064AAF4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064AB24;
    // 0x8064AAF4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064AAF8:
    // 0x8064AAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064AAFC: jal         0x8064AEA8
    // 0x8064AB00: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064AEA8(rdram, ctx);
        goto after_0;
    // 0x8064AB00: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064AB04: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064AB08: jal         0x80067BBC
    // 0x8064AB0C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064AB0C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064AB10: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064AB14: jal         0x80067818
    // 0x8064AB18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064AB18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064AB1C: jal         0x8064A43C
    // 0x8064AB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064AB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064AB24:
    // 0x8064AB24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064AB28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064AB2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064AB30: jr          $ra
    // 0x8064AB34: nop

    return;
    // 0x8064AB34: nop

;}
RECOMP_FUNC void func_804CF0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF0A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CF0AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CF0B0: jal         0x8004700C
    // 0x804CF0B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CF0B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CF0B8: beql        $v0, $zero, L_804CF12C
    if (ctx->r2 == 0) {
        // 0x804CF0BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CF12C;
    }
    goto skip_0;
    // 0x804CF0BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CF0C0: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x804CF0C4: bne         $s0, $t6, L_804CF0FC
    if (ctx->r16 != ctx->r14) {
        // 0x804CF0C8: nop
    
            goto L_804CF0FC;
    }
    // 0x804CF0C8: nop

    // 0x804CF0CC: jal         0x804CEE78
    // 0x804CF0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CEE78(rdram, ctx);
        goto after_1;
    // 0x804CF0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CF0D4: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(240, 0XC78) << 16);
    // 0x804CF0D8: addiu       $a1, $a1, -0x10D8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(240, 0XC78));
    // 0x804CF0DC: jal         0x800628E4
    // 0x804CF0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800628E4(rdram, ctx);
        goto after_2;
    // 0x804CF0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804CF0E4: jal         0x804CECC8
    // 0x804CF0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECC8(rdram, ctx);
        goto after_3;
    // 0x804CF0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CF0EC: jal         0x804CECB8
    // 0x804CF0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECB8(rdram, ctx);
        goto after_4;
    // 0x804CF0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804CF0F4: b           L_804CF12C
    // 0x804CF0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CF12C;
    // 0x804CF0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF0FC:
    // 0x804CF0FC: jal         0x804CED5C
    // 0x804CF100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CED5C(rdram, ctx);
        goto after_5;
    // 0x804CF100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CF104: jal         0x804CECC8
    // 0x804CF108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECC8(rdram, ctx);
        goto after_6;
    // 0x804CF108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804CF10C: jal         0x804CECB8
    // 0x804CF110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECB8(rdram, ctx);
        goto after_7;
    // 0x804CF110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804CF114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CF118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CF11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CF120: jal         0x804CF34C
    // 0x804CF124: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CF34C(rdram, ctx);
        goto after_8;
    // 0x804CF124: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_8:
    // 0x804CF128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF12C:
    // 0x804CF12C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CF130: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CF134: jr          $ra
    // 0x804CF138: nop

    return;
    // 0x804CF138: nop

;}
RECOMP_FUNC void func_8006C3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3C4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006C3C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C3CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006C3D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006C3D4:
    // 0x8006C3D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006C3D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006C3DC: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8006C3E0: bne         $v0, $a0, L_8006C3D4
    if (ctx->r2 != ctx->r4) {
        // 0x8006C3E4: swc1        $f0, 0x28($v1)
        MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
            goto L_8006C3D4;
    }
    // 0x8006C3E4: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x8006C3E8: jr          $ra
    // 0x8006C3EC: nop

    return;
    // 0x8006C3EC: nop

;}
RECOMP_FUNC void func_8078EF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EF60: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078EF64: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8078EF68: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8078EF6C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8078EF70: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8078EF74: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078EF78: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8078EF7C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8078EF80: lbu         $t6, 0xF5C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF5C);
    // 0x8078EF84: lbu         $t8, 0xF5D($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF5D);
    // 0x8078EF88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078EF8C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8078EF90: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8078EF94: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8078EF98: lhu         $t0, 0x630C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X630C);
    // 0x8078EF9C: jr          $ra
    // 0x8078EFA0: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    return;
    // 0x8078EFA0: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_8002C684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C68C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002C690: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C694: addiu       $a1, $a1, -0x2848
    ctx->r5 = ADD32(ctx->r5, -0X2848);
    // 0x8002C698: lw          $t7, 0x1C0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C0);
    // 0x8002C69C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002C6A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002C6A4: jal         0x80028118
    // 0x8002C6A8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C6A8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8002C6AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002C6B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C6B4: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002C6B8: addiu       $t8, $t8, 0x381C
    ctx->r24 = ADD32(ctx->r24, 0X381C);
    // 0x8002C6BC: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x8002C6C0: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C6C4: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C6C8: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C6CC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C6D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002C6D4: lw          $t0, 0x134($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X134);
    // 0x8002C6D8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002C6DC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8002C6E0: lwc1        $f4, -0x18B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X18B4);
    // 0x8002C6E4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002C6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C6EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C6F0: jr          $ra
    // 0x8002C6F4: nop

    return;
    // 0x8002C6F4: nop

;}
RECOMP_FUNC void func_80079D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079D48: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80079D4C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80079D50: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80079D54: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80079D58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80079D5C: lwc1        $f20, 0x170($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X170);
    // 0x80079D60: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80079D64: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80079D68: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80079D6C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80079D70: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80079D74: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80079D78: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80079D7C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80079D80: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80079D84: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80079D88: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80079D8C: sw          $a0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r4;
    // 0x80079D90: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x80079D94: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    // 0x80079D98: sw          $a3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r7;
    // 0x80079D9C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x80079DA0: lw          $s0, 0x160($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X160);
    // 0x80079DA4: lwc1        $f0, 0x174($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X174);
    // 0x80079DA8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80079DAC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80079DB0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80079DB4: sw          $s0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r16;
    // 0x80079DB8: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x80079DBC: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80079DC0: jal         0x80081FE0
    // 0x80079DC4: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x80079DC4: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    after_0:
    // 0x80079DC8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80079DCC: lwc1        $f6, 0x174($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X174);
    // 0x80079DD0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80079DD4: div.s       $f12, $f22, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80079DD8: jal         0x80081FE0
    // 0x80079DDC: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    floorf_recomp(rdram, ctx);
        goto after_1;
    // 0x80079DDC: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    after_1:
    // 0x80079DE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80079DE4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80079DE8: lwc1        $f16, 0x174($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X174);
    // 0x80079DEC: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80079DF0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80079DF4: bc1f        L_80079E58
    if (!c1cs) {
        // 0x80079DF8: sw          $t4, 0x120($sp)
        MEM_W(0X120, ctx->r29) = ctx->r12;
            goto L_80079E58;
    }
    // 0x80079DF8: sw          $t4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r12;
    // 0x80079DFC: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80079E00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079E04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80079E08: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80079E0C: lwc1        $f2, 0x168($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X168);
    // 0x80079E10: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079E14: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80079E18: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x80079E1C: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80079E20: nop

    // 0x80079E24: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80079E28: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80079E2C: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079E30: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80079E34: nop

    // 0x80079E38: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80079E3C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80079E40: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80079E44: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80079E48: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80079E4C: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x80079E50: b           L_80079EB8
    // 0x80079E54: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
        goto L_80079EB8;
    // 0x80079E54: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
L_80079E58:
    // 0x80079E58: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80079E5C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079E60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80079E64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80079E68: lwc1        $f2, 0x168($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X168);
    // 0x80079E6C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079E70: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80079E74: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80079E78: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80079E7C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80079E80: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80079E84: sw          $t8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r24;
    // 0x80079E88: mul.s       $f0, $f18, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80079E8C: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079E90: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80079E94: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80079E98: nop

    // 0x80079E9C: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80079EA0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80079EA4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80079EA8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80079EAC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80079EB0: sw          $t3, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r11;
    // 0x80079EB4: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
L_80079EB8:
    // 0x80079EB8: lw          $s6, 0x164($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X164);
    // 0x80079EBC: lwc1        $f10, 0x12C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80079EC0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80079EC4: addiu       $t9, $s6, -0x1
    ctx->r25 = ADD32(ctx->r22, -0X1);
    // 0x80079EC8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80079ECC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80079ED0: lwc1        $f22, 0x16C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x80079ED4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80079ED8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80079EDC: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x80079EE0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80079EE4: nop

    // 0x80079EE8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80079EEC: bc1f        L_8007A2E8
    if (!c1cs) {
        // 0x80079EF0: sub.s       $f22, $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
            goto L_8007A2E8;
    }
    // 0x80079EF0: sub.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x80079EF4: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x80079EF8: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x80079EFC: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x80079F00: addiu       $t8, $s6, -0x1
    ctx->r24 = ADD32(ctx->r22, -0X1);
    // 0x80079F04: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80079F08: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80079F0C: bne         $t5, $zero, L_80079F18
    if (ctx->r13 != 0) {
        // 0x80079F10: nop
    
            goto L_80079F18;
    }
    // 0x80079F10: nop

    // 0x80079F14: break       7
    do_break(2147983124);
L_80079F18:
    // 0x80079F18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079F1C: bne         $t5, $at, L_80079F30
    if (ctx->r13 != ctx->r1) {
        // 0x80079F20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079F30;
    }
    // 0x80079F20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079F24: bne         $t4, $at, L_80079F30
    if (ctx->r12 != ctx->r1) {
        // 0x80079F28: nop
    
            goto L_80079F30;
    }
    // 0x80079F28: nop

    // 0x80079F2C: break       6
    do_break(2147983148);
L_80079F30:
    // 0x80079F30: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80079F34: lui         $at, 0x3A80
    ctx->r1 = S32(0X3A80 << 16);
    // 0x80079F38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079F3C: mflo        $t6
    ctx->r14 = lo;
    // 0x80079F40: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80079F44: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80079F48: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80079F4C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80079F50: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
L_80079F54:
    // 0x80079F54: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80079F58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079F5C: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80079F60: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80079F64: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x80079F68: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80079F6C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80079F70: mfc1        $fp, $f8
    ctx->r30 = (int32_t)ctx->f8.u32l;
    // 0x80079F74: nop

    // 0x80079F78: sra         $s3, $fp, 5
    ctx->r19 = S32(SIGNED(ctx->r30) >> 5);
    // 0x80079F7C: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
    // 0x80079F80: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80079F84: beq         $at, $zero, L_80079F94
    if (ctx->r1 == 0) {
        // 0x80079F88: nop
    
            goto L_80079F94;
    }
    // 0x80079F88: nop

    // 0x80079F8C: b           L_80079F94
    // 0x80079F90: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
        goto L_80079F94;
    // 0x80079F90: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_80079F94:
    // 0x80079F94: addiu       $s7, $s5, -0x1
    ctx->r23 = ADD32(ctx->r21, -0X1);
    // 0x80079F98: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x80079F9C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80079FA0: swc1        $f2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f2.u32l;
    // 0x80079FA4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80079FA8: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079FAC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80079FB0: jal         0x80081FE0
    // 0x80079FB4: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x80079FB4: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80079FB8: lwc1        $f2, 0x138($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80079FBC: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80079FC0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80079FC4: nop

    // 0x80079FC8: bc1fl       L_80079FE4
    if (!c1cs) {
        // 0x80079FCC: add.s       $f4, $f22, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
            goto L_80079FE4;
    }
    goto skip_0;
    // 0x80079FCC: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
    skip_0:
    // 0x80079FD0: jal         0x80081FE0
    // 0x80079FD4: swc1        $f2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f2.u32l;
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x80079FD4: swc1        $f2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80079FD8: lwc1        $f2, 0x138($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X138);
    // 0x80079FDC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80079FE0: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
L_80079FE4:
    // 0x80079FE4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80079FE8: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x80079FEC: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80079FF0: lhu         $t5, 0x1A($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X1A);
    // 0x80079FF4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80079FF8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80079FFC: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8007A000: nop

    // 0x8007A004: slt         $at, $t0, $t6
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007A008: bnel        $at, $zero, L_8007A2D0
    if (ctx->r1 != 0) {
        // 0x8007A00C: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_8007A2D0;
    }
    goto skip_1;
    // 0x8007A00C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_1:
    // 0x8007A010: add.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8007A014: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007A018: lw          $v0, 0x160($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X160);
    // 0x8007A01C: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x8007A020: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007A024: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007A028: lw          $a3, 0x15C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X15C);
    // 0x8007A02C: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x8007A030: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x8007A034: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x8007A038: subu        $t6, $s5, $s3
    ctx->r14 = SUB32(ctx->r21, ctx->r19);
    // 0x8007A03C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007A040: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8007A044: nop

    // 0x8007A048: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007A04C: bnel        $at, $zero, L_8007A2D0
    if (ctx->r1 != 0) {
        // 0x8007A050: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_8007A2D0;
    }
    goto skip_2;
    // 0x8007A050: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x8007A054: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A058: lw          $t3, 0x120($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X120);
    // 0x8007A05C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8007A060: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007A064: andi        $t6, $a2, 0x7
    ctx->r14 = ctx->r6 & 0X7;
    // 0x8007A068: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007A06C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8007A070: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007A074: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007A078: lw          $s0, 0xF4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XF4);
    // 0x8007A07C: mflo        $t4
    ctx->r12 = lo;
    // 0x8007A080: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8007A084: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8007A088: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8007A08C: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8007A090: sllv        $t5, $v0, $a3
    ctx->r13 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8007A094: andi        $t3, $a3, 0x3
    ctx->r11 = ctx->r7 & 0X3;
    // 0x8007A098: sll         $t9, $t3, 19
    ctx->r25 = S32(ctx->r11 << 19);
    // 0x8007A09C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007A0A0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8007A0A4: addiu       $t3, $t7, 0x7
    ctx->r11 = ADD32(ctx->r15, 0X7);
    // 0x8007A0A8: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x8007A0AC: sra         $t8, $t3, 3
    ctx->r24 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8007A0B0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007A0B4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8007A0B8: andi        $s0, $s0, 0xFFF
    ctx->r16 = ctx->r16 & 0XFFF;
    // 0x8007A0BC: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x8007A0C0: or          $s2, $t4, $t5
    ctx->r18 = ctx->r12 | ctx->r13;
    // 0x8007A0C4: sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16 << 12);
    // 0x8007A0C8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007A0CC: lh          $s1, 0x102($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X102);
    // 0x8007A0D0: lh          $s4, 0x10A($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X10A);
    // 0x8007A0D4: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8007A0D8: jal         0x80077038
    // 0x8007A0DC: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    func_80077038(rdram, ctx);
        goto after_4;
    // 0x8007A0DC: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    after_4:
    // 0x8007A0E0: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8007A0E4: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8007A0E8: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8007A0EC: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x8007A0F0: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8007A0F4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007A0F8: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    // 0x8007A0FC: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8007A100: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x8007A104: lw          $v1, 0x140($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X140);
    // 0x8007A108: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8007A10C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x8007A110: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007A114: sw          $t9, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r25;
    // 0x8007A118: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8007A11C: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8007A120: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007A124: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8007A128: or          $t8, $s0, $t3
    ctx->r24 = ctx->r16 | ctx->r11;
    // 0x8007A12C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007A130: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007A134: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x8007A138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007A13C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007A140: blez        $s1, L_8007A150
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8007A144: sw          $v0, 0x140($sp)
        MEM_W(0X140, ctx->r29) = ctx->r2;
            goto L_8007A150;
    }
    // 0x8007A144: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x8007A148: b           L_8007A154
    // 0x8007A14C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
        goto L_8007A154;
    // 0x8007A14C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_8007A150:
    // 0x8007A150: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007A154:
    // 0x8007A154: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8007A158: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007A15C: blez        $a0, L_8007A16C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007A160: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_8007A16C;
    }
    // 0x8007A160: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007A164: b           L_8007A170
    // 0x8007A168: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A170;
    // 0x8007A168: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A16C:
    // 0x8007A16C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A170:
    // 0x8007A170: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8007A174: andi        $t5, $v1, 0xFFF
    ctx->r13 = ctx->r3 & 0XFFF;
    // 0x8007A178: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8007A17C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8007A180: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8007A184: blez        $s4, L_8007A194
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007A188: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_8007A194;
    }
    // 0x8007A188: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007A18C: b           L_8007A198
    // 0x8007A190: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
        goto L_8007A198;
    // 0x8007A190: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_8007A194:
    // 0x8007A194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007A198:
    // 0x8007A198: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8007A19C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007A1A0: blez        $a0, L_8007A1B0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007A1A4: andi        $t8, $v1, 0xFFF
        ctx->r24 = ctx->r3 & 0XFFF;
            goto L_8007A1B0;
    }
    // 0x8007A1A4: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x8007A1A8: b           L_8007A1B4
    // 0x8007A1AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A1B4;
    // 0x8007A1AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A1B0:
    // 0x8007A1B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A1B4:
    // 0x8007A1B4: andi        $t3, $v0, 0xFFF
    ctx->r11 = ctx->r2 & 0XFFF;
    // 0x8007A1B8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007A1BC: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x8007A1C0: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007A1C4: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x8007A1C8: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8007A1CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007A1D0: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8007A1D4: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x8007A1D8: bgez        $s4, L_8007A22C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8007A1DC: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_8007A22C;
    }
    // 0x8007A1DC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007A1E0: lh          $v0, 0x126($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X126);
    // 0x8007A1E4: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A1E8: mflo        $v1
    ctx->r3 = lo;
    // 0x8007A1EC: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8007A1F0: bgez        $v0, L_8007A210
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007A1F4: nop
    
            goto L_8007A210;
    }
    // 0x8007A1F4: nop

    // 0x8007A1F8: blez        $v1, L_8007A208
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007A1FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007A208;
    }
    // 0x8007A1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A200: b           L_8007A22C
    // 0x8007A204: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007A22C;
    // 0x8007A204: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007A208:
    // 0x8007A208: b           L_8007A22C
    // 0x8007A20C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8007A22C;
    // 0x8007A20C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8007A210:
    // 0x8007A210: bgez        $v1, L_8007A220
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007A214: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007A220;
    }
    // 0x8007A214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A218: b           L_8007A220
    // 0x8007A21C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007A220;
    // 0x8007A21C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007A220:
    // 0x8007A220: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007A224: b           L_8007A22C
    // 0x8007A228: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007A22C;
    // 0x8007A228: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007A22C:
    // 0x8007A22C: bgez        $t2, L_8007A294
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007A230: lw          $t9, 0x11C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X11C);
            goto L_8007A294;
    }
    // 0x8007A230: lw          $t9, 0x11C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X11C);
    // 0x8007A234: lh          $v1, 0x122($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X122);
    // 0x8007A238: bgez        $v1, L_8007A268
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007A23C: nop
    
            goto L_8007A268;
    }
    // 0x8007A23C: nop

    // 0x8007A240: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A248: mflo        $v0
    ctx->r2 = lo;
    // 0x8007A24C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007A250: blez        $v0, L_8007A260
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A254: nop
    
            goto L_8007A260;
    }
    // 0x8007A254: nop

    // 0x8007A258: b           L_8007A29C
    // 0x8007A25C: subu        $t8, $fp, $v0
    ctx->r24 = SUB32(ctx->r30, ctx->r2);
        goto L_8007A29C;
    // 0x8007A25C: subu        $t8, $fp, $v0
    ctx->r24 = SUB32(ctx->r30, ctx->r2);
L_8007A260:
    // 0x8007A260: b           L_8007A298
    // 0x8007A264: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A298;
    // 0x8007A264: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A268:
    // 0x8007A268: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A26C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A270: mflo        $v0
    ctx->r2 = lo;
    // 0x8007A274: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007A278: bgez        $v0, L_8007A288
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007A27C: nop
    
            goto L_8007A288;
    }
    // 0x8007A27C: nop

    // 0x8007A280: b           L_8007A288
    // 0x8007A284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8007A288;
    // 0x8007A284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007A288:
    // 0x8007A288: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007A28C: b           L_8007A298
    // 0x8007A290: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007A298;
    // 0x8007A290: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007A294:
    // 0x8007A294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A298:
    // 0x8007A298: subu        $t8, $fp, $v0
    ctx->r24 = SUB32(ctx->r30, ctx->r2);
L_8007A29C:
    // 0x8007A29C: subu        $t4, $t9, $a1
    ctx->r12 = SUB32(ctx->r25, ctx->r5);
    // 0x8007A2A0: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x8007A2A4: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x8007A2A8: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8007A2AC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007A2B0: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8007A2B4: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x8007A2B8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007A2BC: sw          $t9, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r25;
    // 0x8007A2C0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8007A2C4: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007A2C8: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8007A2CC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8007A2D0:
    // 0x8007A2D0: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8007A2D4: slt         $at, $s7, $t3
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007A2D8: bnel        $at, $zero, L_80079F54
    if (ctx->r1 != 0) {
        // 0x8007A2DC: lwc1        $f0, 0x98($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
            goto L_80079F54;
    }
    goto skip_3;
    // 0x8007A2DC: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
    skip_3:
    // 0x8007A2E0: b           L_8007A6BC
    // 0x8007A2E4: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
        goto L_8007A6BC;
    // 0x8007A2E4: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
L_8007A2E8:
    // 0x8007A2E8: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8007A2EC: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x8007A2F0: bc1fl       L_8007A6BC
    if (!c1cs) {
        // 0x8007A2F4: lw          $t4, 0x140($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X140);
            goto L_8007A6BC;
    }
    goto skip_4;
    // 0x8007A2F4: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    skip_4:
    // 0x8007A2F8: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x8007A2FC: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x8007A300: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8007A304: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007A308: bne         $t7, $zero, L_8007A314
    if (ctx->r15 != 0) {
        // 0x8007A30C: nop
    
            goto L_8007A314;
    }
    // 0x8007A30C: nop

    // 0x8007A310: break       7
    do_break(2147984144);
L_8007A314:
    // 0x8007A314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007A318: bne         $t7, $at, L_8007A32C
    if (ctx->r15 != ctx->r1) {
        // 0x8007A31C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007A32C;
    }
    // 0x8007A31C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A320: bne         $t6, $at, L_8007A32C
    if (ctx->r14 != ctx->r1) {
        // 0x8007A324: nop
    
            goto L_8007A32C;
    }
    // 0x8007A324: nop

    // 0x8007A328: break       6
    do_break(2147984168);
L_8007A32C:
    // 0x8007A32C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007A330: lui         $at, 0xBA80
    ctx->r1 = S32(0XBA80 << 16);
    // 0x8007A334: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A338: mflo        $t8
    ctx->r24 = lo;
    // 0x8007A33C: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8007A340: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A344: nop

L_8007A348:
    // 0x8007A348: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007A34C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8007A350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A354: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007A358: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x8007A35C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8007A360: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x8007A364: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007A368: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x8007A36C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8007A370: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007A374: mfc1        $s7, $f8
    ctx->r23 = (int32_t)ctx->f8.u32l;
    // 0x8007A378: nop

    // 0x8007A37C: sra         $t1, $s7, 5
    ctx->r9 = S32(SIGNED(ctx->r23) >> 5);
    // 0x8007A380: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x8007A384: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007A388: beq         $at, $zero, L_8007A398
    if (ctx->r1 == 0) {
        // 0x8007A38C: nop
    
            goto L_8007A398;
    }
    // 0x8007A38C: nop

    // 0x8007A390: b           L_8007A398
    // 0x8007A394: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
        goto L_8007A398;
    // 0x8007A394: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
L_8007A398:
    // 0x8007A398: addiu       $t3, $s5, -0x1
    ctx->r11 = ADD32(ctx->r21, -0X1);
    // 0x8007A39C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8007A3A0: nop

    // 0x8007A3A4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007A3A8: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007A3AC: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x8007A3B0: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8007A3B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007A3B8: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8007A3BC: nop

    // 0x8007A3C0: slt         $at, $s3, $a0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007A3C4: bnel        $at, $zero, L_8007A6B0
    if (ctx->r1 != 0) {
        // 0x8007A3C8: slt         $at, $s5, $s6
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8007A6B0;
    }
    goto skip_5;
    // 0x8007A3C8: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
    skip_5:
    // 0x8007A3CC: add.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8007A3D0: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007A3D4: lw          $v0, 0x160($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X160);
    // 0x8007A3D8: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x8007A3DC: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007A3E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007A3E4: lw          $a3, 0x15C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X15C);
    // 0x8007A3E8: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x8007A3EC: subu        $t0, $s6, $s5
    ctx->r8 = SUB32(ctx->r22, ctx->r21);
    // 0x8007A3F0: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x8007A3F4: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x8007A3F8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007A3FC: subu        $t6, $s5, $t1
    ctx->r14 = SUB32(ctx->r21, ctx->r9);
    // 0x8007A400: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8007A404: nop

    // 0x8007A408: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007A40C: bnel        $at, $zero, L_8007A6B0
    if (ctx->r1 != 0) {
        // 0x8007A410: slt         $at, $s5, $s6
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8007A6B0;
    }
    goto skip_6;
    // 0x8007A410: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
    skip_6:
    // 0x8007A414: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A418: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x8007A41C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8007A420: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007A424: andi        $t6, $a2, 0x7
    ctx->r14 = ctx->r6 & 0X7;
    // 0x8007A428: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007A42C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8007A430: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007A434: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007A438: lw          $s0, 0xF4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XF4);
    // 0x8007A43C: mflo        $t4
    ctx->r12 = lo;
    // 0x8007A440: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x8007A444: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x8007A448: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x8007A44C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8007A450: sllv        $t3, $v0, $a3
    ctx->r11 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8007A454: andi        $t5, $a3, 0x3
    ctx->r13 = ctx->r7 & 0X3;
    // 0x8007A458: sll         $t9, $t5, 19
    ctx->r25 = S32(ctx->r13 << 19);
    // 0x8007A45C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8007A460: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8007A464: addiu       $t5, $t7, 0x7
    ctx->r13 = ADD32(ctx->r15, 0X7);
    // 0x8007A468: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x8007A46C: sra         $t8, $t5, 3
    ctx->r24 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8007A470: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x8007A474: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007A478: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8007A47C: andi        $s0, $s0, 0xFFF
    ctx->r16 = ctx->r16 & 0XFFF;
    // 0x8007A480: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x8007A484: or          $s2, $t4, $t3
    ctx->r18 = ctx->r12 | ctx->r11;
    // 0x8007A488: sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16 << 12);
    // 0x8007A48C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007A490: lh          $s1, 0x102($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X102);
    // 0x8007A494: lh          $s4, 0x10A($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X10A);
    // 0x8007A498: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8007A49C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8007A4A0: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x8007A4A4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8007A4A8: jal         0x80077038
    // 0x8007A4AC: sll         $fp, $fp, 5
    ctx->r30 = S32(ctx->r30 << 5);
    func_80077038(rdram, ctx);
        goto after_5;
    // 0x8007A4AC: sll         $fp, $fp, 5
    ctx->r30 = S32(ctx->r30 << 5);
    after_5:
    // 0x8007A4B0: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8007A4B4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8007A4B8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8007A4BC: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007A4C0: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8007A4C4: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8007A4C8: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8007A4CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007A4D0: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    // 0x8007A4D4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007A4D8: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x8007A4DC: lw          $v1, 0x140($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X140);
    // 0x8007A4E0: subu        $t7, $s6, $t1
    ctx->r15 = SUB32(ctx->r22, ctx->r9);
    // 0x8007A4E4: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007A4E8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007A4EC: sw          $t9, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r25;
    // 0x8007A4F0: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8007A4F4: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x8007A4F8: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x8007A4FC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007A500: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x8007A504: or          $t9, $s0, $t8
    ctx->r25 = ctx->r16 | ctx->r24;
    // 0x8007A508: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007A50C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007A510: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x8007A514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007A518: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007A51C: blez        $s1, L_8007A52C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8007A520: sw          $v0, 0x140($sp)
        MEM_W(0X140, ctx->r29) = ctx->r2;
            goto L_8007A52C;
    }
    // 0x8007A520: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x8007A524: b           L_8007A530
    // 0x8007A528: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
        goto L_8007A530;
    // 0x8007A528: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_8007A52C:
    // 0x8007A52C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007A530:
    // 0x8007A530: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007A534: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007A538: blez        $a0, L_8007A548
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007A53C: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_8007A548;
    }
    // 0x8007A53C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007A540: b           L_8007A54C
    // 0x8007A544: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A54C;
    // 0x8007A544: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A548:
    // 0x8007A548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A54C:
    // 0x8007A54C: andi        $t4, $v0, 0xFFF
    ctx->r12 = ctx->r2 & 0XFFF;
    // 0x8007A550: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x8007A554: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007A558: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x8007A55C: or          $t5, $t3, $t7
    ctx->r13 = ctx->r11 | ctx->r15;
    // 0x8007A560: blez        $s4, L_8007A570
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007A564: sw          $t5, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r13;
            goto L_8007A570;
    }
    // 0x8007A564: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007A568: b           L_8007A574
    // 0x8007A56C: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
        goto L_8007A574;
    // 0x8007A56C: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_8007A570:
    // 0x8007A570: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007A574:
    // 0x8007A574: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8007A578: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007A57C: blez        $a0, L_8007A58C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007A580: andi        $t9, $v1, 0xFFF
        ctx->r25 = ctx->r3 & 0XFFF;
            goto L_8007A58C;
    }
    // 0x8007A580: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x8007A584: b           L_8007A590
    // 0x8007A588: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A590;
    // 0x8007A588: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A58C:
    // 0x8007A58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A590:
    // 0x8007A590: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8007A594: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x8007A598: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8007A59C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007A5A0: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x8007A5A4: lui         $t5, 0xB400
    ctx->r13 = S32(0XB400 << 16);
    // 0x8007A5A8: subu        $t9, $fp, $s7
    ctx->r25 = SUB32(ctx->r30, ctx->r23);
    // 0x8007A5AC: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8007A5B0: sw          $t7, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r15;
    // 0x8007A5B4: bgez        $s4, L_8007A608
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8007A5B8: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_8007A608;
    }
    // 0x8007A5B8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007A5BC: lh          $v0, 0x126($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X126);
    // 0x8007A5C0: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A5C4: mflo        $v1
    ctx->r3 = lo;
    // 0x8007A5C8: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8007A5CC: bgez        $v0, L_8007A5EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007A5D0: nop
    
            goto L_8007A5EC;
    }
    // 0x8007A5D0: nop

    // 0x8007A5D4: blez        $v1, L_8007A5E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007A5D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007A5E4;
    }
    // 0x8007A5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A5DC: b           L_8007A60C
    // 0x8007A5E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007A60C;
    // 0x8007A5E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007A5E4:
    // 0x8007A5E4: b           L_8007A60C
    // 0x8007A5E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8007A60C;
    // 0x8007A5E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8007A5EC:
    // 0x8007A5EC: bgez        $v1, L_8007A5FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007A5F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007A5FC;
    }
    // 0x8007A5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A5F4: b           L_8007A5FC
    // 0x8007A5F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007A5FC;
    // 0x8007A5F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007A5FC:
    // 0x8007A5FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007A600: b           L_8007A60C
    // 0x8007A604: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007A60C;
    // 0x8007A604: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007A608:
    // 0x8007A608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8007A60C:
    // 0x8007A60C: bgez        $t2, L_8007A674
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007A610: lw          $t6, 0x11C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X11C);
            goto L_8007A674;
    }
    // 0x8007A610: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x8007A614: lh          $v1, 0x122($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X122);
    // 0x8007A618: bgez        $v1, L_8007A648
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007A61C: nop
    
            goto L_8007A648;
    }
    // 0x8007A61C: nop

    // 0x8007A620: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A628: mflo        $v0
    ctx->r2 = lo;
    // 0x8007A62C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007A630: blez        $v0, L_8007A640
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007A634: nop
    
            goto L_8007A640;
    }
    // 0x8007A634: nop

    // 0x8007A638: b           L_8007A67C
    // 0x8007A63C: subu        $t8, $t9, $v0
    ctx->r24 = SUB32(ctx->r25, ctx->r2);
        goto L_8007A67C;
    // 0x8007A63C: subu        $t8, $t9, $v0
    ctx->r24 = SUB32(ctx->r25, ctx->r2);
L_8007A640:
    // 0x8007A640: b           L_8007A678
    // 0x8007A644: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007A678;
    // 0x8007A644: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007A648:
    // 0x8007A648: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A64C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A650: mflo        $v0
    ctx->r2 = lo;
    // 0x8007A654: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007A658: bgez        $v0, L_8007A668
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007A65C: nop
    
            goto L_8007A668;
    }
    // 0x8007A65C: nop

    // 0x8007A660: b           L_8007A668
    // 0x8007A664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8007A668;
    // 0x8007A664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007A668:
    // 0x8007A668: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007A66C: b           L_8007A678
    // 0x8007A670: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007A678;
    // 0x8007A670: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007A674:
    // 0x8007A674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A678:
    // 0x8007A678: subu        $t8, $t9, $v0
    ctx->r24 = SUB32(ctx->r25, ctx->r2);
L_8007A67C:
    // 0x8007A67C: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8007A680: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x8007A684: andi        $t4, $t8, 0xFFFF
    ctx->r12 = ctx->r24 & 0XFFFF;
    // 0x8007A688: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8007A68C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8007A690: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8007A694: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x8007A698: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8007A69C: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x8007A6A0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8007A6A4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8007A6A8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8007A6AC: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
L_8007A6B0:
    // 0x8007A6B0: bne         $at, $zero, L_8007A348
    if (ctx->r1 != 0) {
        // 0x8007A6B4: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_8007A348;
    }
    // 0x8007A6B4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8007A6B8: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
L_8007A6BC:
    // 0x8007A6BC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x8007A6C0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007A6C4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8007A6C8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8007A6CC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8007A6D0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8007A6D4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8007A6D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A6DC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8007A6E0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8007A6E4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8007A6E8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8007A6EC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8007A6F0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8007A6F4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8007A6F8: jr          $ra
    // 0x8007A6FC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8007A6FC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_8001EA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EA24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001EA28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001EA2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EA30: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001EA34: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8001EA38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001EA3C: sb          $zero, 0x1F9($s0)
    MEM_B(0X1F9, ctx->r16) = 0;
    // 0x8001EA40: sb          $zero, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = 0;
    // 0x8001EA44: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8001EA48: jal         0x80047AB8
    // 0x8001EA4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8001EA4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8001EA50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001EA54: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8001EA58: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8001EA5C: lbu         $v0, 0x18($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X18);
    // 0x8001EA60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001EA64: bnel        $v0, $at, L_8001EA80
    if (ctx->r2 != ctx->r1) {
        // 0x8001EA68: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8001EA80;
    }
    goto skip_0;
    // 0x8001EA68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x8001EA6C: jal         0x8001E324
    // 0x8001EA70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_1;
    // 0x8001EA70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8001EA74: b           L_8001EB2C
    // 0x8001EA78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001EB2C;
    // 0x8001EA78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EA7C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8001EA80:
    // 0x8001EA80: beq         $v0, $at, L_8001EA94
    if (ctx->r2 == ctx->r1) {
        // 0x8001EA84: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8001EA94;
    }
    // 0x8001EA84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001EA88: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8001EA8C: bnel        $v0, $at, L_8001EAA8
    if (ctx->r2 != ctx->r1) {
        // 0x8001EA90: lwc1        $f4, 0x84($a3)
        ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
            goto L_8001EAA8;
    }
    goto skip_1;
    // 0x8001EA90: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    skip_1:
L_8001EA94:
    // 0x8001EA94: jal         0x8001E834
    // 0x8001EA98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E834(rdram, ctx);
        goto after_2;
    // 0x8001EA98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8001EA9C: b           L_8001EB2C
    // 0x8001EAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001EB2C;
    // 0x8001EAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EAA4: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
L_8001EAA8:
    // 0x8001EAA8: lwc1        $f6, 0xA8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XA8);
    // 0x8001EAAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EAB0: lwc1        $f2, -0x420($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X420);
    // 0x8001EAB4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001EAB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EABC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001EAC0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001EAC4: nop

    // 0x8001EAC8: bc1t        L_8001EB20
    if (c1cs) {
        // 0x8001EACC: nop
    
            goto L_8001EB20;
    }
    // 0x8001EACC: nop

    // 0x8001EAD0: lwc1        $f12, -0x41C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X41C);
    // 0x8001EAD4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001EAD8: nop

    // 0x8001EADC: bc1t        L_8001EB20
    if (c1cs) {
        // 0x8001EAE0: nop
    
            goto L_8001EB20;
    }
    // 0x8001EAE0: nop

    // 0x8001EAE4: lwc1        $f8, 0x88($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X88);
    // 0x8001EAE8: lwc1        $f10, 0xAC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XAC);
    // 0x8001EAEC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001EAF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001EAF4: nop

    // 0x8001EAF8: bc1t        L_8001EB20
    if (c1cs) {
        // 0x8001EAFC: nop
    
            goto L_8001EB20;
    }
    // 0x8001EAFC: nop

    // 0x8001EB00: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001EB04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001EB08: bc1t        L_8001EB20
    if (c1cs) {
        // 0x8001EB0C: nop
    
            goto L_8001EB20;
    }
    // 0x8001EB0C: nop

    // 0x8001EB10: jal         0x8001E788
    // 0x8001EB14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8001E788(rdram, ctx);
        goto after_3;
    // 0x8001EB14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8001EB18: b           L_8001EB2C
    // 0x8001EB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001EB2C;
    // 0x8001EB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EB20:
    // 0x8001EB20: jal         0x8001E834
    // 0x8001EB24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E834(rdram, ctx);
        goto after_4;
    // 0x8001EB24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8001EB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EB2C:
    // 0x8001EB2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EB30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001EB34: jr          $ra
    // 0x8001EB38: nop

    return;
    // 0x8001EB38: nop

;}
RECOMP_FUNC void func_804471C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804471C0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x804471C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804471C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804471CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804471D0: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x804471D4: addiu       $t0, $zero, 0x1B6C
    ctx->r8 = ADD32(0, 0X1B6C);
    // 0x804471D8: subu        $t1, $t0, $a3
    ctx->r9 = SUB32(ctx->r8, ctx->r7);
    // 0x804471DC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x804471E0: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x804471E4: slti        $at, $t8, 0x3C0
    ctx->r1 = SIGNED(ctx->r24) < 0X3C0 ? 1 : 0;
    // 0x804471E8: beq         $at, $zero, L_804471F4
    if (ctx->r1 == 0) {
        // 0x804471EC: sw          $t8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r24;
            goto L_804471F4;
    }
    // 0x804471EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804471F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_804471F4:
    // 0x804471F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804471F8: ori         $at, $at, 0x6AA0
    ctx->r1 = ctx->r1 | 0X6AA0;
    // 0x804471FC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80447200: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80447204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80447208: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8044720C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80447210: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80447214: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80447218: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8044721C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80447220: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80447224: nop

    // 0x80447228: bc1f        L_8044723C
    if (!c1cs) {
        // 0x8044722C: nop
    
            goto L_8044723C;
    }
    // 0x8044722C: nop

    // 0x80447230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80447234: nop

    // 0x80447238: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_8044723C:
    // 0x8044723C: jr          $ra
    // 0x80447240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80447240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8044E9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E9C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044E9C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8044E9C8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8044E9CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8044E9D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044E9D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8044E9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E9DC: div.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8044E9E0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8044E9E4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13C60) << 16);
    // 0x8044E9E8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8044E9EC: nop

    // 0x8044E9F0: bc1f        L_8044E9FC
    if (!c1cs) {
        // 0x8044E9F4: nop
    
            goto L_8044E9FC;
    }
    // 0x8044E9F4: nop

    // 0x8044E9F8: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_8044E9FC:
    // 0x8044E9FC: lwc1        $f0, -0x7FC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C60));
    // 0x8044EA00: lwc1        $f2, -0x7FBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C64));
    // 0x8044EA04: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13C78) << 16);
    // 0x8044EA08: lwc1        $f6, -0x7FA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C78));
    // 0x8044EA0C: lwc1        $f4, -0x7FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C7C));
    // 0x8044EA10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8044EA14: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8044EA18: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x8044EA1C: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(98, 0X13C78) << 16);
    // 0x8044EA20: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8044EA24: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8044EA28: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(98, 0X13C60) << 16);
    // 0x8044EA2C: addiu       $t8, $t8, -0x7FC0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X13C60));
    // 0x8044EA30: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8044EA34: addiu       $t7, $t7, -0x7FA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(98, 0X13C78));
    // 0x8044EA38: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x8044EA3C: addu        $a0, $a1, $t8
    ctx->r4 = ADD32(ctx->r5, ctx->r24);
    // 0x8044EA40: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8044EA44: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8044EA48: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044EA4C: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x8044EA50: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8044EA54: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8044EA58: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8044EA5C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8044EA60: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8044EA64: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8044EA68: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8044EA6C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8044EA70: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8044EA74: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8044EA78: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8044EA7C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8044EA80: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8044EA84: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8044EA88: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8044EA8C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8044EA90: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8044EA94: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8044EA98: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8044EA9C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8044EAA0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8044EAA4: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8044EAA8: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8044EAAC: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8044EAB0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8044EAB4: nop

    // 0x8044EAB8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8044EABC: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8044EAC0: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8044EAC4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8044EAC8: jal         0x8006C56C
    // 0x8044EACC: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    func_8006C56C(rdram, ctx);
        goto after_0;
    // 0x8044EACC: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    after_0:
    // 0x8044EAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044EAD4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8044EAD8: jr          $ra
    // 0x8044EADC: nop

    return;
    // 0x8044EADC: nop

;}
RECOMP_FUNC void func_8078E06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E06C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078E070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078E074: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8078E078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E07C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8078E080: jal         0x80067878
    // 0x8078E084: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8078E084: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8078E088: jal         0x80045BD8
    // 0x8078E08C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8078E08C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8078E090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078E094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078E098: jr          $ra
    // 0x8078E09C: nop

    return;
    // 0x8078E09C: nop

;}
RECOMP_FUNC void func_80028574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028574: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80028578: lwc1        $f6, 0xDC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XDC);
    // 0x8002857C: lwc1        $f10, 0x84($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80028580: lwc1        $f16, 0xA8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XA8);
    // 0x80028584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80028588: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002858C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80028590: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80028594: lwc1        $f18, 0xAC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XAC);
    // 0x80028598: lwc1        $f8, 0x88($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8002859C: lwc1        $f10, 0xE0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XE0);
    // 0x800285A0: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x800285A4: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800285A8: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800285AC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800285B0: jr          $ra
    // 0x800285B4: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800285B4: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
;}
