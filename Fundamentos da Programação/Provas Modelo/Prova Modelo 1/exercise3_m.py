import math

def approx_cos(x, n):
    
    sum = 0
    
    for i in range(n):
        
        sum += (-1)**i / math.factorial(2 * i) * x**(2*i)
        
    return round(sum, 5)