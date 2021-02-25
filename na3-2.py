import math

a = input('a = ')
b = input('b = ')
c = input('c = ')

a, b, c = float(a), float(b), float(c)

d = b**2 - 4*a*c
print('d = ', d)

x1 = ( -b + math.sqrt(d) ) / (2*a)
x2 = ( -b - math.sqrt(d) ) / (2*a)
print('x1 = ', x1)
print('x2 = ', x2)