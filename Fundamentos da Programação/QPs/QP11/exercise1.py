
def msort(xs):
    
    if len(xs) <= 1:
        
        return xs
    
    left = msort(xs[:len(xs) // 2])
    
    
    right = msort(xs[len(xs) // 2:])
    
    
    return merge(left, right)

    
def merge(xs, ys):
    
    r = 0
    l = 0
    lis = []
    
    while r < len(xs) and l < len(ys):
        
        if xs[r] > ys[l]:
            
            lis.append(ys[l])
            l += 1
            
        else:
            
            lis.append(xs[r])
            r += 1
    
    lis.extend(xs[r:])
    
    lis.extend(ys[l:])
    
    return lis
    
            
            
    
    
    

    