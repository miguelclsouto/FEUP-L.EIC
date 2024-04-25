def validate_cc(number):
    
    temp = number
    
    multiply = False
    
    sum = 0
    
    # temp = num
    # temp2 = temp % 10
    # a cada iteracao
    # temp //= 10 # estamos a divir o numero por 10 (divisao inteira)
    # para podermos ir para o proximo numero do cartao
    
    while temp != 0:
        
        temp2 = temp % 10
        
        
        temp2 *= (multiply + 1)
        
        sum += temp2 // 10 + temp2 % 10
        
        
        multiply = not multiply
        
        temp //= 10
        
        
    valid = sum % 10
    
    if valid == 0:
        
        final = "Card number " + str(number) + " valid"
        return final
    
    
    else:
        
        valid = str(valid)
        
        final2 = "Card number " + str(number) + " invalid (checksum " + valid + ")"
        return final2
        
    
    

           
    