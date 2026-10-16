#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804222E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804222E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804222E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804222EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804222F0: jal         0x80045A34
    // 0x804222F4: addiu       $a1, $zero, 0x8A0
    ctx->r5 = ADD32(0, 0X8A0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804222F4: addiu       $a1, $zero, 0x8A0
    ctx->r5 = ADD32(0, 0X8A0);
    after_0:
    // 0x804222F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804222FC: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80422300: bne         $v0, $zero, L_80422310
    if (ctx->r2 != 0) {
        // 0x80422304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80422310;
    }
    // 0x80422304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80422308: b           L_80422314
    // 0x8042230C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80422314;
    // 0x8042230C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80422310:
    // 0x80422310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80422314:
    // 0x80422314: jr          $ra
    // 0x80422318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80422318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80035640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035644: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035648: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003564C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80035650: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80035654: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80035658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003565C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80035660: lwc1        $f4, 0x84($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X84);
    // 0x80035664: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x80035668: addiu       $t8, $t8, 0x53E8
    ctx->r24 = ADD32(ctx->r24, 0X53E8);
    // 0x8003566C: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x80035670: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x80035674: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x80035678: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003567C: jal         0x80035540
    // 0x80035680: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80035540(rdram, ctx);
        goto after_0;
    // 0x80035680: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80035684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035688: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003568C: jr          $ra
    // 0x80035690: nop

    return;
    // 0x80035690: nop

;}
RECOMP_FUNC void func_805538DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805538DC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805538E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805538E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805538E8: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4170) << 16);
    // 0x805538EC: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x805538F0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x805538F4: lwc1        $f4, 0x4C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4170));
    // 0x805538F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805538FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80553900: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x80553904: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x80553908: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x8055390C: jr          $ra
    // 0x80553910: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
    return;
    // 0x80553910: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_805C8904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C8908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C890C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8910: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8914: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x805C8918: jal         0x805C70B0
    // 0x805C891C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_805C70B0(rdram, ctx);
        goto after_0;
    // 0x805C891C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_0:
    // 0x805C8920: beq         $v0, $zero, L_805C8964
    if (ctx->r2 == 0) {
        // 0x805C8924: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_805C8964;
    }
    // 0x805C8924: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805C8928: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x805C892C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C8930: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X3908) << 16);
    // 0x805C8934: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805C8938: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x805C893C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8940: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x805C8944: lw          $a2, -0x6208($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(447, 0X3908));
    // 0x805C8948: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C894C: jal         0x805C74C8
    // 0x805C8950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C8950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805C8954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C895C: jal         0x805C9D10
    // 0x805C8960: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C8960: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
L_805C8964:
    // 0x805C8964: jal         0x805C6CA4
    // 0x805C8968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_3;
    // 0x805C8968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805C896C: jal         0x805C7844
    // 0x805C8970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_4;
    // 0x805C8970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805C8974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C8978: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C897C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C8980: jr          $ra
    // 0x805C8984: nop

    return;
    // 0x805C8984: nop

;}
RECOMP_FUNC void func_80451E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80451E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80451E6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80451E70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80451E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80451E78: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80451E7C: jal         0x8045111C
    // 0x80451E80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8045111C(rdram, ctx);
        goto after_0;
    // 0x80451E80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80451E84: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80451E88: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451E8C: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80451E90: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80451E94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80451E98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80451E9C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451EA0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80451EA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451EA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80451EAC: ori         $at, $at, 0x6E80
    ctx->r1 = ctx->r1 | 0X6E80;
    // 0x80451EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451EB4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80451EB8: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80451EBC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80451EC0: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80451EC4: bne         $t8, $zero, L_80451EE8
    if (ctx->r24 != 0) {
        // 0x80451EC8: nop
    
            goto L_80451EE8;
    }
    // 0x80451EC8: nop

    // 0x80451ECC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451ED0: ori         $at, $at, 0x6E80
    ctx->r1 = ctx->r1 | 0X6E80;
    // 0x80451ED4: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x80451ED8: jal         0x80451C7C
    // 0x80451EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80451C7C(rdram, ctx);
        goto after_1;
    // 0x80451EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80451EE0: b           L_80451EF0
    // 0x80451EE4: nop

        goto L_80451EF0;
    // 0x80451EE4: nop

L_80451EE8:
    // 0x80451EE8: jal         0x80451B1C
    // 0x80451EEC: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80451B1C(rdram, ctx);
        goto after_2;
    // 0x80451EEC: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_2:
L_80451EF0:
    // 0x80451EF0: jal         0x804507C4
    // 0x80451EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804507C4(rdram, ctx);
        goto after_3;
    // 0x80451EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80451EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80451EFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80451F00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80451F04: jr          $ra
    // 0x80451F08: nop

    return;
    // 0x80451F08: nop

;}
RECOMP_FUNC void func_8001AEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AEDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001AEE0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001AEE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001AEE8: beq         $a0, $zero, L_8001AEF8
    if (ctx->r4 == 0) {
        // 0x8001AEEC: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001AEF8;
    }
    // 0x8001AEEC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001AEF0: swc1        $f12, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f12.u32l;
    // 0x8001AEF4: sh          $a2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r6;
L_8001AEF8:
    // 0x8001AEF8: jr          $ra
    // 0x8001AEFC: nop

    return;
    // 0x8001AEFC: nop

;}
RECOMP_FUNC void func_80455060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80455068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045506C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455070: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80455074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80455078: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045507C: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x80455080: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80455084: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80455088: bne         $t6, $at, L_804550B4
    if (ctx->r14 != ctx->r1) {
        // 0x8045508C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804550B4;
    }
    // 0x8045508C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80455090: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80455094: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80455098: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8045509C: jal         0x8044EDC4
    // 0x804550A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x804550A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x804550A4: jal         0x80446D70
    // 0x804550A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x804550A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804550AC: b           L_804550C4
    // 0x804550B0: nop

        goto L_804550C4;
    // 0x804550B0: nop

L_804550B4:
    // 0x804550B4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804550B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804550BC: jal         0x80453744
    // 0x804550C0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_80453744(rdram, ctx);
        goto after_2;
    // 0x804550C0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_804550C4:
    // 0x804550C4: jal         0x80454664
    // 0x804550C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x804550C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804550CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804550D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804550D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804550D8: jr          $ra
    // 0x804550DC: nop

    return;
    // 0x804550DC: nop

;}
RECOMP_FUNC void func_80011C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011C64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011C68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80011C6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011C70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011C74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80011C78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011C7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011C80: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011C84: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80011C88: addiu       $s3, $zero, 0x15
    ctx->r19 = ADD32(0, 0X15);
    // 0x80011C8C: addiu       $s4, $zero, 0x77
    ctx->r20 = ADD32(0, 0X77);
L_80011C90:
    // 0x80011C90: beq         $s1, $s3, L_80011CB4
    if (ctx->r17 == ctx->r19) {
        // 0x80011C94: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80011CB4;
    }
    // 0x80011C94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80011C98: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
L_80011C9C:
    // 0x80011C9C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80011CA0: jal         0x80011990
    // 0x80011CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80011990(rdram, ctx);
        goto after_0;
    // 0x80011CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80011CA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80011CAC: bnel        $s0, $s2, L_80011C9C
    if (ctx->r16 != ctx->r18) {
        // 0x80011CB0: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_80011C9C;
    }
    goto skip_0;
    // 0x80011CB0: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    skip_0:
L_80011CB4:
    // 0x80011CB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011CB8: bne         $s1, $s4, L_80011C90
    if (ctx->r17 != ctx->r20) {
        // 0x80011CBC: nop
    
            goto L_80011C90;
    }
    // 0x80011CBC: nop

    // 0x80011CC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011CC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011CC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011CCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011CD0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011CD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011CD8: jr          $ra
    // 0x80011CDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80011CDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011CE0: nop

    // 0x80011CE4: nop

    // 0x80011CE8: nop

    // 0x80011CEC: nop

;}
RECOMP_FUNC void func_8066A074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A07C: jal         0x8004700C
    // 0x8066A080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8066A080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A084: beq         $v0, $zero, L_8066A0DC
    if (ctx->r2 == 0) {
        // 0x8066A088: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8066A0DC;
    }
    // 0x8066A088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A08C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8066A090: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8066A094: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8066A098: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8066A09C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8066A0A0: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(511, 0XD68) << 16);
    // 0x8066A0A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A0A8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8066A0AC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8066A0B0: nop

    // 0x8066A0B4: bc1fl       L_8066A0E0
    if (!c1cs) {
        // 0x8066A0B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A0E0;
    }
    goto skip_0;
    // 0x8066A0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A0BC: lwc1        $f10, -0x5518($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(511, 0XD68));
    // 0x8066A0C0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8066A0C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8066A0C8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8066A0CC: jal         0x8066A790
    // 0x8066A0D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066A790(rdram, ctx);
        goto after_1;
    // 0x8066A0D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8066A0D4: jal         0x80669DD4
    // 0x8066A0D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669DD4(rdram, ctx);
        goto after_2;
    // 0x8066A0D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8066A0DC:
    // 0x8066A0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A0E0:
    // 0x8066A0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A0E4: jr          $ra
    // 0x8066A0E8: nop

    return;
    // 0x8066A0E8: nop

;}
RECOMP_FUNC void func_806E8840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8840: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806E8844: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806E8848: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x806E884C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x806E8850: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x806E8854: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x806E8858: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x806E885C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x806E8860: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x806E8864: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806E8868: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E886C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806E8870: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E8874: lh          $v0, 0x5C8($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X5C8);
    // 0x806E8878: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806E887C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E8880: blez        $v0, L_806E8894
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806E8884: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_806E8894;
    }
    // 0x806E8884: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x806E8888: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806E888C: b           L_806E889C
    // 0x806E8890: sh          $t6, 0x5C8($s5)
    MEM_H(0X5C8, ctx->r21) = ctx->r14;
        goto L_806E889C;
    // 0x806E8890: sh          $t6, 0x5C8($s5)
    MEM_H(0X5C8, ctx->r21) = ctx->r14;
L_806E8894:
    // 0x806E8894: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x806E8898: sh          $t7, 0x5C8($s5)
    MEM_H(0X5C8, ctx->r21) = ctx->r15;
L_806E889C:
    // 0x806E889C: lwc1        $f4, 0x5CC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X5CC);
    // 0x806E88A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806E88A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806E88A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E88AC: swc1        $f8, 0x5CC($s5)
    MEM_W(0X5CC, ctx->r21) = ctx->f8.u32l;
    // 0x806E88B0: lwc1        $f0, 0x5CC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X5CC);
    // 0x806E88B4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x806E88B8: nop

    // 0x806E88BC: bc1fl       L_806E88D0
    if (!c1cs) {
        // 0x806E88C0: lh          $s2, 0x5C8($s5)
        ctx->r18 = MEM_H(ctx->r21, 0X5C8);
            goto L_806E88D0;
    }
    goto skip_0;
    // 0x806E88C0: lh          $s2, 0x5C8($s5)
    ctx->r18 = MEM_H(ctx->r21, 0X5C8);
    skip_0:
    // 0x806E88C4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806E88C8: swc1        $f10, 0x5CC($s5)
    MEM_W(0X5CC, ctx->r21) = ctx->f10.u32l;
    // 0x806E88CC: lh          $s2, 0x5C8($s5)
    ctx->r18 = MEM_H(ctx->r21, 0X5C8);
L_806E88D0:
    // 0x806E88D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806E88D4: addiu       $s4, $zero, 0x2E
    ctx->r20 = ADD32(0, 0X2E);
    // 0x806E88D8: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x806E88DC: addu        $s0, $s5, $s1
    ctx->r16 = ADD32(ctx->r21, ctx->r17);
    // 0x806E88E0: swc1        $f16, 0x458($s0)
    MEM_W(0X458, ctx->r16) = ctx->f16.u32l;
L_806E88E4:
    // 0x806E88E4: slti        $at, $s1, 0xB8
    ctx->r1 = SIGNED(ctx->r17) < 0XB8 ? 1 : 0;
    // 0x806E88E8: bne         $at, $zero, L_806E88F8
    if (ctx->r1 != 0) {
        // 0x806E88EC: nop
    
            goto L_806E88F8;
    }
    // 0x806E88EC: nop

    // 0x806E88F0: addiu       $s1, $s1, -0xB8
    ctx->r17 = ADD32(ctx->r17, -0XB8);
    // 0x806E88F4: addiu       $s0, $s0, -0xB8
    ctx->r16 = ADD32(ctx->r16, -0XB8);
L_806E88F8:
    // 0x806E88F8: jal         0x80066DE4
    // 0x806E88FC: lwc1        $f12, 0x5CC($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X5CC);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806E88FC: lwc1        $f12, 0x5CC($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X5CC);
    after_0:
    // 0x806E8900: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x806E8904: lwc1        $f18, 0x458($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X458);
    // 0x806E8908: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x806E890C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806E8910: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E8914: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806E8918: bne         $s3, $s4, L_806E88E4
    if (ctx->r19 != ctx->r20) {
        // 0x806E891C: swc1        $f6, 0x454($s0)
        MEM_W(0X454, ctx->r16) = ctx->f6.u32l;
            goto L_806E88E4;
    }
    // 0x806E891C: swc1        $f6, 0x454($s0)
    MEM_W(0X454, ctx->r16) = ctx->f6.u32l;
    // 0x806E8920: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16B4) << 16);
    // 0x806E8924: lwc1        $f22, -0x669C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16B4));
    // 0x806E8928: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16B8) << 16);
    // 0x806E892C: lwc1        $f20, -0x6698($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16B8));
    // 0x806E8930: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806E8934: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_806E8938:
    // 0x806E8938: jal         0x806E83E0
    // 0x806E893C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_806E83E0(rdram, ctx);
        goto after_1;
    // 0x806E893C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x806E8940: lwc1        $f8, 0x510($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X510);
    // 0x806E8944: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806E8948: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E894C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x806E8950: nop

    // 0x806E8954: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x806E8958: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806E895C: bne         $s2, $s4, L_806E8938
    if (ctx->r18 != ctx->r20) {
        // 0x806E8960: swc1        $f18, 0x50C($s0)
        MEM_W(0X50C, ctx->r16) = ctx->f18.u32l;
            goto L_806E8938;
    }
    // 0x806E8960: swc1        $f18, 0x50C($s0)
    MEM_W(0X50C, ctx->r16) = ctx->f18.u32l;
    // 0x806E8964: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x806E8968: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806E896C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x806E8970: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x806E8974: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x806E8978: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x806E897C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x806E8980: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x806E8984: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x806E8988: jr          $ra
    // 0x806E898C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806E898C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80424A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424A1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80424A20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80424A24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80424A28: jal         0x804249A0
    // 0x80424A2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804249A0(rdram, ctx);
        goto after_0;
    // 0x80424A2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80424A30: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424A34: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X3408) << 16);
    // 0x80424A38: lui         $a2, 0x8042
    ctx->r6 = S32(RELOC_HI16(35, 0X333C) << 16);
    // 0x80424A3C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80424A40: lw          $a3, 0xE4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE4);
    // 0x80424A44: addiu       $a2, $a2, 0x5D3C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(35, 0X333C));
    // 0x80424A48: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80424A4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80424A50: addiu       $a1, $a1, 0x5E08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X3408));
    // 0x80424A54: jal         0x80424824
    // 0x80424A58: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80424A58: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    after_1:
    // 0x80424A5C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80424A64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80424A68: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36D4) << 16);
    // 0x80424A6C: lwc1        $f6, 0x60D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36D4));
    // 0x80424A70: lwc1        $f4, 0xE4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424A7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80424A80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80424A84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424A88: swc1        $f8, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f8.u32l;
    // 0x80424A8C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424A90: lwc1        $f10, 0xE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424A94: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80424A98: nop

    // 0x80424A9C: bc1fl       L_80424AB0
    if (!c1cs) {
        // 0x80424AA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80424AB0;
    }
    goto skip_0;
    // 0x80424AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80424AA4: jal         0x80424E54
    // 0x80424AA8: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    func_80424E54(rdram, ctx);
        goto after_2;
    // 0x80424AA8: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x80424AAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80424AB0:
    // 0x80424AB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80424AB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424AB8: jr          $ra
    // 0x80424ABC: nop

    return;
    // 0x80424ABC: nop

;}
RECOMP_FUNC void func_8001DFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DFE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DFE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DFEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001DFF0: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8001DFF4: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001DFF8: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001DFFC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8001E000: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001E004: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001E008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E00C: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    // 0x8001E010: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001E014: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8001E018: jal         0x8002FABC
    // 0x8001E01C: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    func_8002FABC(rdram, ctx);
        goto after_0;
    // 0x8001E01C: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    after_0:
    // 0x8001E020: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8001E024: lbu         $t8, -0x764C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X764C);
    // 0x8001E028: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001E02C: beq         $t8, $zero, L_8001E054
    if (ctx->r24 == 0) {
        // 0x8001E030: nop
    
            goto L_8001E054;
    }
    // 0x8001E030: nop

    // 0x8001E034: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x8001E038: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E03C: bnel        $t9, $at, L_8001E084
    if (ctx->r25 != ctx->r1) {
        // 0x8001E040: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E084;
    }
    goto skip_0;
    // 0x8001E040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001E044: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x8001E048: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001E04C: bnel        $t0, $at, L_8001E084
    if (ctx->r8 != ctx->r1) {
        // 0x8001E050: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E084;
    }
    goto skip_1;
    // 0x8001E050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8001E054:
    // 0x8001E054: jal         0x8003E478
    // 0x8001E058: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003E478(rdram, ctx);
        goto after_1;
    // 0x8001E058: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8001E05C: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8001E060: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001E064: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x8001E068: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001E06C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001E070: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x8001E074: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001E078: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8001E07C: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x8001E080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E084:
    // 0x8001E084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E08C: jr          $ra
    // 0x8001E090: nop

    return;
    // 0x8001E090: nop

;}
RECOMP_FUNC void func_806CEA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEA58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CEA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CEA60: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x806CEA64: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x806CEA68: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
    // 0x806CEA6C: beql        $t6, $zero, L_806CEAD8
    if (ctx->r14 == 0) {
        // 0x806CEA70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806CEAD8;
    }
    goto skip_0;
    // 0x806CEA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806CEA74: beq         $v0, $zero, L_806CEAD4
    if (ctx->r2 == 0) {
        // 0x806CEA78: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_806CEAD4;
    }
    // 0x806CEA78: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806CEA7C: bnel        $v1, $at, L_806CEAC0
    if (ctx->r3 != ctx->r1) {
        // 0x806CEA80: lbu         $t7, 0x18($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X18);
            goto L_806CEAC0;
    }
    goto skip_1;
    // 0x806CEA80: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    skip_1:
    // 0x806CEA84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CEA88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CEA8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806CEA90: jal         0x806CE828
    // 0x806CEA94: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806CE828(rdram, ctx);
        goto after_0;
    // 0x806CEA94: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x806CEA98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CEA9C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806CEAA0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806CEAA4: beq         $v0, $zero, L_806CEAD4
    if (ctx->r2 == 0) {
        // 0x806CEAA8: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_806CEAD4;
    }
    // 0x806CEAA8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806CEAAC: jal         0x806CE938
    // 0x806CEAB0: nop

    func_806CE938(rdram, ctx);
        goto after_1;
    // 0x806CEAB0: nop

    after_1:
    // 0x806CEAB4: b           L_806CEAD8
    // 0x806CEAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806CEAD8;
    // 0x806CEAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CEABC: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
L_806CEAC0:
    // 0x806CEAC0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806CEAC4: bnel        $t7, $at, L_806CEAD8
    if (ctx->r15 != ctx->r1) {
        // 0x806CEAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806CEAD8;
    }
    goto skip_2;
    // 0x806CEAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806CEACC: jal         0x806CE938
    // 0x806CEAD0: nop

    func_806CE938(rdram, ctx);
        goto after_2;
    // 0x806CEAD0: nop

    after_2:
L_806CEAD4:
    // 0x806CEAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806CEAD8:
    // 0x806CEAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CEADC: jr          $ra
    // 0x806CEAE0: nop

    return;
    // 0x806CEAE0: nop

;}
RECOMP_FUNC void func_804CE798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CE79C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE7A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804CE7A4: jal         0x804CE408
    // 0x804CE7A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804CE408(rdram, ctx);
        goto after_0;
    // 0x804CE7A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CE7AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804CE7B0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804CE7B4: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(240, 0X19B8) << 16);
    // 0x804CE7B8: addiu       $a2, $a0, 0xC4
    ctx->r6 = ADD32(ctx->r4, 0XC4);
    // 0x804CE7BC: sw          $v0, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->r2;
    // 0x804CE7C0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CE7C4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x804CE7C8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x804CE7CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CE7D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CE7D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CE7D8: lw          $t8, -0x398($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(240, 0X19B8));
    // 0x804CE7DC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x804CE7E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CE7E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x804CE7E8: jal         0x80048490
    // 0x804CE7EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_1;
    // 0x804CE7EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x804CE7F0: jal         0x80048378
    // 0x804CE7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x804CE7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804CE7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE7FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CE800: jr          $ra
    // 0x804CE804: nop

    return;
    // 0x804CE804: nop

;}
RECOMP_FUNC void func_80670AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670AA8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80670AAC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80670AB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80670AB4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80670AB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80670ABC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80670AC0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80670AC4: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(523, 0XA8) << 16);
    // 0x80670AC8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80670ACC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80670AD0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80670AD4: lw          $t1, 0xAE8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(523, 0XA8));
    // 0x80670AD8: jr          $ra
    // 0x80670ADC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80670ADC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8006C4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006C4D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C4D8: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8006C4DC: lw          $a3, 0x44($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X44);
    // 0x8006C4E0: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8006C4E4: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006C4E8: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006C4EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006C4F0: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8006C4F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006C4F8: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8006C4FC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8006C500: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8006C504: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8006C508: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8006C50C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006C510: jal         0x8006C258
    // 0x8006C514: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_8006C258(rdram, ctx);
        goto after_0;
    // 0x8006C514: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8006C518: jal         0x8006C3C4
    // 0x8006C51C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8006C3C4(rdram, ctx);
        goto after_1;
    // 0x8006C51C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8006C520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C524: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006C528: jr          $ra
    // 0x8006C52C: nop

    return;
    // 0x8006C52C: nop

;}
RECOMP_FUNC void func_800073BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800073C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800073C4: jal         0x8000744C
    // 0x800073C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8000744C(rdram, ctx);
        goto after_0;
    // 0x800073C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800073CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800073D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800073D4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x800073D8: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800073DC: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x800073E0: bnel        $t7, $zero, L_800073F0
    if (ctx->r15 != 0) {
        // 0x800073E4: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800073F0;
    }
    goto skip_0;
    // 0x800073E4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_0:
    // 0x800073E8: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x800073EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800073F0:
    // 0x800073F0: jr          $ra
    // 0x800073F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800073F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8073F3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F3B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F3B8: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(748, 0X223C) << 16);
    // 0x8073F3BC: addiu       $a1, $a1, 0xA2C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X223C));
    // 0x8073F3C0: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x8073F3C4: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x8073F3C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8073F3CC: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8073F3D0: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8073F3D4: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8073F3D8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8073F3DC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8073F3E0: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8073F3E4: bne         $at, $zero, L_8073F404
    if (ctx->r1 != 0) {
        // 0x8073F3E8: slti        $at, $t2, 0x11
        ctx->r1 = SIGNED(ctx->r10) < 0X11 ? 1 : 0;
            goto L_8073F404;
    }
    // 0x8073F3E8: slti        $at, $t2, 0x11
    ctx->r1 = SIGNED(ctx->r10) < 0X11 ? 1 : 0;
    // 0x8073F3EC: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8073F3F0: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x8073F3F4: bne         $at, $zero, L_8073F404
    if (ctx->r1 != 0) {
        // 0x8073F3F8: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_8073F404;
    }
    // 0x8073F3F8: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8073F3FC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8073F400: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8073F404:
    // 0x8073F404: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x8073F408: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8073F40C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8073F410: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(748, 0X18F0) << 16);
    // 0x8073F414: addiu       $t7, $t7, 0xE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(748, 0X18F0));
    // 0x8073F418: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8073F41C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8073F420: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8073F424: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8073F428: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8073F42C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8073F430: jr          $ra
    // 0x8073F434: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    return;
    // 0x8073F434: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80446A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446A6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446A70: addiu       $t6, $zero, 0x744
    ctx->r14 = ADD32(0, 0X744);
    // 0x80446A74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446A78: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446A7C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80446A80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446A84: jr          $ra
    // 0x80446A88: sw          $t7, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r15;
    return;
    // 0x80446A88: sw          $t7, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80536474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536474: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536478: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053647C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536480: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536484: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536488: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053648C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536490: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536494: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536498: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053649C: jr          $ra
    // 0x805364A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805364A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800334EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800334EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800334F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800334F4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800334F8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800334FC: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x80033500: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80033504: beq         $t7, $zero, L_8003358C
    if (ctx->r15 == 0) {
        // 0x80033508: nop
    
            goto L_8003358C;
    }
    // 0x80033508: nop

    // 0x8003350C: lwc1        $f4, -0x7674($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7674);
    // 0x80033510: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80033514: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033518: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8003351C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80033520: nop

    // 0x80033524: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80033528: jal         0x80032F9C
    // 0x8003352C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80032F9C(rdram, ctx);
        goto after_0;
    // 0x8003352C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80033530: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80033534: beq         $v0, $zero, L_8003359C
    if (ctx->r2 == 0) {
        // 0x80033538: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003359C;
    }
    // 0x80033538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003353C: lw          $t9, 0x198($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X198);
    // 0x80033540: sltiu       $at, $t9, 0x28
    ctx->r1 = ctx->r25 < 0X28 ? 1 : 0;
    // 0x80033544: bne         $at, $zero, L_80033574
    if (ctx->r1 != 0) {
        // 0x80033548: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80033574;
    }
    // 0x80033548: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8003354C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033550: lwc1        $f10, 0x194($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X194);
    // 0x80033554: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80033558: nop

    // 0x8003355C: bc1f        L_80033574
    if (!c1cs) {
        // 0x80033560: nop
    
            goto L_80033574;
    }
    // 0x80033560: nop

    // 0x80033564: jal         0x8002DA50
    // 0x80033568: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8002DA50(rdram, ctx);
        goto after_1;
    // 0x80033568: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8003356C: b           L_80033580
    // 0x80033570: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80033580;
    // 0x80033570: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80033574:
    // 0x80033574: jal         0x8002D9A8
    // 0x80033578: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8002D9A8(rdram, ctx);
        goto after_2;
    // 0x80033578: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8003357C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80033580:
    // 0x80033580: sb          $zero, 0xDC($v1)
    MEM_B(0XDC, ctx->r3) = 0;
    // 0x80033584: b           L_800335A0
    // 0x80033588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800335A0;
    // 0x80033588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003358C:
    // 0x8003358C: jal         0x8002D9A8
    // 0x80033590: nop

    func_8002D9A8(rdram, ctx);
        goto after_3;
    // 0x80033590: nop

    after_3:
    // 0x80033594: b           L_800335A0
    // 0x80033598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800335A0;
    // 0x80033598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003359C:
    // 0x8003359C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800335A0:
    // 0x800335A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800335A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800335A8: jr          $ra
    // 0x800335AC: nop

    return;
    // 0x800335AC: nop

;}
RECOMP_FUNC void func_80425474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80425478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042547C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80425480: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80425484: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80425488: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X2D48) << 16);
    // 0x8042548C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80425490: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80425494: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80425498: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042549C: lw          $t8, 0x5748($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X2D48));
    // 0x804254A0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804254A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804254A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804254AC: jal         0x80048490
    // 0x804254B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804254B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804254B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804254B8: jal         0x80048378
    // 0x804254BC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804254BC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804254C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804254C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804254C8: jr          $ra
    // 0x804254CC: nop

    return;
    // 0x804254CC: nop

;}
RECOMP_FUNC void func_80681F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80681F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80681F70: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80681F74: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X2210) << 16);
    // 0x80681F78: addiu       $t8, $t8, 0x2620
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(550, 0X2210));
    // 0x80681F7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80681F80: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80681F84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80681F88: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80681F8C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80681F90: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80681F94: beql        $v1, $zero, L_80681FB4
    if (ctx->r3 == 0) {
        // 0x80681F98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80681FB4;
    }
    goto skip_0;
    // 0x80681F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80681F9C: jalr        $v1
    // 0x80681FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80681FA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80681FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80681FA8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80681FAC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80681FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80681FB4:
    // 0x80681FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80681FB8: jr          $ra
    // 0x80681FBC: nop

    return;
    // 0x80681FBC: nop

;}
RECOMP_FUNC void func_80799430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80799434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8079943C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80799440: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80799444: jal         0x800447C8
    // 0x80799448: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80799448: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8079944C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80799450: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80799454: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80799458: sw          $t7, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r15;
    // 0x8079945C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80799460: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80799464: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80799468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079946C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80799470: jr          $ra
    // 0x80799474: nop

    return;
    // 0x80799474: nop

;}
RECOMP_FUNC void func_8042FEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FEDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042FEE0: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3820) << 16);
    // 0x8042FEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FEE8: addiu       $t6, $t6, 0x1900
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3820));
    // 0x8042FEEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8042FEF0: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8042FEF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8042FEF8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8042FEFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8042FF00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042FF04: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8042FF08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042FF0C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8042FF10: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8042FF14: jalr        $t9
    // 0x8042FF18: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042FF18: nop

    after_0:
    // 0x8042FF1C: jal         0x8042F6B4
    // 0x8042FF20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8042F6B4(rdram, ctx);
        goto after_1;
    // 0x8042FF20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8042FF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FF28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042FF2C: jr          $ra
    // 0x8042FF30: nop

    return;
    // 0x8042FF30: nop

;}
RECOMP_FUNC void func_807AF260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF260: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x807AF264: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x807AF268: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x807AF26C: addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // 0x807AF270: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x807AF274: beql        $v0, $zero, L_807AF2B0
    if (ctx->r2 == 0) {
        // 0x807AF278: lwc1        $f4, 0x6C($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
            goto L_807AF2B0;
    }
    goto skip_0;
    // 0x807AF278: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x807AF27C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x807AF280: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807AF284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AF288: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x807AF28C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x807AF290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AF294: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807AF298: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x807AF29C: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x807AF2A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807AF2A4: b           L_807AF2D0
    // 0x807AF2A8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
        goto L_807AF2D0;
    // 0x807AF2A8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x807AF2AC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
L_807AF2B0:
    // 0x807AF2B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AF2B4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x807AF2B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AF2BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807AF2C0: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807AF2C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807AF2C8: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x807AF2CC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_807AF2D0:
    // 0x807AF2D0: jr          $ra
    // 0x807AF2D4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    return;
    // 0x807AF2D4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
;}
RECOMP_FUNC void Math_FNearbyIntF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081D50: jal         0x80082088
    // 0x80081D54: nop

    nearbyintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80081D54: nop

    after_0:
    // 0x80081D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081D60: jr          $ra
    // 0x80081D64: nop

    return;
    // 0x80081D64: nop

;}
RECOMP_FUNC void func_8046D058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D060: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8046D064: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8046D068: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046D06C: jal         0x80048F84
    // 0x8046D070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046D070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046D074: jal         0x8046C850
    // 0x8046D078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046D078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046D07C: beq         $v0, $zero, L_8046D0A0
    if (ctx->r2 == 0) {
        // 0x8046D080: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8046D0A0;
    }
    // 0x8046D080: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046D084: lw          $t6, 0x138($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X138);
    // 0x8046D088: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046D08C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D090: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8046D094: sw          $t7, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r15;
    // 0x8046D098: jal         0x8046D3E8
    // 0x8046D09C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046D09C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_2:
L_8046D0A0:
    // 0x8046D0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D0A8: jr          $ra
    // 0x8046D0AC: nop

    return;
    // 0x8046D0AC: nop

;}
RECOMP_FUNC void func_8006CC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC2C: jal         0x8004700C
    // 0x8006CC30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8006CC30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006CC34: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8006CC38: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x8006CC3C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8006CC40: bnel        $t6, $zero, L_8006CC80
    if (ctx->r14 != 0) {
        // 0x8006CC44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006CC80;
    }
    goto skip_0;
    // 0x8006CC44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006CC48: beq         $v0, $zero, L_8006CC7C
    if (ctx->r2 == 0) {
        // 0x8006CC4C: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8006CC7C;
    }
    // 0x8006CC4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006CC50: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8006CC54: lwc1        $f4, 0x1080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1080);
    // 0x8006CC58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006CC5C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8006CC60: nop

    // 0x8006CC64: bc1fl       L_8006CC80
    if (!c1cs) {
        // 0x8006CC68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006CC80;
    }
    goto skip_1;
    // 0x8006CC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006CC6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006CC70: nop

    // 0x8006CC74: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006CC78: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
L_8006CC7C:
    // 0x8006CC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006CC80:
    // 0x8006CC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC84: jr          $ra
    // 0x8006CC88: nop

    return;
    // 0x8006CC88: nop

;}
RECOMP_FUNC void func_80532BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532C04: jal         0x80532B10
    // 0x80532C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80532B10(rdram, ctx);
        goto after_0;
    // 0x80532C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80532C0C: jal         0x80045BD8
    // 0x80532C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80532C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80532C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532C1C: jr          $ra
    // 0x80532C20: nop

    return;
    // 0x80532C20: nop

;}
RECOMP_FUNC void func_8044BB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB1C: jr          $ra
    // 0x8044BB20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_806F008C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F0090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F0094: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F0098: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F009C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F00A0: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(676, 0X4BD4) << 16);
    // 0x806F00A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F00A8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F00AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F00B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F00B4: lw          $t8, 0xB24($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(676, 0X4BD4));
    // 0x806F00B8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F00BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F00C0: jal         0x80048490
    // 0x806F00C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F00C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F00C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F00CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F00D0: jr          $ra
    // 0x806F00D4: nop

    return;
    // 0x806F00D4: nop

;}
RECOMP_FUNC void func_805ACDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACDD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805ACDDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ACDE0: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x805ACDE4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805ACDE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805ACDEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ACDF0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x805ACDF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACDF8: bc1fl       L_805ACE14
    if (!c1cs) {
        // 0x805ACDFC: addiu       $a0, $a3, 0xC4
        ctx->r4 = ADD32(ctx->r7, 0XC4);
            goto L_805ACE14;
    }
    goto skip_0;
    // 0x805ACDFC: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    skip_0:
    // 0x805ACE00: lbu         $a2, 0x20($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X20);
    // 0x805ACE04: jal         0x805AD274
    // 0x805ACE08: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_805AD274(rdram, ctx);
        goto after_0;
    // 0x805ACE08: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x805ACE0C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805ACE10: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
L_805ACE14:
    // 0x805ACE14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACE18: jal         0x80048F84
    // 0x805ACE1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805ACE1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x805ACE20: jal         0x805AC528
    // 0x805ACE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AC528(rdram, ctx);
        goto after_2;
    // 0x805ACE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805ACE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805ACE2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805ACE30: jr          $ra
    // 0x805ACE34: nop

    return;
    // 0x805ACE34: nop

;}
RECOMP_FUNC void func_80020844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002084C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80020850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020858: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8002085C: jal         0x80049C70
    // 0x80020860: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80049C70(rdram, ctx);
        goto after_0;
    // 0x80020860: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80020864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80020868: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8002086C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80020870: jal         0x80049C70
    // 0x80020874: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_1;
    // 0x80020874: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80020878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002087C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020880: jr          $ra
    // 0x80020884: nop

    return;
    // 0x80020884: nop

;}
RECOMP_FUNC void func_8045332C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045332C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453334: jal         0x804531D0
    // 0x80453338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x80453338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045333C: beql        $v0, $zero, L_80453350
    if (ctx->r2 == 0) {
        // 0x80453340: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80453350;
    }
    goto skip_0;
    // 0x80453340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80453344: jal         0x804528E8
    // 0x80453348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804528E8(rdram, ctx);
        goto after_1;
    // 0x80453348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045334C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453350:
    // 0x80453350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453354: jr          $ra
    // 0x80453358: nop

    return;
    // 0x80453358: nop

;}
RECOMP_FUNC void func_80067A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067A80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067A84: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80067A88: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80067A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067A90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80067A94: jal         0x80018EBC
    // 0x80067A98: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80018EBC(rdram, ctx);
        goto after_0;
    // 0x80067A98: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80067A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067AA4: jr          $ra
    // 0x80067AA8: nop

    return;
    // 0x80067AA8: nop

;}
RECOMP_FUNC void func_804345A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804345A8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x804345AC: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x804345B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804345B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804345B8: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x804345BC: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x804345C0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x804345C4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x804345C8: jal         0x80434568
    // 0x804345CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80434568(rdram, ctx);
        goto after_0;
    // 0x804345CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804345D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804345D4: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(71, 0X292C) << 16);
    // 0x804345D8: addiu       $t7, $t7, 0x63DC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(71, 0X292C));
    // 0x804345DC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804345E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804345E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804345E8: bne         $t6, $zero, L_80434600
    if (ctx->r14 != 0) {
        // 0x804345EC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80434600;
    }
    // 0x804345EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804345F0: jal         0x800445A4
    // 0x804345F4: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804345F4: nop

    after_1:
    // 0x804345F8: b           L_80434628
    // 0x804345FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80434628;
    // 0x804345FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80434600:
    // 0x80434600: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80434604: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80434608: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043460C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80434610: jal         0x80434634
    // 0x80434614: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_80434634(rdram, ctx);
        goto after_2;
    // 0x80434614: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x80434618: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043461C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80434620: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80434624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80434628:
    // 0x80434628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043462C: jr          $ra
    // 0x80434630: nop

    return;
    // 0x80434630: nop

;}
RECOMP_FUNC void func_80069030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069038: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x8006903C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80069040: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80069044: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80069048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006904C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069050: addiu       $t1, $t1, -0x5508
    ctx->r9 = ADD32(ctx->r9, -0X5508);
    // 0x80069054: addiu       $t4, $t4, -0x54E0
    ctx->r12 = ADD32(ctx->r12, -0X54E0);
    // 0x80069058: addiu       $t0, $t0, -0x54E4
    ctx->r8 = ADD32(ctx->r8, -0X54E4);
    // 0x8006905C: addiu       $a3, $a3, -0x6A58
    ctx->r7 = ADD32(ctx->r7, -0X6A58);
    // 0x80069060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80069064: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80069068: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8006906C: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
L_80069070:
    // 0x80069070: beql        $s0, $zero, L_80069084
    if (ctx->r16 == 0) {
        // 0x80069074: addu        $v0, $t1, $a1
        ctx->r2 = ADD32(ctx->r9, ctx->r5);
            goto L_80069084;
    }
    goto skip_0;
    // 0x80069074: addu        $v0, $t1, $a1
    ctx->r2 = ADD32(ctx->r9, ctx->r5);
    skip_0:
    // 0x80069078: b           L_800690E8
    // 0x8006907C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
        goto L_800690E8;
    // 0x8006907C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80069080: addu        $v0, $t1, $a1
    ctx->r2 = ADD32(ctx->r9, ctx->r5);
L_80069084:
    // 0x80069084: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80069088: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006908C: addiu       $t6, $t6, -0x6A5C
    ctx->r14 = ADD32(ctx->r14, -0X6A5C);
    // 0x80069090: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80069094: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80069098: bne         $at, $zero, L_800690A8
    if (ctx->r1 != 0) {
        // 0x8006909C: addu        $a2, $t4, $a1
        ctx->r6 = ADD32(ctx->r12, ctx->r5);
            goto L_800690A8;
    }
    // 0x8006909C: addu        $a2, $t4, $a1
    ctx->r6 = ADD32(ctx->r12, ctx->r5);
    // 0x800690A0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x800690A4: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
L_800690A8:
    // 0x800690A8: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800690AC: slti        $at, $t7, 0x65
    ctx->r1 = SIGNED(ctx->r15) < 0X65 ? 1 : 0;
    // 0x800690B0: bnel        $at, $zero, L_800690C0
    if (ctx->r1 != 0) {
        // 0x800690B4: lbu         $t8, 0x0($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X0);
            goto L_800690C0;
    }
    goto skip_1;
    // 0x800690B4: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800690B8: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x800690BC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
L_800690C0:
    // 0x800690C0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800690C4: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x800690C8: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800690CC: bne         $at, $zero, L_800690E4
    if (ctx->r1 != 0) {
        // 0x800690D0: sb          $t9, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r25;
            goto L_800690E4;
    }
    // 0x800690D0: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800690D4: addiu       $t6, $v0, -0x64
    ctx->r14 = ADD32(ctx->r2, -0X64);
    // 0x800690D8: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800690DC: b           L_800690E8
    // 0x800690E0: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
        goto L_800690E8;
    // 0x800690E0: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
L_800690E4:
    // 0x800690E4: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_800690E8:
    // 0x800690E8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800690EC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800690F0: blez        $v0, L_80069100
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800690F4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80069100;
    }
    // 0x800690F4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800690F8: b           L_80069128
    // 0x800690FC: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
        goto L_80069128;
    // 0x800690FC: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
L_80069100:
    // 0x80069100: addu        $t8, $t4, $a1
    ctx->r24 = ADD32(ctx->r12, ctx->r5);
    // 0x80069104: addu        $v0, $t1, $a1
    ctx->r2 = ADD32(ctx->r9, ctx->r5);
    // 0x80069108: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8006910C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80069110: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80069114: beq         $at, $zero, L_80069124
    if (ctx->r1 == 0) {
        // 0x80069118: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_80069124;
    }
    // 0x80069118: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x8006911C: b           L_80069128
    // 0x80069120: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
        goto L_80069128;
    // 0x80069120: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80069124:
    // 0x80069124: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80069128:
    // 0x80069128: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006912C: bne         $a1, $t3, L_80069070
    if (ctx->r5 != ctx->r11) {
        // 0x80069130: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80069070;
    }
    // 0x80069130: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80069134: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80069138: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006913C: addiu       $a1, $a1, -0x6A58
    ctx->r5 = ADD32(ctx->r5, -0X6A58);
    // 0x80069140: jal         0x800748D8
    // 0x80069144: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    func_800748D8(rdram, ctx);
        goto after_0;
    // 0x80069144: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    after_0:
    // 0x80069148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006914C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069154: jr          $ra
    // 0x80069158: nop

    return;
    // 0x80069158: nop

;}
RECOMP_FUNC void func_8047091C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047091C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80470920: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80470924: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80470928: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8047092C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80470930: jal         0x80470104
    // 0x80470934: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80470104(rdram, ctx);
        goto after_0;
    // 0x80470934: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80470938: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8047093C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80470940: lbu         $v1, 0x114C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X114C);
    // 0x80470944: beql        $v1, $zero, L_80470960
    if (ctx->r3 == 0) {
        // 0x80470948: lw          $t6, 0x1E0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1E0);
            goto L_80470960;
    }
    goto skip_0;
    // 0x80470948: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x8047094C: beql        $v1, $at, L_80470978
    if (ctx->r3 == ctx->r1) {
        // 0x80470950: lw          $t7, 0x1E0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1E0);
            goto L_80470978;
    }
    goto skip_1;
    // 0x80470950: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    skip_1:
    // 0x80470954: b           L_8047098C
    // 0x80470958: nop

        goto L_8047098C;
    // 0x80470958: nop

    // 0x8047095C: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
L_80470960:
    // 0x80470960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80470964: jal         0x80470718
    // 0x80470968: sw          $t6, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->r14;
    func_80470718(rdram, ctx);
        goto after_1;
    // 0x80470968: sw          $t6, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->r14;
    after_1:
    // 0x8047096C: b           L_8047098C
    // 0x80470970: nop

        goto L_8047098C;
    // 0x80470970: nop

    // 0x80470974: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
L_80470978:
    // 0x80470978: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8047097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80470980: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80470984: jal         0x80470718
    // 0x80470988: sw          $t9, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->r25;
    func_80470718(rdram, ctx);
        goto after_2;
    // 0x80470988: sw          $t9, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->r25;
    after_2:
L_8047098C:
    // 0x8047098C: jal         0x8046FC20
    // 0x80470990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046FC20(rdram, ctx);
        goto after_3;
    // 0x80470990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80470994: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80470998: slti        $at, $v0, 0x97
    ctx->r1 = SIGNED(ctx->r2) < 0X97 ? 1 : 0;
    // 0x8047099C: bnel        $at, $zero, L_804709BC
    if (ctx->r1 != 0) {
        // 0x804709A0: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_804709BC;
    }
    goto skip_2;
    // 0x804709A0: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x804709A4: jal         0x80056484
    // 0x804709A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80056484(rdram, ctx);
        goto after_4;
    // 0x804709A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804709AC: jal         0x80044658
    // 0x804709B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_5;
    // 0x804709B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804709B4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x804709B8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
L_804709BC:
    // 0x804709BC: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x804709C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804709C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804709C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804709CC: jr          $ra
    // 0x804709D0: nop

    return;
    // 0x804709D0: nop

;}
RECOMP_FUNC void func_805533D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805533D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805533DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805533E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805533E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805533E8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805533EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805533F0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805533F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805533F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x805533FC: jal         0x80047AB8
    // 0x80553400: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80553400: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80553404: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80553408: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8055340C: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x80553410: lhu         $v1, 0x30($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X30);
    // 0x80553414: beq         $v1, $zero, L_805534CC
    if (ctx->r3 == 0) {
        // 0x80553418: nop
    
            goto L_805534CC;
    }
    // 0x80553418: nop

    // 0x8055341C: beq         $v1, $at, L_805534CC
    if (ctx->r3 == ctx->r1) {
        // 0x80553420: nop
    
            goto L_805534CC;
    }
    // 0x80553420: nop

    // 0x80553424: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x80553428: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8055342C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80553430: beq         $v1, $at, L_805534CC
    if (ctx->r3 == ctx->r1) {
        // 0x80553434: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_805534CC;
    }
    // 0x80553434: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80553438: beq         $v1, $at, L_805534CC
    if (ctx->r3 == ctx->r1) {
        // 0x8055343C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805534CC;
    }
    // 0x8055343C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553440: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80553444: addiu       $a2, $v0, 0x30
    ctx->r6 = ADD32(ctx->r2, 0X30);
    // 0x80553448: jal         0x8004D038
    // 0x8055344C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8004D038(rdram, ctx);
        goto after_1;
    // 0x8055344C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80553450: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80553454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553458: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8055345C: lbu         $t0, 0x44($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X44);
    // 0x80553460: beql        $t0, $zero, L_805534C4
    if (ctx->r8 == 0) {
        // 0x80553464: lw          $t5, 0x8($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X8);
            goto L_805534C4;
    }
    goto skip_0;
    // 0x80553464: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x80553468: jal         0x8004D3C4
    // 0x8055346C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D3C4(rdram, ctx);
        goto after_2;
    // 0x8055346C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80553470: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80553474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553478: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8055347C: jal         0x8004A97C
    // 0x80553480: lhu         $a0, 0x30($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X30);
    func_8004A97C(rdram, ctx);
        goto after_3;
    // 0x80553480: lhu         $a0, 0x30($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X30);
    after_3:
    // 0x80553484: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80553488: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8055348C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80553490: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80553494: nop

    // 0x80553498: bc1fl       L_805534B4
    if (!c1cs) {
        // 0x8055349C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805534B4;
    }
    goto skip_1;
    // 0x8055349C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x805534A0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805534A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805534A8: b           L_805534C0
    // 0x805534AC: swc1        $f6, 0xD60($t3)
    MEM_W(0XD60, ctx->r11) = ctx->f6.u32l;
        goto L_805534C0;
    // 0x805534AC: swc1        $f6, 0xD60($t3)
    MEM_W(0XD60, ctx->r11) = ctx->f6.u32l;
    // 0x805534B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805534B4:
    // 0x805534B4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x805534B8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x805534BC: swc1        $f10, 0xD60($t4)
    MEM_W(0XD60, ctx->r12) = ctx->f10.u32l;
L_805534C0:
    // 0x805534C0: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
L_805534C4:
    // 0x805534C4: ori         $t6, $t5, 0xF0
    ctx->r14 = ctx->r13 | 0XF0;
    // 0x805534C8: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
L_805534CC:
    // 0x805534CC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805534D0: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x805534D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805534D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805534DC: jal         0x8004D150
    // 0x805534E0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x805534E0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_4:
    // 0x805534E4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x805534E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805534EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805534F0: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x805534F4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805534F8: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x805534FC: beql        $t9, $zero, L_80553530
    if (ctx->r25 == 0) {
        // 0x80553500: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80553530;
    }
    goto skip_2;
    // 0x80553500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80553504: jal         0x8004D618
    // 0x80553508: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    func_8004D618(rdram, ctx);
        goto after_5;
    // 0x80553508: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    after_5:
    // 0x8055350C: jal         0x805538A4
    // 0x80553510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805538A4(rdram, ctx);
        goto after_6;
    // 0x80553510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80553514: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80553518: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8055351C: swc1        $f16, 0xD60($t0)
    MEM_W(0XD60, ctx->r8) = ctx->f16.u32l;
    // 0x80553520: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80553524: ori         $t2, $t1, 0xF000
    ctx->r10 = ctx->r9 | 0XF000;
    // 0x80553528: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    // 0x8055352C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80553530:
    // 0x80553530: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80553534: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80553538: jr          $ra
    // 0x8055353C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8055353C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805AE084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE084: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE088: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE08C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE090: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE094: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE098: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE09C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE0A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE0A4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE0A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE0AC: jr          $ra
    // 0x805AE0B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE0B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C350C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C350C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C3510: lui         $v1, 0xB800
    ctx->r3 = S32(0XB800 << 16);
    // 0x804C3514: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804C3518: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x804C351C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804C3520: sw          $v1, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->r3;
    // 0x804C3524: sw          $zero, 0x144($v0)
    MEM_W(0X144, ctx->r2) = 0;
    // 0x804C3528: jr          $ra
    // 0x804C352C: sw          $t6, 0x280($v0)
    MEM_W(0X280, ctx->r2) = ctx->r14;
    return;
    // 0x804C352C: sw          $t6, 0x280($v0)
    MEM_W(0X280, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8040EFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EFD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EFD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EFD8: jal         0x8040EDB0
    // 0x8040EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EDB0(rdram, ctx);
        goto after_0;
    // 0x8040EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EFE0: jal         0x8040EB60
    // 0x8040EFE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040EB60(rdram, ctx);
        goto after_1;
    // 0x8040EFE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040EFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EFF0: jr          $ra
    // 0x8040EFF4: nop

    return;
    // 0x8040EFF4: nop

;}
RECOMP_FUNC void func_80043DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043DDC: jal         0x80057C9C
    // 0x80043DE0: nop

    func_80057C9C(rdram, ctx);
        goto after_0;
    // 0x80043DE0: nop

    after_0:
    // 0x80043DE4: bne         $v0, $zero, L_80043DF4
    if (ctx->r2 != 0) {
        // 0x80043DE8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80043DF4;
    }
    // 0x80043DE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80043DEC: b           L_80043E00
    // 0x80043DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043E00;
    // 0x80043DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043DF4:
    // 0x80043DF4: jal         0x80043C94
    // 0x80043DF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80043C94(rdram, ctx);
        goto after_1;
    // 0x80043DF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80043DFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80043E00:
    // 0x80043E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043E04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043E08: jr          $ra
    // 0x80043E0C: nop

    return;
    // 0x80043E0C: nop

;}
RECOMP_FUNC void func_80043D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043D14: jal         0x80057BAC
    // 0x80043D18: nop

    func_80057BAC(rdram, ctx);
        goto after_0;
    // 0x80043D18: nop

    after_0:
    // 0x80043D1C: jal         0x80043C94
    // 0x80043D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80043C94(rdram, ctx);
        goto after_1;
    // 0x80043D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80043D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043D2C: jr          $ra
    // 0x80043D30: nop

    return;
    // 0x80043D30: nop

;}
RECOMP_FUNC void func_804465A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804465A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804465A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804465A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804465AC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x804465B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804465B4: sw          $t6, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r14;
    // 0x804465B8: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x804465BC: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x804465C0: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x804465C4: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x804465C8: sw          $a1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r5;
    // 0x804465CC: sw          $v1, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r3;
    // 0x804465D0: sw          $a1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r5;
    // 0x804465D4: jr          $ra
    // 0x804465D8: sw          $t7, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r15;
    return;
    // 0x804465D8: sw          $t7, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8066B324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B324: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8066B328: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B32C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B330: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B334: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B338: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B33C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8066B340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8066B344: jal         0x8066AD18
    // 0x8066B348: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B348: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066B34C: jal         0x8066B1C4
    // 0x8066B350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B1C4(rdram, ctx);
        goto after_1;
    // 0x8066B350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8066B354: jal         0x8066B050
    // 0x8066B358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_2;
    // 0x8066B358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8066B35C: beq         $v0, $zero, L_8066B37C
    if (ctx->r2 == 0) {
        // 0x8066B360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8066B37C;
    }
    // 0x8066B360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B364: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8066B368: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8066B36C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B370: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x8066B374: jal         0x8066B970
    // 0x8066B378: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_8066B970(rdram, ctx);
        goto after_3;
    // 0x8066B378: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_3:
L_8066B37C:
    // 0x8066B37C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066B380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B384: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8066B388: jr          $ra
    // 0x8066B38C: nop

    return;
    // 0x8066B38C: nop

;}
RECOMP_FUNC void func_805D8944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8944: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D8948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D894C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D8950: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D8954: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D8958: jal         0x805D87D0
    // 0x805D895C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805D87D0(rdram, ctx);
        goto after_0;
    // 0x805D895C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805D8960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8964: jal         0x805D84A4
    // 0x805D8968: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805D84A4(rdram, ctx);
        goto after_1;
    // 0x805D8968: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805D896C: jal         0x805D871C
    // 0x805D8970: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_805D871C(rdram, ctx);
        goto after_2;
    // 0x805D8970: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x805D8974: beq         $v0, $zero, L_805D8998
    if (ctx->r2 == 0) {
        // 0x805D8978: addiu       $t7, $zero, 0x12C
        ctx->r15 = ADD32(0, 0X12C);
            goto L_805D8998;
    }
    // 0x805D8978: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x805D897C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805D8980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D8988: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    // 0x805D898C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805D8990: jal         0x805D8AB4
    // 0x805D8994: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_805D8AB4(rdram, ctx);
        goto after_3;
    // 0x805D8994: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
L_805D8998:
    // 0x805D8998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D899C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D89A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D89A4: jr          $ra
    // 0x805D89A8: nop

    return;
    // 0x805D89A8: nop

;}
RECOMP_FUNC void func_804C2028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C202C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C2030: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804C2034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C2038: beq         $t6, $zero, L_804C2074
    if (ctx->r14 == 0) {
        // 0x804C203C: nop
    
            goto L_804C2074;
    }
    // 0x804C203C: nop

    // 0x804C2040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C2044: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804C2048: jalr        $t9
    // 0x804C204C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C204C: nop

    after_0:
    // 0x804C2050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C2054: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804C2058: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804C205C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804C2060: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804C2064: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804C2068: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804C206C: b           L_804C2074
    // 0x804C2070: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804C2074;
    // 0x804C2070: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804C2074:
    // 0x804C2074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C2078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C207C: jr          $ra
    // 0x804C2080: nop

    return;
    // 0x804C2080: nop

;}
RECOMP_FUNC void func_804529CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804529CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804529D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804529D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804529D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804529DC: addiu       $t6, $zero, 0x1D
    ctx->r14 = ADD32(0, 0X1D);
    // 0x804529E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804529E4: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x804529E8: jal         0x8044580C
    // 0x804529EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8044580C(rdram, ctx);
        goto after_0;
    // 0x804529EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804529F0: jal         0x80450350
    // 0x804529F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80450350(rdram, ctx);
        goto after_1;
    // 0x804529F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804529F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804529FC: jal         0x80450384
    // 0x80452A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80450384(rdram, ctx);
        goto after_2;
    // 0x80452A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80452A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452A0C: jr          $ra
    // 0x80452A10: nop

    return;
    // 0x80452A10: nop

;}
RECOMP_FUNC void func_804448C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804448C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804448CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x804448D0: jr          $ra
    // 0x804448D4: sb          $t6, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = ctx->r14;
    return;
    // 0x804448D4: sb          $t6, 0x7EA4($at)
    MEM_B(0X7EA4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_806CD820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD820: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CD824: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806CD828: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806CD82C: jal         0x806CCF00
    // 0x806CD830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD834: jal         0x806CD470
    // 0x806CD838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD83C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD840: jal         0x806CB7EC
    // 0x806CD844: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_806CB7EC(rdram, ctx);
        goto after_2;
    // 0x806CD844: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_2:
    // 0x806CD848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806CD84C: lui         $a1, 0x3A83
    ctx->r5 = S32(0X3A83 << 16);
    // 0x806CD850: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x806CD854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD858: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806CD85C: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x806CD860: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x806CD864: jal         0x806CCF4C
    // 0x806CD868: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_806CCF4C(rdram, ctx);
        goto after_3;
    // 0x806CD868: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x806CD86C: jal         0x806CCE38
    // 0x806CD870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_4;
    // 0x806CD870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CD874: beq         $v0, $zero, L_806CD890
    if (ctx->r2 == 0) {
        // 0x806CD878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD890;
    }
    // 0x806CD878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD87C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD880: jal         0x806CED40
    // 0x806CD884: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806CED40(rdram, ctx);
        goto after_5;
    // 0x806CD884: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x806CD888: jal         0x806CCCE4
    // 0x806CD88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_6;
    // 0x806CD88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_806CD890:
    // 0x806CD890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806CD894: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806CD898: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806CD89C: jr          $ra
    // 0x806CD8A0: nop

    return;
    // 0x806CD8A0: nop

;}
RECOMP_FUNC void func_806CEC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEC80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CEC84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CEC88: jal         0x806CEC44
    // 0x806CEC8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806CEC44(rdram, ctx);
        goto after_0;
    // 0x806CEC8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806CEC90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CEC94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CEC98: jal         0x806CED40
    // 0x806CEC9C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_806CED40(rdram, ctx);
        goto after_1;
    // 0x806CEC9C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x806CECA0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806CECA4: sw          $zero, 0x1E4($t6)
    MEM_W(0X1E4, ctx->r14) = 0;
    // 0x806CECA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CECAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CECB0: jr          $ra
    // 0x806CECB4: nop

    return;
    // 0x806CECB4: nop

;}
RECOMP_FUNC void func_8045A7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A7E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045A7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045A7E8: jal         0x8045A7A8
    // 0x8045A7EC: nop

    func_8045A7A8(rdram, ctx);
        goto after_0;
    // 0x8045A7EC: nop

    after_0:
    // 0x8045A7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045A7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045A7F8: jr          $ra
    // 0x8045A7FC: nop

    return;
    // 0x8045A7FC: nop

;}
RECOMP_FUNC void func_807C3EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3EC0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C3EC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807C3EC8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807C3ECC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C3ED0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C3ED4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C3ED8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C3EDC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x807C3EE0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C3EE4: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(907, 0X1428) << 16);
    // 0x807C3EE8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C3EEC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C3EF0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C3EF4: lw          $t1, 0x4788($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(907, 0X1428));
    // 0x807C3EF8: jr          $ra
    // 0x807C3EFC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C3EFC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804489F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804489F8: jr          $ra
    // 0x804489FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804489FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805C82C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C82C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C82C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C82C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C82CC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C82D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C82D4: jal         0x805C6A70
    // 0x805C82D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805C6A70(rdram, ctx);
        goto after_0;
    // 0x805C82D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C82DC: bne         $v0, $zero, L_805C8330
    if (ctx->r2 != 0) {
        // 0x805C82E0: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805C8330;
    }
    // 0x805C82E0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805C82E4: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(447, 0X3AFC) << 16);
    // 0x805C82E8: lw          $t6, -0x6014($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(447, 0X3AFC));
    // 0x805C82EC: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(447, 0X3AF8) << 16);
    // 0x805C82F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C82F4: sw          $t6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r14;
    // 0x805C82F8: lw          $t7, -0x6018($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(447, 0X3AF8));
    // 0x805C82FC: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C8300: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x805C8304: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C8308: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    // 0x805C830C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C8310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8314: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x805C8318: jal         0x805C74C8
    // 0x805C831C: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C831C: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    after_1:
    // 0x805C8320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8328: jal         0x805C9D10
    // 0x805C832C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C832C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
L_805C8330:
    // 0x805C8330: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C8334: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805C8338: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805C833C: jal         0x80048F84
    // 0x805C8340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805C8340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x805C8344: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C8348: jal         0x80048F84
    // 0x805C834C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805C834C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805C8350: jal         0x805C7844
    // 0x805C8354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_5;
    // 0x805C8354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805C8358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C835C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8360: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805C8364: jr          $ra
    // 0x805C8368: nop

    return;
    // 0x805C8368: nop

;}
RECOMP_FUNC void func_80078040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007804C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80078050: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80078054: jal         0x80084820
    // 0x80078058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80078058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007805C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078060: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80078064: jal         0x80084820
    // 0x80078068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x80078068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8007806C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078070: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80078074: addiu       $t7, $t7, 0x7F30
    ctx->r15 = ADD32(ctx->r15, 0X7F30);
    // 0x80078078: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8007807C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80078080: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80078084: lbu         $t8, 0x8($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X8);
    // 0x80078088: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    // 0x8007808C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078090: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80078094: sb          $t9, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r25;
    // 0x80078098: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007809C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800780A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800780A4: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    // 0x800780A8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800780AC: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    // 0x800780B0: sb          $v0, 0x1F($a0)
    MEM_B(0X1F, ctx->r4) = ctx->r2;
    // 0x800780B4: sb          $v0, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r2;
    // 0x800780B8: sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // 0x800780BC: sb          $v0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r2;
    // 0x800780C0: sb          $v1, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r3;
    // 0x800780C4: sb          $v1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r3;
    // 0x800780C8: sb          $v1, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r3;
    // 0x800780CC: sb          $v1, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r3;
    // 0x800780D0: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x800780D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800780D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800780DC: jr          $ra
    // 0x800780E0: nop

    return;
    // 0x800780E0: nop

    // 0x800780E4: nop

    // 0x800780E8: nop

    // 0x800780EC: nop

;}
RECOMP_FUNC void func_806EA7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA7D0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806EA7D4: addiu       $at, $zero, 0x45D6
    ctx->r1 = ADD32(0, 0X45D6);
    // 0x806EA7D8: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(670, 0XC0C) << 16);
    // 0x806EA7DC: bne         $t6, $at, L_806EA7F0
    if (ctx->r14 != ctx->r1) {
        // 0x806EA7E0: addiu       $v0, $v0, -0x4C24
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(670, 0XC0C));
            goto L_806EA7F0;
    }
    // 0x806EA7E0: addiu       $v0, $v0, -0x4C24
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(670, 0XC0C));
    // 0x806EA7E4: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(670, 0XC0C) << 16);
    // 0x806EA7E8: jr          $ra
    // 0x806EA7EC: addiu       $v0, $v0, -0x4C24
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(670, 0XC0C));
    return;
    // 0x806EA7EC: addiu       $v0, $v0, -0x4C24
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(670, 0XC0C));
L_806EA7F0:
    // 0x806EA7F0: jr          $ra
    // 0x806EA7F4: nop

    return;
    // 0x806EA7F4: nop

;}
RECOMP_FUNC void func_8066B4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B4EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066B4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B4F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B4F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B4FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B500: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8066B508: jal         0x8066AD18
    // 0x8066B50C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B50C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066B510: jal         0x8066B050
    // 0x8066B514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_1;
    // 0x8066B514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8066B518: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8066B51C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8066B520: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8066B524: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8066B528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B52C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B530: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066B534: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8066B538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8066B53C: bc1f        L_8066B54C
    if (!c1cs) {
        // 0x8066B540: nop
    
            goto L_8066B54C;
    }
    // 0x8066B540: nop

    // 0x8066B544: jal         0x8066B970
    // 0x8066B548: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_8066B970(rdram, ctx);
        goto after_2;
    // 0x8066B548: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
L_8066B54C:
    // 0x8066B54C: jal         0x8066B1C4
    // 0x8066B550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B1C4(rdram, ctx);
        goto after_3;
    // 0x8066B550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8066B554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066B558: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B55C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066B560: jr          $ra
    // 0x8066B564: nop

    return;
    // 0x8066B564: nop

;}
RECOMP_FUNC void func_8000AC58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AC5C: jr          $ra
    // 0x8000AC60: sw          $a0, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = ctx->r4;
    return;
    // 0x8000AC60: sw          $a0, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8001BEF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BEF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001BEF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001BEF8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001BEFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001BF00: slti        $at, $a1, 0x51
    ctx->r1 = SIGNED(ctx->r5) < 0X51 ? 1 : 0;
    // 0x8001BF04: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001BF08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001BF0C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001BF10: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF18: beq         $at, $zero, L_8001BF60
    if (ctx->r1 == 0) {
        // 0x8001BF1C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001BF60;
    }
    // 0x8001BF1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BF20: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8001BF24: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8001BF28: addiu       $t7, $t7, -0x6CE0
    ctx->r15 = ADD32(ctx->r15, -0X6CE0);
    // 0x8001BF2C: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8001BF30: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BF34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001BF38: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
L_8001BF3C:
    // 0x8001BF3C: addiu       $s2, $s0, 0x1
    ctx->r18 = ADD32(ctx->r16, 0X1);
    // 0x8001BF40: lbu         $a3, 0x0($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X0);
    // 0x8001BF44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001BF48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001BF4C: jal         0x8001BE40
    // 0x8001BF50: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8001BE40(rdram, ctx);
        goto after_0;
    // 0x8001BF50: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x8001BF54: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8001BF58: bne         $s2, $s4, L_8001BF3C
    if (ctx->r18 != ctx->r20) {
        // 0x8001BF5C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001BF3C;
    }
    // 0x8001BF5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001BF60:
    // 0x8001BF60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BF64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001BF68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BF6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001BF70: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001BF74: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001BF78: jr          $ra
    // 0x8001BF7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001BF7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80471934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8047193C: jal         0x8004700C
    // 0x80471940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80471940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80471944: beq         $v0, $zero, L_80471964
    if (ctx->r2 == 0) {
        // 0x80471948: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471964;
    }
    // 0x80471948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8047194C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80471950: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x80471954: bnel        $t6, $t7, L_80471968
    if (ctx->r14 != ctx->r15) {
        // 0x80471958: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80471968;
    }
    goto skip_0;
    // 0x80471958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8047195C: b           L_80471968
    // 0x80471960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80471968;
    // 0x80471960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80471964:
    // 0x80471964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80471968:
    // 0x80471968: jr          $ra
    // 0x8047196C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8047196C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806CD470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD470: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CD478: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CD47C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CD480: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806CD484: lwc1        $f2, 0x864($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X864);
    // 0x806CD488: lwc1        $f4, 0x868($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X868);
    // 0x806CD48C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C3C) << 16);
    // 0x806CD490: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x806CD494: swc1        $f6, 0x868($v0)
    MEM_W(0X868, ctx->r2) = ctx->f6.u32l;
    // 0x806CD498: lwc1        $f0, 0x868($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X868);
    // 0x806CD49C: lwc1        $f10, -0xCA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C3C));
    // 0x806CD4A0: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x806CD4A4: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x806CD4A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CD4AC: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x806CD4B0: swc1        $f18, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f18.u32l;
    // 0x806CD4B4: jal         0x80065954
    // 0x806CD4B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x806CD4B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806CD4BC: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C40) << 16);
    // 0x806CD4C0: lwc1        $f4, -0xCA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C40));
    // 0x806CD4C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD4C8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C44) << 16);
    // 0x806CD4CC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806CD4D0: nop

    // 0x806CD4D4: bc1fl       L_806CD4F0
    if (!c1cs) {
        // 0x806CD4D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806CD4F0;
    }
    goto skip_0;
    // 0x806CD4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806CD4DC: lwc1        $f6, 0x864($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X864);
    // 0x806CD4E0: lwc1        $f8, -0xC9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C44));
    // 0x806CD4E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CD4E8: swc1        $f10, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f10.u32l;
    // 0x806CD4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806CD4F0:
    // 0x806CD4F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD4F4: jr          $ra
    // 0x806CD4F8: nop

    return;
    // 0x806CD4F8: nop

;}
RECOMP_FUNC void func_806AE7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE7C0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F8C) << 16);
    // 0x806AE7C4: lwc1        $f0, -0x334($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F8C));
    // 0x806AE7C8: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806AE7CC: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806AE7D0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AE7D4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806AE7D8: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X7FC) << 16);
    // 0x806AE7DC: addiu       $t9, $t9, -0x1AC4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X7FC));
    // 0x806AE7E0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806AE7E4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x806AE7E8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x806AE7EC: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x806AE7F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806AE7F4: sltiu       $at, $t7, 0x3C
    ctx->r1 = ctx->r15 < 0X3C ? 1 : 0;
    // 0x806AE7F8: bne         $at, $zero, L_806AE814
    if (ctx->r1 != 0) {
        // 0x806AE7FC: sw          $t7, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r15;
            goto L_806AE814;
    }
    // 0x806AE7FC: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x806AE800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AE804: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x806AE808: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806AE80C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806AE810: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_806AE814:
    // 0x806AE814: jr          $ra
    // 0x806AE818: nop

    return;
    // 0x806AE818: nop

;}
RECOMP_FUNC void func_806E4730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4730: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806E4734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E4738: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806E473C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806E4740: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806E4744: jal         0x8004700C
    // 0x806E4748: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806E4748: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806E474C: jal         0x800653D8
    // 0x806E4750: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806E4750: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x806E4754: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x806E4758: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x806E475C: jal         0x806E3DD0
    // 0x806E4760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806E3DD0(rdram, ctx);
        goto after_2;
    // 0x806E4760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x806E4764: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x806E4768: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x806E476C: bnel        $t8, $zero, L_806E4780
    if (ctx->r24 != 0) {
        // 0x806E4770: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_806E4780;
    }
    goto skip_0;
    // 0x806E4770: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x806E4774: jal         0x806E3A3C
    // 0x806E4778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806E3A3C(rdram, ctx);
        goto after_3;
    // 0x806E4778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x806E477C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_806E4780:
    // 0x806E4780: beql        $t9, $zero, L_806E4B38
    if (ctx->r25 == 0) {
        // 0x806E4784: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4B38;
    }
    goto skip_1;
    // 0x806E4784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806E4788: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x806E478C: bnel        $t0, $zero, L_806E4B38
    if (ctx->r8 != 0) {
        // 0x806E4790: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4B38;
    }
    goto skip_2;
    // 0x806E4790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806E4794: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x806E4798: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X2004) << 16);
    // 0x806E479C: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806E47A0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x806E47A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806E47A8: lwc1        $f4, 0x5804($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2004));
    // 0x806E47AC: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x806E47B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806E47B4: nop

    // 0x806E47B8: bc1fl       L_806E48C4
    if (!c1cs) {
        // 0x806E47BC: andi        $v1, $v0, 0x1
        ctx->r3 = ctx->r2 & 0X1;
            goto L_806E48C4;
    }
    goto skip_3;
    // 0x806E47BC: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    skip_3:
    // 0x806E47C0: beq         $at, $zero, L_806E48C0
    if (ctx->r1 == 0) {
        // 0x806E47C4: lui         $at, 0x806E
        ctx->r1 = S32(RELOC_HI16(649, 0X20BC) << 16);
            goto L_806E48C0;
    }
    // 0x806E47C4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X20BC) << 16);
    // 0x806E47C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806E47CC: lwc1        $f8, 0x58BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X20BC));
    // 0x806E47D0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X2118) << 16);
    // 0x806E47D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806E47D8: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x806E47DC: jal         0x80066E88
    // 0x806E47E0: lwc1        $f12, 0x5918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2118));
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x806E47E0: lwc1        $f12, 0x5918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2118));
    after_4:
    // 0x806E47E4: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806E47E8: addiu       $a3, $s1, 0xC4
    ctx->r7 = ADD32(ctx->r17, 0XC4);
    // 0x806E47EC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X2118) << 16);
    // 0x806E47F0: swc1        $f10, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f10.u32l;
    // 0x806E47F4: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x806E47F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E47FC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806E4800: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x806E4804: jal         0x80066DE4
    // 0x806E4808: lwc1        $f12, 0x5918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2118));
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x806E4808: lwc1        $f12, 0x5918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2118));
    after_5:
    // 0x806E480C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4810: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806E4814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806E4818: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806E481C: addiu       $t6, $zero, 0x17
    ctx->r14 = ADD32(0, 0X17);
    // 0x806E4820: swc1        $f16, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f16.u32l;
    // 0x806E4824: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x806E4828: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x806E482C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x806E4830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4834: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806E4838: slti        $at, $t4, 0x17
    ctx->r1 = SIGNED(ctx->r12) < 0X17 ? 1 : 0;
    // 0x806E483C: bne         $at, $zero, L_806E4978
    if (ctx->r1 != 0) {
        // 0x806E4840: sw          $t4, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r12;
            goto L_806E4978;
    }
    // 0x806E4840: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x806E4844: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x806E4848: jal         0x806E3D64
    // 0x806E484C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E3D64(rdram, ctx);
        goto after_6;
    // 0x806E484C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_6:
    // 0x806E4850: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x806E4854: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806E4858: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E485C: lwc1        $f8, 0x84($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X84);
    // 0x806E4860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806E4864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4868: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806E486C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4870: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806E4874: bc1fl       L_806E4884
    if (!c1cs) {
        // 0x806E4878: lw          $t8, 0x138($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X138);
            goto L_806E4884;
    }
    goto skip_4;
    // 0x806E4878: lw          $t8, 0x138($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X138);
    skip_4:
    // 0x806E487C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806E4880: lw          $t8, 0x138($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X138);
L_806E4884:
    // 0x806E4884: beql        $v0, $t8, L_806E48B0
    if (ctx->r2 == ctx->r24) {
        // 0x806E4888: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_806E48B0;
    }
    goto skip_5;
    // 0x806E4888: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_5:
    // 0x806E488C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x806E4890: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E4894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E489C: jal         0x806E511C
    // 0x806E48A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806E511C(rdram, ctx);
        goto after_7;
    // 0x806E48A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x806E48A4: b           L_806E4978
    // 0x806E48A8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_806E4978;
    // 0x806E48A8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E48AC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_806E48B0:
    // 0x806E48B0: jal         0x806E511C
    // 0x806E48B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E511C(rdram, ctx);
        goto after_8;
    // 0x806E48B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_8:
    // 0x806E48B8: b           L_806E4978
    // 0x806E48BC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_806E4978;
    // 0x806E48BC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_806E48C0:
    // 0x806E48C0: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
L_806E48C4:
    // 0x806E48C4: bne         $v1, $zero, L_806E4900
    if (ctx->r3 != 0) {
        // 0x806E48C8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_806E4900;
    }
    // 0x806E48C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806E48CC: addiu       $a3, $s1, 0xC4
    ctx->r7 = ADD32(ctx->r17, 0XC4);
    // 0x806E48D0: lwc1        $f10, 0x1C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x806E48D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806E48D8: nop

    // 0x806E48DC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x806E48E0: nop

    // 0x806E48E4: bc1t        L_806E4900
    if (c1cs) {
        // 0x806E48E8: nop
    
            goto L_806E4900;
    }
    // 0x806E48E8: nop

    // 0x806E48EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806E48F0: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x806E48F4: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x806E48F8: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x806E48FC: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
L_806E4900:
    // 0x806E4900: bne         $v1, $zero, L_806E4978
    if (ctx->r3 != 0) {
        // 0x806E4904: addiu       $a3, $s1, 0xC4
        ctx->r7 = ADD32(ctx->r17, 0XC4);
            goto L_806E4978;
    }
    // 0x806E4904: addiu       $a3, $s1, 0xC4
    ctx->r7 = ADD32(ctx->r17, 0XC4);
    // 0x806E4908: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x806E490C: beql        $t9, $zero, L_806E497C
    if (ctx->r25 == 0) {
        // 0x806E4910: lw          $a1, 0x14($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X14);
            goto L_806E497C;
    }
    goto skip_6;
    // 0x806E4910: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    skip_6:
    // 0x806E4914: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806E4918: lwc1        $f4, 0x18($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X18);
    // 0x806E491C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E4920: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x806E4924: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x806E4928: nop

    // 0x806E492C: bc1fl       L_806E4944
    if (!c1cs) {
        // 0x806E4930: lwc1        $f8, 0x3C($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
            goto L_806E4944;
    }
    goto skip_7;
    // 0x806E4930: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    skip_7:
    // 0x806E4934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E4938: b           L_806E4978
    // 0x806E493C: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_806E4978;
    // 0x806E493C: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
    // 0x806E4940: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
L_806E4944:
    // 0x806E4944: lwc1        $f10, 0x84($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806E4948: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E494C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806E4950: nop

    // 0x806E4954: bc1fl       L_806E4970
    if (!c1cs) {
        // 0x806E4958: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_806E4970;
    }
    goto skip_8;
    // 0x806E4958: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_8:
    // 0x806E495C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806E4960: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806E4964: b           L_806E4978
    // 0x806E4968: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
        goto L_806E4978;
    // 0x806E4968: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
    // 0x806E496C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_806E4970:
    // 0x806E4970: nop

    // 0x806E4974: swc1        $f18, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f18.u32l;
L_806E4978:
    // 0x806E4978: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
L_806E497C:
    // 0x806E497C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E4980: jal         0x806E3FE4
    // 0x806E4984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806E3FE4(rdram, ctx);
        goto after_9;
    // 0x806E4984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x806E4988: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x806E498C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4990: beq         $v0, $zero, L_806E499C
    if (ctx->r2 == 0) {
        // 0x806E4994: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_806E499C;
    }
    // 0x806E4994: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x806E4998: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
L_806E499C:
    // 0x806E499C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x806E49A0: beq         $v0, $zero, L_806E49AC
    if (ctx->r2 == 0) {
        // 0x806E49A4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_806E49AC;
    }
    // 0x806E49A4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x806E49A8: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
L_806E49AC:
    // 0x806E49AC: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x806E49B0: beql        $t3, $zero, L_806E4A64
    if (ctx->r11 == 0) {
        // 0x806E49B4: lw          $t8, 0x30($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X30);
            goto L_806E4A64;
    }
    goto skip_9;
    // 0x806E49B4: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x806E49B8: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x806E49BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E49C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806E49C4: beql        $t4, $zero, L_806E4A64
    if (ctx->r12 == 0) {
        // 0x806E49C8: lw          $t8, 0x30($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X30);
            goto L_806E4A64;
    }
    goto skip_10;
    // 0x806E49C8: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    skip_10:
    // 0x806E49CC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x806E49D0: jal         0x806E3D64
    // 0x806E49D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E3D64(rdram, ctx);
        goto after_10;
    // 0x806E49D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_10:
    // 0x806E49D8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E49DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806E49E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806E49E4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x806E49E8: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x806E49EC: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x806E49F0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x806E49F4: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806E49F8: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x806E49FC: lwc1        $f10, 0x84($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X84);
    // 0x806E4A00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4A08: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806E4A0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806E4A10: bc1fl       L_806E4A20
    if (!c1cs) {
        // 0x806E4A14: lw          $t6, 0x138($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X138);
            goto L_806E4A20;
    }
    goto skip_11;
    // 0x806E4A14: lw          $t6, 0x138($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X138);
    skip_11:
    // 0x806E4A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806E4A1C: lw          $t6, 0x138($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X138);
L_806E4A20:
    // 0x806E4A20: beql        $v0, $t6, L_806E4A4C
    if (ctx->r2 == ctx->r14) {
        // 0x806E4A24: sw          $t7, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->r15;
            goto L_806E4A4C;
    }
    goto skip_12;
    // 0x806E4A24: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    skip_12:
    // 0x806E4A28: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x806E4A2C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E4A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4A38: jal         0x806E511C
    // 0x806E4A3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806E511C(rdram, ctx);
        goto after_11;
    // 0x806E4A3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_11:
    // 0x806E4A40: b           L_806E4B18
    // 0x806E4A44: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_806E4B18;
    // 0x806E4A44: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4A48: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
L_806E4A4C:
    // 0x806E4A4C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x806E4A50: jal         0x806E511C
    // 0x806E4A54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E511C(rdram, ctx);
        goto after_12;
    // 0x806E4A54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_12:
    // 0x806E4A58: b           L_806E4B18
    // 0x806E4A5C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_806E4B18;
    // 0x806E4A5C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4A60: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
L_806E4A64:
    // 0x806E4A64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806E4A68: bnel        $t8, $zero, L_806E4AD0
    if (ctx->r24 != 0) {
        // 0x806E4A6C: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_806E4AD0;
    }
    goto skip_13;
    // 0x806E4A6C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_13:
    // 0x806E4A70: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x806E4A74: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(649, 0X1D68) << 16);
    // 0x806E4A78: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x806E4A7C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806E4A80: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E4A84: lw          $t1, 0x5568($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(649, 0X1D68));
    // 0x806E4A88: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x806E4A8C: bne         $t2, $zero, L_806E4AB8
    if (ctx->r10 != 0) {
        // 0x806E4A90: sw          $t1, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->r9;
            goto L_806E4AB8;
    }
    // 0x806E4A90: sw          $t1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r9;
    // 0x806E4A94: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x806E4A98: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x806E4A9C: jal         0x80067BBC
    // 0x806E4AA0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_13;
    // 0x806E4AA0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_13:
    // 0x806E4AA4: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
    // 0x806E4AA8: jal         0x80067818
    // 0x806E4AAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_14;
    // 0x806E4AAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x806E4AB0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4AB4: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
L_806E4AB8:
    // 0x806E4AB8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x806E4ABC: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x806E4AC0: bne         $at, $zero, L_806E4ACC
    if (ctx->r1 != 0) {
        // 0x806E4AC4: sw          $t3, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r11;
            goto L_806E4ACC;
    }
    // 0x806E4AC4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x806E4AC8: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_806E4ACC:
    // 0x806E4ACC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_806E4AD0:
    // 0x806E4AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4AD4: bnel        $t5, $zero, L_806E4AEC
    if (ctx->r13 != 0) {
        // 0x806E4AD8: lw          $t6, 0x138($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X138);
            goto L_806E4AEC;
    }
    goto skip_14;
    // 0x806E4AD8: lw          $t6, 0x138($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X138);
    skip_14:
    // 0x806E4ADC: jal         0x806E3CC0
    // 0x806E4AE0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E3CC0(rdram, ctx);
        goto after_15;
    // 0x806E4AE0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_15:
    // 0x806E4AE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806E4AE8: lw          $t6, 0x138($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X138);
L_806E4AEC:
    // 0x806E4AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4AF0: bnel        $t6, $zero, L_806E4B1C
    if (ctx->r14 != 0) {
        // 0x806E4AF4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806E4B1C;
    }
    goto skip_15;
    // 0x806E4AF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_15:
    // 0x806E4AF8: jal         0x806E3D64
    // 0x806E4AFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806E3D64(rdram, ctx);
        goto after_16;
    // 0x806E4AFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_16:
    // 0x806E4B00: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x806E4B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E4B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4B0C: jal         0x806E511C
    // 0x806E4B10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806E511C(rdram, ctx);
        goto after_17;
    // 0x806E4B10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x806E4B14: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_806E4B18:
    // 0x806E4B18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_806E4B1C:
    // 0x806E4B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E4B20: jal         0x80048F84
    // 0x806E4B24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_18;
    // 0x806E4B24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_18:
    // 0x806E4B28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x806E4B2C: jal         0x80048F84
    // 0x806E4B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_19;
    // 0x806E4B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x806E4B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E4B38:
    // 0x806E4B38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806E4B3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806E4B40: jr          $ra
    // 0x806E4B44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806E4B44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80400B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400B10: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80400B14: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80400B18: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80400B1C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80400B20: bgtz        $t8, L_80400B48
    if (SIGNED(ctx->r24) > 0) {
        // 0x80400B24: nop
    
            goto L_80400B48;
    }
    // 0x80400B24: nop

    // 0x80400B28: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80400B2C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80400B30: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80400B34: bne         $v0, $at, L_80400B44
    if (ctx->r2 != ctx->r1) {
        // 0x80400B38: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80400B44;
    }
    // 0x80400B38: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80400B3C: jr          $ra
    // 0x80400B40: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    return;
    // 0x80400B40: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80400B44:
    // 0x80400B44: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
L_80400B48:
    // 0x80400B48: jr          $ra
    // 0x80400B4C: nop

    return;
    // 0x80400B4C: nop

;}
RECOMP_FUNC void func_804BCA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BCA20: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804BCA24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BCA28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BCA2C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BCA30: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804BCA34: lw          $s0, 0x370($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X370);
    // 0x804BCA38: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x804BCA3C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x804BCA40: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x804BCA44: jal         0x80066DE4
    // 0x804BCA48: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x804BCA48: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804BCA4C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804BCA50: jal         0x80066E88
    // 0x804BCA54: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804BCA54: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x804BCA58: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x804BCA5C: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x804BCA60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x804BCA64: jal         0x80066DE4
    // 0x804BCA68: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804BCA68: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x804BCA6C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804BCA70: jal         0x80066E88
    // 0x804BCA74: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x804BCA74: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x804BCA78: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x804BCA7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BCA80: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x804BCA84: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x804BCA88: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x804BCA8C: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BCA90: lh          $t6, 0x348($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X348);
    // 0x804BCA94: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804BCA98: lh          $t7, 0x34A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X34A);
    // 0x804BCA9C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804BCAA0: lwc1        $f10, 0x6C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x804BCAA4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804BCAA8: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x804BCAAC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804BCAB0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X418C) << 16);
    // 0x804BCAB4: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x804BCAB8: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
    // 0x804BCABC: addiu       $v0, $v0, 0x348
    ctx->r2 = ADD32(ctx->r2, 0X348);
    // 0x804BCAC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BCAC4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804BCAC8: mul.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x804BCACC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BCAD0: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x804BCAD4: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804BCAD8: nop

    // 0x804BCADC: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x804BCAE0: nop

    // 0x804BCAE4: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x804BCAE8: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x804BCAEC: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x804BCAF0: nop

    // 0x804BCAF4: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x804BCAF8: add.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x804BCAFC: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x804BCB00: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x804BCB04: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x804BCB08: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x804BCB0C: lwc1        $f4, -0x544($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X418C));
    // 0x804BCB10: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x804BCB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BCB18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BCB1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x804BCB20: jr          $ra
    // 0x804BCB24: nop

    return;
    // 0x804BCB24: nop

;}
RECOMP_FUNC void func_80436C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436C58: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80436C5C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80436C60: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80436C64: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(77, 0X1F18) << 16);
    // 0x80436C68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80436C6C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80436C70: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80436C74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80436C78: lw          $t8, -0x7848($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(77, 0X1F18));
    // 0x80436C7C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80436C80: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80436C84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80436C88: jal         0x80048490
    // 0x80436C8C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80436C8C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80436C90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80436C94: jal         0x80048378
    // 0x80436C98: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80436C98: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80436C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436CA4: jr          $ra
    // 0x80436CA8: nop

    return;
    // 0x80436CA8: nop

;}
RECOMP_FUNC void func_8045D424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045D424: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8045D428: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8045D42C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8045D430: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8045D434: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8045D438: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8045D43C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8045D440: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8045D444: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8045D448: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8045D44C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8045D450: lw          $s1, 0x4($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X4);
    // 0x8045D454: lw          $s2, 0x8($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X8);
    // 0x8045D458: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
    // 0x8045D45C: swc1        $f26, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f26.u32l;
    // 0x8045D460: swc1        $f26, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f26.u32l;
    // 0x8045D464: swc1        $f26, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f26.u32l;
    // 0x8045D468: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8045D46C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8045D470: beq         $v0, $at, L_8045D4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D474: addiu       $at, $zero, 0x4109
        ctx->r1 = ADD32(0, 0X4109);
            goto L_8045D4B8;
    }
    // 0x8045D474: addiu       $at, $zero, 0x4109
    ctx->r1 = ADD32(0, 0X4109);
    // 0x8045D478: beq         $v0, $at, L_8045D4C8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D47C: addiu       $at, $zero, 0x410A
        ctx->r1 = ADD32(0, 0X410A);
            goto L_8045D4C8;
    }
    // 0x8045D47C: addiu       $at, $zero, 0x410A
    ctx->r1 = ADD32(0, 0X410A);
    // 0x8045D480: beq         $v0, $at, L_8045D4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D484: addiu       $at, $zero, 0x410B
        ctx->r1 = ADD32(0, 0X410B);
            goto L_8045D4B8;
    }
    // 0x8045D484: addiu       $at, $zero, 0x410B
    ctx->r1 = ADD32(0, 0X410B);
    // 0x8045D488: beq         $v0, $at, L_8045D4C8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D48C: addiu       $at, $zero, 0x469C
        ctx->r1 = ADD32(0, 0X469C);
            goto L_8045D4C8;
    }
    // 0x8045D48C: addiu       $at, $zero, 0x469C
    ctx->r1 = ADD32(0, 0X469C);
    // 0x8045D490: beq         $v0, $at, L_8045D4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D494: addiu       $at, $zero, 0x469D
        ctx->r1 = ADD32(0, 0X469D);
            goto L_8045D4B8;
    }
    // 0x8045D494: addiu       $at, $zero, 0x469D
    ctx->r1 = ADD32(0, 0X469D);
    // 0x8045D498: beq         $v0, $at, L_8045D4C8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D49C: addiu       $at, $zero, 0x469E
        ctx->r1 = ADD32(0, 0X469E);
            goto L_8045D4C8;
    }
    // 0x8045D49C: addiu       $at, $zero, 0x469E
    ctx->r1 = ADD32(0, 0X469E);
    // 0x8045D4A0: beq         $v0, $at, L_8045D4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8045D4A4: addiu       $at, $zero, 0x469F
        ctx->r1 = ADD32(0, 0X469F);
            goto L_8045D4B8;
    }
    // 0x8045D4A4: addiu       $at, $zero, 0x469F
    ctx->r1 = ADD32(0, 0X469F);
    // 0x8045D4A8: beql        $v0, $at, L_8045D4CC
    if (ctx->r2 == ctx->r1) {
        // 0x8045D4AC: lui         $at, 0xC300
        ctx->r1 = S32(0XC300 << 16);
            goto L_8045D4CC;
    }
    goto skip_0;
    // 0x8045D4AC: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    skip_0:
    // 0x8045D4B0: b           L_8045D4DC
    // 0x8045D4B4: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
        goto L_8045D4DC;
    // 0x8045D4B4: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
L_8045D4B8:
    // 0x8045D4B8: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x8045D4BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045D4C0: b           L_8045D4D8
    // 0x8045D4C4: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_8045D4D8;
    // 0x8045D4C4: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_8045D4C8:
    // 0x8045D4C8: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
L_8045D4CC:
    // 0x8045D4CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045D4D0: nop

    // 0x8045D4D4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_8045D4D8:
    // 0x8045D4D8: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
L_8045D4DC:
    // 0x8045D4DC: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8045D4E0: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x8045D4E4: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8045D4E8: mul.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8045D4EC: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x8045D4F0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8045D4F4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8045D4F8: bne         $at, $zero, L_8045D564
    if (ctx->r1 != 0) {
        // 0x8045D4FC: mov.s       $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
            goto L_8045D564;
    }
    // 0x8045D4FC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x8045D500: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045D504: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8045D508: nop

    // 0x8045D50C: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
L_8045D510:
    // 0x8045D510: jal         0x80066E88
    // 0x8045D514: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8045D514: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8045D518: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8045D51C: lwc1        $f18, -0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X1C);
    // 0x8045D520: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8045D524: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8045D528: jal         0x80066DE4
    // 0x8045D52C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8045D52C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x8045D530: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8045D534: lwc1        $f8, -0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, -0X18);
    // 0x8045D538: swc1        $f26, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f26.u32l;
    // 0x8045D53C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8045D540: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8045D544: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8045D548: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8045D54C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8045D550: swc1        $f10, -0x18($s1)
    MEM_W(-0X18, ctx->r17) = ctx->f10.u32l;
    // 0x8045D554: lw          $t7, 0x30($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X30);
    // 0x8045D558: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8045D55C: bnel        $at, $zero, L_8045D510
    if (ctx->r1 != 0) {
        // 0x8045D560: swc1        $f20, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
            goto L_8045D510;
    }
    goto skip_1;
    // 0x8045D560: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    skip_1:
L_8045D564:
    // 0x8045D564: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8045D568: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8045D56C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8045D570: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8045D574: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8045D578: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8045D57C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8045D580: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8045D584: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8045D588: jr          $ra
    // 0x8045D58C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8045D58C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800481E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800481E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800481E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800481E8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800481EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800481F0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800481F4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800481F8: addiu       $a2, $a2, -0x7E94
    ctx->r6 = ADD32(ctx->r6, -0X7E94);
    // 0x800481FC: jal         0x80057F74
    // 0x80048200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x80048200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80048204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004820C: jr          $ra
    // 0x80048210: nop

    return;
    // 0x80048210: nop

;}
RECOMP_FUNC void func_804659A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804659A0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x804659A4: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x804659A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804659AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804659B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804659B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804659B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804659BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804659C0: jal         0x80465FA4
    // 0x804659C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80465FA4(rdram, ctx);
        goto after_0;
    // 0x804659C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804659C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804659CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804659D0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804659D4: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804659D8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804659DC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x804659E0: nop

    // 0x804659E4: bc1tl       L_804659F4
    if (c1cs) {
        // 0x804659E8: lwc1        $f6, 0x30($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
            goto L_804659F4;
    }
    goto skip_0;
    // 0x804659E8: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x804659EC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804659F0: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
L_804659F4:
    // 0x804659F4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x804659F8: lwc1        $f8, 0x34($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X34);
    // 0x804659FC: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80465A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465A04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80465A08: jr          $ra
    // 0x80465A0C: nop

    return;
    // 0x80465A0C: nop

;}
RECOMP_FUNC void func_805D1710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1710: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(468, 0X28) << 16);
    // 0x805D1714: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805D1718: jr          $ra
    // 0x805D171C: addiu       $v0, $v0, 0x1738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(468, 0X28));
    return;
    // 0x805D171C: addiu       $v0, $v0, 0x1738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(468, 0X28));
;}
RECOMP_FUNC void func_8064BE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BE98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064BE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064BEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064BEA4: lh          $t6, 0xC2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC2);
    // 0x8064BEA8: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8064BEAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064BEB0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064BEB4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8064BEB8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064BEBC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064BEC0: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BEC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064BEC8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064BECC: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064BED0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8064BED4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064BED8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064BEDC: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x8064BEE0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064BEE4: jal         0x8064BE3C
    // 0x8064BEE8: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    func_8064BE3C(rdram, ctx);
        goto after_0;
    // 0x8064BEE8: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064BEEC: bne         $v0, $zero, L_8064BF04
    if (ctx->r2 != 0) {
        // 0x8064BEF0: nop
    
            goto L_8064BF04;
    }
    // 0x8064BEF0: nop

    // 0x8064BEF4: jal         0x800445A4
    // 0x8064BEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064BEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064BEFC: b           L_8064BF64
    // 0x8064BF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064BF64;
    // 0x8064BF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064BF04:
    // 0x8064BF04: jal         0x8064A468
    // 0x8064BF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064BF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064BF0C: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X1CC8) << 16);
    // 0x8064BF10: addiu       $t9, $t9, -0x4268
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X1CC8));
    // 0x8064BF14: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064BF18: jal         0x8064BE80
    // 0x8064BF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064BE80(rdram, ctx);
        goto after_3;
    // 0x8064BF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064BF20: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064BF24: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X3240) << 16);
    // 0x8064BF28: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064BF2C: addiu       $t0, $t0, -0x2CF0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X3240));
    // 0x8064BF30: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064BF34: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064BF38: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064BF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064BF40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BF44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064BF48: jal         0x8064BF74
    // 0x8064BF4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064BF74(rdram, ctx);
        goto after_4;
    // 0x8064BF4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064BF50: jal         0x8064A158
    // 0x8064BF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064BF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064BF58: jal         0x8064A40C
    // 0x8064BF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064BF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064BF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064BF64:
    // 0x8064BF64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064BF68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064BF6C: jr          $ra
    // 0x8064BF70: nop

    return;
    // 0x8064BF70: nop

;}
RECOMP_FUNC void func_8001A4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A4D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001A4D8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001A4DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A4E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001A4E4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A4E8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001A4EC: jr          $ra
    // 0x8001A4F0: sw          $zero, 0x5A0($at)
    MEM_W(0X5A0, ctx->r1) = 0;
    return;
    // 0x8001A4F0: sw          $zero, 0x5A0($at)
    MEM_W(0X5A0, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800280F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800280F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800280F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800280FC: sw          $a2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r6;
    // 0x80028100: jal         0x80027F00
    // 0x80028104: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    func_80027F00(rdram, ctx);
        goto after_0;
    // 0x80028104: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80028108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002810C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028110: jr          $ra
    // 0x80028114: nop

    return;
    // 0x80028114: nop

;}
RECOMP_FUNC void func_806ECF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECF00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ECF04: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806ECF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ECF0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ECF10: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806ECF14: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806ECF18: jal         0x80062AEC
    // 0x806ECF1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806ECF1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806ECF20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806ECF24: beq         $v0, $at, L_806ECF50
    if (ctx->r2 == ctx->r1) {
        // 0x806ECF28: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806ECF50;
    }
    // 0x806ECF28: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806ECF2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806ECF30: beq         $v0, $at, L_806ECF84
    if (ctx->r2 == ctx->r1) {
        // 0x806ECF34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_806ECF84;
    }
    // 0x806ECF34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806ECF38: beq         $v0, $at, L_806ECFB8
    if (ctx->r2 == ctx->r1) {
        // 0x806ECF3C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806ECFB8;
    }
    // 0x806ECF3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806ECF40: beq         $v0, $at, L_806ECFEC
    if (ctx->r2 == ctx->r1) {
        // 0x806ECF44: nop
    
            goto L_806ECFEC;
    }
    // 0x806ECF44: nop

    // 0x806ECF48: b           L_806ED024
    // 0x806ECF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED024;
    // 0x806ECF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ECF50:
    // 0x806ECF50: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CD0) << 16);
    // 0x806ECF54: lwc1        $f4, 0xC20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CD0));
    // 0x806ECF58: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x806ECF5C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806ECF60: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806ECF64: nop

    // 0x806ECF68: bc1fl       L_806ED024
    if (!c1cs) {
        // 0x806ECF6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED024;
    }
    goto skip_0;
    // 0x806ECF6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806ECF70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806ECF74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806ECF78: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806ECF7C: b           L_806ED024
    // 0x806ECF80: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
        goto L_806ED024;
    // 0x806ECF80: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
L_806ECF84:
    // 0x806ECF84: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CD4) << 16);
    // 0x806ECF88: lwc1        $f10, 0xC24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CD4));
    // 0x806ECF8C: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x806ECF90: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806ECF94: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806ECF98: nop

    // 0x806ECF9C: bc1fl       L_806ED024
    if (!c1cs) {
        // 0x806ECFA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED024;
    }
    goto skip_1;
    // 0x806ECFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x806ECFA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806ECFA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806ECFAC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806ECFB0: b           L_806ED024
    // 0x806ECFB4: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
        goto L_806ED024;
    // 0x806ECFB4: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
L_806ECFB8:
    // 0x806ECFB8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CD8) << 16);
    // 0x806ECFBC: lwc1        $f4, 0xC28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CD8));
    // 0x806ECFC0: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806ECFC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806ECFC8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806ECFCC: nop

    // 0x806ECFD0: bc1fl       L_806ED024
    if (!c1cs) {
        // 0x806ECFD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED024;
    }
    goto skip_2;
    // 0x806ECFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x806ECFD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806ECFDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806ECFE0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806ECFE4: b           L_806ED024
    // 0x806ECFE8: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
        goto L_806ED024;
    // 0x806ECFE8: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
L_806ECFEC:
    // 0x806ECFEC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CDC) << 16);
    // 0x806ECFF0: lwc1        $f10, 0xC2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CDC));
    // 0x806ECFF4: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806ECFF8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806ECFFC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806ED000: nop

    // 0x806ED004: bc1fl       L_806ED024
    if (!c1cs) {
        // 0x806ED008: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED024;
    }
    goto skip_3;
    // 0x806ED008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x806ED00C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806ED010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806ED014: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806ED018: b           L_806ED024
    // 0x806ED01C: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
        goto L_806ED024;
    // 0x806ED01C: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
    // 0x806ED020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED024:
    // 0x806ED024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED02C: jr          $ra
    // 0x806ED030: nop

    return;
    // 0x806ED030: nop

;}
RECOMP_FUNC void func_807B8314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8314: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8318: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x807B831C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x807B8320: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x807B8324: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x807B8328: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x807B832C: beq         $t8, $zero, L_807B8338
    if (ctx->r24 == 0) {
        // 0x807B8330: nop
    
            goto L_807B8338;
    }
    // 0x807B8330: nop

    // 0x807B8334: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
L_807B8338:
    // 0x807B8338: jr          $ra
    // 0x807B833C: nop

    return;
    // 0x807B833C: nop

;}
RECOMP_FUNC void func_80041CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041CD4: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80041CD8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80041CDC: lhu         $a2, 0xA($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0XA);
    // 0x80041CE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80041CE4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80041CE8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80041CEC: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80041CF0: lhu         $a1, 0x1200($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X1200);
    // 0x80041CF4: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80041CF8: beq         $at, $zero, L_80041D0C
    if (ctx->r1 == 0) {
        // 0x80041CFC: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80041D0C;
    }
    // 0x80041CFC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80041D00: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80041D04: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80041D08: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80041D0C:
    // 0x80041D0C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041D10: bne         $at, $zero, L_80041D24
    if (ctx->r1 != 0) {
        // 0x80041D14: nop
    
            goto L_80041D24;
    }
    // 0x80041D14: nop

    // 0x80041D18: lbu         $t9, 0x1202($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1202);
    // 0x80041D1C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80041D20: sb          $t0, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = ctx->r8;
L_80041D24:
    // 0x80041D24: jal         0x80041914
    // 0x80041D28: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    func_80041914(rdram, ctx);
        goto after_0;
    // 0x80041D28: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    after_0:
    // 0x80041D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041D34: jr          $ra
    // 0x80041D38: nop

    return;
    // 0x80041D38: nop

;}
RECOMP_FUNC void func_807A116C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A116C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807A1170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1174: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807A1178: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A117C: jal         0x8004700C
    // 0x807A1180: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807A1180: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x807A1184: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807A1188: addiu       $at, $zero, 0x403B
    ctx->r1 = ADD32(0, 0X403B);
    // 0x807A118C: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(841, 0XD54) << 16);
    // 0x807A1190: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x807A1194: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x807A1198: addiu       $t7, $t7, 0x1C94
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(841, 0XD54));
    // 0x807A119C: beq         $v1, $at, L_807A11E8
    if (ctx->r3 == ctx->r1) {
        // 0x807A11A0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_807A11E8;
    }
    // 0x807A11A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807A11A4: addiu       $at, $zero, 0x403C
    ctx->r1 = ADD32(0, 0X403C);
    // 0x807A11A8: beq         $v1, $at, L_807A11F0
    if (ctx->r3 == ctx->r1) {
        // 0x807A11AC: lui         $t8, 0x807A
        ctx->r24 = S32(RELOC_HI16(841, 0XD58) << 16);
            goto L_807A11F0;
    }
    // 0x807A11AC: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(841, 0XD58) << 16);
    // 0x807A11B0: addiu       $at, $zero, 0x403D
    ctx->r1 = ADD32(0, 0X403D);
    // 0x807A11B4: beq         $v1, $at, L_807A11FC
    if (ctx->r3 == ctx->r1) {
        // 0x807A11B8: lui         $t9, 0x807A
        ctx->r25 = S32(RELOC_HI16(841, 0XD5C) << 16);
            goto L_807A11FC;
    }
    // 0x807A11B8: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(841, 0XD5C) << 16);
    // 0x807A11BC: addiu       $at, $zero, 0x4516
    ctx->r1 = ADD32(0, 0X4516);
    // 0x807A11C0: beq         $v1, $at, L_807A1208
    if (ctx->r3 == ctx->r1) {
        // 0x807A11C4: lui         $t0, 0x807A
        ctx->r8 = S32(RELOC_HI16(841, 0XD60) << 16);
            goto L_807A1208;
    }
    // 0x807A11C4: lui         $t0, 0x807A
    ctx->r8 = S32(RELOC_HI16(841, 0XD60) << 16);
    // 0x807A11C8: addiu       $at, $zero, 0x4517
    ctx->r1 = ADD32(0, 0X4517);
    // 0x807A11CC: beq         $v1, $at, L_807A1214
    if (ctx->r3 == ctx->r1) {
        // 0x807A11D0: lui         $t1, 0x807A
        ctx->r9 = S32(RELOC_HI16(841, 0XD64) << 16);
            goto L_807A1214;
    }
    // 0x807A11D0: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(841, 0XD64) << 16);
    // 0x807A11D4: addiu       $at, $zero, 0x4518
    ctx->r1 = ADD32(0, 0X4518);
    // 0x807A11D8: beq         $v1, $at, L_807A1220
    if (ctx->r3 == ctx->r1) {
        // 0x807A11DC: lui         $t2, 0x807A
        ctx->r10 = S32(RELOC_HI16(841, 0XD68) << 16);
            goto L_807A1220;
    }
    // 0x807A11DC: lui         $t2, 0x807A
    ctx->r10 = S32(RELOC_HI16(841, 0XD68) << 16);
    // 0x807A11E0: b           L_807A1228
    // 0x807A11E4: nop

        goto L_807A1228;
    // 0x807A11E4: nop

L_807A11E8:
    // 0x807A11E8: b           L_807A1228
    // 0x807A11EC: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
        goto L_807A1228;
    // 0x807A11EC: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
L_807A11F0:
    // 0x807A11F0: addiu       $t8, $t8, 0x1C98
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(841, 0XD58));
    // 0x807A11F4: b           L_807A1228
    // 0x807A11F8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
        goto L_807A1228;
    // 0x807A11F8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_807A11FC:
    // 0x807A11FC: addiu       $t9, $t9, 0x1C9C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(841, 0XD5C));
    // 0x807A1200: b           L_807A1228
    // 0x807A1204: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
        goto L_807A1228;
    // 0x807A1204: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
L_807A1208:
    // 0x807A1208: addiu       $t0, $t0, 0x1CA0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(841, 0XD60));
    // 0x807A120C: b           L_807A1228
    // 0x807A1210: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
        goto L_807A1228;
    // 0x807A1210: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
L_807A1214:
    // 0x807A1214: addiu       $t1, $t1, 0x1CA4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(841, 0XD64));
    // 0x807A1218: b           L_807A1228
    // 0x807A121C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
        goto L_807A1228;
    // 0x807A121C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
L_807A1220:
    // 0x807A1220: addiu       $t2, $t2, 0x1CA8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(841, 0XD68));
    // 0x807A1224: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
L_807A1228:
    // 0x807A1228: beq         $v0, $zero, L_807A1258
    if (ctx->r2 == 0) {
        // 0x807A122C: sb          $zero, 0xC($a1)
        MEM_B(0XC, ctx->r5) = 0;
            goto L_807A1258;
    }
    // 0x807A122C: sb          $zero, 0xC($a1)
    MEM_B(0XC, ctx->r5) = 0;
    // 0x807A1230: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807A1234: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807A1238: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807A123C: nop

    // 0x807A1240: bc1f        L_807A1250
    if (!c1cs) {
        // 0x807A1244: nop
    
            goto L_807A1250;
    }
    // 0x807A1244: nop

    // 0x807A1248: b           L_807A125C
    // 0x807A124C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_807A125C;
    // 0x807A124C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_807A1250:
    // 0x807A1250: b           L_807A125C
    // 0x807A1254: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_807A125C;
    // 0x807A1254: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_807A1258:
    // 0x807A1258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_807A125C:
    // 0x807A125C: jal         0x807A1AE4
    // 0x807A1260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A1AE4(rdram, ctx);
        goto after_1;
    // 0x807A1260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807A1264: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807A1268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807A126C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A1270: jal         0x807A0FFC
    // 0x807A1274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A0FFC(rdram, ctx);
        goto after_2;
    // 0x807A1274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x807A1278: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x807A127C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A1280: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807A1284: nop

    // 0x807A1288: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x807A128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807A1294: jr          $ra
    // 0x807A1298: nop

    return;
    // 0x807A1298: nop

;}
RECOMP_FUNC void func_800528A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800528A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800528AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800528B0: jal         0x80064D1C
    // 0x800528B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x800528B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x800528B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800528BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800528C0: jr          $ra
    // 0x800528C4: nop

    return;
    // 0x800528C4: nop

;}
RECOMP_FUNC void func_8043F93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F93C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043F940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F944: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F94C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8043F950: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8043F954: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F958: jal         0x80442188
    // 0x8043F95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043F960: jal         0x8043F42C
    // 0x8043F964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8043F42C(rdram, ctx);
        goto after_1;
    // 0x8043F964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8043F968: jal         0x8043F240
    // 0x8043F96C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8043F240(rdram, ctx);
        goto after_2;
    // 0x8043F96C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8043F970: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EAC) << 16);
    // 0x8043F974: lwc1        $f0, 0x3DAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EAC));
    // 0x8043F978: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F97C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EB0) << 16);
    // 0x8043F980: swc1        $f0, 0x1C24($v0)
    MEM_W(0X1C24, ctx->r2) = ctx->f0.u32l;
    // 0x8043F984: swc1        $f0, 0x1C28($v0)
    MEM_W(0X1C28, ctx->r2) = ctx->f0.u32l;
    // 0x8043F988: lwc1        $f4, 0x3DB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EB0));
    // 0x8043F98C: swc1        $f4, 0x1C2C($v0)
    MEM_W(0X1C2C, ctx->r2) = ctx->f4.u32l;
    // 0x8043F990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043F998: jr          $ra
    // 0x8043F99C: nop

    return;
    // 0x8043F99C: nop

;}
RECOMP_FUNC void func_806D3628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3628: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806D362C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806D3630: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806D3634: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x806D3638: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806D363C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D3640: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x806D3644: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x806D3648: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D364C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D3650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D3654: jal         0x806D30C4
    // 0x806D3658: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_806D30C4(rdram, ctx);
        goto after_0;
    // 0x806D3658: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x806D365C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x806D3660: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x806D3664: slti        $at, $t9, 0x15
    ctx->r1 = SIGNED(ctx->r25) < 0X15 ? 1 : 0;
    // 0x806D3668: bne         $at, $zero, L_806D36B0
    if (ctx->r1 != 0) {
        // 0x806D366C: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_806D36B0;
    }
    // 0x806D366C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x806D3670: jal         0x8004A73C
    // 0x806D3674: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8004A73C(rdram, ctx);
        goto after_1;
    // 0x806D3674: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x806D3678: jal         0x8005FDC4
    // 0x806D367C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x806D367C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D3680: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x806D3684: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x806D3688: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x806D368C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x806D3690: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x806D3694: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x806D3698: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x806D369C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D36A0: jal         0x806D414C
    // 0x806D36A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D414C(rdram, ctx);
        goto after_3;
    // 0x806D36A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806D36A8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x806D36AC: sw          $zero, 0x28($t1)
    MEM_W(0X28, ctx->r9) = 0;
L_806D36B0:
    // 0x806D36B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806D36B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806D36B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806D36BC: jr          $ra
    // 0x806D36C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806D36C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8047012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047012C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470130: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x80470134: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80470138: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8047013C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80470140: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80470144: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80470148: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8047014C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80470150: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470154: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80470158: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8047015C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80470160: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80470164: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80470168: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8047016C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470170: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x80470174: ori         $t4, $zero, 0xA080
    ctx->r12 = 0 | 0XA080;
    // 0x80470178: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8047017C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80470180: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80470184: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470188: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8047018C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80470190: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x80470194: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80470198: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8047019C: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x804701A0: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x804701A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804701A8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804701AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804701B0: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x804701B4: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x804701B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804701BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804701C0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804701C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804701C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804701CC: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x804701D0: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x804701D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804701D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804701DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804701E0: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x804701E4: lbu         $t3, 0x10($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X10);
    // 0x804701E8: lbu         $t9, 0xE($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XE);
    // 0x804701EC: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x804701F0: lbu         $t5, 0xF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF);
    // 0x804701F4: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x804701F8: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x804701FC: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x80470200: sll         $t3, $t5, 8
    ctx->r11 = S32(ctx->r13 << 8);
    // 0x80470204: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x80470208: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8047020C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470210: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x80470214: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x80470218: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8047021C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80470220: ori         $t9, $t9, 0x9623
    ctx->r25 = ctx->r25 | 0X9623;
    // 0x80470224: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80470228: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8047022C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80470230: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470234: addiu       $t5, $zero, 0x204
    ctx->r13 = ADD32(0, 0X204);
    // 0x80470238: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8047023C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80470240: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80470244: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80470248: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8047024C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80470250: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x80470254: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80470258: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8047025C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80470260: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80470264: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x80470268: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8047026C: jr          $ra
    // 0x80470270: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    return;
    // 0x80470270: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_806E9144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9144: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806E9148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x806E914C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x806E9150: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x806E9154: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x806E9158: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x806E915C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806E9160: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806E9164: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E9168: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806E916C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806E9170: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806E9174: sw          $zero, 0x454($s3)
    MEM_W(0X454, ctx->r19) = 0;
    // 0x806E9178: sw          $zero, 0x450($s3)
    MEM_W(0X450, ctx->r19) = 0;
    // 0x806E917C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_806E9180:
    // 0x806E9180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806E9184: slti        $at, $s0, 0x2E
    ctx->r1 = SIGNED(ctx->r16) < 0X2E ? 1 : 0;
    // 0x806E9188: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806E918C: bne         $at, $zero, L_806E9180
    if (ctx->r1 != 0) {
        // 0x806E9190: swc1        $f20, 0x454($s1)
        MEM_W(0X454, ctx->r17) = ctx->f20.u32l;
            goto L_806E9180;
    }
    // 0x806E9190: swc1        $f20, 0x454($s1)
    MEM_W(0X454, ctx->r17) = ctx->f20.u32l;
    // 0x806E9194: sh          $zero, 0x5C8($s3)
    MEM_H(0X5C8, ctx->r19) = 0;
    // 0x806E9198: swc1        $f20, 0x5CC($s3)
    MEM_W(0X5CC, ctx->r19) = ctx->f20.u32l;
    // 0x806E919C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806E91A0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x806E91A4: addiu       $s2, $zero, 0x2E
    ctx->r18 = ADD32(0, 0X2E);
L_806E91A8:
    // 0x806E91A8: jal         0x806E83E0
    // 0x806E91AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E83E0(rdram, ctx);
        goto after_0;
    // 0x806E91AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x806E91B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806E91B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806E91B8: bne         $s0, $s2, L_806E91A8
    if (ctx->r16 != ctx->r18) {
        // 0x806E91BC: swc1        $f0, 0x50C($s1)
        MEM_W(0X50C, ctx->r17) = ctx->f0.u32l;
            goto L_806E91A8;
    }
    // 0x806E91BC: swc1        $f0, 0x50C($s1)
    MEM_W(0X50C, ctx->r17) = ctx->f0.u32l;
    // 0x806E91C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E91C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E91C8: lui         $at, 0xC238
    ctx->r1 = S32(0XC238 << 16);
    // 0x806E91CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E91D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806E91D4: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x806E91D8: swc1        $f4, 0x5D0($s3)
    MEM_W(0X5D0, ctx->r19) = ctx->f4.u32l;
    // 0x806E91DC: swc1        $f6, 0x5D4($s3)
    MEM_W(0X5D4, ctx->r19) = ctx->f6.u32l;
    // 0x806E91E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_806E91E4:
    // 0x806E91E4: jal         0x806E8990
    // 0x806E91E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806E8990(rdram, ctx);
        goto after_1;
    // 0x806E91E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x806E91EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806E91F0: bnel        $s0, $s1, L_806E91E4
    if (ctx->r16 != ctx->r17) {
        // 0x806E91F4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_806E91E4;
    }
    goto skip_0;
    // 0x806E91F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x806E91F8: jal         0x80047090
    // 0x806E91FC: addiu       $a0, $zero, 0x45D0
    ctx->r4 = ADD32(0, 0X45D0);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x806E91FC: addiu       $a0, $zero, 0x45D0
    ctx->r4 = ADD32(0, 0X45D0);
    after_2:
    // 0x806E9200: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806E9204: bne         $v0, $at, L_806E9214
    if (ctx->r2 != ctx->r1) {
        // 0x806E9208: andi        $s1, $v0, 0xFFFF
        ctx->r17 = ctx->r2 & 0XFFFF;
            goto L_806E9214;
    }
    // 0x806E9208: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x806E920C: b           L_806E9234
    // 0x806E9210: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_806E9234;
    // 0x806E9210: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806E9214:
    // 0x806E9214: lui         $a0, 0x45D0
    ctx->r4 = S32(0X45D0 << 16);
    // 0x806E9218: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806E921C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E9220: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x806E9224: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x806E9228: jal         0x8004613C
    // 0x806E922C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x806E922C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    after_3:
    // 0x806E9230: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_806E9234:
    // 0x806E9234: beq         $s0, $zero, L_806E926C
    if (ctx->r16 == 0) {
        // 0x806E9238: andi        $t7, $s1, 0x3FF
        ctx->r15 = ctx->r17 & 0X3FF;
            goto L_806E926C;
    }
    // 0x806E9238: andi        $t7, $s1, 0x3FF
    ctx->r15 = ctx->r17 & 0X3FF;
    // 0x806E923C: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x806E9240: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E9244: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806E9248: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806E924C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806E9250: jal         0x80047F9C
    // 0x806E9254: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x806E9254: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    after_4:
    // 0x806E9258: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806E925C: jal         0x806E9858
    // 0x806E9260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E9858(rdram, ctx);
        goto after_5;
    // 0x806E9260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806E9264: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x806E9268: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
L_806E926C:
    // 0x806E926C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x806E9270: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E9274: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806E9278: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x806E927C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x806E9280: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x806E9284: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x806E9288: jr          $ra
    // 0x806E928C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806E928C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8076063C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076063C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760640: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760644: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760648: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076064C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760650: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760654: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760658: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076065C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760660: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760664: jr          $ra
    // 0x80760668: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760668: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B1224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B1228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B122C: jal         0x8004700C
    // 0x806B1230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B1230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B1234: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B1238: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806B123C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1240: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(598, 0X10C0) << 16);
    // 0x806B1244: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806B1248: addiu       $t7, $t7, 0x1050
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(598, 0X10C0));
    // 0x806B124C: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x806B1250: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806B1254: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806B1258: beq         $v0, $zero, L_806B1298
    if (ctx->r2 == 0) {
        // 0x806B125C: swc1        $f4, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
            goto L_806B1298;
    }
    // 0x806B125C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x806B1260: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806B1264: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806B1268: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x806B126C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16F8) << 16);
    // 0x806B1270: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806B1274: nop

    // 0x806B1278: bc1fl       L_806B1288
    if (!c1cs) {
        // 0x806B127C: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_806B1288;
    }
    goto skip_0;
    // 0x806B127C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    skip_0:
    // 0x806B1280: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806B1284: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
L_806B1288:
    // 0x806B1288: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x806B128C: lwc1        $f10, 0x1688($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16F8));
    // 0x806B1290: b           L_806B12A4
    // 0x806B1294: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
        goto L_806B12A4;
    // 0x806B1294: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
L_806B1298:
    // 0x806B1298: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806B129C: nop

    // 0x806B12A0: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
L_806B12A4:
    // 0x806B12A4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x806B12A8: jal         0x8005FA94
    // 0x806B12AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005FA94(rdram, ctx);
        goto after_1;
    // 0x806B12AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x806B12B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806B12B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B12B8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806B12BC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x806B12C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806B12C4: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x806B12C8: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x806B12CC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x806B12D0: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x806B12D4: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1780) << 16);
    // 0x806B12D8: sh          $zero, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = 0;
    // 0x806B12DC: sw          $t2, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r10;
    // 0x806B12E0: swc1        $f18, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f18.u32l;
    // 0x806B12E4: lwc1        $f4, 0x1710($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1780));
    // 0x806B12E8: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x806B12EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B12F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B12F4: jr          $ra
    // 0x806B12F8: nop

    return;
    // 0x806B12F8: nop

;}
RECOMP_FUNC void func_806F6DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6DDC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F6DE0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F6DE4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F6DE8: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(691, 0X878) << 16);
    // 0x806F6DEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F6DF0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F6DF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F6DF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F6DFC: lw          $t8, 0x7608($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(691, 0X878));
    // 0x806F6E00: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F6E04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F6E08: jal         0x80048490
    // 0x806F6E0C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F6E0C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F6E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6E18: jr          $ra
    // 0x806F6E1C: nop

    return;
    // 0x806F6E1C: nop

;}
RECOMP_FUNC void func_8071531C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071531C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80715320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80715324: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80715328: jal         0x80714DD4
    // 0x8071532C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x8071532C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80715330: jal         0x80714E64
    // 0x80715334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x80715334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80715338: jal         0x80714D40
    // 0x8071533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x8071533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80715340: jal         0x80714B20
    // 0x80715344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714B20(rdram, ctx);
        goto after_3;
    // 0x80715344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80715348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8071534C: bne         $v0, $at, L_80715364
    if (ctx->r2 != ctx->r1) {
        // 0x80715350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80715364;
    }
    // 0x80715350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80715354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80715358: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8071535C: jal         0x80715C24
    // 0x80715360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80715C24(rdram, ctx);
        goto after_4;
    // 0x80715360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
L_80715364:
    // 0x80715364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80715368: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8071536C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80715370: jr          $ra
    // 0x80715374: nop

    return;
    // 0x80715374: nop

;}
RECOMP_FUNC void func_80445978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044597C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445980: jal         0x80067D28
    // 0x80445984: nop

    func_80067D28(rdram, ctx);
        goto after_0;
    // 0x80445984: nop

    after_0:
    // 0x80445988: addiu       $a0, $zero, 0x22A
    ctx->r4 = ADD32(0, 0X22A);
    // 0x8044598C: jal         0x80067818
    // 0x80445990: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80445990: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80445994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044599C: jr          $ra
    // 0x804459A0: nop

    return;
    // 0x804459A0: nop

;}
RECOMP_FUNC void func_8043F914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F91C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F924: jal         0x80442188
    // 0x8043F928: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F928: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8043F92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F934: jr          $ra
    // 0x8043F938: nop

    return;
    // 0x8043F938: nop

;}
RECOMP_FUNC void func_8057C4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C4E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C4E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C4E8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8057C4EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8057C4F0: jal         0x8057BB68
    // 0x8057C4F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C4F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8057C4F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C4FC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8057C500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8057C504: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8057C508: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8057C50C: bne         $t6, $at, L_8057C520
    if (ctx->r14 != ctx->r1) {
        // 0x8057C510: nop
    
            goto L_8057C520;
    }
    // 0x8057C510: nop

    // 0x8057C514: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x8057C518: b           L_8057C520
    // 0x8057C51C: lw          $v1, 0x78($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X78);
        goto L_8057C520;
    // 0x8057C51C: lw          $v1, 0x78($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X78);
L_8057C520:
    // 0x8057C520: beql        $v1, $zero, L_8057C584
    if (ctx->r3 == 0) {
        // 0x8057C524: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057C584;
    }
    goto skip_0;
    // 0x8057C524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057C528: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    // 0x8057C52C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8057C530: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057C534: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057C538: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057C53C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057C540: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8057C544: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057C548: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8057C54C: lwc1        $f16, 0x88($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8057C550: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057C554: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x8057C558: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8057C55C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057C560: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x8057C564: lw          $t8, 0xEE0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEE0);
    // 0x8057C568: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8057C56C: sw          $t9, 0xEE0($v1)
    MEM_W(0XEE0, ctx->r3) = ctx->r25;
    // 0x8057C570: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8057C574: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8057C578: jal         0x8057C6B0
    // 0x8057C57C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_8057C6B0(rdram, ctx);
        goto after_1;
    // 0x8057C57C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x8057C580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057C584:
    // 0x8057C584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C588: jr          $ra
    // 0x8057C58C: nop

    return;
    // 0x8057C58C: nop

;}
RECOMP_FUNC void func_804235A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804235A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804235AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804235B0: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x804235B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804235B8: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    // 0x804235BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804235C0: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
    // 0x804235C4: jal         0x80065490
    // 0x804235C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x804235C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804235CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804235D0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804235D4: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x804235D8: lwc1        $f4, 0x9C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X9C);
    // 0x804235DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x804235E0: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x804235E4: lw          $t7, 0x1F4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1F4);
    // 0x804235E8: lwc1        $f8, 0x6C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x804235EC: lwc1        $f10, 0x90($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X90);
    // 0x804235F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804235F4: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
    // 0x804235F8: lw          $t8, 0x1F4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1F4);
    // 0x804235FC: lwc1        $f18, 0x70($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X70);
    // 0x80423600: lwc1        $f4, 0x94($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X94);
    // 0x80423604: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80423608: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x8042360C: lw          $t9, 0x1F4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1F4);
    // 0x80423610: lwc1        $f8, 0x74($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X74);
    // 0x80423614: lwc1        $f10, 0x98($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X98);
    // 0x80423618: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8042361C: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x80423620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80423628: jr          $ra
    // 0x8042362C: nop

    return;
    // 0x8042362C: nop

;}
RECOMP_FUNC void func_800578D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800578D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800578D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800578DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800578E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800578E4: jal         0x80047090
    // 0x800578E8: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x800578E8: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_0:
    // 0x800578EC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x800578F0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800578F4: jal         0x80047AB8
    // 0x800578F8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x800578F8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800578FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80057900: lwc1        $f6, 0xB50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB50);
    // 0x80057904: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80057908: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x8005790C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80057910: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057914: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80057918: ori         $a0, $a0, 0x1C00
    ctx->r4 = ctx->r4 | 0X1C00;
    // 0x8005791C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80057920: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80057924: jal         0x8004613C
    // 0x80057928: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x80057928: nop

    after_2:
    // 0x8005792C: beq         $v0, $zero, L_80057964
    if (ctx->r2 == 0) {
        // 0x80057930: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80057964;
    }
    // 0x80057930: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80057934: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x80057938: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8005793C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80057940: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80057944: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80057948: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x8005794C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80057950: jal         0x80047F9C
    // 0x80057954: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80057954: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80057958: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8005795C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80057960: sb          $t2, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r10;
L_80057964:
    // 0x80057964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057968: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005796C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80057970: jr          $ra
    // 0x80057974: nop

    return;
    // 0x80057974: nop

;}
RECOMP_FUNC void func_8005C884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C88C: jal         0x8005C4CC
    // 0x8005C890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005C4CC(rdram, ctx);
        goto after_0;
    // 0x8005C890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C894: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8005C898: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8005C89C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005C8A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C8A4: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x8005C8A8: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8005C8AC: beq         $t7, $at, L_8005C8C0
    if (ctx->r15 == ctx->r1) {
        // 0x8005C8B0: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_8005C8C0;
    }
    // 0x8005C8B0: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x8005C8B4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8005C8B8: bnel        $t8, $at, L_8005C8D8
    if (ctx->r24 != ctx->r1) {
        // 0x8005C8BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005C8D8;
    }
    goto skip_0;
    // 0x8005C8BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8005C8C0:
    // 0x8005C8C0: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x8005C8C4: beql        $t9, $zero, L_8005C8D8
    if (ctx->r25 == 0) {
        // 0x8005C8C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005C8D8;
    }
    goto skip_1;
    // 0x8005C8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005C8CC: jal         0x8005D110
    // 0x8005C8D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8005D110(rdram, ctx);
        goto after_1;
    // 0x8005C8D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8005C8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005C8D8:
    // 0x8005C8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C8DC: jr          $ra
    // 0x8005C8E0: nop

    return;
    // 0x8005C8E0: nop

;}
RECOMP_FUNC void func_80020CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020CE4: lbu         $v0, 0xDF($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XDF);
    // 0x80020CE8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80020CEC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80020CF0: bne         $v0, $at, L_80020DA8
    if (ctx->r2 != ctx->r1) {
        // 0x80020CF4: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80020DA8;
    }
    // 0x80020CF4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80020CF8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80020CFC: lbu         $t8, 0x5C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5C);
    // 0x80020D00: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80020D04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80020D08: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80020D0C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80020D10: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80020D14: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80020D18: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x80020D1C: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80020D20: lbu         $t4, 0x4($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4);
    // 0x80020D24: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x80020D28: beq         $t3, $zero, L_80020DA0
    if (ctx->r11 == 0) {
        // 0x80020D2C: srl         $t5, $t4, 3
        ctx->r13 = S32(U32(ctx->r12) >> 3);
            goto L_80020DA0;
    }
    // 0x80020D2C: srl         $t5, $t4, 3
    ctx->r13 = S32(U32(ctx->r12) >> 3);
    // 0x80020D30: sltiu       $at, $t5, 0x10
    ctx->r1 = ctx->r13 < 0X10 ? 1 : 0;
    // 0x80020D34: beq         $at, $zero, L_80020D98
    if (ctx->r1 == 0) {
        // 0x80020D38: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80020D98;
    }
    // 0x80020D38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80020D3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80020D40: addu        $at, $at, $t5
    gpr jr_addend_80020D48 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80020D44: lw          $t5, -0x3F4($at)
    ctx->r13 = ADD32(ctx->r1, -0X3F4);
    // 0x80020D48: jr          $t5
    // 0x80020D4C: nop

    switch (jr_addend_80020D48 >> 2) {
        case 0: goto L_80020D50; break;
        case 1: goto L_80020D58; break;
        case 2: goto L_80020D60; break;
        case 3: goto L_80020D98; break;
        case 4: goto L_80020D98; break;
        case 5: goto L_80020D98; break;
        case 6: goto L_80020D98; break;
        case 7: goto L_80020D98; break;
        case 8: goto L_80020D98; break;
        case 9: goto L_80020D68; break;
        case 10: goto L_80020D70; break;
        case 11: goto L_80020D78; break;
        case 12: goto L_80020D98; break;
        case 13: goto L_80020D80; break;
        case 14: goto L_80020D88; break;
        case 15: goto L_80020D90; break;
        default: switch_error(__func__, 0x80020D48, 0x800AFC0C);
    }
    // 0x80020D4C: nop

L_80020D50:
    // 0x80020D50: b           L_80020DB0
    // 0x80020D54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80020DB0;
    // 0x80020D54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80020D58:
    // 0x80020D58: b           L_80020DB0
    // 0x80020D5C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80020DB0;
    // 0x80020D5C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80020D60:
    // 0x80020D60: b           L_80020DB0
    // 0x80020D64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80020DB0;
    // 0x80020D64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80020D68:
    // 0x80020D68: b           L_80020DB0
    // 0x80020D6C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_80020DB0;
    // 0x80020D6C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80020D70:
    // 0x80020D70: b           L_80020DB0
    // 0x80020D74: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_80020DB0;
    // 0x80020D74: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_80020D78:
    // 0x80020D78: b           L_80020DB0
    // 0x80020D7C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_80020DB0;
    // 0x80020D7C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80020D80:
    // 0x80020D80: b           L_80020DB0
    // 0x80020D84: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
        goto L_80020DB0;
    // 0x80020D84: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80020D88:
    // 0x80020D88: b           L_80020DB0
    // 0x80020D8C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_80020DB0;
    // 0x80020D8C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_80020D90:
    // 0x80020D90: b           L_80020DB0
    // 0x80020D94: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
        goto L_80020DB0;
    // 0x80020D94: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_80020D98:
    // 0x80020D98: b           L_80020DB0
    // 0x80020D9C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80020DB0;
    // 0x80020D9C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80020DA0:
    // 0x80020DA0: b           L_80020DB0
    // 0x80020DA4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80020DB0;
    // 0x80020DA4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80020DA8:
    // 0x80020DA8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80020DAC: sb          $t6, 0xDF($a0)
    MEM_B(0XDF, ctx->r4) = ctx->r14;
L_80020DB0:
    // 0x80020DB0: sb          $v1, 0xDE($a0)
    MEM_B(0XDE, ctx->r4) = ctx->r3;
    // 0x80020DB4: jr          $ra
    // 0x80020DB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80020DB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_806FD95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD964: jal         0x8004700C
    // 0x806FD968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806FD968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FD96C: bne         $v0, $zero, L_806FD97C
    if (ctx->r2 != 0) {
        // 0x806FD970: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806FD97C;
    }
    // 0x806FD970: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806FD974: b           L_806FD9B4
    // 0x806FD978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD9B4;
    // 0x806FD978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FD97C:
    // 0x806FD97C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806FD980: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806FD984: lwc1        $f4, 0x84($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X84);
    // 0x806FD988: jal         0x80065954
    // 0x806FD98C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x806FD98C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x806FD990: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x806FD994: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FD998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD99C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806FD9A0: nop

    // 0x806FD9A4: bc1f        L_806FD9B4
    if (!c1cs) {
        // 0x806FD9A8: nop
    
            goto L_806FD9B4;
    }
    // 0x806FD9A8: nop

    // 0x806FD9AC: b           L_806FD9B4
    // 0x806FD9B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FD9B4;
    // 0x806FD9B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FD9B4:
    // 0x806FD9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD9B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD9BC: jr          $ra
    // 0x806FD9C0: nop

    return;
    // 0x806FD9C0: nop

;}
RECOMP_FUNC void func_806F5FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F5FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5FB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F5FB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806F5FB8: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806F5FBC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806F5FC0: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x806F5FC4: bne         $t6, $at, L_806F5FFC
    if (ctx->r14 != ctx->r1) {
        // 0x806F5FC8: addiu       $at, $zero, 0x4001
        ctx->r1 = ADD32(0, 0X4001);
            goto L_806F5FFC;
    }
    // 0x806F5FC8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F5FCC: beq         $v1, $at, L_806F5FFC
    if (ctx->r3 == ctx->r1) {
        // 0x806F5FD0: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_806F5FFC;
    }
    // 0x806F5FD0: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806F5FD4: bne         $v1, $at, L_806F5FF8
    if (ctx->r3 != ctx->r1) {
        // 0x806F5FD8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_806F5FF8;
    }
    // 0x806F5FD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806F5FDC: jal         0x806F5DFC
    // 0x806F5FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F5DFC(rdram, ctx);
        goto after_0;
    // 0x806F5FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F5FE4: beq         $v0, $zero, L_806F5FFC
    if (ctx->r2 == 0) {
        // 0x806F5FE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806F5FFC;
    }
    // 0x806F5FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F5FEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806F5FF0: b           L_806F5FFC
    // 0x806F5FF4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
        goto L_806F5FFC;
    // 0x806F5FF4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_806F5FF8:
    // 0x806F5FF8: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_806F5FFC:
    // 0x806F5FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6004: jr          $ra
    // 0x806F6008: nop

    return;
    // 0x806F6008: nop

;}
RECOMP_FUNC void func_806E72A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E72A0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E72A4: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(664, 0X334) << 16);
    // 0x806E72A8: addiu       $t6, $t6, 0x7574
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(664, 0X334));
    // 0x806E72AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E72B0: jr          $ra
    // 0x806E72B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806E72B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80430174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430174: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430178: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043017C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BD0) << 16);
    // 0x80430180: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80430184: lwc1        $f8, 0x1CB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BD0));
    // 0x80430188: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043018C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80430190: jr          $ra
    // 0x80430194: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80430194: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
;}
