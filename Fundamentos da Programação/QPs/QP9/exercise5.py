from functools import reduce

def bounding_box(pts):
    
    
    lx = list(map(lambda x: x[0], pts))
    ly = list(map(lambda x: x[1], pts))


    xmax = reduce(greater_equal,lx)
    xmin = reduce(less,lx)
    ymax = reduce(greater_equal,ly)
    ymin = reduce(less,ly)
    
    
    return (xmin, ymin, xmax,ymax)


def less(a, b):
    
    if a < b:
        
        return a
    
    return b



def greater_equal(a, b):
    
    if a >= b:
        
        return a
    
    return b
