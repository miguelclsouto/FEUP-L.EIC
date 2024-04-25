.data

num: .word 10

.text

la t0, num
lw a0, 0(t0)

jal ra, POLI 
li a7, 10 
ecall

POLI:
	mv s0, a0
	addi sp, sp, -12
	sw s0, 0(sp)
	sw ra, 4(sp)
	sw t0, 8 (sp)
	mv t0, a0 # t0 = n # assim ja tenho o t0 guardado
	# fiz o move porque sei que vopu ter utilizar este valor mais a frente
	jal ra, QUAD # a0 = n**2
	addi s0, x0, 3
	mul s0, s0, t0 # 3n
	add a0, a0, s0 # n**2 + 3n
	addi a0, a0, 1 # n**2 + 3n + 1
	lw s0, 0(sp)
	lw ra, 4(sp)
	lw t0, 8 (sp)
	# agora o s0 o ra e o t0 passaram a ser o que eram antes
	addi sp, sp, 12
	# voltar a colocar o stack pointer no sitio
	ret
	
	
QUAD:
	mul a0, a0, a0
	ret
