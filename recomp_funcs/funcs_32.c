#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804527B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804527B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804527B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804527B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804527BC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804527C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804527C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804527C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804527CC: sw          $a1, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r5;
    // 0x804527D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804527D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804527D8: swc1        $f0, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f0.u32l;
    // 0x804527DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804527E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804527E4: swc1        $f0, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->f0.u32l;
    // 0x804527E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804527EC: jal         0x80444C94
    // 0x804527F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80444C94(rdram, ctx);
        goto after_0;
    // 0x804527F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804527F4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804527F8: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x804527FC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80452800: jal         0x8044FE40
    // 0x80452804: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    func_8044FE40(rdram, ctx);
        goto after_1;
    // 0x80452804: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    after_1:
    // 0x80452808: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045280C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80452810: jal         0x8044FE64
    // 0x80452814: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8044FE64(rdram, ctx);
        goto after_2;
    // 0x80452814: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80452818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045281C: jal         0x80445858
    // 0x80452820: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80445858(rdram, ctx);
        goto after_3;
    // 0x80452820: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80452824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045282C: jr          $ra
    // 0x80452830: nop

    return;
    // 0x80452830: nop

;}
RECOMP_FUNC void func_80456090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456090: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80456094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80456098: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8045609C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804560A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804560A4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x804560A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804560AC: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x804560B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804560B4: jal         0x8044EFA0
    // 0x804560B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804560B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x804560BC: jal         0x804449C0
    // 0x804560C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x804560C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804560C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804560C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804560CC: jal         0x80450490
    // 0x804560D0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x804560D0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x804560D4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x804560D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804560DC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x804560E0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804560E4: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x804560E8: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D58) << 16);
    // 0x804560EC: lw          $t9, -0x7EC8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D58));
    // 0x804560F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804560F4: jalr        $t9
    // 0x804560F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804560F8: nop

    after_3:
    // 0x804560FC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80456100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80456104: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456108: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8045610C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80456114: jal         0x80455D88
    // 0x80456118: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80455D88(rdram, ctx);
        goto after_4;
    // 0x80456118: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x8045611C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80456120: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80456124: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456128: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8045612C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80456134: jal         0x80455D88
    // 0x80456138: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    func_80455D88(rdram, ctx);
        goto after_5;
    // 0x80456138: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x8045613C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80456140: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80456144: lw          $t2, 0xFB8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XFB8);
    // 0x80456148: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8045614C: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80456150: bnel        $t4, $zero, L_8045627C
    if (ctx->r12 != 0) {
        // 0x80456154: lbu         $v0, 0xF5D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
            goto L_8045627C;
    }
    goto skip_0;
    // 0x80456154: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    skip_0:
    // 0x80456158: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    // 0x8045615C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456160: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456164: bne         $v0, $zero, L_804561A4
    if (ctx->r2 != 0) {
        // 0x80456168: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804561A4;
    }
    // 0x80456168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045616C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14158) << 16);
    // 0x80456170: lwc1        $f0, -0x7AC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14158));
    // 0x80456174: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456178: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8045617C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1415C) << 16);
    // 0x80456180: lwc1        $f10, -0x7AC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1415C));
    // 0x80456184: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80456188: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x8045618C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456190: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456194: jal         0x80444B28
    // 0x80456198: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_6;
    // 0x80456198: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8045619C: b           L_80456374
    // 0x804561A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x804561A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804561A4:
    // 0x804561A4: bne         $v0, $at, L_804561E8
    if (ctx->r2 != ctx->r1) {
        // 0x804561A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804561E8;
    }
    // 0x804561A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804561AC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14160) << 16);
    // 0x804561B0: lwc1        $f0, -0x7AC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14160));
    // 0x804561B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804561B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804561BC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14164) << 16);
    // 0x804561C0: lwc1        $f18, -0x7ABC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14164));
    // 0x804561C4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804561C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x804561CC: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x804561D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804561D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x804561D8: jal         0x80444B28
    // 0x804561DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_7;
    // 0x804561DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x804561E0: b           L_80456374
    // 0x804561E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x804561E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804561E8:
    // 0x804561E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804561EC: bne         $v0, $at, L_80456230
    if (ctx->r2 != ctx->r1) {
        // 0x804561F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456230;
    }
    // 0x804561F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804561F4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14168) << 16);
    // 0x804561F8: lwc1        $f0, -0x7AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14168));
    // 0x804561FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456204: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1416C) << 16);
    // 0x80456208: lwc1        $f6, -0x7AB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1416C));
    // 0x8045620C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456210: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80456214: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456218: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8045621C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80456220: jal         0x80444B28
    // 0x80456224: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_8;
    // 0x80456224: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80456228: b           L_80456374
    // 0x8045622C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x8045622C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456230:
    // 0x80456230: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456234: bne         $v0, $at, L_80456370
    if (ctx->r2 != ctx->r1) {
        // 0x80456238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456370;
    }
    // 0x80456238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045623C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14170) << 16);
    // 0x80456240: lwc1        $f0, -0x7AB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14170));
    // 0x80456244: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456248: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8045624C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14174) << 16);
    // 0x80456250: lwc1        $f10, -0x7AAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14174));
    // 0x80456254: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456258: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8045625C: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456260: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456264: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456268: jal         0x80444B28
    // 0x8045626C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_9;
    // 0x8045626C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80456270: b           L_80456374
    // 0x80456274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x80456274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80456278: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
L_8045627C:
    // 0x8045627C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456280: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456284: bne         $v0, $zero, L_804562BC
    if (ctx->r2 != 0) {
        // 0x80456288: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804562BC;
    }
    // 0x80456288: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045628C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14178) << 16);
    // 0x80456290: lwc1        $f0, -0x7AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14178));
    // 0x80456294: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456298: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8045629C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x804562A0: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x804562A4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804562A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804562AC: jal         0x80444B28
    // 0x804562B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_10;
    // 0x804562B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x804562B4: b           L_80456374
    // 0x804562B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x804562B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804562BC:
    // 0x804562BC: bne         $v0, $at, L_804562F8
    if (ctx->r2 != ctx->r1) {
        // 0x804562C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804562F8;
    }
    // 0x804562C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804562C4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1417C) << 16);
    // 0x804562C8: lwc1        $f0, -0x7AA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1417C));
    // 0x804562CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804562D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804562D4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804562D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x804562DC: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x804562E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804562E4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804562E8: jal         0x80444B28
    // 0x804562EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_11;
    // 0x804562EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x804562F0: b           L_80456374
    // 0x804562F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x804562F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804562F8:
    // 0x804562F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804562FC: bne         $v0, $at, L_80456338
    if (ctx->r2 != ctx->r1) {
        // 0x80456300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456338;
    }
    // 0x80456300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456304: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14180) << 16);
    // 0x80456308: lwc1        $f0, -0x7AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14180));
    // 0x8045630C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456314: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456318: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8045631C: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456320: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456324: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456328: jal         0x80444B28
    // 0x8045632C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_12;
    // 0x8045632C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80456330: b           L_80456374
    // 0x80456334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456374;
    // 0x80456334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456338:
    // 0x80456338: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8045633C: bne         $v0, $at, L_80456370
    if (ctx->r2 != ctx->r1) {
        // 0x80456340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456370;
    }
    // 0x80456340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456344: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14184) << 16);
    // 0x80456348: lwc1        $f0, -0x7A9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14184));
    // 0x8045634C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456350: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80456354: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456358: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8045635C: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456360: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456364: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456368: jal         0x80444B28
    // 0x8045636C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_13;
    // 0x8045636C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
L_80456370:
    // 0x80456370: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456374:
    // 0x80456374: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80456378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8045637C: jr          $ra
    // 0x80456380: nop

    return;
    // 0x80456380: nop

;}
RECOMP_FUNC void func_8006B308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B308: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006B30C: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006B310: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006B314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B318: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8006B31C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006B320: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006B324: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006B328: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8006B32C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006B330: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B334: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006B338: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006B33C: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x8006B340: jal         0x8006A99C
    // 0x8006B344: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8006B344: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8006B348: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006B34C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8006B350: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006B354: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8006B358: nop

    // 0x8006B35C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B360: jal         0x8006A99C
    // 0x8006B364: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8006B364: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8006B368: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8006B36C: addiu       $a1, $sp, 0x2B
    ctx->r5 = ADD32(ctx->r29, 0X2B);
    // 0x8006B370: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    // 0x8006B374: lh          $a3, 0x26($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X26);
    // 0x8006B378: jal         0x8006AA74
    // 0x8006B37C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8006AA74(rdram, ctx);
        goto after_2;
    // 0x8006B37C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8006B380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B384: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006B388: jr          $ra
    // 0x8006B38C: nop

    return;
    // 0x8006B38C: nop

;}
RECOMP_FUNC void func_80447490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447494: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447498: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044749C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804474A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804474A4: bne         $a2, $zero, L_804474CC
    if (ctx->r6 != 0) {
        // 0x804474A8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804474CC;
    }
    // 0x804474A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804474AC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x804474B0: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804474B4: bgtz        $t7, L_8044750C
    if (SIGNED(ctx->r15) > 0) {
        // 0x804474B8: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8044750C;
    }
    // 0x804474B8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804474BC: jal         0x8044602C
    // 0x804474C0: nop

    func_8044602C(rdram, ctx);
        goto after_0;
    // 0x804474C0: nop

    after_0:
    // 0x804474C4: b           L_80447510
    // 0x804474C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80447510;
    // 0x804474C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804474CC:
    // 0x804474CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804474D0: bnel        $a2, $at, L_804474FC
    if (ctx->r6 != ctx->r1) {
        // 0x804474D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804474FC;
    }
    goto skip_0;
    // 0x804474D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804474D8: jal         0x80445FD4
    // 0x804474DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_1;
    // 0x804474DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804474E0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804474E4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804474E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804474EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804474F0: b           L_8044750C
    // 0x804474F4: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044750C;
    // 0x804474F4: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x804474F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804474FC:
    // 0x804474FC: bnel        $a2, $at, L_80447510
    if (ctx->r6 != ctx->r1) {
        // 0x80447500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447510;
    }
    goto skip_1;
    // 0x80447500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447504: jal         0x8044602C
    // 0x80447508: nop

    func_8044602C(rdram, ctx);
        goto after_2;
    // 0x80447508: nop

    after_2:
L_8044750C:
    // 0x8044750C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447510:
    // 0x80447510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447518: jr          $ra
    // 0x8044751C: nop

    return;
    // 0x8044751C: nop

;}
RECOMP_FUNC void func_80793698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793698: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8079369C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807936A0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B10) << 16);
    // 0x807936A4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x807936A8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x807936AC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x807936B0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x807936B4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x807936B8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807936BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807936C0: lwc1        $f24, 0x7E60($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B10));
    // 0x807936C4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x807936C8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x807936CC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x807936D0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x807936D4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x807936D8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B14) << 16);
    // 0x807936DC: lui         $s7, 0x41A5
    ctx->r23 = S32(0X41A5 << 16);
    // 0x807936E0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807936E4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x807936E8: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x807936EC: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x807936F0: lwc1        $f22, 0x7E64($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B14));
    // 0x807936F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807936F8: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x807936FC: addiu       $fp, $zero, 0x6
    ctx->r30 = ADD32(0, 0X6);
L_80793700:
    // 0x80793700: jal         0x80047090
    // 0x80793704: addiu       $a0, $zero, 0x41A5
    ctx->r4 = ADD32(0, 0X41A5);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80793704: addiu       $a0, $zero, 0x41A5
    ctx->r4 = ADD32(0, 0X41A5);
    after_0:
    // 0x80793708: beq         $s6, $v0, L_807937F4
    if (ctx->r22 == ctx->r2) {
        // 0x8079370C: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_807937F4;
    }
    // 0x8079370C: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80793710: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80793714: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80793718: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8079371C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80793720: addu        $s2, $s4, $t6
    ctx->r18 = ADD32(ctx->r20, ctx->r14);
    // 0x80793724: jal         0x8004613C
    // 0x80793728: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80793728: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x8079372C: beq         $v0, $zero, L_80793778
    if (ctx->r2 == 0) {
        // 0x80793730: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80793778;
    }
    // 0x80793730: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80793734: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x80793738: andi        $t8, $s3, 0x3FF
    ctx->r24 = ctx->r19 & 0X3FF;
    // 0x8079373C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80793740: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80793744: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80793748: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x8079374C: jal         0x80047F9C
    // 0x80793750: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80793750: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80793754: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x80793758: jal         0x8079364C
    // 0x8079375C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079364C(rdram, ctx);
        goto after_3;
    // 0x8079375C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80793760: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80793764: nop

    // 0x80793768: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8079376C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80793770: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80793774: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80793778:
    // 0x80793778: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8079377C: bne         $s1, $fp, L_80793700
    if (ctx->r17 != ctx->r30) {
        // 0x80793780: sw          $s0, 0x14($s2)
        MEM_W(0X14, ctx->r18) = ctx->r16;
            goto L_80793700;
    }
    // 0x80793780: sw          $s0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r16;
    // 0x80793784: sw          $zero, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = 0;
    // 0x80793788: sw          $zero, 0x30($s4)
    MEM_W(0X30, ctx->r20) = 0;
    // 0x8079378C: sw          $zero, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = 0;
    // 0x80793790: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80793794: lbu         $t2, -0x7203($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X7203);
    // 0x80793798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079379C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x807937A0: sh          $t2, 0x34($s4)
    MEM_H(0X34, ctx->r20) = ctx->r10;
    // 0x807937A4: lh          $v0, 0x34($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X34);
    // 0x807937A8: beq         $v0, $zero, L_807937D8
    if (ctx->r2 == 0) {
        // 0x807937AC: nop
    
            goto L_807937D8;
    }
    // 0x807937AC: nop

    // 0x807937B0: beq         $v0, $at, L_807937E0
    if (ctx->r2 == ctx->r1) {
        // 0x807937B4: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_807937E0;
    }
    // 0x807937B4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x807937B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x807937BC: beq         $v0, $v1, L_807937E0
    if (ctx->r2 == ctx->r3) {
        // 0x807937C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_807937E0;
    }
    // 0x807937C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807937C4: beql        $v0, $at, L_807937F0
    if (ctx->r2 == ctx->r1) {
        // 0x807937C8: sh          $zero, 0x36($s4)
        MEM_H(0X36, ctx->r20) = 0;
            goto L_807937F0;
    }
    goto skip_0;
    // 0x807937C8: sh          $zero, 0x36($s4)
    MEM_H(0X36, ctx->r20) = 0;
    skip_0:
    // 0x807937CC: sh          $zero, 0x36($s4)
    MEM_H(0X36, ctx->r20) = 0;
    // 0x807937D0: b           L_807937F4
    // 0x807937D4: sh          $zero, 0x38($s4)
    MEM_H(0X38, ctx->r20) = 0;
        goto L_807937F4;
    // 0x807937D4: sh          $zero, 0x38($s4)
    MEM_H(0X38, ctx->r20) = 0;
L_807937D8:
    // 0x807937D8: b           L_807937F4
    // 0x807937DC: sh          $t3, 0x36($s4)
    MEM_H(0X36, ctx->r20) = ctx->r11;
        goto L_807937F4;
    // 0x807937DC: sh          $t3, 0x36($s4)
    MEM_H(0X36, ctx->r20) = ctx->r11;
L_807937E0:
    // 0x807937E0: sh          $v1, 0x36($s4)
    MEM_H(0X36, ctx->r20) = ctx->r3;
    // 0x807937E4: b           L_807937F4
    // 0x807937E8: sh          $v1, 0x38($s4)
    MEM_H(0X38, ctx->r20) = ctx->r3;
        goto L_807937F4;
    // 0x807937E8: sh          $v1, 0x38($s4)
    MEM_H(0X38, ctx->r20) = ctx->r3;
    // 0x807937EC: sh          $zero, 0x36($s4)
    MEM_H(0X36, ctx->r20) = 0;
L_807937F0:
    // 0x807937F0: sh          $zero, 0x38($s4)
    MEM_H(0X38, ctx->r20) = 0;
L_807937F4:
    // 0x807937F4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x807937F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807937FC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80793800: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80793804: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80793808: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8079380C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80793810: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80793814: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80793818: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8079381C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80793820: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80793824: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80793828: jr          $ra
    // 0x8079382C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8079382C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8004D328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D328: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004D32C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D330: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004D334: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004D338: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8004D33C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8004D340: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8004D344: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004D348: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004D34C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004D350: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004D354: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D358: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004D35C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004D360: beql        $v0, $zero, L_8004D3B8
    if (ctx->r2 == 0) {
        // 0x8004D364: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D3B8;
    }
    goto skip_0;
    // 0x8004D364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004D368: beql        $v0, $at, L_8004D3B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004D36C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D3B8;
    }
    goto skip_1;
    // 0x8004D36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004D370: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004D374: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004D378: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004D37C: beq         $v0, $at, L_8004D3B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004D380: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004D3B4;
    }
    // 0x8004D380: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004D384: beq         $v0, $at, L_8004D3B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004D388: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8004D3B4;
    }
    // 0x8004D388: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8004D38C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004D390: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8004D394: jal         0x80047AB8
    // 0x8004D398: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D398: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004D39C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8004D3A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004D3A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004D3A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8004D3AC: jalr        $t9
    // 0x8004D3B0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004D3B0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
L_8004D3B4:
    // 0x8004D3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004D3B8:
    // 0x8004D3B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004D3BC: jr          $ra
    // 0x8004D3C0: nop

    return;
    // 0x8004D3C0: nop

;}
RECOMP_FUNC void func_807A62A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A62A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A62A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A62AC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1564) << 16);
    // 0x807A62B0: lwc1        $f0, 0x7264($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1564));
    // 0x807A62B4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807A62B8: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807A62BC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1568) << 16);
    // 0x807A62C0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807A62C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A62C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807A62CC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x807A62D0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x807A62D4: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807A62D8: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x807A62DC: lwc1        $f18, 0x7268($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1568));
    // 0x807A62E0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x807A62E4: nop

    // 0x807A62E8: bc1fl       L_807A6320
    if (!c1cs) {
        // 0x807A62EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A6320;
    }
    goto skip_0;
    // 0x807A62EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A62F0: jal         0x807A6778
    // 0x807A62F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A6778(rdram, ctx);
        goto after_0;
    // 0x807A62F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A62F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A62FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807A6300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A6304: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807A630C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807A6310: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x807A6314: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6318: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x807A631C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6320:
    // 0x807A6320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6324: jr          $ra
    // 0x807A6328: nop

    return;
    // 0x807A6328: nop

;}
RECOMP_FUNC void func_8002CB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CB50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CB54: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CB58: addiu       $a1, $a1, -0x2AA0
    ctx->r5 = ADD32(ctx->r5, -0X2AA0);
    // 0x8002CB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CB60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CB64: jal         0x80028118
    // 0x8002CB68: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002CB68: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002CB6C: jal         0x8002CAB0
    // 0x8002CB70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002CAB0(rdram, ctx);
        goto after_1;
    // 0x8002CB70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002CB74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CB7C: jr          $ra
    // 0x8002CB80: nop

    return;
    // 0x8002CB80: nop

;}
RECOMP_FUNC void func_807B4DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B4DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B4DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B4DD0: jal         0x807B4A10
    // 0x807B4DD4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B4DD4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x807B4DD8: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2CDC) << 16);
    // 0x807B4DDC: addiu       $a1, $a1, 0x74DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2CDC));
    // 0x807B4DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B4DE4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x807B4DE8: jal         0x807B4900
    // 0x807B4DEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B4DEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B4DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B4DF8: jr          $ra
    // 0x807B4DFC: nop

    return;
    // 0x807B4DFC: nop

;}
RECOMP_FUNC void func_80041FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041FE8: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x80041FEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80041FF0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80041FF4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80041FF8: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80041FFC: lw          $a1, 0x138($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X138);
    // 0x80042000: lw          $v1, 0x144($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X144);
    // 0x80042004: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80042008: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8004200C: subu        $a3, $a1, $v1
    ctx->r7 = SUB32(ctx->r5, ctx->r3);
    // 0x80042010: blez        $a3, L_80042040
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80042014: nop
    
            goto L_80042040;
    }
    // 0x80042014: nop

    // 0x80042018: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8004201C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80042020: lw          $a0, 0x278($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X278);
    // 0x80042024: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042028: bne         $at, $zero, L_80042038
    if (ctx->r1 != 0) {
        // 0x8004202C: nop
    
            goto L_80042038;
    }
    // 0x8004202C: nop

    // 0x80042030: b           L_80042058
    // 0x80042034: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80042058;
    // 0x80042034: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80042038:
    // 0x80042038: b           L_80042058
    // 0x8004203C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
        goto L_80042058;
    // 0x8004203C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_80042040:
    // 0x80042040: lw          $a0, 0x3B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B8);
    // 0x80042044: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042048: beq         $at, $zero, L_80042058
    if (ctx->r1 == 0) {
        // 0x8004204C: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_80042058;
    }
    // 0x8004204C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80042050: b           L_80042058
    // 0x80042054: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80042058;
    // 0x80042054: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80042058:
    // 0x80042058: jr          $ra
    // 0x8004205C: sw          $v1, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r3;
    return;
    // 0x8004205C: sw          $v1, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_804CC130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC130: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(234, 0X10) << 16);
    // 0x804CC134: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(234, 0X10));
    // 0x804CC138: jr          $ra
    // 0x804CC13C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804CC13C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8007185C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007185C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80071860: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80071864: lw          $t7, -0x7B80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B80);
    // 0x80071868: lw          $t6, -0x7B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B7C);
    // 0x8007186C: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80071870: jr          $ra
    // 0x80071874: nop

    return;
    // 0x80071874: nop

;}
RECOMP_FUNC void func_800376A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800376A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800376A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800376AC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x800376B0: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x800376B4: bnel        $t6, $zero, L_800376FC
    if (ctx->r14 != 0) {
        // 0x800376B8: lbu         $t1, 0x1F8($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
            goto L_800376FC;
    }
    goto skip_0;
    // 0x800376B8: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
    skip_0:
    // 0x800376BC: lw          $t7, 0x78($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X78);
    // 0x800376C0: beql        $t7, $zero, L_800376FC
    if (ctx->r15 == 0) {
        // 0x800376C4: lbu         $t1, 0x1F8($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
            goto L_800376FC;
    }
    goto skip_1;
    // 0x800376C4: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
    skip_1:
    // 0x800376C8: lbu         $t8, 0x22($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X22);
    // 0x800376CC: beql        $t8, $zero, L_800376E8
    if (ctx->r24 == 0) {
        // 0x800376D0: addiu       $a1, $zero, 0x15
        ctx->r5 = ADD32(0, 0X15);
            goto L_800376E8;
    }
    goto skip_2;
    // 0x800376D0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    skip_2:
    // 0x800376D4: lw          $t9, 0x24($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X24);
    // 0x800376D8: andi        $t0, $t9, 0x3000
    ctx->r8 = ctx->r25 & 0X3000;
    // 0x800376DC: bnel        $t0, $zero, L_800376FC
    if (ctx->r8 != 0) {
        // 0x800376E0: lbu         $t1, 0x1F8($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
            goto L_800376FC;
    }
    goto skip_3;
    // 0x800376E0: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
    skip_3:
    // 0x800376E4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
L_800376E8:
    // 0x800376E8: jal         0x8002DBE4
    // 0x800376EC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x800376EC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x800376F0: b           L_8003775C
    // 0x800376F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003775C;
    // 0x800376F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800376F8: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
L_800376FC:
    // 0x800376FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037700: beq         $t1, $zero, L_80037754
    if (ctx->r9 == 0) {
        // 0x80037704: nop
    
            goto L_80037754;
    }
    // 0x80037704: nop

    // 0x80037708: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8003770C: lwc1        $f4, 0xFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFC);
    // 0x80037710: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80037714: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037718: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003771C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80037720: bc1tl       L_80037750
    if (c1cs) {
        // 0x80037724: sh          $zero, 0xADE($v0)
        MEM_H(0XADE, ctx->r2) = 0;
            goto L_80037750;
    }
    goto skip_4;
    // 0x80037724: sh          $zero, 0xADE($v0)
    MEM_H(0XADE, ctx->r2) = 0;
    skip_4:
    // 0x80037728: lwc1        $f6, 0x100($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X100);
    // 0x8003772C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80037730: nop

    // 0x80037734: bc1tl       L_80037750
    if (c1cs) {
        // 0x80037738: sh          $zero, 0xADE($v0)
        MEM_H(0XADE, ctx->r2) = 0;
            goto L_80037750;
    }
    goto skip_5;
    // 0x80037738: sh          $zero, 0xADE($v0)
    MEM_H(0XADE, ctx->r2) = 0;
    skip_5:
    // 0x8003773C: jal         0x80037380
    // 0x80037740: nop

    func_80037380(rdram, ctx);
        goto after_1;
    // 0x80037740: nop

    after_1:
    // 0x80037744: b           L_80037760
    // 0x80037748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80037760;
    // 0x80037748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003774C: sh          $zero, 0xADE($v0)
    MEM_H(0XADE, ctx->r2) = 0;
L_80037750:
    // 0x80037750: sh          $zero, 0xAE2($v0)
    MEM_H(0XAE2, ctx->r2) = 0;
L_80037754:
    // 0x80037754: jal         0x80037498
    // 0x80037758: nop

    func_80037498(rdram, ctx);
        goto after_2;
    // 0x80037758: nop

    after_2:
L_8003775C:
    // 0x8003775C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037760:
    // 0x80037760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037764: jr          $ra
    // 0x80037768: nop

    return;
    // 0x80037768: nop

;}
RECOMP_FUNC void func_80679F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679F80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80679F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80679F88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80679F8C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80679F90: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X2658) << 16);
    // 0x80679F94: lh          $s0, 0x1F0($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X1F0);
    // 0x80679F98: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x80679F9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80679FA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679FA4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80679FA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80679FAC: lw          $t8, -0x3CF8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(541, 0X2658));
    // 0x80679FB0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80679FB4: bne         $s0, $at, L_8067A020
    if (ctx->r16 != ctx->r1) {
        // 0x80679FB8: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_8067A020;
    }
    // 0x80679FB8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80679FBC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679FC0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80679FC4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80679FC8: jal         0x80067D5C
    // 0x80679FCC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80679FCC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x80679FD0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80679FD4: jal         0x80067F78
    // 0x80679FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80679FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80679FDC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80679FE0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80679FE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679FE8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80679FEC: beq         $v0, $at, L_8067A05C
    if (ctx->r2 == ctx->r1) {
        // 0x80679FF0: sh          $v0, 0x1F0($a3)
        MEM_H(0X1F0, ctx->r7) = ctx->r2;
            goto L_8067A05C;
    }
    // 0x80679FF0: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x80679FF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80679FF8: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679FFC: jal         0x80067D5C
    // 0x8067A000: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x8067A000: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8067A004: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8067A008: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8067A00C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8067A010: jal         0x80067838
    // 0x8067A014: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8067A014: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8067A018: b           L_8067A060
    // 0x8067A01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067A060;
    // 0x8067A01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067A020:
    // 0x8067A020: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8067A024: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8067A028: jal         0x80067930
    // 0x8067A02C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x8067A02C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_4:
    // 0x8067A030: beq         $v0, $zero, L_8067A05C
    if (ctx->r2 == 0) {
        // 0x8067A034: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_8067A05C;
    }
    // 0x8067A034: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8067A038: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8067A03C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8067A040: jal         0x80067D5C
    // 0x8067A044: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x8067A044: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_5:
    // 0x8067A048: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8067A04C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8067A050: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8067A054: jal         0x800678F0
    // 0x8067A058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x8067A058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_8067A05C:
    // 0x8067A05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067A060:
    // 0x8067A060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067A064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067A068: jr          $ra
    // 0x8067A06C: nop

    return;
    // 0x8067A06C: nop

;}
RECOMP_FUNC void func_80050EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050EE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050EE8: jal         0x80064DD0
    // 0x80050EEC: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80050EEC: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_0:
    // 0x80050EF0: bne         $v0, $zero, L_80050F00
    if (ctx->r2 != 0) {
        // 0x80050EF4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80050F00;
    }
    // 0x80050EF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050EF8: b           L_80050F1C
    // 0x80050EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050F1C;
    // 0x80050EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050F00:
    // 0x80050F00: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80050F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80050F08: jal         0x80065728
    // 0x80050F0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80050F0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80050F10: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80050F14: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80050F18: sh          $t6, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r14;
L_80050F1C:
    // 0x80050F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050F24: jr          $ra
    // 0x80050F28: nop

    return;
    // 0x80050F28: nop

;}
RECOMP_FUNC void func_8067BF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BF3C: jal         0x80679F40
    // 0x8067BF40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80679F40(rdram, ctx);
        goto after_0;
    // 0x8067BF40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067BF44: jal         0x80045BD8
    // 0x8067BF48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8067BF48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8067BF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BF50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BF54: jr          $ra
    // 0x8067BF58: nop

    return;
    // 0x8067BF58: nop

;}
RECOMP_FUNC void func_80460100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460100: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80460104: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80460108: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8046010C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80460110: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80460114: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80460118: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8046011C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80460120: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80460124: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80460128: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8046012C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80460130: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80460134: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80460138: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8046013C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80460140: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x80460144: addiu       $t3, $zero, 0xC80
    ctx->r11 = ADD32(0, 0XC80);
    // 0x80460148: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8046014C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80460150: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80460154: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80460158: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046015C: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x80460160: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x80460164: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80460168: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8046016C: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x80460170: ori         $a3, $a3, 0x2078
    ctx->r7 = ctx->r7 | 0X2078;
    // 0x80460174: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80460178: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8046017C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80460180: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80460184: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80460188: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8046018C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80460190: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80460194: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80460198: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046019C: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x804601A0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x804601A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804601A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804601AC: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x804601B0: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x804601B4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804601B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804601BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804601C0: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x804601C4: addiu       $t3, $zero, 0x205
    ctx->r11 = ADD32(0, 0X205);
    // 0x804601C8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804601CC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x804601D0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x804601D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x804601D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804601DC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x804601E0: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x804601E4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x804601E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x804601EC: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x804601F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x804601F4: jr          $ra
    // 0x804601F8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x804601F8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_807995BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807995BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807995C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807995C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807995C8: jal         0x80799560
    // 0x807995CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80799560(rdram, ctx);
        goto after_0;
    // 0x807995CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807995D0: bne         $v0, $zero, L_807995E8
    if (ctx->r2 != 0) {
        // 0x807995D4: nop
    
            goto L_807995E8;
    }
    // 0x807995D4: nop

    // 0x807995D8: jal         0x800445A4
    // 0x807995DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x807995DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807995E0: b           L_80799644
    // 0x807995E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80799644;
    // 0x807995E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807995E8:
    // 0x807995E8: jal         0x807995A4
    // 0x807995EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807995A4(rdram, ctx);
        goto after_2;
    // 0x807995EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807995F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807995F4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x807995F8: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x807995FC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80799600: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80799604: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80799608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079960C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80799610: jal         0x80799654
    // 0x80799614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80799654(rdram, ctx);
        goto after_3;
    // 0x80799614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80799618: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x8079961C: addiu       $at, $zero, 0x46B2
    ctx->r1 = ADD32(0, 0X46B2);
    // 0x80799620: bnel        $t7, $at, L_80799644
    if (ctx->r15 != ctx->r1) {
        // 0x80799624: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799644;
    }
    goto skip_0;
    // 0x80799624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80799628: jal         0x8079918C
    // 0x8079962C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079918C(rdram, ctx);
        goto after_4;
    // 0x8079962C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80799630: bnel        $v0, $zero, L_80799644
    if (ctx->r2 != 0) {
        // 0x80799634: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799644;
    }
    goto skip_1;
    // 0x80799634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80799638: jal         0x800445A4
    // 0x8079963C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8079963C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80799640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80799644:
    // 0x80799644: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80799648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079964C: jr          $ra
    // 0x80799650: nop

    return;
    // 0x80799650: nop

;}
RECOMP_FUNC void func_806B23B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B23B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B23BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806B23C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806B23C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806B23C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B23CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B23D0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806B23D4: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X14DC) << 16);
    // 0x806B23D8: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X1508) << 16);
    // 0x806B23DC: addiu       $a1, $a1, 0x2E58
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X1508));
    // 0x806B23E0: addiu       $a2, $a2, 0x2E2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X14DC));
    // 0x806B23E4: jal         0x806B1A18
    // 0x806B23E8: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    func_806B1A18(rdram, ctx);
        goto after_0;
    // 0x806B23E8: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_0:
    // 0x806B23EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806B23F0: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X1534) << 16);
    // 0x806B23F4: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X14DC) << 16);
    // 0x806B23F8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x806B23FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B2400: addiu       $a2, $a2, 0x2E2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X14DC));
    // 0x806B2404: addiu       $a1, $a1, 0x2E84
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X1534));
    // 0x806B2408: jal         0x806B1A18
    // 0x806B240C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    func_806B1A18(rdram, ctx);
        goto after_1;
    // 0x806B240C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_1:
    // 0x806B2410: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x806B2414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B2418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B241C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2420: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B2424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B2428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B242C: jr          $ra
    // 0x806B2430: nop

    return;
    // 0x806B2430: nop

;}
RECOMP_FUNC void func_806F5578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F557C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F5580: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806F5584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5588: lui         $a0, 0x46BA
    ctx->r4 = S32(0X46BA << 16);
    // 0x806F558C: ori         $a0, $a0, 0x1800
    ctx->r4 = ctx->r4 | 0X1800;
    // 0x806F5590: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x806F5594: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x806F5598: jal         0x8004613C
    // 0x806F559C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x806F559C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806F55A0: beq         $v0, $zero, L_806F55D4
    if (ctx->r2 == 0) {
        // 0x806F55A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806F55D4;
    }
    // 0x806F55A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806F55A8: addiu       $a0, $zero, 0x46BA
    ctx->r4 = ADD32(0, 0X46BA);
    // 0x806F55AC: jal         0x80047090
    // 0x806F55B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806F55B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x806F55B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806F55B8: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x806F55BC: lhu         $t9, 0xE($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XE);
    // 0x806F55C0: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806F55C4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806F55C8: jal         0x80044194
    // 0x806F55CC: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806F55CC: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    after_2:
    // 0x806F55D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_806F55D4:
    // 0x806F55D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F55D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F55DC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x806F55E0: jr          $ra
    // 0x806F55E4: nop

    return;
    // 0x806F55E4: nop

;}
RECOMP_FUNC void func_807B5314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5314: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x807B5318: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x807B531C: lbu         $t7, -0x7204($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7204);
    // 0x807B5320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B5324: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B5328: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B532C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x807B5330: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x807B5334: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B5338: addiu       $a0, $a0, 0xF7
    ctx->r4 = ADD32(ctx->r4, 0XF7);
    // 0x807B533C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x807B5340: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x807B5344: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x807B5348: lui         $t4, 0x361
    ctx->r12 = S32(0X361 << 16);
    // 0x807B534C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x807B5350: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x807B5354: addiu       $t4, $t4, -0x2570
    ctx->r12 = ADD32(ctx->r12, -0X2570);
    // 0x807B5358: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x807B535C: addiu       $t9, $t8, 0x2D0
    ctx->r25 = ADD32(ctx->r24, 0X2D0);
    // 0x807B5360: addu        $a1, $t9, $t4
    ctx->r5 = ADD32(ctx->r25, ctx->r12);
    // 0x807B5364: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807B5368: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x807B536C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x807B5370: jal         0x800675D0
    // 0x807B5374: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x807B5374: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    after_0:
    // 0x807B5378: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x807B537C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x807B5380: addiu       $s1, $s1, 0xCF
    ctx->r17 = ADD32(ctx->r17, 0XCF);
    // 0x807B5384: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x807B5388: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x807B538C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B5390: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x807B5394: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x807B5398: jal         0x800675D0
    // 0x807B539C: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x807B539C: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    after_1:
    // 0x807B53A0: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x807B53A4: jal         0x807B4A10
    // 0x807B53A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807B4A10(rdram, ctx);
        goto after_2;
    // 0x807B53A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x807B53AC: addiu       $t5, $zero, 0x3B
    ctx->r13 = ADD32(0, 0X3B);
    // 0x807B53B0: sh          $t5, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r13;
    // 0x807B53B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x807B53B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B53BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B53C0: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x807B53C4: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x807B53C8: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x807B53CC: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x807B53D0: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x807B53D4: addu        $t6, $s1, $a1
    ctx->r14 = ADD32(ctx->r17, ctx->r5);
L_807B53D8:
    // 0x807B53D8: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x807B53DC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x807B53E0: slti        $at, $a1, 0x62
    ctx->r1 = SIGNED(ctx->r5) < 0X62 ? 1 : 0;
    // 0x807B53E4: bne         $t1, $a0, L_807B5410
    if (ctx->r9 != ctx->r4) {
        // 0x807B53E8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_807B5410;
    }
    // 0x807B53E8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x807B53EC: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x807B53F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x807B53F4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x807B53F8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x807B53FC: sh          $a2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r6;
    // 0x807B5400: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x807B5404: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
    // 0x807B5408: b           L_807B5448
    // 0x807B540C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B5448;
    // 0x807B540C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5410:
    // 0x807B5410: beq         $t0, $zero, L_807B5428
    if (ctx->r8 == 0) {
        // 0x807B5414: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_807B5428;
    }
    // 0x807B5414: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x807B5418: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x807B541C: sh          $a0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r4;
    // 0x807B5420: b           L_807B5448
    // 0x807B5424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B5448;
    // 0x807B5424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5428:
    // 0x807B5428: beq         $v1, $zero, L_807B5448
    if (ctx->r3 == 0) {
        // 0x807B542C: nop
    
            goto L_807B5448;
    }
    // 0x807B542C: nop

    // 0x807B5430: beq         $t3, $v1, L_807B5448
    if (ctx->r11 == ctx->r3) {
        // 0x807B5434: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_807B5448;
    }
    // 0x807B5434: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x807B5438: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x807B543C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B5440: sh          $a0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r4;
    // 0x807B5444: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5448:
    // 0x807B5448: bnel        $at, $zero, L_807B53D8
    if (ctx->r1 != 0) {
        // 0x807B544C: addu        $t6, $s1, $a1
        ctx->r14 = ADD32(ctx->r17, ctx->r5);
            goto L_807B53D8;
    }
    goto skip_0;
    // 0x807B544C: addu        $t6, $s1, $a1
    ctx->r14 = ADD32(ctx->r17, ctx->r5);
    skip_0:
    // 0x807B5450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B5454: sw          $v0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r2;
    // 0x807B5458: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x807B545C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B5460: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B5464: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x807B5468: jal         0x807B4900
    // 0x807B546C: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    func_807B4900(rdram, ctx);
        goto after_3;
    // 0x807B546C: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    after_3:
    // 0x807B5470: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x807B5474: lbu         $t9, -0x7204($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7204);
    // 0x807B5478: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x807B547C: lbu         $t5, -0x7203($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X7203);
    // 0x807B5480: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x807B5484: lui         $t8, 0x361
    ctx->r24 = S32(0X361 << 16);
    // 0x807B5488: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x807B548C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x807B5490: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x807B5494: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B5498: addiu       $t7, $t6, 0x174
    ctx->r15 = ADD32(ctx->r14, 0X174);
    // 0x807B549C: addiu       $t8, $t8, -0x2570
    ctx->r24 = ADD32(ctx->r24, -0X2570);
    // 0x807B54A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x807B54A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807B54A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x807B54AC: jal         0x800675D0
    // 0x807B54B0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800675D0(rdram, ctx);
        goto after_4;
    // 0x807B54B0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x807B54B4: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x807B54B8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x807B54BC: addiu       $s1, $s1, 0xAB
    ctx->r17 = ADD32(ctx->r17, 0XAB);
    // 0x807B54C0: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x807B54C4: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x807B54C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B54CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x807B54D0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x807B54D4: jal         0x800675D0
    // 0x807B54D8: lhu         $a2, 0x4($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X4);
    func_800675D0(rdram, ctx);
        goto after_5;
    // 0x807B54D8: lhu         $a2, 0x4($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X4);
    after_5:
    // 0x807B54DC: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x807B54E0: jal         0x807B4A10
    // 0x807B54E4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_6;
    // 0x807B54E4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x807B54E8: lw          $v0, 0x10C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10C);
    // 0x807B54EC: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x807B54F0: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x807B54F4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x807B54F8: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x807B54FC: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x807B5500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5504: addiu       $a2, $zero, 0x62
    ctx->r6 = ADD32(0, 0X62);
    // 0x807B5508: addu        $t4, $s1, $a1
    ctx->r12 = ADD32(ctx->r17, ctx->r5);
L_807B550C:
    // 0x807B550C: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x807B5510: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x807B5514: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x807B5518: bne         $t1, $a0, L_807B5530
    if (ctx->r9 != ctx->r4) {
        // 0x807B551C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_807B5530;
    }
    // 0x807B551C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x807B5520: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x807B5524: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x807B5528: b           L_807B5568
    // 0x807B552C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B5568;
    // 0x807B552C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5530:
    // 0x807B5530: beq         $t0, $zero, L_807B5548
    if (ctx->r8 == 0) {
        // 0x807B5534: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_807B5548;
    }
    // 0x807B5534: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x807B5538: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x807B553C: sh          $a0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r4;
    // 0x807B5540: b           L_807B5568
    // 0x807B5544: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_807B5568;
    // 0x807B5544: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5548:
    // 0x807B5548: beq         $v1, $zero, L_807B5568
    if (ctx->r3 == 0) {
        // 0x807B554C: nop
    
            goto L_807B5568;
    }
    // 0x807B554C: nop

    // 0x807B5550: beq         $t3, $v1, L_807B5568
    if (ctx->r11 == ctx->r3) {
        // 0x807B5554: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_807B5568;
    }
    // 0x807B5554: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x807B5558: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x807B555C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B5560: sh          $a0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r4;
    // 0x807B5564: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B5568:
    // 0x807B5568: bnel        $a1, $a2, L_807B550C
    if (ctx->r5 != ctx->r6) {
        // 0x807B556C: addu        $t4, $s1, $a1
        ctx->r12 = ADD32(ctx->r17, ctx->r5);
            goto L_807B550C;
    }
    goto skip_1;
    // 0x807B556C: addu        $t4, $s1, $a1
    ctx->r12 = ADD32(ctx->r17, ctx->r5);
    skip_1:
    // 0x807B5570: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x807B5574: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B5578: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x807B557C: jal         0x807B4900
    // 0x807B5580: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_807B4900(rdram, ctx);
        goto after_7;
    // 0x807B5580: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_7:
    // 0x807B5584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5588: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B558C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B5590: jr          $ra
    // 0x807B5594: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x807B5594: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80049624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049624: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80049628: lbu         $t6, 0x5B4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5B4);
    // 0x8004962C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049634: bnel        $t6, $zero, L_80049668
    if (ctx->r14 != 0) {
        // 0x80049638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049668;
    }
    goto skip_0;
    // 0x80049638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004963C: jal         0x80049318
    // 0x80049640: nop

    func_80049318(rdram, ctx);
        goto after_0;
    // 0x80049640: nop

    after_0:
    // 0x80049644: beql        $v0, $zero, L_80049668
    if (ctx->r2 == 0) {
        // 0x80049648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049668;
    }
    goto skip_1;
    // 0x80049648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004964C: jal         0x800492C0
    // 0x80049650: addiu       $a0, $zero, -0x89
    ctx->r4 = ADD32(0, -0X89);
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x80049650: addiu       $a0, $zero, -0x89
    ctx->r4 = ADD32(0, -0X89);
    after_1:
    // 0x80049654: beq         $v0, $zero, L_80049664
    if (ctx->r2 == 0) {
        // 0x80049658: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80049664;
    }
    // 0x80049658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004965C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80049660: sb          $t7, 0x5B4($at)
    MEM_B(0X5B4, ctx->r1) = ctx->r15;
L_80049664:
    // 0x80049664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049668:
    // 0x80049668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004966C: jr          $ra
    // 0x80049670: nop

    return;
    // 0x80049670: nop

;}
RECOMP_FUNC void func_8007FF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FF58: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FF60: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FF64: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FF68: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FF6C: jal         0x800818E8
    // 0x8007FF70: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FF70: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FF74: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FF78: jal         0x800806B0
    // 0x8007FF7C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800806B0(rdram, ctx);
        goto after_1;
    // 0x8007FF7C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x8007FF80: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FF84: jal         0x800817A0
    // 0x8007FF88: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FF88: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FF90: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FF94: jr          $ra
    // 0x8007FF98: nop

    return;
    // 0x8007FF98: nop

;}
RECOMP_FUNC void func_8043DE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DE8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043DE90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043DE94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043DE98: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8043DE9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043DEA0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8043DEA4: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8043DEA8: beql        $t8, $zero, L_8043DEBC
    if (ctx->r24 == 0) {
        // 0x8043DEAC: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8043DEBC;
    }
    goto skip_0;
    // 0x8043DEAC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8043DEB0: jal         0x8043E0F8
    // 0x8043DEB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8043E0F8(rdram, ctx);
        goto after_0;
    // 0x8043DEB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8043DEB8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8043DEBC:
    // 0x8043DEBC: jal         0x80048F84
    // 0x8043DEC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8043DEC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8043DEC4: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8043DEC8: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8043DECC: jal         0x80065ABC
    // 0x8043DED0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x8043DED0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x8043DED4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8043DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DEDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043DEE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043DEE4: jr          $ra
    // 0x8043DEE8: nop

    return;
    // 0x8043DEE8: nop

;}
RECOMP_FUNC void func_805A787C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A787C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A7880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A7888: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A788C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7890: jal         0x8004700C
    // 0x805A7894: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A7894: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A7898: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805A789C: beq         $v0, $zero, L_805A7A24
    if (ctx->r2 == 0) {
        // 0x805A78A0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_805A7A24;
    }
    // 0x805A78A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805A78A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A78A8: jal         0x805A7440
    // 0x805A78AC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_805A7440(rdram, ctx);
        goto after_1;
    // 0x805A78AC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x805A78B0: jal         0x800692D4
    // 0x805A78B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_2;
    // 0x805A78B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A78B8: jal         0x805A7620
    // 0x805A78BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7620(rdram, ctx);
        goto after_3;
    // 0x805A78BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A78C0: beq         $v0, $zero, L_805A78E4
    if (ctx->r2 == 0) {
        // 0x805A78C4: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_805A78E4;
    }
    // 0x805A78C4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805A78C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A78CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A78D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A78D4: jal         0x805A8794
    // 0x805A78D8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_4;
    // 0x805A78D8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x805A78DC: b           L_805A7A28
    // 0x805A78E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A7A28;
    // 0x805A78E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A78E4:
    // 0x805A78E4: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x805A78E8: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805A78EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805A78F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A78F4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A78F8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x805A78FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A7904: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A7908: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805A790C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805A7910: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805A7914: bc1fl       L_805A793C
    if (!c1cs) {
        // 0x805A7918: lwc1        $f0, 0x1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_805A793C;
    }
    goto skip_0;
    // 0x805A7918: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x805A791C: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x805A7920: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x805A7924: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A7928: jal         0x805A8794
    // 0x805A792C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_5;
    // 0x805A792C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x805A7930: b           L_805A7A28
    // 0x805A7934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A7A28;
    // 0x805A7934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A7938: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
L_805A793C:
    // 0x805A793C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A7940: nop

    // 0x805A7944: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x805A7948: nop

    // 0x805A794C: bc1fl       L_805A7968
    if (!c1cs) {
        // 0x805A7950: swc1        $f0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
            goto L_805A7968;
    }
    goto skip_1;
    // 0x805A7950: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x805A7954: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x805A7958: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x805A795C: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x805A7960: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x805A7964: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_805A7968:
    // 0x805A7968: jal         0x80066E88
    // 0x805A796C: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x805A796C: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_6:
    // 0x805A7970: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805A7974: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A7978: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x805A797C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A7980: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805A7984: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A7988: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x805A798C: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x805A7990: beql        $t7, $zero, L_805A79B0
    if (ctx->r15 == 0) {
        // 0x805A7994: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_805A79B0;
    }
    goto skip_2;
    // 0x805A7994: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_2:
    // 0x805A7998: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x805A799C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A79A0: nop

    // 0x805A79A4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805A79A8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x805A79AC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_805A79B0:
    // 0x805A79B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A79B4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A79B8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805A79BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A79C0: lwc1        $f10, 0x88($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X88);
    // 0x805A79C4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805A79C8: nop

    // 0x805A79CC: bc1fl       L_805A79FC
    if (!c1cs) {
        // 0x805A79D0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_805A79FC;
    }
    goto skip_3;
    // 0x805A79D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x805A79D4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805A79D8: jal         0x80066DE4
    // 0x805A79DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x805A79DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_7:
    // 0x805A79E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805A79E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A79E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A79EC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805A79F0: b           L_805A7A04
    // 0x805A79F4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
        goto L_805A7A04;
    // 0x805A79F4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x805A79F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_805A79FC:
    // 0x805A79FC: nop

    // 0x805A7A00: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
L_805A7A04:
    // 0x805A7A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A7A08: jal         0x80048F84
    // 0x805A7A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x805A7A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_8:
    // 0x805A7A10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A7A14: jal         0x80048F84
    // 0x805A7A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_9;
    // 0x805A7A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x805A7A1C: jal         0x805A7460
    // 0x805A7A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7460(rdram, ctx);
        goto after_10;
    // 0x805A7A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_805A7A24:
    // 0x805A7A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7A28:
    // 0x805A7A28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A7A2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A7A30: jr          $ra
    // 0x805A7A34: nop

    return;
    // 0x805A7A34: nop

;}
RECOMP_FUNC void func_8057B470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057B470: lui         $v1, 0x8058
    ctx->r3 = S32(RELOC_HI16(384, 0X1E4C) << 16);
    // 0x8057B474: addiu       $v1, $v1, -0x4774
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(384, 0X1E4C));
    // 0x8057B478: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8057B47C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057B480: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8057B484: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057B488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057B48C: beq         $t6, $zero, L_8057B49C
    if (ctx->r14 == 0) {
        // 0x8057B490: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_8057B49C;
    }
    // 0x8057B490: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8057B494: b           L_8057B4F0
    // 0x8057B498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057B4F0;
    // 0x8057B498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057B49C:
    // 0x8057B49C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8057B4A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8057B4A4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1BD0) << 16);
    // 0x8057B4A8: lwc1        $f4, -0x49F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1BD0));
    // 0x8057B4AC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8057B4B0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8057B4B4: lui         $a0, 0x8058
    ctx->r4 = S32(RELOC_HI16(384, 0X1E40) << 16);
    // 0x8057B4B8: lui         $a1, 0x4013
    ctx->r5 = S32(0X4013 << 16);
    // 0x8057B4BC: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8057B4C0: addiu       $a0, $a0, -0x4780
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(384, 0X1E40));
    // 0x8057B4C4: jal         0x80046804
    // 0x8057B4C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8057B4C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8057B4CC: bne         $v0, $zero, L_8057B4DC
    if (ctx->r2 != 0) {
        // 0x8057B4D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8057B4DC;
    }
    // 0x8057B4D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8057B4D4: b           L_8057B4F0
    // 0x8057B4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057B4F0;
    // 0x8057B4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057B4DC:
    // 0x8057B4DC: jal         0x80044194
    // 0x8057B4E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x8057B4E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8057B4E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057B4E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8057B4EC: sw          $zero, -0x763C($at)
    MEM_W(-0X763C, ctx->r1) = 0;
L_8057B4F0:
    // 0x8057B4F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057B4F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8057B4F8: jr          $ra
    // 0x8057B4FC: nop

    return;
    // 0x8057B4FC: nop

;}
RECOMP_FUNC void func_806F1F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1F74: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806F1F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F1F7C: beq         $t6, $zero, L_806F1FB8
    if (ctx->r14 == 0) {
        // 0x806F1F80: nop
    
            goto L_806F1FB8;
    }
    // 0x806F1F80: nop

    // 0x806F1F84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F1F88: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806F1F8C: jalr        $t9
    // 0x806F1F90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F1F90: nop

    after_0:
    // 0x806F1F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F1F98: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806F1F9C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806F1FA0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806F1FA4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806F1FA8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806F1FAC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806F1FB0: b           L_806F1FB8
    // 0x806F1FB4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806F1FB8;
    // 0x806F1FB4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806F1FB8:
    // 0x806F1FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F1FC0: jr          $ra
    // 0x806F1FC4: nop

    return;
    // 0x806F1FC4: nop

;}
RECOMP_FUNC void func_8006E310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006E314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E320: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E324: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006E328: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006E32C: jal         0x8006E154
    // 0x8006E330: addiu       $a1, $a1, -0x1D20
    ctx->r5 = ADD32(ctx->r5, -0X1D20);
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8006E330: addiu       $a1, $a1, -0x1D20
    ctx->r5 = ADD32(ctx->r5, -0X1D20);
    after_0:
    // 0x8006E334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E33C: jr          $ra
    // 0x8006E340: nop

    return;
    // 0x8006E340: nop

;}
RECOMP_FUNC void func_8045A7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A7A8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8045A7AC: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x8045A7B0: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8045A7B4: beq         $v0, $zero, L_8045A7D8
    if (ctx->r2 == 0) {
        // 0x8045A7B8: nop
    
            goto L_8045A7D8;
    }
    // 0x8045A7B8: nop

    // 0x8045A7BC: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8045A7C0: lwc1        $f4, 0x328($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X328);
    // 0x8045A7C4: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8045A7C8: lwc1        $f6, 0x32C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X32C);
    // 0x8045A7CC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8045A7D0: lwc1        $f8, 0x50($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8045A7D4: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
L_8045A7D8:
    // 0x8045A7D8: jr          $ra
    // 0x8045A7DC: nop

    return;
    // 0x8045A7DC: nop

;}
RECOMP_FUNC void func_804650B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804650B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804650B8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x804650BC: addiu       $v1, $zero, 0x17
    ctx->r3 = ADD32(0, 0X17);
    // 0x804650C0: addiu       $a1, $v0, 0x18D8
    ctx->r5 = ADD32(ctx->r2, 0X18D8);
    // 0x804650C4: addiu       $a2, $v0, 0x1ED8
    ctx->r6 = ADD32(ctx->r2, 0X1ED8);
    // 0x804650C8: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x804650CC: addiu       $t4, $zero, 0x1C0
    ctx->r12 = ADD32(0, 0X1C0);
    // 0x804650D0: addiu       $t3, $zero, 0x9B
    ctx->r11 = ADD32(0, 0X9B);
    // 0x804650D4: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x804650D8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x804650DC: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x804650E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_804650E4:
    // 0x804650E4: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x804650E8: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x804650EC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x804650F0: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x804650F4: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x804650F8: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x804650FC: sb          $a0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r4;
    // 0x80465100: sb          $a0, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r4;
    // 0x80465104: sb          $a3, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r7;
    // 0x80465108: sb          $t0, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r8;
    // 0x8046510C: sb          $t0, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r8;
    // 0x80465110: sb          $a3, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r7;
    // 0x80465114: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
    // 0x80465118: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
    // 0x8046511C: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // 0x80465120: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80465124: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80465128: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
    // 0x8046512C: sh          $zero, 0x2($a2)
    MEM_H(0X2, ctx->r6) = 0;
    // 0x80465130: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80465134: sb          $t3, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r11;
    // 0x80465138: sb          $a3, 0x1E($a1)
    MEM_B(0X1E, ctx->r5) = ctx->r7;
    // 0x8046513C: sb          $t2, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r10;
    // 0x80465140: sb          $t2, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r10;
    // 0x80465144: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x80465148: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x8046514C: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
    // 0x80465150: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x80465154: sh          $t1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r9;
    // 0x80465158: sh          $zero, 0x10($a1)
    MEM_H(0X10, ctx->r5) = 0;
    // 0x8046515C: sb          $t3, 0x1F($a2)
    MEM_B(0X1F, ctx->r6) = ctx->r11;
    // 0x80465160: sb          $a3, 0x1E($a2)
    MEM_B(0X1E, ctx->r6) = ctx->r7;
    // 0x80465164: sb          $t2, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r10;
    // 0x80465168: sb          $t2, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r10;
    // 0x8046516C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
    // 0x80465170: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x80465174: sh          $zero, 0x16($a2)
    MEM_H(0X16, ctx->r6) = 0;
    // 0x80465178: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x8046517C: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
    // 0x80465180: sh          $zero, 0x10($a2)
    MEM_H(0X10, ctx->r6) = 0;
    // 0x80465184: sb          $t3, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r11;
    // 0x80465188: sb          $a3, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = ctx->r7;
    // 0x8046518C: sb          $t2, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r10;
    // 0x80465190: sb          $t2, 0x2C($a1)
    MEM_B(0X2C, ctx->r5) = ctx->r10;
    // 0x80465194: sh          $zero, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = 0;
    // 0x80465198: sh          $t4, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r12;
    // 0x8046519C: sh          $zero, 0x26($a1)
    MEM_H(0X26, ctx->r5) = 0;
    // 0x804651A0: sh          $zero, 0x24($a1)
    MEM_H(0X24, ctx->r5) = 0;
    // 0x804651A4: sh          $t1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r9;
    // 0x804651A8: sh          $t1, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r9;
    // 0x804651AC: sb          $t3, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r11;
    // 0x804651B0: sb          $a3, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r7;
    // 0x804651B4: sb          $t2, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r10;
    // 0x804651B8: sb          $t2, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r10;
    // 0x804651BC: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x804651C0: sh          $t4, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r12;
    // 0x804651C4: sh          $zero, 0x26($a2)
    MEM_H(0X26, ctx->r6) = 0;
    // 0x804651C8: sh          $zero, 0x24($a2)
    MEM_H(0X24, ctx->r6) = 0;
    // 0x804651CC: sh          $t1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r9;
    // 0x804651D0: sh          $t1, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r9;
    // 0x804651D4: sb          $t0, 0x3F($a1)
    MEM_B(0X3F, ctx->r5) = ctx->r8;
    // 0x804651D8: sb          $a3, 0x3E($a1)
    MEM_B(0X3E, ctx->r5) = ctx->r7;
    // 0x804651DC: sb          $a0, 0x3D($a1)
    MEM_B(0X3D, ctx->r5) = ctx->r4;
    // 0x804651E0: sb          $a0, 0x3C($a1)
    MEM_B(0X3C, ctx->r5) = ctx->r4;
    // 0x804651E4: sh          $v0, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r2;
    // 0x804651E8: sh          $t4, 0x38($a1)
    MEM_H(0X38, ctx->r5) = ctx->r12;
    // 0x804651EC: sh          $zero, 0x36($a1)
    MEM_H(0X36, ctx->r5) = 0;
    // 0x804651F0: sh          $zero, 0x34($a1)
    MEM_H(0X34, ctx->r5) = 0;
    // 0x804651F4: sh          $zero, 0x32($a1)
    MEM_H(0X32, ctx->r5) = 0;
    // 0x804651F8: sh          $t1, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r9;
    // 0x804651FC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80465200: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
    // 0x80465204: addiu       $a2, $a2, -0x40
    ctx->r6 = ADD32(ctx->r6, -0X40);
    // 0x80465208: sb          $t0, 0x7F($a2)
    MEM_B(0X7F, ctx->r6) = ctx->r8;
    // 0x8046520C: sb          $a3, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = ctx->r7;
    // 0x80465210: sb          $a0, 0x7D($a2)
    MEM_B(0X7D, ctx->r6) = ctx->r4;
    // 0x80465214: sb          $a0, 0x7C($a2)
    MEM_B(0X7C, ctx->r6) = ctx->r4;
    // 0x80465218: sh          $v0, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r2;
    // 0x8046521C: sh          $t4, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r12;
    // 0x80465220: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x80465224: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x80465228: sh          $zero, 0x72($a2)
    MEM_H(0X72, ctx->r6) = 0;
    // 0x8046522C: bgez        $v1, L_804650E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80465230: sh          $t1, 0x70($a2)
        MEM_H(0X70, ctx->r6) = ctx->r9;
            goto L_804650E4;
    }
    // 0x80465230: sh          $t1, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r9;
    // 0x80465234: jr          $ra
    // 0x80465238: nop

    return;
    // 0x80465238: nop

;}
RECOMP_FUNC void func_805AE5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE5C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE5C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE5CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE5D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE5D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE5D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE5DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE5E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE5E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE5E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE5EC: jr          $ra
    // 0x805AE5F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE5F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80737208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737208: lui         $a3, 0x8074
    ctx->r7 = S32(RELOC_HI16(736, 0X3908) << 16);
    // 0x8073720C: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X3918) << 16);
    // 0x80737210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737214: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737218: addiu       $t1, $t1, -0x6C88
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(736, 0X3918));
    // 0x8073721C: addiu       $a3, $a3, -0x6C98
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(736, 0X3908));
    // 0x80737220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80737224: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80737228:
    // 0x80737228: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8073722C: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x80737230: lw          $t7, 0x18($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X18);
    // 0x80737234: lw          $t2, 0x1C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X1C);
    // 0x80737238: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073723C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80737240: bgez        $t2, L_80737254
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80737244: lw          $v1, 0x0($t9)
        ctx->r3 = MEM_W(ctx->r25, 0X0);
            goto L_80737254;
    }
    // 0x80737244: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80737248: sb          $t0, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r8;
    // 0x8073724C: b           L_80737268
    // 0x80737250: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
        goto L_80737268;
    // 0x80737250: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
L_80737254:
    // 0x80737254: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
    // 0x80737258: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x8073725C: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80737260: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x80737264: sh          $t5, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r13;
L_80737268:
    // 0x80737268: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8073726C: bnel        $t6, $zero, L_80737294
    if (ctx->r14 != 0) {
        // 0x80737270: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_80737294;
    }
    goto skip_0;
    // 0x80737270: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80737274: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80737278: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8073727C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80737280: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80737284: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80737288: b           L_807372AC
    // 0x8073728C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_807372AC;
    // 0x8073728C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x80737290: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_80737294:
    // 0x80737294: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80737298: addu        $t2, $t9, $a1
    ctx->r10 = ADD32(ctx->r25, ctx->r5);
    // 0x8073729C: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x807372A0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x807372A4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807372A8: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_807372AC:
    // 0x807372AC: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x807372B0: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807372B4: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x807372B8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x807372BC: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x807372C0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807372C4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x807372C8: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x807372CC: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    // 0x807372D0: bnel        $t5, $zero, L_8073731C
    if (ctx->r13 != 0) {
        // 0x807372D4: lwc1        $f10, 0x34($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
            goto L_8073731C;
    }
    goto skip_1;
    // 0x807372D4: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    skip_1:
    // 0x807372D8: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x807372DC: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x807372E0: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x807372E4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807372E8: nop

    // 0x807372EC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807372F0: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x807372F4: swc1        $f18, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f18.u32l;
    // 0x807372F8: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x807372FC: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80737300: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80737304: nop

    // 0x80737308: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8073730C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80737310: b           L_80737354
    // 0x80737314: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
        goto L_80737354;
    // 0x80737314: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80737318: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
L_8073731C:
    // 0x8073731C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80737320: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80737324: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80737328: nop

    // 0x8073732C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80737330: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80737334: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x80737338: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8073733C: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80737340: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80737344: nop

    // 0x80737348: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8073734C: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80737350: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
L_80737354:
    // 0x80737354: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80737358: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8073735C: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x80737360: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80737364: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x80737368: lwc1        $f6, -0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8073736C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80737370: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80737374: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80737378: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8073737C: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80737380: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80737384: swc1        $f4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f4.u32l;
    // 0x80737388: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8073738C: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80737390: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80737394: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80737398: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8073739C: swc1        $f6, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f6.u32l;
    // 0x807373A0: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    // 0x807373A4: bnel        $t2, $zero, L_807373CC
    if (ctx->r10 != 0) {
        // 0x807373A8: lw          $t5, 0x10($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X10);
            goto L_807373CC;
    }
    goto skip_2;
    // 0x807373A8: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    skip_2:
    // 0x807373AC: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x807373B0: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807373B4: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x807373B8: lwc1        $f10, 0x10($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X10);
    // 0x807373BC: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x807373C0: b           L_807373E0
    // 0x807373C4: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
        goto L_807373E0;
    // 0x807373C4: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
    // 0x807373C8: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
L_807373CC:
    // 0x807373CC: lwc1        $f18, 0x50($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807373D0: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x807373D4: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x807373D8: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x807373DC: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
L_807373E0:
    // 0x807373E0: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x807373E4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x807373E8: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x807373EC: bnel        $t9, $zero, L_80737404
    if (ctx->r25 != 0) {
        // 0x807373F0: lw          $t3, 0x138($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X138);
            goto L_80737404;
    }
    goto skip_3;
    // 0x807373F0: lw          $t3, 0x138($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X138);
    skip_3:
    // 0x807373F4: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    // 0x807373F8: b           L_8073740C
    // 0x807373FC: sw          $t2, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r10;
        goto L_8073740C;
    // 0x807373FC: sw          $t2, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r10;
    // 0x80737400: lw          $t3, 0x138($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X138);
L_80737404:
    // 0x80737404: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x80737408: sw          $t4, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r12;
L_8073740C:
    // 0x8073740C: bne         $a3, $t1, L_80737228
    if (ctx->r7 != ctx->r9) {
        // 0x80737410: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_80737228;
    }
    // 0x80737410: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80737414: jr          $ra
    // 0x80737418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80737418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807BB344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB344: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807BB348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB34C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB350: jal         0x807BAF34
    // 0x807BB354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807BAF34(rdram, ctx);
        goto after_0;
    // 0x807BB354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807BB358: jal         0x807BA848
    // 0x807BB35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BA848(rdram, ctx);
        goto after_1;
    // 0x807BB35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BB360: jal         0x807BAC0C
    // 0x807BB364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAC0C(rdram, ctx);
        goto after_2;
    // 0x807BB364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BB368: jal         0x807BAB94
    // 0x807BB36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_3;
    // 0x807BB36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807BB370: jal         0x807BAA20
    // 0x807BB374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAA20(rdram, ctx);
        goto after_4;
    // 0x807BB374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807BB378: beq         $v0, $zero, L_807BB3D4
    if (ctx->r2 == 0) {
        // 0x807BB37C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BB3D4;
    }
    // 0x807BB37C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB380: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x807BB384: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x807BB388: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x807BB38C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB390: jal         0x807BB7A4
    // 0x807BB394: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807BB7A4(rdram, ctx);
        goto after_5;
    // 0x807BB394: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x807BB398: jal         0x800653D8
    // 0x807BB39C: nop

    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x807BB39C: nop

    after_6:
    // 0x807BB3A0: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x807BB3A4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x807BB3A8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X124C) << 16);
    // 0x807BB3AC: lwc1        $f8, -0x45A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X124C));
    // 0x807BB3B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807BB3B4: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1250) << 16);
    // 0x807BB3B8: lwc1        $f16, -0x45A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1250));
    // 0x807BB3BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807BB3C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807BB3C4: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x807BB3C8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x807BB3CC: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x807BB3D0: swc1        $f6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f6.u32l;
L_807BB3D4:
    // 0x807BB3D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB3D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB3DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807BB3E0: jr          $ra
    // 0x807BB3E4: nop

    return;
    // 0x807BB3E4: nop

;}
RECOMP_FUNC void func_806F70B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F70B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F70BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F70C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F70C4: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806F70C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F70CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F70D0: bnel        $t6, $zero, L_806F710C
    if (ctx->r14 != 0) {
        // 0x806F70D4: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806F710C;
    }
    goto skip_0;
    // 0x806F70D4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806F70D8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F70DC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806F70E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F70E4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806F70E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F70EC: nop

    // 0x806F70F0: bc1fl       L_806F7134
    if (!c1cs) {
        // 0x806F70F4: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806F7134;
    }
    goto skip_1;
    // 0x806F70F4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x806F70F8: jal         0x806F73DC
    // 0x806F70FC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F73DC(rdram, ctx);
        goto after_0;
    // 0x806F70FC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_0:
    // 0x806F7100: b           L_806F7134
    // 0x806F7104: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_806F7134;
    // 0x806F7104: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806F7108: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_806F710C:
    // 0x806F710C: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806F7110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F7114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7118: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806F711C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806F7120: bc1fl       L_806F7134
    if (!c1cs) {
        // 0x806F7124: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806F7134;
    }
    goto skip_2;
    // 0x806F7124: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_2:
    // 0x806F7128: jal         0x806F73DC
    // 0x806F712C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F73DC(rdram, ctx);
        goto after_1;
    // 0x806F712C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806F7130: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806F7134:
    // 0x806F7134: jal         0x806F6E20
    // 0x806F7138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806F6E20(rdram, ctx);
        goto after_2;
    // 0x806F7138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806F713C: jal         0x806F6F08
    // 0x806F7140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F6F08(rdram, ctx);
        goto after_3;
    // 0x806F7140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F7144: jal         0x806F6F64
    // 0x806F7148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F6F64(rdram, ctx);
        goto after_4;
    // 0x806F7148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F714C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F7150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F7154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F7158: jr          $ra
    // 0x806F715C: nop

    return;
    // 0x806F715C: nop

;}
RECOMP_FUNC void func_8004A924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A924: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A928: jr          $ra
    // 0x8004A92C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8004A92C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8003F5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F5DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F5E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F5E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F5E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F5EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F5F0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F5F4: jal         0x8003EBD4
    // 0x8003F5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F5FC: jal         0x8003E520
    // 0x8003F600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_1;
    // 0x8003F600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003F604: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003F608: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003F60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F610: jalr        $t9
    // 0x8003F614: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8003F614: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_2:
    // 0x8003F618: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F61C: addiu       $t6, $t6, -0x1A14
    ctx->r14 = ADD32(ctx->r14, -0X1A14);
    // 0x8003F620: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F624: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F628: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F62C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F630: jal         0x8003E6C4
    // 0x8003F634: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_3;
    // 0x8003F634: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8003F638: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8003F63C: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x8003F640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F644: jal         0x8003F14C
    // 0x8003F648: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8003F14C(rdram, ctx);
        goto after_4;
    // 0x8003F648: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8003F64C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F650: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F658: jr          $ra
    // 0x8003F65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003F65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_805D1608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D160C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1610: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805D1614: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805D1618: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(465, 0X690) << 16);
    // 0x805D161C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805D1620: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D1624: addiu       $t7, $t7, 0x1680
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(465, 0X690));
    // 0x805D1628: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805D162C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D1630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D1634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D1638: jal         0x805D15B8
    // 0x805D163C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805D15B8(rdram, ctx);
        goto after_0;
    // 0x805D163C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x805D1640: jal         0x805D1570
    // 0x805D1644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805D1570(rdram, ctx);
        goto after_1;
    // 0x805D1644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805D1648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D164C: lui         $t9, 0x805D
    ctx->r25 = S32(RELOC_HI16(465, 0XE4) << 16);
    // 0x805D1650: addiu       $t9, $t9, 0x10D4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(465, 0XE4));
    // 0x805D1654: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805D1658: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D165C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x805D1660: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x805D1664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D1668: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805D166C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805D1670: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x805D1674: jr          $ra
    // 0x805D1678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805D1678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D167C: nop

;}
RECOMP_FUNC void func_80447AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447AE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447AE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447AF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447AF4: bne         $a2, $zero, L_80447B34
    if (ctx->r6 != 0) {
        // 0x80447AF8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447B34;
    }
    // 0x80447AF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447AFC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80447B00: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x80447B04: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80447B08: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80447B0C: bne         $at, $zero, L_80447B74
    if (ctx->r1 != 0) {
        // 0x80447B10: sw          $t7, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r15;
            goto L_80447B74;
    }
    // 0x80447B10: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80447B14: jal         0x8044625C
    // 0x80447B18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044625C(rdram, ctx);
        goto after_0;
    // 0x80447B18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80447B1C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447B20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447B24: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80447B28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447B2C: b           L_80447B74
    // 0x80447B30: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80447B74;
    // 0x80447B30: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80447B34:
    // 0x80447B34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447B38: bnel        $a2, $at, L_80447B64
    if (ctx->r6 != ctx->r1) {
        // 0x80447B3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447B64;
    }
    goto skip_0;
    // 0x80447B3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447B40: jal         0x8044625C
    // 0x80447B44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044625C(rdram, ctx);
        goto after_1;
    // 0x80447B44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447B48: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447B4C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447B50: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80447B54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447B58: b           L_80447B74
    // 0x80447B5C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80447B74;
    // 0x80447B5C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80447B60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447B64:
    // 0x80447B64: bnel        $a2, $at, L_80447B78
    if (ctx->r6 != ctx->r1) {
        // 0x80447B68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447B78;
    }
    goto skip_1;
    // 0x80447B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447B6C: jal         0x804462B4
    // 0x80447B70: nop

    func_804462B4(rdram, ctx);
        goto after_2;
    // 0x80447B70: nop

    after_2:
L_80447B74:
    // 0x80447B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447B78:
    // 0x80447B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447B80: jr          $ra
    // 0x80447B84: nop

    return;
    // 0x80447B84: nop

;}
RECOMP_FUNC void func_805C836C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C836C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805C8370: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8374: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8378: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C837C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8380: jal         0x8004700C
    // 0x805C8384: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C8384: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x805C8388: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(447, 0X3B28) << 16);
    // 0x805C838C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x805C8390: addiu       $t7, $t7, -0x5FE8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(447, 0X3B28));
    // 0x805C8394: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x805C8398: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C839C: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x805C83A0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x805C83A4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x805C83A8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805C83AC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x805C83B0: beq         $v0, $zero, L_805C88F0
    if (ctx->r2 == 0) {
        // 0x805C83B4: sw          $t8, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->r24;
            goto L_805C88F0;
    }
    // 0x805C83B4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x805C83B8: lw          $t0, 0x4C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4C);
    // 0x805C83BC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C83C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C83C4: beq         $t0, $zero, L_805C83D4
    if (ctx->r8 == 0) {
        // 0x805C83C8: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_805C83D4;
    }
    // 0x805C83C8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805C83CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C83D0: nop

L_805C83D4:
    // 0x805C83D4: lw          $t1, 0x64($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X64);
    // 0x805C83D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C83DC: beql        $t1, $zero, L_805C8400
    if (ctx->r9 == 0) {
        // 0x805C83E0: sw          $zero, 0x20($a3)
        MEM_W(0X20, ctx->r7) = 0;
            goto L_805C8400;
    }
    goto skip_0;
    // 0x805C83E0: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    skip_0:
    // 0x805C83E4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x805C83E8: jal         0x805C6E30
    // 0x805C83EC: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    func_805C6E30(rdram, ctx);
        goto after_1;
    // 0x805C83EC: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x805C83F0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C83F4: beq         $v0, $zero, L_805C8440
    if (ctx->r2 == 0) {
        // 0x805C83F8: lwc1        $f14, 0x30($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
            goto L_805C8440;
    }
    // 0x805C83F8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C83FC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
L_805C8400:
    // 0x805C8400: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x805C8404: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    // 0x805C8408: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x805C840C: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x805C8410: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x805C8414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8418: jal         0x805C74C8
    // 0x805C841C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_2;
    // 0x805C841C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x805C8420: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C8424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C842C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805C8430: jal         0x805C9D10
    // 0x805C8434: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    func_805C9D10(rdram, ctx);
        goto after_3;
    // 0x805C8434: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    after_3:
    // 0x805C8438: b           L_805C88F4
    // 0x805C843C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C88F4;
    // 0x805C843C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8440:
    // 0x805C8440: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x805C8444: lw          $t2, -0x7CE8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7CE8);
    // 0x805C8448: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C844C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x805C8450: lwc1        $f6, 0x30($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X30);
    // 0x805C8454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C8458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C845C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C8460: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C8464: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805C8468: nop

    // 0x805C846C: bc1f        L_805C86CC
    if (!c1cs) {
        // 0x805C8470: nop
    
            goto L_805C86CC;
    }
    // 0x805C8470: nop

    // 0x805C8474: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x805C8478: jal         0x805C6E30
    // 0x805C847C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    func_805C6E30(rdram, ctx);
        goto after_4;
    // 0x805C847C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x805C8480: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C8484: bne         $v0, $zero, L_805C86CC
    if (ctx->r2 != 0) {
        // 0x805C8488: lwc1        $f14, 0x30($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
            goto L_805C86CC;
    }
    // 0x805C8488: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C848C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805C8490: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805C8494: lh          $t3, 0xADE($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XADE);
    // 0x805C8498: lh          $t4, 0xAFE($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XAFE);
    // 0x805C849C: lh          $t5, 0xAE0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0XAE0);
    // 0x805C84A0: lh          $t6, 0xB00($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XB00);
    // 0x805C84A4: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x805C84A8: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C84AC: subu        $v1, $t5, $t6
    ctx->r3 = SUB32(ctx->r13, ctx->r14);
    // 0x805C84B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x805C84B4: mflo        $t7
    ctx->r15 = lo;
    // 0x805C84B8: nop

    // 0x805C84BC: nop

    // 0x805C84C0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C84C4: mflo        $t8
    ctx->r24 = lo;
    // 0x805C84C8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x805C84CC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x805C84D0: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(447, 0X3AFC) << 16);
    // 0x805C84D4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805C84D8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x805C84DC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x805C84E0: nop

    // 0x805C84E4: bc1fl       L_805C8544
    if (!c1cs) {
        // 0x805C84E8: lw          $v0, 0x30($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X30);
            goto L_805C8544;
    }
    goto skip_1;
    // 0x805C84E8: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
    skip_1:
    // 0x805C84EC: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x805C84F0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x805C84F4: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x805C84F8: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x805C84FC: beq         $t1, $at, L_805C8540
    if (ctx->r9 == ctx->r1) {
        // 0x805C8500: andi        $t2, $v0, 0x4000
        ctx->r10 = ctx->r2 & 0X4000;
            goto L_805C8540;
    }
    // 0x805C8500: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x805C8504: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x805C8508: beq         $t2, $at, L_805C8540
    if (ctx->r10 == ctx->r1) {
        // 0x805C850C: andi        $t3, $v0, 0x2
        ctx->r11 = ctx->r2 & 0X2;
            goto L_805C8540;
    }
    // 0x805C850C: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x805C8510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805C8514: beq         $t3, $at, L_805C8540
    if (ctx->r11 == ctx->r1) {
        // 0x805C8518: andi        $t4, $v0, 0x4
        ctx->r12 = ctx->r2 & 0X4;
            goto L_805C8540;
    }
    // 0x805C8518: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x805C851C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x805C8520: beq         $t4, $at, L_805C8540
    if (ctx->r12 == ctx->r1) {
        // 0x805C8524: andi        $t5, $v0, 0x8
        ctx->r13 = ctx->r2 & 0X8;
            goto L_805C8540;
    }
    // 0x805C8524: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x805C8528: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805C852C: beq         $t5, $at, L_805C8540
    if (ctx->r13 == ctx->r1) {
        // 0x805C8530: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_805C8540;
    }
    // 0x805C8530: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x805C8534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805C8538: bnel        $t6, $at, L_805C8560
    if (ctx->r14 != ctx->r1) {
        // 0x805C853C: lw          $v0, 0x64($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X64);
            goto L_805C8560;
    }
    goto skip_2;
    // 0x805C853C: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    skip_2:
L_805C8540:
    // 0x805C8540: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
L_805C8544:
    // 0x805C8544: lw          $t7, -0x6014($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(447, 0X3AFC));
    // 0x805C8548: beq         $v0, $zero, L_805C857C
    if (ctx->r2 == 0) {
        // 0x805C854C: sw          $t7, 0x64($a3)
        MEM_W(0X64, ctx->r7) = ctx->r15;
            goto L_805C857C;
    }
    // 0x805C854C: sw          $t7, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r15;
    // 0x805C8550: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805C8554: b           L_805C857C
    // 0x805C8558: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
        goto L_805C857C;
    // 0x805C8558: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x805C855C: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
L_805C8560:
    // 0x805C8560: beql        $v0, $zero, L_805C8580
    if (ctx->r2 == 0) {
        // 0x805C8564: lw          $t1, 0x24($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X24);
            goto L_805C8580;
    }
    goto skip_3;
    // 0x805C8564: lw          $t1, 0x24($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X24);
    skip_3:
    // 0x805C8568: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x805C856C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x805C8570: bnel        $t9, $zero, L_805C8580
    if (ctx->r25 != 0) {
        // 0x805C8574: lw          $t1, 0x24($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X24);
            goto L_805C8580;
    }
    goto skip_4;
    // 0x805C8574: lw          $t1, 0x24($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X24);
    skip_4:
    // 0x805C8578: sw          $t0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r8;
L_805C857C:
    // 0x805C857C: lw          $t1, 0x24($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X24);
L_805C8580:
    // 0x805C8580: bnel        $t1, $zero, L_805C85EC
    if (ctx->r9 != 0) {
        // 0x805C8584: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805C85EC;
    }
    goto skip_5;
    // 0x805C8584: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_5:
    // 0x805C8588: lw          $t2, 0x478($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X478);
    // 0x805C858C: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8590: lwc1        $f12, 0x30($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X30);
    // 0x805C8594: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805C8598: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C859C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805C85A0: nop

    // 0x805C85A4: bc1fl       L_805C85EC
    if (!c1cs) {
        // 0x805C85A8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805C85EC;
    }
    goto skip_6;
    // 0x805C85A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_6:
    // 0x805C85AC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x805C85B0: addiu       $t3, $s0, 0xC4
    ctx->r11 = ADD32(ctx->r16, 0XC4);
    // 0x805C85B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805C85B8: bc1fl       L_805C85D8
    if (!c1cs) {
        // 0x805C85BC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_805C85D8;
    }
    goto skip_7;
    // 0x805C85BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_7:
    // 0x805C85C0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805C85C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C85C8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x805C85CC: b           L_805C8608
    // 0x805C85D0: swc1        $f18, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f18.u32l;
        goto L_805C8608;
    // 0x805C85D0: swc1        $f18, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f18.u32l;
    // 0x805C85D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_805C85D8:
    // 0x805C85D8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805C85DC: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x805C85E0: b           L_805C8608
    // 0x805C85E4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_805C8608;
    // 0x805C85E4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x805C85E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_805C85EC:
    // 0x805C85EC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805C85F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C85F4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x805C85F8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x805C85FC: jal         0x805C72B0
    // 0x805C8600: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805C72B0(rdram, ctx);
        goto after_5;
    // 0x805C8600: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
    // 0x805C8604: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_805C8608:
    // 0x805C8608: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x805C860C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x805C8610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8614: bne         $t5, $zero, L_805C86B4
    if (ctx->r13 != 0) {
        // 0x805C8618: nop
    
            goto L_805C86B4;
    }
    // 0x805C8618: nop

    // 0x805C861C: lwc1        $f8, 0x84($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X84);
    // 0x805C8620: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8624: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805C8628: nop

    // 0x805C862C: bc1fl       L_805C8678
    if (!c1cs) {
        // 0x805C8630: lw          $t9, 0x138($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X138);
            goto L_805C8678;
    }
    goto skip_8;
    // 0x805C8630: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    skip_8:
    // 0x805C8634: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x805C8638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C863C: bne         $t7, $zero, L_805C8664
    if (ctx->r15 != 0) {
        // 0x805C8640: nop
    
            goto L_805C8664;
    }
    // 0x805C8640: nop

    // 0x805C8644: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x805C8648: bne         $t8, $zero, L_805C8664
    if (ctx->r24 != 0) {
        // 0x805C864C: nop
    
            goto L_805C8664;
    }
    // 0x805C864C: nop

    // 0x805C8650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8654: jal         0x805C7844
    // 0x805C8658: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C7844(rdram, ctx);
        goto after_6;
    // 0x805C8658: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_6:
    // 0x805C865C: b           L_805C8724
    // 0x805C8660: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
        goto L_805C8724;
    // 0x805C8660: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_805C8664:
    // 0x805C8664: jal         0x805C79B4
    // 0x805C8668: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C79B4(rdram, ctx);
        goto after_7;
    // 0x805C8668: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_7:
    // 0x805C866C: b           L_805C8724
    // 0x805C8670: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
        goto L_805C8724;
    // 0x805C8670: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C8674: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
L_805C8678:
    // 0x805C8678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C867C: beq         $t9, $zero, L_805C86A4
    if (ctx->r25 == 0) {
        // 0x805C8680: nop
    
            goto L_805C86A4;
    }
    // 0x805C8680: nop

    // 0x805C8684: lw          $t0, 0x24($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X24);
    // 0x805C8688: bne         $t0, $zero, L_805C86A4
    if (ctx->r8 != 0) {
        // 0x805C868C: nop
    
            goto L_805C86A4;
    }
    // 0x805C868C: nop

    // 0x805C8690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8694: jal         0x805C7844
    // 0x805C8698: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C7844(rdram, ctx);
        goto after_8;
    // 0x805C8698: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_8:
    // 0x805C869C: b           L_805C8724
    // 0x805C86A0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
        goto L_805C8724;
    // 0x805C86A0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_805C86A4:
    // 0x805C86A4: jal         0x805C79B4
    // 0x805C86A8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C79B4(rdram, ctx);
        goto after_9;
    // 0x805C86A8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_9:
    // 0x805C86AC: b           L_805C8724
    // 0x805C86B0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
        goto L_805C8724;
    // 0x805C86B0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_805C86B4:
    // 0x805C86B4: jal         0x805C6E78
    // 0x805C86B8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C6E78(rdram, ctx);
        goto after_10;
    // 0x805C86B8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_10:
    // 0x805C86BC: jal         0x805C7844
    // 0x805C86C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_11;
    // 0x805C86C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x805C86C4: b           L_805C8724
    // 0x805C86C8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
        goto L_805C8724;
    // 0x805C86C8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_805C86CC:
    // 0x805C86CC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805C86D0: lw          $t1, -0x7CE8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CE8);
    // 0x805C86D4: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C86D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805C86DC: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x805C86E0: lui         $at, 0xC090
    ctx->r1 = S32(0XC090 << 16);
    // 0x805C86E4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x805C86E8: nop

    // 0x805C86EC: bc1fl       L_805C870C
    if (!c1cs) {
        // 0x805C86F0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_805C870C;
    }
    goto skip_9;
    // 0x805C86F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_9:
    // 0x805C86F4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x805C86F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C86FC: sw          $t2, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r10;
    // 0x805C8700: b           L_805C8714
    // 0x805C8704: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
        goto L_805C8714;
    // 0x805C8704: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x805C8708: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_805C870C:
    // 0x805C870C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805C8710: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
L_805C8714:
    // 0x805C8714: jal         0x805C7844
    // 0x805C8718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_12;
    // 0x805C8718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x805C871C: b           L_805C88F4
    // 0x805C8720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C88F4;
    // 0x805C8720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8724:
    // 0x805C8724: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x805C8728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C872C: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x805C8730: lbu         $t5, 0x111($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X111);
    // 0x805C8734: beql        $t5, $zero, L_805C87B4
    if (ctx->r13 == 0) {
        // 0x805C8738: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_805C87B4;
    }
    goto skip_10;
    // 0x805C8738: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    skip_10:
    // 0x805C873C: jal         0x805C6E30
    // 0x805C8740: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C6E30(rdram, ctx);
        goto after_13;
    // 0x805C8740: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_13:
    // 0x805C8744: bne         $v0, $zero, L_805C87B0
    if (ctx->r2 != 0) {
        // 0x805C8748: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_805C87B0;
    }
    // 0x805C8748: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C874C: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x805C8750: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x805C8754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8758: bne         $t6, $zero, L_805C87B0
    if (ctx->r14 != 0) {
        // 0x805C875C: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_805C87B0;
    }
    // 0x805C875C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8760: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8764: sw          $t7, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r15;
    // 0x805C8768: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x805C876C: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x805C8770: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x805C8774: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x805C8778: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C877C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C8780: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x805C8784: jal         0x805C74C8
    // 0x805C8788: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C74C8(rdram, ctx);
        goto after_14;
    // 0x805C8788: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_14:
    // 0x805C878C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C8790: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x805C8794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C879C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x805C87A0: jal         0x805C9D10
    // 0x805C87A4: sw          $t9, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r25;
    func_805C9D10(rdram, ctx);
        goto after_15;
    // 0x805C87A4: sw          $t9, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r25;
    after_15:
    // 0x805C87A8: b           L_805C88F4
    // 0x805C87AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C88F4;
    // 0x805C87AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C87B0:
    // 0x805C87B0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
L_805C87B4:
    // 0x805C87B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C87B8: lw          $t1, 0x1F4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1F4);
    // 0x805C87BC: lbu         $t2, 0x111($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X111);
    // 0x805C87C0: bnel        $t2, $zero, L_805C88DC
    if (ctx->r10 != 0) {
        // 0x805C87C4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_805C88DC;
    }
    goto skip_11;
    // 0x805C87C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_11:
    // 0x805C87C8: jal         0x805C6E30
    // 0x805C87CC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C6E30(rdram, ctx);
        goto after_16;
    // 0x805C87CC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_16:
    // 0x805C87D0: bne         $v0, $zero, L_805C88D8
    if (ctx->r2 != 0) {
        // 0x805C87D4: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_805C88D8;
    }
    // 0x805C87D4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C87D8: lw          $t3, 0x4C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4C);
    // 0x805C87DC: bnel        $t3, $zero, L_805C88DC
    if (ctx->r11 != 0) {
        // 0x805C87E0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_805C88DC;
    }
    goto skip_12;
    // 0x805C87E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_12:
    // 0x805C87E4: lw          $t4, 0x24($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X24);
    // 0x805C87E8: bnel        $t4, $zero, L_805C88DC
    if (ctx->r12 != 0) {
        // 0x805C87EC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_805C88DC;
    }
    goto skip_13;
    // 0x805C87EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_13:
    // 0x805C87F0: lw          $t5, 0x30($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X30);
    // 0x805C87F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805C87F8: bnel        $t5, $zero, L_805C88DC
    if (ctx->r13 != 0) {
        // 0x805C87FC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_805C88DC;
    }
    goto skip_14;
    // 0x805C87FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_14:
    // 0x805C8800: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805C8804: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x805C8808: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C880C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x805C8810: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805C8814: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805C8818: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C881C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x805C8820: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x805C8824: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BFC) << 16);
    // 0x805C8828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C882C: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x805C8830: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x805C8834: lwc1        $f18, -0x5F14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BFC));
    // 0x805C8838: swc1        $f18, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f18.u32l;
    // 0x805C883C: jal         0x805C781C
    // 0x805C8840: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_805C781C(rdram, ctx);
        goto after_17;
    // 0x805C8840: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_17:
    // 0x805C8844: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x805C8848: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X3970) << 16);
    // 0x805C884C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x805C8850: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x805C8854: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x805C8858: lw          $a2, -0x61A0($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(447, 0X3970));
    // 0x805C885C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C8860: jal         0x805C74C8
    // 0x805C8864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74C8(rdram, ctx);
        goto after_18;
    // 0x805C8864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x805C8868: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805C886C: jal         0x80067BBC
    // 0x805C8870: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_19;
    // 0x805C8870: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_19:
    // 0x805C8874: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x805C8878: jal         0x80067818
    // 0x805C887C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_20;
    // 0x805C887C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_20:
    // 0x805C8880: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x805C8884: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C888C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x805C8890: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x805C8894: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x805C8898: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805C889C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x805C88A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x805C88A4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x805C88A8: sw          $zero, 0x64($a3)
    MEM_W(0X64, ctx->r7) = 0;
    // 0x805C88AC: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x805C88B0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x805C88B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805C88B8: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x805C88BC: lw          $t9, 0x4C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4C);
    // 0x805C88C0: jalr        $t9
    // 0x805C88C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_21;
    // 0x805C88C4: nop

    after_21:
    // 0x805C88C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C88CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C88D0: jal         0x805C9D10
    // 0x805C88D4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_805C9D10(rdram, ctx);
        goto after_22;
    // 0x805C88D4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_22:
L_805C88D8:
    // 0x805C88D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_805C88DC:
    // 0x805C88DC: jal         0x80048F84
    // 0x805C88E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_23;
    // 0x805C88E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x805C88E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805C88E8: jal         0x80048F84
    // 0x805C88EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_24;
    // 0x805C88EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
L_805C88F0:
    // 0x805C88F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C88F4:
    // 0x805C88F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C88F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x805C88FC: jr          $ra
    // 0x805C8900: nop

    return;
    // 0x805C8900: nop

;}
RECOMP_FUNC void func_80039C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039C44: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039C48: addiu       $a0, $a0, 0x7240
    ctx->r4 = ADD32(ctx->r4, 0X7240);
    // 0x80039C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039C50: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039C54: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039C58: sw          $a0, 0x4278($at)
    MEM_W(0X4278, ctx->r1) = ctx->r4;
    // 0x80039C5C: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    // 0x80039C60: jal         0x8004667C
    // 0x80039C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80039C68: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039C6C: addiu       $a0, $a0, 0x7250
    ctx->r4 = ADD32(ctx->r4, 0X7250);
    // 0x80039C70: jal         0x80039ABC
    // 0x80039C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80039C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039C80: jr          $ra
    // 0x80039C84: nop

    return;
    // 0x80039C84: nop

;}
RECOMP_FUNC void func_80048E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048E30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80048E34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80048E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80048E3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80048E40: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80048E44: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x80048E48: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    // 0x80048E4C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80048E50: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80048E54: jal         0x80059040
    // 0x80048E58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80059040(rdram, ctx);
        goto after_0;
    // 0x80048E58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80048E5C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80048E60: jal         0x80059EBC
    // 0x80048E64: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    func_80059EBC(rdram, ctx);
        goto after_1;
    // 0x80048E64: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    after_1:
    // 0x80048E68: bnel        $v0, $zero, L_80048E8C
    if (ctx->r2 != 0) {
        // 0x80048E6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80048E8C;
    }
    goto skip_0;
    // 0x80048E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80048E70: jal         0x8005F960
    // 0x80048E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005F960(rdram, ctx);
        goto after_2;
    // 0x80048E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80048E78: bnel        $v0, $zero, L_80048E8C
    if (ctx->r2 != 0) {
        // 0x80048E7C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80048E8C;
    }
    goto skip_1;
    // 0x80048E7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80048E80: jal         0x80048D4C
    // 0x80048E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048D4C(rdram, ctx);
        goto after_3;
    // 0x80048E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80048E88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80048E8C:
    // 0x80048E8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80048E90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80048E94: jr          $ra
    // 0x80048E98: nop

    return;
    // 0x80048E98: nop

;}
RECOMP_FUNC void func_8045FA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FA68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045FA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045FA70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8045FA74: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8045FA78: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8045FA7C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045FA80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045FA84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045FA88: jal         0x8045FAB0
    // 0x8045FA8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8045FAB0(rdram, ctx);
        goto after_0;
    // 0x8045FA8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8045FA90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045FA94: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8045FA98: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8045FA9C: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x8045FAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045FAA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045FAA8: jr          $ra
    // 0x8045FAAC: nop

    return;
    // 0x8045FAAC: nop

;}
RECOMP_FUNC void func_80465EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80465EC4: jal         0x80045A34
    // 0x80465EC8: addiu       $a1, $zero, 0x2860
    ctx->r5 = ADD32(0, 0X2860);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80465EC8: addiu       $a1, $zero, 0x2860
    ctx->r5 = ADD32(0, 0X2860);
    after_0:
    // 0x80465ECC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80465ED0: beq         $v0, $zero, L_80465EE8
    if (ctx->r2 == 0) {
        // 0x80465ED4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80465EE8;
    }
    // 0x80465ED4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80465ED8: jal         0x80465E90
    // 0x80465EDC: nop

    func_80465E90(rdram, ctx);
        goto after_1;
    // 0x80465EDC: nop

    after_1:
    // 0x80465EE0: jal         0x80465CAC
    // 0x80465EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80465CAC(rdram, ctx);
        goto after_2;
    // 0x80465EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80465EE8:
    // 0x80465EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80465EF0: jr          $ra
    // 0x80465EF4: nop

    return;
    // 0x80465EF4: nop

;}
RECOMP_FUNC void func_80737194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737194: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737198: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(736, 0X3810) << 16);
    // 0x8073719C: addiu       $a1, $a1, -0x6D90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(736, 0X3810));
    // 0x807371A0: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x807371A4: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x807371A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807371AC: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x807371B0: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x807371B4: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x807371B8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x807371BC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x807371C0: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x807371C4: bne         $at, $zero, L_807371E4
    if (ctx->r1 != 0) {
        // 0x807371C8: slti        $at, $t2, 0x6
        ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
            goto L_807371E4;
    }
    // 0x807371C8: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x807371CC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x807371D0: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
    // 0x807371D4: bne         $at, $zero, L_807371E4
    if (ctx->r1 != 0) {
        // 0x807371D8: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_807371E4;
    }
    // 0x807371D8: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x807371DC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x807371E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_807371E4:
    // 0x807371E4: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x807371E8: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x807371EC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x807371F0: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X2650) << 16);
    // 0x807371F4: addiu       $t7, $t7, -0x7F50
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X2650));
    // 0x807371F8: sll         $t6, $t5, 7
    ctx->r14 = S32(ctx->r13 << 7);
    // 0x807371FC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80737200: jr          $ra
    // 0x80737204: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    return;
    // 0x80737204: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_805538A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805538A4: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x805538A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805538AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805538B0: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X416C) << 16);
    // 0x805538B4: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x805538B8: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x805538BC: lwc1        $f4, 0x4C8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X416C));
    // 0x805538C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805538C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x805538C8: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x805538CC: swc1        $f2, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f2.u32l;
    // 0x805538D0: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x805538D4: jr          $ra
    // 0x805538D8: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
    return;
    // 0x805538D8: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_804462B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804462B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804462B8: jr          $ra
    // 0x804462BC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    return;
    // 0x804462BC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8000A388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A38C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000A390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000A398: sll         $t6, $a2, 24
    ctx->r14 = S32(ctx->r6 << 24);
    // 0x8000A39C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000A3A0: jal         0x8000A2F4
    // 0x8000A3A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000A2F4(rdram, ctx);
        goto after_0;
    // 0x8000A3A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000A3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A3AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A3B0: jr          $ra
    // 0x8000A3B4: nop

    return;
    // 0x8000A3B4: nop

;}
RECOMP_FUNC void func_804300D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804300D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804300D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804300DC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804300E0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BC8) << 16);
    // 0x804300E4: lwc1        $f6, 0x1CA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BC8));
    // 0x804300E8: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x804300EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804300F0: nop

    // 0x804300F4: bc1f        L_8043010C
    if (!c1cs) {
        // 0x804300F8: nop
    
            goto L_8043010C;
    }
    // 0x804300F8: nop

    // 0x804300FC: jal         0x804301BC
    // 0x80430100: nop

    func_804301BC(rdram, ctx);
        goto after_0;
    // 0x80430100: nop

    after_0:
    // 0x80430104: b           L_80430118
    // 0x80430108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80430118;
    // 0x80430108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043010C:
    // 0x8043010C: jal         0x80430174
    // 0x80430110: nop

    func_80430174(rdram, ctx);
        goto after_1;
    // 0x80430110: nop

    after_1:
    // 0x80430114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430118:
    // 0x80430118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043011C: jr          $ra
    // 0x80430120: nop

    return;
    // 0x80430120: nop

;}
RECOMP_FUNC void func_8041D6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D6D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041D6D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8041D6DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8041D6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041D6E4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8041D6E8: jal         0x80067878
    // 0x8041D6EC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8041D6EC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8041D6F0: jal         0x80045BD8
    // 0x8041D6F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8041D6F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8041D6F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041D6FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041D700: jr          $ra
    // 0x8041D704: nop

    return;
    // 0x8041D704: nop

;}
RECOMP_FUNC void func_8004733C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004733C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80047348: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004734C: lhu         $t6, 0xC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XC);
    // 0x80047350: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80047354: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80047358: beq         $t6, $at, L_800473B4
    if (ctx->r14 == ctx->r1) {
        // 0x8004735C: nop
    
            goto L_800473B4;
    }
    // 0x8004735C: nop

    // 0x80047360: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x80047364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047368: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8004736C: beq         $t8, $at, L_800473B4
    if (ctx->r24 == ctx->r1) {
        // 0x80047370: nop
    
            goto L_800473B4;
    }
    // 0x80047370: nop

    // 0x80047374: lwc1        $f4, 0x8C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8C);
    // 0x80047378: lwc1        $f6, 0xB0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x8004737C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80047380: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80047384: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80047388: nop

    // 0x8004738C: bc1f        L_800473B4
    if (!c1cs) {
        // 0x80047390: nop
    
            goto L_800473B4;
    }
    // 0x80047390: nop

    // 0x80047394: lw          $t9, 0x3F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3F4);
    // 0x80047398: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8004739C: bne         $t0, $zero, L_800473B4
    if (ctx->r8 != 0) {
        // 0x800473A0: nop
    
            goto L_800473B4;
    }
    // 0x800473A0: nop

    // 0x800473A4: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x800473A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800473AC: bnel        $t1, $at, L_800473CC
    if (ctx->r9 != ctx->r1) {
        // 0x800473B0: lw          $t2, 0x478($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X478);
            goto L_800473CC;
    }
    goto skip_0;
    // 0x800473B0: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
    skip_0:
L_800473B4:
    // 0x800473B4: jal         0x80047128
    // 0x800473B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80047128(rdram, ctx);
        goto after_0;
    // 0x800473B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800473BC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800473C0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800473C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800473C8: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
L_800473CC:
    // 0x800473CC: lwc1        $f8, 0x84($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X84);
    // 0x800473D0: lwc1        $f18, 0xB8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XB8);
    // 0x800473D4: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800473D8: lwc1        $f6, 0xB4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB4);
    // 0x800473DC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800473E0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800473E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800473E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800473EC: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800473F0: lw          $t4, 0x478($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X478);
    // 0x800473F4: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x800473F8: lwc1        $f4, 0xBC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XBC);
    // 0x800473FC: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80047400: lwc1        $f8, 0xB4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XB4);
    // 0x80047404: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80047408: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004740C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80047410: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047414: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80047418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004741C: lwc1        $f0, 0xB4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XB4);
    // 0x80047420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047424: jr          $ra
    // 0x80047428: nop

    return;
    // 0x80047428: nop

;}
RECOMP_FUNC void func_8040B1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B1D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B1E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B1E4: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(14, 0X1128) << 16);
    // 0x8040B1E8: addiu       $t1, $t1, -0x4378
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(14, 0X1128));
    // 0x8040B1EC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8040B1F0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8040B1F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040B1F8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8040B1FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8040B200: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8040B204: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8040B208: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8040B20C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8040B210: jal         0x8040B0CC
    // 0x8040B214: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8040B0CC(rdram, ctx);
        goto after_0;
    // 0x8040B214: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_0:
    // 0x8040B218: beq         $v0, $zero, L_8040B22C
    if (ctx->r2 == 0) {
        // 0x8040B21C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040B22C;
    }
    // 0x8040B21C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B220: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(14, 0X608) << 16);
    // 0x8040B224: addiu       $t2, $t2, -0x4E98
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(14, 0X608));
    // 0x8040B228: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
L_8040B22C:
    // 0x8040B22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B234: jr          $ra
    // 0x8040B238: nop

    return;
    // 0x8040B238: nop

;}
RECOMP_FUNC void func_8075F6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F6F8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8075F6FC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8075F700: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8075F704: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8075F708: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8075F70C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8075F710: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8075F714: lui         $t1, 0x8076
    ctx->r9 = S32(RELOC_HI16(757, 0XD60) << 16);
    // 0x8075F718: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8075F71C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8075F720: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8075F724: lw          $t1, -0x550($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(757, 0XD60));
    // 0x8075F728: jr          $ra
    // 0x8075F72C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8075F72C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80050B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050B38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050B40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050B44: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80050B48: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80050B4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80050B50: beql        $t6, $zero, L_80050B98
    if (ctx->r14 == 0) {
        // 0x80050B54: lw          $t7, 0xC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XC);
            goto L_80050B98;
    }
    goto skip_0;
    // 0x80050B54: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80050B58: jal         0x80064DD0
    // 0x80050B5C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80050B5C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x80050B60: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80050B64: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80050B68: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80050B6C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80050B70: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80050B74: jal         0x800675D0
    // 0x80050B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80050B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80050B7C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80050B80: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80050B84: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x80050B88: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x80050B8C: jal         0x8005BA80
    // 0x80050B90: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    func_8005BA80(rdram, ctx);
        goto after_2;
    // 0x80050B90: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    after_2:
    // 0x80050B94: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
L_80050B98:
    // 0x80050B98: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80050B9C: addiu       $t8, $t8, 0x758C
    ctx->r24 = ADD32(ctx->r24, 0X758C);
    // 0x80050BA0: beql        $t7, $zero, L_80050BE8
    if (ctx->r15 == 0) {
        // 0x80050BA4: lw          $t9, 0x14($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X14);
            goto L_80050BE8;
    }
    goto skip_1;
    // 0x80050BA4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x80050BA8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80050BAC: jal         0x80064DD0
    // 0x80050BB0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_80064DD0(rdram, ctx);
        goto after_3;
    // 0x80050BB0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_3:
    // 0x80050BB4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80050BB8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80050BBC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80050BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050BC4: jal         0x800675D0
    // 0x80050BC8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800675D0(rdram, ctx);
        goto after_4;
    // 0x80050BC8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80050BCC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80050BD0: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x80050BD4: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x80050BD8: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x80050BDC: jal         0x8005BBC8
    // 0x80050BE0: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    func_8005BBC8(rdram, ctx);
        goto after_5;
    // 0x80050BE0: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    after_5:
    // 0x80050BE4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_80050BE8:
    // 0x80050BE8: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x80050BEC: addiu       $t0, $t0, 0x758C
    ctx->r8 = ADD32(ctx->r8, 0X758C);
    // 0x80050BF0: beql        $t9, $zero, L_80050C38
    if (ctx->r25 == 0) {
        // 0x80050BF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80050C38;
    }
    goto skip_2;
    // 0x80050BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80050BF8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80050BFC: jal         0x80064DD0
    // 0x80050C00: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_80064DD0(rdram, ctx);
        goto after_6;
    // 0x80050C00: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_6:
    // 0x80050C04: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80050C08: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80050C0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80050C10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050C14: jal         0x800675D0
    // 0x80050C18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800675D0(rdram, ctx);
        goto after_7;
    // 0x80050C18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80050C1C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80050C20: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80050C24: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    // 0x80050C28: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x80050C2C: jal         0x8005BD08
    // 0x80050C30: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    func_8005BD08(rdram, ctx);
        goto after_8;
    // 0x80050C30: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    after_8:
    // 0x80050C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80050C38:
    // 0x80050C38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050C3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80050C40: jr          $ra
    // 0x80050C44: nop

    return;
    // 0x80050C44: nop

;}
RECOMP_FUNC void func_804C971C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C971C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C9720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C9724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C9728: jal         0x804C95D0
    // 0x804C972C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C95D0(rdram, ctx);
        goto after_0;
    // 0x804C972C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C9730: jal         0x804C9658
    // 0x804C9734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C9658(rdram, ctx);
        goto after_1;
    // 0x804C9734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C9738: jal         0x804C9624
    // 0x804C973C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C9624(rdram, ctx);
        goto after_2;
    // 0x804C973C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804C9740: jal         0x804C9450
    // 0x804C9744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C9450(rdram, ctx);
        goto after_3;
    // 0x804C9744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C9748: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x804C974C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X780) << 16);
    // 0x804C9750: lw          $t8, 0x154($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X154);
    // 0x804C9754: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C9758: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804C975C: lwc1        $f4, -0x6540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X780));
    // 0x804C9760: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7F4) << 16);
    // 0x804C9764: lwc1        $f6, -0x64CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7F4));
    // 0x804C9768: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C976C: bne         $t8, $zero, L_804C979C
    if (ctx->r24 != 0) {
        // 0x804C9770: swc1        $f8, 0xDC($s0)
        MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
            goto L_804C979C;
    }
    // 0x804C9770: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x804C9774: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x804C9778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804C977C: bnel        $t9, $at, L_804C97A0
    if (ctx->r25 != ctx->r1) {
        // 0x804C9780: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C97A0;
    }
    goto skip_0;
    // 0x804C9780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C9784: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804C9788: jal         0x80067BBC
    // 0x804C978C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x804C978C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x804C9790: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x804C9794: jal         0x80067818
    // 0x804C9798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x804C9798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_804C979C:
    // 0x804C979C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C97A0:
    // 0x804C97A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C97A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C97A8: jr          $ra
    // 0x804C97AC: nop

    return;
    // 0x804C97AC: nop

;}
RECOMP_FUNC void func_805363B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805363B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805363B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805363BC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805363C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805363C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805363C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805363CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805363D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805363D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805363D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805363DC: jr          $ra
    // 0x805363E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805363E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C227C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C227C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C2280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C2284: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C2288: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804C228C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C2290: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(203, 0X1100) << 16);
    // 0x804C2294: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C2298: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C229C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C22A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C22A4: lw          $t8, 0x2870($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(203, 0X1100));
    // 0x804C22A8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C22AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C22B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C22B4: jal         0x80048490
    // 0x804C22B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C22B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804C22BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C22C0: jal         0x80048378
    // 0x804C22C4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804C22C4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804C22C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C22CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C22D0: jr          $ra
    // 0x804C22D4: nop

    return;
    // 0x804C22D4: nop

;}
RECOMP_FUNC void func_806EADA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EADA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EADAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806EADB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EADB4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806EADB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EADBC: jal         0x806EA844
    // 0x806EADC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806EA844(rdram, ctx);
        goto after_0;
    // 0x806EADC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806EADC4: jal         0x806EA9C0
    // 0x806EADC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806EA9C0(rdram, ctx);
        goto after_1;
    // 0x806EADC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806EADCC: jal         0x806EA92C
    // 0x806EADD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806EA92C(rdram, ctx);
        goto after_2;
    // 0x806EADD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806EADD4: beq         $v0, $zero, L_806EADF0
    if (ctx->r2 == 0) {
        // 0x806EADD8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806EADF0;
    }
    // 0x806EADD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EADDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806EADE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EADE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EADE8: jal         0x806EB43C
    // 0x806EADEC: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EADEC: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_3:
L_806EADF0:
    // 0x806EADF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EADF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EADF8: jr          $ra
    // 0x806EADFC: nop

    return;
    // 0x806EADFC: nop

;}
RECOMP_FUNC void func_80454FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454FD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80454FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454FE0: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13910) << 16);
    // 0x80454FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454FE8: jal         0x804548E4
    // 0x80454FEC: lw          $a1, 0x7CF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13910));
    func_804548E4(rdram, ctx);
        goto after_0;
    // 0x80454FEC: lw          $a1, 0x7CF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13910));
    after_0:
    // 0x80454FF0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80454FF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454FF8: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80454FFC: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x80455000: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455004: ori         $at, $at, 0x6DB4
    ctx->r1 = ctx->r1 | 0X6DB4;
    // 0x80455008: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x8045500C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455010: ori         $at, $at, 0x6DB8
    ctx->r1 = ctx->r1 | 0X6DB8;
    // 0x80455014: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80455018: addu        $a2, $v1, $at
    ctx->r6 = ADD32(ctx->r3, ctx->r1);
    // 0x8045501C: jal         0x804549D4
    // 0x80455020: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804549D4(rdram, ctx);
        goto after_1;
    // 0x80455020: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80455024: beq         $v0, $zero, L_8045504C
    if (ctx->r2 == 0) {
        // 0x80455028: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8045504C;
    }
    // 0x80455028: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8045502C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455030: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80455034: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80455038: sw          $t6, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r14;
    // 0x8045503C: jal         0x804457C0
    // 0x80455040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804457C0(rdram, ctx);
        goto after_2;
    // 0x80455040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80455044: jal         0x804535D4
    // 0x80455048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804535D4(rdram, ctx);
        goto after_3;
    // 0x80455048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8045504C:
    // 0x8045504C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80455050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80455054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80455058: jr          $ra
    // 0x8045505C: nop

    return;
    // 0x8045505C: nop

;}
RECOMP_FUNC void func_8003872C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003872C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038734: jal         0x80021958
    // 0x80038738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003873C: bne         $v0, $zero, L_8003874C
    if (ctx->r2 != 0) {
        // 0x80038740: nop
    
            goto L_8003874C;
    }
    // 0x80038740: nop

    // 0x80038744: b           L_80038780
    // 0x80038748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038780;
    // 0x80038748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003874C:
    // 0x8003874C: jal         0x80033FB0
    // 0x80038750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033FB0(rdram, ctx);
        goto after_1;
    // 0x80038750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038754: beq         $v0, $zero, L_80038764
    if (ctx->r2 == 0) {
        // 0x80038758: nop
    
            goto L_80038764;
    }
    // 0x80038758: nop

    // 0x8003875C: b           L_80038780
    // 0x80038760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038780;
    // 0x80038760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038764:
    // 0x80038764: jal         0x800386B4
    // 0x80038768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800386B4(rdram, ctx);
        goto after_2;
    // 0x80038768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003876C: bnel        $v0, $zero, L_80038780
    if (ctx->r2 != 0) {
        // 0x80038770: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038780;
    }
    goto skip_0;
    // 0x80038770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038774: b           L_80038780
    // 0x80038778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038780;
    // 0x80038778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003877C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038780:
    // 0x80038780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038788: jr          $ra
    // 0x8003878C: nop

    return;
    // 0x8003878C: nop

;}
RECOMP_FUNC void func_804CE834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CE838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE83C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CE840: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804CE844: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(240, 0X1A28) << 16);
    // 0x804CE848: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CE84C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CE850: lw          $t8, -0x328($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(240, 0X1A28));
    // 0x804CE854: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CE858: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804CE85C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804CE860: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804CE864: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804CE868: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804CE86C: beql        $v1, $zero, L_804CE8A0
    if (ctx->r3 == 0) {
        // 0x804CE870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CE8A0;
    }
    goto skip_0;
    // 0x804CE870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CE874: jalr        $v1
    // 0x804CE878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804CE878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CE87C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CE880: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804CE884: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804CE888: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804CE88C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804CE890: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804CE894: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804CE898: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804CE89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CE8A0:
    // 0x804CE8A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CE8A4: jr          $ra
    // 0x804CE8A8: nop

    return;
    // 0x804CE8A8: nop

;}
RECOMP_FUNC void func_8042FDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FDD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FDD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FDDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042FDE0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FDE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042FDE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8042FDEC: swc1        $f0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f0.u32l;
    // 0x8042FDF0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8042FDF4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8042FDF8: jal         0x804303F0
    // 0x8042FDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804303F0(rdram, ctx);
        goto after_0;
    // 0x8042FDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042FE00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042FE04: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x8042FE08: addiu       $t7, $t7, -0x658
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x8042FE0C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FE10: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x8042FE14: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8042FE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FE1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FE20: jr          $ra
    // 0x8042FE24: nop

    return;
    // 0x8042FE24: nop

;}
RECOMP_FUNC void func_8006E9EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E9F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E9F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E9F8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E9FC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8006EA00: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8006EA04: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8006EA08: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8006EA0C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006EA10: addiu       $t7, $t7, 0x7EF8
    ctx->r15 = ADD32(ctx->r15, 0X7EF8);
    // 0x8006EA14: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006EA18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006EA1C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8006EA20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EA24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8006EA28: jal         0x8006F070
    // 0x8006EA2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_0;
    // 0x8006EA2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006EA30: jal         0x8006E9D4
    // 0x8006EA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E9D4(rdram, ctx);
        goto after_1;
    // 0x8006EA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006EA38: jal         0x8005FD1C
    // 0x8006EA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x8006EA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006EA40: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8006EA44: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006EA48: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x8006EA4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EA50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EA54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006EA58: jr          $ra
    // 0x8006EA5C: nop

    return;
    // 0x8006EA5C: nop

;}
RECOMP_FUNC void func_8045F920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F920: jr          $ra
    // 0x8045F924: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8045F924: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8056831C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056831C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568324: jal         0x80567DD4
    // 0x80568328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80567DD4(rdram, ctx);
        goto after_0;
    // 0x80568328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8056832C: jal         0x805677F4
    // 0x80568330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805677F4(rdram, ctx);
        goto after_1;
    // 0x80568330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80568334: jal         0x80567E60
    // 0x80568338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80567E60(rdram, ctx);
        goto after_2;
    // 0x80568338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8056833C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568344: jr          $ra
    // 0x80568348: nop

    return;
    // 0x80568348: nop

;}
RECOMP_FUNC void lceil(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082040: ceil.w.d    $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(ceil(ctx->f12.d));
    // 0x80082044: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082048: jr          $ra
    // 0x8008204C: nop

    return;
    // 0x8008204C: nop

;}
RECOMP_FUNC void func_8001A46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A46C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A474: jal         0x8001A420
    // 0x8001A478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001A420(rdram, ctx);
        goto after_0;
    // 0x8001A478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001A47C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001A480: bgez        $v0, L_8001A4B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001A484: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8001A4B0;
    }
    // 0x8001A484: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001A488: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001A48C: lw          $v0, 0x590($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X590);
    // 0x8001A490: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A494: beq         $v0, $zero, L_8001A4B0
    if (ctx->r2 == 0) {
        // 0x8001A498: nop
    
            goto L_8001A4B0;
    }
    // 0x8001A498: nop

    // 0x8001A49C: jal         0x8001A5C4
    // 0x8001A4A0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_8001A5C4(rdram, ctx);
        goto after_1;
    // 0x8001A4A0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x8001A4A4: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001A4A8: b           L_8001A4B0
    // 0x8001A4AC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8001A4B0;
    // 0x8001A4AC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8001A4B0:
    // 0x8001A4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A4B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001A4B8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8001A4BC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A4C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001A4C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A4C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A4CC: jr          $ra
    // 0x8001A4D0: sw          $t6, 0x5A0($at)
    MEM_W(0X5A0, ctx->r1) = ctx->r14;
    return;
    // 0x8001A4D0: sw          $t6, 0x5A0($at)
    MEM_W(0X5A0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8007FF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FF50: jr          $ra
    // 0x8007FF54: nop

    return;
    // 0x8007FF54: nop

;}
RECOMP_FUNC void func_8049F5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F5F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049F5FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049F600: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8049F604: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8049F608: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8049F60C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8049F610: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8049F614: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8049F618: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8049F61C: beq         $v0, $at, L_8049F638
    if (ctx->r2 == ctx->r1) {
        // 0x8049F620: lw          $t0, 0x1F4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1F4);
            goto L_8049F638;
    }
    // 0x8049F620: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049F624: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8049F628: beql        $v0, $at, L_8049F67C
    if (ctx->r2 == ctx->r1) {
        // 0x8049F62C: lbu         $t9, 0x18($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X18);
            goto L_8049F67C;
    }
    goto skip_0;
    // 0x8049F62C: lbu         $t9, 0x18($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X18);
    skip_0:
    // 0x8049F630: b           L_8049F770
    // 0x8049F634: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
        goto L_8049F770;
    // 0x8049F634: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
L_8049F638:
    // 0x8049F638: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8049F63C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8049F640: beq         $v0, $at, L_8049F650
    if (ctx->r2 == ctx->r1) {
        // 0x8049F644: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8049F650;
    }
    // 0x8049F644: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8049F648: bnel        $v0, $at, L_8049F7C8
    if (ctx->r2 != ctx->r1) {
        // 0x8049F64C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_1;
    // 0x8049F64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8049F650:
    // 0x8049F650: lhu         $t7, 0x8($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X8);
    // 0x8049F654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8049F65C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8049F660: bnel        $t8, $zero, L_8049F7C8
    if (ctx->r24 != 0) {
        // 0x8049F664: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_2;
    // 0x8049F664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8049F668: jal         0x8002F6E4
    // 0x8049F66C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8049F66C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8049F670: b           L_8049F7C8
    // 0x8049F674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8049F7C8;
    // 0x8049F674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F678: lbu         $t9, 0x18($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X18);
L_8049F67C:
    // 0x8049F67C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8049F680: bnel        $t9, $at, L_8049F7C8
    if (ctx->r25 != ctx->r1) {
        // 0x8049F684: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_3;
    // 0x8049F684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8049F688: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x8049F68C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8049F690: beq         $v0, $at, L_8049F6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8049F694: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8049F6A0;
    }
    // 0x8049F694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8049F698: bnel        $v0, $at, L_8049F7C8
    if (ctx->r2 != ctx->r1) {
        // 0x8049F69C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_4;
    // 0x8049F69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8049F6A0:
    // 0x8049F6A0: lhu         $t2, 0x8($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X8);
    // 0x8049F6A4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8049F6A8: bnel        $t3, $zero, L_8049F7C8
    if (ctx->r11 != 0) {
        // 0x8049F6AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_5;
    // 0x8049F6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8049F6B0: lw          $t4, 0x12C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X12C);
    // 0x8049F6B4: bnel        $t4, $zero, L_8049F6E4
    if (ctx->r12 != 0) {
        // 0x8049F6B8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8049F6E4;
    }
    goto skip_6;
    // 0x8049F6B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_6:
    // 0x8049F6BC: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8049F6C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8049F6C4: nop

    // 0x8049F6C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8049F6CC: nop

    // 0x8049F6D0: bc1fl       L_8049F6F8
    if (!c1cs) {
        // 0x8049F6D4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8049F6F8;
    }
    goto skip_7;
    // 0x8049F6D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_7:
    // 0x8049F6D8: b           L_8049F7C8
    // 0x8049F6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8049F7C8;
    // 0x8049F6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F6E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8049F6E4:
    // 0x8049F6E4: lwc1        $f10, 0xC4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8049F6E8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8049F6EC: nop

    // 0x8049F6F0: bc1t        L_8049F7C4
    if (c1cs) {
        // 0x8049F6F4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8049F7C4;
    }
    // 0x8049F6F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8049F6F8:
    // 0x8049F6F8: sb          $t5, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r13;
    // 0x8049F6FC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8049F700: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x8049F704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F70C: jalr        $t9
    // 0x8049F710: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8049F710: nop

    after_1:
    // 0x8049F714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F71C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8049F720: jal         0x8049FBAC
    // 0x8049F724: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_2;
    // 0x8049F724: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x8049F728: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8049F72C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8049F730: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8049F734: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8049F738: jal         0x80048378
    // 0x8049F73C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    func_80048378(rdram, ctx);
        goto after_3;
    // 0x8049F73C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    after_3:
    // 0x8049F740: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8049F744: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x8049F748: jal         0x80067BBC
    // 0x8049F74C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8049F74C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_4:
    // 0x8049F750: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8049F754: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x8049F758: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8049F75C: jal         0x80067818
    // 0x8049F760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8049F760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8049F764: b           L_8049F7C8
    // 0x8049F768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8049F7C8;
    // 0x8049F768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F76C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
L_8049F770:
    // 0x8049F770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8049F774: beq         $v0, $at, L_8049F784
    if (ctx->r2 == ctx->r1) {
        // 0x8049F778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8049F784;
    }
    // 0x8049F778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8049F77C: bnel        $v0, $at, L_8049F7C8
    if (ctx->r2 != ctx->r1) {
        // 0x8049F780: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F7C8;
    }
    goto skip_8;
    // 0x8049F780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
L_8049F784:
    // 0x8049F784: lhu         $t2, 0x8($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X8);
    // 0x8049F788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F78C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F790: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8049F794: bne         $t3, $zero, L_8049F7C4
    if (ctx->r11 != 0) {
        // 0x8049F798: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8049F7C4;
    }
    // 0x8049F798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8049F79C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8049F7A0: jal         0x8049FBAC
    // 0x8049F7A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8049FBAC(rdram, ctx);
        goto after_6;
    // 0x8049F7A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_6:
    // 0x8049F7A8: jal         0x80048378
    // 0x8049F7AC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048378(rdram, ctx);
        goto after_7;
    // 0x8049F7AC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_7:
    // 0x8049F7B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8049F7B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8049F7B8: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8049F7BC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8049F7C0: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_8049F7C4:
    // 0x8049F7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8049F7C8:
    // 0x8049F7C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8049F7CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8049F7D0: jr          $ra
    // 0x8049F7D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8049F7D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001D094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D09C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D0A0: lw          $a2, 0x34($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X34);
    // 0x8001D0A4: bnel        $a2, $zero, L_8001D0E8
    if (ctx->r6 != 0) {
        // 0x8001D0A8: addiu       $t9, $a2, -0x1
        ctx->r25 = ADD32(ctx->r6, -0X1);
            goto L_8001D0E8;
    }
    goto skip_0;
    // 0x8001D0A8: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    skip_0:
    // 0x8001D0AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D0B0: jal         0x800653D8
    // 0x8001D0B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8001D0B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001D0B8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8001D0BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D0C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001D0C4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8001D0C8: lw          $v1, -0x6920($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6920);
    // 0x8001D0CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001D0D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D0D4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8001D0D8: sw          $v1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r3;
    // 0x8001D0DC: sw          $v1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r3;
    // 0x8001D0E0: sw          $a2, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r6;
    // 0x8001D0E4: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
L_8001D0E8:
    // 0x8001D0E8: sw          $t9, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r25;
    // 0x8001D0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D0F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D0F4: jr          $ra
    // 0x8001D0F8: nop

    return;
    // 0x8001D0F8: nop

;}
RECOMP_FUNC void func_8001CE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE8C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001CE90: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001CE94: bne         $t7, $zero, L_8001CF68
    if (ctx->r15 != 0) {
        // 0x8001CE98: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8001CF68;
    }
    // 0x8001CE98: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8001CE9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CEA0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8001CEA4: lbu         $a3, 0x31($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X31);
    // 0x8001CEA8: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x8001CEAC: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x8001CEB0: addu        $t0, $t0, $a3
    ctx->r8 = ADD32(ctx->r8, ctx->r7);
    // 0x8001CEB4: lbu         $t0, -0x6954($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6954);
    // 0x8001CEB8: beq         $a1, $zero, L_8001CF40
    if (ctx->r5 == 0) {
        // 0x8001CEBC: addiu       $a2, $v0, 0x28
        ctx->r6 = ADD32(ctx->r2, 0X28);
            goto L_8001CF40;
    }
    // 0x8001CEBC: addiu       $a2, $v0, 0x28
    ctx->r6 = ADD32(ctx->r2, 0X28);
    // 0x8001CEC0: andi        $t2, $a1, 0x3
    ctx->r10 = ctx->r5 & 0X3;
    // 0x8001CEC4: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x8001CEC8: beq         $t2, $zero, L_8001CEEC
    if (ctx->r10 == 0) {
        // 0x8001CECC: addu        $t1, $t2, $a1
        ctx->r9 = ADD32(ctx->r10, ctx->r5);
            goto L_8001CEEC;
    }
    // 0x8001CECC: addu        $t1, $t2, $a1
    ctx->r9 = ADD32(ctx->r10, ctx->r5);
L_8001CED0:
    // 0x8001CED0: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x8001CED4: bne         $v1, $t9, L_8001CEE0
    if (ctx->r3 != ctx->r25) {
        // 0x8001CED8: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8001CEE0;
    }
    // 0x8001CED8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001CEDC: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8001CEE0:
    // 0x8001CEE0: bne         $t1, $a1, L_8001CED0
    if (ctx->r9 != ctx->r5) {
        // 0x8001CEE4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001CED0;
    }
    // 0x8001CEE4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CEE8: beq         $a1, $zero, L_8001CF40
    if (ctx->r5 == 0) {
        // 0x8001CEEC: andi        $t3, $a1, 0x1
        ctx->r11 = ctx->r5 & 0X1;
            goto L_8001CF40;
    }
L_8001CEEC:
    // 0x8001CEEC: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x8001CEF0: bne         $v1, $t3, L_8001CEFC
    if (ctx->r3 != ctx->r11) {
        // 0x8001CEF4: addiu       $t4, $a1, -0x1
        ctx->r12 = ADD32(ctx->r5, -0X1);
            goto L_8001CEFC;
    }
    // 0x8001CEF4: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x8001CEF8: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8001CEFC:
    // 0x8001CEFC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8001CF00: bne         $v1, $t5, L_8001CF0C
    if (ctx->r3 != ctx->r13) {
        // 0x8001CF04: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001CF0C;
    }
    // 0x8001CF04: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CF08: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8001CF0C:
    // 0x8001CF0C: addiu       $t6, $a1, -0x2
    ctx->r14 = ADD32(ctx->r5, -0X2);
    // 0x8001CF10: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001CF14: bne         $v1, $t7, L_8001CF20
    if (ctx->r3 != ctx->r15) {
        // 0x8001CF18: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001CF20;
    }
    // 0x8001CF18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CF1C: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8001CF20:
    // 0x8001CF20: addiu       $t8, $a1, -0x3
    ctx->r24 = ADD32(ctx->r5, -0X3);
    // 0x8001CF24: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001CF28: bne         $v1, $t9, L_8001CF34
    if (ctx->r3 != ctx->r25) {
        // 0x8001CF2C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001CF34;
    }
    // 0x8001CF2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CF30: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8001CF34:
    // 0x8001CF34: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001CF38: bne         $a1, $zero, L_8001CEEC
    if (ctx->r5 != 0) {
        // 0x8001CF3C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001CEEC;
    }
    // 0x8001CF3C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001CF40:
    // 0x8001CF40: xori        $t3, $a3, 0x1
    ctx->r11 = ctx->r7 ^ 0X1;
    // 0x8001CF44: bne         $a3, $zero, L_8001CF54
    if (ctx->r7 != 0) {
        // 0x8001CF48: sb          $t3, 0x31($v0)
        MEM_B(0X31, ctx->r2) = ctx->r11;
            goto L_8001CF54;
    }
    // 0x8001CF48: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
    // 0x8001CF4C: xori        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 ^ 0X1;
    // 0x8001CF50: sb          $t4, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r12;
L_8001CF54:
    // 0x8001CF54: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8001CF58: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001CF5C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8001CF60: lw          $t6, -0x6950($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6950);
    // 0x8001CF64: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8001CF68:
    // 0x8001CF68: jr          $ra
    // 0x8001CF6C: nop

    return;
    // 0x8001CF6C: nop

;}
RECOMP_FUNC void gfxprint_locate8x8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F46C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007F470: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8007F474: jal         0x8007F440
    // 0x8007F478: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    gfxprint_locate(rdram, ctx);
        goto after_0;
    // 0x8007F478: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    after_0:
    // 0x8007F47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F484: jr          $ra
    // 0x8007F488: nop

    return;
    // 0x8007F488: nop

;}
RECOMP_FUNC void func_8045F928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045F92C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F930: jal         0x8045F164
    // 0x8045F934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045F164(rdram, ctx);
        goto after_0;
    // 0x8045F934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045F938: jal         0x80045BD8
    // 0x8045F93C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8045F93C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045F940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045F944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045F948: jr          $ra
    // 0x8045F94C: nop

    return;
    // 0x8045F94C: nop

;}
RECOMP_FUNC void func_80526574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526574: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80526578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052657C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80526580: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80526584: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526588: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8052658C: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80526590: lh          $t6, 0x80($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X80);
    // 0x80526594: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80526598: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8052659C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x805265A0: nop

    // 0x805265A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805265A8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x805265AC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x805265B0: lh          $t8, 0x82($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X82);
    // 0x805265B4: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x805265B8: addiu       $t9, $t8, -0x28
    ctx->r25 = ADD32(ctx->r24, -0X28);
    // 0x805265BC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x805265C0: nop

    // 0x805265C4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805265C8: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805265CC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x805265D0: nop

    // 0x805265D4: bc1fl       L_8052674C
    if (!c1cs) {
        // 0x805265D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8052674C;
    }
    goto skip_0;
    // 0x805265D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805265DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805265E0: nop

    // 0x805265E4: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x805265E8: nop

    // 0x805265EC: bc1fl       L_8052674C
    if (!c1cs) {
        // 0x805265F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8052674C;
    }
    goto skip_1;
    // 0x805265F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805265F4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x805265F8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x805265FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80526600: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80526604: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80526608: nop

    // 0x8052660C: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80526610: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80526614: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80526618: nop

    // 0x8052661C: bc1f        L_80526748
    if (!c1cs) {
        // 0x80526620: nop
    
            goto L_80526748;
    }
    // 0x80526620: nop

    // 0x80526624: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80526628: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8052662C: nop

    // 0x80526630: bc1fl       L_8052674C
    if (!c1cs) {
        // 0x80526634: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8052674C;
    }
    goto skip_2;
    // 0x80526634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80526638: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8052663C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80526640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80526644: beq         $v0, $at, L_80526660
    if (ctx->r2 == ctx->r1) {
        // 0x80526648: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80526660;
    }
    // 0x80526648: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8052664C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80526650: beql        $v0, $at, L_805266B8
    if (ctx->r2 == ctx->r1) {
        // 0x80526654: lbu         $t0, 0x18($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X18);
            goto L_805266B8;
    }
    goto skip_3;
    // 0x80526654: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    skip_3:
    // 0x80526658: b           L_8052674C
    // 0x8052665C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052674C;
    // 0x8052665C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80526660:
    // 0x80526660: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80526664: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80526668: bc1fl       L_80526684
    if (!c1cs) {
        // 0x8052666C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80526684;
    }
    goto skip_4;
    // 0x8052666C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_4:
    // 0x80526670: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80526674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80526678: b           L_8052668C
    // 0x8052667C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_8052668C;
    // 0x8052667C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80526680: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80526684:
    // 0x80526684: nop

    // 0x80526688: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8052668C:
    // 0x8052668C: jal         0x8002F96C
    // 0x80526690: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    func_8002F96C(rdram, ctx);
        goto after_0;
    // 0x80526690: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    after_0:
    // 0x80526694: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80526698: jal         0x80067BBC
    // 0x8052669C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8052669C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x805266A0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x805266A4: jal         0x80067818
    // 0x805266A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805266A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x805266AC: b           L_8052674C
    // 0x805266B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052674C;
    // 0x805266B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805266B4: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
L_805266B8:
    // 0x805266B8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805266BC: bnel        $t0, $at, L_8052674C
    if (ctx->r8 != ctx->r1) {
        // 0x805266C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8052674C;
    }
    goto skip_5;
    // 0x805266C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x805266C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805266C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805266CC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x805266D0: jal         0x80067BBC
    // 0x805266D4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805266D4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_3:
    // 0x805266D8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x805266DC: jal         0x80067818
    // 0x805266E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805266E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805266E4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x805266E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805266EC: sb          $t1, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r9;
    // 0x805266F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805266F4: jalr        $t9
    // 0x805266F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x805266F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805266FC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80526700: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80526704: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80526708: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8052670C: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80526710: nop

    // 0x80526714: bc1fl       L_80526730
    if (!c1cs) {
        // 0x80526718: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80526730;
    }
    goto skip_6;
    // 0x80526718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_6:
    // 0x8052671C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80526720: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80526724: b           L_80526738
    // 0x80526728: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
        goto L_80526738;
    // 0x80526728: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8052672C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80526730:
    // 0x80526730: nop

    // 0x80526734: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_80526738:
    // 0x80526738: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8052673C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80526740: nop

    // 0x80526744: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
L_80526748:
    // 0x80526748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052674C:
    // 0x8052674C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80526750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80526754: jr          $ra
    // 0x80526758: nop

    return;
    // 0x80526758: nop

;}
RECOMP_FUNC void func_8004D2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D2DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004D2E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D2E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004D2E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004D2EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004D2F0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8004D2F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004D2F8: jal         0x80047AB8
    // 0x8004D2FC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D2FC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8004D300: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8004D304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004D308: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D30C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8004D310: jalr        $t9
    // 0x8004D314: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004D314: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8004D318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D31C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004D320: jr          $ra
    // 0x8004D324: nop

    return;
    // 0x8004D324: nop

;}
RECOMP_FUNC void func_80710020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710020: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80710024: lhu         $t6, -0x71A0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X71A0);
    // 0x80710028: lhu         $a1, 0x46($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X46);
    // 0x8071002C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80710030: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80710034: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80710038: beq         $at, $zero, L_80710048
    if (ctx->r1 == 0) {
        // 0x8071003C: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_80710048;
    }
    // 0x8071003C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80710040: jr          $ra
    // 0x80710044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80710044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80710048:
    // 0x80710048: addiu       $t8, $t8, 0x7EA0
    ctx->r24 = ADD32(ctx->r24, 0X7EA0);
    // 0x8071004C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80710050: lhu         $t9, 0xFC0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XFC0);
    // 0x80710054: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80710058: beql        $at, $zero, L_8071006C
    if (ctx->r1 == 0) {
        // 0x8071005C: lhu         $t0, 0xFC8($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0XFC8);
            goto L_8071006C;
    }
    goto skip_0;
    // 0x8071005C: lhu         $t0, 0xFC8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XFC8);
    skip_0:
    // 0x80710060: jr          $ra
    // 0x80710064: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80710064: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80710068: lhu         $t0, 0xFC8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XFC8);
L_8071006C:
    // 0x8071006C: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80710070: beql        $at, $zero, L_80710084
    if (ctx->r1 == 0) {
        // 0x80710074: lhu         $t1, 0xFD0($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0XFD0);
            goto L_80710084;
    }
    goto skip_1;
    // 0x80710074: lhu         $t1, 0xFD0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XFD0);
    skip_1:
    // 0x80710078: jr          $ra
    // 0x8071007C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8071007C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80710080: lhu         $t1, 0xFD0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XFD0);
L_80710084:
    // 0x80710084: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80710088: beql        $at, $zero, L_8071009C
    if (ctx->r1 == 0) {
        // 0x8071008C: lhu         $t2, 0xFD8($v0)
        ctx->r10 = MEM_HU(ctx->r2, 0XFD8);
            goto L_8071009C;
    }
    goto skip_2;
    // 0x8071008C: lhu         $t2, 0xFD8($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XFD8);
    skip_2:
    // 0x80710090: jr          $ra
    // 0x80710094: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80710094: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80710098: lhu         $t2, 0xFD8($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XFD8);
L_8071009C:
    // 0x8071009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807100A0: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x807100A4: beq         $at, $zero, L_807100B4
    if (ctx->r1 == 0) {
        // 0x807100A8: nop
    
            goto L_807100B4;
    }
    // 0x807100A8: nop

    // 0x807100AC: jr          $ra
    // 0x807100B0: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    return;
    // 0x807100B0: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
L_807100B4:
    // 0x807100B4: jr          $ra
    // 0x807100B8: nop

    return;
    // 0x807100B8: nop

;}
RECOMP_FUNC void func_80049524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049528: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8004952C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049530: beq         $a0, $at, L_80049544
    if (ctx->r4 == ctx->r1) {
        // 0x80049534: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80049544;
    }
    // 0x80049534: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80049538: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004953C: b           L_80049570
    // 0x80049540: sb          $zero, 0x5AC($at)
    MEM_B(0X5AC, ctx->r1) = 0;
        goto L_80049570;
    // 0x80049540: sb          $zero, 0x5AC($at)
    MEM_B(0X5AC, ctx->r1) = 0;
L_80049544:
    // 0x80049544: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80049548: lbu         $t6, 0x5AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5AC);
    // 0x8004954C: addiu       $a0, $zero, -0x7D
    ctx->r4 = ADD32(0, -0X7D);
    // 0x80049550: bnel        $t6, $zero, L_80049574
    if (ctx->r14 != 0) {
        // 0x80049554: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80049574;
    }
    goto skip_0;
    // 0x80049554: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    skip_0:
    // 0x80049558: jal         0x800492C0
    // 0x8004955C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800492C0(rdram, ctx);
        goto after_0;
    // 0x8004955C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80049560: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80049564: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80049568: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8004956C: sb          $t7, 0x5AC($at)
    MEM_B(0X5AC, ctx->r1) = ctx->r15;
L_80049570:
    // 0x80049570: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
L_80049574:
    // 0x80049574: bne         $at, $zero, L_80049594
    if (ctx->r1 != 0) {
        // 0x80049578: slti        $at, $a1, 0x1D
        ctx->r1 = SIGNED(ctx->r5) < 0X1D ? 1 : 0;
            goto L_80049594;
    }
    // 0x80049578: slti        $at, $a1, 0x1D
    ctx->r1 = SIGNED(ctx->r5) < 0X1D ? 1 : 0;
    // 0x8004957C: beq         $at, $zero, L_80049594
    if (ctx->r1 == 0) {
        // 0x80049580: nop
    
            goto L_80049594;
    }
    // 0x80049580: nop

    // 0x80049584: jal         0x80049470
    // 0x80049588: nop

    func_80049470(rdram, ctx);
        goto after_1;
    // 0x80049588: nop

    after_1:
    // 0x8004958C: b           L_800495A0
    // 0x80049590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800495A0;
    // 0x80049590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049594:
    // 0x80049594: jal         0x800493B8
    // 0x80049598: nop

    func_800493B8(rdram, ctx);
        goto after_2;
    // 0x80049598: nop

    after_2:
    // 0x8004959C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800495A0:
    // 0x800495A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800495A4: jr          $ra
    // 0x800495A8: nop

    return;
    // 0x800495A8: nop

;}
RECOMP_FUNC void func_804545A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804545A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804545AC: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x804545B0: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x804545B4: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x804545B8: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x804545BC: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x804545C0: sw          $a1, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r5;
    // 0x804545C4: sw          $v1, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r3;
    // 0x804545C8: sw          $a1, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r5;
    // 0x804545CC: sw          $t6, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r14;
    // 0x804545D0: jr          $ra
    // 0x804545D4: sw          $v1, 0x230($v0)
    MEM_W(0X230, ctx->r2) = ctx->r3;
    return;
    // 0x804545D4: sw          $v1, 0x230($v0)
    MEM_W(0X230, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_804079D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804079D0: lui         $v0, 0x8040
    ctx->r2 = S32(RELOC_HI16(11, 0X10) << 16);
    // 0x804079D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804079D8: jr          $ra
    // 0x804079DC: addiu       $v0, $v0, 0x79E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(11, 0X10));
    return;
    // 0x804079DC: addiu       $v0, $v0, 0x79E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(11, 0X10));
;}
RECOMP_FUNC void func_8001E674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E674: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8001E678: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x8001E67C: bnel        $t7, $zero, L_8001E698
    if (ctx->r15 != 0) {
        // 0x8001E680: lbu         $v0, 0x12C8($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X12C8);
            goto L_8001E698;
    }
    goto skip_0;
    // 0x8001E680: lbu         $v0, 0x12C8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X12C8);
    skip_0:
    // 0x8001E684: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x8001E688: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x8001E68C: beql        $t9, $zero, L_8001E704
    if (ctx->r25 == 0) {
        // 0x8001E690: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E704;
    }
    goto skip_1;
    // 0x8001E690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8001E694: lbu         $v0, 0x12C8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X12C8);
L_8001E698:
    // 0x8001E698: lhu         $a1, 0x12BC($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X12BC);
    // 0x8001E69C: lhu         $v1, 0x12BE($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X12BE);
    // 0x8001E6A0: beq         $v0, $zero, L_8001E700
    if (ctx->r2 == 0) {
        // 0x8001E6A4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8001E700;
    }
    // 0x8001E6A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001E6A8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
L_8001E6AC:
    // 0x8001E6AC: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E6B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001E6B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E6B8: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8001E6BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001E6C0: mflo        $t0
    ctx->r8 = lo;
    // 0x8001E6C4: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8001E6C8: lhu         $t2, 0x1200($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1200);
    // 0x8001E6CC: addu        $a1, $t2, $a2
    ctx->r5 = ADD32(ctx->r10, ctx->r6);
    // 0x8001E6D0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001E6D4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001E6D8: sll         $t3, $a1, 4
    ctx->r11 = S32(ctx->r5 << 4);
    // 0x8001E6DC: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8001E6E0: lbu         $t5, 0x209($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X209);
    // 0x8001E6E4: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x8001E6E8: bne         $t6, $zero, L_8001E6F8
    if (ctx->r14 != 0) {
        // 0x8001E6EC: nop
    
            goto L_8001E6F8;
    }
    // 0x8001E6EC: nop

    // 0x8001E6F0: jr          $ra
    // 0x8001E6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001E6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001E6F8:
    // 0x8001E6F8: bne         $v0, $zero, L_8001E6AC
    if (ctx->r2 != 0) {
        // 0x8001E6FC: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_8001E6AC;
    }
    // 0x8001E6FC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8001E700:
    // 0x8001E700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E704:
    // 0x8001E704: jr          $ra
    // 0x8001E708: nop

    return;
    // 0x8001E708: nop

;}
RECOMP_FUNC void func_8045DD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045DD10: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(110, 0X111C) << 16);
    // 0x8045DD14: addiu       $v0, $v0, -0x11D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(110, 0X111C));
    // 0x8045DD18: jr          $ra
    // 0x8045DD1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8045DD1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80042060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004206C: jal         0x80030104
    // 0x80042070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80030104(rdram, ctx);
        goto after_0;
    // 0x80042070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80042074: jal         0x80041D3C
    // 0x80042078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041D3C(rdram, ctx);
        goto after_1;
    // 0x80042078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004207C: jal         0x80041F58
    // 0x80042080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041F58(rdram, ctx);
        goto after_2;
    // 0x80042080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80042084: jal         0x80041FE8
    // 0x80042088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041FE8(rdram, ctx);
        goto after_3;
    // 0x80042088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004208C: jal         0x80021DB8
    // 0x80042090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021DB8(rdram, ctx);
        goto after_4;
    // 0x80042090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80042094: jal         0x80041450
    // 0x80042098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041450(rdram, ctx);
        goto after_5;
    // 0x80042098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004209C: jal         0x80036924
    // 0x800420A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036924(rdram, ctx);
        goto after_6;
    // 0x800420A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800420A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800420A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800420AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800420B0: jr          $ra
    // 0x800420B4: nop

    return;
    // 0x800420B4: nop

;}
RECOMP_FUNC void func_80737570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737570: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80737574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073757C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x80737580: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737584: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(736, 0X3AC8) << 16);
    // 0x80737588: addiu       $a1, $a1, -0x6AD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(736, 0X3AC8));
    // 0x8073758C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80737590: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x80737594: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80737598: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8073759C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807375A0: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x807375A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807375A8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807375AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807375B0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807375B4: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x807375B8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x807375BC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x807375C0: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x807375C4: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x807375C8: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x807375CC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x807375D0: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x807375D4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807375D8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807375DC: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x807375E0: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807375E4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x807375E8: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x807375EC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x807375F0: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x807375F4: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x807375F8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x807375FC: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x80737600: jal         0x807370C0
    // 0x80737604: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    func_807370C0(rdram, ctx);
        goto after_0;
    // 0x80737604: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80737608: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8073760C: beq         $v0, $zero, L_80737784
    if (ctx->r2 == 0) {
        // 0x80737610: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80737784;
    }
    // 0x80737610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80737614: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80737618: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8073761C: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80737620: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80737624: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80737628: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8073762C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80737630: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B58) << 16);
    // 0x80737634: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80737638: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8073763C: lwc1        $f18, 0x34($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80737640: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80737644: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80737648: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8073764C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80737650: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80737654: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80737658: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8073765C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80737660: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80737664: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80737668: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8073766C: lwc1        $f16, -0x6A48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B58));
    // 0x80737670: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B5C) << 16);
    // 0x80737674: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80737678: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8073767C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80737680: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80737684: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80737688: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8073768C: nop

    // 0x80737690: bc1tl       L_807376C4
    if (c1cs) {
        // 0x80737694: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_807376C4;
    }
    goto skip_0;
    // 0x80737694: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80737698: lwc1        $f10, -0x6A44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B5C));
    // 0x8073769C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807376A0: nop

    // 0x807376A4: bc1tl       L_807376C4
    if (c1cs) {
        // 0x807376A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_807376C4;
    }
    goto skip_1;
    // 0x807376A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x807376AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807376B0: nop

    // 0x807376B4: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x807376B8: b           L_807376E8
    // 0x807376BC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
        goto L_807376E8;
    // 0x807376BC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x807376C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_807376C4:
    // 0x807376C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807376C8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807376CC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807376D0: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807376D4: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807376D8: nop

    // 0x807376DC: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807376E0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x807376E4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
L_807376E8:
    // 0x807376E8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B60) << 16);
    // 0x807376EC: lwc1        $f0, -0x6A40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B60));
    // 0x807376F0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x807376F4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B68) << 16);
    // 0x807376F8: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807376FC: swc1        $f10, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f10.u32l;
    // 0x80737700: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80737704: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80737708: swc1        $f18, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f18.u32l;
    // 0x8073770C: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x80737710: bnel        $t0, $zero, L_8073774C
    if (ctx->r8 != 0) {
        // 0x80737714: lwc1        $f8, 0x50($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8073774C;
    }
    goto skip_2;
    // 0x80737714: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    skip_2:
    // 0x80737718: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B64) << 16);
    // 0x8073771C: lwc1        $f4, -0x6A3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B64));
    // 0x80737720: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80737724: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80737728: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8073772C: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80737730: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80737734: jal         0x800659EC
    // 0x80737738: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x80737738: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    after_1:
    // 0x8073773C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80737740: b           L_80737764
    // 0x80737744: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
        goto L_80737764;
    // 0x80737744: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80737748: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
L_8073774C:
    // 0x8073774C: lwc1        $f18, -0x6A38($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B68));
    // 0x80737750: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80737754: jal         0x800659EC
    // 0x80737758: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    func_800659EC(rdram, ctx);
        goto after_2;
    // 0x80737758: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    after_2:
    // 0x8073775C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80737760: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_80737764:
    // 0x80737764: jal         0x8073741C
    // 0x80737768: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_8073741C(rdram, ctx);
        goto after_3;
    // 0x80737768: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x8073776C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80737770: jal         0x80067BBC
    // 0x80737774: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80737774: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80737778: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x8073777C: jal         0x80067818
    // 0x80737780: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80737780: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_80737784:
    // 0x80737784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80737788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073778C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80737790: jr          $ra
    // 0x80737794: nop

    return;
    // 0x80737794: nop

;}
RECOMP_FUNC void func_805537D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805537D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805537D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805537DC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805537E0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x805537E4: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x805537E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805537EC: jal         0x80049D74
    // 0x805537F0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805537F0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x805537F4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x805537F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805537FC: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80553800: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80553804: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80553808: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8055380C: lw          $t9, 0xDB4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XDB4);
    // 0x80553810: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80553814: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(354, 0X40A8) << 16);
    // 0x80553818: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8055381C: lw          $t9, 0x4BC8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(354, 0X40A8));
    // 0x80553820: jalr        $t9
    // 0x80553824: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80553824: nop

    after_1:
    // 0x80553828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8055382C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80553830: jr          $ra
    // 0x80553834: nop

    return;
    // 0x80553834: nop

;}
RECOMP_FUNC void func_806D2F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2F28: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806D2F2C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806D2F30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806D2F34: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D2F38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D2F3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D2F40: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806D2F44: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(613, 0X118) << 16);
    // 0x806D2F48: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806D2F4C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D2F50: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D2F54: lw          $t1, 0x2F68($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(613, 0X118));
    // 0x806D2F58: jr          $ra
    // 0x806D2F5C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806D2F5C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_806F8CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F8CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8CDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F8CE0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B50) << 16);
    // 0x806F8CE4: lwc1        $f4, -0x6CA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B50));
    // 0x806F8CE8: lwc1        $f0, 0x268($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X268);
    // 0x806F8CEC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B54) << 16);
    // 0x806F8CF0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806F8CF4: nop

    // 0x806F8CF8: bc1t        L_806F8D40
    if (c1cs) {
        // 0x806F8CFC: nop
    
            goto L_806F8D40;
    }
    // 0x806F8CFC: nop

    // 0x806F8D00: lwc1        $f6, -0x6C9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B54));
    // 0x806F8D04: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(694, 0X1358) << 16);
    // 0x806F8D08: addiu       $t6, $t6, -0x7498
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(694, 0X1358));
    // 0x806F8D0C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806F8D10: nop

    // 0x806F8D14: bc1t        L_806F8D40
    if (c1cs) {
        // 0x806F8D18: nop
    
            goto L_806F8D40;
    }
    // 0x806F8D18: nop

    // 0x806F8D1C: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x806F8D20: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F8D24: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x806F8D28: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806F8D2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806F8D30: sb          $t7, 0x74($t9)
    MEM_B(0X74, ctx->r25) = ctx->r15;
    // 0x806F8D34: jal         0x8005FDC4
    // 0x806F8D38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x806F8D38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806F8D3C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_806F8D40:
    // 0x806F8D40: jal         0x806F85F8
    // 0x806F8D44: addiu       $a0, $v0, 0x268
    ctx->r4 = ADD32(ctx->r2, 0X268);
    func_806F85F8(rdram, ctx);
        goto after_1;
    // 0x806F8D44: addiu       $a0, $v0, 0x268
    ctx->r4 = ADD32(ctx->r2, 0X268);
    after_1:
    // 0x806F8D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8D50: jr          $ra
    // 0x806F8D54: nop

    return;
    // 0x806F8D54: nop

;}
RECOMP_FUNC void func_804EFC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFC38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EFC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EFC40: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804EFC44: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804EFC48: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(267, 0X1120) << 16);
    // 0x804EFC4C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804EFC50: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804EFC54: addiu       $t7, $t7, -0x150
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(267, 0X1120));
    // 0x804EFC58: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804EFC5C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804EFC60: jal         0x804EFB58
    // 0x804EFC64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EFB58(rdram, ctx);
        goto after_0;
    // 0x804EFC64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EFC68: bne         $v0, $zero, L_804EFC80
    if (ctx->r2 != 0) {
        // 0x804EFC6C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804EFC80;
    }
    // 0x804EFC6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EFC70: jal         0x800445A4
    // 0x804EFC74: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804EFC74: nop

    after_1:
    // 0x804EFC78: b           L_804EFCAC
    // 0x804EFC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804EFCAC;
    // 0x804EFC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EFC80:
    // 0x804EFC80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EFC84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804EFC88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804EFC8C: jal         0x804EFCB8
    // 0x804EFC90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EFCB8(rdram, ctx);
        goto after_2;
    // 0x804EFC90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x804EFC94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EFC98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804EFC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804EFCA0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804EFCA4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804EFCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EFCAC:
    // 0x804EFCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EFCB0: jr          $ra
    // 0x804EFCB4: nop

    return;
    // 0x804EFCB4: nop

;}
RECOMP_FUNC void func_8045AF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AF48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8045AF4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8045AF50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8045AF54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8045AF58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045AF5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8045AF60: jal         0x8045AA4C
    // 0x8045AF64: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    func_8045AA4C(rdram, ctx);
        goto after_0;
    // 0x8045AF64: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8045AF68: jal         0x8045AAC0
    // 0x8045AF6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8045AAC0(rdram, ctx);
        goto after_1;
    // 0x8045AF6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8045AF70: jal         0x8045ABB8
    // 0x8045AF74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8045ABB8(rdram, ctx);
        goto after_2;
    // 0x8045AF74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8045AF78: lhu         $t6, 0x1C($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X1C);
    // 0x8045AF7C: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x8045AF80: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x8045AF84: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8045AF88: beq         $t7, $zero, L_8045B034
    if (ctx->r15 == 0) {
        // 0x8045AF8C: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(104, 0XD68) << 16);
            goto L_8045B034;
    }
    // 0x8045AF8C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD68) << 16);
    // 0x8045AF90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8045AF94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045AF98: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8045AF9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8045AFA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8045AFA4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8045AFA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045AFAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045AFB0: bc1fl       L_8045B020
    if (!c1cs) {
        // 0x8045AFB4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8045B020;
    }
    goto skip_0;
    // 0x8045AFB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8045AFB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045AFBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045AFC0: nop

    // 0x8045AFC4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8045AFC8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8045AFCC: jal         0x80066DE4
    // 0x8045AFD0: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8045AFD0: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    after_3:
    // 0x8045AFD4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8045AFD8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8045AFDC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8045AFE0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8045AFE4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8045AFE8: jal         0x80066E88
    // 0x8045AFEC: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8045AFEC: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    after_4:
    // 0x8045AFF0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8045AFF4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8045AFF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045AFFC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8045B000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045B004: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8045B008: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8045B00C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045B010: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8045B014: b           L_8045B060
    // 0x8045B018: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
        goto L_8045B060;
    // 0x8045B018: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8045B01C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8045B020:
    // 0x8045B020: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8045B024: jal         0x8045B594
    // 0x8045B028: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    func_8045B594(rdram, ctx);
        goto after_5;
    // 0x8045B028: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x8045B02C: b           L_8045B064
    // 0x8045B030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8045B064;
    // 0x8045B030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8045B034:
    // 0x8045B034: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045B038: lwc1        $f10, -0x4888($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD68));
    // 0x8045B03C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045B040: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8045B044: jal         0x80048F84
    // 0x8045B048: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x8045B048: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    after_6:
    // 0x8045B04C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD6C) << 16);
    // 0x8045B050: lwc1        $f6, -0x4884($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD6C));
    // 0x8045B054: lwc1        $f4, 0x24($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8045B058: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045B05C: swc1        $f8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f8.u32l;
L_8045B060:
    // 0x8045B060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8045B064:
    // 0x8045B064: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045B068: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8045B06C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8045B070: jr          $ra
    // 0x8045B074: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8045B074: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807B92A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B92A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B92AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B92B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B92B4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B92B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B92BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B92C0: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x807B92C4: beq         $v0, $zero, L_807B92EC
    if (ctx->r2 == 0) {
        // 0x807B92C8: nop
    
            goto L_807B92EC;
    }
    // 0x807B92C8: nop

    // 0x807B92CC: beq         $v0, $at, L_807B92FC
    if (ctx->r2 == ctx->r1) {
        // 0x807B92D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_807B92FC;
    }
    // 0x807B92D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807B92D4: beq         $v0, $at, L_807B930C
    if (ctx->r2 == ctx->r1) {
        // 0x807B92D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_807B930C;
    }
    // 0x807B92D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807B92DC: beq         $v0, $at, L_807B931C
    if (ctx->r2 == ctx->r1) {
        // 0x807B92E0: nop
    
            goto L_807B931C;
    }
    // 0x807B92E0: nop

    // 0x807B92E4: b           L_807B9348
    // 0x807B92E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_807B9348;
    // 0x807B92E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_807B92EC:
    // 0x807B92EC: jal         0x807B914C
    // 0x807B92F0: nop

    func_807B914C(rdram, ctx);
        goto after_0;
    // 0x807B92F0: nop

    after_0:
    // 0x807B92F4: b           L_807B9348
    // 0x807B92F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_807B9348;
    // 0x807B92F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_807B92FC:
    // 0x807B92FC: jal         0x807B9178
    // 0x807B9300: nop

    func_807B9178(rdram, ctx);
        goto after_1;
    // 0x807B9300: nop

    after_1:
    // 0x807B9304: b           L_807B9348
    // 0x807B9308: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_807B9348;
    // 0x807B9308: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_807B930C:
    // 0x807B930C: jal         0x807B91E0
    // 0x807B9310: nop

    func_807B91E0(rdram, ctx);
        goto after_2;
    // 0x807B9310: nop

    after_2:
    // 0x807B9314: b           L_807B9348
    // 0x807B9318: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_807B9348;
    // 0x807B9318: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_807B931C:
    // 0x807B931C: jal         0x807B927C
    // 0x807B9320: nop

    func_807B927C(rdram, ctx);
        goto after_3;
    // 0x807B9320: nop

    after_3:
    // 0x807B9324: jal         0x807B8F6C
    // 0x807B9328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B8F6C(rdram, ctx);
        goto after_4;
    // 0x807B9328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807B932C: jal         0x807B9014
    // 0x807B9330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B9014(rdram, ctx);
        goto after_5;
    // 0x807B9330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807B9334: jal         0x807B9390
    // 0x807B9338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B9390(rdram, ctx);
        goto after_6;
    // 0x807B9338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x807B933C: jal         0x807B90E8
    // 0x807B9340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B90E8(rdram, ctx);
        goto after_7;
    // 0x807B9340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807B9344: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_807B9348:
    // 0x807B9348: jal         0x80067BBC
    // 0x807B934C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x807B934C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x807B9350: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    // 0x807B9354: jal         0x80067818
    // 0x807B9358: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x807B9358: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x807B935C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x807B9360: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9364: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x807B9368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B936C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9370: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x807B9374: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x807B9378: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B937C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x807B9380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9384: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x807B9388: jr          $ra
    // 0x807B938C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807B938C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002BD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BD54: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BD58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BD5C: jal         0x8002BC1C
    // 0x8002BD60: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002BC1C(rdram, ctx);
        goto after_0;
    // 0x8002BD60: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002BD64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BD68: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002BD6C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8002BD70: addiu       $t8, $t8, 0x1B38
    ctx->r24 = ADD32(ctx->r24, 0X1B38);
    // 0x8002BD74: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8002BD78: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002BD7C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002BD80: lw          $t9, -0x72D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72D8);
    // 0x8002BD84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002BD88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8002BD8C: blezl       $t0, L_8002BDA8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002BD90: lw          $t4, 0x1F4($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X1F4);
            goto L_8002BDA8;
    }
    goto skip_0;
    // 0x8002BD90: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x8002BD94: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BD98: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x8002BD9C: b           L_8002BDB0
    // 0x8002BDA0: sw          $t1, 0x1C8($t2)
    MEM_W(0X1C8, ctx->r10) = ctx->r9;
        goto L_8002BDB0;
    // 0x8002BDA0: sw          $t1, 0x1C8($t2)
    MEM_W(0X1C8, ctx->r10) = ctx->r9;
    // 0x8002BDA4: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
L_8002BDA8:
    // 0x8002BDA8: addiu       $t3, $zero, 0x120
    ctx->r11 = ADD32(0, 0X120);
    // 0x8002BDAC: sw          $t3, 0x1C8($t4)
    MEM_W(0X1C8, ctx->r12) = ctx->r11;
L_8002BDB0:
    // 0x8002BDB0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8002BDB4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BDB8: swc1        $f0, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f0.u32l;
    // 0x8002BDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BDC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BDC4: jr          $ra
    // 0x8002BDC8: nop

    return;
    // 0x8002BDC8: nop

;}
RECOMP_FUNC void func_8078AA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078AA64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078AA68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078AA6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078AA70: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8078AA74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078AA78: beq         $v0, $zero, L_8078AAA0
    if (ctx->r2 == 0) {
        // 0x8078AA7C: slti        $at, $v0, 0x17
        ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
            goto L_8078AAA0;
    }
    // 0x8078AA7C: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8078AA80: beq         $at, $zero, L_8078AA94
    if (ctx->r1 == 0) {
        // 0x8078AA84: lui         $a1, 0x3CA3
        ctx->r5 = S32(0X3CA3 << 16);
            goto L_8078AA94;
    }
    // 0x8078AA84: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x8078AA88: jal         0x8078A81C
    // 0x8078AA8C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_8078A81C(rdram, ctx);
        goto after_0;
    // 0x8078AA8C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_0:
    // 0x8078AA90: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8078AA94:
    // 0x8078AA94: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8078AA98: b           L_8078AAFC
    // 0x8078AA9C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_8078AAFC;
    // 0x8078AA9C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_8078AAA0:
    // 0x8078AAA0: jal         0x8004700C
    // 0x8078AAA4: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8078AAA4: nop

    after_1:
    // 0x8078AAA8: beq         $v0, $zero, L_8078AAFC
    if (ctx->r2 == 0) {
        // 0x8078AAAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8078AAFC;
    }
    // 0x8078AAAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8078AAB0: jal         0x8002F8EC
    // 0x8078AAB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8002F8EC(rdram, ctx);
        goto after_2;
    // 0x8078AAB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8078AAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078AABC: jal         0x8078ACF0
    // 0x8078AAC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8078ACF0(rdram, ctx);
        goto after_3;
    // 0x8078AAC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8078AAC4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDF4) << 16);
    // 0x8078AAC8: lwc1        $f6, -0x4FCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDF4));
    // 0x8078AACC: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8078AAD0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDFC) << 16);
    // 0x8078AAD4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8078AAD8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8078AADC: nop

    // 0x8078AAE0: bc1f        L_8078AAF4
    if (!c1cs) {
        // 0x8078AAE4: nop
    
            goto L_8078AAF4;
    }
    // 0x8078AAE4: nop

    // 0x8078AAE8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDF8) << 16);
    // 0x8078AAEC: b           L_8078AAF8
    // 0x8078AAF0: lwc1        $f0, -0x4FC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDF8));
        goto L_8078AAF8;
    // 0x8078AAF0: lwc1        $f0, -0x4FC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDF8));
L_8078AAF4:
    // 0x8078AAF4: lwc1        $f0, -0x4FC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDFC));
L_8078AAF8:
    // 0x8078AAF8: swc1        $f0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
L_8078AAFC:
    // 0x8078AAFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078AB00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078AB04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078AB08: jr          $ra
    // 0x8078AB0C: nop

    return;
    // 0x8078AB0C: nop

;}
RECOMP_FUNC void func_800608D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800608D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800608D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800608DC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800608E0: lwc1        $f12, 0x40($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X40);
    // 0x800608E4: jal         0x80065954
    // 0x800608E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800608E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800608EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800608F0: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800608F4: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800608F8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800608FC: swc1        $f6, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f6.u32l;
    // 0x80060900: jal         0x80065954
    // 0x80060904: lwc1        $f12, 0x44($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X44);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80060904: lwc1        $f12, 0x44($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X44);
    after_1:
    // 0x80060908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006090C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80060910: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060914: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80060918: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006091C: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80060920: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80060924: bc1f        L_80060930
    if (!c1cs) {
        // 0x80060928: swc1        $f10, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
            goto L_80060930;
    }
    // 0x80060928: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x8006092C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80060930:
    // 0x80060930: beq         $v1, $zero, L_80060954
    if (ctx->r3 == 0) {
        // 0x80060934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80060954;
    }
    // 0x80060934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060938: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8006093C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060940: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x80060944: nop

    // 0x80060948: bc1fl       L_80060958
    if (!c1cs) {
        // 0x8006094C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80060958;
    }
    goto skip_0;
    // 0x8006094C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80060950: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80060954:
    // 0x80060954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80060958:
    // 0x80060958: jr          $ra
    // 0x8006095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8059F0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F0D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059F0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059F0DC: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8059F0E0: bnel        $t6, $zero, L_8059F108
    if (ctx->r14 != 0) {
        // 0x8059F0E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8059F108;
    }
    goto skip_0;
    // 0x8059F0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8059F0E8: jal         0x8005FDC4
    // 0x8059F0EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8059F0EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8059F0F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8059F0F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F0F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8059F0FC: jal         0x8059F190
    // 0x8059F100: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8059F190(rdram, ctx);
        goto after_1;
    // 0x8059F100: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8059F104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8059F108:
    // 0x8059F108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059F10C: jr          $ra
    // 0x8059F110: nop

    return;
    // 0x8059F110: nop

;}
RECOMP_FUNC void func_805D008C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D0090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D0094: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805D0098: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(462, 0X338) << 16);
    // 0x805D009C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D00A0: addiu       $t6, $t6, 0x2A8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(462, 0X338));
    // 0x805D00A4: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x805D00A8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805D00AC: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x805D00B0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D00B4: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x805D00B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805D00BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805D00C0: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x805D00C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D00C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D00CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805D00D0: jal         0x805D00FC
    // 0x805D00D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D00FC(rdram, ctx);
        goto after_0;
    // 0x805D00D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805D00D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D00DC: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x805D00E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D00E4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x805D00E8: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805D00EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D00F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D00F4: jr          $ra
    // 0x805D00F8: nop

    return;
    // 0x805D00F8: nop

;}
RECOMP_FUNC void func_80463124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80463128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046312C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80463130: jal         0x80045A34
    // 0x80463134: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80463134: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80463138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046313C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80463140: bne         $v0, $zero, L_80463150
    if (ctx->r2 != 0) {
        // 0x80463144: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80463150;
    }
    // 0x80463144: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80463148: b           L_80463170
    // 0x8046314C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80463170;
    // 0x8046314C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80463150:
    // 0x80463150: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80463154: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80463158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046315C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80463160: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80463164: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80463168: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8046316C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
L_80463170:
    // 0x80463170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80463174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80463178: jr          $ra
    // 0x8046317C: nop

    return;
    // 0x8046317C: nop

;}
RECOMP_FUNC void func_80080C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080C84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80080C88: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80080C8C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80080C90: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080C94: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80080C98: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080C9C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080CA0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80080CA4: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80080CA8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80080CAC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080CB0: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80080CB4: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80080CB8: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080CBC: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80080CC0: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080CC4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080CC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080CCC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80080CD0: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80080CD4: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80080CD8: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80080CDC: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80080CE0: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80080CE4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080CE8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80080CEC: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80080CF0: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080CF4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80080CF8: mul.s       $f16, $f18, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80080CFC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x80080D00: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080D04: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80080D08: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80080D0C: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80080D10: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080D14: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80080D18: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80080D1C: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80080D20: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80080D24: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80080D28: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x80080D2C: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80080D30: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80080D34: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80080D38: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80080D3C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80080D40: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80080D44: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80080D48: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80080D4C: jr          $ra
    // 0x80080D50: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80080D50: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80064B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064B6C: addiu       $v0, $v0, 0x65AC
    ctx->r2 = ADD32(ctx->r2, 0X65AC);
    // 0x80064B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064B74: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80064B78: jal         0x8006502C
    // 0x80064B7C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    func_8006502C(rdram, ctx);
        goto after_0;
    // 0x80064B7C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    after_0:
    // 0x80064B80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80064B84: jal         0x80064FEC
    // 0x80064B88: sw          $v0, 0x65B4($at)
    MEM_W(0X65B4, ctx->r1) = ctx->r2;
    func_80064FEC(rdram, ctx);
        goto after_1;
    // 0x80064B88: sw          $v0, 0x65B4($at)
    MEM_W(0X65B4, ctx->r1) = ctx->r2;
    after_1:
    // 0x80064B8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80064B90: jal         0x80065060
    // 0x80064B94: sw          $v0, 0x65B8($at)
    MEM_W(0X65B8, ctx->r1) = ctx->r2;
    func_80065060(rdram, ctx);
        goto after_2;
    // 0x80064B94: sw          $v0, 0x65B8($at)
    MEM_W(0X65B8, ctx->r1) = ctx->r2;
    after_2:
    // 0x80064B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80064BA0: sw          $v0, 0x65BC($at)
    MEM_W(0X65BC, ctx->r1) = ctx->r2;
    // 0x80064BA4: jr          $ra
    // 0x80064BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80064BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806F2E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2E7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F2E80: jal         0x80047090
    // 0x806F2E84: addiu       $a0, $zero, 0x45E6
    ctx->r4 = ADD32(0, 0X45E6);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806F2E84: addiu       $a0, $zero, 0x45E6
    ctx->r4 = ADD32(0, 0X45E6);
    after_0:
    // 0x806F2E88: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806F2E8C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x806F2E90: bne         $v0, $at, L_806F2EA0
    if (ctx->r2 != ctx->r1) {
        // 0x806F2E94: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806F2EA0;
    }
    // 0x806F2E94: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806F2E98: b           L_806F2EE0
    // 0x806F2E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F2EE0;
    // 0x806F2E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F2EA0:
    // 0x806F2EA0: lui         $at, 0x45E6
    ctx->r1 = S32(0X45E6 << 16);
    // 0x806F2EA4: ori         $at, $at, 0x4400
    ctx->r1 = ctx->r1 | 0X4400;
    // 0x806F2EA8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806F2EAC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x806F2EB0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x806F2EB4: jal         0x8004613C
    // 0x806F2EB8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806F2EB8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x806F2EBC: bne         $v0, $zero, L_806F2ECC
    if (ctx->r2 != 0) {
        // 0x806F2EC0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806F2ECC;
    }
    // 0x806F2EC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806F2EC4: b           L_806F2EE0
    // 0x806F2EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F2EE0;
    // 0x806F2EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F2ECC:
    // 0x806F2ECC: jal         0x80044194
    // 0x806F2ED0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806F2ED0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x806F2ED4: jal         0x806F1DDC
    // 0x806F2ED8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_806F1DDC(rdram, ctx);
        goto after_3;
    // 0x806F2ED8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x806F2EDC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_806F2EE0:
    // 0x806F2EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2EE8: jr          $ra
    // 0x806F2EEC: nop

    return;
    // 0x806F2EEC: nop

;}
RECOMP_FUNC void func_80446548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446548: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044654C: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446550: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446554: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446558: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x8044655C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446560: jr          $ra
    // 0x80446564: sw          $t7, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r15;
    return;
    // 0x80446564: sw          $t7, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_807ACB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACB30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807ACB34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ACB38: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x807ACB3C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x807ACB40: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807ACB44: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x807ACB48: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x807ACB4C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x807ACB50: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807ACB54: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x807ACB58: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x807ACB5C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807ACB60: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACB64: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x807ACB68: ori         $t3, $t3, 0x2CC0
    ctx->r11 = ctx->r11 | 0X2CC0;
    // 0x807ACB6C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x807ACB70: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x807ACB74: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x807ACB78: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x807ACB7C: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x807ACB80: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACB84: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x807ACB88: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x807ACB8C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x807ACB90: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x807ACB94: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x807ACB98: ori         $a1, $a1, 0x41C8
    ctx->r5 = ctx->r5 | 0X41C8;
    // 0x807ACB9C: sw          $a1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r5;
    // 0x807ACBA0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x807ACBA4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACBA8: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x807ACBAC: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x807ACBB0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807ACBB4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x807ACBB8: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x807ACBBC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807ACBC0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACBC4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x807ACBC8: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x807ACBCC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x807ACBD0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x807ACBD4: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x807ACBD8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x807ACBDC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACBE0: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x807ACBE4: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x807ACBE8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x807ACBEC: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x807ACBF0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x807ACBF4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x807ACBF8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACBFC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x807ACC00: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x807ACC04: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807ACC08: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x807ACC0C: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x807ACC10: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x807ACC14: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807ACC18: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACC1C: addiu       $t4, $zero, 0x204
    ctx->r12 = ADD32(0, 0X204);
    // 0x807ACC20: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x807ACC24: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x807ACC28: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x807ACC2C: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x807ACC30: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x807ACC34: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x807ACC38: jal         0x807AC8D0
    // 0x807ACC3C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_807AC8D0(rdram, ctx);
        goto after_0;
    // 0x807ACC3C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x807ACC40: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x807ACC44: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x807ACC48: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x807ACC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ACC50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807ACC54: jr          $ra
    // 0x807ACC58: nop

    return;
    // 0x807ACC58: nop

;}
RECOMP_FUNC void func_80665434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80665438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066543C: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x80665440: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80665444: bnel        $t6, $zero, L_806654A8
    if (ctx->r14 != 0) {
        // 0x80665448: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_806654A8;
    }
    goto skip_0;
    // 0x80665448: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8066544C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80665450: lui         $t0, 0x8066
    ctx->r8 = S32(RELOC_HI16(504, 0X2B58) << 16);
    // 0x80665454: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80665458: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8066545C: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x80665460: beq         $at, $zero, L_80665480
    if (ctx->r1 == 0) {
        // 0x80665464: sw          $t8, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r24;
            goto L_80665480;
    }
    // 0x80665464: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x80665468: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8066546C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80665470: lw          $t0, 0x7828($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(504, 0X2B58));
    // 0x80665474: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x80665478: b           L_806654A4
    // 0x8066547C: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
        goto L_806654A4;
    // 0x8066547C: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_80665480:
    // 0x80665480: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80665484: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80665488: lui         $t4, 0x8066
    ctx->r12 = S32(RELOC_HI16(504, 0X2B58) << 16);
    // 0x8066548C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80665490: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x80665494: lw          $t4, 0x7828($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(504, 0X2B58));
    // 0x80665498: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8066549C: sw          $t5, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r13;
    // 0x806654A0: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
L_806654A4:
    // 0x806654A4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_806654A8:
    // 0x806654A8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x806654AC: lbu         $t8, 0x2C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2C);
    // 0x806654B0: beql        $t8, $zero, L_806654C4
    if (ctx->r24 == 0) {
        // 0x806654B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806654C4;
    }
    goto skip_1;
    // 0x806654B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806654B8: jal         0x806654D0
    // 0x806654BC: nop

    func_806654D0(rdram, ctx);
        goto after_0;
    // 0x806654BC: nop

    after_0:
    // 0x806654C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806654C4:
    // 0x806654C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806654C8: jr          $ra
    // 0x806654CC: nop

    return;
    // 0x806654CC: nop

;}
