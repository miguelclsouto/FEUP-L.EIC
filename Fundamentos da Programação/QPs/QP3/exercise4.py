n = int(input())

if n % 2 == 1:
    temp1 = temp2 = n // 2 + 1
else:
    temp1 = n // 2
    temp2 = temp1 + 1

for i in range(1, n +1):
    for j in range (1, n + 1):
        
        if temp1 - 1 < j < temp2 + 1 and temp1 - 1 < i < temp2+1:
            
            print("0", end = "")
            
            continue
        
        print("#", end = "")
        
    print() # para fzr um espaco