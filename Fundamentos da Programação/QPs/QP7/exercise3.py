def sparse_dot_product(dict1, dict2):
    
    prod = 0
    
    for key1 in dict1.keys():
        
        if key1 in dict2.keys(): 
            
            prod += dict1[key1] * dict2[key1]
            
    return prod
