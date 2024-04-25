
n = int(input())

num = 0
i = 0

valid = True


while n != 0:
    
    temp = n % 10
    
    if temp > 7:
        
        valid = 0
        break
    
    num += temp * 8**i
    i += 1
    
    n //= 10
    
    
if valid:
    
    print(num)
    
else:
    
    print("Not a valid number.")