def mask_data(data, n_characters, position):
    
    new_data = ""
    
    temp = -1
    
    if position == "begin":
        
        temp = 1
        
    length = len(data)
    
    for i in range(0, length):
        
        if (not (i < n_characters) and position == "begin") or (not(i >= length - n_characters) and position == "end"):
            
            new_data += data[i]
            
            continue
        
        new_data += "*"

    return new_data