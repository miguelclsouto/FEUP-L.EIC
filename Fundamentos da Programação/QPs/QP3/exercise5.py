n1 = int(input())
n2 = int(input())

result = 0
while n1 != 0 and n2 != 0:
    temp = n1 % 10
    n1 = n1 // 10
    result = result * 10 + temp
    temp = n2 % 10
    n2 = n2 // 10
    result = result * 10 + temp
    
print(result)
    
# I could have also used Arrays / Lists
    