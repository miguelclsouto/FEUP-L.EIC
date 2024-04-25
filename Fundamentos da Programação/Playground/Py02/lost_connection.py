import math
def time_until_lost_connection(direction_A, direction_B): # direction is an angle
    
    angle = math.radians(abs(direction_A - direction_B)) # direction is an angle
    
    v = 5 / 60 # dist por min # km / min if v = 5 km / h
    t = 0
    
    cosa = math.cos(angle)
    
    t = 2 * v**2 - 4 * v * cosa
    
    d = 35
    
    d0 = math.sqrt(35**2 / (2 * (1 - cosa))) # distance to the origin
    
    t = d0 / v
    
    return round(t, 3)        
