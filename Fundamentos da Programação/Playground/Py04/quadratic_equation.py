import math

n1 = 2
n2 = 5
n3 = -3

def solver(a, b, c): # only for real solutions
    
    if b**2 - 4 * a * c < 0: # binomio discriminante
        
        return []
    
    sol1 = (- b + math.sqrt(b**2 - 4 * a * c )) / (2 * a)
    
    sol2 = (- b - math.sqrt(b**2 - 4 * a * c )) / (2 * a)
    
    if sol1 < sol2:
        
        return [sol1, sol2]
    
    elif sol1 == sol2:
        
        return [sol1]
    
    return [sol2, sol1]

print(solver(n1, n2, n3))