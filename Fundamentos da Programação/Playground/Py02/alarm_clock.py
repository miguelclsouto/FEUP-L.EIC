
h = int(input())
m = int(input())

h = (h + 6) % 24

temp = (m + 51) // 60

h += temp

m = (m + 51) % 60

print(f"{h:02}:{m:02}")