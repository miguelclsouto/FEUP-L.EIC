.data

v1:	.float 13, 8, 7.5, 2.5  # float is single precision
	# posso omitir o zero aqui, fixe
v2:	.float 10.5, 20.5
v3:	.float 20.5, 30.5

.text

la a0, v1
addi sp, sp, -16
sw a0, 0(sp)
jal alinea_a
fmv.s fs0, fa0
lw a0, 0(sp)
jal area_circulo
fmv.s fs1, fa0
lw a0, 0(sp)
la a1, v2
la a2, v3
jal dist
fmv.s fs2, fa0
addi sp, sp, 16
addi a7, x0, 10 # ou li a7, 10
ecall

# a0 is the address for v1
alinea_a: addi sp, sp, -16
	sw ra, 0(sp)
	flw ft0, 0(a0)
	flw ft1, 4(a0)
	flw ft2, 8(a0)
	fsub.s ft0, ft0, ft1
	fmul.s ft0, ft0, ft2
	flw ft1, 0(a0)
	flw ft2, 12(a0)
	fadd.s ft3, ft1, ft2
	addi a1, x0, 3
	fcvt.s.w ft1, a1
	fsub.s ft3, ft3, ft1
	fdiv.s ft0, ft0, ft3
	
fim_a:	lw ra, 0(sp)
	addi sp, sp, 16
	fmv.s fa0, ft0
	# mv a0, t0 
	ret
	
area_circulo:	addi sp, sp, -16
	sw ra, 0(sp)
	flw ft0, 0(a0)
	li t0, 314159
	li t1, 100000
	fcvt.s.w ft1, t0
	fcvt.s.w ft2, t1
	fdiv.s ft1, ft1, ft2
	fmul.s ft0, ft0, ft1
	lw ra, 0(sp)
	addi sp, sp, 16
	fmv.s fa0, ft0
	ret

dist: 	flw ft0 0(a1)
	flw ft1, 4(a1)
	flw ft2, 0(a2)
	flw ft3, 4(a2)
	fsub.s ft0, ft0, ft2
	fsub.s ft1, ft1, ft3
	fmul.s ft0, ft0, ft0
	fmul.s ft1, ft1, ft1
	fadd.s ft0, ft0, ft1
	fsqrt.s ft0, ft0
	fmv.s fa0, ft0
	ret
