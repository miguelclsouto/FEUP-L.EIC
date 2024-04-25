def longest(s):
    
    length = 0
    s = s.split()
    
    for i in s:
        if length < len(i):
            
            length = len(i)
            
    return length # return len(max(words, key=len))