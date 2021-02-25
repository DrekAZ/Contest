import numpy as np
import scipy as sc

a = np.sqrt(2) * 100000
a1 = 141421

abs_err = np.abs(a-a1)
rel_err = abs_err/np.abs(a)
digit10 = np.floor( -sc.log10( rel_err ) )
digit2 = np.floor( -sc.log2( rel_err ) )

print('a = ', a, 'a1 = ', a1)
print('1. |a - a1| = ', abs_err)
print('2. |(a - a1) / a| = ', rel_err)
print('3. a1 の 10進有効桁数 = ', digit10)
print('4. a2 の 2進有効桁数 = ', digit2)

print( -sc.log10( rel_err))