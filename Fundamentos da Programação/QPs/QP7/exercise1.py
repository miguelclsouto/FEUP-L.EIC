def switch_dict(adict):
    
    new_adict = {}
    
    for (key,value) in adict.items():
        
        if value not in new_adict.keys():
            
            new_adict[value] = [key]
            
        else:
            
            new_adict[value].append(key)
            
    return new_adict
            
        

# ou verificava se aquela key / value ja estava no dicionario para poder
# adicionar ou nao com o if key / value in dict:


        


