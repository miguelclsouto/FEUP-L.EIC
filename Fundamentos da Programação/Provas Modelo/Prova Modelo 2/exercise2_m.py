def next_prime(number):
    
    number += 1
    
    while not prime(number):
        
        number += 1
    
    return number

def prime(num):
    
    for i in range(2, num // 2):
        
        if num % i == 0:
            
            return False
        
    return True