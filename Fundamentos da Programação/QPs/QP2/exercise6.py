p = int(input("principal amount: "))
r = float(input("interest rate: "))
n = int(input("frequency the interest is paid out: "))

a = p * (1 + (r/n))**(2*n)
a = round(a, 3)
print(a)
1
