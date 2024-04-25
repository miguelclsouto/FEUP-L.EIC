def rearrange(l):
    
    first = [x for x in l if x <= 0]
    
    after = [x for x in l if x not in first] # > 0
    
    return first + after

def rearrange2(l):
    
    first = [x for x in l if x <= 0]
    
    after = [x for x in l if x not in first] # > 0

    return first + after