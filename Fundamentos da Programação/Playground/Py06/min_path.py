
def min_path(path): 
    
    # i could also use 4 booleans
    
    useless = [{'UP', 'DOWN'}, {'RIGHT', 'LEFT'}]
    
    # i could also create a copy of path and use it
    # path.copy() and use it for the exercise
    
    i = 0
    
    while i <= len(path) - 1:
        
        l = set(path[i:i + 2])
        
        if l in useless:
            
            path[i:i + 2] = []
            i -= 1
            
        else:
            
            i += 1
            
    return path

