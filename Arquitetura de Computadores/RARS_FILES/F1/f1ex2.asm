.data

vector: .word 7, -8, -23, 56, 20, -10, 0, 40

.text
.global CheckABS

li a0, 20
li a1, 8
beq a1, zero, r # nao quero entrar na subroutine nem verificar espaco que nao existe se a len do vetor for nula (0)
la a2, vector

jal ra, CheckABS

fim:
	li a7, 10
	ecall
r:
	add a0, x0, x0
	beq x0, x0, fim
# a0 = valor "limite " X
# a1 = tamanho do vetor
# a2 = endereco do vector

CheckABS:
	#beq a1, zero, end
	li t0, 0
iter:	
	lw t1, 0(a2) # temos um valor do vetor agora no t1
	li t2, 0x7FFFFFFF
	bleu t1, t2, abs
	neg t1, t1
abs: # agora queres verificar se o valor e maior do que a treshold
	bleu t1, a0, cont
	add t1, x0, x0 # passa a ser 0 se for greater
	addi t0, t0, 1 # aumentar o num de cenas
	sw t1, 0(a2) # guardar o valor de volta em a2
	# neste caso guardar 0 em a2
cont:
	addi a2, a2, 4 # avancar para a prox word
	addi a1, a1, -1 # menos um num do vetor
	bne a1, zero, iter
end:
	mv a0, t0
	ret
	
