.text

.global strcasecmp

strcasecmp:

	# código
	
	# argumentos a0 = vetor de chars 1, a1 = vetor de chars 2
	
	addi t0, x0, 1 # t0 = 1 (primeira posicao onde eles diferem)
	
loop: # comparamos os chars

	lb t1, 0(a0) # load de um char
	lb t2, 0(a1) # load de um char
	
	# chamo uma rotina para transformar as letras em lowercase
	# era mais facil usar o s
	
	addi sp, sp, -32
	sw ra, 0(sp)
	sw a0, 4(sp)
	sw a1, 8(sp)
	sw t0, 12(sp)
	
	sb t2, 16(sp)
	
	mv a0, t1
	jal lower
	mv t1, a0

	lb t2, 16(sp)
	sb t1, 16(sp)
	
	mv a0, t2
	jal lower
	mv t2, a0
	
	lb t1, 16(sp)
	
	lw t0, 12(sp)
	lw a0, 4(sp)
	lw a1, 8(sp)
	lw ra, 0(sp)
	addi sp, sp, 32
	
	# agora as letras estao em lower case
	
	bne t1, t2, end # t1 != t2
	
	# agora quero verificar se as letras sao iguas a '\0'
	
	bne t1, x0, skip # o vetor de chars ainda nao acabou
	
	# else o vetor de chars acabou ( '\0' == '\0' )
	add t0, x0, x0 # t0 = 0
	
	# queremos entao acabar a sub-rotina
	
	beq x0, x0, end
	
skip:	
	# posso verificar se ambos sao iguas e se tb sao '\0'
	
	addi t0, t0, 1
	addi a0, a0, 1
	addi a1, a1, 1
	beq x0, x0, loop

end:	
	mv a0, t0
	ret

lower:
	# argumento a0 - letra
	
	beq a0, x0, end2 # se for '\0' nao vou modificar nada
	
	addi t0, x0, 'a'
	addi t1, x0, 'z'
	blt a0, t0, change # a0 < 'a'
	bgt a0, t1, change # a0 > 'z'
	
	# else nao queremos mudar a letra (ja esta em lower case)
	
	beq x0, x0, end2
	
change:	# esta em uppercase
	
	addi t1, x0, 'A'
	sub a0, a0, t1 # a0 = a0 - 'A' 
	add a0, a0, t0 # a0 = a0 + 'a'
	
	# a0 = a0 - 'A' + 'a' (tornar lowercase)

end2:	
	ret
	