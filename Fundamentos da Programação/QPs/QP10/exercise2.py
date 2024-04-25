import math
def comprehensions(i, j):
    
    # basicamente crio uma lista dos numeros usando o range
    l = range(i, j + 1)
    
    
    f1 = list(filter(first,l))
    
    
    f2 = tuple(map(lambda x: round(math.sqrt(x),2), l))
    
    
    t3 = map(lambda x: chr(x), l)
    
    
    t3 = zip(l, t3)
    
    
    # dictionary comprehension
    f3 = {k:v for k, v in t3}
    
    return (f1, f2, f3)
    
def first(n):
    
    return n % 10 == 3 or n % 10 == 8