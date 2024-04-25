from math import sqrt as sqr

a = int(input())
b = int(input())
c = int(input())

quadform1 = (-b + sqr(b**2 - 4*a*c))/ (2*a)

quadform2 = (-b - sqr(b**2 - 4*a*c))/ (2*a)

print("The solutions are", round(quadform1,2), "and", round(quadform2,2))