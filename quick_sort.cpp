#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "MT.h"
using namespace std;

#define N 5000000
long data[N];
/*****************************/
/* データの比較（昇順）      */
/* a > bの場合に０以外（真） */
/*****************************/
long ascend(long a, long b, long t)
{
	if(t==0) return a < b;
	else return a <= b;
}

/*****************************/
/* データの比較（降順）      */
/* a < bの場合に０以外（真） */
/*****************************/
long descend(long a, long b, long t)
{
	if(t==0) return a > b;
	else return a >= b;
}

/*****************************/
/* データの入れ替え          */
/*****************************/
void swap(long *left, long *right) {
  long *temp = left;
  left = right;
  right = temp;
}

/*****************************/
/* データの表示              */
/*****************************/
void print(long n, long *data){
  for(long i=0;i<n;i++) printf("%10ld    :       %10ld\n",i,data[i]);
}

void quick(long *data, long left, long right, long (*compare)(long, long, long)) {
  long d = data[left];
  long Lcnt = left+1, Rcnt = right;
  long p = left;
  
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
  if(left < p-1) quick(data, left, p-1, compare);
  if(p+1 < right) quick(data, p+1, right, compare);
  return;
}

int main()
{
  // 初期設定
	init_genrand((unsigned)time(NULL));
	// 昇順
	clock_t tm1 = clock();
	for (long i1 = 0; i1 < N; i1++) {
	  data[i1] = genrand_int31();
	}
	clock_t tm2 = clock();
	//printf("-----------------ソート前-------------------\n");
	//print(N, data);
	quick(data, 0, N-1, ascend);
	//printf("-----------------ソート後-------------------\n");
	//print(N, data);
	clock_t tm3 = clock();
	printf("昇順（データ数： %d）\n", N);
	printf("   data %d ms\n", (int)(tm2-tm1));
	printf("   sort %d ms\n", (int)(tm3-tm2));
	printf("\n");
	// 降順
	tm1 = clock();
	for (long i1 = 0; i1 < N; i1++) {
	  data[i1] = genrand_int31();
	}
	tm2 = clock();
	//printf("-----------------ソート前-------------------\n");
	//print(N, data);
	quick(data, 0, N-1, descend);
	//printf("-----------------ソート後-------------------\n");
	//print(N, data);
	tm3 = clock();
	printf("降順（データ数： %d）\n", N);
	printf("   data %d ms\n", (int)(tm2-tm1));
	printf("   sort %d ms\n", (int)(tm3-tm2));
  
	return 0;
}