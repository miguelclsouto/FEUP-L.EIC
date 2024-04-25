.data 

an: .double .278393, .230389, .000972, .078108 # 8 bytes


x: .double .83

y: .double -0.76

.text

la a0, x

la a1, an

jal erf

la a0, y

la a1, an

fld fa0, 0(a0)

jal erfpos

li a7, 10
ecall

erf:	# PODIA TER IMPLEMENTADO ISTO COM UM LOOP TB
	# em a0 esta o x / o y
	# podia tb por o x / y no fa0 como argumento
	li t0, 1
	fcvt.d.w ft0, t0 # ft0 = 1.0
	fcvt.d.w ft1, x0 # ft1 = acumulador
	fld ft2, 0(a0) # x
	fabs.d ft2, ft2 # ter a certeza de que o valor e positivo
	fld ft3, 0(a1)
	addi a1, a1, 8
	fmul.d ft1, ft2, ft3 # x * a1
	fld ft3, 0(a1) # a2
	addi a1, a1, 8
	fmv.d ft4, ft2 # ft4 = x tb tal como ft2
	fmul.d ft4, ft4, ft2 # x**2
	fmul.d ft3, ft3, ft4 # a1 * x**2
	fadd.d ft1, ft1, ft3
	fld ft3, 0(a1) # a3
	addi a1, a1, 8
	fmul.d ft4, ft4, ft2 # ft4 = x**3
	fmul.d ft3, ft3, ft4 # a2 * x**3
	fadd.d ft1, ft1, ft3
	# eu podia fzr aqui um loop em que multiplicava o ft4 sempre por ft2
	fld ft3, 0(a1) # a4
	fmul.d ft4, ft4, ft2 # ft4 = x**4
	fmul.d ft3, ft3, ft4 # a4 * x**3
	fadd.d ft1, ft1, ft3
	fadd.d ft1, ft0, ft1
	fmul.d ft1, ft1, ft1
	fmul.d ft1, ft1, ft1
	fdiv.d ft1, ft0, ft1
	fsub.d ft0, ft0, ft1
	fmv.d fa0, ft0
	ret
	
erfpos:	fcvt.d.w ft0, x0
# vamos verificar se o valor e positivo
	flt.d t0, fa0, ft1 # y < 0
	addi sp, sp, -16
	sw ra, 0(sp)
	sw t0, 4(sp)
	# bne t0, x0,  # ent y < 0 e vou querer depois adicionar o 0
	# fabs.d fa0, fa0
	jal erf # O RESULTADO ESTA EM FA0 # tinha era que por o argumento em modulo value dentro da funcao como nao usei o fa0 como argumento mas o address, a0
	# COMO ISTO E UM FLOATING POINT TB PODIA VERIFICAR SE O VALOR ESTAVA CORRETO AO FZR UM AND COM 0X80000000, PODIA FZR LOAD DISTO E DEPOIS FZR ISSO
	lw ra, 0(sp)
	lw t0, 4(sp)
	addi sp, sp, 16
	beq t0, x0, fim
	# se t0 = 0, ent o valor e positivo por isso nao preciso de fzr nada
	# se nao vou querer por o valor negativo
	fneg.d fa0, fa0 # ja esta
fim:	ret # ja tenho o valor
	
	
	
	
