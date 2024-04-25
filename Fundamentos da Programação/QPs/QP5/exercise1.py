import re

def rm_letter_rev(ch, s):
    
    s = s[::-1]

    s = s.split(ch)
    
    string = ""
    
    for i in range(len(s)):
        
        string = string + s[i]
        
    return string
