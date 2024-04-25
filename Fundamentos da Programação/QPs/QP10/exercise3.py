
def pythagoreans(a, b):
    
    #list comprehension
    
    return [(x, y, z) for x in range(a, b) for y in range(x, b) for z in range(y, b) if z*z == x*x + y*y]