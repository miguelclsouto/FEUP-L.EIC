def treasure(clues):
    
    # podia usar um while em que 
    # verifica quando a nova key ja nao estava no dict.keys()
    
    key = (0, 0)
    for i in range(len(clues.keys())):
        
        key = clues[key]
        
    return key   