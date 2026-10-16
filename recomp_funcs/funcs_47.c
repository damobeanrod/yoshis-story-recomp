#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80710238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710238: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8071023C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80710240: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80710244: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80710248: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8071024C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80710250: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80710254: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x80710258: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x8071025C: lbu         $s2, -0x7204($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X7204);
    // 0x80710260: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80710264: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80710268: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8071026C: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x80710270: sll         $a2, $s2, 4
    ctx->r6 = S32(ctx->r18 << 4);
    // 0x80710274: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80710278: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8071027C: lw          $a1, 0x1E4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1E4);
    // 0x80710280: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x80710284: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80710288: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8071028C: jal         0x8070FC30
    // 0x80710290: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8070FC30(rdram, ctx);
        goto after_0;
    // 0x80710290: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80710294: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80710298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8071029C: jal         0x8070FCFC
    // 0x807102A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8070FCFC(rdram, ctx);
        goto after_1;
    // 0x807102A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x807102A4: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x807102A8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x807102AC: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x807102B0: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x807102B4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807102B8: jal         0x8070FDDC
    // 0x807102BC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_8070FDDC(rdram, ctx);
        goto after_2;
    // 0x807102BC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x807102C0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x807102C4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x807102C8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x807102CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x807102D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x807102D4: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x807102D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x807102DC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x807102E0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x807102E4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x807102E8: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x807102EC: addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // 0x807102F0: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x807102F4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x807102F8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x807102FC: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x80710300: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80710304: jal         0x8005C27C
    // 0x80710308: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x80710308: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_3:
    // 0x8071030C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80710310: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80710314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80710318: lw          $t3, 0x1F4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1F4);
    // 0x8071031C: jal         0x80067818
    // 0x80710320: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80710320: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    after_4:
    // 0x80710324: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80710328: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8071032C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710330: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80710334: jal         0x807100BC
    // 0x80710338: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_807100BC(rdram, ctx);
        goto after_5;
    // 0x80710338: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8071033C: beq         $v0, $zero, L_80710354
    if (ctx->r2 == 0) {
        // 0x80710340: addiu       $a0, $zero, 0xBF
        ctx->r4 = ADD32(0, 0XBF);
            goto L_80710354;
    }
    // 0x80710340: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x80710344: jal         0x80067818
    // 0x80710348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80710348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8071034C: b           L_8071039C
    // 0x80710350: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8071039C;
    // 0x80710350: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80710354:
    // 0x80710354: lw          $t4, 0x1E4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1E4);
    // 0x80710358: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8071035C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710360: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80710364: bne         $at, $zero, L_80710390
    if (ctx->r1 != 0) {
        // 0x80710368: nop
    
            goto L_80710390;
    }
    // 0x80710368: nop

    // 0x8071036C: jal         0x8070FFC0
    // 0x80710370: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    func_8070FFC0(rdram, ctx);
        goto after_7;
    // 0x80710370: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    after_7:
    // 0x80710374: jal         0x8070FB48
    // 0x80710378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070FB48(rdram, ctx);
        goto after_8;
    // 0x80710378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8071037C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710380: jal         0x80710C50
    // 0x80710384: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80710C50(rdram, ctx);
        goto after_9;
    // 0x80710384: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80710388: b           L_8071039C
    // 0x8071038C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8071039C;
    // 0x8071038C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80710390:
    // 0x80710390: jal         0x80710C50
    // 0x80710394: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80710C50(rdram, ctx);
        goto after_10;
    // 0x80710394: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80710398: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8071039C:
    // 0x8071039C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807103A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x807103A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x807103A8: jr          $ra
    // 0x807103AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x807103AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80030520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030520: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80030524: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x80030528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003052C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030530: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80030534: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030538: bne         $at, $zero, L_800305B4
    if (ctx->r1 != 0) {
        // 0x8003053C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800305B4;
    }
    // 0x8003053C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030540: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80030544: addiu       $t7, $t7, 0x5D0
    ctx->r15 = ADD32(ctx->r15, 0X5D0);
    // 0x80030548: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003054C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030550: lwc1        $f4, -0x40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X40);
    // 0x80030554: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80030558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003055C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030560: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x80030564: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x80030568: lwc1        $f8, -0x3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3C);
    // 0x8003056C: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x80030570: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x80030574: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80030578: lbu         $t9, 0x77($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X77);
    // 0x8003057C: beql        $t9, $zero, L_80030598
    if (ctx->r25 == 0) {
        // 0x80030580: lbu         $t1, 0x79($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X79);
            goto L_80030598;
    }
    goto skip_0;
    // 0x80030580: lbu         $t1, 0x79($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X79);
    skip_0:
    // 0x80030584: jal         0x8005FB2C
    // 0x80030588: nop

    func_8005FB2C(rdram, ctx);
        goto after_0;
    // 0x80030588: nop

    after_0:
    // 0x8003058C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80030590: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80030594: lbu         $t1, 0x79($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X79);
L_80030598:
    // 0x80030598: beql        $t1, $zero, L_800305AC
    if (ctx->r9 == 0) {
        // 0x8003059C: addiu       $a0, $zero, 0x207
        ctx->r4 = ADD32(0, 0X207);
            goto L_800305AC;
    }
    goto skip_1;
    // 0x8003059C: addiu       $a0, $zero, 0x207
    ctx->r4 = ADD32(0, 0X207);
    skip_1:
    // 0x800305A0: jal         0x8005FBC0
    // 0x800305A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FBC0(rdram, ctx);
        goto after_1;
    // 0x800305A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800305A8: addiu       $a0, $zero, 0x207
    ctx->r4 = ADD32(0, 0X207);
L_800305AC:
    // 0x800305AC: jal         0x80067818
    // 0x800305B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x800305B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_800305B4:
    // 0x800305B4: jal         0x80028220
    // 0x800305B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_3;
    // 0x800305B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800305BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800305C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800305C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800305C8: jr          $ra
    // 0x800305CC: nop

    return;
    // 0x800305CC: nop

;}
RECOMP_FUNC void func_8046749C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046749C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804674A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804674A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804674A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804674AC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804674B0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804674B4: jal         0x80466A0C
    // 0x804674B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80466A0C(rdram, ctx);
        goto after_0;
    // 0x804674B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x804674BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804674C0: jal         0x80466B28
    // 0x804674C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80466B28(rdram, ctx);
        goto after_1;
    // 0x804674C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x804674C8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x804674CC: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x804674D0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804674D4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x804674D8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804674DC: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x804674E0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x804674E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x804674E8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x804674EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804674F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804674F4: jr          $ra
    // 0x804674F8: nop

    return;
    // 0x804674F8: nop

;}
RECOMP_FUNC void func_8077FB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FB48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8077FB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FB50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8077FB54: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8077FB58: lw          $a0, 0x264($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X264);
    // 0x8077FB5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8077FB60: jal         0x800443EC
    // 0x8077FB64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x8077FB64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077FB68: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8077FB6C: bne         $v0, $zero, L_8077FB7C
    if (ctx->r2 != 0) {
        // 0x8077FB70: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8077FB7C;
    }
    // 0x8077FB70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8077FB74: b           L_8077FC6C
    // 0x8077FB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8077FC6C;
    // 0x8077FB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8077FB7C:
    // 0x8077FB7C: lhu         $v0, 0xC($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XC);
    // 0x8077FB80: addiu       $at, $zero, 0x46FD
    ctx->r1 = ADD32(0, 0X46FD);
    // 0x8077FB84: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    // 0x8077FB88: bne         $v0, $at, L_8077FBBC
    if (ctx->r2 != ctx->r1) {
        // 0x8077FB8C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8077FBBC;
    }
    // 0x8077FB8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8077FB90: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x8077FB94: lw          $t8, 0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X38);
    // 0x8077FB98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8077FB9C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8077FBA0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8077FBA4: sb          $t9, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r25;
    // 0x8077FBA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8077FBAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8077FBB0: swc1        $f6, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f6.u32l;
    // 0x8077FBB4: b           L_8077FC24
    // 0x8077FBB8: swc1        $f10, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f10.u32l;
        goto L_8077FC24;
    // 0x8077FBB8: swc1        $f10, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f10.u32l;
L_8077FBBC:
    // 0x8077FBBC: addiu       $at, $zero, 0x4734
    ctx->r1 = ADD32(0, 0X4734);
    // 0x8077FBC0: bne         $v0, $at, L_8077FBE8
    if (ctx->r2 != ctx->r1) {
        // 0x8077FBC4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8077FBE8;
    }
    // 0x8077FBC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8077FBC8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8077FBCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8077FBD0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8077FBD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8077FBD8: sb          $t0, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r8;
    // 0x8077FBDC: swc1        $f16, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f16.u32l;
    // 0x8077FBE0: b           L_8077FC24
    // 0x8077FBE4: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
        goto L_8077FC24;
    // 0x8077FBE4: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
L_8077FBE8:
    // 0x8077FBE8: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8077FBEC: lw          $t1, 0x174($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X174);
    // 0x8077FBF0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8077FBF4: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    // 0x8077FBF8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8077FBFC: lwc1        $f6, 0x88($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X88);
    // 0x8077FC00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8077FC04: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8077FC08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8077FC0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8077FC10: lwc1        $f16, 0x10($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8077FC14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8077FC18: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8077FC1C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8077FC20: swc1        $f6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
L_8077FC24:
    // 0x8077FC24: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(781, 0X800) << 16);
    // 0x8077FC28: lwc1        $f10, 0x110($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X800));
    // 0x8077FC2C: lwc1        $f8, 0x8C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8C);
    // 0x8077FC30: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(781, 0X808) << 16);
    // 0x8077FC34: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8077FC38: nop

    // 0x8077FC3C: bc1f        L_8077FC50
    if (!c1cs) {
        // 0x8077FC40: nop
    
            goto L_8077FC50;
    }
    // 0x8077FC40: nop

    // 0x8077FC44: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(781, 0X804) << 16);
    // 0x8077FC48: b           L_8077FC54
    // 0x8077FC4C: lwc1        $f0, 0x114($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X804));
        goto L_8077FC54;
    // 0x8077FC4C: lwc1        $f0, 0x114($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X804));
L_8077FC50:
    // 0x8077FC50: lwc1        $f0, 0x118($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X808));
L_8077FC54:
    // 0x8077FC54: swc1        $f0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f0.u32l;
    // 0x8077FC58: jal         0x80047AB8
    // 0x8077FC5C: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8077FC5C: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    after_1:
    // 0x8077FC60: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8077FC64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8077FC68: sw          $zero, 0x264($t4)
    MEM_W(0X264, ctx->r12) = 0;
L_8077FC6C:
    // 0x8077FC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8077FC74: jr          $ra
    // 0x8077FC78: nop

    return;
    // 0x8077FC78: nop

;}
RECOMP_FUNC void func_80707264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80707264: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80707268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070726C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80707270: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80707274: jal         0x8004700C
    // 0x80707278: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80707278: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8070727C: beq         $v0, $zero, L_80707378
    if (ctx->r2 == 0) {
        // 0x80707280: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80707378;
    }
    // 0x80707280: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80707284: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80707288: sw          $t6, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r14;
    // 0x8070728C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80707290: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x80707294: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80707298: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8070729C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807072A0: nop

    // 0x807072A4: bc1f        L_807072B0
    if (!c1cs) {
        // 0x807072A8: nop
    
            goto L_807072B0;
    }
    // 0x807072A8: nop

    // 0x807072AC: sw          $zero, 0x138($a1)
    MEM_W(0X138, ctx->r5) = 0;
L_807072B0:
    // 0x807072B0: jal         0x800653D8
    // 0x807072B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x807072B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x807072B8: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x807072BC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x807072C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x807072C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807072C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807072CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x807072D0: lui         $at, 0xC30A
    ctx->r1 = S32(0XC30A << 16);
    // 0x807072D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807072D8: lw          $t9, 0x138($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X138);
    // 0x807072DC: lui         $at, 0x430A
    ctx->r1 = S32(0X430A << 16);
    // 0x807072E0: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x807072E4: lhu         $t0, 0x32($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X32);
    // 0x807072E8: add.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x807072EC: bne         $t9, $zero, L_80707300
    if (ctx->r25 != 0) {
        // 0x807072F0: sub.s       $f2, $f18, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f0.fl;
            goto L_80707300;
    }
    // 0x807072F0: sub.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x807072F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807072F8: nop

    // 0x807072FC: add.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f0.fl;
L_80707300:
    // 0x80707300: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80707304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80707308: addiu       $at, $zero, 0x461F
    ctx->r1 = ADD32(0, 0X461F);
    // 0x8070730C: bnel        $t0, $at, L_80707320
    if (ctx->r8 != ctx->r1) {
        // 0x80707310: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80707320;
    }
    goto skip_0;
    // 0x80707310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x80707314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80707318: nop

    // 0x8070731C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
L_80707320:
    // 0x80707320: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80707324: jal         0x800653D8
    // 0x80707328: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x80707328: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8070732C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80707330: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80707334: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x80707338: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8070733C: lw          $t1, 0x478($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X478);
    // 0x80707340: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80707344: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80707348: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8070734C: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80707350: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80707354: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80707358: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8070735C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80707360: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80707364: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x80707368: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x8070736C: lwc1        $f10, 0x34($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X34);
    // 0x80707370: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80707374: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
L_80707378:
    // 0x80707378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070737C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80707380: jr          $ra
    // 0x80707384: nop

    return;
    // 0x80707384: nop

;}
RECOMP_FUNC void ceilf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082018: ceil.w.s    $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(ceilf(ctx->f12.fl));
    // 0x8008201C: jr          $ra
    // 0x80082020: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x80082020: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_8003B218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B220: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8003B224: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003B228: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8003B22C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8003B230: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8003B234: addiu       $t7, $t7, -0x1400
    ctx->r15 = ADD32(ctx->r15, -0X1400);
    // 0x8003B238: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8003B23C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B240: jal         0x8003B540
    // 0x8003B244: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8003B540(rdram, ctx);
        goto after_0;
    // 0x8003B244: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8003B248: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003B24C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B254: jal         0x8003AF90
    // 0x8003B258: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    func_8003AF90(rdram, ctx);
        goto after_1;
    // 0x8003B258: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    after_1:
    // 0x8003B25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B264: jr          $ra
    // 0x8003B268: nop

    return;
    // 0x8003B268: nop

;}
RECOMP_FUNC void func_80535B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535B68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535B6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535B70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535B78: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535B7C: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X12A8) << 16);
    // 0x80535B80: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X12BC) << 16);
    // 0x80535B84: addiu       $a1, $a1, 0x6B4C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X12BC));
    // 0x80535B88: addiu       $a2, $a2, 0x6B38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X12A8));
    // 0x80535B8C: jal         0x80535958
    // 0x80535B90: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535B90: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80535B94: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535B98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535BA0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535BA4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535BA8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535BB4: jr          $ra
    // 0x80535BB8: nop

    return;
    // 0x80535BB8: nop

;}
RECOMP_FUNC void func_80683014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80683014: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80683018: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8068301C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80683020: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80683024: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80683028: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8068302C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683030: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683034: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683038: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068303C: jr          $ra
    // 0x80683040: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683040: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806CD718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD718: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CD71C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806CD720: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806CD724: jal         0x806CCF00
    // 0x806CD728: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD728: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD72C: jal         0x806CD470
    // 0x806CD730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD738: jal         0x806CB7EC
    // 0x806CD73C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_806CB7EC(rdram, ctx);
        goto after_2;
    // 0x806CD73C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_2:
    // 0x806CD740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806CD744: lui         $a1, 0x3A83
    ctx->r5 = S32(0X3A83 << 16);
    // 0x806CD748: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x806CD74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD750: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806CD754: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x806CD758: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x806CD75C: jal         0x806CCF4C
    // 0x806CD760: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_806CCF4C(rdram, ctx);
        goto after_3;
    // 0x806CD760: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x806CD764: jal         0x806CCE38
    // 0x806CD768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_4;
    // 0x806CD768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CD76C: beq         $v0, $zero, L_806CD79C
    if (ctx->r2 == 0) {
        // 0x806CD770: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD79C;
    }
    // 0x806CD770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD774: jal         0x806CB78C
    // 0x806CD778: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_806CB78C(rdram, ctx);
        goto after_5;
    // 0x806CD778: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_5:
    // 0x806CD77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD784: jal         0x806CED40
    // 0x806CD788: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806CED40(rdram, ctx);
        goto after_6;
    // 0x806CD788: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_6:
    // 0x806CD78C: jal         0x806CCCE4
    // 0x806CD790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_7;
    // 0x806CD790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CD794: jal         0x806CC008
    // 0x806CD798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_8;
    // 0x806CD798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_806CD79C:
    // 0x806CD79C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806CD7A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806CD7A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806CD7A8: jr          $ra
    // 0x806CD7AC: nop

    return;
    // 0x806CD7AC: nop

;}
RECOMP_FUNC void func_805AE594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE594: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE598: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE59C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE5A0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE5A4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE5A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE5AC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE5B0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE5B4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE5B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE5BC: jr          $ra
    // 0x805AE5C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE5C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800073F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800073FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80007404: jal         0x80005640
    // 0x80007408: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80005640(rdram, ctx);
        goto after_0;
    // 0x80007408: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000740C: beq         $v0, $zero, L_8000741C
    if (ctx->r2 == 0) {
        // 0x80007410: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8000741C;
    }
    // 0x80007410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80007414: b           L_80007440
    // 0x80007418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80007440;
    // 0x80007418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000741C:
    // 0x8000741C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80007420: jal         0x80004160
    // 0x80007424: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_80004160(rdram, ctx);
        goto after_1;
    // 0x80007424: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80007428: beql        $v0, $zero, L_8000743C
    if (ctx->r2 == 0) {
        // 0x8000742C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000743C;
    }
    goto skip_0;
    // 0x8000742C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80007430: b           L_80007440
    // 0x80007434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80007440;
    // 0x80007434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000743C:
    // 0x8000743C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007440:
    // 0x80007440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007444: jr          $ra
    // 0x80007448: nop

    return;
    // 0x80007448: nop

;}
RECOMP_FUNC void func_80065060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065060: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80065064: addiu       $v0, $a1, -0x6C08
    ctx->r2 = ADD32(ctx->r5, -0X6C08);
    // 0x80065068: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8006506C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065070: beq         $a0, $v0, L_80065094
    if (ctx->r4 == ctx->r2) {
        // 0x80065074: nop
    
            goto L_80065094;
    }
    // 0x80065074: nop

    // 0x80065078: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
L_8006507C:
    // 0x8006507C: bnel        $t6, $zero, L_8006508C
    if (ctx->r14 != 0) {
        // 0x80065080: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8006508C;
    }
    goto skip_0;
    // 0x80065080: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80065084: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80065088: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_8006508C:
    // 0x8006508C: bnel        $a0, $v0, L_8006507C
    if (ctx->r4 != ctx->r2) {
        // 0x80065090: lhu         $t6, 0x2($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X2);
            goto L_8006507C;
    }
    goto skip_1;
    // 0x80065090: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    skip_1:
L_80065094:
    // 0x80065094: jr          $ra
    // 0x80065098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8073FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073FC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073FC38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8073FC3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8073FC40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8073FC44: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8073FC48: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8073FC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073FC50: beq         $v0, $at, L_8073FC60
    if (ctx->r2 == ctx->r1) {
        // 0x8073FC54: addiu       $at, $zero, 0x4018
        ctx->r1 = ADD32(0, 0X4018);
            goto L_8073FC60;
    }
    // 0x8073FC54: addiu       $at, $zero, 0x4018
    ctx->r1 = ADD32(0, 0X4018);
    // 0x8073FC58: bnel        $v0, $at, L_8073FC78
    if (ctx->r2 != ctx->r1) {
        // 0x8073FC5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073FC78;
    }
    goto skip_0;
    // 0x8073FC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8073FC60:
    // 0x8073FC60: jal         0x8073F1B0
    // 0x8073FC64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8073F1B0(rdram, ctx);
        goto after_0;
    // 0x8073FC64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8073FC68: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8073FC6C: jal         0x8003DC78
    // 0x8073FC70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003DC78(rdram, ctx);
        goto after_1;
    // 0x8073FC70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8073FC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073FC78:
    // 0x8073FC78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073FC7C: jr          $ra
    // 0x8073FC80: nop

    return;
    // 0x8073FC80: nop

;}
RECOMP_FUNC void func_80679284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80679288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067928C: jal         0x80677FF0
    // 0x80679290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80677FF0(rdram, ctx);
        goto after_0;
    // 0x80679290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80679294: jal         0x80045BD8
    // 0x80679298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80679298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8067929C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806792A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806792A4: jr          $ra
    // 0x806792A8: nop

    return;
    // 0x806792A8: nop

;}
RECOMP_FUNC void func_804B9944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9944: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x804B9948: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804B994C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B9950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B9954: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804B9958: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804B995C: jal         0x8004921C
    // 0x804B9960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804B9960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804B9964: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x804B9968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B996C: jal         0x8004921C
    // 0x804B9970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B9970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804B9974: lh          $s1, 0x2A($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2A);
    // 0x804B9978: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B997C: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x804B9980: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x804B9984: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B9988: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x804B998C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804B9990: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x804B9994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B999C: mflo        $t8
    ctx->r24 = lo;
    // 0x804B99A0: nop

    // 0x804B99A4: nop

    // 0x804B99A8: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B99AC: lw          $t8, 0x80($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X80);
    // 0x804B99B0: mflo        $t9
    ctx->r25 = lo;
    // 0x804B99B4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x804B99B8: jal         0x8004921C
    // 0x804B99BC: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x804B99BC: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    after_2:
    // 0x804B99C0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B99C4: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B99C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B99CC: jal         0x8004921C
    // 0x804B99D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x804B99D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x804B99D4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B99D8: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x804B99DC: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B99E0: lbu         $t7, 0x145($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X145);
    // 0x804B99E4: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B99E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B99EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B99F0: mflo        $t8
    ctx->r24 = lo;
    // 0x804B99F4: nop

    // 0x804B99F8: nop

    // 0x804B99FC: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B9A00: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B9A04: mflo        $t6
    ctx->r14 = lo;
    // 0x804B9A08: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x804B9A0C: jal         0x8004921C
    // 0x804B9A10: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x804B9A10: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    after_4:
    // 0x804B9A14: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B9A18: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B9A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9A20: jal         0x8004921C
    // 0x804B9A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x804B9A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804B9A28: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804B9A2C: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x804B9A30: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B9A34: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x804B9A38: lui         $s2, 0x400
    ctx->r18 = S32(0X400 << 16);
    // 0x804B9A3C: ori         $s2, $s2, 0x81FF
    ctx->r18 = ctx->r18 | 0X81FF;
    // 0x804B9A40: addiu       $t9, $t7, 0x20
    ctx->r25 = ADD32(ctx->r15, 0X20);
    // 0x804B9A44: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x804B9A48: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B9A4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x804B9A50: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804B9A54: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x804B9A58: mflo        $t8
    ctx->r24 = lo;
    // 0x804B9A5C: lui         $t3, 0xB100
    ctx->r11 = S32(0XB100 << 16);
    // 0x804B9A60: nop

    // 0x804B9A64: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B9A68: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B9A6C: mflo        $t7
    ctx->r15 = lo;
    // 0x804B9A70: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x804B9A74: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x804B9A78: lw          $a3, 0x1F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1F4);
    // 0x804B9A7C: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B9A80: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B9A84: lw          $t0, 0x960($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X960);
    // 0x804B9A88: addiu       $t5, $a3, 0x968
    ctx->r13 = ADD32(ctx->r7, 0X968);
    // 0x804B9A8C: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x804B9A90: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x804B9A94: andi        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 & 0X1;
    // 0x804B9A98: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x804B9A9C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x804B9AA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B9AA4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x804B9AA8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B9AAC: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x804B9AB0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x804B9AB4: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x804B9AB8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B9ABC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B9AC0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x804B9AC4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9AC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B9ACC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x804B9AD0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9AD4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B9AD8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B9ADC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9AE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B9AE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B9AE8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B9AEC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B9AF0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9AF4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B9AF8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B9AFC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B9B00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B9B04: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B9B08: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B9B0C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B9B10: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B9B14: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B9B18: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9B1C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B9B20: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B9B24: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B9B28: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x804B9B2C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9B30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9B34: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x804B9B38: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B9B3C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9B40: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x804B9B44: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x804B9B48: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B9B4C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9B50: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B9B54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B9B58: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B9B5C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B9B60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804B9B64: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B9B68: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B9B6C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x804B9B70: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x804B9B74: lui         $t6, 0xB100
    ctx->r14 = S32(0XB100 << 16);
    // 0x804B9B78: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x804B9B7C: ori         $t9, $t9, 0x604
    ctx->r25 = ctx->r25 | 0X604;
    // 0x804B9B80: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9B84: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x804B9B88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804B9B8C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B9B90: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B9B94: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x804B9B98: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x804B9B9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9BA0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x804B9BA4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x804B9BA8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9BAC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B9BB0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B9BB4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x804B9BB8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x804B9BBC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9BC0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9BC4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B9BC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B9BCC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B9BD0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9BD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B9BD8: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B9BDC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B9BE0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B9BE4: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B9BE8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B9BEC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9BF0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B9BF4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B9BF8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B9BFC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804B9C00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B9C04: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9C08: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B9C0C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x804B9C10: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x804B9C14: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B9C18: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B9C1C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B9C20: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x804B9C24: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x804B9C28: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B9C2C: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x804B9C30: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
L_804B9C34:
    // 0x804B9C34: bne         $t4, $zero, L_804B9C44
    if (ctx->r12 != 0) {
        // 0x804B9C38: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_804B9C44;
    }
    // 0x804B9C38: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804B9C3C: b           L_804B9C44
    // 0x804B9C40: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
        goto L_804B9C44;
    // 0x804B9C40: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
L_804B9C44:
    // 0x804B9C44: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B9C48: beq         $at, $zero, L_804B9CCC
    if (ctx->r1 == 0) {
        // 0x804B9C4C: sll         $a0, $t0, 2
        ctx->r4 = S32(ctx->r8 << 2);
            goto L_804B9CCC;
    }
    // 0x804B9C4C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x804B9C50: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x804B9C54: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
L_804B9C58:
    // 0x804B9C58: slti        $at, $a1, 0x1C
    ctx->r1 = SIGNED(ctx->r5) < 0X1C ? 1 : 0;
    // 0x804B9C5C: beq         $at, $zero, L_804B9CCC
    if (ctx->r1 == 0) {
        // 0x804B9C60: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_804B9CCC;
    }
    // 0x804B9C60: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x804B9C64: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x804B9C68: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B9C6C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B9C70: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x804B9C74: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x804B9C78: sll         $t8, $a2, 8
    ctx->r24 = S32(ctx->r6 << 8);
    // 0x804B9C7C: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B9C80: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B9C84: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x804B9C88: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B9C8C: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x804B9C90: addiu       $t6, $v1, 0x6
    ctx->r14 = ADD32(ctx->r3, 0X6);
    // 0x804B9C94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9C98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B9C9C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x804B9CA0: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x804B9CA4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9CA8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804B9CAC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x804B9CB0: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B9CB4: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B9CB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804B9CBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804B9CC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x804B9CC4: bne         $at, $zero, L_804B9C58
    if (ctx->r1 != 0) {
        // 0x804B9CC8: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_804B9C58;
    }
    // 0x804B9CC8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B9CCC:
    // 0x804B9CCC: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B9CD0: beq         $at, $zero, L_804B9D24
    if (ctx->r1 == 0) {
        // 0x804B9CD4: sll         $t6, $t4, 9
        ctx->r14 = S32(ctx->r12 << 9);
            goto L_804B9D24;
    }
    // 0x804B9CD4: sll         $t6, $t4, 9
    ctx->r14 = S32(ctx->r12 << 9);
    // 0x804B9CD8: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B9CDC: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B9CE0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B9CE4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B9CE8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x804B9CEC: sll         $t6, $a2, 8
    ctx->r14 = S32(ctx->r6 << 8);
    // 0x804B9CF0: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x804B9CF4: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B9CF8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B9CFC: addiu       $t7, $v1, 0x6
    ctx->r15 = ADD32(ctx->r3, 0X6);
    // 0x804B9D00: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x804B9D04: or          $t0, $t9, $a3
    ctx->r8 = ctx->r25 | ctx->r7;
    // 0x804B9D08: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x804B9D0C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9D10: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x804B9D14: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B9D18: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B9D1C: b           L_804B9DA8
    // 0x804B9D20: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
        goto L_804B9DA8;
    // 0x804B9D20: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
L_804B9D24:
    // 0x804B9D24: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x804B9D28: bne         $t4, $ra, L_804B9D44
    if (ctx->r12 != ctx->r31) {
        // 0x804B9D2C: addiu       $v1, $v1, 0x200
        ctx->r3 = ADD32(ctx->r3, 0X200);
            goto L_804B9D44;
    }
    // 0x804B9D2C: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // 0x804B9D30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9D34: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x804B9D38: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B9D3C: b           L_804B9D54
    // 0x804B9D40: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_804B9D54;
    // 0x804B9D40: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B9D44:
    // 0x804B9D44: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9D48: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B9D4C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B9D50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B9D54:
    // 0x804B9D54: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804B9D58: bne         $t4, $s1, L_804B9C34
    if (ctx->r12 != ctx->r17) {
        // 0x804B9D5C: nop
    
            goto L_804B9C34;
    }
    // 0x804B9D5C: nop

    // 0x804B9D60: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B9D64: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B9D68: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B9D6C: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B9D70: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x804B9D74: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x804B9D78: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x804B9D7C: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B9D80: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B9D84: addiu       $t9, $v1, 0x6
    ctx->r25 = ADD32(ctx->r3, 0X6);
    // 0x804B9D88: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x804B9D8C: or          $t0, $t6, $a3
    ctx->r8 = ctx->r14 | ctx->r7;
    // 0x804B9D90: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x804B9D94: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B9D98: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x804B9D9C: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B9DA0: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B9DA4: or          $t3, $t9, $a3
    ctx->r11 = ctx->r25 | ctx->r7;
L_804B9DA8:
    // 0x804B9DA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B9DAC: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B9DB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B9DB4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x804B9DB8: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B9DBC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B9DC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B9DC4: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B9DC8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B9DCC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B9DD0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x804B9DD4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B9DD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B9DDC: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x804B9DE0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B9DE4: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B9DE8: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B9DEC: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x804B9DF0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B9DF4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B9DF8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B9DFC: addiu       $t1, $a2, 0x8
    ctx->r9 = ADD32(ctx->r6, 0X8);
    // 0x804B9E00: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B9E04: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B9E08: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B9E0C: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x804B9E10: ori         $t7, $t7, 0x600
    ctx->r15 = ctx->r15 | 0X600;
    // 0x804B9E14: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x804B9E18: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B9E1C: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B9E20: lui         $t6, 0x5
    ctx->r14 = S32(0X5 << 16);
    // 0x804B9E24: ori         $t6, $t6, 0xC05C
    ctx->r14 = ctx->r14 | 0XC05C;
    // 0x804B9E28: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x804B9E2C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804B9E30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B9E34: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B9E38: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x804B9E3C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B9E40: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B9E44: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804B9E48: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x804B9E4C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B9E50: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x804B9E54: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x804B9E58: sw          $t7, 0x960($t8)
    MEM_W(0X960, ctx->r24) = ctx->r15;
    // 0x804B9E5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804B9E60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804B9E64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804B9E68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B9E6C: jr          $ra
    // 0x804B9E70: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x804B9E70: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8004941C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004941C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80049420: addiu       $v1, $v1, 0x5A0
    ctx->r3 = ADD32(ctx->r3, 0X5A0);
    // 0x80049424: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80049428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004942C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80049430: bne         $t6, $at, L_80049460
    if (ctx->r14 != ctx->r1) {
        // 0x80049434: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80049460;
    }
    // 0x80049434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049438: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x8004943C: jal         0x80067F78
    // 0x80049440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067F78(rdram, ctx);
        goto after_0;
    // 0x80049440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80049444: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80049448: addiu       $v1, $v1, 0x5A0
    ctx->r3 = ADD32(ctx->r3, 0X5A0);
    // 0x8004944C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80049450: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80049454: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x80049458: jal         0x800678F0
    // 0x8004945C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800678F0(rdram, ctx);
        goto after_1;
    // 0x8004945C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80049460:
    // 0x80049460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049468: jr          $ra
    // 0x8004946C: nop

    return;
    // 0x8004946C: nop

;}
RECOMP_FUNC void func_8066A0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A0EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066A0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A0F4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066A0F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066A0FC: jal         0x80669E80
    // 0x8066A100: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A100: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066A104: jal         0x80669FA4
    // 0x8066A108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8066A10C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066A110: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8066A114: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8066A118: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8066A11C: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8066A120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066A124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A128: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8066A12C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8066A130: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8066A134: nop

    // 0x8066A138: bc1fl       L_8066A14C
    if (!c1cs) {
        // 0x8066A13C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A14C;
    }
    goto skip_0;
    // 0x8066A13C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A140: jal         0x8066A790
    // 0x8066A144: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A144: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A14C:
    // 0x8066A14C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066A150: jr          $ra
    // 0x8066A154: nop

    return;
    // 0x8066A154: nop

;}
RECOMP_FUNC void func_800455DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800455DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800455E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800455E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800455E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800455EC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x800455F0: lw          $s0, 0x16C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X16C);
    // 0x800455F4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800455F8: jal         0x80045520
    // 0x800455FC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_80045520(rdram, ctx);
        goto after_0;
    // 0x800455FC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x80045600: bne         $v0, $zero, L_80045610
    if (ctx->r2 != 0) {
        // 0x80045604: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80045610;
    }
    // 0x80045604: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80045608: b           L_800456DC
    // 0x8004560C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800456DC;
    // 0x8004560C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045610:
    // 0x80045610: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x80045614: addiu       $t8, $t7, 0x74
    ctx->r24 = ADD32(ctx->r15, 0X74);
    // 0x80045618: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x8004561C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80045620: lw          $t9, 0x168($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X168);
    // 0x80045624: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80045628: lw          $s1, 0x84($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X84);
    // 0x8004562C: bnel        $t1, $zero, L_80045640
    if (ctx->r9 != 0) {
        // 0x80045630: lbu         $t2, 0x164($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X164);
            goto L_80045640;
    }
    goto skip_0;
    // 0x80045630: lbu         $t2, 0x164($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X164);
    skip_0:
    // 0x80045634: b           L_800456D8
    // 0x80045638: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
        goto L_800456D8;
    // 0x80045638: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
    // 0x8004563C: lbu         $t2, 0x164($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X164);
L_80045640:
    // 0x80045640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045644: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045648: bne         $t2, $at, L_80045660
    if (ctx->r10 != ctx->r1) {
        // 0x8004564C: addiu       $a0, $a0, 0x610
        ctx->r4 = ADD32(ctx->r4, 0X610);
            goto L_80045660;
    }
    // 0x8004564C: addiu       $a0, $a0, 0x610
    ctx->r4 = ADD32(ctx->r4, 0X610);
    // 0x80045650: jal         0x80071380
    // 0x80045654: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80045654: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    after_1:
    // 0x80045658: b           L_800456DC
    // 0x8004565C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800456DC;
    // 0x8004565C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045660:
    // 0x80045660: jal         0x8005AB3C
    // 0x80045664: nop

    func_8005AB3C(rdram, ctx);
        goto after_2;
    // 0x80045664: nop

    after_2:
    // 0x80045668: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8004566C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80045670: jal         0x8005ABF4
    // 0x80045674: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8005ABF4(rdram, ctx);
        goto after_3;
    // 0x80045674: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80045678: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8004567C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80045680: jal         0x8007336C
    // 0x80045684: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8007336C(rdram, ctx);
        goto after_4;
    // 0x80045684: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80045688: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004568C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80045690: jal         0x8005ABB0
    // 0x80045694: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    func_8005ABB0(rdram, ctx);
        goto after_5;
    // 0x80045694: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_5:
    // 0x80045698: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8004569C: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800456A0: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    // 0x800456A4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800456A8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800456AC: sw          $t5, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r13;
    // 0x800456B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800456B4: jal         0x80065528
    // 0x800456B8: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    func_80065528(rdram, ctx);
        goto after_6;
    // 0x800456B8: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    after_6:
    // 0x800456BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800456C0: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x800456C4: jal         0x80065528
    // 0x800456C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80065528(rdram, ctx);
        goto after_7;
    // 0x800456C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x800456CC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800456D0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800456D4: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
L_800456D8:
    // 0x800456D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800456DC:
    // 0x800456DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800456E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800456E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800456E8: jr          $ra
    // 0x800456EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800456EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8067AAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067AAD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067AAD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067AADC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8067AAE0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067AAE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AAE8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8067AAEC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067AAF0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067AAF4: lbu         $v1, 0x37($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X37);
    // 0x8067AAF8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8067AAFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067AB00: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2718) << 16);
    // 0x8067AB04: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8067AB08: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8067AB0C: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x8067AB10: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8067AB14: beql        $v0, $zero, L_8067AB64
    if (ctx->r2 == 0) {
        // 0x8067AB18: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_8067AB64;
    }
    goto skip_0;
    // 0x8067AB18: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8067AB1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067AB20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AB24: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067AB28: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8067AB2C: nop

    // 0x8067AB30: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8067AB34: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8067AB38: nop

    // 0x8067AB3C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8067AB40: bne         $v0, $zero, L_8067AB58
    if (ctx->r2 != 0) {
        // 0x8067AB44: nop
    
            goto L_8067AB58;
    }
    // 0x8067AB44: nop

    // 0x8067AB48: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8067AB4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067AB50: b           L_8067AB70
    // 0x8067AB54: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8067AB70;
    // 0x8067AB54: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8067AB58:
    // 0x8067AB58: b           L_8067AB70
    // 0x8067AB5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8067AB70;
    // 0x8067AB5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8067AB60: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_8067AB64:
    // 0x8067AB64: nop

    // 0x8067AB68: bltz        $v0, L_8067AB58
    if (SIGNED(ctx->r2) < 0) {
        // 0x8067AB6C: nop
    
            goto L_8067AB58;
    }
    // 0x8067AB6C: nop

L_8067AB70:
    // 0x8067AB70: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8067AB74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067AB78: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x8067AB7C: beq         $at, $zero, L_8067ABD8
    if (ctx->r1 == 0) {
        // 0x8067AB80: addiu       $v1, $v1, -0x9
        ctx->r3 = ADD32(ctx->r3, -0X9);
            goto L_8067ABD8;
    }
    // 0x8067AB80: addiu       $v1, $v1, -0x9
    ctx->r3 = ADD32(ctx->r3, -0X9);
    // 0x8067AB84: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8067AB88: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2708) << 16);
    // 0x8067AB8C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8067AB90: lw          $t9, -0x3C48($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X2708));
    // 0x8067AB94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067AB98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8067AB9C: jalr        $t9
    // 0x8067ABA0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067ABA0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8067ABA4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067ABA8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2728) << 16);
    // 0x8067ABAC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067ABB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067ABB4: lwc1        $f8, -0x3C28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2728));
    // 0x8067ABB8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2738) << 16);
    // 0x8067ABBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067ABC0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8067ABC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067ABC8: bc1fl       L_8067AC28
    if (!c1cs) {
        // 0x8067ABCC: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067AC28;
    }
    goto skip_1;
    // 0x8067ABCC: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x8067ABD0: b           L_8067AC24
    // 0x8067ABD4: lwc1        $f0, -0x3C18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2738));
        goto L_8067AC24;
    // 0x8067ABD4: lwc1        $f0, -0x3C18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2738));
L_8067ABD8:
    // 0x8067ABD8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8067ABDC: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8067ABE0: lw          $t9, -0x3C38($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X2718));
    // 0x8067ABE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067ABE8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8067ABEC: jalr        $t9
    // 0x8067ABF0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8067ABF0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8067ABF4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067ABF8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2748) << 16);
    // 0x8067ABFC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067AC00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AC04: lwc1        $f10, -0x3C08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2748));
    // 0x8067AC08: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2758) << 16);
    // 0x8067AC0C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067AC10: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8067AC14: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AC18: bc1fl       L_8067AC28
    if (!c1cs) {
        // 0x8067AC1C: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067AC28;
    }
    goto skip_2;
    // 0x8067AC1C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_2:
    // 0x8067AC20: lwc1        $f0, -0x3BF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2758));
L_8067AC24:
    // 0x8067AC24: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
L_8067AC28:
    // 0x8067AC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067AC2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067AC30: jr          $ra
    // 0x8067AC34: nop

    return;
    // 0x8067AC34: nop

;}
RECOMP_FUNC void func_805E42F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E42F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E42F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E42FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805E4300: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805E4304: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805E4308: jal         0x80067BBC
    // 0x805E430C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805E430C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x805E4310: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4314: jal         0x80067818
    // 0x805E4318: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805E4318: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805E431C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4324: jr          $ra
    // 0x805E4328: nop

    return;
    // 0x805E4328: nop

;}
RECOMP_FUNC void func_80469100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469100: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80469104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469108: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046910C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80469110: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80469114: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80469118: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8046911C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80469120: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80469124: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80469128: jal         0x80047AB8
    // 0x8046912C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8046912C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80469130: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80469134: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80469138: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8046913C: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80469140: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80469144: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80469148: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8046914C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80469150: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80469154: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80469158: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8046915C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80469160: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80469164: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80469168: nop

    // 0x8046916C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80469170: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80469174: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80469178: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x8046917C: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x80469180: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80469184: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80469188: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x8046918C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80469190: beq         $t3, $zero, L_80469234
    if (ctx->r11 == 0) {
        // 0x80469194: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80469234;
    }
    // 0x80469194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80469198: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8046919C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x804691A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x804691A4: jal         0x80049018
    // 0x804691A8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x804691A8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x804691AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x804691B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x804691B4: beq         $v0, $zero, L_804691D8
    if (ctx->r2 == 0) {
        // 0x804691B8: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_804691D8;
    }
    // 0x804691B8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804691BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804691C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804691C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804691C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804691CC: nop

    // 0x804691D0: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804691D4: nop

L_804691D8:
    // 0x804691D8: lw          $t4, 0x1F4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1F4);
    // 0x804691DC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x804691E0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x804691E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x804691E8: beq         $t6, $zero, L_80469200
    if (ctx->r14 == 0) {
        // 0x804691EC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80469200;
    }
    // 0x804691EC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804691F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804691F4: nop

    // 0x804691F8: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804691FC: nop

L_80469200:
    // 0x80469200: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80469204: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80469208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8046920C: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80469210: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80469214: nop

    // 0x80469218: bc1fl       L_80469320
    if (!c1cs) {
        // 0x8046921C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80469320;
    }
    goto skip_0;
    // 0x8046921C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80469220: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80469224: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80469228: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8046922C: b           L_8046931C
    // 0x80469230: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
        goto L_8046931C;
    // 0x80469230: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
L_80469234:
    // 0x80469234: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80469238: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8046923C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80469240: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80469244: beql        $t8, $zero, L_804692D4
    if (ctx->r24 == 0) {
        // 0x80469248: lh          $t2, 0x2($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X2);
            goto L_804692D4;
    }
    goto skip_1;
    // 0x80469248: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x8046924C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80469250: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80469254: lw          $t0, 0x7EA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7EA8);
    // 0x80469258: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8046925C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE68) << 16);
    // 0x80469260: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80469264: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80469268: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8046926C: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80469270: lwc1        $f8, 0x70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X70);
    // 0x80469274: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80469278: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8046927C: nop

    // 0x80469280: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80469284: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80469288: lwc1        $f16, -0x6978($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE68));
    // 0x8046928C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE6C) << 16);
    // 0x80469290: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80469294: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80469298: lb          $t1, 0x2($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2);
    // 0x8046929C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x804692A0: nop

    // 0x804692A4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804692A8: lwc1        $f10, -0x6974($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE6C));
    // 0x804692AC: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804692B0: nop

    // 0x804692B4: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x804692B8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x804692BC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804692C0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x804692C4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x804692C8: b           L_8046931C
    // 0x804692CC: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
        goto L_8046931C;
    // 0x804692CC: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x804692D0: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
L_804692D4:
    // 0x804692D4: lwc1        $f6, 0x70($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X70);
    // 0x804692D8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE70) << 16);
    // 0x804692DC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x804692E0: lwc1        $f8, -0x6970($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE70));
    // 0x804692E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804692E8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804692EC: lwc1        $f4, 0xD0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XD0);
    // 0x804692F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804692F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804692F8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x804692FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80469300: mul.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80469304: nop

    // 0x80469308: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8046930C: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80469310: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80469314: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80469318: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
L_8046931C:
    // 0x8046931C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80469320:
    // 0x80469320: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80469324: jr          $ra
    // 0x80469328: nop

    return;
    // 0x80469328: nop

;}
RECOMP_FUNC void func_8005B21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B21C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8005B220: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8005B224: jr          $ra
    // 0x8005B228: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
    return;
    // 0x8005B228: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
;}
RECOMP_FUNC void func_80453848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045384C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453850: jal         0x80453784
    // 0x80453854: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80453784(rdram, ctx);
        goto after_0;
    // 0x80453854: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80453858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045385C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453860: jr          $ra
    // 0x80453864: nop

    return;
    // 0x80453864: nop

;}
RECOMP_FUNC void func_8040B280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B280: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B284: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8040B288: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040B28C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8040B290: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040B294: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(14, 0X608) << 16);
    // 0x8040B298: beq         $t6, $zero, L_8040B2B0
    if (ctx->r14 == 0) {
        // 0x8040B29C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8040B2B0;
    }
    // 0x8040B29C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8040B2A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040B2A4: nop

    // 0x8040B2A8: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8040B2AC: nop

L_8040B2B0:
    // 0x8040B2B0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8040B2B4: addiu       $t9, $t9, -0x4E98
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(14, 0X608));
    // 0x8040B2B8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8040B2BC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8040B2C0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8040B2C4: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8040B2C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8040B2CC: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8040B2D0: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8040B2D4: lbu         $v1, 0x30($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X30);
    // 0x8040B2D8: beq         $t8, $v1, L_8040B2E8
    if (ctx->r24 == ctx->r3) {
        // 0x8040B2DC: nop
    
            goto L_8040B2E8;
    }
    // 0x8040B2DC: nop

    // 0x8040B2E0: sb          $v1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r3;
    // 0x8040B2E4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
L_8040B2E8:
    // 0x8040B2E8: jr          $ra
    // 0x8040B2EC: nop

    return;
    // 0x8040B2EC: nop

;}
RECOMP_FUNC void func_806CE8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CE8D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CE8D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806CE8DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806CE8E0: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806CE8E4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806CE8E8: bnel        $t6, $zero, L_806CE92C
    if (ctx->r14 != 0) {
        // 0x806CE8EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806CE92C;
    }
    goto skip_0;
    // 0x806CE8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806CE8F0: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x806CE8F4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806CE8F8: bne         $t7, $at, L_806CE928
    if (ctx->r15 != ctx->r1) {
        // 0x806CE8FC: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_806CE928;
    }
    // 0x806CE8FC: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806CE900: bne         $v0, $at, L_806CE924
    if (ctx->r2 != ctx->r1) {
        // 0x806CE904: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_806CE924;
    }
    // 0x806CE904: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806CE908: jal         0x806CE828
    // 0x806CE90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806CE828(rdram, ctx);
        goto after_0;
    // 0x806CE90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806CE910: beq         $v0, $zero, L_806CE928
    if (ctx->r2 == 0) {
        // 0x806CE914: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806CE928;
    }
    // 0x806CE914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CE918: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806CE91C: b           L_806CE928
    // 0x806CE920: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
        goto L_806CE928;
    // 0x806CE920: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_806CE924:
    // 0x806CE924: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
L_806CE928:
    // 0x806CE928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806CE92C:
    // 0x806CE92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CE930: jr          $ra
    // 0x806CE934: nop

    return;
    // 0x806CE934: nop

;}
RECOMP_FUNC void func_80452744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045274C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80452750: jal         0x804525A8
    // 0x80452754: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x80452754: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80452758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045275C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452760: jr          $ra
    // 0x80452764: nop

    return;
    // 0x80452764: nop

;}
RECOMP_FUNC void func_80038188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003818C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038190: jal         0x80021958
    // 0x80038194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038198: bne         $v0, $zero, L_800381A8
    if (ctx->r2 != 0) {
        // 0x8003819C: nop
    
            goto L_800381A8;
    }
    // 0x8003819C: nop

    // 0x800381A0: b           L_800381DC
    // 0x800381A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800381DC;
    // 0x800381A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800381A8:
    // 0x800381A8: jal         0x800415FC
    // 0x800381AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800381AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800381B0: beq         $v0, $zero, L_800381C0
    if (ctx->r2 == 0) {
        // 0x800381B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800381C0;
    }
    // 0x800381B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800381B8: b           L_800381DC
    // 0x800381BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800381DC;
    // 0x800381BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800381C0:
    // 0x800381C0: jal         0x800376A4
    // 0x800381C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x800381C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x800381C8: bnel        $v0, $zero, L_800381DC
    if (ctx->r2 != 0) {
        // 0x800381CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800381DC;
    }
    goto skip_0;
    // 0x800381CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800381D0: b           L_800381DC
    // 0x800381D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800381DC;
    // 0x800381D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800381D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800381DC:
    // 0x800381DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800381E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800381E4: jr          $ra
    // 0x800381E8: nop

    return;
    // 0x800381E8: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_806995B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806995B8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x806995BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806995C0: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x806995C4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806995C8: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0XDB8) << 16);
    // 0x806995CC: addiu       $t8, $t8, -0x5D78
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(562, 0XDB8));
    // 0x806995D0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x806995D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x806995D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806995DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806995E0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x806995E4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x806995E8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x806995EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806995F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806995F4: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x806995F8: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x806995FC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80699600: jal         0x8004921C
    // 0x80699604: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80699604: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    after_0:
    // 0x80699608: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8069960C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80699610: jal         0x8004921C
    // 0x80699614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80699614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80699618: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8069961C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80699620: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80699624: lw          $v1, 0x168($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X168);
    // 0x80699628: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8069962C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80699630: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x80699634: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x80699638: lw          $t9, 0x88($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X88);
    // 0x8069963C: jal         0x80077338
    // 0x80699640: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x80699640: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    after_2:
    // 0x80699644: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80699648: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8069964C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80699650: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80699654: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80699658: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8069965C: ori         $t9, $t9, 0xACB0
    ctx->r25 = ctx->r25 | 0XACB0;
    // 0x80699660: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x80699664: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80699668: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8069966C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80699670: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80699674: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x80699678: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8069967C: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80699680: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x80699684: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80699688: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8069968C: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x80699690: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80699694: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80699698: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8069969C: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806996A0: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x806996A4: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x806996A8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806996AC: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x806996B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806996B4: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x806996B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806996BC: jal         0x8007711C
    // 0x806996C0: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x806996C0: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    after_3:
    // 0x806996C4: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x806996C8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x806996CC: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(562, 0XCEC) << 16);
    // 0x806996D0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x806996D4: addiu       $v0, $v0, -0x5E44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(562, 0XCEC));
    // 0x806996D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806996DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806996E0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x806996E4: addiu       $a0, $t0, 0x18
    ctx->r4 = ADD32(ctx->r8, 0X18);
L_806996E8:
    // 0x806996E8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806996EC: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x806996F0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x806996F4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x806996F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806996FC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80699700: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80699704: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80699708: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8069970C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80699710: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80699714: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80699718: nop

    // 0x8069971C: sh          $t6, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r14;
    // 0x80699720: lwc1        $f6, -0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0XC);
    // 0x80699724: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80699728: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8069972C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80699730: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80699734: nop

    // 0x80699738: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8069973C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80699740: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80699744: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80699748: nop

    // 0x8069974C: sh          $t9, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r25;
    // 0x80699750: lwc1        $f10, -0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X10);
    // 0x80699754: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80699758: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8069975C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80699760: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80699764: nop

    // 0x80699768: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8069976C: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80699770: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80699774: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80699778: nop

    // 0x8069977C: sh          $t8, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r24;
    // 0x80699780: lwc1        $f8, -0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0XC);
    // 0x80699784: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80699788: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8069978C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80699790: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80699794: nop

    // 0x80699798: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069979C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806997A0: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806997A4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x806997A8: nop

    // 0x806997AC: sh          $t7, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r15;
    // 0x806997B0: lwc1        $f18, -0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X8);
    // 0x806997B4: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x806997B8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x806997BC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x806997C0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x806997C4: nop

    // 0x806997C8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806997CC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x806997D0: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806997D4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x806997D8: nop

    // 0x806997DC: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x806997E0: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x806997E4: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x806997E8: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x806997EC: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x806997F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806997F4: nop

    // 0x806997F8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806997FC: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80699800: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80699804: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80699808: nop

    // 0x8069980C: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80699810: lwc1        $f6, -0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80699814: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80699818: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8069981C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80699820: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80699824: nop

    // 0x80699828: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8069982C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80699830: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80699834: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80699838: nop

    // 0x8069983C: sh          $t8, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r24;
    // 0x80699840: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80699844: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80699848: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8069984C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80699850: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80699854: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80699858: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8069985C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80699860: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80699864: bne         $a1, $a2, L_806996E8
    if (ctx->r5 != ctx->r6) {
        // 0x80699868: sh          $t7, 0x42($v1)
        MEM_H(0X42, ctx->r3) = ctx->r15;
            goto L_806996E8;
    }
    // 0x80699868: sh          $t7, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r15;
    // 0x8069986C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80699870: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80699874: ori         $t6, $t6, 0x207F
    ctx->r14 = ctx->r14 | 0X207F;
    // 0x80699878: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8069987C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x80699880: addiu       $t7, $a3, 0x10
    ctx->r15 = ADD32(ctx->r7, 0X10);
    // 0x80699884: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80699888: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8069988C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80699890: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80699894: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80699898: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8069989C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x806998A0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806998A4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x806998A8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x806998AC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x806998B0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x806998B4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x806998B8: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x806998BC: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x806998C0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806998C4: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x806998C8: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x806998CC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806998D0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x806998D4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x806998D8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x806998DC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806998E0: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x806998E4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806998E8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806998EC: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x806998F0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x806998F4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x806998F8: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806998FC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80699900: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80699904: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80699908: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8069990C: mflo        $v0
    ctx->r2 = lo;
    // 0x80699910: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80699914: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80699918: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8069991C: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80699920: beq         $at, $zero, L_80699930
    if (ctx->r1 == 0) {
        // 0x80699924: nop
    
            goto L_80699930;
    }
    // 0x80699924: nop

    // 0x80699928: b           L_80699930
    // 0x8069992C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80699930;
    // 0x8069992C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80699930:
    // 0x80699930: bgez        $t0, L_80699940
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80699934: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_80699940;
    }
    // 0x80699934: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80699938: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8069993C: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80699940:
    // 0x80699940: bgtz        $v0, L_80699950
    if (SIGNED(ctx->r2) > 0) {
        // 0x80699944: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80699950;
    }
    // 0x80699944: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80699948: b           L_80699950
    // 0x8069994C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80699950;
    // 0x8069994C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80699950:
    // 0x80699950: bgtz        $v0, L_80699960
    if (SIGNED(ctx->r2) > 0) {
        // 0x80699954: addiu       $t9, $t1, 0x7FF
        ctx->r25 = ADD32(ctx->r9, 0X7FF);
            goto L_80699960;
    }
    // 0x80699954: addiu       $t9, $t1, 0x7FF
    ctx->r25 = ADD32(ctx->r9, 0X7FF);
    // 0x80699958: b           L_80699964
    // 0x8069995C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80699964;
    // 0x8069995C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80699960:
    // 0x80699960: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80699964:
    // 0x80699964: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x80699968: mflo        $t6
    ctx->r14 = lo;
    // 0x8069996C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80699970: bne         $a1, $zero, L_8069997C
    if (ctx->r5 != 0) {
        // 0x80699974: nop
    
            goto L_8069997C;
    }
    // 0x80699974: nop

    // 0x80699978: break       7
    do_break(2154404216);
L_8069997C:
    // 0x8069997C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80699980: bne         $a1, $at, L_80699994
    if (ctx->r5 != ctx->r1) {
        // 0x80699984: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80699994;
    }
    // 0x80699984: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80699988: bne         $t9, $at, L_80699994
    if (ctx->r25 != ctx->r1) {
        // 0x8069998C: nop
    
            goto L_80699994;
    }
    // 0x8069998C: nop

    // 0x80699990: break       6
    do_break(2154404240);
L_80699994:
    // 0x80699994: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x80699998: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8069999C: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x806999A0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x806999A4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x806999A8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x806999AC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x806999B0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x806999B4: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x806999B8: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x806999BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x806999C0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x806999C4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x806999C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x806999CC: addiu       $t8, $t0, 0x7
    ctx->r24 = ADD32(ctx->r8, 0X7);
    // 0x806999D0: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x806999D4: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x806999D8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x806999DC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x806999E0: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x806999E4: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x806999E8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x806999EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x806999F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x806999F4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x806999F8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x806999FC: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x80699A00: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80699A04: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80699A08: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80699A0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80699A10: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80699A14: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80699A18: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80699A1C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80699A20: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80699A24: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80699A28: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80699A2C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80699A30: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80699A34: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0XD90) << 16);
    // 0x80699A38: addiu       $t8, $t8, -0x5DA0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(562, 0XD90));
    // 0x80699A3C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80699A40: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x80699A44: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80699A48: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80699A4C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80699A50: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80699A54: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80699A58: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80699A5C: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
    // 0x80699A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699A64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80699A68: jr          $ra
    // 0x80699A6C: nop

    return;
    // 0x80699A6C: nop

;}
RECOMP_FUNC void func_80741E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741E44: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80741E48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80741E4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80741E50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80741E54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80741E58: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80741E5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80741E60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80741E64: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80741E68: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(751, 0X1158) << 16);
    // 0x80741E6C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80741E70: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80741E74: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80741E78: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80741E7C: lw          $t1, 0x1FB8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(751, 0X1158));
    // 0x80741E80: jr          $ra
    // 0x80741E84: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80741E84: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80741E88: nop

    // 0x80741E8C: nop

;}
RECOMP_FUNC void func_8066A658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A658: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8066A65C: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(511, 0X734) << 16);
    // 0x8066A660: addiu       $t6, $t6, -0x5B4C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(511, 0X734));
    // 0x8066A664: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8066A668: jr          $ra
    // 0x8066A66C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8066A66C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8043D900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D900: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0X874) << 16);
    // 0x8043D904: addiu       $t6, $t6, -0x274C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(92, 0X874));
    // 0x8043D908: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8043D90C: jr          $ra
    // 0x8043D910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043D910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8067BAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BB00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067BB04: jal         0x80062684
    // 0x8067BB08: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x8067BB08: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x8067BB0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067BB10: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8067BB14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8067BB18: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8067BB1C: bne         $at, $zero, L_8067BB44
    if (ctx->r1 != 0) {
        // 0x8067BB20: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8067BB44;
    }
    // 0x8067BB20: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8067BB24: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8067BB28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8067BB2C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8067BB30: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8067BB34: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x8067BB38: mfhi        $t1
    ctx->r9 = hi;
    // 0x8067BB3C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x8067BB40: nop

L_8067BB44:
    // 0x8067BB44: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067BB48: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D84) << 16);
    // 0x8067BB4C: lwc1        $f4, -0x25CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D84));
    // 0x8067BB50: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8067BB54: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D88) << 16);
    // 0x8067BB58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8067BB5C: nop

    // 0x8067BB60: bc1t        L_8067BB7C
    if (c1cs) {
        // 0x8067BB64: nop
    
            goto L_8067BB7C;
    }
    // 0x8067BB64: nop

    // 0x8067BB68: lwc1        $f6, -0x25C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D88));
    // 0x8067BB6C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8067BB70: nop

    // 0x8067BB74: bc1fl       L_8067BB88
    if (!c1cs) {
        // 0x8067BB78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067BB88;
    }
    goto skip_0;
    // 0x8067BB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8067BB7C:
    // 0x8067BB7C: jal         0x80679D20
    // 0x8067BB80: nop

    func_80679D20(rdram, ctx);
        goto after_1;
    // 0x8067BB80: nop

    after_1:
    // 0x8067BB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067BB88:
    // 0x8067BB88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BB8C: jr          $ra
    // 0x8067BB90: nop

    return;
    // 0x8067BB90: nop

;}
RECOMP_FUNC void func_8001E094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E09C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E0A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E0A4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8001E0A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001E0AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001E0B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001E0B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001E0B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001E0BC: bc1fl       L_8001E124
    if (!c1cs) {
        // 0x8001E0C0: lwc1        $f10, 0x4($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
            goto L_8001E124;
    }
    goto skip_0;
    // 0x8001E0C0: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    skip_0:
    // 0x8001E0C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001E0C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001E0CC: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8001E0D0: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E0D4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001E0D8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8001E0DC: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x8001E0E0: nop

    // 0x8001E0E4: bc1fl       L_8001E1B4
    if (!c1cs) {
        // 0x8001E0E8: lbu         $t4, 0x18($s1)
        ctx->r12 = MEM_BU(ctx->r17, 0X18);
            goto L_8001E1B4;
    }
    goto skip_1;
    // 0x8001E0E8: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    skip_1:
    // 0x8001E0EC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8001E0F0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001E0F4: lhu         $t8, 0x16($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X16);
    // 0x8001E0F8: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x8001E0FC: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001E100: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001E104: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001E108: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8001E10C: lw          $t9, -0x6710($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6710);
    // 0x8001E110: jalr        $t9
    // 0x8001E114: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001E114: nop

    after_0:
    // 0x8001E118: b           L_8001E1B4
    // 0x8001E11C: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
        goto L_8001E1B4;
    // 0x8001E11C: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    // 0x8001E120: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
L_8001E124:
    // 0x8001E124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001E128: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E12C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001E130: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8001E134: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8001E138: nop

    // 0x8001E13C: bc1fl       L_8001E180
    if (!c1cs) {
        // 0x8001E140: lw          $t7, 0x174($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X174);
            goto L_8001E180;
    }
    goto skip_2;
    // 0x8001E140: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    skip_2:
    // 0x8001E144: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x8001E148: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001E14C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E150: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001E154: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001E158: lhu         $t4, 0x16($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X16);
    // 0x8001E15C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8001E160: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001E164: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8001E168: lw          $t9, -0x66F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X66F0);
    // 0x8001E16C: jalr        $t9
    // 0x8001E170: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8001E170: nop

    after_1:
    // 0x8001E174: b           L_8001E1B4
    // 0x8001E178: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
        goto L_8001E1B4;
    // 0x8001E178: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    // 0x8001E17C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
L_8001E180:
    // 0x8001E180: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001E184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001E188: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001E18C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001E190: lhu         $t0, 0x16($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X16);
    // 0x8001E194: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x8001E198: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8001E19C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001E1A0: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8001E1A4: lw          $t9, -0x6710($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6710);
    // 0x8001E1A8: jalr        $t9
    // 0x8001E1AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8001E1AC: nop

    after_2:
    // 0x8001E1B0: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
L_8001E1B4:
    // 0x8001E1B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001E1B8: bnel        $t4, $at, L_8001E1FC
    if (ctx->r12 != ctx->r1) {
        // 0x8001E1BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E1FC;
    }
    goto skip_3;
    // 0x8001E1BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8001E1C0: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    // 0x8001E1C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8001E1C8: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8001E1CC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8001E1D0: beq         $v0, $at, L_8001E1F0
    if (ctx->r2 == ctx->r1) {
        // 0x8001E1D4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8001E1F0;
    }
    // 0x8001E1D4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8001E1D8: beq         $v0, $at, L_8001E1F0
    if (ctx->r2 == ctx->r1) {
        // 0x8001E1DC: nop
    
            goto L_8001E1F0;
    }
    // 0x8001E1DC: nop

    // 0x8001E1E0: beq         $v0, $zero, L_8001E1F0
    if (ctx->r2 == 0) {
        // 0x8001E1E4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8001E1F0;
    }
    // 0x8001E1E4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8001E1E8: bnel        $v0, $at, L_8001E1FC
    if (ctx->r2 != ctx->r1) {
        // 0x8001E1EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E1FC;
    }
    goto skip_4;
    // 0x8001E1EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8001E1F0:
    // 0x8001E1F0: jal         0x8002FB90
    // 0x8001E1F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002FB90(rdram, ctx);
        goto after_3;
    // 0x8001E1F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8001E1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E1FC:
    // 0x8001E1FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001E200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001E204: jr          $ra
    // 0x8001E208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001E208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80527A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527A18: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80527A1C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80527A20: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80527A24: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80527A28: jal         0x80067BBC
    // 0x80527A2C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80527A2C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80527A30: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    // 0x80527A34: jal         0x80067818
    // 0x80527A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80527A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527A3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527A40: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6194) << 16);
    // 0x80527A44: lwc1        $f4, -0x3F6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6194));
    // 0x80527A48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527A4C: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X591C) << 16);
    // 0x80527A50: addiu       $v0, $v0, -0x47E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X591C));
    // 0x80527A54: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X1B90) << 16);
    // 0x80527A58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80527A5C: addiu       $t7, $t7, 0x7A90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X1B90));
    // 0x80527A60: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527A64: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80527A68: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527A6C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80527A70: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527A74: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527A78: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527A7C: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527A88: jr          $ra
    // 0x80527A8C: nop

    return;
    // 0x80527A8C: nop

;}
RECOMP_FUNC void func_8040EFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EFA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EFB0: jal         0x8040EDB0
    // 0x8040EFB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EDB0(rdram, ctx);
        goto after_0;
    // 0x8040EFB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EFB8: jal         0x8040EB60
    // 0x8040EFBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040EB60(rdram, ctx);
        goto after_1;
    // 0x8040EFBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040EFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EFC8: jr          $ra
    // 0x8040EFCC: nop

    return;
    // 0x8040EFCC: nop

;}
RECOMP_FUNC void func_807933FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807933FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80793400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80793404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80793408: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8079340C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80793410: sb          $t6, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r14;
    // 0x80793414: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80793418: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x8079341C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80793420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80793424: jalr        $t9
    // 0x80793428: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80793428: nop

    after_0:
    // 0x8079342C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80793430: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80793434: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80793438: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8079343C: lwc1        $f6, 0x84($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X84);
    // 0x80793440: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80793444: nop

    // 0x80793448: bc1fl       L_80793468
    if (!c1cs) {
        // 0x8079344C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80793468;
    }
    goto skip_0;
    // 0x8079344C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80793450: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80793454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80793458: addiu       $v0, $a2, 0xC4
    ctx->r2 = ADD32(ctx->r6, 0XC4);
    // 0x8079345C: b           L_80793470
    // 0x80793460: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_80793470;
    // 0x80793460: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80793464: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80793468:
    // 0x80793468: addiu       $v0, $a2, 0xC4
    ctx->r2 = ADD32(ctx->r6, 0XC4);
    // 0x8079346C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_80793470:
    // 0x80793470: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80793474: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80793478: nop

    // 0x8079347C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80793480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80793484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80793488: jr          $ra
    // 0x8079348C: nop

    return;
    // 0x8079348C: nop

;}
RECOMP_FUNC void func_807B1A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B1A50: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x807B1A54: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x807B1A58: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x807B1A5C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x807B1A60: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x807B1A64: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x807B1A68: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x807B1A6C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x807B1A70: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x807B1A74: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x807B1A78: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x807B1A7C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x807B1A80: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x807B1A84: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x807B1A88: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x807B1A8C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x807B1A90: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x807B1A94: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B1A98: addiu       $s3, $sp, 0x134
    ctx->r19 = ADD32(ctx->r29, 0X134);
    // 0x807B1A9C: addiu       $s1, $sp, 0xF4
    ctx->r17 = ADD32(ctx->r29, 0XF4);
    // 0x807B1AA0: addiu       $s5, $s0, 0x6C
    ctx->r21 = ADD32(ctx->r16, 0X6C);
    // 0x807B1AA4: sw          $s5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r21;
    // 0x807B1AA8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x807B1AAC: addiu       $s6, $s0, 0x4
    ctx->r22 = ADD32(ctx->r16, 0X4);
    // 0x807B1AB0: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x807B1AB4: sw          $t7, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r15;
    // 0x807B1AB8: lw          $s7, 0x0($t7)
    ctx->r23 = MEM_W(ctx->r15, 0X0);
    // 0x807B1ABC: sw          $s6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r22;
    // 0x807B1AC0: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x807B1AC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B1AC8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x807B1ACC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807B1AD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1AD4: swc1        $f4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->f4.u32l;
    // 0x807B1AD8: lwc1        $f2, 0x154($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X154);
    // 0x807B1ADC: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x807B1AE0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B1AE4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807B1AE8: swc1        $f10, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f10.u32l;
L_807B1AEC:
    // 0x807B1AEC: lwc1        $f24, 0x0($s5)
    ctx->f24.u32l = MEM_W(ctx->r21, 0X0);
    // 0x807B1AF0: lwc1        $f4, 0x158($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B1AF4: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x807B1AF8: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x807B1AFC: nop

    // 0x807B1B00: bc1fl       L_807B1ED8
    if (!c1cs) {
        // 0x807B1B04: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_807B1ED8;
    }
    goto skip_0;
    // 0x807B1B04: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    skip_0:
    // 0x807B1B08: lwc1        $f26, 0x4($s5)
    ctx->f26.u32l = MEM_W(ctx->r21, 0X4);
    // 0x807B1B0C: lwc1        $f8, 0x15C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B1B10: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x807B1B14: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x807B1B18: nop

    // 0x807B1B1C: bc1fl       L_807B1ED8
    if (!c1cs) {
        // 0x807B1B20: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_807B1ED8;
    }
    goto skip_1;
    // 0x807B1B20: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    skip_1:
    // 0x807B1B24: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
    // 0x807B1B28: lh          $t1, 0x2($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X2);
    // 0x807B1B2C: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1B30: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x807B1B34: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x807B1B38: lwc1        $f22, 0x130($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X130);
    // 0x807B1B3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B1B40: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B1B44: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x807B1B48: sub.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x807B1B4C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B1B50: sub.s       $f20, $f24, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f16.fl;
    // 0x807B1B54: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x807B1B58: sub.s       $f30, $f26, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f26.fl - ctx->f22.fl;
    // 0x807B1B5C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x807B1B60: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x807B1B64: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B1B68: jal         0x80081E8C
    // 0x807B1B6C: sqrt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = sqrtf(ctx->f0.fl);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x807B1B6C: sqrt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x807B1B70: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3968) << 16);
    // 0x807B1B74: lwc1        $f8, 0x34B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3968));
    // 0x807B1B78: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x807B1B7C: jal         0x80066E88
    // 0x807B1B80: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807B1B80: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    after_1:
    // 0x807B1B84: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x807B1B88: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1B8C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x807B1B90: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x807B1B94: jal         0x80066DE4
    // 0x807B1B98: swc1        $f6, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807B1B98: swc1        $f6, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x807B1B9C: mul.s       $f8, $f0, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x807B1BA0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X396C) << 16);
    // 0x807B1BA4: lwc1        $f4, 0x34BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X396C));
    // 0x807B1BA8: lwc1        $f22, 0x130($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X130);
    // 0x807B1BAC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3970) << 16);
    // 0x807B1BB0: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x807B1BB4: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x807B1BB8: bc1t        L_807B1CFC
    if (c1cs) {
        // 0x807B1BBC: swc1        $f10, 0x1B0($sp)
        MEM_W(0X1B0, ctx->r29) = ctx->f10.u32l;
            goto L_807B1CFC;
    }
    // 0x807B1BBC: swc1        $f10, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->f10.u32l;
    // 0x807B1BC0: lwc1        $f6, 0x34C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3970));
    // 0x807B1BC4: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x807B1BC8: nop

    // 0x807B1BCC: bc1tl       L_807B1D00
    if (c1cs) {
        // 0x807B1BD0: div.s       $f24, $f30, $f20
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
            goto L_807B1D00;
    }
    goto skip_2;
    // 0x807B1BD0: div.s       $f24, $f30, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
    skip_2:
    // 0x807B1BD4: lwc1        $f0, 0x158($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B1BD8: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x807B1BDC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3974) << 16);
    // 0x807B1BE0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807B1BE4: lwc1        $f4, 0x34C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3974));
    // 0x807B1BE8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3978) << 16);
    // 0x807B1BEC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807B1BF0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x807B1BF4: nop

    // 0x807B1BF8: bc1tl       L_807B1CF4
    if (c1cs) {
        // 0x807B1BFC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_807B1CF4;
    }
    goto skip_3;
    // 0x807B1BFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x807B1C00: lwc1        $f6, 0x34C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3978));
    // 0x807B1C04: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X397C) << 16);
    // 0x807B1C08: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x807B1C0C: nop

    // 0x807B1C10: bc1tl       L_807B1C3C
    if (c1cs) {
        // 0x807B1C14: sqrt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
            goto L_807B1C3C;
    }
    goto skip_4;
    // 0x807B1C14: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    skip_4:
    // 0x807B1C18: lwc1        $f8, 0x34CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X397C));
    // 0x807B1C1C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x807B1C20: nop

    // 0x807B1C24: bc1tl       L_807B1C3C
    if (c1cs) {
        // 0x807B1C28: sqrt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
            goto L_807B1C3C;
    }
    goto skip_5;
    // 0x807B1C28: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    skip_5:
    // 0x807B1C2C: lwc1        $f10, 0x15C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B1C30: b           L_807B1C70
    // 0x807B1C34: add.s       $f30, $f22, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f10.fl;
        goto L_807B1C70;
    // 0x807B1C34: add.s       $f30, $f22, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x807B1C38: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
L_807B1C3C:
    // 0x807B1C3C: lwc1        $f2, 0x15C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B1C40: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807B1C44: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x807B1C48: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1C4C: nop

    // 0x807B1C50: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x807B1C54: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807B1C58: nop

    // 0x807B1C5C: bc1f        L_807B1C6C
    if (!c1cs) {
        // 0x807B1C60: nop
    
            goto L_807B1C6C;
    }
    // 0x807B1C60: nop

    // 0x807B1C64: b           L_807B1C70
    // 0x807B1C68: add.s       $f30, $f22, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f16.fl;
        goto L_807B1C70;
    // 0x807B1C68: add.s       $f30, $f22, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f16.fl;
L_807B1C6C:
    // 0x807B1C6C: add.s       $f30, $f22, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f14.fl;
L_807B1C70:
    // 0x807B1C70: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1C74: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x807B1C78: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B1C7C: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x807B1C80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1C84: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x807B1C88: nop

    // 0x807B1C8C: sh          $t3, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r11;
    // 0x807B1C90: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1C94: bne         $at, $zero, L_807B1CC8
    if (ctx->r1 != 0) {
        // 0x807B1C98: swc1        $f10, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f10.u32l;
            goto L_807B1CC8;
    }
    // 0x807B1C98: swc1        $f10, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f10.u32l;
    // 0x807B1C9C: slti        $at, $s2, 0xD
    ctx->r1 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x807B1CA0: beq         $at, $zero, L_807B1CC8
    if (ctx->r1 == 0) {
        // 0x807B1CA4: lwc1        $f4, 0x1B0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1B0);
            goto L_807B1CC8;
    }
    // 0x807B1CA4: lwc1        $f4, 0x1B0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1CA8: c.lt.s      $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f4.fl < ctx->f30.fl;
    // 0x807B1CAC: nop

    // 0x807B1CB0: bc1f        L_807B1CC0
    if (!c1cs) {
        // 0x807B1CB4: nop
    
            goto L_807B1CC0;
    }
    // 0x807B1CB4: nop

    // 0x807B1CB8: b           L_807B1CE8
    // 0x807B1CBC: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_807B1CE8;
    // 0x807B1CBC: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_807B1CC0:
    // 0x807B1CC0: b           L_807B1CE8
    // 0x807B1CC4: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
        goto L_807B1CE8;
    // 0x807B1CC4: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1CC8:
    // 0x807B1CC8: lwc1        $f6, 0x1B0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1CCC: c.lt.s      $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f30.fl < ctx->f6.fl;
    // 0x807B1CD0: nop

    // 0x807B1CD4: bc1fl       L_807B1CE8
    if (!c1cs) {
        // 0x807B1CD8: swc1        $f30, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
            goto L_807B1CE8;
    }
    goto skip_6;
    // 0x807B1CD8: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
    skip_6:
    // 0x807B1CDC: b           L_807B1CE8
    // 0x807B1CE0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_807B1CE8;
    // 0x807B1CE0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x807B1CE4: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1CE8:
    // 0x807B1CE8: b           L_807B1ED8
    // 0x807B1CEC: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
        goto L_807B1ED8;
    // 0x807B1CEC: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
    // 0x807B1CF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_807B1CF4:
    // 0x807B1CF4: b           L_807B1ED8
    // 0x807B1CF8: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
        goto L_807B1ED8;
    // 0x807B1CF8: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_807B1CFC:
    // 0x807B1CFC: div.s       $f24, $f30, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
L_807B1D00:
    // 0x807B1D00: lwc1        $f8, 0x15C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B1D04: lwc1        $f4, 0x158($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B1D08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B1D0C: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x807B1D10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B1D14: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3980) << 16);
    // 0x807B1D18: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x807B1D1C: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x807B1D20: lwc1        $f4, 0x194($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X194);
    // 0x807B1D24: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B1D28: lwc1        $f8, 0x34D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3980));
    // 0x807B1D2C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3984) << 16);
    // 0x807B1D30: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x807B1D34: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1D38: nop

    // 0x807B1D3C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x807B1D40: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x807B1D44: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x807B1D48: nop

    // 0x807B1D4C: bc1t        L_807B1EC4
    if (c1cs) {
        // 0x807B1D50: nop
    
            goto L_807B1EC4;
    }
    // 0x807B1D50: nop

    // 0x807B1D54: lwc1        $f4, 0x34D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3984));
    // 0x807B1D58: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3988) << 16);
    // 0x807B1D5C: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x807B1D60: nop

    // 0x807B1D64: bc1tl       L_807B1DA0
    if (c1cs) {
        // 0x807B1D68: sqrt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
            goto L_807B1DA0;
    }
    goto skip_7;
    // 0x807B1D68: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
    skip_7:
    // 0x807B1D6C: lwc1        $f10, 0x34D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3988));
    // 0x807B1D70: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x807B1D74: nop

    // 0x807B1D78: bc1tl       L_807B1DA0
    if (c1cs) {
        // 0x807B1D7C: sqrt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
            goto L_807B1DA0;
    }
    goto skip_8;
    // 0x807B1D7C: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
    skip_8:
    // 0x807B1D80: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x807B1D84: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1D88: div.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x807B1D8C: mul.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x807B1D90: add.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807B1D94: b           L_807B1E10
    // 0x807B1D98: add.s       $f30, $f22, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f8.fl;
        goto L_807B1E10;
    // 0x807B1D98: add.s       $f30, $f22, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x807B1D9C: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
L_807B1DA0:
    // 0x807B1DA0: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x807B1DA4: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807B1DA8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x807B1DAC: div.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x807B1DB0: div.s       $f20, $f6, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x807B1DB4: mul.s       $f26, $f24, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x807B1DB8: nop

    // 0x807B1DBC: mul.s       $f28, $f24, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x807B1DC0: nop

    // 0x807B1DC4: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x807B1DC8: nop

    // 0x807B1DCC: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x807B1DD0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x807B1DD4: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x807B1DD8: nop

    // 0x807B1DDC: mul.s       $f8, $f28, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x807B1DE0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B1DE4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x807B1DE8: nop

    // 0x807B1DEC: bc1f        L_807B1E04
    if (!c1cs) {
        // 0x807B1DF0: nop
    
            goto L_807B1E04;
    }
    // 0x807B1DF0: nop

    // 0x807B1DF4: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1DF8: add.s       $f30, $f22, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x807B1DFC: b           L_807B1E10
    // 0x807B1E00: add.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f20.fl;
        goto L_807B1E10;
    // 0x807B1E00: add.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f20.fl;
L_807B1E04:
    // 0x807B1E04: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1E08: add.s       $f30, $f22, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x807B1E0C: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
L_807B1E10:
    // 0x807B1E10: blez        $s2, L_807B1E40
    if (SIGNED(ctx->r18) <= 0) {
        // 0x807B1E14: slti        $at, $s2, 0x9
        ctx->r1 = SIGNED(ctx->r18) < 0X9 ? 1 : 0;
            goto L_807B1E40;
    }
    // 0x807B1E14: slti        $at, $s2, 0x9
    ctx->r1 = SIGNED(ctx->r18) < 0X9 ? 1 : 0;
    // 0x807B1E18: beq         $at, $zero, L_807B1E40
    if (ctx->r1 == 0) {
        // 0x807B1E1C: lwc1        $f0, 0x1B4($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
            goto L_807B1E40;
    }
    // 0x807B1E1C: lwc1        $f0, 0x1B4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x807B1E20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807B1E24: nop

    // 0x807B1E28: bc1f        L_807B1E38
    if (!c1cs) {
        // 0x807B1E2C: nop
    
            goto L_807B1E38;
    }
    // 0x807B1E2C: nop

    // 0x807B1E30: b           L_807B1E60
    // 0x807B1E34: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_807B1E60;
    // 0x807B1E34: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_807B1E38:
    // 0x807B1E38: b           L_807B1E60
    // 0x807B1E3C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
        goto L_807B1E60;
    // 0x807B1E3C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
L_807B1E40:
    // 0x807B1E40: lwc1        $f0, 0x1B4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x807B1E44: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807B1E48: nop

    // 0x807B1E4C: bc1fl       L_807B1E60
    if (!c1cs) {
        // 0x807B1E50: swc1        $f2, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
            goto L_807B1E60;
    }
    goto skip_9;
    // 0x807B1E50: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    skip_9:
    // 0x807B1E54: b           L_807B1E60
    // 0x807B1E58: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_807B1E60;
    // 0x807B1E58: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x807B1E5C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
L_807B1E60:
    // 0x807B1E60: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x807B1E64: bne         $at, $zero, L_807B1E9C
    if (ctx->r1 != 0) {
        // 0x807B1E68: lwc1        $f0, 0x1B0($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
            goto L_807B1E9C;
    }
    // 0x807B1E68: lwc1        $f0, 0x1B0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1E6C: slti        $at, $s2, 0xD
    ctx->r1 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x807B1E70: beql        $at, $zero, L_807B1EA0
    if (ctx->r1 == 0) {
        // 0x807B1E74: c.lt.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
            goto L_807B1EA0;
    }
    goto skip_10;
    // 0x807B1E74: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    skip_10:
    // 0x807B1E78: lwc1        $f0, 0x1B0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1E7C: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x807B1E80: nop

    // 0x807B1E84: bc1f        L_807B1E94
    if (!c1cs) {
        // 0x807B1E88: nop
    
            goto L_807B1E94;
    }
    // 0x807B1E88: nop

    // 0x807B1E8C: b           L_807B1EB8
    // 0x807B1E90: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_807B1EB8;
    // 0x807B1E90: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_807B1E94:
    // 0x807B1E94: b           L_807B1EB8
    // 0x807B1E98: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
        goto L_807B1EB8;
    // 0x807B1E98: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1E9C:
    // 0x807B1E9C: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
L_807B1EA0:
    // 0x807B1EA0: nop

    // 0x807B1EA4: bc1fl       L_807B1EB8
    if (!c1cs) {
        // 0x807B1EA8: swc1        $f30, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
            goto L_807B1EB8;
    }
    goto skip_11;
    // 0x807B1EA8: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
    skip_11:
    // 0x807B1EAC: b           L_807B1EB8
    // 0x807B1EB0: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_807B1EB8;
    // 0x807B1EB0: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x807B1EB4: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1EB8:
    // 0x807B1EB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1EBC: b           L_807B1ED8
    // 0x807B1EC0: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
        goto L_807B1ED8;
    // 0x807B1EC0: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
L_807B1EC4:
    // 0x807B1EC4: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x807B1EC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1ECC: b           L_807B1EDC
    // 0x807B1ED0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_807B1EDC;
    // 0x807B1ED0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807B1ED4: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_807B1ED8:
    // 0x807B1ED8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807B1EDC:
    // 0x807B1EDC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x807B1EE0: addiu       $s6, $s6, 0x6
    ctx->r22 = ADD32(ctx->r22, 0X6);
    // 0x807B1EE4: addiu       $s7, $s7, 0x6
    ctx->r23 = ADD32(ctx->r23, 0X6);
    // 0x807B1EE8: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x807B1EEC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807B1EF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B1EF4: bne         $s2, $at, L_807B1AEC
    if (ctx->r18 != ctx->r1) {
        // 0x807B1EF8: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_807B1AEC;
    }
    // 0x807B1EF8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x807B1EFC: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x807B1F00: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x807B1F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B1F08: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x807B1F0C: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    // 0x807B1F10: jal         0x807B11E8
    // 0x807B1F14: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    func_807B11E8(rdram, ctx);
        goto after_3;
    // 0x807B1F14: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_3:
    // 0x807B1F18: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x807B1F1C: addiu       $t6, $sp, 0xF4
    ctx->r14 = ADD32(ctx->r29, 0XF4);
    // 0x807B1F20: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x807B1F24: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x807B1F28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x807B1F2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807B1F30: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x807B1F34: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x807B1F38: jal         0x807B1100
    // 0x807B1F3C: addiu       $a3, $sp, 0x134
    ctx->r7 = ADD32(ctx->r29, 0X134);
    func_807B1100(rdram, ctx);
        goto after_4;
    // 0x807B1F3C: addiu       $a3, $sp, 0x134
    ctx->r7 = ADD32(ctx->r29, 0X134);
    after_4:
    // 0x807B1F40: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x807B1F44: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x807B1F48: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x807B1F4C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x807B1F50: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x807B1F54: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x807B1F58: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x807B1F5C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x807B1F60: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x807B1F64: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x807B1F68: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x807B1F6C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x807B1F70: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x807B1F74: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x807B1F78: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x807B1F7C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x807B1F80: jr          $ra
    // 0x807B1F84: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x807B1F84: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_80432EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432EA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80432EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80432EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80432EAC: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80432EB0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80432EB4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80432EB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80432EBC: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80432EC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80432EC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80432EC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80432ECC: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80432ED0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80432ED4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80432ED8: nop

    // 0x80432EDC: bc1fl       L_80432EEC
    if (!c1cs) {
        // 0x80432EE0: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80432EEC;
    }
    goto skip_0;
    // 0x80432EE0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x80432EE4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80432EE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80432EEC:
    // 0x80432EEC: nop

    // 0x80432EF0: bc1f        L_80432EFC
    if (!c1cs) {
        // 0x80432EF4: nop
    
            goto L_80432EFC;
    }
    // 0x80432EF4: nop

    // 0x80432EF8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80432EFC:
    // 0x80432EFC: jal         0x80065954
    // 0x80432F00: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80432F00: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80432F04: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80432F08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80432F0C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80432F10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80432F14: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80432F18: lui         $at, 0x427E
    ctx->r1 = S32(0X427E << 16);
    // 0x80432F1C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80432F20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80432F24: nop

    // 0x80432F28: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80432F2C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80432F30: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80432F34: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80432F38: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80432F3C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80432F40: nop

    // 0x80432F44: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80432F48: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80432F4C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80432F50: jal         0x80067D5C
    // 0x80432F54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x80432F54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80432F58: jal         0x80067D38
    // 0x80432F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80067D38(rdram, ctx);
        goto after_2;
    // 0x80432F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80432F60: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80432F64: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80432F68: bnel        $t9, $zero, L_80432F84
    if (ctx->r25 != 0) {
        // 0x80432F6C: lh          $a1, 0x1F0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X1F0);
            goto L_80432F84;
    }
    goto skip_1;
    // 0x80432F6C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    skip_1:
    // 0x80432F70: jal         0x80432E48
    // 0x80432F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80432E48(rdram, ctx);
        goto after_3;
    // 0x80432F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80432F78: b           L_80432FB0
    // 0x80432F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80432FB0;
    // 0x80432F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80432F80: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
L_80432F84:
    // 0x80432F84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80432F88: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x80432F8C: bne         $a1, $at, L_80432FA4
    if (ctx->r5 != ctx->r1) {
        // 0x80432F90: nop
    
            goto L_80432FA4;
    }
    // 0x80432F90: nop

    // 0x80432F94: jal         0x80067F78
    // 0x80432F98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80067F78(rdram, ctx);
        goto after_4;
    // 0x80432F98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80432F9C: b           L_80432FAC
    // 0x80432FA0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80432FAC;
    // 0x80432FA0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80432FA4:
    // 0x80432FA4: jal         0x800678F0
    // 0x80432FA8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_800678F0(rdram, ctx);
        goto after_5;
    // 0x80432FA8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_5:
L_80432FAC:
    // 0x80432FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80432FB0:
    // 0x80432FB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80432FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80432FB8: jr          $ra
    // 0x80432FBC: nop

    return;
    // 0x80432FBC: nop

;}
RECOMP_FUNC void func_8066B0E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B0E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066B0E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B0EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B0F0: jal         0x8066B050
    // 0x8066B0F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8066B050(rdram, ctx);
        goto after_0;
    // 0x8066B0F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B0F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066B0FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066B100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8066B104: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x8066B108: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8066B10C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B110: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8066B114: nop

    // 0x8066B118: bc1f        L_8066B138
    if (!c1cs) {
        // 0x8066B11C: nop
    
            goto L_8066B138;
    }
    // 0x8066B11C: nop

    // 0x8066B120: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8066B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B128: jal         0x8066B970
    // 0x8066B12C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B12C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x8066B130: b           L_8066B144
    // 0x8066B134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066B144;
    // 0x8066B134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B138:
    // 0x8066B138: jal         0x8066AD18
    // 0x8066B13C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066AD18(rdram, ctx);
        goto after_2;
    // 0x8066B13C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8066B140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B144:
    // 0x8066B144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066B14C: jr          $ra
    // 0x8066B150: nop

    return;
    // 0x8066B150: nop

;}
RECOMP_FUNC void func_80423044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042304C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80423050: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80423054: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80423058: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X31B4) << 16);
    // 0x8042305C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80423060: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80423064: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80423068: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042306C: lw          $t8, 0x5BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X31B4));
    // 0x80423070: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80423074: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80423078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042307C: jal         0x80048490
    // 0x80423080: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80423080: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80423084: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80423088: jal         0x80048378
    // 0x8042308C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042308C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80423090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423098: jr          $ra
    // 0x8042309C: nop

    return;
    // 0x8042309C: nop

;}
RECOMP_FUNC void func_8006C910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C910: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006C914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006C918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C920: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x8006C924: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x8006C928: jal         0x8006C3C4
    // 0x8006C92C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006C3C4(rdram, ctx);
        goto after_0;
    // 0x8006C92C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C930: jal         0x8006CB3C
    // 0x8006C934: nop

    func_8006CB3C(rdram, ctx);
        goto after_1;
    // 0x8006C934: nop

    after_1:
    // 0x8006C938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C93C: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8006C940: addiu       $t6, $t6, -0x3C10
    ctx->r14 = ADD32(ctx->r14, -0X3C10);
    // 0x8006C944: jal         0x8006C848
    // 0x8006C948: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    func_8006C848(rdram, ctx);
        goto after_2;
    // 0x8006C948: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    after_2:
    // 0x8006C94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C954: jr          $ra
    // 0x8006C958: nop

    return;
    // 0x8006C958: nop

;}
RECOMP_FUNC void func_806EF030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EF034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF03C: jal         0x806EC16C
    // 0x806EF040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EF040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF044: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF048: jal         0x800577D8
    // 0x806EF04C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EF04C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EF050: jal         0x806EE5E4
    // 0x806EF054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_2;
    // 0x806EF054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EF058: jal         0x806EE664
    // 0x806EF05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_3;
    // 0x806EF05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EF060: jal         0x806EE720
    // 0x806EF064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_4;
    // 0x806EF064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF068: jal         0x806EEE1C
    // 0x806EF06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EEE1C(rdram, ctx);
        goto after_5;
    // 0x806EF06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EF070: beq         $v0, $zero, L_806EF0B4
    if (ctx->r2 == 0) {
        // 0x806EF074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EF0B4;
    }
    // 0x806EF074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF07C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EF080: jal         0x806EF4A0
    // 0x806EF084: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_6;
    // 0x806EF084: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EF088: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EF08C: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806EF090: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D50) << 16);
    // 0x806EF094: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x806EF098: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x806EF09C: lwc1        $f4, 0xCA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D50));
    // 0x806EF0A0: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x806EF0A4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x806EF0A8: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806EF0AC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EF0B0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_806EF0B4:
    // 0x806EF0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EF0B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF0BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EF0C0: jr          $ra
    // 0x806EF0C4: nop

    return;
    // 0x806EF0C4: nop

;}
RECOMP_FUNC void func_80682C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682C84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682C88: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682C8C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682C90: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682C94: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682C98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682C9C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682CA0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682CA4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682CA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682CAC: jr          $ra
    // 0x80682CB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682CB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C0110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0110: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(194, 0X10) << 16);
    // 0x804C0114: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(194, 0X10));
    // 0x804C0118: jr          $ra
    // 0x804C011C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804C011C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80780260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780260: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80780264: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80780268: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8078026C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80780270: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80780274: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80780278: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8078027C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80780280: lh          $v1, 0x144($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X144);
    // 0x80780284: lui         $t7, 0x8078
    ctx->r15 = S32(RELOC_HI16(784, 0X1260) << 16);
    // 0x80780288: addiu       $t7, $t7, 0x1450
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(784, 0X1260));
    // 0x8078028C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80780290: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80780294: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x80780298: lh          $s2, 0x184($a0)
    ctx->r18 = MEM_H(ctx->r4, 0X184);
    // 0x8078029C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x807802A0: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807802A4: addiu       $t8, $v0, 0x18
    ctx->r24 = ADD32(ctx->r2, 0X18);
    // 0x807802A8: addiu       $t9, $v0, 0x30
    ctx->r25 = ADD32(ctx->r2, 0X30);
    // 0x807802AC: addiu       $t0, $v0, 0x48
    ctx->r8 = ADD32(ctx->r2, 0X48);
    // 0x807802B0: addiu       $t1, $v0, 0x60
    ctx->r9 = ADD32(ctx->r2, 0X60);
    // 0x807802B4: addiu       $t2, $v0, 0x78
    ctx->r10 = ADD32(ctx->r2, 0X78);
    // 0x807802B8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x807802BC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x807802C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x807802C4: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x807802C8: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x807802CC: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x807802D0: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x807802D4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x807802D8: addiu       $t3, $v0, 0x90
    ctx->r11 = ADD32(ctx->r2, 0X90);
    // 0x807802DC: addiu       $t4, $v0, 0xA8
    ctx->r12 = ADD32(ctx->r2, 0XA8);
    // 0x807802E0: addiu       $t5, $v0, 0xC0
    ctx->r13 = ADD32(ctx->r2, 0XC0);
    // 0x807802E4: addiu       $t6, $v0, 0xD8
    ctx->r14 = ADD32(ctx->r2, 0XD8);
    // 0x807802E8: addiu       $t7, $v0, 0xF0
    ctx->r15 = ADD32(ctx->r2, 0XF0);
    // 0x807802EC: addiu       $t8, $v0, 0x108
    ctx->r24 = ADD32(ctx->r2, 0X108);
    // 0x807802F0: addiu       $t9, $v0, 0x120
    ctx->r25 = ADD32(ctx->r2, 0X120);
    // 0x807802F4: addiu       $t0, $v0, 0x138
    ctx->r8 = ADD32(ctx->r2, 0X138);
    // 0x807802F8: addiu       $t1, $v0, 0x150
    ctx->r9 = ADD32(ctx->r2, 0X150);
    // 0x807802FC: addiu       $t2, $v0, 0x168
    ctx->r10 = ADD32(ctx->r2, 0X168);
    // 0x80780300: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80780304: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80780308: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x8078030C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80780310: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80780314: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x80780318: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8078031C: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80780320: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x80780324: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80780328: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x8078032C: blez        $s2, L_80780364
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80780330: sw          $t2, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r10;
            goto L_80780364;
    }
    // 0x80780330: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x80780334: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80780338: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x8078033C: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x80780340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80780344: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
L_80780348:
    // 0x80780348: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078034C: lw          $a0, 0x188($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X188);
    // 0x80780350: jal         0x80780200
    // 0x80780354: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80780200(rdram, ctx);
        goto after_0;
    // 0x80780354: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80780358: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8078035C: bne         $s0, $s3, L_80780348
    if (ctx->r16 != ctx->r19) {
        // 0x80780360: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80780348;
    }
    // 0x80780360: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80780364:
    // 0x80780364: lh          $t5, 0x144($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X144);
    // 0x80780368: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8078036C: sh          $t6, 0x144($s4)
    MEM_H(0X144, ctx->r20) = ctx->r14;
    // 0x80780370: lh          $t7, 0x144($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X144);
    // 0x80780374: slti        $at, $t7, 0x37
    ctx->r1 = SIGNED(ctx->r15) < 0X37 ? 1 : 0;
    // 0x80780378: bnel        $at, $zero, L_80780388
    if (ctx->r1 != 0) {
        // 0x8078037C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80780388;
    }
    goto skip_0;
    // 0x8078037C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80780380: sh          $zero, 0x144($s4)
    MEM_H(0X144, ctx->r20) = 0;
    // 0x80780384: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80780388:
    // 0x80780388: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8078038C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80780390: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80780394: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80780398: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8078039C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x807803A0: jr          $ra
    // 0x807803A4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x807803A4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_806E021C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E021C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E0220: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E0224: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E0228: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806E022C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E0230: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x806E0234: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x806E0238: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x806E023C: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x806E0240: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x806E0244: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x806E0248: jr          $ra
    // 0x806E024C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x806E024C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_807A6514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A651C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807A6520: jal         0x80045A34
    // 0x807A6524: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807A6524: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x807A6528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A652C: bne         $v0, $zero, L_807A653C
    if (ctx->r2 != 0) {
        // 0x807A6530: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807A653C;
    }
    // 0x807A6530: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807A6534: b           L_807A6548
    // 0x807A6538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A6548;
    // 0x807A6538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A653C:
    // 0x807A653C: jal         0x807A64F0
    // 0x807A6540: nop

    func_807A64F0(rdram, ctx);
        goto after_1;
    // 0x807A6540: nop

    after_1:
    // 0x807A6544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807A6548:
    // 0x807A6548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A654C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6550: jr          $ra
    // 0x807A6554: nop

    return;
    // 0x807A6554: nop

;}
RECOMP_FUNC void func_80067508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067508: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x8006750C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80067510: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80067514: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80067518: addiu       $t6, $t6, 0x78B0
    ctx->r14 = ADD32(ctx->r14, 0X78B0);
    // 0x8006751C: addiu       $v0, $v0, -0x5028
    ctx->r2 = ADD32(ctx->r2, -0X5028);
    // 0x80067520: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80067524: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80067528: jr          $ra
    // 0x8006752C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    return;
    // 0x8006752C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_804528C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804528C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804528C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804528CC: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x804528D0: jal         0x804527B0
    // 0x804528D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x804528D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x804528D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804528DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804528E0: jr          $ra
    // 0x804528E4: nop

    return;
    // 0x804528E4: nop

;}
RECOMP_FUNC void func_8002AEE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AEE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AEE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AEEC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002AEF0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8002AEF4: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8002AEF8: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x8002AEFC: jal         0x8005A994
    // 0x8002AF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8005A994(rdram, ctx);
        goto after_0;
    // 0x8002AF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8002AF04: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002AF08: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002AF0C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002AF10: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x8002AF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002AF18: swc1        $f12, 0xB0($t6)
    MEM_W(0XB0, ctx->r14) = ctx->f12.u32l;
    // 0x8002AF1C: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x8002AF20: lwc1        $f4, 0xB0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x8002AF24: jal         0x8006CA74
    // 0x8002AF28: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    func_8006CA74(rdram, ctx);
        goto after_1;
    // 0x8002AF28: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8002AF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AF30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AF34: jr          $ra
    // 0x8002AF38: nop

    return;
    // 0x8002AF38: nop

;}
RECOMP_FUNC void func_80568668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568668: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8056866C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80568670: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80568674: jal         0x8004700C
    // 0x80568678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80568678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8056867C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80568680: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80568684: beq         $v0, $zero, L_805686EC
    if (ctx->r2 == 0) {
        // 0x80568688: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_805686EC;
    }
    // 0x80568688: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8056868C: jal         0x80567DD4
    // 0x80568690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567DD4(rdram, ctx);
        goto after_1;
    // 0x80568690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80568694: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80568698: jal         0x80048F84
    // 0x8056869C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8056869C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805686A0: jal         0x805677F4
    // 0x805686A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805677F4(rdram, ctx);
        goto after_3;
    // 0x805686A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805686A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x805686AC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x805686B0: beql        $t8, $zero, L_805686D0
    if (ctx->r24 == 0) {
        // 0x805686B4: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_805686D0;
    }
    goto skip_0;
    // 0x805686B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x805686B8: jal         0x8002FBFC
    // 0x805686BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002FBFC(rdram, ctx);
        goto after_4;
    // 0x805686BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x805686C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805686C4: jal         0x80569310
    // 0x805686C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80569310(rdram, ctx);
        goto after_5;
    // 0x805686C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_5:
    // 0x805686CC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_805686D0:
    // 0x805686D0: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x805686D4: beql        $t0, $zero, L_805686F0
    if (ctx->r8 == 0) {
        // 0x805686D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805686F0;
    }
    goto skip_1;
    // 0x805686D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805686DC: jal         0x800610A0
    // 0x805686E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800610A0(rdram, ctx);
        goto after_6;
    // 0x805686E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805686E4: jal         0x80044658
    // 0x805686E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_7;
    // 0x805686E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_805686EC:
    // 0x805686EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805686F0:
    // 0x805686F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805686F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805686F8: jr          $ra
    // 0x805686FC: nop

    return;
    // 0x805686FC: nop

;}
RECOMP_FUNC void pad_press_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FC0C: jr          $ra
    // 0x8007FC10: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    return;
    // 0x8007FC10: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
;}
RECOMP_FUNC void func_805A6E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6E6C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x805A6E70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A6E74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A6E78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A6E7C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x805A6E80: lw          $a2, 0x16C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X16C);
    // 0x805A6E84: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x805A6E88: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805A6E8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A6E90: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x805A6E94: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x805A6E98: jal         0x8004921C
    // 0x805A6E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805A6E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x805A6EA0: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x805A6EA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A6EA8: jal         0x8004921C
    // 0x805A6EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805A6EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805A6EB0: lw          $t7, 0x168($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X168);
    // 0x805A6EB4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A6EB8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x805A6EBC: lw          $a3, 0x80($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X80);
    // 0x805A6EC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6EC4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x805A6EC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805A6ECC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805A6ED0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A6ED4: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x805A6ED8: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x805A6EDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6EE0: addiu       $t0, $zero, 0xCF0
    ctx->r8 = ADD32(0, 0XCF0);
    // 0x805A6EE4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x805A6EE8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A6EEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A6EF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6EF4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x805A6EF8: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x805A6EFC: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x805A6F00: ori         $a1, $a1, 0x4340
    ctx->r5 = ctx->r5 | 0X4340;
    // 0x805A6F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6F08: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x805A6F0C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x805A6F10: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x805A6F14: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x805A6F18: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6F1C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x805A6F20: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x805A6F24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A6F28: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x805A6F2C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x805A6F30: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x805A6F34: lbu         $t1, 0x1($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1);
    // 0x805A6F38: lbu         $t5, 0x3($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X3);
    // 0x805A6F3C: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x805A6F40: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x805A6F44: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x805A6F48: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x805A6F4C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x805A6F50: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6F54: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x805A6F58: or          $t5, $t3, $t7
    ctx->r13 = ctx->r11 | ctx->r15;
    // 0x805A6F5C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A6F60: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x805A6F64: lui         $t8, 0xFC11
    ctx->r24 = S32(0XFC11 << 16);
    // 0x805A6F68: ori         $t8, $t8, 0xFE23
    ctx->r24 = ctx->r24 | 0XFE23;
    // 0x805A6F6C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6F70: addiu       $t0, $zero, -0x805
    ctx->r8 = ADD32(0, -0X805);
    // 0x805A6F74: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x805A6F78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805A6F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6F80: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6F84: lui         $t1, 0xBB00
    ctx->r9 = S32(0XBB00 << 16);
    // 0x805A6F88: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x805A6F8C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x805A6F90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A6F94: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x805A6F98: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805A6F9C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6FA0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A6FA4: lui         $t2, 0xFD90
    ctx->r10 = S32(0XFD90 << 16);
    // 0x805A6FA8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x805A6FAC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6FB0: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x805A6FB4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A6FB8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x805A6FBC: lui         $t4, 0xF590
    ctx->r12 = S32(0XF590 << 16);
    // 0x805A6FC0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x805A6FC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A6FC8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6FCC: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x805A6FD0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x805A6FD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x805A6FD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805A6FDC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x805A6FE0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x805A6FE4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x805A6FE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A6FEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A6FF0: jal         0x8004921C
    // 0x805A6FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x805A6FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805A6FF8: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x805A6FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7000: jal         0x8004921C
    // 0x805A7004: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x805A7004: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805A7008: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x805A700C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7010: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A7014: addiu       $t5, $zero, 0x7FF
    ctx->r13 = ADD32(0, 0X7FF);
    // 0x805A7018: mflo        $t8
    ctx->r24 = lo;
    // 0x805A701C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x805A7020: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x805A7024: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x805A7028: slti        $at, $t9, 0x7FF
    ctx->r1 = SIGNED(ctx->r25) < 0X7FF ? 1 : 0;
    // 0x805A702C: beql        $at, $zero, L_805A7070
    if (ctx->r1 == 0) {
        // 0x805A7030: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_805A7070;
    }
    goto skip_0;
    // 0x805A7030: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    skip_0:
    // 0x805A7034: jal         0x8004921C
    // 0x805A7038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x805A7038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805A703C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x805A7040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7044: jal         0x8004921C
    // 0x805A7048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x805A7048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805A704C: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x805A7050: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A7054: mflo        $t4
    ctx->r12 = lo;
    // 0x805A7058: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x805A705C: sra         $t3, $t6, 1
    ctx->r11 = S32(SIGNED(ctx->r14) >> 1);
    // 0x805A7060: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x805A7064: b           L_805A7070
    // 0x805A7068: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
        goto L_805A7070;
    // 0x805A7068: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x805A706C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_805A7070:
    // 0x805A7070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7074: jal         0x8004921C
    // 0x805A7078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x805A7078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x805A707C: bgez        $v0, L_805A708C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805A7080: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805A708C;
    }
    // 0x805A7080: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805A7084: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805A7088: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_805A708C:
    // 0x805A708C: bgtz        $t8, L_805A709C
    if (SIGNED(ctx->r24) > 0) {
        // 0x805A7090: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805A709C;
    }
    // 0x805A7090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7094: b           L_805A70B4
    // 0x805A7098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_805A70B4;
    // 0x805A7098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_805A709C:
    // 0x805A709C: jal         0x8004921C
    // 0x805A70A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x805A70A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x805A70A4: bgez        $v0, L_805A70B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805A70A8: sra         $a3, $v0, 3
        ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805A70B4;
    }
    // 0x805A70A8: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805A70AC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805A70B0: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_805A70B4:
    // 0x805A70B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A70B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A70BC: jal         0x8004921C
    // 0x805A70C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x805A70C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x805A70C4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x805A70C8: bgez        $v0, L_805A70D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805A70CC: sra         $t0, $v0, 3
        ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805A70D8;
    }
    // 0x805A70CC: sra         $t0, $v0, 3
    ctx->r8 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805A70D0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805A70D4: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_805A70D8:
    // 0x805A70D8: bgtzl       $t0, L_805A70EC
    if (SIGNED(ctx->r8) > 0) {
        // 0x805A70DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805A70EC;
    }
    goto skip_1;
    // 0x805A70DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x805A70E0: b           L_805A710C
    // 0x805A70E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805A710C;
    // 0x805A70E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805A70E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_805A70EC:
    // 0x805A70EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A70F0: jal         0x8004921C
    // 0x805A70F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x805A70F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_9:
    // 0x805A70F8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x805A70FC: bgez        $v0, L_805A710C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805A7100: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805A710C;
    }
    // 0x805A7100: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805A7104: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805A7108: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_805A710C:
    // 0x805A710C: addiu       $t1, $a3, 0x7FF
    ctx->r9 = ADD32(ctx->r7, 0X7FF);
    // 0x805A7110: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x805A7114: bne         $v1, $zero, L_805A7120
    if (ctx->r3 != 0) {
        // 0x805A7118: nop
    
            goto L_805A7120;
    }
    // 0x805A7118: nop

    // 0x805A711C: break       7
    do_break(2153410844);
L_805A7120:
    // 0x805A7120: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A7124: bne         $v1, $at, L_805A7138
    if (ctx->r3 != ctx->r1) {
        // 0x805A7128: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A7138;
    }
    // 0x805A7128: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A712C: bne         $t1, $at, L_805A7138
    if (ctx->r9 != ctx->r1) {
        // 0x805A7130: nop
    
            goto L_805A7138;
    }
    // 0x805A7130: nop

    // 0x805A7134: break       6
    do_break(2153410868);
L_805A7138:
    // 0x805A7138: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805A713C: mflo        $t9
    ctx->r25 = lo;
    // 0x805A7140: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x805A7144: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x805A7148: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805A714C: andi        $t3, $t6, 0xFFF
    ctx->r11 = ctx->r14 & 0XFFF;
    // 0x805A7150: sll         $t7, $t3, 12
    ctx->r15 = S32(ctx->r11 << 12);
    // 0x805A7154: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x805A7158: or          $t5, $t4, $t7
    ctx->r13 = ctx->r12 | ctx->r15;
    // 0x805A715C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A7160: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x805A7164: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A7168: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805A716C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x805A7170: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x805A7174: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A7178: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x805A717C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A7180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A7184: jal         0x8004921C
    // 0x805A7188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x805A7188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x805A718C: addiu       $t1, $v0, 0x7
    ctx->r9 = ADD32(ctx->r2, 0X7);
    // 0x805A7190: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805A7194: sra         $t9, $t1, 3
    ctx->r25 = S32(SIGNED(ctx->r9) >> 3);
    // 0x805A7198: andi        $t2, $t9, 0x1FF
    ctx->r10 = ctx->r25 & 0X1FF;
    // 0x805A719C: sll         $t6, $t2, 9
    ctx->r14 = S32(ctx->r10 << 9);
    // 0x805A71A0: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x805A71A4: or          $t3, $t6, $at
    ctx->r11 = ctx->r14 | ctx->r1;
    // 0x805A71A8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A71AC: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x805A71B0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x805A71B4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x805A71B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x805A71BC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x805A71C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A71C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A71C8: jal         0x8004921C
    // 0x805A71CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x805A71CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x805A71D0: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x805A71D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A71D8: jal         0x8004921C
    // 0x805A71DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x805A71DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x805A71E0: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x805A71E4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805A71E8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x805A71EC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x805A71F0: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x805A71F4: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x805A71F8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x805A71FC: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x805A7200: sll         $t6, $t2, 12
    ctx->r14 = S32(ctx->r10 << 12);
    // 0x805A7204: or          $t3, $t8, $t6
    ctx->r11 = ctx->r24 | ctx->r14;
    // 0x805A7208: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A720C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A7210: lui         $t7, 0xE450
    ctx->r15 = S32(0XE450 << 16);
    // 0x805A7214: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x805A7218: ori         $t7, $t7, 0x3C0
    ctx->r15 = ctx->r15 | 0X3C0;
    // 0x805A721C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7220: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x805A7224: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805A7228: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A722C: lui         $t5, 0xB400
    ctx->r13 = S32(0XB400 << 16);
    // 0x805A7230: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x805A7234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A7238: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805A723C: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x805A7240: ori         $t1, $t1, 0x400
    ctx->r9 = ctx->r9 | 0X400;
    // 0x805A7244: lui         $t0, 0xB300
    ctx->r8 = S32(0XB300 << 16);
    // 0x805A7248: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x805A724C: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x805A7250: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x805A7254: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A7258: sw          $s0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r16;
    // 0x805A725C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A7260: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A7264: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A7268: jr          $ra
    // 0x805A726C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x805A726C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80475D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475D58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475D5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475D60: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475D64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475D6C: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26DD8) << 16);
    // 0x80475D70: addiu       $a2, $a2, -0x4A68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26DD8));
    // 0x80475D74: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80475D78: jal         0x80475B40
    // 0x80475D7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475D7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475D88: jr          $ra
    // 0x80475D8C: nop

    return;
    // 0x80475D8C: nop

;}
RECOMP_FUNC void func_80584DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584DBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80584DC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80584DC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80584DCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80584DD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80584DD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80584DD8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80584DDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80584DE0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80584DE4: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x80584DE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80584DEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80584DF0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80584DF4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80584DF8: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x80584DFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80584E00: jal         0x80583CCC
    // 0x80584E04: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x80584E04: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80584E08: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80584E0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584E10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80584E14: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80584E18: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80584E1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80584E20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80584E24: jr          $ra
    // 0x80584E28: nop

    return;
    // 0x80584E28: nop

;}
RECOMP_FUNC void func_80026A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A30: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026A34: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80026A38: addiu       $t8, $t8, 0x48FC
    ctx->r24 = ADD32(ctx->r24, 0X48FC);
    // 0x80026A3C: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x80026A40: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x80026A44: jr          $ra
    // 0x80026A48: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    return;
    // 0x80026A48: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8004C4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C4D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004C4D4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004C4D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004C4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C4E0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004C4E4: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004C4E8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004C4EC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004C4F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004C4F4: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004C4F8: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004C4FC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004C500: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004C504: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004C508: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8004C50C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C510: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8004C514: jal         0x80049864
    // 0x8004C518: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004C518: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004C51C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8004C520: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004C524: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8004C528: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8004C52C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004C530: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C534: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8004C538: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8004C53C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C540: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004C544: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004C548: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004C54C: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8004C550: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C554: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004C558: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004C55C: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8004C560: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004C564: sh          $t4, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r12;
    // 0x8004C568: lh          $t5, 0x48($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X48);
    // 0x8004C56C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8004C570: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8004C574: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x8004C578: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8004C57C: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8004C580: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8004C584: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8004C588: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x8004C58C: lbu         $v1, 0x1($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X1);
    // 0x8004C590: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8004C594: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8004C598: srl         $t8, $v1, 6
    ctx->r24 = S32(U32(ctx->r3) >> 6);
    // 0x8004C59C: andi        $t1, $v1, 0x3F
    ctx->r9 = ctx->r3 & 0X3F;
    // 0x8004C5A0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004C5A4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004C5A8: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x8004C5AC: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8004C5B0: lw          $t6, 0xA24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XA24);
    // 0x8004C5B4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004C5B8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004C5BC: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8004C5C0: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8004C5C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C5C8: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8004C5CC: addiu       $t4, $t0, 0xC
    ctx->r12 = ADD32(ctx->r8, 0XC);
    // 0x8004C5D0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004C5D4: sllv        $t3, $t2, $t5
    ctx->r11 = S32(ctx->r10 << (ctx->r13 & 31));
    // 0x8004C5D8: andi        $t7, $t3, 0x8000
    ctx->r15 = ctx->r11 & 0X8000;
    // 0x8004C5DC: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004C5E0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004C5E4: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8004C5E8: beq         $t7, $zero, L_8004C664
    if (ctx->r15 == 0) {
        // 0x8004C5EC: sh          $t2, 0x3A($sp)
        MEM_H(0X3A, ctx->r29) = ctx->r10;
            goto L_8004C664;
    }
    // 0x8004C5EC: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
    // 0x8004C5F0: lhu         $t8, 0x38($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X38);
    // 0x8004C5F4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8004C5F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004C5FC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C600: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8004C604: jal         0x8004C318
    // 0x8004C608: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    func_8004C318(rdram, ctx);
        goto after_1;
    // 0x8004C608: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    after_1:
    // 0x8004C60C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C610: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004C614: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004C618: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8004C61C: bne         $at, $zero, L_8004C650
    if (ctx->r1 != 0) {
        // 0x8004C620: sb          $t6, 0x14($t0)
        MEM_B(0X14, ctx->r8) = ctx->r14;
            goto L_8004C650;
    }
    // 0x8004C620: sb          $t6, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r14;
    // 0x8004C624: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8004C628: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8004C62C: lhu         $t4, 0x22($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X22);
    // 0x8004C630: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004C634: lwc1        $f6, 0x84($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X84);
    // 0x8004C638: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C63C: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x8004C640: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C644: lwc1        $f8, 0x8C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8C8);
    // 0x8004C648: b           L_8004C66C
    // 0x8004C64C: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
        goto L_8004C66C;
    // 0x8004C64C: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_8004C650:
    // 0x8004C650: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004C654: nop

    // 0x8004C658: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C65C: b           L_8004C66C
    // 0x8004C660: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
        goto L_8004C66C;
    // 0x8004C660: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
L_8004C664:
    // 0x8004C664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004C668: nop

L_8004C66C:
    // 0x8004C66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004C670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004C674: jr          $ra
    // 0x8004C678: nop

    return;
    // 0x8004C678: nop

;}
RECOMP_FUNC void func_804CE910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE910: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804CE914: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(240, 0X118) << 16);
    // 0x804CE918: addiu       $t6, $t6, -0x1C38
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(240, 0X118));
    // 0x804CE91C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804CE920: jr          $ra
    // 0x804CE924: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804CE924: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void Math_FAsinF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081F80: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80081F84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081F88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081F94: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80081F98: jal         0x80081E8C
    // 0x80081F9C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80081F9C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x80081FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081FA8: jr          $ra
    // 0x80081FAC: nop

    return;
    // 0x80081FAC: nop

;}
RECOMP_FUNC void func_806784E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806784E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806784EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806784F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806784F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806784F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806784FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80678500: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80678504: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80678508: lui         $a0, 0x8068
    ctx->r4 = S32(RELOC_HI16(538, 0X15B0) << 16);
    // 0x8067850C: addiu       $a0, $a0, -0x6AE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(538, 0X15B0));
    // 0x80678510: lui         $a1, 0x4564
    ctx->r5 = S32(0X4564 << 16);
    // 0x80678514: jal         0x80046804
    // 0x80678518: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x80678518: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8067851C: bne         $v0, $zero, L_8067852C
    if (ctx->r2 != 0) {
        // 0x80678520: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8067852C;
    }
    // 0x80678520: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80678524: b           L_80678584
    // 0x80678528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80678584;
    // 0x80678528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067852C:
    // 0x8067852C: jal         0x80047090
    // 0x80678530: addiu       $a0, $zero, 0x4564
    ctx->r4 = ADD32(0, 0X4564);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x80678530: addiu       $a0, $zero, 0x4564
    ctx->r4 = ADD32(0, 0X4564);
    after_1:
    // 0x80678534: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x80678538: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x8067853C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80678540: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80678544: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80678548: jal         0x806792AC
    // 0x8067854C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    func_806792AC(rdram, ctx);
        goto after_2;
    // 0x8067854C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    after_2:
    // 0x80678550: lw          $t2, 0x1E0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E0);
    // 0x80678554: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80678558: beq         $t2, $zero, L_80678568
    if (ctx->r10 == 0) {
        // 0x8067855C: sw          $t1, 0x138($s0)
        MEM_W(0X138, ctx->r16) = ctx->r9;
            goto L_80678568;
    }
    // 0x8067855C: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
    // 0x80678560: b           L_80678584
    // 0x80678564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80678584;
    // 0x80678564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80678568:
    // 0x80678568: jal         0x80044194
    // 0x8067856C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x8067856C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80678570: jal         0x80052BA4
    // 0x80678574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_4;
    // 0x80678574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80678578: jal         0x8005FDC4
    // 0x8067857C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x8067857C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80678580: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80678584:
    // 0x80678584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80678588: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8067858C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80678590: jr          $ra
    // 0x80678594: nop

    return;
    // 0x80678594: nop

;}
RECOMP_FUNC void func_805D7EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7F00: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805D7F04: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(474, 0X251C) << 16);
    // 0x805D7F08: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D7F0C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D7F10: addiu       $t6, $t6, -0x61E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X251C));
    // 0x805D7F14: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805D7F18: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D7F1C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805D7F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D7F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D7F28: jal         0x805D7F48
    // 0x805D7F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D7F48(rdram, ctx);
        goto after_0;
    // 0x805D7F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805D7F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D7F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D7F38: jr          $ra
    // 0x805D7F3C: nop

    return;
    // 0x805D7F3C: nop

;}
RECOMP_FUNC void func_8064DCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DCD0: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(498, 0X10) << 16);
    // 0x8064DCD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8064DCD8: jr          $ra
    // 0x8064DCDC: addiu       $v0, $v0, -0x2320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(498, 0X10));
    return;
    // 0x8064DCDC: addiu       $v0, $v0, -0x2320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(498, 0X10));
;}
RECOMP_FUNC void func_804C90AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C90AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C90B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C90B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C90B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C90BC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x804C90C0: jal         0x80048F84
    // 0x804C90C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x804C90C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C90C8: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x804C90CC: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x804C90D0: jal         0x80065ABC
    // 0x804C90D4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x804C90D4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x804C90D8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x804C90DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x804C90E0: jal         0x80081E8C
    // 0x804C90E4: lwc1        $f14, 0xC4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC4);
    fatan2(rdram, ctx);
        goto after_2;
    // 0x804C90E4: lwc1        $f14, 0xC4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC4);
    after_2:
    // 0x804C90E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804C90EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C90F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X940) << 16);
    // 0x804C90F4: lwc1        $f8, -0x6D80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X940));
    // 0x804C90F8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804C90FC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804C9100: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x804C9104: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x804C9108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C910C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C9110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C9114: jr          $ra
    // 0x804C9118: nop

    return;
    // 0x804C9118: nop

;}
RECOMP_FUNC void func_80516880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80516884: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80516888: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8051688C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80516890: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80516894: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80516898: jal         0x80045A34
    // 0x8051689C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8051689C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x805168A0: bne         $v0, $zero, L_805168B8
    if (ctx->r2 != 0) {
        // 0x805168A4: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_805168B8;
    }
    // 0x805168A4: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x805168A8: jal         0x800445A4
    // 0x805168AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805168AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805168B0: b           L_80516CB8
    // 0x805168B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x805168B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805168B8:
    // 0x805168B8: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    // 0x805168BC: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x805168C0: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x805168C4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805168C8: sw          $t6, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r14;
    // 0x805168CC: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x805168D0: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(279, 0X550) << 16);
    // 0x805168D4: lwc1        $f4, 0x6DC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(279, 0X550));
    // 0x805168D8: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(279, 0X554) << 16);
    // 0x805168DC: addiu       $a0, $zero, 0x4140
    ctx->r4 = ADD32(0, 0X4140);
    // 0x805168E0: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x805168E4: lwc1        $f6, 0x6DC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(279, 0X554));
    // 0x805168E8: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(279, 0X558) << 16);
    // 0x805168EC: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x805168F0: lwc1        $f8, 0x6DC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(279, 0X558));
    // 0x805168F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805168F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805168FC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(279, 0X55C) << 16);
    // 0x80516900: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80516904: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80516908: lwc1        $f16, 0x6DCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(279, 0X55C));
    // 0x8051690C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80516910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80516914: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80516918: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8051691C: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x80516920: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80516924: jal         0x80047090
    // 0x80516928: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x80516928: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8051692C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80516930: lui         $a3, 0x3BE5
    ctx->r7 = S32(0X3BE5 << 16);
    // 0x80516934: ori         $a3, $a3, 0x6042
    ctx->r7 = ctx->r7 | 0X6042;
    // 0x80516938: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8051693C: lui         $a1, 0xC180
    ctx->r5 = S32(0XC180 << 16);
    // 0x80516940: jal         0x8004613C
    // 0x80516944: lui         $a2, 0xC372
    ctx->r6 = S32(0XC372 << 16);
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x80516944: lui         $a2, 0xC372
    ctx->r6 = S32(0XC372 << 16);
    after_3:
    // 0x80516948: bne         $v0, $zero, L_80516960
    if (ctx->r2 != 0) {
        // 0x8051694C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80516960;
    }
    // 0x8051694C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80516950: jal         0x800445A4
    // 0x80516954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80516954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80516958: b           L_80516CB8
    // 0x8051695C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x8051695C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516960:
    // 0x80516960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516964: jal         0x80047F9C
    // 0x80516968: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80516968: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8051696C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80516970: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80516974: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80516978: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    // 0x8051697C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80516980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80516984: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80516988: sb          $t9, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r25;
    // 0x8051698C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80516990: addiu       $a0, $zero, 0x4141
    ctx->r4 = ADD32(0, 0X4141);
    // 0x80516994: swc1        $f20, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f20.u32l;
    // 0x80516998: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8051699C: swc1        $f20, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f20.u32l;
    // 0x805169A0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x805169A4: swc1        $f20, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f20.u32l;
    // 0x805169A8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x805169AC: jal         0x80047090
    // 0x805169B0: swc1        $f20, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x805169B0: swc1        $f20, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f20.u32l;
    after_6:
    // 0x805169B4: lui         $at, 0x4141
    ctx->r1 = S32(0X4141 << 16);
    // 0x805169B8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x805169BC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805169C0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x805169C4: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x805169C8: jal         0x8004613C
    // 0x805169CC: lui         $a2, 0xC308
    ctx->r6 = S32(0XC308 << 16);
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x805169CC: lui         $a2, 0xC308
    ctx->r6 = S32(0XC308 << 16);
    after_7:
    // 0x805169D0: bne         $v0, $zero, L_805169E8
    if (ctx->r2 != 0) {
        // 0x805169D4: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_805169E8;
    }
    // 0x805169D4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x805169D8: jal         0x800445A4
    // 0x805169DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x805169DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x805169E0: b           L_80516CB8
    // 0x805169E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x805169E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805169E8:
    // 0x805169E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805169EC: jal         0x80047F9C
    // 0x805169F0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x805169F0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_9:
    // 0x805169F4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x805169F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x805169FC: addiu       $a0, $zero, 0x4141
    ctx->r4 = ADD32(0, 0X4141);
    // 0x80516A00: sb          $v0, 0x17C($t5)
    MEM_B(0X17C, ctx->r13) = ctx->r2;
    // 0x80516A04: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80516A08: sb          $v0, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r2;
    // 0x80516A0C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80516A10: swc1        $f20, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f20.u32l;
    // 0x80516A14: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80516A18: swc1        $f20, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f20.u32l;
    // 0x80516A1C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80516A20: swc1        $f20, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->f20.u32l;
    // 0x80516A24: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80516A28: jal         0x80047090
    // 0x80516A2C: swc1        $f20, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_10;
    // 0x80516A2C: swc1        $f20, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->f20.u32l;
    after_10:
    // 0x80516A30: lui         $at, 0x4141
    ctx->r1 = S32(0X4141 << 16);
    // 0x80516A34: lui         $a3, 0x3BC4
    ctx->r7 = S32(0X3BC4 << 16);
    // 0x80516A38: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x80516A3C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80516A40: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80516A44: jal         0x8004613C
    // 0x80516A48: lui         $a2, 0xC326
    ctx->r6 = S32(0XC326 << 16);
    func_8004613C(rdram, ctx);
        goto after_11;
    // 0x80516A48: lui         $a2, 0xC326
    ctx->r6 = S32(0XC326 << 16);
    after_11:
    // 0x80516A4C: bne         $v0, $zero, L_80516A64
    if (ctx->r2 != 0) {
        // 0x80516A50: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_80516A64;
    }
    // 0x80516A50: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80516A54: jal         0x800445A4
    // 0x80516A58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_12;
    // 0x80516A58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80516A5C: b           L_80516CB8
    // 0x80516A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x80516A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516A64:
    // 0x80516A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516A68: jal         0x80047F9C
    // 0x80516A6C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_13;
    // 0x80516A6C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_13:
    // 0x80516A70: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80516A74: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80516A78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80516A7C: sb          $t1, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r9;
    // 0x80516A80: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80516A84: addiu       $a0, $zero, 0x413F
    ctx->r4 = ADD32(0, 0X413F);
    // 0x80516A88: sb          $t3, 0x18($t4)
    MEM_B(0X18, ctx->r12) = ctx->r11;
    // 0x80516A8C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80516A90: swc1        $f20, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f20.u32l;
    // 0x80516A94: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80516A98: swc1        $f20, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f20.u32l;
    // 0x80516A9C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80516AA0: swc1        $f20, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->f20.u32l;
    // 0x80516AA4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80516AA8: jal         0x80047090
    // 0x80516AAC: swc1        $f20, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_14;
    // 0x80516AAC: swc1        $f20, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->f20.u32l;
    after_14:
    // 0x80516AB0: lui         $at, 0x413F
    ctx->r1 = S32(0X413F << 16);
    // 0x80516AB4: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80516AB8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80516ABC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80516AC0: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    // 0x80516AC4: jal         0x8004613C
    // 0x80516AC8: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    func_8004613C(rdram, ctx);
        goto after_15;
    // 0x80516AC8: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    after_15:
    // 0x80516ACC: bne         $v0, $zero, L_80516AE4
    if (ctx->r2 != 0) {
        // 0x80516AD0: sw          $v0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r2;
            goto L_80516AE4;
    }
    // 0x80516AD0: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80516AD4: jal         0x800445A4
    // 0x80516AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_16;
    // 0x80516AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80516ADC: b           L_80516CB8
    // 0x80516AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x80516AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516AE4:
    // 0x80516AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516AE8: jal         0x80047F9C
    // 0x80516AEC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    func_80047F9C(rdram, ctx);
        goto after_17;
    // 0x80516AEC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_17:
    // 0x80516AF0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80516AF4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80516AF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80516AFC: sb          $t9, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = ctx->r25;
    // 0x80516B00: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80516B04: addiu       $a0, $zero, 0x413F
    ctx->r4 = ADD32(0, 0X413F);
    // 0x80516B08: sb          $t1, 0x18($t2)
    MEM_B(0X18, ctx->r10) = ctx->r9;
    // 0x80516B0C: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80516B10: swc1        $f20, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f20.u32l;
    // 0x80516B14: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80516B18: swc1        $f20, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f20.u32l;
    // 0x80516B1C: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80516B20: swc1        $f20, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->f20.u32l;
    // 0x80516B24: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80516B28: jal         0x80047090
    // 0x80516B2C: swc1        $f20, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_18;
    // 0x80516B2C: swc1        $f20, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f20.u32l;
    after_18:
    // 0x80516B30: lui         $at, 0x413F
    ctx->r1 = S32(0X413F << 16);
    // 0x80516B34: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x80516B38: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80516B3C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80516B40: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80516B44: jal         0x8004613C
    // 0x80516B48: lui         $a2, 0xC250
    ctx->r6 = S32(0XC250 << 16);
    func_8004613C(rdram, ctx);
        goto after_19;
    // 0x80516B48: lui         $a2, 0xC250
    ctx->r6 = S32(0XC250 << 16);
    after_19:
    // 0x80516B4C: bne         $v0, $zero, L_80516B64
    if (ctx->r2 != 0) {
        // 0x80516B50: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_80516B64;
    }
    // 0x80516B50: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80516B54: jal         0x800445A4
    // 0x80516B58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_20;
    // 0x80516B58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80516B5C: b           L_80516CB8
    // 0x80516B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x80516B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516B64:
    // 0x80516B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516B68: jal         0x80047F9C
    // 0x80516B6C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80047F9C(rdram, ctx);
        goto after_21;
    // 0x80516B6C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_21:
    // 0x80516B70: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80516B74: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80516B78: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80516B7C: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    // 0x80516B80: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x80516B84: addiu       $a0, $zero, 0x413F
    ctx->r4 = ADD32(0, 0X413F);
    // 0x80516B88: sb          $t9, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r25;
    // 0x80516B8C: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x80516B90: swc1        $f20, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f20.u32l;
    // 0x80516B94: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x80516B98: swc1        $f20, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f20.u32l;
    // 0x80516B9C: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x80516BA0: swc1        $f20, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f20.u32l;
    // 0x80516BA4: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x80516BA8: jal         0x80047090
    // 0x80516BAC: swc1        $f20, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_22;
    // 0x80516BAC: swc1        $f20, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f20.u32l;
    after_22:
    // 0x80516BB0: lui         $at, 0x413F
    ctx->r1 = S32(0X413F << 16);
    // 0x80516BB4: lui         $a3, 0x3B44
    ctx->r7 = S32(0X3B44 << 16);
    // 0x80516BB8: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x80516BBC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80516BC0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80516BC4: jal         0x8004613C
    // 0x80516BC8: lui         $a2, 0xC160
    ctx->r6 = S32(0XC160 << 16);
    func_8004613C(rdram, ctx);
        goto after_23;
    // 0x80516BC8: lui         $a2, 0xC160
    ctx->r6 = S32(0XC160 << 16);
    after_23:
    // 0x80516BCC: bne         $v0, $zero, L_80516BE4
    if (ctx->r2 != 0) {
        // 0x80516BD0: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_80516BE4;
    }
    // 0x80516BD0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80516BD4: jal         0x800445A4
    // 0x80516BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_24;
    // 0x80516BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x80516BDC: b           L_80516CB8
    // 0x80516BE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x80516BE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516BE4:
    // 0x80516BE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516BE8: jal         0x80047F9C
    // 0x80516BEC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    func_80047F9C(rdram, ctx);
        goto after_25;
    // 0x80516BEC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    after_25:
    // 0x80516BF0: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80516BF4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80516BF8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80516BFC: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
    // 0x80516C00: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80516C04: addiu       $a0, $zero, 0x4142
    ctx->r4 = ADD32(0, 0X4142);
    // 0x80516C08: sb          $t7, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r15;
    // 0x80516C0C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80516C10: swc1        $f20, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f20.u32l;
    // 0x80516C14: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80516C18: swc1        $f20, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f20.u32l;
    // 0x80516C1C: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80516C20: swc1        $f20, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->f20.u32l;
    // 0x80516C24: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x80516C28: jal         0x80047090
    // 0x80516C2C: swc1        $f20, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_26;
    // 0x80516C2C: swc1        $f20, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->f20.u32l;
    after_26:
    // 0x80516C30: lui         $at, 0x4142
    ctx->r1 = S32(0X4142 << 16);
    // 0x80516C34: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x80516C38: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80516C3C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80516C40: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    // 0x80516C44: jal         0x8004613C
    // 0x80516C48: lui         $a2, 0xC35A
    ctx->r6 = S32(0XC35A << 16);
    func_8004613C(rdram, ctx);
        goto after_27;
    // 0x80516C48: lui         $a2, 0xC35A
    ctx->r6 = S32(0XC35A << 16);
    after_27:
    // 0x80516C4C: bne         $v0, $zero, L_80516C64
    if (ctx->r2 != 0) {
        // 0x80516C50: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_80516C64;
    }
    // 0x80516C50: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80516C54: jal         0x800445A4
    // 0x80516C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_28;
    // 0x80516C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x80516C5C: b           L_80516CB8
    // 0x80516C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80516CB8;
    // 0x80516C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516C64:
    // 0x80516C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516C68: jal         0x80047F9C
    // 0x80516C6C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_80047F9C(rdram, ctx);
        goto after_29;
    // 0x80516C6C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_29:
    // 0x80516C70: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x80516C74: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80516C78: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80516C7C: sb          $t3, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r11;
    // 0x80516C80: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80516C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80516C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80516C8C: sb          $t5, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r13;
    // 0x80516C90: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80516C94: swc1        $f20, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f20.u32l;
    // 0x80516C98: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x80516C9C: swc1        $f20, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f20.u32l;
    // 0x80516CA0: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x80516CA4: swc1        $f20, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->f20.u32l;
    // 0x80516CA8: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x80516CAC: jal         0x80516D84
    // 0x80516CB0: swc1        $f20, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->f20.u32l;
    func_80516D84(rdram, ctx);
        goto after_30;
    // 0x80516CB0: swc1        $f20, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->f20.u32l;
    after_30:
    // 0x80516CB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80516CB8:
    // 0x80516CB8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80516CBC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80516CC0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80516CC4: jr          $ra
    // 0x80516CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80516CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8057BD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BD84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057BD88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BD8C: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x8057BD90: beql        $v0, $zero, L_8057BDC8
    if (ctx->r2 == 0) {
        // 0x8057BD94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8057BDC8;
    }
    goto skip_0;
    // 0x8057BD94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8057BD98: jalr        $v0
    // 0x8057BD9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8057BD9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057BDA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057BDA4: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8057BDA8: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8057BDAC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8057BDB0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8057BDB4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8057BDB8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8057BDBC: b           L_8057BDC8
    // 0x8057BDC0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_8057BDC8;
    // 0x8057BDC0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x8057BDC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057BDC8:
    // 0x8057BDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057BDCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057BDD0: jr          $ra
    // 0x8057BDD4: nop

    return;
    // 0x8057BDD4: nop

;}
RECOMP_FUNC void func_806721E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806721E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806721E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806721E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806721EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806721F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806721F4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806721F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x806721FC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80672200: jal         0x80671D4C
    // 0x80672204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80672204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80672208: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x8067220C: addiu       $a1, $s0, 0x60
    ctx->r5 = ADD32(ctx->r16, 0X60);
    // 0x80672210: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80672214: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672218: blez        $t7, L_80672248
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8067221C: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80672248;
    }
    // 0x8067221C: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80672220: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80672224: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672228: jal         0x80671954
    // 0x8067222C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x8067222C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_1:
    // 0x80672230: beq         $v0, $zero, L_8067223C
    if (ctx->r2 == 0) {
        // 0x80672234: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8067223C;
    }
    // 0x80672234: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80672238: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8067223C:
    // 0x8067223C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80672240: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80672244: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80672248:
    // 0x80672248: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8067224C: beq         $at, $zero, L_80672260
    if (ctx->r1 == 0) {
        // 0x80672250: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80672260;
    }
    // 0x80672250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80672254: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672258: jal         0x80671C98
    // 0x8067225C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x8067225C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
L_80672260:
    // 0x80672260: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80672264: bne         $at, $zero, L_80672280
    if (ctx->r1 != 0) {
        // 0x80672268: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80672280;
    }
    // 0x80672268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8067226C: jal         0x80672C80
    // 0x80672270: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80672270: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
    // 0x80672274: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80672278: jal         0x80067818
    // 0x8067227C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067227C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80672280:
    // 0x80672280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80672284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80672288: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8067228C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80672290: jr          $ra
    // 0x80672294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80672294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805D8AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8AB4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D8AB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805D8ABC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805D8AC0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D8AC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D8AC8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D8ACC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D8AD0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D8AD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805D8AD8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D8ADC: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X253C) << 16);
    // 0x805D8AE0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D8AE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D8AE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D8AEC: lw          $t1, -0x61C4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X253C));
    // 0x805D8AF0: jr          $ra
    // 0x805D8AF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D8AF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80667024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80667028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066702C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80667030: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80667034: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80667038: jal         0x80666E34
    // 0x8066703C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80666E34(rdram, ctx);
        goto after_0;
    // 0x8066703C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80667040: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80667044: jal         0x80666ACC
    // 0x80667048: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80666ACC(rdram, ctx);
        goto after_1;
    // 0x80667048: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8066704C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80667050: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80667054: jal         0x80666CF8
    // 0x80667058: addiu       $a1, $a1, 0x6C
    ctx->r5 = ADD32(ctx->r5, 0X6C);
    func_80666CF8(rdram, ctx);
        goto after_2;
    // 0x80667058: addiu       $a1, $a1, 0x6C
    ctx->r5 = ADD32(ctx->r5, 0X6C);
    after_2:
    // 0x8066705C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80667060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80667064: jr          $ra
    // 0x80667068: nop

    return;
    // 0x80667068: nop

;}
RECOMP_FUNC void func_80715AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80715AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715AC8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80715ACC: beq         $v0, $zero, L_80715AE8
    if (ctx->r2 == 0) {
        // 0x80715AD0: nop
    
            goto L_80715AE8;
    }
    // 0x80715AD0: nop

    // 0x80715AD4: lw          $v1, 0x180($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X180);
    // 0x80715AD8: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0X1548) << 16);
    // 0x80715ADC: addiu       $t6, $t6, 0x5D68
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0X1548));
    // 0x80715AE0: bne         $v1, $zero, L_80715AF8
    if (ctx->r3 != 0) {
        // 0x80715AE4: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_80715AF8;
    }
    // 0x80715AE4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
L_80715AE8:
    // 0x80715AE8: jal         0x800447C8
    // 0x80715AEC: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80715AEC: nop

    after_0:
    // 0x80715AF0: b           L_80715B64
    // 0x80715AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80715B64;
    // 0x80715AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715AF8:
    // 0x80715AF8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80715AFC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80715B00: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80715B04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80715B08: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x80715B0C: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x80715B10: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80715B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80715B18: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80715B1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80715B20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80715B24: jal         0x80045A34
    // 0x80715B28: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80715B28: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80715B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80715B30: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80715B34: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(730, 0XC3C) << 16);
    // 0x80715B38: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80715B3C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80715B40: lw          $t0, 0x1E0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1E0);
    // 0x80715B44: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80715B48: addiu       $t1, $t1, 0x545C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(730, 0XC3C));
    // 0x80715B4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80715B50: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x80715B54: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80715B58: jal         0x8071584C
    // 0x80715B5C: sb          $t2, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r10;
    func_8071584C(rdram, ctx);
        goto after_2;
    // 0x80715B5C: sb          $t2, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r10;
    after_2:
    // 0x80715B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715B64:
    // 0x80715B64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80715B68: jr          $ra
    // 0x80715B6C: nop

    return;
    // 0x80715B6C: nop

;}
RECOMP_FUNC void func_8002F96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F96C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F970: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002F974: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F97C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002F980: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002F984: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002F988: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F98C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F990: jal         0x8002F678
    // 0x8002F994: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F994: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F998: beq         $v0, $zero, L_8002F9C4
    if (ctx->r2 == 0) {
        // 0x8002F99C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002F9C4;
    }
    // 0x8002F99C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F9A0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002F9A4: addiu       $t6, $t6, -0x1310
    ctx->r14 = ADD32(ctx->r14, -0X1310);
    // 0x8002F9A8: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
    // 0x8002F9AC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002F9B0: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002F9B4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002F9B8: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8002F9BC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002F9C0: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
L_8002F9C4:
    // 0x8002F9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F9C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F9CC: jr          $ra
    // 0x8002F9D0: nop

    return;
    // 0x8002F9D0: nop

;}
RECOMP_FUNC void func_8002DD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DD0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DD10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DD14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DD18: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DD1C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002DD20: jal         0x8002DBE4
    // 0x8002DD24: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x8002DD24: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002DD28: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DD2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002DD30: sb          $t7, 0x21($t8)
    MEM_B(0X21, ctx->r24) = ctx->r15;
    // 0x8002DD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DD38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DD3C: jr          $ra
    // 0x8002DD40: nop

    return;
    // 0x8002DD40: nop

;}
RECOMP_FUNC void gfxprint_printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FAAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007FAB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FAB4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007FAB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007FABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007FAC0: jal         0x8007FA8C
    // 0x8007FAC4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    gfxprint_vprintf(rdram, ctx);
        goto after_0;
    // 0x8007FAC4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8007FAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007FAD0: jr          $ra
    // 0x8007FAD4: nop

    return;
    // 0x8007FAD4: nop

;}
RECOMP_FUNC void func_80422FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422FA8: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80422FAC: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(35, 0X2F0C) << 16);
    // 0x80422FB0: addiu       $v1, $a1, 0xFC
    ctx->r3 = ADD32(ctx->r5, 0XFC);
    // 0x80422FB4: addiu       $v0, $v0, 0x590C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(35, 0X2F0C));
    // 0x80422FB8: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80422FBC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80422FC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80422FC4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
L_80422FC8:
    // 0x80422FC8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80422FCC: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80422FD0: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x80422FD4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80422FD8: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80422FDC: sh          $t7, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r15;
    // 0x80422FE0: lh          $t8, -0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X2);
    // 0x80422FE4: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x80422FE8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80422FEC: sltu        $at, $a3, $t9
    ctx->r1 = ctx->r7 < ctx->r25 ? 1 : 0;
    // 0x80422FF0: bnel        $at, $zero, L_80422FC8
    if (ctx->r1 != 0) {
        // 0x80422FF4: lh          $t6, 0x0($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X0);
            goto L_80422FC8;
    }
    goto skip_0;
    // 0x80422FF4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x80422FF8: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(35, 0X2FD8) << 16);
    // 0x80422FFC: addiu       $t1, $t1, 0x59D8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(35, 0X2FD8));
    // 0x80423000: addiu       $v1, $a1, 0x1C8
    ctx->r3 = ADD32(ctx->r5, 0X1C8);
    // 0x80423004: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80423008: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    // 0x8042300C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80423010: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423014: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80423018:
    // 0x80423018: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8042301C: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80423020: addiu       $v1, $v1, 0x220
    ctx->r3 = ADD32(ctx->r3, 0X220);
    // 0x80423024: bne         $a3, $a1, L_80423018
    if (ctx->r7 != ctx->r5) {
        // 0x80423028: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80423018;
    }
    // 0x80423028: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8042302C: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x80423030: jr          $ra
    // 0x80423034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80423034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_806FBC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBC10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806FBC14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FBC18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806FBC1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806FBC20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FBC24: jal         0x8004700C
    // 0x806FBC28: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806FBC28: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806FBC2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806FBC30: jal         0x806FBB60
    // 0x806FBC34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806FBB60(rdram, ctx);
        goto after_1;
    // 0x806FBC34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806FBC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FBC3C: jal         0x806FBA08
    // 0x806FBC40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_806FBA08(rdram, ctx);
        goto after_2;
    // 0x806FBC40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x806FBC44: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806FBC48: beq         $v0, $zero, L_806FBCC0
    if (ctx->r2 == 0) {
        // 0x806FBC4C: nop
    
            goto L_806FBCC0;
    }
    // 0x806FBC4C: nop

    // 0x806FBC50: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x806FBC54: lui         $v1, 0x8070
    ctx->r3 = S32(RELOC_HI16(700, 0X2850) << 16);
    // 0x806FBC58: addiu       $v1, $v1, -0x3B80
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(700, 0X2850));
    // 0x806FBC5C: bne         $s0, $t6, L_806FBCC0
    if (ctx->r16 != ctx->r14) {
        // 0x806FBC60: lui         $t9, 0x8070
        ctx->r25 = S32(RELOC_HI16(700, 0X2754) << 16);
            goto L_806FBCC0;
    }
    // 0x806FBC60: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FBC64: sw          $zero, 0x14C4($s1)
    MEM_W(0X14C4, ctx->r17) = 0;
    // 0x806FBC68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806FBC6C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x806FBC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FBC74: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x806FBC78: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806FBC7C: sw          $t7, 0x14CC($s1)
    MEM_W(0X14CC, ctx->r17) = ctx->r15;
    // 0x806FBC80: lw          $t9, -0x3C7C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FBC84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FBC88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806FBC8C: sw          $t9, 0x14C8($s1)
    MEM_W(0X14C8, ctx->r17) = ctx->r25;
    // 0x806FBC90: jal         0x806FC1EC
    // 0x806FBC94: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_806FC1EC(rdram, ctx);
        goto after_3;
    // 0x806FBC94: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x806FBC98: jal         0x806F9C90
    // 0x806FBC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F9C90(rdram, ctx);
        goto after_4;
    // 0x806FBC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806FBCA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806FBCA4: jal         0x80067BBC
    // 0x806FBCA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x806FBCA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x806FBCAC: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    // 0x806FBCB0: jal         0x80067818
    // 0x806FBCB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x806FBCB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x806FBCB8: b           L_806FBCCC
    // 0x806FBCBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806FBCCC;
    // 0x806FBCBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FBCC0:
    // 0x806FBCC0: jal         0x806F9CC8
    // 0x806FBCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F9CC8(rdram, ctx);
        goto after_7;
    // 0x806FBCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806FBCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FBCCC:
    // 0x806FBCCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806FBCD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806FBCD4: jr          $ra
    // 0x806FBCD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806FBCD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006D1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1CC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006D1D0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006D1D4: lw          $v0, 0x59C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X59C);
    // 0x8006D1D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006D1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1E0: lh          $a3, 0x114($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X114);
    // 0x8006D1E4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8006D1E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006D1EC: beql        $a3, $zero, L_8006D2D4
    if (ctx->r7 == 0) {
        // 0x8006D1F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006D2D4;
    }
    goto skip_0;
    // 0x8006D1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006D1F4: beq         $a3, $at, L_8006D240
    if (ctx->r7 == ctx->r1) {
        // 0x8006D1F8: lui         $t1, 0x800A
        ctx->r9 = S32(0X800A << 16);
            goto L_8006D240;
    }
    // 0x8006D1F8: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8006D1FC: lw          $t6, 0x5B4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X5B4);
    // 0x8006D200: beql        $a3, $t6, L_8006D244
    if (ctx->r7 == ctx->r14) {
        // 0x8006D204: lw          $v0, 0x630($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X630);
            goto L_8006D244;
    }
    goto skip_1;
    // 0x8006D204: lw          $v0, 0x630($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X630);
    skip_1:
    // 0x8006D208: lw          $t7, 0x3EC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3EC);
    // 0x8006D20C: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x8006D210: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8006D214: lbu         $t9, 0x598($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X598);
    // 0x8006D218: beql        $t9, $at, L_8006D288
    if (ctx->r25 == ctx->r1) {
        // 0x8006D21C: lw          $t3, 0xF10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0XF10);
            goto L_8006D288;
    }
    goto skip_2;
    // 0x8006D21C: lw          $t3, 0xF10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF10);
    skip_2:
    // 0x8006D220: jal         0x8006CFC0
    // 0x8006D224: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8006CFC0(rdram, ctx);
        goto after_0;
    // 0x8006D224: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006D228: jal         0x8006D0F4
    // 0x8006D22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006D0F4(rdram, ctx);
        goto after_1;
    // 0x8006D22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006D230: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006D234: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006D238: b           L_8006D284
    // 0x8006D23C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_8006D284;
    // 0x8006D23C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8006D240:
    // 0x8006D240: lw          $v0, 0x630($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X630);
L_8006D244:
    // 0x8006D244: lw          $a0, 0x5B4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5B4);
    // 0x8006D248: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006D24C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8006D250: bne         $at, $zero, L_8006D260
    if (ctx->r1 != 0) {
        // 0x8006D254: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_8006D260;
    }
    // 0x8006D254: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8006D258: b           L_8006D26C
    // 0x8006D25C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006D26C;
    // 0x8006D25C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006D260:
    // 0x8006D260: bgezl       $v0, L_8006D270
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D264: sw          $v0, 0x630($v1)
        MEM_W(0X630, ctx->r3) = ctx->r2;
            goto L_8006D270;
    }
    goto skip_3;
    // 0x8006D264: sw          $v0, 0x630($v1)
    MEM_W(0X630, ctx->r3) = ctx->r2;
    skip_3:
    // 0x8006D268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D26C:
    // 0x8006D26C: sw          $v0, 0x630($v1)
    MEM_W(0X630, ctx->r3) = ctx->r2;
L_8006D270:
    // 0x8006D270: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006D274: lw          $t1, 0x7838($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7838);
    // 0x8006D278: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x8006D27C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006D280: sw          $t1, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->r9;
L_8006D284:
    // 0x8006D284: lw          $t3, 0xF10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XF10);
L_8006D288:
    // 0x8006D288: sw          $zero, 0xAA4($v1)
    MEM_W(0XAA4, ctx->r3) = 0;
    // 0x8006D28C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D290: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006D294: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
    // 0x8006D298: lw          $t5, 0xF14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XF14);
    // 0x8006D29C: addiu       $a0, $a0, -0x7688
    ctx->r4 = ADD32(ctx->r4, -0X7688);
    // 0x8006D2A0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8006D2A4: sltiu       $at, $t5, 0x9
    ctx->r1 = ctx->r13 < 0X9 ? 1 : 0;
    // 0x8006D2A8: bne         $at, $zero, L_8006D2B8
    if (ctx->r1 != 0) {
        // 0x8006D2AC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8006D2B8;
    }
    // 0x8006D2AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D2B0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8006D2B4: sw          $t6, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->r14;
L_8006D2B8:
    // 0x8006D2B8: jal         0x80065728
    // 0x8006D2BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8006D2BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8006D2C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8006D2C4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006D2C8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006D2CC: sw          $a3, 0x5B4($v1)
    MEM_W(0X5B4, ctx->r3) = ctx->r7;
    // 0x8006D2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006D2D4:
    // 0x8006D2D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006D2D8: jr          $ra
    // 0x8006D2DC: nop

    return;
    // 0x8006D2DC: nop

;}
RECOMP_FUNC void func_8042EF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EF0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8042EF10: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X33FC) << 16);
    // 0x8042EF14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042EF18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042EF1C: addiu       $t7, $t7, 0x14DC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X33FC));
    // 0x8042EF20: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8042EF24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8042EF28: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8042EF2C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8042EF30: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8042EF34: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x8042EF38: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8042EF3C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8042EF40: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x8042EF44: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8042EF48: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042EF4C: addiu       $t1, $t1, 0x1230
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x8042EF50: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8042EF54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042EF58: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042EF5C: jal         0x80045A34
    // 0x8042EF60: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8042EF60: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8042EF64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042EF68: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042EF6C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8042EF70: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8042EF74: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042EF78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8042EF7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042EF80: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x8042EF84: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042EF88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042EF8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042EF90: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8042EF94:
    // 0x8042EF94: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042EF98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042EF9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042EFA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8042EFA4: bne         $a1, $v0, L_8042EF94
    if (ctx->r5 != ctx->r2) {
        // 0x8042EFA8: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8042EF94;
    }
    // 0x8042EFA8: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8042EFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EFB0: jal         0x8042EFF4
    // 0x8042EFB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8042EFF4(rdram, ctx);
        goto after_1;
    // 0x8042EFB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8042EFB8: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x8042EFBC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042EFC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042EFC4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8042EFC8: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8042EFCC: lwc1        $f6, 0x24($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8042EFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EFD4: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x8042EFD8: jal         0x8042EEF4
    // 0x8042EFDC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    func_8042EEF4(rdram, ctx);
        goto after_2;
    // 0x8042EFDC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8042EFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042EFE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042EFE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8042EFEC: jr          $ra
    // 0x8042EFF0: nop

    return;
    // 0x8042EFF0: nop

;}
RECOMP_FUNC void func_80001B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B28: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x80001B2C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80001B30: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80001B34: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80001B38: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80001B3C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80001B40: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80001B44: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80001B48: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80001B4C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80001B50: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80001B54: sw          $a0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r4;
    // 0x80001B58: sw          $a3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r7;
    // 0x80001B5C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80001B60: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80001B64: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80001B68: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80001B6C: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80001B70: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x80001B74: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80001B78: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80001B7C: lw          $t6, 0x773C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X773C);
    // 0x80001B80: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80001B84: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80001B88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80001B8C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80001B90: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80001B94: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80001B98: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80001B9C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80001BA0: srl         $t3, $t3, 31
    ctx->r11 = S32(U32(ctx->r11) >> 31);
    // 0x80001BA4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80001BA8: bne         $t2, $t8, L_80001BEC
    if (ctx->r10 != ctx->r24) {
        // 0x80001BAC: addu        $a3, $t9, $t6
        ctx->r7 = ADD32(ctx->r25, ctx->r14);
            goto L_80001BEC;
    }
    // 0x80001BAC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x80001BB0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80001BB4: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x80001BB8: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80001BBC: sh          $zero, 0x10($a2)
    MEM_H(0X10, ctx->r6) = 0;
    // 0x80001BC0: sh          $zero, 0x12($a2)
    MEM_H(0X12, ctx->r6) = 0;
    // 0x80001BC4: sb          $zero, 0x2($a2)
    MEM_B(0X2, ctx->r6) = 0;
    // 0x80001BC8: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x80001BCC: lbu         $t9, 0x5($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5);
    // 0x80001BD0: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80001BD4: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x80001BD8: sb          $t9, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r25;
    // 0x80001BDC: lbu         $t6, 0xB0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XB0);
    // 0x80001BE0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80001BE4: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80001BE8: sb          $t7, 0xB0($a3)
    MEM_B(0XB0, ctx->r7) = ctx->r15;
L_80001BEC:
    // 0x80001BEC: lhu         $t8, 0xC($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0XC);
    // 0x80001BF0: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x80001BF4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80001BF8: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001BFC: sh          $t8, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r24;
    // 0x80001C00: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80001C04: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x80001C08: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80001C0C: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // 0x80001C10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001C14: mflo        $t7
    ctx->r15 = lo;
    // 0x80001C18: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80001C1C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001C20: bne         $t2, $v0, L_80001C28
    if (ctx->r10 != ctx->r2) {
        // 0x80001C24: sh          $t0, 0x6($s0)
        MEM_H(0X6, ctx->r16) = ctx->r8;
            goto L_80001C28;
    }
    // 0x80001C24: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_80001C28:
    // 0x80001C28: sb          $a0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r4;
    // 0x80001C2C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80001C30: sll         $t7, $v1, 13
    ctx->r15 = S32(ctx->r3 << 13);
    // 0x80001C34: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80001C38: beql        $t8, $zero, L_80001C9C
    if (ctx->r24 == 0) {
        // 0x80001C3C: lw          $t6, 0x10($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X10);
            goto L_80001C9C;
    }
    goto skip_0;
    // 0x80001C3C: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    skip_0:
    // 0x80001C40: srl         $a3, $t0, 16
    ctx->r7 = S32(U32(ctx->r8) >> 16);
    // 0x80001C44: lw          $a0, 0x16C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X16C);
    // 0x80001C48: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80001C4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80001C50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80001C54: sw          $s0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r16;
    // 0x80001C58: jal         0x80002B8C
    // 0x80001C5C: sw          $s2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r18;
    func_80002B8C(rdram, ctx);
        goto after_0;
    // 0x80001C5C: sw          $s2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r18;
    after_0:
    // 0x80001C60: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
    // 0x80001C64: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80001C68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80001C6C: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80001C70: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80001C74: addiu       $t6, $t9, 0x580
    ctx->r14 = ADD32(ctx->r25, 0X580);
    // 0x80001C78: sh          $t6, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r14;
    // 0x80001C7C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80001C80: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80001C84: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x80001C88: lw          $s0, 0x160($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X160);
    // 0x80001C8C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80001C90: b           L_80002564
    // 0x80001C94: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
        goto L_80002564;
    // 0x80001C94: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
    // 0x80001C98: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
L_80001C9C:
    // 0x80001C9C: srl         $t9, $t0, 16
    ctx->r25 = S32(U32(ctx->r8) >> 16);
    // 0x80001CA0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80001CA4: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80001CA8: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80001CAC: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
    // 0x80001CB0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80001CB4: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80001CB8: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80001CBC: blez        $a0, L_80002564
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80001CC0: sw          $t8, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r24;
            goto L_80002564;
    }
    // 0x80001CC0: sw          $t8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r24;
    // 0x80001CC4: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80001CC8: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80001CCC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80001CD0: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80001CD4: sw          $v0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r2;
    // 0x80001CD8: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80001CDC: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80001CE0: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x80001CE4: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x80001CE8: sw          $s0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r16;
    // 0x80001CEC: sw          $s2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r18;
    // 0x80001CF0: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x80001CF4: lw          $s3, 0x16C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X16C);
    // 0x80001CF8: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80001CFC: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80001D00: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
L_80001D04:
    // 0x80001D04: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x80001D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001D0C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80001D10: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80001D14: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80001D18: bne         $v1, $at, L_80001D28
    if (ctx->r3 != ctx->r1) {
        // 0x80001D1C: srl         $t0, $t0, 28
        ctx->r8 = S32(U32(ctx->r8) >> 28);
            goto L_80001D28;
    }
    // 0x80001D1C: srl         $t0, $t0, 28
    ctx->r8 = S32(U32(ctx->r8) >> 28);
    // 0x80001D20: b           L_80001D50
    // 0x80001D24: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
        goto L_80001D50;
    // 0x80001D24: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
L_80001D28:
    // 0x80001D28: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x80001D2C: beq         $t7, $zero, L_80001D4C
    if (ctx->r15 == 0) {
        // 0x80001D30: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_80001D4C;
    }
    // 0x80001D30: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80001D34: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80001D38: and         $t8, $a0, $at
    ctx->r24 = ctx->r4 & ctx->r1;
    // 0x80001D3C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80001D40: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80001D44: b           L_80001D50
    // 0x80001D48: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
        goto L_80001D50;
    // 0x80001D48: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
L_80001D4C:
    // 0x80001D4C: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
L_80001D50:
    // 0x80001D50: beq         $t0, $zero, L_80001D60
    if (ctx->r8 == 0) {
        // 0x80001D54: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80001D60;
    }
    // 0x80001D54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80001D58: bnel        $t0, $at, L_80001E1C
    if (ctx->r8 != ctx->r1) {
        // 0x80001D5C: lw          $t7, 0x100($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X100);
            goto L_80001E1C;
    }
    goto skip_1;
    // 0x80001D5C: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    skip_1:
L_80001D60:
    // 0x80001D60: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80001D64: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80001D68: lw          $t8, 0x4D20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4D20);
    // 0x80001D6C: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x80001D70: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80001D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001D78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80001D7C: beql        $t8, $v0, L_80001E1C
    if (ctx->r24 == ctx->r2) {
        // 0x80001D80: lw          $t7, 0x100($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X100);
            goto L_80001E1C;
    }
    goto skip_2;
    // 0x80001D80: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    skip_2:
    // 0x80001D84: beq         $a1, $at, L_80001DA8
    if (ctx->r5 == ctx->r1) {
        // 0x80001D88: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_80001DA8;
    }
    // 0x80001D88: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80001D8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001D90: beq         $a1, $at, L_80001DB8
    if (ctx->r5 == ctx->r1) {
        // 0x80001D94: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80001DB8;
    }
    // 0x80001D94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80001D98: beq         $a1, $at, L_80001DB8
    if (ctx->r5 == ctx->r1) {
        // 0x80001D9C: nop
    
            goto L_80001DB8;
    }
    // 0x80001D9C: nop

    // 0x80001DA0: b           L_80001DB8
    // 0x80001DA4: nop

        goto L_80001DB8;
    // 0x80001DA4: nop

L_80001DA8:
    // 0x80001DA8: addiu       $t6, $t6, 0x6CCA
    ctx->r14 = ADD32(ctx->r14, 0X6CCA);
    // 0x80001DAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80001DB0: b           L_80001DC0
    // 0x80001DB4: sw          $t6, 0x4D20($at)
    MEM_W(0X4D20, ctx->r1) = ctx->r14;
        goto L_80001DC0;
    // 0x80001DB4: sw          $t6, 0x4D20($at)
    MEM_W(0X4D20, ctx->r1) = ctx->r14;
L_80001DB8:
    // 0x80001DB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80001DBC: sw          $v0, 0x4D20($at)
    MEM_W(0X4D20, ctx->r1) = ctx->r2;
L_80001DC0:
    // 0x80001DC0: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80001DC4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80001DC8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80001DCC: lw          $v0, 0xC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XC);
    // 0x80001DD0: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80001DD4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80001DD8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80001DDC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80001DE0: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80001DE4: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001DE8: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80001DEC: mflo        $a0
    ctx->r4 = lo;
    // 0x80001DF0: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x80001DF4: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x80001DF8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80001DFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80001E00: lw          $t8, 0x4D20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4D20);
    // 0x80001E04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80001E08: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x80001E0C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80001E10: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80001E14: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80001E18: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
L_80001E1C:
    // 0x80001E1C: beql        $t7, $zero, L_800023E8
    if (ctx->r15 == 0) {
        // 0x80001E20: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800023E8;
    }
    goto skip_3;
    // 0x80001E20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_3:
    // 0x80001E24: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
L_80001E28:
    // 0x80001E28: sw          $zero, 0x138($sp)
    MEM_W(0X138, ctx->r29) = 0;
    // 0x80001E2C: sw          $zero, 0x134($sp)
    MEM_W(0X134, ctx->r29) = 0;
    // 0x80001E30: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x80001E34: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x80001E38: subu        $a0, $t8, $t3
    ctx->r4 = SUB32(ctx->r24, ctx->r11);
    // 0x80001E3C: sw          $a0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r4;
    // 0x80001E40: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80001E44: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80001E48: andi        $s4, $a2, 0xF
    ctx->r20 = ctx->r6 & 0XF;
    // 0x80001E4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80001E50: subu        $v1, $t9, $a2
    ctx->r3 = SUB32(ctx->r25, ctx->r6);
    // 0x80001E54: bne         $s4, $zero, L_80001E6C
    if (ctx->r20 != 0) {
        // 0x80001E58: srl         $t0, $a3, 28
        ctx->r8 = S32(U32(ctx->r7) >> 28);
            goto L_80001E6C;
    }
    // 0x80001E58: srl         $t0, $a3, 28
    ctx->r8 = S32(U32(ctx->r7) >> 28);
    // 0x80001E5C: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x80001E60: bnel        $t7, $zero, L_80001E70
    if (ctx->r15 != 0) {
        // 0x80001E64: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_80001E70;
    }
    goto skip_4;
    // 0x80001E64: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    skip_4:
    // 0x80001E68: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_80001E6C:
    // 0x80001E6C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
L_80001E70:
    // 0x80001E70: subu        $a1, $t9, $s4
    ctx->r5 = SUB32(ctx->r25, ctx->r20);
    // 0x80001E74: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80001E78: beq         $at, $zero, L_80001EAC
    if (ctx->r1 == 0) {
        // 0x80001E7C: or          $fp, $a1, $zero
        ctx->r30 = ctx->r5 | 0;
            goto L_80001EAC;
    }
    // 0x80001E7C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80001E80: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x80001E84: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80001E88: bgez        $v0, L_80001E94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80001E8C: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_80001E94;
    }
    // 0x80001E8C: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x80001E90: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
L_80001E94:
    // 0x80001E94: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
    // 0x80001E98: sll         $s1, $v0, 4
    ctx->r17 = S32(ctx->r2 << 4);
    // 0x80001E9C: addu        $t8, $a1, $s1
    ctx->r24 = ADD32(ctx->r5, ctx->r17);
    // 0x80001EA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80001EA4: b           L_80001EF8
    // 0x80001EA8: subu        $t1, $t8, $a0
    ctx->r9 = SUB32(ctx->r24, ctx->r4);
        goto L_80001EF8;
    // 0x80001EA8: subu        $t1, $t8, $a0
    ctx->r9 = SUB32(ctx->r24, ctx->r4);
L_80001EAC:
    // 0x80001EAC: subu        $s1, $v1, $a1
    ctx->r17 = SUB32(ctx->r3, ctx->r5);
    // 0x80001EB0: bgtz        $s1, L_80001EC0
    if (SIGNED(ctx->r17) > 0) {
        // 0x80001EB4: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80001EC0;
    }
    // 0x80001EB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80001EB8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80001EBC: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
L_80001EC0:
    // 0x80001EC0: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x80001EC4: addiu       $s2, $s1, 0xF
    ctx->r18 = ADD32(ctx->r17, 0XF);
    // 0x80001EC8: bgez        $s2, L_80001ED4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80001ECC: addu        $at, $s2, $zero
        ctx->r1 = ADD32(ctx->r18, 0);
            goto L_80001ED4;
    }
    // 0x80001ECC: addu        $at, $s2, $zero
    ctx->r1 = ADD32(ctx->r18, 0);
    // 0x80001ED0: addiu       $at, $s2, 0xF
    ctx->r1 = ADD32(ctx->r18, 0XF);
L_80001ED4:
    // 0x80001ED4: sra         $s2, $at, 4
    ctx->r18 = S32(SIGNED(ctx->r1) >> 4);
    // 0x80001ED8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80001EDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80001EE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80001EE4: beql        $t7, $zero, L_80001EF8
    if (ctx->r15 == 0) {
        // 0x80001EE8: sw          $t8, 0x138($sp)
        MEM_W(0X138, ctx->r29) = ctx->r24;
            goto L_80001EF8;
    }
    goto skip_5;
    // 0x80001EE8: sw          $t8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r24;
    skip_5:
    // 0x80001EEC: b           L_80001EF8
    // 0x80001EF0: sw          $t9, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r25;
        goto L_80001EF8;
    // 0x80001EF0: sw          $t9, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r25;
    // 0x80001EF4: sw          $t8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r24;
L_80001EF8:
    // 0x80001EF8: beq         $t0, $zero, L_80001F20
    if (ctx->r8 == 0) {
        // 0x80001EFC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80001F20;
    }
    // 0x80001EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001F00: beq         $t0, $at, L_80001F40
    if (ctx->r8 == ctx->r1) {
        // 0x80001F04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80001F40;
    }
    // 0x80001F04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001F08: beq         $t0, $at, L_80002330
    if (ctx->r8 == ctx->r1) {
        // 0x80001F0C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80002330;
    }
    // 0x80001F0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80001F10: beql        $t0, $at, L_80001F34
    if (ctx->r8 == ctx->r1) {
        // 0x80001F14: addiu       $s7, $zero, 0x5
        ctx->r23 = ADD32(0, 0X5);
            goto L_80001F34;
    }
    goto skip_6;
    // 0x80001F14: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    skip_6:
    // 0x80001F18: b           L_80001F4C
    // 0x80001F1C: nop

        goto L_80001F4C;
    // 0x80001F1C: nop

L_80001F20:
    // 0x80001F20: addiu       $s7, $zero, 0x9
    ctx->r23 = ADD32(0, 0X9);
    // 0x80001F24: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80001F28: b           L_80001F4C
    // 0x80001F2C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
        goto L_80001F4C;
    // 0x80001F2C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80001F30: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_80001F34:
    // 0x80001F34: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80001F38: b           L_80001F4C
    // 0x80001F3C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
        goto L_80001F4C;
    // 0x80001F3C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80001F40:
    // 0x80001F40: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x80001F44: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80001F48: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80001F4C:
    // 0x80001F4C: beq         $s2, $zero, L_8000205C
    if (ctx->r18 == 0) {
        // 0x80001F50: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8000205C;
    }
    // 0x80001F50: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80001F54: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80001F58: subu        $v0, $t6, $s4
    ctx->r2 = SUB32(ctx->r14, ctx->r20);
    // 0x80001F5C: sll         $v1, $a3, 4
    ctx->r3 = S32(ctx->r7 << 4);
    // 0x80001F60: bgez        $v0, L_80001F6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80001F64: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_80001F6C;
    }
    // 0x80001F64: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x80001F68: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
L_80001F6C:
    // 0x80001F6C: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
    // 0x80001F70: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80001F74: bne         $v1, $zero, L_80001FA8
    if (ctx->r3 != 0) {
        // 0x80001F78: nop
    
            goto L_80001FA8;
    }
    // 0x80001F78: nop

    // 0x80001F7C: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001F80: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x80001F84: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80001F88: mflo        $t7
    ctx->r15 = lo;
    // 0x80001F8C: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x80001F90: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x80001F94: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001F98: mflo        $s0
    ctx->r16 = lo;
    // 0x80001F9C: addiu       $s0, $s0, 0x1F
    ctx->r16 = ADD32(ctx->r16, 0X1F);
    // 0x80001FA0: b           L_8000200C
    // 0x80001FA4: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_8000200C;
    // 0x80001FA4: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80001FA8:
    // 0x80001FA8: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001FAC: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x80001FB0: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80001FB4: lw          $a2, 0x130($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X130);
    // 0x80001FB8: addiu       $a3, $t2, 0x1
    ctx->r7 = ADD32(ctx->r10, 0X1);
    // 0x80001FBC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80001FC0: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x80001FC4: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
    // 0x80001FC8: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x80001FCC: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x80001FD0: mflo        $t6
    ctx->r14 = lo;
    // 0x80001FD4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80001FD8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80001FDC: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001FE0: mflo        $s0
    ctx->r16 = lo;
    // 0x80001FE4: addiu       $s0, $s0, 0x1F
    ctx->r16 = ADD32(ctx->r16, 0X1F);
    // 0x80001FE8: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x80001FEC: jal         0x8000606C
    // 0x80001FF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000606C(rdram, ctx);
        goto after_1;
    // 0x80001FF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80001FF4: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x80001FF8: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80001FFC: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x80002000: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80002004: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80002008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8000200C:
    // 0x8000200C: sra         $t8, $s0, 4
    ctx->r24 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80002010: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80002014: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80002018: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x8000201C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80002020: addiu       $t8, $zero, 0x940
    ctx->r24 = ADD32(0, 0X940);
    // 0x80002024: subu        $t7, $t8, $s0
    ctx->r15 = SUB32(ctx->r24, ctx->r16);
    // 0x80002028: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8000202C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x80002030: andi        $t0, $a0, 0xF
    ctx->r8 = ctx->r4 & 0XF;
    // 0x80002034: subu        $t8, $a0, $t0
    ctx->r24 = SUB32(ctx->r4, ctx->r8);
    // 0x80002038: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8000203C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002040: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80002044: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80002048: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000204C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80002050: lbu         $a1, 0x0($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X0);
    // 0x80002054: b           L_80002064
    // 0x80002058: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
        goto L_80002064;
    // 0x80002058: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_8000205C:
    // 0x8000205C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80002060: lbu         $a1, 0x0($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X0);
L_80002064:
    // 0x80002064: beq         $a1, $zero, L_8000209C
    if (ctx->r5 == 0) {
        // 0x80002068: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_8000209C;
    }
    // 0x80002068: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8000206C: lui         $t6, 0xF00
    ctx->r14 = S32(0XF00 << 16);
    // 0x80002070: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80002074: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80002078: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000207C: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x80002080: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80002084: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80002088: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8000208C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80002090: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80002094: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x80002098: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
L_8000209C:
    // 0x8000209C: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x800020A0: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x800020A4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800020A8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800020AC: bne         $t3, $zero, L_800020BC
    if (ctx->r11 != 0) {
        // 0x800020B0: srl         $v0, $v0, 28
        ctx->r2 = S32(U32(ctx->r2) >> 28);
            goto L_800020BC;
    }
    // 0x800020B0: srl         $v0, $v0, 28
    ctx->r2 = S32(U32(ctx->r2) >> 28);
    // 0x800020B4: b           L_800020C4
    // 0x800020B8: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
        goto L_800020C4;
    // 0x800020B8: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
L_800020BC:
    // 0x800020BC: addiu       $s5, $s6, 0x1F
    ctx->r21 = ADD32(ctx->r22, 0X1F);
    // 0x800020C0: and         $s5, $s5, $at
    ctx->r21 = ctx->r21 & ctx->r1;
L_800020C4:
    // 0x800020C4: beq         $v0, $zero, L_800020E4
    if (ctx->r2 == 0) {
        // 0x800020C8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800020E4;
    }
    // 0x800020C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800020CC: beq         $v0, $at, L_800021F0
    if (ctx->r2 == ctx->r1) {
        // 0x800020D0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800021F0;
    }
    // 0x800020D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800020D4: beq         $v0, $at, L_80002168
    if (ctx->r2 == ctx->r1) {
        // 0x800020D8: nop
    
            goto L_80002168;
    }
    // 0x800020D8: nop

    // 0x800020DC: b           L_80002274
    // 0x800020E0: nop

        goto L_80002274;
    // 0x800020E0: nop

L_800020E4:
    // 0x800020E4: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800020E8: addiu       $t8, $zero, 0x940
    ctx->r24 = ADD32(0, 0X940);
    // 0x800020EC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800020F0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800020F4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800020F8: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800020FC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002100: mflo        $t9
    ctx->r25 = lo;
    // 0x80002104: addiu       $t6, $t9, 0x1F
    ctx->r14 = ADD32(ctx->r25, 0X1F);
    // 0x80002108: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x8000210C: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x80002110: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80002114: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x80002118: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8000211C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80002120: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80002124: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x80002128: addiu       $t7, $s5, 0x580
    ctx->r15 = ADD32(ctx->r21, 0X580);
    // 0x8000212C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80002130: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80002134: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80002138: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000213C: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x80002140: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80002144: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80002148: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8000214C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80002150: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80002154: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80002158: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000215C: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x80002160: b           L_80002274
    // 0x80002164: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80002274;
    // 0x80002164: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80002168:
    // 0x80002168: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000216C: addiu       $t9, $zero, 0x940
    ctx->r25 = ADD32(0, 0X940);
    // 0x80002170: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80002174: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80002178: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8000217C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80002180: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002184: mflo        $t8
    ctx->r24 = lo;
    // 0x80002188: addiu       $t7, $t8, 0x1F
    ctx->r15 = ADD32(ctx->r24, 0X1F);
    // 0x8000218C: andi        $t6, $t7, 0xFFF0
    ctx->r14 = ctx->r15 & 0XFFF0;
    // 0x80002190: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x80002194: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x80002198: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8000219C: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800021A0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800021A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800021A8: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x800021AC: addiu       $t6, $s5, 0x580
    ctx->r14 = ADD32(ctx->r21, 0X580);
    // 0x800021B0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800021B4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800021B8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800021BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800021C0: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x800021C4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800021C8: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x800021CC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800021D0: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800021D4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800021D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800021DC: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x800021E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800021E4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800021E8: b           L_80002274
    // 0x800021EC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80002274;
    // 0x800021EC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800021F0:
    // 0x800021F0: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800021F4: addiu       $t9, $zero, 0x940
    ctx->r25 = ADD32(0, 0X940);
    // 0x800021F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800021FC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002204: addiu       $a3, $s5, 0x580
    ctx->r7 = ADD32(ctx->r21, 0X580);
    // 0x80002208: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x8000220C: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
    // 0x80002210: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x80002214: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x80002218: mflo        $t6
    ctx->r14 = lo;
    // 0x8000221C: addiu       $t7, $t6, 0x1F
    ctx->r15 = ADD32(ctx->r14, 0X1F);
    // 0x80002220: andi        $t8, $t7, 0xFFF0
    ctx->r24 = ctx->r15 & 0XFFF0;
    // 0x80002224: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x80002228: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000222C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80002230: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x80002234: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80002238: jal         0x80000FF8
    // 0x8000223C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    func_80000FF8(rdram, ctx);
        goto after_2;
    // 0x8000223C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x80002240: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80002244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002248: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000224C: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x80002250: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002254: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80002258: jal         0x80001148
    // 0x8000225C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    func_80001148(rdram, ctx);
        goto after_3;
    // 0x8000225C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    after_3:
    // 0x80002260: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x80002264: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80002268: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8000226C: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80002270: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
L_80002274:
    // 0x80002274: beq         $t3, $zero, L_800022C4
    if (ctx->r11 == 0) {
        // 0x80002278: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800022C4;
    }
    // 0x80002278: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8000227C: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x80002280: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80002284: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80002288: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000228C: addiu       $t9, $t7, 0x580
    ctx->r25 = ADD32(ctx->r15, 0X580);
    // 0x80002290: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80002294: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80002298: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000229C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800022A0: addu        $t6, $s1, $fp
    ctx->r14 = ADD32(ctx->r17, ctx->r30);
    // 0x800022A4: addiu       $t9, $s6, 0x580
    ctx->r25 = ADD32(ctx->r22, 0X580);
    // 0x800022A8: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800022AC: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x800022B0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800022B4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800022B8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800022BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800022C0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_800022C4:
    // 0x800022C4: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x800022C8: addu        $t9, $s1, $fp
    ctx->r25 = ADD32(ctx->r17, ctx->r30);
    // 0x800022CC: subu        $v1, $t9, $t1
    ctx->r3 = SUB32(ctx->r25, ctx->r9);
    // 0x800022D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800022D4: beq         $t8, $at, L_800022F4
    if (ctx->r24 == ctx->r1) {
        // 0x800022D8: addu        $t3, $t3, $v1
        ctx->r11 = ADD32(ctx->r11, ctx->r3);
            goto L_800022F4;
    }
    // 0x800022D8: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x800022DC: xori        $v0, $t8, 0x2
    ctx->r2 = ctx->r24 ^ 0X2;
    // 0x800022E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800022E4: bne         $v0, $zero, L_8000230C
    if (ctx->r2 != 0) {
        // 0x800022E8: sw          $zero, 0x130($sp)
        MEM_W(0X130, ctx->r29) = 0;
            goto L_8000230C;
    }
    // 0x800022E8: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
    // 0x800022EC: b           L_80002318
    // 0x800022F0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
        goto L_80002318;
    // 0x800022F0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
L_800022F4:
    // 0x800022F4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800022F8: sll         $s6, $s1, 1
    ctx->r22 = S32(ctx->r17 << 1);
    // 0x800022FC: sw          $t6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r14;
    // 0x80002300: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    // 0x80002304: b           L_80002330
    // 0x80002308: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
        goto L_80002330;
    // 0x80002308: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
L_8000230C:
    // 0x8000230C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80002310: b           L_80002330
    // 0x80002314: addu        $s6, $t7, $s6
    ctx->r22 = ADD32(ctx->r15, ctx->r22);
        goto L_80002330;
    // 0x80002314: addu        $s6, $t7, $s6
    ctx->r22 = ADD32(ctx->r15, ctx->r22);
L_80002318:
    // 0x80002318: beql        $s6, $zero, L_8000232C
    if (ctx->r22 == 0) {
        // 0x8000231C: addu        $s6, $s4, $v1
        ctx->r22 = ADD32(ctx->r20, ctx->r3);
            goto L_8000232C;
    }
    goto skip_7;
    // 0x8000231C: addu        $s6, $s4, $v1
    ctx->r22 = ADD32(ctx->r20, ctx->r3);
    skip_7:
    // 0x80002320: b           L_80002330
    // 0x80002324: addu        $s6, $t9, $s6
    ctx->r22 = ADD32(ctx->r25, ctx->r22);
        goto L_80002330;
    // 0x80002324: addu        $s6, $t9, $s6
    ctx->r22 = ADD32(ctx->r25, ctx->r22);
    // 0x80002328: addu        $s6, $s4, $v1
    ctx->r22 = ADD32(ctx->r20, ctx->r3);
L_8000232C:
    // 0x8000232C: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
L_80002330:
    // 0x80002330: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x80002334: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x80002338: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8000233C: beq         $t8, $zero, L_800023A4
    if (ctx->r24 == 0) {
        // 0x80002340: nop
    
            goto L_800023A4;
    }
    // 0x80002340: nop

    // 0x80002344: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80002348: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000234C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002350: subu        $a2, $t6, $t3
    ctx->r6 = SUB32(ctx->r14, ctx->r11);
    // 0x80002354: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80002358: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x8000235C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002360: addiu       $a1, $s6, 0x580
    ctx->r5 = ADD32(ctx->r22, 0X580);
    // 0x80002364: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x80002368: jal         0x80000FA0
    // 0x8000236C: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    func_80000FA0(rdram, ctx);
        goto after_4;
    // 0x8000236C: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    after_4:
    // 0x80002370: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80002374: lbu         $t8, 0xB0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XB0);
    // 0x80002378: ori         $t6, $t8, 0x20
    ctx->r14 = ctx->r24 | 0X20;
    // 0x8000237C: sb          $t6, 0xB0($v0)
    MEM_B(0XB0, ctx->r2) = ctx->r14;
    // 0x80002380: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80002384: jal         0x800009AC
    // 0x80002388: lw          $a0, 0x170($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X170);
    func_800009AC(rdram, ctx);
        goto after_5;
    // 0x80002388: lw          $a0, 0x170($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X170);
    after_5:
    // 0x8000238C: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80002390: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80002394: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80002398: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8000239C: b           L_800023E4
    // 0x800023A0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
        goto L_800023E4;
    // 0x800023A0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
L_800023A4:
    // 0x800023A4: beql        $t7, $zero, L_800023C8
    if (ctx->r15 == 0) {
        // 0x800023A8: lw          $t7, 0x8($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X8);
            goto L_800023C8;
    }
    goto skip_8;
    // 0x800023A8: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    skip_8:
    // 0x800023AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800023B0: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x800023B4: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x800023B8: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800023BC: b           L_800023D0
    // 0x800023C0: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
        goto L_800023D0;
    // 0x800023C0: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x800023C4: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
L_800023C8:
    // 0x800023C8: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800023CC: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
L_800023D0:
    // 0x800023D0: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x800023D4: bnel        $t3, $t6, L_80001E28
    if (ctx->r11 != ctx->r14) {
        // 0x800023D8: lw          $t8, 0x100($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X100);
            goto L_80001E28;
    }
    goto skip_9;
    // 0x800023D8: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    skip_9:
    // 0x800023DC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800023E0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
L_800023E4:
    // 0x800023E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800023E8:
    // 0x800023E8: beq         $v1, $at, L_80002404
    if (ctx->r3 == ctx->r1) {
        // 0x800023EC: lw          $t7, 0x118($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X118);
            goto L_80002404;
    }
    // 0x800023EC: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x800023F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800023F4: beq         $v1, $at, L_80002410
    if (ctx->r3 == ctx->r1) {
        // 0x800023F8: lw          $t8, 0xB4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB4);
            goto L_80002410;
    }
    // 0x800023F8: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x800023FC: b           L_80002518
    // 0x80002400: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
        goto L_80002518;
    // 0x80002400: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
L_80002404:
    // 0x80002404: addiu       $t9, $t7, 0x580
    ctx->r25 = ADD32(ctx->r15, 0X580);
    // 0x80002408: b           L_80002514
    // 0x8000240C: sh          $t9, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r25;
        goto L_80002514;
    // 0x8000240C: sh          $t9, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r25;
L_80002410:
    // 0x80002410: beq         $t8, $zero, L_8000242C
    if (ctx->r24 == 0) {
        // 0x80002414: lw          $a1, 0x118($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X118);
            goto L_8000242C;
    }
    // 0x80002414: lw          $a1, 0x118($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X118);
    // 0x80002418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000241C: beq         $t8, $at, L_800024C0
    if (ctx->r24 == ctx->r1) {
        // 0x80002420: lw          $a1, 0x118($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X118);
            goto L_800024C0;
    }
    // 0x80002420: lw          $a1, 0x118($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X118);
    // 0x80002424: b           L_80002518
    // 0x80002428: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
        goto L_80002518;
    // 0x80002428: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
L_8000242C:
    // 0x8000242C: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x80002430: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002434: addiu       $t6, $zero, 0x3E0
    ctx->r14 = ADD32(0, 0X3E0);
    // 0x80002438: sh          $t6, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r14;
    // 0x8000243C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002440: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80002444: addiu       $a2, $zero, 0x3E0
    ctx->r6 = ADD32(0, 0X3E0);
    // 0x80002448: bgez        $a3, L_80002454
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8000244C: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_80002454;
    }
    // 0x8000244C: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x80002450: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
L_80002454:
    // 0x80002454: sra         $a3, $at, 1
    ctx->r7 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80002458: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8000245C: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x80002460: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    // 0x80002464: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x80002468: jal         0x80001064
    // 0x8000246C: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    func_80001064(rdram, ctx);
        goto after_6;
    // 0x8000246C: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    after_6:
    // 0x80002470: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80002474: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80002478: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x8000247C: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80002480: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80002484: beq         $t9, $zero, L_800024B4
    if (ctx->r25 == 0) {
        // 0x80002488: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_800024B4;
    }
    // 0x80002488: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x8000248C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002490: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002494: addiu       $a1, $t7, 0x3E0
    ctx->r5 = ADD32(ctx->r15, 0X3E0);
    // 0x80002498: addiu       $a2, $t7, 0x10
    ctx->r6 = ADD32(ctx->r15, 0X10);
    // 0x8000249C: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800024A0: jal         0x80000FA0
    // 0x800024A4: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    func_80000FA0(rdram, ctx);
        goto after_7;
    // 0x800024A4: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    after_7:
    // 0x800024A8: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x800024AC: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800024B0: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
L_800024B4:
    // 0x800024B4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800024B8: b           L_80002514
    // 0x800024BC: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
        goto L_80002514;
    // 0x800024BC: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
L_800024C0:
    // 0x800024C0: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x800024C4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800024C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800024CC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800024D0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800024D4: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800024D8: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800024DC: addiu       $a2, $a2, 0x3E0
    ctx->r6 = ADD32(ctx->r6, 0X3E0);
    // 0x800024E0: bgez        $a3, L_800024EC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800024E4: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_800024EC;
    }
    // 0x800024E4: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x800024E8: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
L_800024EC:
    // 0x800024EC: sra         $a3, $at, 1
    ctx->r7 = S32(SIGNED(ctx->r1) >> 1);
    // 0x800024F0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800024F4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    // 0x800024F8: jal         0x80001064
    // 0x800024FC: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    func_80001064(rdram, ctx);
        goto after_8;
    // 0x800024FC: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    after_8:
    // 0x80002500: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x80002504: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80002508: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x8000250C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80002510: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
L_80002514:
    // 0x80002514: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
L_80002518:
    // 0x80002518: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8000251C: beq         $t8, $zero, L_8000253C
    if (ctx->r24 == 0) {
        // 0x80002520: addiu       $t7, $t9, 0x1
        ctx->r15 = ADD32(ctx->r25, 0X1);
            goto L_8000253C;
    }
    // 0x80002520: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80002524: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x80002528: lw          $s0, 0x160($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X160);
    // 0x8000252C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80002530: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80002534: b           L_80002564
    // 0x80002538: sw          $s3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r19;
        goto L_80002564;
    // 0x80002538: sw          $s3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r19;
L_8000253C:
    // 0x8000253C: bne         $t7, $v1, L_80001D04
    if (ctx->r15 != ctx->r3) {
        // 0x80002540: sw          $t7, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r15;
            goto L_80001D04;
    }
    // 0x80002540: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80002544: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x80002548: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x8000254C: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x80002550: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x80002554: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80002558: sw          $s3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r19;
    // 0x8000255C: lw          $s0, 0x160($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X160);
    // 0x80002560: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80002564:
    // 0x80002564: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80002568: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x8000256C: lw          $s3, 0x16C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X16C);
    // 0x80002570: bne         $t2, $t9, L_80002588
    if (ctx->r10 != ctx->r25) {
        // 0x80002574: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80002588;
    }
    // 0x80002574: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80002578: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x8000257C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002580: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80002584: sb          $t8, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r24;
L_80002588:
    // 0x80002588: lw          $s1, 0x168($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X168);
    // 0x8000258C: lhu         $t6, 0xA6($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XA6);
    // 0x80002590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002594: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80002598: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000259C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800025A0: lhu         $a3, 0x12E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X12E);
    // 0x800025A4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800025A8: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800025AC: sw          $s0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r16;
    // 0x800025B0: sw          $s2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r18;
    // 0x800025B4: jal         0x80002770
    // 0x800025B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80002770(rdram, ctx);
        goto after_9;
    // 0x800025B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_9:
    // 0x800025BC: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800025C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800025C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800025C8: bne         $t9, $at, L_800025E8
    if (ctx->r25 != ctx->r1) {
        // 0x800025CC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800025E8;
    }
    // 0x800025CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800025D0: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x800025D4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x800025D8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800025DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800025E0: jal         0x80001198
    // 0x800025E4: addiu       $s3, $v0, 0x8
    ctx->r19 = ADD32(ctx->r2, 0X8);
    func_80001198(rdram, ctx);
        goto after_10;
    // 0x800025E4: addiu       $s3, $v0, 0x8
    ctx->r19 = ADD32(ctx->r2, 0X8);
    after_10:
L_800025E8:
    // 0x800025E8: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800025EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800025F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800025F4: bne         $t7, $at, L_8000260C
    if (ctx->r15 != ctx->r1) {
        // 0x800025F8: addiu       $a1, $zero, 0x3C0
        ctx->r5 = ADD32(0, 0X3C0);
            goto L_8000260C;
    }
    // 0x800025F8: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x800025FC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80002600: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80002604: jal         0x800011EC
    // 0x80002608: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    func_800011EC(rdram, ctx);
        goto after_11;
    // 0x80002608: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_11:
L_8000260C:
    // 0x8000260C: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x80002610: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002614: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80002618: lbu         $a1, 0x2($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X2);
    // 0x8000261C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80002620: addiu       $t8, $s1, 0x20
    ctx->r24 = ADD32(ctx->r17, 0X20);
    // 0x80002624: beq         $a1, $zero, L_80002644
    if (ctx->r5 == 0) {
        // 0x80002628: slti        $at, $a1, 0x10
        ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
            goto L_80002644;
    }
    // 0x80002628: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8000262C: beq         $at, $zero, L_80002638
    if (ctx->r1 == 0) {
        // 0x80002630: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_80002638;
    }
    // 0x80002630: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80002634: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_80002638:
    // 0x80002638: jal         0x80001164
    // 0x8000263C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80001164(rdram, ctx);
        goto after_12;
    // 0x8000263C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_12:
    // 0x80002640: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
L_80002644:
    // 0x80002644: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x80002648: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000264C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002650: beq         $v0, $zero, L_80002684
    if (ctx->r2 == 0) {
        // 0x80002654: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80002684;
    }
    // 0x80002654: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80002658: jal         0x8000124C
    // 0x8000265C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    func_8000124C(rdram, ctx);
        goto after_13;
    // 0x8000265C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_13:
    // 0x80002660: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x80002664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002668: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8000266C: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x80002670: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80002674: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80002678: jal         0x80001228
    // 0x8000267C: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    func_80001228(rdram, ctx);
        goto after_14;
    // 0x8000267C: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    after_14:
    // 0x80002680: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
L_80002684:
    // 0x80002684: lbu         $t9, 0x3($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X3);
    // 0x80002688: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000268C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80002690: bne         $t9, $zero, L_800026A8
    if (ctx->r25 != 0) {
        // 0x80002694: lw          $a3, 0x168($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X168);
            goto L_800026A8;
    }
    // 0x80002694: lw          $a3, 0x168($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X168);
    // 0x80002698: lw          $a2, 0x160($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X160);
    // 0x8000269C: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    // 0x800026A0: beql        $t7, $zero, L_800026B8
    if (ctx->r15 == 0) {
        // 0x800026A4: lbu         $t8, 0x4($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X4);
            goto L_800026B8;
    }
    goto skip_10;
    // 0x800026A4: lbu         $t8, 0x4($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X4);
    skip_10:
L_800026A8:
    // 0x800026A8: lw          $a2, 0x160($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X160);
    // 0x800026AC: b           L_800026D8
    // 0x800026B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800026D8;
    // 0x800026B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800026B4: lbu         $t8, 0x4($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X4);
L_800026B8:
    // 0x800026B8: bne         $t8, $zero, L_800026D0
    if (ctx->r24 != 0) {
        // 0x800026BC: nop
    
            goto L_800026D0;
    }
    // 0x800026BC: nop

    // 0x800026C0: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x800026C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800026C8: beq         $t6, $zero, L_800026D8
    if (ctx->r14 == 0) {
        // 0x800026CC: nop
    
            goto L_800026D8;
    }
    // 0x800026CC: nop

L_800026D0:
    // 0x800026D0: b           L_800026D8
    // 0x800026D4: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_800026D8;
    // 0x800026D4: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_800026D8:
    // 0x800026D8: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x800026DC: addiu       $t9, $zero, 0x3C0
    ctx->r25 = ADD32(0, 0X3C0);
    // 0x800026E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800026E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800026E8: jal         0x80002818
    // 0x800026EC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80002818(rdram, ctx);
        goto after_15;
    // 0x800026EC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_15:
    // 0x800026F0: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800026F4: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x800026F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800026FC: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x80002700: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002704: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80002708: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x8000270C: beq         $t9, $zero, L_8000273C
    if (ctx->r25 == 0) {
        // 0x80002710: andi        $t8, $t7, 0x1
        ctx->r24 = ctx->r15 & 0X1;
            goto L_8000273C;
    }
    // 0x80002710: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80002714: bnel        $t8, $zero, L_80002724
    if (ctx->r24 != 0) {
        // 0x80002718: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_80002724;
    }
    goto skip_11;
    // 0x80002718: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    skip_11:
    // 0x8000271C: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
    // 0x80002720: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
L_80002724:
    // 0x80002724: lw          $a1, 0x15C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X15C);
    // 0x80002728: lw          $a2, 0x160($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X160);
    // 0x8000272C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002730: jal         0x80002D0C
    // 0x80002734: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80002D0C(rdram, ctx);
        goto after_16;
    // 0x80002734: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_16:
    // 0x80002738: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8000273C:
    // 0x8000273C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80002740: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80002744: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80002748: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000274C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80002750: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80002754: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80002758: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000275C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80002760: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80002764: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80002768: jr          $ra
    // 0x8000276C: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x8000276C: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_8044D410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D410: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044D414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D418: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044D41C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044D420: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8044D424: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044D428: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D42C: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044D430: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044D434: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D438: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8044D43C: beq         $t7, $zero, L_8044D480
    if (ctx->r15 == 0) {
        // 0x8044D440: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8044D480;
    }
    // 0x8044D440: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8044D444: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8044D448: lw          $t3, 0xA54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA54);
    // 0x8044D44C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044D450: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x8044D454: addu        $a1, $t1, $a1
    ctx->r5 = ADD32(ctx->r9, ctx->r5);
    // 0x8044D458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D45C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8044D460: jal         0x8044D1F4
    // 0x8044D464: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D464: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x8044D468: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044D46C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8044D470: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8044D474: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8044D478: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x8044D47C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8044D480:
    // 0x8044D480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D484: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044D488: jr          $ra
    // 0x8044D48C: nop

    return;
    // 0x8044D48C: nop

;}
RECOMP_FUNC void func_80671FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671FA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80671FA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80671FA8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80671FAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80671FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80671FB4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671FB8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80671FBC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80671FC0: jal         0x80671D4C
    // 0x80671FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80671FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80671FC8: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x80671FCC: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x80671FD0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80671FD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80671FD8: blez        $t7, L_80672008
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80671FDC: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80672008;
    }
    // 0x80671FDC: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80671FE0: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80671FE4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80671FE8: jal         0x80671954
    // 0x80671FEC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x80671FEC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_1:
    // 0x80671FF0: beq         $v0, $zero, L_80671FFC
    if (ctx->r2 == 0) {
        // 0x80671FF4: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_80671FFC;
    }
    // 0x80671FF4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80671FF8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80671FFC:
    // 0x80671FFC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80672000: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80672004: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80672008:
    // 0x80672008: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8067200C: beq         $at, $zero, L_80672020
    if (ctx->r1 == 0) {
        // 0x80672010: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80672020;
    }
    // 0x80672010: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80672014: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672018: jal         0x80671C98
    // 0x8067201C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x8067201C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_2:
L_80672020:
    // 0x80672020: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80672024: bne         $at, $zero, L_80672040
    if (ctx->r1 != 0) {
        // 0x80672028: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80672040;
    }
    // 0x80672028: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8067202C: jal         0x80672C80
    // 0x80672030: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80672030: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80672034: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80672038: jal         0x80067818
    // 0x8067203C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067203C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80672040:
    // 0x80672040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80672044: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80672048: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8067204C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80672050: jr          $ra
    // 0x80672054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80672054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80445C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C74: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80445C78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C7C: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x80445C80: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C84: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80445C88: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x80445C8C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C90: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80445C94: jr          $ra
    // 0x80445C98: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    return;
    // 0x80445C98: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_806E7F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7F5C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806E7F60: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x806E7F64: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x806E7F68: bne         $at, $zero, L_806E7F78
    if (ctx->r1 != 0) {
        // 0x806E7F6C: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_806E7F78;
    }
    // 0x806E7F6C: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x806E7F70: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E7F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E7F78:
    // 0x806E7F78: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x806E7F7C: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x806E7F80: andi        $v1, $v1, 0x6
    ctx->r3 = ctx->r3 & 0X6;
    // 0x806E7F84: beq         $a1, $zero, L_806E7FC8
    if (ctx->r5 == 0) {
        // 0x806E7F88: lui         $v0, 0x806F
        ctx->r2 = S32(RELOC_HI16(664, 0XE80) << 16);
            goto L_806E7FC8;
    }
    // 0x806E7F88: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(664, 0XE80) << 16);
    // 0x806E7F8C: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(664, 0XE80) << 16);
    // 0x806E7F90: addiu       $v0, $v0, -0x7F40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0XE80));
    // 0x806E7F94: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x806E7F98: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806E7F9C: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x806E7FA0: lwc1        $f6, 0x6C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x806E7FA4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x806E7FA8: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x806E7FAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806E7FB0: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x806E7FB4: lwc1        $f16, 0x70($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X70);
    // 0x806E7FB8: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x806E7FBC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806E7FC0: jr          $ra
    // 0x806E7FC4: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806E7FC4: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
L_806E7FC8:
    // 0x806E7FC8: addiu       $v0, $v0, -0x7F40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0XE80));
    // 0x806E7FCC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x806E7FD0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x806E7FD4: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x806E7FD8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x806E7FDC: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x806E7FE0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x806E7FE4: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x806E7FE8: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x806E7FEC: jr          $ra
    // 0x806E7FF0: nop

    return;
    // 0x806E7FF0: nop

;}
RECOMP_FUNC void func_8040D380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D380: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8040D384: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040D388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D390: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8040D394: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040D398: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040D39C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8040D3A0: bc1fl       L_8040D3B8
    if (!c1cs) {
        // 0x8040D3A4: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8040D3B8;
    }
    goto skip_0;
    // 0x8040D3A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8040D3A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040D3AC: b           L_8040D400
    // 0x8040D3B0: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
        goto L_8040D400;
    // 0x8040D3B0: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
    // 0x8040D3B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8040D3B8:
    // 0x8040D3B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8040D3BC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8040D3C0: nop

    // 0x8040D3C4: bc1fl       L_8040D404
    if (!c1cs) {
        // 0x8040D3C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040D404;
    }
    goto skip_1;
    // 0x8040D3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040D3CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040D3D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040D3D4: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
    // 0x8040D3D8: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x8040D3DC: lbu         $t6, 0x165($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X165);
    // 0x8040D3E0: beql        $v0, $t6, L_8040D404
    if (ctx->r2 == ctx->r14) {
        // 0x8040D3E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040D404;
    }
    goto skip_2;
    // 0x8040D3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8040D3E8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8040D3EC: jal         0x80067BBC
    // 0x8040D3F0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040D3F0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8040D3F4: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8040D3F8: jal         0x80067818
    // 0x8040D3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8040D3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
L_8040D400:
    // 0x8040D400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040D404:
    // 0x8040D404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D408: jr          $ra
    // 0x8040D40C: nop

    return;
    // 0x8040D40C: nop

;}
RECOMP_FUNC void func_805E48B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E48B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E48B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E48BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E48C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E48C4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E48C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805E48CC: jal         0x805E4378
    // 0x805E48D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E48D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x805E48D4: jal         0x805E478C
    // 0x805E48D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E478C(rdram, ctx);
        goto after_1;
    // 0x805E48D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E48DC: jal         0x805E4460
    // 0x805E48E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_2;
    // 0x805E48E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805E48E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805E48E8: bne         $v0, $at, L_805E4904
    if (ctx->r2 != ctx->r1) {
        // 0x805E48EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805E4904;
    }
    // 0x805E48EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E48F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x805E48F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E48F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805E48FC: jal         0x805E4D78
    // 0x805E4900: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_805E4D78(rdram, ctx);
        goto after_3;
    // 0x805E4900: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_3:
L_805E4904:
    // 0x805E4904: jal         0x805E4674
    // 0x805E4908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_4;
    // 0x805E4908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805E490C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4910: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4914: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E4918: jr          $ra
    // 0x805E491C: nop

    return;
    // 0x805E491C: nop

;}
RECOMP_FUNC void func_8005DA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DA78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005DA7C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8005DA80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005DA84: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8005DA88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005DA8C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8005DA90: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005DA94: lw          $t7, 0x6348($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6348);
    // 0x8005DA98: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8005DA9C: jr          $ra
    // 0x8005DAA0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8005DAA0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80536114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536114: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536118: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053611C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536120: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536124: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053612C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536130: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536134: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536138: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053613C: jr          $ra
    // 0x80536140: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536140: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80031424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003142C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031430: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031438: jal         0x80041D3C
    // 0x8003143C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_80041D3C(rdram, ctx);
        goto after_0;
    // 0x8003143C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80031440: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x80031444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031448: beql        $t6, $zero, L_80031474
    if (ctx->r14 == 0) {
        // 0x8003144C: lw          $t7, 0xC0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XC0);
            goto L_80031474;
    }
    goto skip_0;
    // 0x8003144C: lw          $t7, 0xC0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC0);
    skip_0:
    // 0x80031450: jal         0x800421B4
    // 0x80031454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800421B4(rdram, ctx);
        goto after_1;
    // 0x80031454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80031458: beql        $v0, $zero, L_800314A4
    if (ctx->r2 == 0) {
        // 0x8003145C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800314A4;
    }
    goto skip_1;
    // 0x8003145C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80031460: jal         0x8001EA24
    // 0x80031464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001EA24(rdram, ctx);
        goto after_2;
    // 0x80031464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80031468: b           L_80031494
    // 0x8003146C: nop

        goto L_80031494;
    // 0x8003146C: nop

    // 0x80031470: lw          $t7, 0xC0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC0);
L_80031474:
    // 0x80031474: beq         $t7, $zero, L_8003148C
    if (ctx->r15 == 0) {
        // 0x80031478: nop
    
            goto L_8003148C;
    }
    // 0x80031478: nop

    // 0x8003147C: jal         0x80021A44
    // 0x80031480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_3;
    // 0x80031480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80031484: b           L_80031494
    // 0x80031488: nop

        goto L_80031494;
    // 0x80031488: nop

L_8003148C:
    // 0x8003148C: jal         0x8001EA24
    // 0x80031490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001EA24(rdram, ctx);
        goto after_4;
    // 0x80031490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80031494:
    // 0x80031494: jal         0x80028220
    // 0x80031498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_5;
    // 0x80031498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003149C: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
    // 0x800314A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800314A4:
    // 0x800314A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800314A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800314AC: jr          $ra
    // 0x800314B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800314B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80440950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80440950: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80440954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80440958: jal         0x8004700C
    // 0x8044095C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044095C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80440960: bne         $v0, $zero, L_80440970
    if (ctx->r2 != 0) {
        // 0x80440964: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80440970;
    }
    // 0x80440964: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80440968: b           L_804409E8
    // 0x8044096C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804409E8;
    // 0x8044096C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80440970:
    // 0x80440970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80440974: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80440978: bnel        $v0, $zero, L_8044098C
    if (ctx->r2 != 0) {
        // 0x8044097C: lwc1        $f4, 0x84($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
            goto L_8044098C;
    }
    goto skip_0;
    // 0x8044097C: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    skip_0:
    // 0x80440980: b           L_804409E8
    // 0x80440984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804409E8;
    // 0x80440984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80440988: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
L_8044098C:
    // 0x8044098C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80440990: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80440994: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80440998: jal         0x804406D0
    // 0x8044099C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_804406D0(rdram, ctx);
        goto after_1;
    // 0x8044099C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x804409A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804409A4: beq         $v0, $zero, L_804409E4
    if (ctx->r2 == 0) {
        // 0x804409A8: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_804409E4;
    }
    // 0x804409A8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804409AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804409B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x804409B4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x804409B8: nop

    // 0x804409BC: bc1fl       L_804409E8
    if (!c1cs) {
        // 0x804409C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804409E8;
    }
    goto skip_1;
    // 0x804409C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x804409C4: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804409C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804409CC: lw          $t8, 0x2630($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2630);
    // 0x804409D0: beql        $t8, $zero, L_804409E8
    if (ctx->r24 == 0) {
        // 0x804409D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804409E8;
    }
    goto skip_2;
    // 0x804409D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x804409D8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x804409DC: b           L_804409E8
    // 0x804409E0: swc1        $f10, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = ctx->f10.u32l;
        goto L_804409E8;
    // 0x804409E0: swc1        $f10, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = ctx->f10.u32l;
L_804409E4:
    // 0x804409E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804409E8:
    // 0x804409E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804409EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804409F0: jr          $ra
    // 0x804409F4: nop

    return;
    // 0x804409F4: nop

;}
RECOMP_FUNC void func_80067F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067F7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80067F80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80067F84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80067F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067F8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80067F90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80067F94: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
L_80067F98:
    // 0x80067F98: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80067F9C: jal         0x80067930
    // 0x80067FA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80067FA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80067FA4: bne         $v0, $zero, L_80067FC4
    if (ctx->r2 != 0) {
        // 0x80067FA8: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_80067FC4;
    }
    // 0x80067FA8: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80067FAC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80067FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80067FB4: jal         0x80067838
    // 0x80067FB8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80067838(rdram, ctx);
        goto after_1;
    // 0x80067FB8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80067FBC: b           L_80067FE0
    // 0x80067FC0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80067FE0;
    // 0x80067FC0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80067FC4:
    // 0x80067FC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80067FC8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80067FCC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80067FD0: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80067FD4: bnel        $at, $zero, L_80067F98
    if (ctx->r1 != 0) {
        // 0x80067FD8: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_80067F98;
    }
    goto skip_0;
    // 0x80067FD8: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    skip_0:
    // 0x80067FDC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80067FE0:
    // 0x80067FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067FE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80067FE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80067FEC: jr          $ra
    // 0x80067FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000A7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A7CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000A7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A7D4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000A7D8: addiu       $a0, $a0, 0x60A4
    ctx->r4 = ADD32(ctx->r4, 0X60A4);
    // 0x8000A7DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8000A7E0: jal         0x800824B0
    // 0x8000A7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000A7E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A7EC: bne         $v0, $at, L_8000A800
    if (ctx->r2 != ctx->r1) {
        // 0x8000A7F0: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8000A800;
    }
    // 0x8000A7F0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8000A7F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A7F8: b           L_8000A81C
    // 0x8000A7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A81C;
    // 0x8000A7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A800:
    // 0x8000A800: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A804: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000A808: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000A80C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000A810: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A814: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A818: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
L_8000A81C:
    // 0x8000A81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A824: jr          $ra
    // 0x8000A828: nop

    return;
    // 0x8000A828: nop

;}
RECOMP_FUNC void func_8053484C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053484C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80534850: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534854: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80534858: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8053485C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80534860: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1080) << 16);
    // 0x80534864: lwc1        $f18, 0x5690($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1080));
    // 0x80534868: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8053486C: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80534870: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1084) << 16);
    // 0x80534874: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80534878: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8053487C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80534880: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80534884: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80534888: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8053488C: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80534890: lwc1        $f16, 0x5694($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1084));
    // 0x80534894: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80534898: swc1        $f18, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f18.u32l;
    // 0x8053489C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805348A0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x805348A4: nop

    // 0x805348A8: bc1fl       L_805348BC
    if (!c1cs) {
        // 0x805348AC: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_805348BC;
    }
    goto skip_0;
    // 0x805348AC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    skip_0:
    // 0x805348B0: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x805348B4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x805348B8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
L_805348BC:
    // 0x805348BC: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x805348C0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805348C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x805348C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805348CC: nop

    // 0x805348D0: bc1f        L_805348DC
    if (!c1cs) {
        // 0x805348D4: nop
    
            goto L_805348DC;
    }
    // 0x805348D4: nop

    // 0x805348D8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_805348DC:
    // 0x805348DC: jr          $ra
    // 0x805348E0: nop

    return;
    // 0x805348E0: nop

;}
RECOMP_FUNC void func_800335B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800335B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800335B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800335B8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800335BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800335C0: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x800335C4: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x800335C8: beq         $t7, $zero, L_80033644
    if (ctx->r15 == 0) {
        // 0x800335CC: nop
    
            goto L_80033644;
    }
    // 0x800335CC: nop

    // 0x800335D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800335D4: lwc1        $f4, 0x58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58);
    // 0x800335D8: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800335DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800335E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800335E4: nop

    // 0x800335E8: bc1t        L_80033634
    if (c1cs) {
        // 0x800335EC: nop
    
            goto L_80033634;
    }
    // 0x800335EC: nop

    // 0x800335F0: lwc1        $f6, 0x5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5C);
    // 0x800335F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800335F8: nop

    // 0x800335FC: bc1t        L_80033634
    if (c1cs) {
        // 0x80033600: nop
    
            goto L_80033634;
    }
    // 0x80033600: nop

    // 0x80033604: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80033608: jal         0x8002D958
    // 0x8003360C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8002D958(rdram, ctx);
        goto after_0;
    // 0x8003360C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033610: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80033614: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033618: lwc1        $f10, 0x68($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X68);
    // 0x8003361C: lwc1        $f8, 0x120($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X120);
    // 0x80033620: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80033624: jal         0x800331A4
    // 0x80033628: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    func_800331A4(rdram, ctx);
        goto after_1;
    // 0x80033628: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    after_1:
    // 0x8003362C: b           L_80033698
    // 0x80033630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033698;
    // 0x80033630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033634:
    // 0x80033634: jal         0x8002D9F4
    // 0x80033638: nop

    func_8002D9F4(rdram, ctx);
        goto after_2;
    // 0x80033638: nop

    after_2:
    // 0x8003363C: b           L_80033698
    // 0x80033640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033698;
    // 0x80033640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033644:
    // 0x80033644: lwc1        $f18, -0x7674($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7674);
    // 0x80033648: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003364C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033650: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80033654: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80033658: nop

    // 0x8003365C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80033660: jal         0x80032F9C
    // 0x80033664: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80032F9C(rdram, ctx);
        goto after_3;
    // 0x80033664: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x80033668: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003366C: beq         $v0, $zero, L_80033694
    if (ctx->r2 == 0) {
        // 0x80033670: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80033694;
    }
    // 0x80033670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033674: lw          $t9, 0x198($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X198);
    // 0x80033678: sltiu       $at, $t9, 0x28
    ctx->r1 = ctx->r25 < 0X28 ? 1 : 0;
    // 0x8003367C: bnel        $at, $zero, L_80033698
    if (ctx->r1 != 0) {
        // 0x80033680: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80033698;
    }
    goto skip_0;
    // 0x80033680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80033684: jal         0x8002DA50
    // 0x80033688: nop

    func_8002DA50(rdram, ctx);
        goto after_4;
    // 0x80033688: nop

    after_4:
    // 0x8003368C: b           L_80033698
    // 0x80033690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033698;
    // 0x80033690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033694:
    // 0x80033694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033698:
    // 0x80033698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003369C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800336A0: jr          $ra
    // 0x800336A4: nop

    return;
    // 0x800336A4: nop

;}
RECOMP_FUNC void func_80519010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80519018: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8051901C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80519020: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(291, 0X2540) << 16);
    // 0x80519024: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80519028: lw          $v0, -0x5E50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(291, 0X2540));
    // 0x8051902C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519030: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80519034: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80519038: beql        $v1, $zero, L_8051906C
    if (ctx->r3 == 0) {
        // 0x8051903C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051906C;
    }
    goto skip_0;
    // 0x8051903C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80519040: jalr        $v1
    // 0x80519044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80519044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051904C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80519050: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x80519054: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80519058: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8051905C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80519060: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80519064: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x80519068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051906C:
    // 0x8051906C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519070: jr          $ra
    // 0x80519074: nop

    return;
    // 0x80519074: nop

;}
RECOMP_FUNC void func_80472440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472440: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80472444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80472448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8047244C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80472450: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x80472454: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80472458: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8047245C: beq         $t6, $zero, L_80472638
    if (ctx->r14 == 0) {
        // 0x80472460: nop
    
            goto L_80472638;
    }
    // 0x80472460: nop

    // 0x80472464: lw          $v0, 0x7EA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EA8);
    // 0x80472468: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8047246C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80472470: lb          $t7, 0x2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2);
    // 0x80472474: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80472478: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8047247C: lb          $t8, 0x3($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3);
    // 0x80472480: jal         0x804723C4
    // 0x80472484: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    func_804723C4(rdram, ctx);
        goto after_0;
    // 0x80472484: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    after_0:
    // 0x80472488: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8047248C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80472490: jal         0x804723C4
    // 0x80472494: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_804723C4(rdram, ctx);
        goto after_1;
    // 0x80472494: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_1:
    // 0x80472498: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8047249C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x804724A0: bne         $t9, $zero, L_8047250C
    if (ctx->r25 != 0) {
        // 0x804724A4: nop
    
            goto L_8047250C;
    }
    // 0x804724A4: nop

    // 0x804724A8: bne         $t0, $zero, L_8047250C
    if (ctx->r8 != 0) {
        // 0x804724AC: nop
    
            goto L_8047250C;
    }
    // 0x804724AC: nop

    // 0x804724B0: jal         0x804715A4
    // 0x804724B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_804715A4(rdram, ctx);
        goto after_2;
    // 0x804724B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x804724B8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804724BC: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804724C0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x804724C4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x804724C8: nop

    // 0x804724CC: bc1f        L_804724FC
    if (!c1cs) {
        // 0x804724D0: nop
    
            goto L_804724FC;
    }
    // 0x804724D0: nop

    // 0x804724D4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804724D8: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x804724DC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x804724E0: nop

    // 0x804724E4: bc1f        L_804724FC
    if (!c1cs) {
        // 0x804724E8: nop
    
            goto L_804724FC;
    }
    // 0x804724E8: nop

    // 0x804724EC: jal         0x80471660
    // 0x804724F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80471660(rdram, ctx);
        goto after_3;
    // 0x804724F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x804724F4: b           L_80472524
    // 0x804724F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
        goto L_80472524;
    // 0x804724F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_804724FC:
    // 0x804724FC: jal         0x804715E4
    // 0x80472500: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_804715E4(rdram, ctx);
        goto after_4;
    // 0x80472500: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_4:
    // 0x80472504: b           L_80472524
    // 0x80472508: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
        goto L_80472524;
    // 0x80472508: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_8047250C:
    // 0x8047250C: jal         0x80471660
    // 0x80472510: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80471660(rdram, ctx);
        goto after_5;
    // 0x80472510: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x80472514: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80472518: jal         0x80471530
    // 0x8047251C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_80471530(rdram, ctx);
        goto after_6;
    // 0x8047251C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_6:
    // 0x80472520: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_80472524:
    // 0x80472524: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80472528: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8047252C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80472530: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80472534: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80472538: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8047253C: jal         0x80067114
    // 0x80472540: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_7;
    // 0x80472540: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x80472544: jal         0x80065954
    // 0x80472548: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_8;
    // 0x80472548: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x8047254C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80472550: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80472554: bgez        $t3, L_8047259C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80472558: nop
    
            goto L_8047259C;
    }
    // 0x80472558: nop

    // 0x8047255C: jal         0x80066E88
    // 0x80472560: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x80472560: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x80472564: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80472568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8047256C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80472570: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80472574: jal         0x80066DE4
    // 0x80472578: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_10;
    // 0x80472578: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8047257C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80472580: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80472584: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80472588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8047258C: nop

    // 0x80472590: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80472594: b           L_804725D4
    // 0x80472598: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
        goto L_804725D4;
    // 0x80472598: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_8047259C:
    // 0x8047259C: jal         0x80066E88
    // 0x804725A0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_11;
    // 0x804725A0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_11:
    // 0x804725A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x804725A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804725AC: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804725B0: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x804725B4: jal         0x80066DE4
    // 0x804725B8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_12;
    // 0x804725B8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x804725BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x804725C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804725C4: nop

    // 0x804725C8: mul.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x804725CC: nop

    // 0x804725D0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_804725D4:
    // 0x804725D4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804725D8: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x804725DC: nop

    // 0x804725E0: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x804725E4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804725E8: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
    // 0x804725EC: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x804725F0: nop

    // 0x804725F4: bc1f        L_80472600
    if (!c1cs) {
        // 0x804725F8: nop
    
            goto L_80472600;
    }
    // 0x804725F8: nop

    // 0x804725FC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80472600:
    // 0x80472600: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80472604: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AEC) << 16);
    // 0x80472608: lwc1        $f6, 0x2FAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AEC));
    // 0x8047260C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80472610: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80472614: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80472618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8047261C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80472620: nop

    // 0x80472624: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80472628: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8047262C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80472630: b           L_80472648
    // 0x80472634: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
        goto L_80472648;
    // 0x80472634: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
L_80472638:
    // 0x80472638: jal         0x804715A4
    // 0x8047263C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_804715A4(rdram, ctx);
        goto after_13;
    // 0x8047263C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_13:
    // 0x80472640: jal         0x80471660
    // 0x80472644: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80471660(rdram, ctx);
        goto after_14;
    // 0x80472644: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_14:
L_80472648:
    // 0x80472648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8047264C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80472650: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80472654: jr          $ra
    // 0x80472658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80472658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80530490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530490: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(336, 0X10) << 16);
    // 0x80530494: addiu       $v0, $v0, 0x4A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(336, 0X10));
    // 0x80530498: jr          $ra
    // 0x8053049C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8053049C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80451AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80451ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451AD0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80451AD4: jal         0x80450F20
    // 0x80451AD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80450F20(rdram, ctx);
        goto after_0;
    // 0x80451AD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80451ADC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80451AE0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451AE4: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80451AE8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80451AEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80451AF0: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80451AF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451AF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80451AFC: swc1        $f0, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f0.u32l;
    // 0x80451B00: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451B04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80451B08: swc1        $f0, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f0.u32l;
    // 0x80451B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80451B10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80451B14: jr          $ra
    // 0x80451B18: nop

    return;
    // 0x80451B18: nop

;}
RECOMP_FUNC void func_8066AF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066AF94: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8066AF98: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(514, 0X25A0) << 16);
    // 0x8066AF9C: addiu       $t9, $t9, -0x2E00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(514, 0X25A0));
    // 0x8066AFA0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8066AFA4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8066AFA8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8066AFAC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8066AFB0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8066AFB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066AFB8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066AFBC: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8066AFC0: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8066AFC4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8066AFC8: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8066AFCC: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8066AFD0: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8066AFD4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8066AFD8: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8066AFDC: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8066AFE0: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8066AFE4: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8066AFE8: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8066AFEC: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x8066AFF0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8066AFF4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8066AFF8: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x8066AFFC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8066B000: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8066B004: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8066B008: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8066B00C: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x8066B010: bnel        $at, $zero, L_8066B048
    if (ctx->r1 != 0) {
        // 0x8066B014: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8066B048;
    }
    goto skip_0;
    // 0x8066B014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8066B018: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x8066B01C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x8066B020: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x8066B024: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8066B028: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x8066B02C: bne         $at, $zero, L_8066B03C
    if (ctx->r1 != 0) {
        // 0x8066B030: nop
    
            goto L_8066B03C;
    }
    // 0x8066B030: nop

    // 0x8066B034: b           L_8066B048
    // 0x8066B038: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
        goto L_8066B048;
    // 0x8066B038: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_8066B03C:
    // 0x8066B03C: b           L_8066B048
    // 0x8066B040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8066B048;
    // 0x8066B040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8066B044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066B048:
    // 0x8066B048: jr          $ra
    // 0x8066B04C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8066B04C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8071162C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071162C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80711630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80711634: jal         0x807115CC
    // 0x80711638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807115CC(rdram, ctx);
        goto after_0;
    // 0x80711638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8071163C: beql        $v0, $zero, L_80711650
    if (ctx->r2 == 0) {
        // 0x80711640: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80711650;
    }
    goto skip_0;
    // 0x80711640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80711644: jal         0x800447C8
    // 0x80711648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80711648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8071164C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80711650:
    // 0x80711650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711654: jr          $ra
    // 0x80711658: nop

    return;
    // 0x80711658: nop

;}
RECOMP_FUNC void func_8045EE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045EE2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045EE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045EE34: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8045EE38: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(110, 0X1298) << 16);
    // 0x8045EE3C: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8045EE40: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8045EE44: addiu       $t6, $t6, -0x1058
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(110, 0X1298));
    // 0x8045EE48: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8045EE4C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045EE50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045EE54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045EE58: jal         0x8045EED0
    // 0x8045EE5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8045EED0(rdram, ctx);
        goto after_0;
    // 0x8045EE5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8045EE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045EE64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8045EE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8045EE6C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8045EE70: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8045EE74: jal         0x80045A34
    // 0x8045EE78: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8045EE78: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_1:
    // 0x8045EE7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045EE80: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8045EE84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045EE88: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8045EE8C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8045EE90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8045EE94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045EE98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8045EE9C: lhu         $t9, 0x28($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X28);
    // 0x8045EEA0: andi        $t1, $t9, 0xFFFD
    ctx->r9 = ctx->r25 & 0XFFFD;
    // 0x8045EEA4: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8045EEA8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8045EEAC: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8045EEB0: sh          $t1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r9;
    // 0x8045EEB4: sh          $t2, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r10;
    // 0x8045EEB8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8045EEBC: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8045EEC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045EEC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045EEC8: jr          $ra
    // 0x8045EECC: nop

    return;
    // 0x8045EECC: nop

;}
