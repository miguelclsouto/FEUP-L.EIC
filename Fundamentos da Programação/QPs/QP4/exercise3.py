def var_numbers(number, precision = 2):

    numb = 0
    
    average = sum_numbers(number) / number

    for i in range(1, number + 1):
        
        numb += (i - average)**2
        
    numb /= number

    return round(numb, precision)

def sum_numbers(num):
    
    sum = 0
    
    for i in range(1, num + 1):
        
        sum += i
        
    return sum

