word_list = ['hello', 'world', 'lousy']
a = "lousy world"

for i in range(3):
    
    word_list.append(a)
    
def get_positions(s, l):
    
    finalsent = ""
    r = s.split()
    
    for i in range(2):
        
        flag = True
        
        for j in range(3):
            
            if l[j] == r[i]: # ou s.find(l[j])
                
                finalsent += str(j) + " "
                
                flag = False
                break
            
        if flag:
            return ''
            
    return finalsent
    

if len(get_positions(a, word_list)) > 0:
    
    print(get_positions(a, word_list))
    
else:
    
    print("")