def square_odds(values):
    
    
    temp = values.split(',') # lista
    
    # tenho que transformar em str para poder usar o join
    
    
    temp = map(lambda x: str(x), map(lambda x : x * x, filter(lambda x: x % 2 == 1, map(lambda x: int(x), temp))))
    
    
    # tenho que transformar em str para poder usar o join
    
    
    temp = ','.join(temp)
    
    return temp