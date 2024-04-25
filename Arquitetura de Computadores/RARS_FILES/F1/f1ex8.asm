.data

vector: .word 10, 25, 30
vector2: .word 10, 27, 30
num: 3

.text

la a0, vector
la a1, num
lw a2, 0(a1)
addi sp, sp, -16
sw a0, 0(sp)
sw a1, 4(sp)
sw a2, 8(sp)
jal soma
mv s0, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal media
mv s1, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
la a3, vector2
sw a3, 12(sp)

jal maxmedia

mv s2, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
lw a3, 12(sp)
# pos + 4
addi sp, sp, 16
li a7, 10
ecall

soma: # soma de todos os elementos do vetor
# a0 = address
# a0 = la vector, a1 = la tamanho do vetor, t0, t1 e t2 tb sao utilizados aqui

	lw t1, 0(a1) # t1 = tamanho do vector
	addi sp, sp, -4
	sw ra, 0(sp)
	add t2, x0, x0
	
iter:	
	beq t1, x0, fim
	lw t0, 0(a0) # t0 = vector # cada valor do vetor e uma word

	add t2, t2, t0
	addi a0, a0, 4 # prox num do vetor
	addi t1, t1, -1
	beq x0, x0, iter
fim:
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t2
	ret
	
media:	# a0 = address
	lw t1, 0(a1)
	addi sp, sp, -8
	sw t1, 0(sp)
	sw ra, 4(sp)
	# quero chamar a soma com o a0 e o a1 como addresses
	jal soma
	mv t0, a0
	lw t1, 0(sp)
	# t0 = soma
	# t1 = len(vetores)
	lw ra, 4(sp)
	addi sp, sp, 8
	#fcvt.s.w t0, t0
	#fcvt.s.w t1, t1
	div t2, t0, t1 # esta floating point division funciona com 2 ints. O resultado e em floating point
	# QUERO FZR A SOMA E DEPOIS DIVIDIR
	mv a0, t2
	ret

maxmedia:
	#lw t0, 0(a0)
	#lw t1, 0(a3)
	# 2 vetores
	addi sp, sp, -16
	#
	#sw t1, 4(sp)
	sw ra, 8(sp)
	# colocar os vetores nas posicoes certas
	
	# TENHO QUE GUARDAR OS ADDRESSES DO VETOR
	
	jal media
	#lw t0, 0(sp)
	#lw t1, 4(sp)
	mv t0, a0 # t0 = media vetor1
	sw t0, 0(sp) # t0 = media do primeiro vetor
	# sw t0, 0(sp)
	mv a0, a3 # assim o address do a0 passa a ser o address do outro vetor (vetor2)
	# na funcao media eu uso o a1
	jal media
	lw t0, 0(sp)
	# mv t0, a0
	# verificar qual e maior
	#mv a0, t0
	# ja esta mv a0, t1
	blt t0, a0, fin # se t0 < t1, entao o t1 e maior (a0 = t1)
	# ou fle.s
	#mv a0, t1 isto ja esta
	mv a0, t0 # else
fin:	lw ra, 8(sp)
	addi sp, sp, 16
	ret
	
	
	
	
	
	
