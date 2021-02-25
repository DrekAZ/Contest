# basic_matrix.py : 行列の基本演算
import numpy as np

# 行列の定義
mat_a = np.array([[1, 2, 3], [2, 2, 3], [3, 3, 3]])
print('mat_a = \n', mat_a)

# ベクトルの定義
vec_a = np.array([1, 2, 3])
print('vec_a = ', vec_a)

# BLAS Level2
# 行列, ベクトル演算: 行列・ベクトル積
mat_av = mat_a.dot(vec_a)
print('A * a = ', mat_av)

# BLAS Level3
# 行列演算: 行列積
mat_b = np.array([[-3, -3, -3], [-3, -2, -2], [-3, -2, -1]])
mat_ab = mat_a.dot(mat_b)
print('A * B = \n', mat_ab)
mat_ab_at = mat_a @ mat_b
print('A @ B = \n', mat_ab_at)