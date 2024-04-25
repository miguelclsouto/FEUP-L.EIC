.data

x: .double 1.57

# A SUBROUTINE FUNCIONA EM RADIANOS

.text

#li a0, 1
#jal fact



la a0, x # address de x
fld fa0, 0(a0) # valor de x
jal cos
li a7, 10
ecall

# agumentos
cos:	# fa0 = x # EM RADIANOS
	fmul.d fa0, fa0, fa0 # x^
	fneg.d fa0, fa0 # -x^2
	# ou podia so multiplicar e depois fzr o negativo
	li t0, 10
	addi sp, sp, -16
	sw ra, 0(sp)
	fcvt.d.w ft0, x0 # ft0 vai ser o acumulador
	addi a1, x0, 1
	fcvt.d.w ft2, a1 # tenho que ter 1.00 em double para poder dividir pelo valor do fatorial
	# TENHO QUE TER ESTE VALOR PARA DIVIDIR PELO VALOR DO FATORIAL
cicle2:	blt t0, zero, fim2 # se o t0 < 0 # SE NAO FIZESSE ISTO TERIA QUE DEPOIS ACRESCENTAR O 1 -X^2 * (FT0)
	# queremos fzr o fatorial de t0
	# mas antes queremos multiplicar pelo valor de -x^2
	fmul.d ft0, ft0, fa0 # ft0 = ft0 * -x^2
	# vou ter que converter depois para double para fzr as contas
	
	sw t0, 4(sp) # nao me parece que esteja a utilizar o a0 em nenhum outro lugar do codigo
	# nesta funcao nao vou usar floating points
	# agora quero somar 1/n!
	mv a0, t0
	jal fact
	fcvt.d.w ft1, a0 # fatorial em double
	fdiv.d ft1, ft2, ft1 # 1 / fact
	# agora queremos somar o valor de ft1 ao acumulador
	fadd.d ft0, ft0, ft1 # 1/fact + accumulador
	lw t0, 4(sp)
	addi t0, t0, -2
	beq x0, x0, cicle2
fim2:	lw ra, 0(sp)
	addi sp, sp, 16
	# nao preciso de adicionar o 1 -x^2 * ft0 pois ja modifiquei o loop
	fmv.d fa0, ft0
	ret




fact: # a0 = argumento
	# vou inicializar um valor a 1
	addi t0, x0, 1
	addi t2, x0, 2
	# vou verificar se o valor e inferior / menor que 2
cicle:  blt a0, t2, fim # se a0 < 2, vamos para o fim
	mul t0, t0, a0
	addi a0, a0, -1
	beq x0, x0, cicle
fim:	mv a0, t0
	ret

	# tb poderia usar recursao
