
def count_zeros(f):
    
    return len(f()) - aux(f, 0, len(f()) - 1)


def aux(f, low, high):
    
    g = f()
    
    mid = (low + high) // 2
    
    if low == high:
        return low # if g[low] == 0 else low + 1 # posso ter [1] ou [0] no final

    elif (g[mid] == 1):
        return aux(f, mid + 1, high) # f = lambda: g
    
    else: # g[mid] == 0
        return aux(f, low, mid) # f = lambda: g
    
def aux2(f):
    
    g = f()
    
    low = 0
    high = len(g) - 1
    
    while low != high:
        
        mid = (low + high) // 2
        
        if g[mid] == 0:
            
            high = mid
        
        else: # g[mid] == 1
            
            low = mid + 1
            
    return low
    

print(count_zeros(lambda: [1, 1, 1, 0, 0]))
print(count_zeros(lambda: [1]*8 + [0]*6))
print(count_zeros(lambda: [1]*800000 + [0]*700000))
print(count_zeros(lambda: [1]*800000 + [0]*56000000))