.text 

.global zip 

zip:

	# código da sub-rotina
	# a0 = vetor de ints1, a1 len do vetor1
	# a2 = vetor de ints2, a3 len do vetor2
	# a4 = vetor resultado
	
	add t0, x0, x0 # len do vetor resultante
	beq x0, a3, fim
	addi sp, sp, -16
	sw s0, 0(sp)
	sw s1, 4(sp)
	mv s0, a2
	mv s1, a3

loop:	beq a1, x0, fim # len v1 == 0 ?
	beq a3, x0, restart # len v2 == 0 ? 
	
continue:

	lw t1, 0(a0)
	sw t1, 0(a4)
	lw t2, 0(a2)
	sw t2, 4(a4)
	
	# proximo numero do vetor
	addi a2, a2, 4
	addi a3, a3, -1
	addi a0, a0, 4
	addi a4, a4, 8
	addi a1, a1, -1
	add t0, t0, 2
	beq x0, x0, loop

restart:
	mv a2, s0
	mv a3, s1
	beq x0, x0, continue

fim:	mv a0, t0

	lw s0, 0(sp)
	lw s1, 4(sp)
	addi sp, sp, 16
	
	ret