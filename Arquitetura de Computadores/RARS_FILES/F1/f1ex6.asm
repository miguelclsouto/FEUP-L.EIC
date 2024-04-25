.data

num: .word 30, 40

.text

#.global check1bits
#.global MesmaPos

la a1, num # a0 = endereco de num
addi sp, sp, -4
sw a1, 0(sp)
lw a0, 0(a1)
jal check1bits # = jal ra, check1bits
mv s0, a0
lw a0, 0(sp) # la do num
jal MesmaPos
mv s1, a0
lw a0, 0(sp)
lw a1, 0(sp)
addi sp, sp, 4
li a7, 10
ecall

check1bits:
	# o a0 ja tem o num
	addi sp, sp -4
	sw ra, 0(sp)
	add t1, x0, x0 # t1 = accumulator do numero de bits a 1
	#lw t0, 0(a0) # t0 = num
iter: 	
	# quero acabar o loop quando t0 for igual a 0
	# vou guardar em t2 o valor para verificar se e um um ou nao, pois ja estou a usar o t1
	andi t2, a0, 1 # verificar o valor
	# agora quero verificar se este valor e 0
	# posso so tb fzr um xor e depois somar
	# xori t2, t2, 1 # 0x00000001 # trocar o valor
	# AFINAL NAO E PRECISO O XOR. SO SERIA PRECISO SE FOSSE PARA CALCULAR O NUMERO DE 0s
	# assim se for par, da um e se for impar da 0
	# agora so preciso de somar este valor ao acumulador
	add t1, t1, t2
	# PODIA SO TB USAR UM BEQ OU BNE E DEPOIS SOMAR 1 A T1 DEPENDENDO DA CONDICAO
	# AGORA TENHO QUE FZER UM SHIFT PARA A DIR DE UM BIT
	srli a0, a0, 1 # de um bit
	bne x0, a0, iter # verificar se a0 = 0, por isso nao seria preciso fzr mais modificacoes
# fim:
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret

MesmaPos:
	addi sp, sp, -4
	sw ra, 0(sp)
	add t0, x0, x0 # t0 = accumulator
	lw t1, 0(a0)
	lw t2, 4(a0)
	li t3, 32
	# t1 e t2 vao ser os 2 numeros
	# vou precisar de fzr esta iteracao 32 vezes
iter2:
	beq t3, x0, fim
	# Acho que e mais simples comparar o LSB de cada vez e fzr um shift right de
	# 1 bit a cada iteracao
	# andi a0, t1, 1
	# andi a1, t2, 1
	# AGORA POSSO FZR UM XOR E INVERTER
	# OU POSSO FZR UM OR E UM XNOR -- XNOR --> QUANDO SAO IGUAIS
	# e verifico se e diferente de 0XFFFFFFFF OU IGUAL A 0XFFFFFFFE # ASSIMQUER DIZER QUE E DIFERENTE
	# OU FACO SO UM XNOR ENTRE OS DOIS LOGO DESDE O INICIO E JA ESTA :), POIS E
	# ter o LSB de cada um
	#xnor a0, 
	xor a0, t1, t2
	neg a0, a0
	# xnor a0, t1, t2 = # xor a0, t1, t2 # neg a0, a0
	# AGORA QUERO CONTAR O NUMERO DE 1, POR ISSO VOU CHAMAR A FUNCAO CHECK1BITS
	jal ra, check1bits
	mv t0, a0
	addi t3, t3, -1
	# beq x0, x0, iter2
	
fim:
	lw ra, 0(sp)
	addi, sp, sp, 4
	mv a0, t0
	ret



