def midpoint(n, m):
    
    return (n + m) / 2


def square_root(a, b):
    
    const = b
    
    while True:
        
        mid = midpoint(a, b)
        
        mid2 = mid * mid

        if mid2 > const:
            
            b = mid
    
        #elif mid2 < const:
            #a = mid

        else:
            
            a = mid

        if abs(mid2 - const) < 0.00001: # podia ter posto esta condicao no while
            
            return mid


print(round(square_root(0,int(input())), 5))