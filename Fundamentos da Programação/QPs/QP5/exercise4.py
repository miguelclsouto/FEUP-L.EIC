

def iterations(g, subtuple):
    
    num = 0
    
    for i in g:
        
        if subtuple == i:
            num += 1
            
    return num
        

def multi(g):
    newtuple = ()
    num = ()
    finaltuple = ()
    
    for i in g:
        if i not in newtuple:
            
            newtuple += (i,)
            
            num += (iterations(g, i),)
        
    for j in range(len(newtuple)):
        
        finaltuple += ((newtuple[j][0], num[j], newtuple[j][1]),)
        
    return finaltuple                
                
        
            