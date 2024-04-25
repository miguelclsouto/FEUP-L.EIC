def camel_case(phrase):
    newstring = ""
    
    upper = False
    
    for i in range(0, len(phrase)):
        
        if phrase[i].isalpha():
            
            if upper:
                
                newstring += phrase[i].upper()
                upper = False
                continue # next iteration
            
            newstring += phrase[i].lower()
          
        else:
            upper = True
            
    finalstring = ""
    
    finalstring += newstring[0].lower()
    
    finalstring += newstring[1:]

    
    return finalstring