.text

.global rotg

rotg:
    	# restante código
    	# fa0 --> x
	
	fcvt.s.w ft0, x0
    	flt.s t0, fa0, ft0 # x < 0
    	beq x0, t0, g # x == t0 (x >= 0) (! (x < 0) )
    	
    	beq x0, x0, h # else
    	
g:	# G(x) = √x, x ≥ 0
	fsqrt.s fa0, fa0
	beq x0, x0, end

h:	# queremos fzr -f(-x)
	fneg.s fa0, fa0 # x = -x
	addi sp, sp, -16
	# guardar la as cenas
	# tenho que gaurdar o ra
	sw ra, 0(sp)
	# chamar a funcao
	jal ra, f
	lw ra, 0(sp)
	# isto da return de 1 - √x em fa0
	# retirar as cenas de la guardadas
	addi sp, sp, 16
	# agora queremos negar o fa0
	fneg.s fa0, fa0
	beq x0, x0, end
	
	

end:
	ret

f:	# 1 – √x 
	# argument fa0 = x

	addi t1, x0, 1 # 1
	fcvt.s.w ft1, t1 # 1.0
	fsqrt.s fa0, fa0 # √x
	fsub.s fa0, ft1, fa0 # 1 - √x (guardado no fa0)
	ret # 1 - √x em fa0
	