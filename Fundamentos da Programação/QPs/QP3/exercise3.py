num = int(input())

final = 0

index = 10

index2 = 1

while True:


    temp = num % 10
    
    num = num // 10

    final = final * 10 + temp

    if num == 0:
        break


print(final)