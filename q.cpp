#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "MT.h"
using namespace std;

#define N 1000002
int n;
int data[N];

int ascend(int a, int b, int t)
{
	if(t==0) return a < b;
	else return a <= b;
}

/*****************************/
/* データの比較（降順）      */
/* a < bの場合に０以外（真） */
/*****************************/
int descend(int a, int b, int t)
{
	if(t==0) return a > b;
	else return a >= b;
}

/*****************************/
/* データの入れ替え          */
/*****************************/
void swap(int *left, int *right) {
  int *temp = left;
  left = right;
  right = temp;
}

/*****************************/
/* データの表示              */
/*****************************/
void prlong(int n, int *data){
  for(int i=0;i<n;i++) printf("%10d    :       %10d\n",i,data[i]);
}

void quick(int *data, int left, int right, int (*compare)(int, int, int)) {
  int d = data[left];
  int Lcnt = left+1, Rcnt = right;
  int p = left;
  
  while(1) {
    while( Lcnt <= right && compare(data[Lcnt], d, 0) ) Lcnt ++;
    while( Rcnt >= left && compare(d, data[Rcnt], 0) ) Rcnt --;
    
    if (Lcnt >= Rcnt) break;
    swap(data[Lcnt], data[Rcnt]);
    Lcnt ++;
    Rcnt --;
  }
  if( compare(data[Rcnt], d, 1) ){
    swap(data[left], data[Rcnt]);
  }
  p = Rcnt;
  printf("--------------%d-------%d------%d::%d:::::::%d\n",left,right,p,data[p],data[Rcnt]);
  cout << Lcnt << Rcnt << endl;
  prlong(n, data);
  if(left < p-1) quick(data, left, p-1, compare);
  if(p+1 < right) quick(data, p+1, right, compare);
  return;
}

int main() {
  cin >> n;
  for(long i=0;i<n;i++){
    cin >> data[i];
  }
  quick(data, 0, n-1, ascend);
  prlong(n, data);
  quick(data, 0, n-1, descend);
  prlong(n, data);
  return 0;
}