import math

def caesar(message):
    
    length = len(message)
    
    fnl_msg = ""
    
    letter = ""
    
    for i in range(length):
        
        if message[i].isalpha():
            
            shift = ((1 + math.sqrt(5))**i - (1 - math.sqrt(5))**i) / (2**i * math.sqrt(5))
            
            letter = ord(message[i]) - ord("A") - round(shift)
            
            letter = chr(int(letter % 26 + ord("A")))
       
        else:
            
            letter = message[i]
            
        fnl_msg += letter
        
    return fnl_msg