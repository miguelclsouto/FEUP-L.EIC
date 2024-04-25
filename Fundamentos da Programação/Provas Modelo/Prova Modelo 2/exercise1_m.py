
def time_diff(time1, time2):
    
    h = 0
    m = 0
    
    if time1[0] > time2[0]:
        
        h = time1[0] - time2[0]
        
        m = abs(time1[1] - time2[1])
        
        if time1[1] < time2[1]:
            
            h -= 1
            m = 60 - m
    
    elif time1[0] == time2[0]:
        
        m = abs(time1[1] - time2[1])    
          
    else:
        
        h = time2[0] - time1[0]
        m = abs(time1[1] - time2[1])
        
        if time1[1] > time2[1]:
            
            h -= 1
            m = 60 - m
    
    return (h, m)
 
    
        
        