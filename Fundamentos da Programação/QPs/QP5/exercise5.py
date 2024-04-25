def triplet(tup):
    
    length = len(tup)
    res = ()
    
    for i in range(length):
        
        for j in range(i + 1, length):
            
            temp = tup[i] + tup[j]
            
            for k in range(j + 1, length):
                
                if tup[k] == -temp:
                    
                    return (tup[i], tup[j], tup[k])
    return ()
                    
