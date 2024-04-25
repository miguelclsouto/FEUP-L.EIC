
import math
sum = 0

for i in range(0, 51):
    
    sum += ((math.factorial(4 * i) * (1103 + 26390 * i))/(math.factorial(i)**4 * 396**(4*i)))
    
p = (1 / ((2*math.sqrt(2)/9801)* (sum)))

print(round(p, 8))