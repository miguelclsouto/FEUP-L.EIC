
# n**2 +(n−1)**2 +(n−2)**2 +···+1**2

.data

num: .word 10

.text
.global square
.global sumSquare

#la t0, num

la t0, num # tenho que ter o load address
lw t0, 0(t0)

# o a0 e o numero que vai diminuir ate chegar a um

# o num ta no t0

jal ra, sumSquare
li a7, 10
ecall
# estas 2 ultimas linhas sao para acabar a execucao do codigo e sair

sumSquare:
	# lw t1, 0(a0) # assim tenho o numero em t1
	li t1, 0 # t1 vai ser para acumular a soma
	blt zero, t0, iter # se o numero for positivo
	# se nao o numero e negativo e vou querer dar return e fazer a0 = 0
	add t0, x0, x0
	beq x0, x0, r
iter:   # podia acrescentar aqui em cima a condicao
	# beq zero, a0, r
	# o a0 vai ter que ser o valor do argumento
	# agora queres fzr o quadrado do numero e depois somar com os outros
	# vou ter que por os ra na pilha e o valor da soma tb
	addi sp, sp, -12
	sw t0, 0(sp)
	sw t1, 4(sp)
	sw ra, 8(sp)
	
	mv a0, t0 # numero como argumento para esta subroutine
	jal ra, square
	# agora o valor de return vai ser dado no a0
	# ao vai ter o valor squared
	#mv t1, a0 # mover o resultado do return
	# tu nao vais querer mover. Na verdade vais querer ir buscar os valores e depois adicionar
	
	# agora no a0 tenho o valor squared e vou querer fzr a acumulacao da soma primeiro
	lw t1, 4(sp)
	lw ra, 8(sp)
	lw t0, 0(sp) # agora o a0 passa a ser o valor normal de novo
	addi sp, sp, 12
	add t1, t1, a0 # t1 e as somas anteriores e o a0 e o squared number
	addi t0, t0, -1 # subtraimos um
	bne t0, zero, iter
	# o a0 e sempre o num squared
r:
	# voltar a buscar os valores da pilha
	# tou a guardar na pilha
	# como e que guardo o ra na pilha
	mv a0, t1 # queres dar return da soma
	ret
	
# z:
	# add a0, x0, x0 # damos return de 0 se o num for negativo
	# devo passar para outra label
	
square:
	mul a0, a0, a0
	ret


fim: 	li a7, 10
	ecall # acabar o programa

