def check_friendly(number_one, number_two):
    
    if number_one == number_two:
        
        return 'identical numbers: ' + str(number_one) 
    
    elif divisors(number_one) == number_two and divisors(number_two) == number_one:
        
        answer = str(number_one) + ' and ' + str(number_two) + ' are friendly'
        return answer
    
    elif divisors(number_one) != number_two:
        
        return 'sum of divisors of ' + str(number_one) + ' is not ' + str(number_two)
    
    else:
        
        return 'sum of divisors of ' + str(number_two) + ' is not ' + str(number_one)
        
def divisors(num):
    
    sum = 0
    
    for i in range(1, num // 2 + 1):
        
        if num % i == 0:
            
            sum += i
            
    return sum