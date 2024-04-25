import math

def fetch_middle(llists):
    
    return list(map(lambda x: x[len(x) // 2] if len(x) % 2 == 1 else (x[len(x) // 2] + x[len(x) // 2 - 1]) / 2, llists))

def fetch_middle2(llists):
    
    lengthrow = len(llists) # rows
    l = []
    
    for i in range(lengthrow):
        
        lengthcol = len(llists[i])
        
        middle1 = llists[i][lengthcol // 2]
        middle2 = llists[i][math.ceil(lengthcol / 2 - 1)] # rounding up
        
        l.append((middle1 + middle2) / 2)
        
    return l