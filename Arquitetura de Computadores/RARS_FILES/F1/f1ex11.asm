.data

v1: .word 0x7FFFFF00, 300, 0x80000011
v2: .word 90, 60, -150
v3: .word 0x7FFFFFFF, 0x80000011, 10
r: .space 12 # nao posso escrever 3 * 4 # (12 bytes) o espaco de 3 words / 3 valores do vetor
multip: .space 12

# nao implementei a alinea e)

.text

la a0, v1
la a1, v2
la a2, r

addi sp, sp, -16
sw a0, 0(sp)
sw a1, 4(sp)
sw a2, 8(sp)
jal ra, soma
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal ra, mult
mv s2, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal prodint
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
mv a0, a1
la a1, v3 # vou querer multiplicar o v2 pelo v3 e guardar isto numa pos de mem
la a2, multip # quero guardar no mul a mult dos vetores
li a3, 3 # tamanho dos vetores
jal dotprod
mv s3, a0
addi sp, sp, 16
# li t6, 0xFFFFFFFF00000000


li a7, 10
ecall

# soma de vetores

	# a0 - ADDR DE V1
	# a1 - ADDR DE V2
	# a2 - ADDR DE VETOR RESULTANTE (SPACE)
	# a3 - tamanho dos vetores
	
dotprod:
	add t2, x0, x0 # t2 = acumulador
cic:	beq a3, x0, finale2 # ja nao ha mais vetores para ver
	# agora vou fzr load dos valores dos vetores
	lw t0, 0(a0)
	lw t1, 0(a1)
	# fzr load dos valores do vetor
	# agora vou multiplica-los apra depois poder guarda-los no addr do a2
	mul t3, t0, t1
	
	# TENHO QUE VERIFICAR OVERFLOW AQUI
	# beq x0, x0, overflowprod
tag1:	sw t3, 0(a2) # guardar na nova pos de mem
	add t4, t2, t3 # tou a somar # depois teria que verificar se ha ouverflow
	# TENHO QUE VERIFICAR OVERFLOW AQUI TB # vou mudar para outros ts
	# beq x0, x0, overflowsum
	# E MAIS FACIL TER UM PARA CADA OVERFLOW, POIS SE NAO NAO SEI DEPOIS ONDE VOLTAR.
	# TB PODERIA SO TER FEITO ISTO COM UMA SUBROUTINE
	# ACHO QUE NOA VOU CRIAR OUTRA SUBROUTINE, POIS ISSO SO SERIA MAIS COMPLICADO
	# agora tenho que verificar se houve overflow
tag2:	addi a0, a0, 4
	addi a1, a1, 4
	addi a2, a2, 4 # pois estamos a falar de palavras (4 bytes)
	# atualizacao do prox valor
	addi a3, a3, -1 # tenho que retirar um do tamanho
	beq x0, x0, cic
finale2:mv a0, t4 # o t4 e o acumulador
	ret


overflowsum: # tens que verificar estes overflows a cada iteracao


	# TENHO QUE MUDAR ESTA FUNC PARA 64 BITS
	
	li t6, 0x80000000
	# pode haver overflow assim com a mul
	# mul t5, t2, t3 # ver se tem o mesmo sinal ou nao
	xor t5, t2, t3
	not t5, t5
	# estou a fzr um xnor em ver de uma mul, por causa de overflow
	
	and t5, t5, t6 # agora tenho o valor correto no t5
	# se t5 < 0, entao nao vou querer mudar nada
	blt t5, x0, tag2
	# se nao, pode ter havido um overflow
	and t5, t6, t2
	and t6, t6, t4 # t4 e onde tenho a resposta
	# agora vou querer verificar se estes ands sao dif ou nao
	beq t5, t6, tag2 # nao houve overflow
	# otherwise, houve overflow
	bne t6, x0, frente4 # vou querer por ent o resultado mais pos, pois deu overflow e deu negativo
	# aqui vou querer por o resultado mais negativo
	li t4, 0x7FFFFFFF
	beq x0, x0, tag2
	
	
frente4:li t4, 0x80000000
	beq x0, x0, tag2
#fin3:	beq x0, x0, tag2


overflowprod:li t6, 0x80000000

	beq x0, t0, tag1
	beq x0, x1, tag1
	
	div t5, t3, t0 # isto tem que dar o t1
	
	beq t5, t1, tag1
	# else houve overflow
	xor t5, t0, t1 # dos valores que multipliquei
	and t5, t5, t6 # obter 0 MSB 
	# agora vejo se e um ou 0,
	# se for 1 ent o valor returned deve ser o valor mais negativo
	bne x0, t5, next_2 # t5 = 1
	li t3, 0x7FFFFFFF # ENTAO DEVE SER O MAIOR VALOR POS
	beq x0, x0, tag1
next_2: li t3, 0x80000000 # ENTAO DEVE SER O MAIOR VALOR NEGATIVO
	beq x0, x0, tag1
	
	
soma: 	addi sp, sp, -4
	sw ra, 0(sp)
	li t2, 3 # tamanho do vetor
	add t3, x0, x0 # t3 = soma dos 2 vetores
	
iter1: 	beq t2, x0, end1
	lw t0, 0(a0) # load de uma word do v1
	lw t1, 0(a1) # load de uma word do v2
	add t3, t1, t0 # vamos somar os 2 valores
	# agora queremos guardar a soma, t3 na pos do endereco a2
	addi sp, sp, -24
	sw a0, 0(sp)
	sw a1, 4(sp)
	sw a2, 8(sp)
	sw t0, 12(sp)
	sw t1, 16(sp)
	sw t2, 20(sp)
	jal ra, overflow
	mv t3, a0
	lw a0, 0(sp)
	lw a1, 4(sp)
	lw a2, 8(sp)
	lw t0, 12(sp)
	lw t1, 16(sp)
	lw t2, 20(sp)
	addi sp, sp, 24
	sw t3, 0(a2)
	addi a2, a2, 4 # endereco para guardar a prox word
	addi a0, a0, 4 # endereco da prox word
	addi a1, a1, 4 # endereco da prox word
	addi t2, t2, -1
	beq x0, x0 iter1
	
end1:	lw ra, 0(sp)
	addi sp, sp, 4
	# nao preciso de dar nenhum return no a0
	ret

# verificar se houve overflow
# a funcao overflow da dar return n0 a0 do valor max ou min caso haja overflow

overflow: lw t0, 0(a0)
	lw t1, 0(a1)
	#mv a0, t3
	xor t2, t0, t1
	li a1, 0x80000000
	and t2, t2, a1 # se for != zero (== 1) nunca havera overflow
	bne t2, x0, fin
	# os 2 sao iguais e pode haver overflow
	and t2, t0, a1 # ter o MSB
	beq t2, x0, f
	addi t2, x0, 1 # ja tenho o MSB

f:	and a1, t3, a1 # verificar o MSB da soma
	# tb podia ter posto no t3
	# verificar se o MSB da soma e igual aos outros os MSBs
	beq a1, t2, fin # nao ha overflow
	# se forem diferentes ja ha overflow
	beq t2, x0, pos # soma de 2 nums pos e deu negativo
	li t3, 0x80000000 # numero mais negativo
	beq x0, x0, fin
	
pos:	li t3, 0x7FFFFFFF # numero mais positivo

fin:	mv a0, t3
	ret 
	
	
	
mult:	li a0, 4
	addi sp, sp, -16
	sw ra, 0(sp)
	li t1, 3 # tamanho do array
	# addi t1, t1, -1
	# tem que comecar a 3
	
iter3: 	beq t1, x0, finale # (VOU SUBTRAINDO E) SO PRECISO DE VERIFICAR SE O VALOR E IGUAL A 0, 
	# MESMO TENDO A CONDICAO NO INICIO OU NO FIM
	lw t0, 0(a1)
	mul t0, t0, a0 # a0 = numero para mult
	sw t0, 0(a1)
	addi a1, a1, 4
	addi t1, t1, -1
	beq x0, x0, iter3

finale:	lw ra, 0(sp)
	addi sp, sp, 16
	ret

# PRODUTO INTERNO

prodint:add t3, x0, x0 # inicializar o t3
	li t2, 3
	addi sp, sp, -4
	sw ra, 0(sp)
	
loop:	beq t2, x0, fi
	lw t0, 0(a0)
	lw t1, 0(a1)
	mul t4, t0, t1 # t0 = t0 * t1
	# falta verificar overflow
	
	add t5, t3, t4 # t3 = t3 + t0 # produto interno
	# falta verificar overflow
	
	mv t3, t5
	addi a0, a0, 4
	addi a1, a1, 4
	addi t2, t2, -1
	beq x0, x0, loop
	
fi:	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t3
	ret
