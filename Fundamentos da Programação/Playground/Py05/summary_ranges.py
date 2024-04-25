def summary_ranges(a_string):
    
    l = a_string.split(",")
    l = list(l)
    length = len(l)
    temp = []
    final = []
    
    for i in range(length - 1):
        
        temp += [l[i]] # append
        
        if int(l[i + 1]) != int(l[i]) + 1:
            
            if len(temp) == 1:
                
                # or check if temp[0] == temp[-1]
                
                final += [temp[0]]
                temp = []
                continue
            
            final += [temp[0] + "->" + temp[-1]]
            
            temp = []
            
            if i == length - 2: # verificar se e o ultimo elemento
                
                final += [l[i+1]]
                return ','.join(final)
            
        if i == length - 2: # verificar se e o ultimo elemento
            
            final += [temp[0] + "->" + l[i + 1]]
            return ','.join(final)