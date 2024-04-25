import math

def digits_average(n):
    
    if n // 10 == 0: # or n < 10
        return n
    
    soma = 0
    
    m = aver(n, soma)
    
    return digits_average(m)

def aver(n, soma):
    
    if n < 10:
        return soma
    
    n1 = n % 10
    n2 = (n // 10) % 10
    
    soma = soma * 10 + math.floor((n1 + n2) / 2 + 0.5)
    
    return aver(n // 10, soma)