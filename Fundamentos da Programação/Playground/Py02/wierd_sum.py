
a = int(input())
b = int(input())

def wierd_sum(a, b):
    return (a - b) % 2 != 0 # if odd, True

sum = int(wierd_sum(a, b)) * (a * b) + a + b + abs(int(wierd_sum(a, b) - 1)) * (a + b)

print(sum)