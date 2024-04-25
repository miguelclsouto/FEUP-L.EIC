def count_chars(a_string):
    
    alph = 0
    digi = 0
    spec = 0
    
    for i in a_string:
        
        if i.isalpha():
            
            alph += 1
            
        elif i.isdigit():
            
            digi += 1
            
        else:
            
            spec += 1
            
    return (alph, digi, spec)