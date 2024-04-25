
def variance(alist):

    aver = 1 / len(alist) * sum(alist)
    
    return round(sum(map(lambda x:(x - aver)**2, alist), 0) / len(alist), 3)
    
    

   
