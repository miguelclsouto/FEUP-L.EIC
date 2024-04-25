def reciprocals(alist):
    
    l = []
    
    for item in alist:

        try:
            n = 1 / item
            
        except:
            pass
        
        else:
            l.append(n)
        
    return l