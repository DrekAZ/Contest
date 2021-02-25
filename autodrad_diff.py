# autograd_diff.py : 自動微分
import numpy
import autograd.numpy as np
import autograd

# 元の関数
def func(x):
  #eturn x ** 2 # x^2
  return np.exp( np.sin(x) ) + 2 * x ** 3

# 真の導関数
def true_dfunc(x):
  #return 2 * x # 2x
  return np.exp( np.sin(x) ) * np.cos(x) + 6 * x ** 2

# x = [-5, 5]
x = np.linspace(-5, 5, 100)

# 自動微分による導関数
dfunc = autograd.elementwise_grad(func)
#dfunc = true_dfunc

# 相対誤差チェック
reldiff = np.abs((dfunc(x) - true_dfunc(x)) / true_dfunc(x))
print('reldiff = ', reldiff)