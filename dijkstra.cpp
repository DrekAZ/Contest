/****************************/
/* Dijkstra（最短経路）     */
/*      coded by Y.Suganuma */
/****************************/
#include <cstdio>
#include <set>

using namespace std;

class Net {
public :
  int node;   // ノード番号
  int r;   // スタートからの距離
  Net (int n1, int r1) {
    node = n1;
    r    = r1;
  }
};
bool operator< (Net n1, Net n2) {
  if (n1.r == n2.r) return  (n1.node < n2.node) ? true : false;
  else return  (n1.r < n2.r) ? true : false;
}

/********************************************/
/* Dijkstra（最短経路）                     */
/*      n : ノードの数                      */
/*          　ノード0:スタート              */
/*          　ノード(n-1):ゴール            */
/*      r : ノード間の距離                  */
/*      rd : 現時点におけるノードまでの距離 */
/*      used : 距離が確定したか否か         */
/********************************************/
void Dijkstra(int n, int **r, int *rd, bool *used) {
  int node = 1;
  set<Net> s;
  set<Net>::iterator it;

  s.insert(Net(0, 0));
  while (!s.empty()) {
    it    = s.begin();
    int k = it->node;   // ノード番号
    int v = it->r;   // スタートノードからの距離
    s.erase(it);
    
    if (!used[k]) {
      // 先頭のノードから到達可能なノードをセットに追加
      //　　・距離が決定しているノードは除く
      //　　・既にノードまでの距離が計算済みであり，その距離が
      //　　　今回計算した距離よりも短い場合は距離を修正して追加
      used[k] = true;
      for (int i1 = 0; i1 < n; i1++) {
        if (!used[i1] && r[k][i1] >= 0) {
          int r1 = v + r[k][i1];
          if (rd[i1] < 0 || r1 < rd[i1]) {
            s.insert(Net(i1, r1));
            rd[i1] = r1;
            node++;
          }
        }
      }
    } else node--;
  }

  printf("展開したノード数： %d，　最短距離： %d\n", node, rd[n-1]);
}

int main() {
  bool *used = new bool [7];
  int *rd    = new int [7];   // ノードまでの距離
  int **r    = new int * [7];   // ノード間距離
  for (int i1 = 0; i1 < 7; i1++) {
    used[i1] = false;
    rd[i1]   = -1;
    r[i1]    = new int [7];
    for (int i2 = 0; i2 < 7; i2++) r[i1][i2] = -1;
  }
  rd[0]   = 0;
  r[0][1] = 2;
  r[1][0] = 2;  
  r[0][2] = 5;
  r[2][0] = 5;
  r[1][2] = 4;
  r[2][1] = 4;
  r[1][3] = 6;
  r[3][1] = 6;
  r[1][4] = 10;
  r[4][1] = 10;
  r[2][3] = 2;
  r[3][2] = 2;
  r[3][5] = 1;
  r[5][3] = 1;
  r[4][5] = 3;
  r[5][4] = 3;
  r[4][6] = 5;
  r[6][4] = 5;
  r[5][6] = 9;
  r[6][5] = 9;

  Dijkstra(7, r, rd, used);

  return 0;
}