import math

angle = int(input())*math.pi/180  # convert to radians

cos_angle = math.cos(angle)
sin_angle = math.sin(angle)

vi = 18
g = - 10
t = 0
vx = cos_angle * vi # vx0 = vx constant -> ax = 0

vy0 = vi * sin_angle
#vy = vy0 + g * t

t = vy0 / 5

x = vx * t

print(round(x))