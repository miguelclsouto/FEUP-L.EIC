def academy_awards(alist):
    
    # ou tb podes usar o metodo count()
    
    dict = {}
    length = len(alist)
    
    for i in range(length):
        if alist[i][1] in dict.keys():
            
            dict[alist[i][1]] += 1
        else:
            
            dict[alist[i][1]] = 1
            
    return dict