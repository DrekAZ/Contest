import re

vw = [] # value / weight のList
knapsack = [] # ナップサックの中身
now_w = 0
now_v = 0

def Input_File(path):
  value, weight = [], []
  with open(path) as f:
    line = re.sub('#.*', '', f.readline())
    n = int(line)
    
    line = re.sub('#.*', '', f.readline())
    weight_max = int(line)
    
    line = f.readline().split(' ')
    for j in range(n):
      value.append( int( line[j] ) )
    
    line = f.readline().split(' ')
    for j in range(n):
      weight.append( int( line[j] ) )
    
  return n, weight_max, value, weight

if __name__=="__main__":
  # テキストファイルのデータを読み込む
  path = input('path = ')
  n, weight_max, value, weight = Input_File(path)
  # 価値が高いものに合わせて同時にsort
  for i in range(n):
    vw.append( value[i]/weight[i] )
  
  temp = sorted( zip(vw, value, weight), reverse=True )
  vw, value, weight = zip(*temp)
  
  for i in range(n):
    if weight[i] + now_w < weight_max:
      now_w += weight[i]
      now_v += value[i]
      knapsack.append(1)
    else :
      knapsack.append(0)
  
  print('Weight = ', now_w)
  print('Value = ', now_v)
  print('knapsack :', knapsack)