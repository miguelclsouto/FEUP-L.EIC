
def lfsr(n):
    
    assert len(n) >= 2, 'n has to use at least 2 bits'
    
    return aux(n,n)


def XOR(a, b):
    return a != b


def aux(n, m):
 
    
    n1 = int(n[-1])
    n2 = int(n[-2])
    
    xor = int(XOR(n1, n2))
    
    
    xor = str(xor)
    
    
    letter = n[-1]
    
    
    n = n[:-1]
    
    
    n = xor + n
    
    if n == m:
        
        return letter
    
    return letter + aux(n, m)

    