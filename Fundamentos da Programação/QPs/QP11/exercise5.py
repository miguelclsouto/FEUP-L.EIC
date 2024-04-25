
# RECURSION

def longest_prefix(words):
    
    if len(words) == 1:
        return words[0]
    
    left = longest_prefix(words[:len(words) // 2])
    
    
    right = longest_prefix(words[len(words) // 2:])
    
    
    maxim = max(len(left), len(right))
    
    
    for i in range(maxim):
        
        if left.startswith(right[:i + 1]):
            
            continue # next iteration
        
        return right[:i]
    
    return right[:maxim]
