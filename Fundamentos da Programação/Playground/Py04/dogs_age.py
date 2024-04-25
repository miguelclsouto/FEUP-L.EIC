a = 3

def dogs(h_age):
    
    dog_age = 0
    
    if h_age <= 2:
        
        dog_age = h_age * 10.5
        
    else:
        
        dog_age = (h_age - 2) * 4 + 2 * 10.5
        
    return dog_age

print(dogs(a))