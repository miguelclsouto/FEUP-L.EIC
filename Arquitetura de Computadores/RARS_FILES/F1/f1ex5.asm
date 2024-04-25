.data

vector: .word 10, 20, 40, 49, 60

vector2: .word 21, 32, 43, 54, 65

.text

la a0, vector # load address do primeiro elemento do vetor
li a1, 5 # a1 = num de elementos do vetor --> len(vector)

addi sp, sp, -8 # guardar os valores na stack / pilha
sw a0, 0(sp)
sw a1, 4(sp)
li a2, 10 # lower boundary
li a3, 49 # upper boundary
jal ra, Interval
mv s0, a0
lw a0, 0(sp)
lw a1, 4(sp)
# nao preciso de fzr store de novo porque os valores ja estao stored no stack
jal ra, Par
mv s1, a0
lw a0, 0(sp)
lw a1, 4(sp)
la a2, vector2
li a3, 5
jal Invert
# chamar a proxima funcao
addi sp, sp, 8
li a7, 10
ecall

Interval:

	addi sp, sp, -4
	sw ra, 0(sp) # guardar o ra para caso chame outra subroutine
	add t0, x0, x0 # t0 = numero de vetores no intervalo de [a; b]
	# a0 = la vector, a1 = len(vector), t1 = num, t0 = accumulator
iter:	
	beq a1, x0, fim
	lw t1, 0(a0) # t1 vai ter o vetor
	# agora quero verificar se o valor esta entre a2 e a3
	# posso verificar se ele nao esta
	blt t1, a2, prox # verificar se a0 < a # o vetor ta em t1
	bgt t1, a3, prox # verificar se a0 > b
	# se passar estes dois testes, entao a <= a0 <= b, logo
	# quero adicionar um a t0
	addi t0, t0, 1
	
prox:
	addi a1, a1, -1 # subtrair um de a1
	addi a0, a0, 4 # prox word
	beq x0, x0, iter
	
fim:	
	lw ra, 0(sp)
	addi sp, sp, 4 # voltar a ter o valor de ra e a por o stack pointer onde tava
	mv a0, t0
	ret

###			
				
Par:
	addi sp, sp, -4
	sw ra, 0(sp)
	add t0, x0, x0 # t0 = accumulator
iter2: 
	beq x0, a1, fim2
	lw t1, 0(a0) # fazer load do vetor
	# para descobrir se e par, basta fazer um and com 1 e verificar se o valor e igual a zero ou nao
	andi t1, t1, 1 # obter 1 ou 0, dependendo se o numero for par ou impar
	bne t1, x0, prox2 # nao e par, e impar se for differente de 0
	addi t0, t0, 1 # e par
	
prox2:
	addi a1, a1, -1 # menos um vetor
	addi a0, a0, 4 # prox endereco do vetor
	beq x0, x0, iter2
	
fim2:	
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t0
	ret

InvertString: addi sp, sp, -16
	sw ra, 0(sp)
	# vou ter que ter 2 pointers. Um para o comeco do string e um para o fim
	
Invert: # nao vou fzr as cenas do sp para poupar tempo
	addi t0, x0, 4 # inicializar o num 4 # tamanho de uma palavra
	addi a3, a3, -1 # tenho que subtrair um para me dar o valor certo do fin do vetor
	mul a3, a3, t0	# pointer que indica o final do vetor
	add a3, a3, a2 # agora ja tenho o address da posicao que quero
	# a3 -> pointer do fim, a2 -> pointer do inicio
cicle:	ble a3, a2, finale
	# senao queremos fzr load das palavras
	lw t0, 0(a2) # palavra do inicio
	lw t1, 0(a3) # palavra do fim
	# agora quero trocar as palavras, basta fzr sw mas agora 
	# trocando os 2 (ambos)
	sw t1, 0(a2)
	sw t0, 0(a3)
	# agora ja os troquei de posicao.
	# AGORA TENHO QUE ATUALIZAR AMBOS OS POINTERS
	addi a2, a2, 4
	addi a3, a3, -4
	beq x0, x0, cicle
finale:	ret # nao precido de fzr nenhum return
	
	
