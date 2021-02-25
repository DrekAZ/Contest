#python による遺伝的アルゴリズム
#作成：高野 敏明
#遺伝子型[0|1] 評価値は遺伝子の一番最後につける
#遺伝的アルゴリズム
#世代生成 -> 交叉選択 -> 突然変異 -> 世代評価 -> 淘汰 -> 新世代
#突然変異(確率:Pm) : 1つの遺伝子を{0|1}反転

import numpy as np
import random
import copy
import re

#定義変数
pen = 5 # ペナルティ
weight_max = 0
value = []
weight = []

GEN_NUM = 15 #集団の個体数
GEN_LEN = 0 #遺伝子長
GEN = 1000 #世代交代数
Pm = 0.01 #突然変異確率



Elite = [] #エリート保存戦略でつかう

random.seed() #乱数シードの決定

def Input_File(path):
  value, weight = [], []
  with open(path) as f:
    line = re.sub('#.*', '', f.readline())
    GEN_LEN = int(line)
    
    line = re.sub('#.*', '', f.readline())
    weight_max = int(line)
    
    line = f.readline().split(' ')
    for j in range(GEN_LEN):
      value.append( int( line[j] ) )
    
    line = f.readline().split(' ')
    for j in range(GEN_LEN):
      weight.append( int( line[j] ) )
    
  return GEN_LEN, weight_max, value, weight

def Create_Generation():
    gene=[]
    for i in range(GEN_NUM):
        genome = []
        v, w = 0, 0
        for j in range(GEN_LEN):
            genome.append(random.randint(0,1))
            w += genome[j] * weight[j]
            v += genome[j] * value[j] - pen * max(0, w - weight_max)
        genome.append(v)
        gene.append(genome)
    return gene

def Evaluation(gene):
    global Elite
    gene_eval = []
    for i in range(len(gene)):
        v, w = 0, 0
        for j in range(len(gene[i])-1):
            w += gene[i][j] * weight[j]
            v += gene[i][j] * value[j] - pen * max(0, w - weight_max)
        gene[i][-1] = v
        if(Elite[-1] < gene[i][-1]):
          Elite = copy.deepcopy(gene[i])

        gene_eval.append(gene[i])
    return copy.deepcopy(gene_eval)

def Progress_Crossover(gene):
    gene_cross = []
    for i in range(int(GEN_NUM/2)):
        a = random.randint(0,len(gene)-1)
        b = random.randint(0,len(gene)-1)
        while(a==b):
            b = random.randint(0,len(gene)-1)
        if(a < b):
            child1, child2 = One_Point_Crossover(gene[a],gene[b])
            gene.pop(b)
            gene.pop(a)
        else:
            child1, child2 = One_Point_Crossover(gene[a],gene[b])
            gene.pop(a)
            gene.pop(b)
        gene_cross.append(child1)
        gene_cross.append(child2)
    return copy.deepcopy(gene_cross)

def One_Point_Crossover(parent1, parent2):
    child1 = parent1
    child2 = parent2
    point = random.randint(0,GEN_LEN-2)
    child1[point+1:] = parent2[point+1:]
    child2[point+1:] = parent1[point+1:]
    return copy.deepcopy(child1), copy.deepcopy(child2)

def Mutation(gene):
    Mu_gene = []
    for i in range(len(gene)):
        for j in range(GEN_LEN):
            p = random.random()
            if(p < Pm):
                gene[i][j] = abs(gene[i][j]-1)
        Mu_gene.append(gene[i])
    return copy.deepcopy(Mu_gene)

def Roulette_Selection(gene):
    gene_next = []
    dart = []
    total = 0.0
    fits = 0.0

    for i in range(len(gene)):
        total += gene[i][-1]
    for i in range(GEN_NUM):
        dart.append(random.random())
    for i in range(len(gene)):
        fits += gene[i][-1]
        for j in range(len(dart)):
            if(dart[j] < (fits/total)):
                gene_next.append(gene[j])
                dart[j] = 1.1
    return copy.deepcopy(gene_next)

if __name__=="__main__":
    path = input('path = ')
    GEN_LEN, weight_max, value, weight = Input_File(path)
    for i in range(GEN_LEN):
      Elite.append(0)

    Current_Gene = Create_Generation()
    Current_Gene = Evaluation(Current_Gene)
    Next_Gene = copy.deepcopy(Current_Gene)

    gene_arr = np.array(Current_Gene)
    print("1st Generation:")
    print(gene_arr)

    for ite in range(1,GEN):
        Current_Gene.extend( [copy.deepcopy(Elite)] )
        Current_Parent = copy.deepcopy(Current_Gene)
        Next_Gene = Progress_Crossover(Current_Gene)
        Next_Gene = Mutation(Next_Gene)
        Next_Gene = Evaluation(Next_Gene)
        Next_Gene.extend(Current_Parent)
        Current_Gene = Roulette_Selection(Next_Gene)
        #途中で表示する
        #gene_arr = np.array(Current_Gene)
        #print(ite+1,"th Generation:")
        #print(gene_arr)
        
    gene_arr = np.array(Current_Gene)
    print("Last Generation:")
    print(gene_arr)
    print("Elite")
    print(np.array(Elite))