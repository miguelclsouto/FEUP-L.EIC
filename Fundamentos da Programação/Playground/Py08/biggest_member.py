def biggest_member(atuple):
    
    maxi = atuple
    
    for sub in atuple:
        
        if type(sub) is tuple:
            
            if len(biggest_member(sub)) > len(maxi):
                
                maxi = biggest_member(sub)
                
    return maxi