n = int(input())

#sum = 0

# these numbers must be multiples of 5 or 3, but not multiples of 15

n3 = n // 3

n5 = n // 5

n15 = n // 15

sum15 = 15 * (n15 * (n15 + 1) // 2) # primeiros n15 numeros multiplos de 15

sum3 = 3 * (n3 * (n3 + 1) / 2) # primeiros n3 numeros multiplos de 3

sum5 = 5 * (n5 * (n5 + 1) / 2) # primeiros n5 numeros multiplos de 5

# n = int(input())

# m3 = range(0, n+1, 3)

# m5 = range(0, n+1, 5)

# m15 = range(0, n+1, 15)

# result = (sum(m3) + sum(m5)) - sum(m15)

# print(result)

print(round(sum5 + sum3 - sum15))