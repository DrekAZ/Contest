import numpy as np
import scipy.linalg as splinalg

# mat_a

# ユークリッドノルム
print('||mat_a||_2 = ', np.linalg.norm(mat_a))
print('||mat_a||_2 = ', splinalg.norm(mat_a))

# 1ノルム
print('||mat_a||_1 = ', np.linalg.norm(mat_a, 1))
print('||mat_a||_1 = ', splinalg.norm(mat_a, 1))

# 無限大ノルム
print('||mat_a||_inf = ', np.linalg.norm(mat_a, np.inf))
print('||mat_a||_inf = ', splinalg.norm(mat_a, np.inf))

# frobenius ノルム 行列のみ
print('||mat_a||_fro = ', np.linalg.norm(mat_a, 'fro'))
print('||mat_a||_fro = ', splinalg.norm(mat_a, 'fro'))