
def rotate_list(l):
    
    return l[3:] + l[:3]

def rotate_list2(l):
    
    final = [0] * len(l)
    
    length = len(l)
    
    for i in range(length):
        
        temp = (i - 3) # % length
        
        final[temp] = l[i]
        
    return final