def pattern_hunting(l1, l2, p):
    
    # assumindo a len de l1 == len de l2
    
    return sorted(list(filter(lambda x: x != None, map(lambda x: l1[x] if p in l2[x] and p not in l1[x] else l2[x] if p in l1[x] and p not in l2[x] else None, range(len(l1))))), reverse = True)

    # return sorted(list(filter(lambda x: p not in x and p in l2[l1.index(x)], l1)) + list(filter(lambda x: p not in x and p in l1[l2.index(x)], l2)), reverse = True)
    
    
    
def pattern_hunting2(l1, l2, p):

    length = len(l1)
    f = []
          
    for i in range(length):
        if p in l2[i]:

            f.append(l1[i])
            
    for i in range(length):
        if p in l1[i]:
            
            f.append(l2[i])
  
    return sorted(f, reverse = True)