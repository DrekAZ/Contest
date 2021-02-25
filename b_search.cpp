/****************************/
	/* 二分探索                 */
	/*      coded by Y.Suganuma */
	/****************************/
	#include <cstdio>
	#include <cstdlib>
	#include <ctime>
	#include "MT.h"
	
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
	
	/*************************/
	/* データの比較（昇順）  */
	/*      bsearch 用       */
	/*************************/
	int compare_n(const void *arg1, const void *arg2)
	{
		int *a1 = (int *)arg1;
		int *a2 = (int *)arg2;
		return *a1 - *a2;
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
	/* クイックソート                */
	/*      n : データの数           */
	/*      data : データ            */
	/*      compare : 比較を行う関数 */
	/*********************************/
	void quick(int n, int *data, int (*compare)(int, int))
	{
		int i1, left = 1, right = n-1, pos = 0, sw1 = 1, sw2;
				// 枢軸要素を正しい位置に置く
		while (sw1 > 0) {
	
			sw1 = 0;
	
			if (right-pos > 0) {
				sw2 = 0;
				for (i1 = right; i1 > pos && sw2 == 0; i1--) {
					if (compare(data[pos], data[i1])) {
						swap(&data[pos], &data[i1]);
						sw1   = 1;
						sw2   = 1;
						pos   = i1;
						right = i1 - 1;
					}
				}
			}
	
			if (pos-left > 0) {
				sw2 = 0;
				for (i1 = left; i1 < pos && sw2 == 0; i1++) {
					if (compare(data[i1], data[pos])) {
						swap(&data[pos], &data[i1]);
						sw1   = 1;
						sw2  = 1;
						pos  = i1;
						left = i1 + 1;
					}
				}
			}
	
			if (right-pos <= 0)
				sw1 = 0;
		}
				// サブ配列の処理
		if (pos > 1)
			quick(pos, data, compare);
		if (pos < n-2)
			quick(n-1-pos, &data[pos+1], compare);
	}
	
	/**************************************/
	/* 二分探索（ Binary Search ）        */
	/*      key : 探索するキーデータ      */
	/*      data : データ                 */
	/*      n : データ数                  */
	/*      return : 1 : 見つかった       */
	/*               0 : 見つからなかった */
	/**************************************/
	bool search(int key, int *data, int n)
	{
		int sw = 0, left = 0, right = n-1, center;
	
		if (data[right] > data[left]) {
			while (left < right) {
				center = (left + right) / 2;
				if (data[center] < key)
					left = (center < n-1) ? center + 1 : center;
				else
					right = center;
			}
		}
		else {
			while (left < right) {
				center = (left + right) / 2;
				if (data[center] > key)
					left = (center < n-1) ? center + 1 : center;
				else
					right = center;
			}
		}
	
		if (data[left] == key)
			sw = 1;
	
		return sw;
	}
	
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
				// データのソート
		quick(5000000, data, ascend);
		clock_t tm3 = clock();
		printf("sort： %d ms\n", (int)(tm3-tm2));
				// データの探索
		for (int i1 = 0; i1 < n; i1++) {
			int sw = search(s[i1], data, 5000000);
			if (sw == 0) {
				printf("***error*** データが見つからない！\n");
				exit(1);
			}
		}
		clock_t tm4 = clock();
		printf("探索： %d ms\n", (int)(tm4-tm3));
				// データの探索（標準関数 bsearch の利用）
		for (int i1 = 0; i1 < n; i1++) {
			int *sw = (int *)bsearch(&s[i1], data, 5000000, sizeof(int), compare_n);
			if (sw == NULL) {
				printf("***error*** データが見つからない！\n");
				exit(1);
			}
		}
		clock_t tm5 = clock();
		printf("探索(bsearch)： %d ms\n", (int)(tm5-tm4));
	
		return 0;
	}