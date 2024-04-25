def palindrome_index(s):

    l = list(filter(lambda n : (s[:n] + s[n + 1:]) == (s[:n] + s[n + 1:])[::-1] , range(len(s))))
    l.append(-1)
    
    return -1 if s == s[::-1] else l[0]

def palindrome_index2(s):
    
    #palindrome = False
    
    for i in range(0, len(s) // 2):
        
                
        if s[i] != s[-i - 1]:
            
            temp1 = s[i]
            temp2 = s[-i + 1]
            
            if s[i] != s[-i - 1 - 1] and s[-i - 1] == s[i + 1]:
                
                return i
            
            if s[-i - 1] != s[i + 1] and s[i] == s[-i - 1 - 1]:
                
                return - i - 1 + len(s)
                
    return -1

