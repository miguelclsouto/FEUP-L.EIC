
def count_exceptions(f, n1, n2): # f is a function
    
    n = 0
    
    for i in range(n1, n2 + 1):
        
        try:
            f(i)
            
        except:
            n += 1
            
    return n
        