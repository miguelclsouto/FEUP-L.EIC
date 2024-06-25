.text

.global aplicar 

aplicar:

	# restante código
	# argumentos --> a0 = vetor de floats v1, a1 = unsigned int n, a2 = vetor de floats r (result)
	
	 mv t0, zero
	
loop: beqz a1, fim

	flw fs0, 0(a0) # fs0 = v[i]
	
	addi sp, sp, -32
	sw ra, 0(sp)
	sw t0, 4(sp)
	sw a0, 8(sp)
	sw a1, 12(sp)
	sw a2, 16(sp)
	fsw fs0, 20(sp)
	
	fmv.s fa0, fs0
	
	jal calcF # fa0 = F(v[i])
	
	lw ra, 0(sp)
	lw t0, 4(sp)
	lw a0, 8(sp)
	lw a1, 12(sp)
	lw a2, 16(sp)
	flw fs0, 20(sp)
	addi sp, sp, 32
	
	fge.s t1, fa0, fs0 # v[i] >= F(v[i])
	
	beqz t1, skip
	
	addi t0, t0, 1
	
skip:
	
	fsw fa0, 0(a2)
	
	addi a2, a2, 4
	addi a0, a0, 4
	addi a1, a1, -1
	beqz zero, loop
	
fim:	mv a0, t0
	ret
