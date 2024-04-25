
def bagdiff2(xs,ys):
    
    length = len(ys)
    
    for i in range(length):
        
        if ys[i] in xs:
            
            xs.remove(ys[i])
            
    return xs