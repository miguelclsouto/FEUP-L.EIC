def roman_to_integer(astring):
    
    romans = { 
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000,
    }
    
    num = 0
    
    exceptions = set(['IV', 'IX', 'XL', 'XC', 'CD', 'CM'])
    # exceptions = {'IV', 'IX', 'XL', 'XC', 'CD', 'CM'}
    
    i = 0
    
    while i < len(astring):
        
        if astring[i:i + 2] in exceptions:
            
            num += romans[astring[i+1]] - romans[astring[i]]

            i += 1
            
        else:    
            
            num += romans[astring[i]]

        i += 1
        
    return num


# ou podia usar uma boolean variable ou um numero que incrementa ate dois 
# para verificar se o proximo caso é uma exececao
