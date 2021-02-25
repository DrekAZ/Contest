/****************************/
	/* 選択ソート               */
	/*      coded by Y.Suganuma */
	/****************************/
	#include <cstdio>
	#include <ctime>
	#include "MT.h"
  
  #define N 5000000
  long data[N];
  using namespace std;
	
	/*****************************/
	/* データの比較（昇順）      */
	/* a > bの場合に０以外（真） */
	/*****************************/
	long ascend(long a, long b)
	{
		return a > b;
	}
	
	/*****************************/
	/* データの比較（降順）      */
	/* a < bの場合に０以外（真） */
	/*****************************/
	long descend(long a, long b)
	{
		return a < b;
	}
	
	/*************************************/
	/* ２つのデータを交換する            */
	/*      a,b : ２つのデータのアドレス */
	/*************************************/
	void swap(long *a, long *b)
	{
		long temp = *a;
		*a       = *b;
		*b       = temp;
	}
	
	void ss(long n, long *data, long (*compare)(long, long)){
	  long i1, m;
		
		if (n > 1) {
			m = 0;
			for (i1 = 1; i1 < n; i1++) {
				if (compare(data[m], data[i1])) m = i1;
			}
			if (m != 0) swap(&data[0], &data[m]);

			//select(n-1, &data[1], compare);
		}
	}
	
	/*********************************/
	/* 選択ソート                    */
	/*      n : データの数           */
	/*      data : データ            */
	/*      compare : 比較を行う関数 */
	/*********************************/
	void select(long n, long *data, long (*compare)(long, long))
	{
	  long i = 0;
		while(n - i > 1) {
		  ss(n-i, &data[i], compare);
		  i ++;
		}
	}
	
	void k(long n, long *data){
	  for(long i=0;i<n;i++) printf("%10ld    :       %10ld\n",i,data[i]);
	}
	
	int main()
	{
        // 初期設定
		init_genrand((unsigned)time(NULL));
				// 昇順
		clock_t tm1 = clock();
		for (long i1 = 0; i1 < N; i1++){
			data[i1] = genrand_int31();
		}
		clock_t tm2 = clock();
		select(N, data, ascend);
		clock_t tm3 = clock();
		printf("昇順（データ数： %ld）\n", N);
		printf("   data %ld ms\n", (long)(tm2-tm1));
		printf("   sort %ld ms\n", (long)(tm3-tm2));
		// 降順
		tm1 = clock();
		for (long i1 = 0; i1 < N; i1++)
			data[i1] = genrand_int31();
		tm2 = clock();
		select(N, data, descend);
		tm3 = clock();
		printf("降順（データ数： %d）\n", N);
		printf("   data %ld ms\n", (long)(tm2-tm1));
		printf("   sort %ld ms\n", (long)(tm3-tm2));
	
		return 0;
	}