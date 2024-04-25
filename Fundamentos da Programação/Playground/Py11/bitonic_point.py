
def bitonic_point(f):
    
    g = f()
    middle = len(g) // 2 
    
    if len(g) <= 2:
        return g[0] if len(g) == 1 or g[0] > g[1] else g[1]
    
    elif g[middle + 1] > g[middle]:
        return bitonic_point(lambda: g[middle + 1:])
    
    else: # g[middle + 1] <= g[middle]:
        return bitonic_point(lambda: g[:middle + 1])



def bitonic_point2(f):
    
    g = f()
    middle = len(g) // 2
    
    if len(g) < 3:
        return max(g)
    
    if g[middle] > g[middle - 1] and g[middle] > g[middle + 1]:
        return g[middle]
    
    elif g[middle] > g[middle - 1]:
        return bitonic_point2(lambda: g[middle + 1:])
    
    return bitonic_point2(lambda: g[:middle])
