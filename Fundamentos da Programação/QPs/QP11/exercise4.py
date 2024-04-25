
def bisect(f, n):
    
    lower = 0.0 # make them floating point
    
    upper = 1.0 # make them floating point
    
    while n > 0:
        
        # mesmo sinal
        
        midpoint = (lower + upper) / 2
        
        if f(lower) * f(midpoint) > 0: # mesmo sinal
            
            lower = midpoint
            
        else:
            upper = midpoint 
        
        n -= 1
    
    return round(midpoint, 5)
    
    
