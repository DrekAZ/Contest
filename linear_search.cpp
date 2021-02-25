/****************************/
/* 線形探索                 */
/*      coded by Y.Suganuma */
/****************************/
	#include <cstdio>
	#include <cstdlib>
	#include <ctime>
	#include "MT.h"
	
	using namespace std;
	
	int main()
	{
				// 初期設定
		int s[100000], n = 0;
		int *data = new int [5000000];
		init_genrand((unsigned)time(NULL));
				// データの設定
		clock_t tm1 = clock();
		for (int i1 = 0; i1 < 5000000; i1++) {
			data[i1] = genrand_int31();
			if (i1%50 == 0 && n < 100000) {
				s[n] = data[i1];
				n++;
			}
		}
		clock_t tm2 = clock();
		printf("保存： %d ms\n", (int)(tm2-tm1));
				// データの探索
		for (int i1 = 0; i1 < n; i1++) {
			int sw = 0;
			for (int i2 = 0; i2 < 5000000; i2++) {
				if (data[i2] == s[i1]) {
					sw = 1;
					break;
				}
			}
			if (sw == 0) {
				printf("***error*** データが見つからない！\n");
				exit(1);
			}
		}
		clock_t tm3 = clock();
		printf("探索： %d ms\n", (int)(tm3-tm2));
	
		return 0;
	}