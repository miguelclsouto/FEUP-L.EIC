def adigits(a, b, c):
    
    n = [a, b, c]
    min = 9
    num = 0
    s = len(n)
    
    while s != 0:
        
        min = 0
        
        for i in range(1, s):
            
            if n[min] > n[i]:
                
                min = i
                
        num = num * 10 + n[min]
        
        n.remove(n[min])
        
        s = len(n)
        
    return num
