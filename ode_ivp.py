# ode_ivp.py : 常微分方程式の初期値問題
import numpy as np

# integrate パッケージ
import scipy.integrate as spint

# matplotlib
import matplotlib.pyplot as plt

# 陽的形式の右辺
# y' = func(t, y) = y
def func(t, y):
  #return y
#  return t ** 2 * y
  return -t * y

# 初期値
# y(0) = 1
y0 = [1.0]

# t = [0, 1]
t_interval = [0.0, 3.0]
print(t_interval)
#t_eval = np.linspace(t_interval[0], t_interval[1], 10)
# 常微分方程式を解く(1)
ret = spint.solve_ivp(func, t_interval, y0)
ret_fix = spint.solve_ivp(func, t_interval, y0, t_eval = np.linspace(t_interval[0], t_interval[1], 10))

# 結果を表示
#print(ret)

# yを表示
#print(ret.y)

print('')
print(ret_fix)

true = np.exp((-1/2)* 3.0 ** 2 )
print('')
ttt = np.linspace(t_interval[0], t_interval[1], 10)
ff = spint.odeint(func, y0, ttt)
print(true)
print(true- ff[9][0]/true)
print('rE(ans)               = ', np.abs( (true - ret.y[0][9]) / true) )
print('rE(ans)               = ', np.abs( (true - ff[9][0]) / true) )
print(ff[:,0])
# t-yグラフを描画
figure, axis = plt.subplots()

# 値をセット
#axis.plot(ret.t, ret.y[0, :], label='Automatic')
#axis.plot(ret_fix.t, ret_fix.y[0, :], label='t_eval')
#axis.plot(ttt, ff[0], lavel='odeint')
plt.plot(ttt, ff[:,0])

# x軸, y軸, グラフタイトルをセット
axis.set(xlabel = 't', ylabel = 'y', title = 'y\' = y')

# グリッドを描画
axis.grid()

# 凡例
axis.legend()

# グラフ保存ファイル名
figure.savefig('ode.png')

# グラフを画面に描画
plt.show()