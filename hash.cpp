/****************************/
	/* ハッシュ法（ Hash ）     */
	/*      coded by Y.Suganuma */
	/****************************/
	#include <cstdio>
	#include <cstdlib>
	#include <cstring>
	#include <string>
	#include <set>
	#include <ctime>
	#include "MT.h"
	
	using namespace std;
	
	int hit = 0;
	
	/***********************************/
	/* クラス Hash（ハッシュテーブル） */
	/***********************************/
	class Hash {
			int size;   // ハッシュテーブルの大きさ
			set <string> *table;   // 衝突リスト
	
			/*******************/
			/* ハッシュ関数    */
			/*      s : 文字列 */
			/*******************/
			int hash(char *s)
			{
				unsigned int hash = 0;
				int len = strlen(s);
				for (int i1 = 0; i1 < len; i1++ ) {
					hash = (hash << 4) + s[i1];   // 左に4ビットシフトし文字を加える
					unsigned int g = hash & 0xf0000000;   // ビット毎のＡＮＤ
					if (g != 0) {
						hash ^= g >> 24;   // 排他的論理和
						hash ^= g;
					}
				}
	
				return hash % size;
			}
	
		public:
	
			/******************/
			/* コンストラクタ */
			/******************/
			Hash(int sz)
			{
				size  = sz;
				table = new set <string> [size];
			}
	
			/***************************************/
			/* データの追加                        */
			/*      str : データ（文字列）         */
			/*      return : =1 : 追加             */
			/*               =0 : 同じデータが存在 */
			/***************************************/
			int add(char *str)
			{
				int k = hash(str);
				if (!(table[k].empty()))
					hit++;
				pair<set<string>::iterator, bool> p = table[k].insert((string)str);
				return p.second;
			}
	
			/***********************************/
			/* データの探索                    */
			/*      str : データ（文字列）     */
			/*      return : =1 : 見つかった   */
			/*               =0 : 見つからない */
			/***********************************/
			int search(char *str)
			{
				int sw = 0;
				int k  = hash(str);
				set<string>::iterator it = table[k].find((string)str);
				if (it != table[k].end())
					sw = 1;
				return sw;
			}
	};
	
	int main()
	{
				// 初期設定
		int n = 0;
		char s[100000][11];
		Hash H(10000000);
		init_genrand((unsigned)time(NULL));
				// データの設定
		clock_t tm1 = clock();
		for (int i1 = 0; i1 < 5000000; i1++) {
			int k = genrand_int31();
			char st[11];
			gcvt((double)k, 11, st);
			st[strlen(st)-1] = '\0';   // 最後のピリオドが除かれる
			int sw = H.add(st);
			if (sw > 0) {
				if (i1%50 == 0 && n < 100000) {
					strcpy(s[n], st);
					n++;
				}
			}
			else
				i1--;
		}
		clock_t tm2 = clock();
		printf("保存： %d ms， 衝突回数： %d\n", (int)(tm2-tm1), hit);
				// データの探索
		for (int i1 = 0; i1 < n; i1++) {
			int sw = H.search(s[i1]);
			if (sw == 0) {
				//printf("***error*** データが見つからない！\n");
				//printf("%s\n",s[i1]);
				//exit(1);
			}
		}
		clock_t tm3 = clock();
		printf("探索： %d ms\n", (int)(tm3-tm2));
	
		return 0;
	}