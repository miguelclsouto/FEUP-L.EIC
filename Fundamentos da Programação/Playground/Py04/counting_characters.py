
l1 = 'How much wood would a woodchuck chuck if a woodchuck could chuck wood?'
l2 = 'w'

def count_chars(sent, let):
    
    count = 0
    
    length = len(sent)
    
    for i in range(length):
        
        if sent[i].upper == let.upper:
            
            count += 1
            
    if count == 0:
        
        return -1
    
    return count
            
# print(count_chars(l1, l2))