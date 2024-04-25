num = int(input("Indica um número com 4 digitos: "))
a = num // 1000
b = (num // 100) % 10
c = (num // 10) % 10
d = num % 10

print(a * 1000)
print(b * 100)
print(c * 10)
print(d)