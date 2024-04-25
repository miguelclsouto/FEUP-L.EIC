
# double prodint_VF(float *X, float *Y, int n)

.data

v1: .float 10.5, 26.7, 30.4

v2: .float 24.3, 36.5, 23.7

.text

li t0, 3 # length dos vetores (assumimos que os vetores tem a mesma length)
la a0, v1
la a1, v2
jal prodint

li a7, 10
ecall


prodint: 
	fcvt.d.w ft0, x0 # ja que queremos que o resultado seja em double vamos converter os valores para double
iter:	beq t0, x0, fim
	flw ft1, 0(a0)
	flw ft2, 0(a1)
	fcvt.d.s ft1, ft1
	fcvt.d.s ft2, ft2
	fmul.d ft2, ft2, ft1
	fadd.d ft0, ft0, ft2
	addi a0, a0, 4
	addi a1, a1, 4
	addi t0, t0, -1
	beq x0, x0, iter

fim:	fmv.d fa0, ft0
	ret
