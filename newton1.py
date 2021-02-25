# newton1.py : Newton法
import numpy as np
import scipy.optimize as sopt

# f(x) = 0
def func(x):
# return x - np.cos(x)
#  return x - np.sin(x)
  return np.exp(-x) -3

# f'(x) = 0
def dfunc(x):
# return 1 + np.sin(x)
#  return 1 - np.cos(x)
  return -np.exp(-x)

# 初期値
x0 = 1.0

# 停止条件
atol = 0
rtol = 1.0e-8

# Newton反復
x_old = x0
for times in range(0, 100):
  print(func(x_old), '=========', dfunc(x_old))
  x_new = x_old - func(x_old) / dfunc(x_old)
  print(f'x_{times:d} = {x_new:25.17e}, {func(x_new):10.3e}')
  if  np.abs(x_new - x_old) <= rtol * np.abs(x_old) + atol:
    break
  x_old = x_new

# 表示
print(f'最終 -> x_{times:d} = {x_new:25.17e}')
print(f'検算 -> func(x_{times:d}) = {func(x_new):25.17e}')

# 桁数
digits = np.floor( -np.log10( np.abs(func(x_new)) ) )
print('digits = ', digits)