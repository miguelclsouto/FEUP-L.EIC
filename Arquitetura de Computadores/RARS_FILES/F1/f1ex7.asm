.data

# nao implementei a alinea f)

string: .asciz "abaaba"
char: .byte 'y'
vogais: .byte 'a', 'e', 'i', 'o', 'u'

# vogais: .asciz "aeiou"

.text

la a0, string
la a1, char
la a2, vogais
addi sp, sp, -12
sw a0, 0(sp)
sw a1, 4(sp)
sw a2, 8(sp)
jal ra, length
mv s0, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal ra, ocorrencias
mv s1, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal ra, vogal
mv s2, a0
lw a0, 0(sp)
lw a1, 4(sp)
lw a2, 8(sp)
jal ra, Letrasmaiusculas
mv s3, a0

addi sp, sp, 12

li a7, 10
ecall

length:	addi sp, sp, -4
	sw ra, 0(sp)
	addi t1, x0, -1 # t1 = acumulador de letra
	
iter1:	lb t0, 0(a0) # load do char
	addi a0, a0, 1 # prox byte
	addi t1, t1, 1
	beq t0, x0, fim1 # encontramos o '\0'
	beq x0, x0, iter1
	
fim1:	sw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret

ocorrencias: addi sp, sp, -4
	sw ra, 0(sp)
	add t1, x0, x0 # acumulador
	lb t0, 0(a1) # load do char # a1 = address do char
	
iter2:	lb t2, 0(a0) # load de um char da string
	bne t2, t0, next # os chars sao diferentes
	# else os chars sao iguais
	addi t1, t1, 1
	
next: 	beq t2, x0, fim2 # encontramos o '\0'
	addi a0, a0, 1 # prox char
	beq x0, x0 iter2
	
fim2: 	sw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret
	
vogal:	addi sp, sp, -4
	sw ra, 0(sp)
	li t0, 5
	add t1, x0, x0 # acumulador
	mv a1, a2 # o address das vogais
	
iter3: 	beq t0, x0, fim3
	addi sp, sp, -16
	sw t0, 0(sp)
	sw t1, 4(sp)
	sw a0, 8(sp)
	sw a1, 12(sp)
	jal ra, ocorrencias
	mv t0, a0 # num de occorencias de um char
	lw t1, 4(sp)
	add t1, t1, t0 # adicionar o num de ocorrencias
	lw t0, 0(sp)
	lw a0, 8(sp)
	lw a1, 12(sp)
	addi sp, sp, 16
	addi a1, a1, 1 # prox vogal
	addi t0, t0, -1
	beq x0, x0, iter3

fim3:	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret

Letrasmaiusculas: addi sp, sp, -4
	sw ra, 0(sp)
	add t1, x0, x0 # t1  = acumulador
	lb t0, 0(a0) # a0 address do string
	li t2, 'A'
	li t3, 'Z'
		
iter4:	beq t0, x0, fim4
	# verificar se o char e maiusculo
	blt t0, t2, frente2 # t0 < 'A'
	bgt t0, t3, frente2 # t0 > 'Z'
	addi t1, t1, 1
frente2:addi a0, a0, 1
	lb t0, 0(a0)
	beq x0, x0, iter4
	
fim4:	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t1
	ret

Palindromo: addi sp, sp, -4 # AQUI VOU TER QUE VERIFICAR AS LETRAS PARA VER SE ESTAO EM MAIUSCULO OU MINUSCULO
	sw ra, 0(sp)
	li t0, 'a'
	li t1, 'A'
	sub t2, t1, t0 # t0 = 'A' - 'a'
	# AGORA POSSO VERIFICAR SE O UMA LETRA E OU NAO MINUSCULA. SE FOR SOMO ISTO
	lb t0, 0(a0)
	li t3, 'A'
	li t4, 'Z'
	# OU PODIA CHAMAR UMA FUNCAO PALINDROMO PARA TRANSFORMAR A LETRA EM MAIUSCULA
iter5:	beq t0, x0, fim5
	# agora quero verficar se a letra e maiuscula ou nao
	# podia usar a outra subrouine se conseguisse controlar para apenas verificar um char
	# para verificar se e uma letra tem que estar entre a e z / entre 'A' e 'Z'
frente3:addi a0, a0, 1 # prox char
	lb t0, 0(a0)
	beq x0, x0, iter5

fim5:	lw ra, 0(sp)
	addi sp, sp, 4
	add a0, x0, x0
	bne t0, x0, end # ENTAO NAO E UM PALINDROMO
	addi a0, x0, 1
end: 	ret

Maiuscula: # argumentos -> a0 e uma letra
	li t0, 'a'
	li t1, 'z'
	bgt t0, a0, fim # menor do que 'a' # a > a0
	blt t1, a0, fim # maior do que 'z' # z < a0
	# entao tenho que passar a letra para maiuscula
	# nao e maiuscula
	li t1, 'A'
	# t0 = 'a'
	sub t1, t1, t0 # 'A' - 'a'
	add a0, a0, t1 # a0 + 'A' - 'a'
fim:	ret # vai estar a letra em maiuscula se for uma letra, se nao nao sera uma letra
	# ou o A0 fica igual se nao for minuscula ou eu modifico a letra