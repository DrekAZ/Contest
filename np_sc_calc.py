import numpy as np
import scipy as sc

#a = 3.0
a = -3.0
#z = -1.0 + 2.0 * 1j
z = -1.0 + 2.0 * 1j

print('a = ', a)
print('z = ', z)

# 平方根
print('np.sqrt(a) = ', np.sqrt(a))
print('np.sqrt(z) = ', np.sqrt(z))

# 平方根: scipy
print('sc.sqrt(a) = ', sc.sqrt(a))
print('sc.sqrt(z) = ', sc.sqrt(z))

c = np.sqrt(a); w = np.sqrt(z)
print(c ** 2)
print(w ** 2)

c = sc.sqrt(a); w = sc.sqrt(z)
print(c ** 2)
print(w ** 2)

print(np.exp(a))
print(np.sin(a))
print(np.log(a))
print(np.log10(a))
print(np.exp(a))
print(np.sin(z))
print(np.log(z))
print(np.log10(z))

print(sc.exp(a))
print(sc.sin(a))
print(sc.log(a))
print(sc.log10(a))
print(sc.exp(z))
print(sc.sin(z))
print(sc.log(z))
print(sc.log10(z))
