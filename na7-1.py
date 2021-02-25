import numpy as np
import scipy as spy
import scipy.linalg as slinalg
from scipy.sparse import csr_matrix

# 行列
mat_a = [[1, -2], [-2, 1]]
mat_b = [[1, -2], [3, 4]]

# 行列確認
print('A = ', mat_a)
print('B = ', mat_b, '\n')

# 固有値と固有ベクトル
eigval_a, ev_a = slinalg.eig(mat_a)
ev_a = ev_a.T
print('Eigenvalues = ', eigval_a)
print('Eigenvectors = ', ev_a, '\n')

eigval_b, ev_b = slinalg.eig(mat_b)
ev_b = ev_b.T
print('Eigenvalues = ', eigval_b)
print('Eigenvectors = ', ev_b)

# A * v = lambda * v ?
for i in range(0, eigval_a.size):
  print('|| A * v - lambda[',i,'] * v ||_2 = ', slinalg.norm(mat_a@ev_a[i].T - eigval_a[i]*ev_a[i]), '\n')
for i in range(0, eigval_b.size):
  print('|| B * v - lambda[',i,'] * v ||_2 = ', slinalg.norm(mat_b@ev_b[i].T - eigval_b[i]*ev_b[i]))