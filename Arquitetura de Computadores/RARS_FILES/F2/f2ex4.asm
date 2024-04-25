
# p(x) = a0 + a1x + axx2 + · · · + an−1xn−1
# p(x) = a0 + x(a1 + x(a2 + · · · + x(an−2 + an−1x)))

.data

an: 	.double 5.5, 7.5, 10.5

x:	.double 5.6

n: .word 3 # numero de coeficientes

.text

li t0, 3 # numero de coeficientes
la a2, n 
lw a2, 0(a2) # 3
la a0, an
la a1, x # 0 a1 nao devia ser o address do x, mas devia ser x
jal polinomio
li a7, 10
ecall


# a0 = address de an
# fa0 = x (double)
# a1 = address de an

polinomio: #addi t0, t0, -1
	#li t1, t1, 8 # 8 = numero de bytes de um double
	#mul t0, t0, t1 # 8 * (t0 - 1) para poder calcular o address final
	#add a0, t0, a0 # agora tenho o address do ultimo elemento do vetor
	# vamos comecar a ver do final para tras
	# posso utilizar o valor do a2 ate ser igual a 0
	# posso estar sempre a mult por 0 ou sempre a subtrair 4 e verificar se o address passa do inicial address do vetor
	# o t4 vai ser o acumulador
	#add ft0, x0, x0 # acumulador
	fcvt.d.w ft0, x0 # ft0 = 0 # acumulador
	fld ft2, 0(a1) # t5 = x (double)
cicle:	beq a2, zero, fin
	fmul.d ft0, ft0, ft2 # MULTIPLICO POR X NO INICIO
	addi a2, a2, -1
	addi t3, x0, 8
	mul t3, t3, a2 # CONTAS COM ADDRESSES USAM INTEGERS
	add t3, t3, a0 # address do final do vetor que vai decrementando sempre
	fld ft1, 0(t3) # t3 = an
	fadd.d ft0, ft0, ft1 # somar o an para acumular o valor e agora vou multiplicalo por x
	# fmul.d ft0, ft0, ft2 # agora vou multiplicalo por x
	# tenho que mutiplicar por x no inicio
	# QUERO FZR LOAD, DEPOIS SOMO E DEPOIS MULTIPLICO POR X
	# TRABALHO COM VALORES INTEIROS PARA OS ADDRESSES 
	# MAS COM FLOATING POINT PARA OS VALORES QUE ESTAO NESSES ADDRESSES
	beq x0, x0, cicle
fin: 	fmv.d fa0, ft0
	ret
	
