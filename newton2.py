# Newton法
import numpy as np
import scipy.optimize as sopt

# f(x) = 0
def func(x):
#  return [x[0] + x[1] -3, x[0] * x[1] -2]
  return [
    x[0] + x[1] + x[2] -6,
    x[0] * x[1] * x[2] -6,
    x[0] **2 + x[1] **2 + x[2] **2 -14
  ]

# f'(x) = 0
def dfunc(x):
#  return np.array([
#    [1, 1],
#    [x[1], x[0]]
#  ])
  return np.array([
    [1, 1, 1],
    [x[1] * x[2], x[0] * x[2], x[0] * x[1]],
    [2 * x[0], 2 * x[1], 2 * x[2]]
  ])

# 初期値
x0 = [2, 3, 4]

# root関数(1) Root func
final = sopt.root(func, x0)

# 表示
print('最終 -> x = ')
for i in range(0, (final.x).size):
  print(f'{i:3d}, {final.x[i]:25.17e}')

print('検算 -> f(x) = ')
for i in range(0, (final.fun).size):
  print(f'{i:3d}, {final.fun[i]:25.17e}')

print('\n')
# root関数(2) jacobi
final = sopt.root(func, x0, jac = dfunc)

# 表示
print('最終 -> x = ')
for i in range(0, (final.x).size):
  print(f'{i:3d}, {final.x[i]:25.17e}')
print('検算 -> f(x) = ')
for i in range(0, (final.fun).size):
  print(f'{i:3d}, {final.fun[i]:25.17e}')