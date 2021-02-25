import mpmath

mpmath.mp.dps = 20 # 蚊数部の10進数桁数

x = [mpmath.mp.mpf('0.7501')]

for i in range(0, 100):
  x.append(4 * x[i] * (1 - x[i]))
  
for i in range(0, 101):
  if i % 10 == 0:
    print(i, ',', x[i])
