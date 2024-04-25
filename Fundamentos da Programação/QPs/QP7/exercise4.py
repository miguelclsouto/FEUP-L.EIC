def isomorphic(a_string1, a_string2):
    
    let1 = set(a_string1)
    let2 = set(a_string2)
    
    if len(a_string1) != len(a_string2) or len(let1) != len(let2):
        
        return f"'{a_string1}' and '{a_string2}' are not isomorphic"
    
    return f"'{a_string1}' and '{a_string2}' are isomorphic"
    
    