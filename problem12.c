/* -----------------------------------------------------------------------------
	プログラミング言語第11回 プログラム課題
----------------------------------------------------------------------------- */

#include <stdio.h>

#define N 21

/* -----------------------------------------------
	【問題1】演習9-9 <関数定義部>
	文字列sの文字の並びを反転する関数を作成せよ．
	たとえば，sに"SEC"を受け取ったら,その配列を"CES"に更新すること.
----------------------------------------------- */
void rev_string(char s[]) {
	int i=0,n=0;
	char temp;
	while(s[n]) {
		n++;
	}
	for(i=0;i<n/2;i++){
		temp = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = temp;
	}
}

/* -----------------------------------------------
	【問題2】演習9-10 <関数定義部>
	文字列s内のすべての数字文字を削除する関数を作成せよ．
	たとえば，sに"AB1C9"を受け取ったら,その配列を"ABC"に更新すること.
----------------------------------------------- */
void del_digit(char s[]) {
	int i=0,n=0;
	while(s[i] != '\0'){
		if(s[i] < '0' || s[i] > '9'){ //mosi moji dattara
			s[n] = s[i];
			n++;
		}
		i++;
	}
	s[n] = '\0';
}

/* -----------------------------------------------
	【問題3】演習10-2 <関数定義部>
	西暦*y年*m月*日の日付を，"前の日"あるいは"次の日"の
	日付に更新する関数を作成せよ．
	うるう年を考慮して計算を行うこと．
----------------------------------------------- */
int mdays[][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31},	
};

int leap(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

void decrement_date(int *y, int *m, int *d) {
	*d = *d - 1;
	if(*m == 1 && 0 == *d){
		*y = *y - 1;
		*m = 12;
		*d = 31;
	} else if(*d == 0){
		*m = *m - 1;
		*d = mdays[ leap(*y) ][*m];
	}
}

void increment_date(int *y, int *m, int *d) {
	*d = *d + 1;
	if(*m == 12 && mdays[ leap(*y) ][*m] < *d){
		*y = *y + 1;
		*m = 1;
		*d = 1;
	} else if(mdays[ leap(*y) ][*m] < *d){
		*m = *m + 1;
		*d = 1;
	}
}


/* -----------------------------------------------
	【問題4】
	3つのint型整数x,y,zが与えられたとき，
	これらを3辺とする三角形が存在するならば1，そうでなければ0を返す関数
	int triangle(int x, int y, int z);
	を作成せよ．
	(ヒント：最長の辺の長さは，他の2辺の長さの和より小さい)．

----------------------------------------------- */
int triangle(int x, int y, int z) {
	if (x < y + z && y < x + z && z < x + y) return 1;
	else return 0;
}


/* -----------------------------------------------
	【問題5】(配列と関数) 
大きさがN=21の配列aがあって，各要素の値は0以上10以下とする．関数
int bowling(int a[]);
は，この配列を引数に受取り，以下の手順で得点を計算して,その値を返却する．
----------------------------------------------- */
int bowling(int a[]) {
	int sc = 0;
	int i=0,j=1;
	while(j<10) {
		if(a[i] == 10){
			sc += a[i]+a[i+1]+a[i+2];
			printf("%5d|",sc);
			i++;
		} else if(a[i] < 10 && a[i]+a[i+1] == 10){
			sc += a[i]+a[i+1]+a[i+2];
			printf("%5d|",sc);
			i = i+2;
		} else {
			sc += a[i]+a[i+1];
			printf("%5d|",sc);
			i = i+2;
		}
		j++;
	}
	
	if(a[i] == 10){
		sc += a[i]+a[i+1]+a[i+2];
		printf("%8d|",sc);
	} else if(a[i] < 10 && a[i]+a[i+1] == 10){
		sc += a[i]+a[i+1]+a[i+2];
		printf("%8d|",sc);
	} else {
		sc += a[i]+a[i+1];
		printf("%8d|",sc);
	}
	
	return sc;
}


/* -----------------------------------------------
	【問題6】(構造体) 時分秒からなる構造体を次のように型定義した．
----------------------------------------------- */
typedef struct _HMS {
	int h;		// 時間(0≦h<10000)
	int m;		// 分(0≦m<60)
	int s;		// 秒(0≦s<60)
} HMS;

/* -----------------------------------------------
(1)	HMS型の時刻データを時分秒「15:23:40」(コロン区切り時分秒各2桁以上)で表示する関数を定義せよ．
(2)	HMS型のオブジェクトを秒へ変換する関数int HMStoS(HMS t)を定義せよ．
(3)	秒をHMS型のオブジェクトへ変換する関数int StoHMS (HMS t)を定義せよ．
(4)	2つのHMS型のオブジェクトの和を計算する関数HMS addHMS (HMS s, HMS t) を定義せよ．
(5)	2つのHMS型のオブジェクトの差HMS diffHMS (HMS s, HMS t)を計算する関数を定義せよ．1:30:25と0:43:05の差は(引数の順序によらず) 0:47:20となる．
(6)	上記のことをテストするmain関数とその出力結果を添付すること．関数の各実引数と返却値は，必ず時間は0以上10000未満，分と秒は0以上60未満の値である仮定する．
----------------------------------------------- */
void print_HMS(HMS t) {
	printf("%02d:%02d:%02d\n",t.h,t.m,t.s);
}

int HMStoS(HMS t) {
	int sec;
	sec = t.h*3600 + t.m*60 + t.s;
	return sec;
}

HMS StoHMS(int n) {
	HMS time;
	time.h = n / 3600;
	time.m = n % 3600 / 60;
	time.s = n % 3600 % 60;
	return time;
}

HMS addHMS(HMS s, HMS t) {
	HMS z;
	z.s = s.s + t.s;
	z.m = z.s / 60 + s.m + t.m;
	z.h = z.m / 60 + s.h + t.h;
	
	z.s = z.s % 60;
	z.m = z.m % 60;

	return z;
}

HMS diffHMS(HMS s, HMS t) {
	HMS z;
	int ss,tt;
	ss = HMStoS(s);
	tt = HMStoS(t);
	ss = ss - tt;
	if(ss < 0) ss = ss * (-1);
	z = StoHMS(ss);
	return z;

	return z;
}

/* bowling スコアの表示(参考) */
void print_fr(int *a) {

	int  i = 0, fr = 1;

	while(fr < 10) {
		if(a[i] == 10) { 
			printf("  :**|");
			i ++;
		} else if(a[i] + a[i+1] == 10) {
			printf("%2d:／|", a[i]);
			i += 2;
		} else {	 	
			printf("%2d:%2d|", a[i], a[i+1]);
			i += 2;
		}
		fr++;
	}
	for(int k = 0; k < 3; k++) {
		if(a[i] == 10) { printf("**"); i++; }
		else if(k == 0 && a[i] + a[i+1] < 10) { printf("%2d:%2d: 0",a[i], a[i+1]); k+=2;}
		else if(k < 2 && a[i] + a[i+1] == 10) { printf("%2d:／",a[i]); k++; i += 2;} 
		else { printf("%2d",a[i]); i++; }
		if(k == 2) printf("|"); else printf(":");
	}
	return ;
}

/*
	テスト
*/
int main () {

{			
	/* 【問題1】演習9-9 のテスト */
	char s[] = "SEC";
	rev_string(s);
	printf("【問題1】演習9-9: %s\n", s);
}

{
	/* 【問題2】演習9-10 のテスト */
	char s[] = "AB1C9";
	del_digit(s);
	printf("【問題2】演習9-10: %s\n", s);
}

{
	printf("【問題3】演習10-2:\n");
	int y = 2020, m = 3, d = 1;
	decrement_date(&y, &m, &d); printf("%d/%d/%d\n", y, m, d);
	y = 2020, m = 2, d = 28;		
	decrement_date(&y, &m, &d); printf("%d/%d/%d\n", y, m, d);
	y = 2019, m = 2, d = 28;
	increment_date(&y, &m, &d);	printf("%d/%d/%d\n", y, m, d);
	y = 2019, m = 12, d = 31;
	increment_date(&y, &m, &d);	printf("%d/%d/%d\n", y, m, d);
}

{	
	printf("【問題4】三角形:\n");
	printf("%d\n\n", triangle(2,2,2));
	printf("%d\n\n", triangle(1,3,2));
}

{
	printf("【問題5】bowling スコア:\n");

			/*   --1--+--2--+--3--+--4--+--5--+--6--+--7--+--8--+--9--+--.10.-- */	
int a0[N] = 	{   10,   10,   10,   10,   10,   10,   10,   10,   10,10,10,10};
int a1[N] = 	{ 2, 8,   10, 9, 1, 0, 5,   10,   10,   10,   10, 8, 1, 5, 2, 0};
int a2[N] = 	{ 1, 6, 4, 3, 5, 5, 7, 2, 9, 0,   10, 5, 4, 8, 2, 1, 8, 5, 5, 2};
int a3[N] = 	{   10,   10,   10,   10,   10, 9, 1,   10,   10,   10,10,10,10};
int a4[N] = 	{   10,   10,   10,   10,   10,   10,   10,   10,   10,10,10, 9};
int a5[N] = 	{ 2, 8,   10, 9, 1, 0, 5,   10, 8, 2, 4, 6,   10, 8, 1,10, 2, 8};

	print_fr(a0); printf("\n");
	printf("%d\n\n", bowling(a0));

	print_fr(a1); printf("\n"); 
	printf("%d\n\n", bowling(a1));

	print_fr(a2); printf("\n"); 
	printf("%d\n\n", bowling(a2));

	print_fr(a3); printf("\n"); 
	printf("%d\n\n", bowling(a3));

	print_fr(a4); printf("\n"); 
	printf("%d\n\n", bowling(a4));

	print_fr(a5); printf("\n"); 
	printf("%d\n\n", bowling(a5));
}


{	
	printf("【問題6】時間の加減算:\n");
	HMS x = {2, 31, 52}, y = {1, 43, 47}, z = {0,16,13};
	print_HMS(addHMS(x, y));  // 04:15:39
	print_HMS(diffHMS(x, y));	// 00:48:05
	print_HMS(addHMS(y, z));  // 02:00:00
	print_HMS(diffHMS(y, z)); // 01:27:34
	
	printf("\n");
	int n = HMStoS(x);
	printf("%02d:%02d:%02d",x.h,x.m,x.s);
	printf(" = %d秒\n",n);
	// 02:31:52 = 9112秒
	
	int t = 36001;
	HMS k = StoHMS(t);
	printf("%d秒 = ",t);
	print_HMS(k); 
	// 36001秒 = 10:00:01
}

	return 0;
}
