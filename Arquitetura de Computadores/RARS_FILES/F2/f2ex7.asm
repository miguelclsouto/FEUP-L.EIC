.data

x: .double 10.4

.text

la a0, x

fld fa0, 0(a0) # load a double from memory

jal rotF

li a7, 10
ecall

rotF: addi sp, sp, -16
sw ra, 0(sp)
# OU POSSO VER O PRIMEIRO BIT PARA SABER SE O VALOR E NEGATIVO OU NAO
fcvt.d.w ft0, x0

flt.d t1, fa0, ft0 # x < 0
beq t1, x0, func_gte
beq x0, x0 func_lt
# vai modificar o fa0
lw ra, 0(sp)
addi sp, sp, 16
ret


func_gte:
	li t1, 314
	li t2, 100
	fcvt.d.w ft0, t1 # 314
	fcvt.d.w ft1, t2 # 100
	fdiv.d ft0, ft0, ft1 # 314 / 100
	fadd.d fa0, fa0, ft0 # x + pi
	fmv.d ft0, fa0
	fmul.d fa0, ft0, ft0 # (x + pi)*2
	fmul.d fa0, fa0, ft0 # (x + pi)*3
	fsqrt.d fa0, fa0
	ret
	

func_lt:
	li t1, 4
	fcvt.d.w ft0, t1 # 4.0
	fsub.d fa0, ft0, fa0 # 4.0 - x
	fsqrt.d fa0, fa0 # sqrt(4.0 - x)
	addi t1, x0, 1
	fcvt.d.w ft0, t1 # 1.0
	fdiv.d fa0, ft0, fa0 # 1 / sqrt(4.0 - x)
	ret
	
