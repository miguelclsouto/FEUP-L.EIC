def lost_element(s1, s2):
    return (s1 - s2 | s2 - s1).pop()

def lost_element2(s1, s2):
    
    # podia tornar em listas e descobrir o tamanho
    
    x = s1 - s2
    if x == set():
        
        
        return list(s2 - s1)[0]
    
    return list(x)[0]