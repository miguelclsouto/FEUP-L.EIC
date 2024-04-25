def local_minima(alist):
    
    newlist = []
    
    for i in range(len(alist) - 2):
        
        temp = alist[i:i+3]
        num = 0
        
        minimo = min(temp)
        
        for i in range(3):
            
            if minimo == temp[i]:
                
                num += 1
                
        if num == 1:
            
            newlist.append(minimo)
            
    return newlist