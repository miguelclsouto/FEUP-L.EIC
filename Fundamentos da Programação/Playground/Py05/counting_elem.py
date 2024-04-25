
def count_until(tup):
    
    sum = 0
    
    for elem in tup:
        
        if type(elem) == tuple:
            
            return sum
        
        sum += 1
        
    return -1