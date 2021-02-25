import math

# exp(x)
def maclaurin_e(m):
  old_ret = 1.0
  ret = old_ret
  coef = 1.0
  for i in range(1, m):
    coef /= i
    ret = old_ret + coef
    old_ret = ret
  
  return ret

e = math.exp(1)
print (' m           hat(e_m)           relerr')
for m in range(1, 18):
  e1 = maclaurin_e(m)
  relerr = abs(e-e1) / abs(e)
  print(f'{m:3d} {maclaurin_e(m):25.17e} {relerr:10.3e}')
  