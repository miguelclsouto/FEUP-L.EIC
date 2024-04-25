
# int conta_intervalo(float *V, int n, float a, float b)

.data

v1: .float 12.5, 13.5, 14.5, 15.6, 16.5

min: .float 13
max: .float 15.6

.text

la a0, v1
la a1, min
la a2, max
li a3, 5
flw fa0, 0(a1) # min
flw fa1, 0(a2) # max
jal conta_intervalo
li a7, 10
ecall


conta_intervalo: add t0, x0, x0 # vou acumular no t0

iter:	beq a3, x0, fim
	flw ft2, 0(a0)
	# agora vou verificar se esta no intervalo
	# os que nao estao no intervalo e so fzr os que estao e subtrair
	fle.s t1, fa0, ft2 # min <= x
	beq t1, x0, prox
	fle.s t1, ft2, fa1 # x <= max
	beq t1, x0, prox
	addi t0, t0, 1
prox:
	addi a0, a0, 4
	addi a3, a3, -1
	beq x0, x0, iter
fim:	mv a0, t0
	ret
	
