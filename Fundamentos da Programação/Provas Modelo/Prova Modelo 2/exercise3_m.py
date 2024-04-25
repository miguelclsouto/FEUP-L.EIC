def total_distance(dist, cities):
    space = 0
    
    for i in range(len(cities) - 1):
        
        distance = (cities[i], cities[i+1])
        
        if dist.get(distance) == None and dist.get(distance[::-1]) == None:
            
            return -1
        
        space += dist.get(distance, 0) + dist.get(distance[::-1], 0)
        
    return space
        