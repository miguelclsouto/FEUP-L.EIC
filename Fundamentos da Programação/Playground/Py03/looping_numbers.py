
n = int(input())
not_loop = False


while (n // 10) != 0:
    
    temp1 = n % 10
    n = n // 10
    
    temp2 = n % 10
    
    if not (temp1 - temp2 == 1 or abs(temp1 - temp2) == 9):
        
        not_loop = True
        break


if not_loop:
    
    print("Not a looping number")
    
else:
    
    print("Looping number")

        