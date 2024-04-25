
def bubble_sort(alist):
    
    # finish = False
    
    for i in range(len(alist)): # ou podia usar um while aqui com a var finish
        
        finish = True # flag
        
        for j in range(len(alist) - 1):
            
            if alist[j] > alist[j + 1]:
                
                finish = False
                
                #temp = alist[j]
                #alist[j] = alist[j + 1]
                #alist[j + 1] = temp
                alist[j], alist[j + 1] = alist[j + 1], alist[j]
                
        if finish:
            return alist
        
    return alist