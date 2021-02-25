import numpy as np
import scipy.integrate as spint
import time

def nonstiff_func(t, y):
  z = [
      -2.0 * y[0] + y[1] - np.cos(t),
      2.0 * y[0] -3.0 * y[1] + 3.0 * np.cos(t) - np.sin(t)
  ]
  return z;
  
def stiff_func(t, y):
  z = [
      -2.0 * y[0] + y[1] - np.cos(t),
      1998.0 * y[0] - 1999.0 * y[1] + 1999.0 * np.cos(t) - np.sin(t)
  ]
  return z;

# 解析解
def ans(t):
  return [np.exp(-t), np.exp(-t) + np.cos(-t)]


# 初期値
y0 = [1.0, 2.0]

# t = [0, 20]
t_interval = [0.0, 20.0]
print(t_interval)

# Non-stiff & RK45
stime = time.time()
ret_nonstiff = spint.solve_ivp(nonstiff_func, t_interval, y0, method = 'RK45', rtol = 1.0e-5, atol = 0.0)
time_ret_nonstiff = time.time() - stime

# stiff
#stime = time.time()
#ret_stiff = spint.solve_ivp(stiff_func, t_interval, y0, method = 'RK45')
#time_ret_stiff = time.time() - stime

# non-stiff & radau
#stime = time.time()
#ret_radau_nonstiff = spint.solve_ivp(nonstiff_func, t_interval, y0, method = 'Radau')
#time_ret_radau_nonstiff = time.time() - stime


# stiff
stime = time.time()
ret_radau_stiff = spint.solve_ivp(stiff_func, t_interval, y0, method = 'Radau', rtol = 1.0e-5, atol = 0.0)
time_ret_radau_stiff = time.time() - stime

# 計算時間と総ステップ数
print('time_ret_nonstiff,  steps      = ', time_ret_nonstiff, ret_nonstiff.t.size)
#print('time_ret_stiff,     steps      = ', time_ret_stiff, ret_stiff.t.size)
#print('time_ret_radau_nonstiff, steps = ', time_ret_radau_nonstiff, ret_radau_nonstiff.t.size)
print('time_ret_radau_stiff,  steps   = ', time_ret_radau_stiff, ret_radau_stiff.t.size)

# 相対誤差
true_y = ans(ret_nonstiff.t); relerr_ret_nonstiff = np.abs((ret_nonstiff.y - true_y) / true_y)
#true_y = ans(ret_stiff.t); relerr_ret_stiff = np.abs((ret_stiff.y  - true_y) / true_y)
#true_y = ans(ret_radau_nonstiff.t); relerr_ret_radau_nonstiff = np.abs((ret_radau_nonstiff.y - true_y) / true_y)
true_y = ans(ret_radau_stiff.t); relerr_ret_radau_stiff = np.abs((ret_radau_stiff.y - true_y) / true_y)

# tとy の表示
print('t_end_nonstiff = ', ret_nonstiff.t[-1])
print('y_end_nonstiff = ', ret_nonstiff.y[0, -1], ret_nonstiff.y[1, -1])
print('relerr_nonstiff = ', relerr_ret_nonstiff[0, -1], relerr_ret_nonstiff[1, -1])
#print('t_end_stiff = ', ret_stiff.t[-1])
#print('y_end_stiff = ', ret_stiff.y[0, -1], ret_stiff.y[1, -1])
#print('relerr_end_stiff = ', relerr_ret_stiff[0, -1], relerr_ret_stiff[1, -1])
print('')
#print('t_end_nonstiff_radau = ', ret_radau_nonstiff.t[-1])
#print('y_end_nonstiff_radau = ', ret_radau_nonstiff.y[0, -1], ret_radau_nonstiff.y[1, -1])
#print('relerr_nonstiff_radau = ', relerr_ret_radau_nonstiff[0, -1], relerr_ret_radau_nonstiff[1, -1])
print('t_end_stiff_radau = ', ret_radau_stiff.t[-1])
print('y_end_stiff_radau = ', ret_radau_stiff.y[0, -1], ret_radau_stiff.y[1, -1])
print('relerr_end_stiff_radau = ', relerr_ret_radau_stiff[0, -1], relerr_ret_radau_stiff[1, -1])