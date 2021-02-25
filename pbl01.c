#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 21

void rev_string(char s[]){
	int i=0,n;
	char temp;
	n = strlen(s);
	for(i=0;i<n/2;i++){
		temp = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = temp;
	}
	printf("%s\n",s);
}

void del_digit(char s[]){
	int i=0,n=0;
	while(s[i] != '\0'){
		if(s[i] < '0' || s[i] > '9'){ //mosi moji dattara
			s[n] = s[i];
			n++;
		}
		i++;
	}
	s[n] = '\0';
	printf("%s\n",s);
}

int mdays[][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31},	
};

int leap(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

void decrement_date(int *y, int *m, int *d){
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
void increment_date(int *y, int *m, int *d){
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

int triangle(int x, int y, int z){
	if (x < y + z && y < x + z && z < x + y) return 1;
	else return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* -----------------------------------------------
	【問題5】(配列と関数) 
大きさがN=21の配列aがあって，各要素の値は0以上10以下とする．関数
int bowling(int a[]);
は，この配列を引数に受取り，以下の手順で得点を計算して,その値を返却する．
----------------------------------------------- */
int bowling(int a[]) {
	int sc = 0;
	/* 解答欄 */
	int i=0,j=1;
	while(j<=10) {
		if(a[i] == 10){
			sc += a[i]+a[i+1]+a[i+2];
			i++;
		} else if(a[i] < 10 && a[i]+a[i+1] == 10){
			sc += a[i]+a[i+1]+a[i+2];
			i = i+2;
		} else {
			sc += a[i]+a[i+1];
			i = i+2;
		}
		j++;
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
	/* (1) 解答欄 */
	printf("%02d:%02d:%02d\n",t.h,t.m,t.s);
}

int HMStoS(HMS t) {
	/* (2) 解答欄 */
	int sec;
	sec = t.h*3600 + t.m*60 + t.s;
	return sec;
}

HMS StoHMS(int n) {
	/* (3) 解答欄 */
	HMS time;
	time.h = n / 3600;
	time.m = n % 3600 / 60;
	time.s = n % 3600 % 60;
	return time;
}

HMS addHMS(HMS s, HMS t) {
	HMS z;
	/* (4) 解答欄 */
	z.s = s.s + t.s;
	z.m = z.s / 60 + s.m + t.m;
	z.h = z.m / 60 + s.h + t.h;
	
	z.s = z.s % 60;
	z.m = z.m % 60;

	return z;
}

HMS diffHMS(HMS s, HMS t) {
	HMS z;
	/* (5) 解答欄 */
	int ss,tt;
	ss = HMStoS(s);
	tt = HMStoS(t);
	
	ss = abs(ss-tt);
	
	z = StoHMS(ss);

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cc(char s[]){
	int n;
	n = sizeof(&s);
	printf("%d\n",n);
}

int main(){

	int x,y,z;
	int year,m,d;
	char s[] = "LLLLLL";
	//scanf("%d/%d/%d",&year,&m,&d);
	//decrement_date(&year,&m,&d);
	//printf("%d/%d/%d\n",year,m,d);
	
	//printf("%d\n",triangle(x,y,z));
	//scanf("%s",s);
	printf("%d\n",sizeof(s));
	cc(s);
	//del_digit(s);

	return 0;
}