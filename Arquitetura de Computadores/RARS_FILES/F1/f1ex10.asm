.data 

num: .word 100

.text

la a0, num
addi sp, sp, -4
sw a0, 0(sp)

jal MaisSig
mv s0, a0
# o numero minimo de bits em que pode ser representado e s0 + 1 se for positivo ou s0 se ja nao for pos
# addi s1, s0, 1
lw a0, 0(sp)
jal MinNumBits2
mv s1, a0
lw a0, 0(sp)
jal Capicua
mv s2, a0
lw a0, 0(sp)
addi sp, sp, 4

li a7, 10
ecall

MaisSig: # pos do bit mais sig
	addi sp, sp, -4
	sw ra, 0(sp)
	li t0, -1
	lw t1, 0(a0) # t1 = num
iter:	beq t1, x0, fim
	srli t1, t1, 1 # shift para a dir de 1
	addi t0, t0, 1
	beq x0, x0, iter
fim:
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t0
	ret

MinNumBits: # acho que o mais facil e fzr o valor absoluto do num e verificar a posicao do um mais a esquerda.
	# De seguida temos que acrescentar mais um bit por causa do num ser negativo ou pos em 2's compl
	# Vou calcular o numero de bits minimo para representar esse num unsigned e depois somo um (n + 1).
	# a0 = address do num
	# ex 1111110000 e negativo e 0000010101 e positivo. Eu posso tb ver primeiro se e negativo ou positivo
	# e ir verificando da esquerda (MSB) para a dir ate descobrir um num que nao e igual ao MSB
	# PARA VALORES QUE SAO POWERS de 2 TIPO 128, O VALOR NEGATIVO DE 128 (-128) OCUPA MENOS UM BIT DO QUE 128 EM COMPLEMENTO PARA 2, POIS
	# SE UTILIZAR 8 BITS, O RANGE DE VALORES SERA ENTRE -128 E 127
	addi sp, sp, -4
	sw ra, 0(sp)
	
	lw t0, 0(a0) # t0 = num
	mv t1, t0
	# agora vou querer verificar se ele e negativo
	li t2,  0x80000000
	bltu t0, t2, next # t0 < 0x80000000, entao t0 > 0, t0 e positivo
	# nao preciso de guardar 1 ou 0 numa variavel para depois saber se o num original era negativo ou nao
	neg t1, t1 # t1 = -t1
next: # t1 = abs(t0)

fim2:	
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret
	

MinNumBits2: # ex 1111110000 e negativo e 0000010101 e positivo. Eu posso tb ver primeiro se e negativo ou positivo
	#  e ir verificando da esquerda (MSB) para a dir ate descobrir um num que nao e igual ao MSB
	addi sp, sp, -4
	sw ra, 0(sp)
	lw t0, 0(a0) # t0 = num
	# mv t1, t0
	# add t1, x0, x0 # t1 = 0
	# andi t2, t0, 0x80000000 # verificar qual e o MSB
	li a1, 0x80000000
	li a2, 32
	and t1, t0, a1 # verificar qual e o MSB
	beq t1, x0, ver
	addi t1, x0, 1
	add t2, x0, x0 # t2 = accumulator
	# I COULD HAVE JUST LET T1 = 0X10000000 AND NOT MAKE IT 0X00000001
	# ASSIM O T1 TEM O MSB DO NUM
	# mv t3, t1
	# bne t3, t1, fim3
	
ver: # verificar
	beq t2, a2, fim3
	slli t0, t0, 1 # 1 bit # multiply by 2
	and t3, t0, a1 # t3  will have the msb each iteration
	beq t3, x0, prox2 # t3 = 0x000000000
	# else we want to make it 0x00000001
	addi t3, x0, 1 # t3 = 0x00000001
prox2:	# Now we have the MSB in t3 that we can compare with t1
	bne t3, t1, fim3 # se t3 e t1 forem diferentes, quero ir para fim3
	#check
	addi t2, t2, 1
	beq x0, x0, ver
fim3:	
	lw ra, 0(sp)
	addi sp, sp, 4
	sub t2, a2, t2 # t2 = 32 - t2
	beq t2, x0, s
	beq x0, x0, r # this is because we do not want words with 0 bits
	
s:	
	addi t2, x0, 1
	
r:
	mv a0, t2
	ret

Capicua:
	# verificar se o MSB e igual ao LSB
	# posso fzr shifts pa direita e pa esquerda sucessivamente para verificar o MSB e o LSB, 16 vezes
	# quando chegar ao 15, para
	# ou faco um and com 0x80000000 e com 0x00000001 e depois faco um srli de 1 para 0x80000000 e um slli para 0x00000001
	lw t0, 0(a0) # t0 = num
	li a0, 0x80000000
	li a1, 0x00000001
	addi sp, sp, -4
	sw ra, 0(sp)
	li t1, 15 # t1 = 15 # repeticoes da iteracao
	addi t2, x0, 1
	
iter2:	
	beq x0, t1, final
	and t3, t0, a0
	and t4, t0, a1 # t4 ja esta bem
	beq t3, x0, frente # t3 = 0x00000000
	addi t3, x0, 1 # else: t3 era igual a 0x80000000 e passou a ser t3 = 0x00000001
	
frente:
	beq t4, x0, frente2
	# vamos verificar se t3 = t4
	# bne t3, t4, final
	addi t4, x0, 1
frente2:
	beq t3, t4, l
	# caso t3 != t4
	add t2, x0, x0
	beq x0, x0, final
	
l:	
	srli a0, a0, 1
	slli a1, a1, 1
	# tenho que reiniciar os valores de t3 e t4
	add t3, x0, x0
	add t4, x0, x0
	addi t1, t1, -1
	beq x0,x0 iter2
	
final: 
	lw ra, 0(sp)
	# posso verificar aqui no final se x0 = t1. Se isso for verdade, ent e capicua, se nao nao e
	addi sp, sp, 4
	mv a0, t2
	ret
	
	
