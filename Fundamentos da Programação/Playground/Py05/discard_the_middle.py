
def discard_middle(s):
    
    if len(s) < 4:
        
        return ""
    
    return s[:2] + s[-2:] # return (s[:2] + s[-2:]) * len(s) >= 4