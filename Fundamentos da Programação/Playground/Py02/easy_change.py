price = int(input())
exchange = int(input()) - price

#index = 0

# a = [0] * 4
a = []

for i in [50, 20, 10, 5]:

    #a[index] = str(exchange // i)
    #a.insert(index,  str(exchange // i))
    
    a.append(str(exchange // i))
    exchange %= i
    
    #index += 1
    


print(*a, sep = " ")