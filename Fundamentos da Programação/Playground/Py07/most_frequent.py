from functools import reduce

# 1 complexity
def most_frequent(alist):
    return max(zip(map(lambda x: alist.count(x), alist), alist))[1]

# 2 complexity
def most_frequent2(alist):
    return reduce(lambda x, y: x if alist.count(x) > alist.count(y) else y, alist)

    # return max(zip(map(lambda x: alist.count(x), alist), alist))[1]

def most_frequent3(alist):
    
    dict = {}
    length = len(alist)
    
    for i in range(length):
        if alist[i] in dict.keys():
            
            dict[alist[i]] += 1
        else:
            
            dict[alist[i]] = 1
            
    maximum = max(dict.values())
    l = []
    alist = list(set(alist))
    
    for i in range(len(alist)):
        if dict[alist[i]] == maximum:
            
            l.append(alist[i])
            
    return max(l)