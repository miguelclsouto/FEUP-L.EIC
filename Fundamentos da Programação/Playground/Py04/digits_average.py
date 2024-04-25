import math


def digits_average(n):
    
    average = 0
    
    while True:
        
        average = 0
        index = 1
        
        while True:
            
            temp = n % 10
            n //= 10
            
            
            average += math.ceil(((temp + n % 10) / 2)) * index
            
            
            index *= 10

            if n // 10 == 0:
                break

        n = average
        
        if n < 10: 
            
            return average