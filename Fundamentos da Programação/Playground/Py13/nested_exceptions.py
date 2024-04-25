
def nested_exceptions(tree):
    
    t = tuple()
    
    for f in tree:
        
        try:
            len(f)
            
        except:
            
            try:
                f()
                
            except:
                t += (True,)
                
            else:
                t += (False,)
                
        else:
            t += (nested_exceptions(f),) # tuple
            
    return t