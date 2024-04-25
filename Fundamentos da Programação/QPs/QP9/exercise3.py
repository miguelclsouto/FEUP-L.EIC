
def x_union(list1, list2):
    
    x1 = list(map(lambda x: x[0], list1))
    
    x2 = list(map(lambda x: x[0], list2))

    f1 = filter(lambda x: x[0] not in x2, list1)
    
    f2 = filter(lambda x: x[0] not in x1, list2)
    
    return list(f1) + list(f2)
