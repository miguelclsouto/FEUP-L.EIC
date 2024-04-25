.data 

v4: .space 20 # (4 * 5)
v2: .space 20 # (4 * 5)
v3: .half 30, 20, 40, -50, -60
v1: .byte 10, 14, 90, 120, 250

.text

la a0, v1 
la a1, v2
la a2 , v3
la a3, v4
addi sp, sp, -16
sw a0, 0(sp)
sw a1, 4(sp)
sw a2, 8(sp)
sw a3, 12(sp)
jal ra, bytetoword
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
lw a3, 12(sp)
jal ra, halfwordtoword
addi sp, sp, 16

li a7, 10
ecall

bytetoword:	addi sp, sp, -4
	sw ra, 0(sp)
	li t1, 0x000000FF
	li t2, 5 # tamanho do vetor
	
iter: 	beq t2, x0, fin
	lb t0, 0(a0) # vai haver sign extension, entao vou ter que retirar isso
	and t0, t0, t1 # assim o t0 ja vai estar em unsigned e sem sign extension
	# agora quero guardar este valor na posicao de memoria do a1
	sw t0, 0(a1)
	addi a1, a1, 4 # adicionar 4 bytes a a1 (words)
	addi a0, a0, 1 # adicionar um byte a a0 (1 byte)
	addi t2, t2, -1
	beq x0, x0, iter
	
fin:	lw ra, 0(sp)
	addi sp, sp, 4
	ret # nao quero modificar o a0

halfwordtoword:	addi sp, sp, -4
	sw ra, 0(sp)
	# o valor e unsigned
	li t2, 5 # tamanho do vetor
	
iter2: 	beq t2, x0, fim
	lh t0, 0(a2)
	sw t0, 0(a3)
	addi a2, a2, 2 # prox halfword
	addi a3, a3, 4 # prox word
	addi t2, t2, -1
	beq x0,x0 iter2
	
fim:	lw ra, 0(sp)
	addi sp, sp, 4
	ret # nao quero modificar o a0
	
