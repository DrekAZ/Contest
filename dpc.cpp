#include <cstdio>

using namespace std;

int dp(int p, int n_toshi, int step, int n_case, int **table, int **rieki, int **next) {
  int m = 0;
  // 最大利益の計算
  // １段目
  if (p == 0) {
    for (int i1 = 0; i1 < n_case; i1++) rieki[p][i1] = table[p][i1];
  }
  // ２段目以降
  else {
    for (int i1 = 0; i1 < n_case; i1++) {
      m       = step * i1;   // 投資額
      int l1  = -1;   // rieki[p][i1] は，
      int l2  = -1;   //    table[p][l1] + rieki[p-1][l2] で最大
      int max = -1;
      int m1  = 0;
      int k1  = 0;
      while (m1 <= m) {
        int m2 = 0;   // 前段
        int k2 = 0;   // 前段
        while (m1+m2 <= m) {
          int r = table[p][k1] + rieki[p-1][k2];
          if (r > max) {
            l1  = k1;
            l2  = k2;
            max = r;
          }
          m2 += step;
          k2++;
        }
        m1 += step;
        k1++;
      }
      next[p][i1] = l2;
      if (l2 >= 0) rieki[p][i1] = table[p][l1] + rieki[p-1][l2];
    }
  }
  // 次の投資先
  // 最終段より前
  if (p < n_toshi-1) m = dynamic(p+1, n_toshi, step, n_case, table, rieki, next);
  // 最終段
  else {
    int max = -1;
    int k1  = n_toshi - 1;
    for (int i1 = 0; i1 < n_case; i1++) {
      if (next[k1][i1] >= 0 && rieki[k1][i1] > max) {
        max = rieki[k1][i1];
        m   = i1;
      }
    }
  }

  return m;
}

int main() {
  // データの入力と領域の確保
  int n_toshi = 3;   // 投資先
  int step    = 1;   // 投資単位
  int n_case  = 5;   // 資金の投資ケース数
  int **table = new int * [n_toshi];   // 投資先，投資額，そのときの利益
  int **rieki = new int * [n_toshi];   // 現段階の最大利益
  int **next  = new int * [n_toshi];   // 最大利益を与える投資先
  for (int i1 = 0; i1 < n_toshi; i1++) {
    table[i1] = new int [n_case];
    rieki[i1] = new int [n_case];
    next[i1]  = new int [n_case];
  }
  /*table[0][0] = 0;
  table[0][1] = 8;
  table[0][2] = 18;
  table[0][3] = 22;
  table[0][4] = 24;
  table[1][0] = 0;
  table[1][1] = 3;
  table[1][2] = 6;
  table[1][3] = 9;
  table[1][4] = 12;
  table[2][0] = 0;
  table[2][1] = 6;
  table[2][2] = 7;
  table[2][3] = 8;
  table[2][4] = 10;*/
  
  table[0][0] = 0;
  table[0][1] = 2;
  table[1][0] = 2;  
  table[0][2] = 5;
  table[2][0] = 5;
  table[1][2] = 4;
  table[2][1] = 4;
  table[1][3] = 6;
  table[3][1] = 6;
  table[1][4] = 10;
  table[4][1] = 10;
  table[2][3] = 2;
  table[3][2] = 2;
  table[3][5] = 1;
  table[5][3] = 1;
  table[4][5] = 3;
  table[5][4] = 3;
  table[4][6] = 5;
  table[6][4] = 5;
  table[5][6] = 9;
  table[6][5] = 9;
  
  // 実行
  int max = dynamic(0, n_toshi, step, n_case, table, rieki, next);
  // 結果の出力
  if (max >= 0) {
    printf("最大利益 %d\n", rieki[n_toshi-1][max]);
    for (int i1 = n_toshi-1; i1 >= 0; i1--) {
      int k = max * step;
      if (i1 > 0) {
        max  = next[i1][max];
        k   -= max * step;
      }
      printf("   投資先 %d 投資資金 %d\n", i1+1, k);
    }
  } else printf("解が存在しません！\n");

  return 0;
}