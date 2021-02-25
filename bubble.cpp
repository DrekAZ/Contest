/****************************/
	/* バブルソート             */
	/*      coded by Y.Suganuma */
	/****************************/
	#include <cstdio>
	#include <ctime>
	#include "MT.h"
	
	#define N 5000000
	int data[N];
	using namespace std;
	/*****************************/
	/* データの比較（昇順）      */
	/* a > bの場合に０以外（真） */
	/*****************************/
	int ascend(int a, int b)
	{
		return a > b;
	}
	
	/*****************************/
	/* データの比較（降順）      */
	/* a < bの場合に０以外（真） */
	/*****************************/
	int descend(int a, int b)
	{
		return a < b;
	}
	
	/*************************************/
	/* ２つのデータを交換する            */
	/*      a,b : ２つのデータのアドレス */
	/*************************************/
	void swap(int *a, int *b)
	{
		int temp = *a;
		*a       = *b;
		*b       = temp;
	}
	
	/*********************************/
	/* バブルソート                  */
	/*      n : データの数           */
	/*      data : データ            */
	/*      compare : 比較を行う関数 */
	/*********************************/
	int bb(int n, int *data, int (*compare)(int, int))
	{
		int sw = 0;
		if (n > 1) {
			for (int i1 = 0; i1 < n-1; i1++) {
				if (compare(data[i1], data[i1+1])) {
					sw = 1;
					swap(&data[i1], &data[i1+1]);
				}
			}
		}
	
		//if (sw > 0)
		//	bubble(n-1, data, compare);
		return sw;
	}
	
  void bubble(int n, int *data, int (*compare)(int, int)) {
	  while (n>1) {
	    int sw = bb(n, data, compare);
	    if (sw == 0) break;
	    n --;
	  }
	}
	
	void k(int n, int *data){
	  for(int i=0;i<n;i++) printf("%10d    :       %10d\n",i,data[i]);
	}
	
	int main()
	{
				// 初期設定
		init_genrand((unsigned)time(NULL));
				// 昇順
		clock_t tm1 = clock();
		for (int i1 = 0; i1 < N; i1++)
			data[i1] = genrand_int31();   // [0,0x7fffffff]
		clock_t tm2 = clock();
		bubble(N, data, ascend);
		clock_t tm3 = clock();
		k(N, data);
		printf("昇順（データ数： %d）\n", N);
		printf("   data %d ms\n", (int)(tm2-tm1));
		printf("   sort %d ms\n", (int)(tm3-tm2));
		// 降順
		tm1 = clock();
		for (int i1 = 0; i1 < N; i1++){
			data[i1] = genrand_int31();
		}
		tm2 = clock();
		bubble(N, data, descend);
		tm3 = clock();
		k(N, data);
		printf("降順（データ数： %d）\n", N);
		printf("   data %d ms\n", (int)(tm2-tm1));
		printf("   sort %d ms\n", (int)(tm3-tm2));
	
		return 0;
	}