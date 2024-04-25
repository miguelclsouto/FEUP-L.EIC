def repeated_letter(s):
    
    length = len(s)
    
    # w = list(s)
    # l = set(s)
    
    for i in range(length):
        
        w = list(s)
        w.remove(s[i])
        
        if s[i] in set(w):
            
            return s[i]
    
    # l = list(filter(lambda char: s.count(char) >= 2, s))
    # l.append(None)
    # return l[0]
