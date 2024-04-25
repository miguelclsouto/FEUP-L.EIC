
def find_me(f, limits, n = 0):
   
    #
    # tu queres que a funcao f de return de 0
    #
    
    n += 1
    
    middlepoint = (limits[0] + limits[1]) // 2
    
    if f(middlepoint) == 0:
        
        return n
    
    elif f(middlepoint) == 1:
        
        return find_me(f, (middlepoint + 1, limits[1]), n)
    
    return find_me(f, (limits[0], middlepoint - 1), n)    
