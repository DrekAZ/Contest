/* -----------------------------------------------------------------------------
	�v���O���~���O�����11�� �v���O�����ۑ�
----------------------------------------------------------------------------- */

#include <stdio.h>

#define N 21

/* -----------------------------------------------
	�y���1�z���K9-9 <�֐���`��>
	������s�̕����̕��т𔽓]����֐����쐬����D
	���Ƃ��΁Cs��"SEC"���󂯎������,���̔z���"CES"�ɍX�V���邱��.
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
	�y���2�z���K9-10 <�֐���`��>
	������s���̂��ׂĂ̐����������폜����֐����쐬����D
	���Ƃ��΁Cs��"AB1C9"���󂯎������,���̔z���"ABC"�ɍX�V���邱��.
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
	�y���3�z���K10-2 <�֐���`��>
	����*y�N*m��*���̓��t���C"�O�̓�"���邢��"���̓�"��
	���t�ɍX�V����֐����쐬����D
	���邤�N���l�����Čv�Z���s�����ƁD
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
	�y���4�z
	3��int�^����x,y,z���^����ꂽ�Ƃ��C
	������3�ӂƂ���O�p�`�����݂���Ȃ��1�C�����łȂ����0��Ԃ��֐�
	int triangle(int x, int y, int z);
	���쐬����D
	(�q���g�F�Œ��̕ӂ̒����́C����2�ӂ̒����̘a��菬����)�D

----------------------------------------------- */
int triangle(int x, int y, int z) {
	if (x < y + z && y < x + z && z < x + y) return 1;
	else return 0;
}


/* -----------------------------------------------
	�y���5�z(�z��Ɗ֐�) 
�傫����N=21�̔z��a�������āC�e�v�f�̒l��0�ȏ�10�ȉ��Ƃ���D�֐�
int bowling(int a[]);
�́C���̔z��������Ɏ���C�ȉ��̎菇�œ��_���v�Z����,���̒l��ԋp����D
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
	�y���6�z(�\����) �����b����Ȃ�\���̂����̂悤�Ɍ^��`�����D
----------------------------------------------- */
typedef struct _HMS {
	int h;		// ����(0��h<10000)
	int m;		// ��(0��m<60)
	int s;		// �b(0��s<60)
} HMS;

/* -----------------------------------------------
(1)	HMS�^�̎����f�[�^�������b�u15:23:40�v(�R������؂莞���b�e2���ȏ�)�ŕ\������֐����`����D
(2)	HMS�^�̃I�u�W�F�N�g��b�֕ϊ�����֐�int HMStoS(HMS t)���`����D
(3)	�b��HMS�^�̃I�u�W�F�N�g�֕ϊ�����֐�int StoHMS (HMS t)���`����D
(4)	2��HMS�^�̃I�u�W�F�N�g�̘a���v�Z����֐�HMS addHMS (HMS s, HMS t) ���`����D
(5)	2��HMS�^�̃I�u�W�F�N�g�̍�HMS diffHMS (HMS s, HMS t)���v�Z����֐����`����D1:30:25��0:43:05�̍���(�����̏����ɂ�炸) 0:47:20�ƂȂ�D
(6)	��L�̂��Ƃ��e�X�g����main�֐��Ƃ��̏o�͌��ʂ�Y�t���邱�ƁD�֐��̊e�������ƕԋp�l�́C�K�����Ԃ�0�ȏ�10000�����C���ƕb��0�ȏ�60�����̒l�ł��鉼�肷��D
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

/* bowling �X�R�A�̕\��(�Q�l) */
void print_fr(int *a) {

	int  i = 0, fr = 1;

	while(fr < 10) {
		if(a[i] == 10) { 
			printf("  :**|");
			i ++;
		} else if(a[i] + a[i+1] == 10) {
			printf("%2d:�^|", a[i]);
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
		else if(k < 2 && a[i] + a[i+1] == 10) { printf("%2d:�^",a[i]); k++; i += 2;} 
		else { printf("%2d",a[i]); i++; }
		if(k == 2) printf("|"); else printf(":");
	}
	return ;
}

/*
	�e�X�g
*/
int main () {

{			
	/* �y���1�z���K9-9 �̃e�X�g */
	char s[] = "SEC";
	rev_string(s);
	printf("�y���1�z���K9-9: %s\n", s);
}

{
	/* �y���2�z���K9-10 �̃e�X�g */
	char s[] = "AB1C9";
	del_digit(s);
	printf("�y���2�z���K9-10: %s\n", s);
}

{
	printf("�y���3�z���K10-2:\n");
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
	printf("�y���4�z�O�p�`:\n");
	printf("%d\n\n", triangle(2,2,2));
	printf("%d\n\n", triangle(1,3,2));
}

{
	printf("�y���5�zbowling �X�R�A:\n");

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
	printf("�y���6�z���Ԃ̉����Z:\n");
	HMS x = {2, 31, 52}, y = {1, 43, 47}, z = {0,16,13};
	print_HMS(addHMS(x, y));  // 04:15:39
	print_HMS(diffHMS(x, y));	// 00:48:05
	print_HMS(addHMS(y, z));  // 02:00:00
	print_HMS(diffHMS(y, z)); // 01:27:34
	
	printf("\n");
	int n = HMStoS(x);
	printf("%02d:%02d:%02d",x.h,x.m,x.s);
	printf(" = %d�b\n",n);
	// 02:31:52 = 9112�b
	
	int t = 36001;
	HMS k = StoHMS(t);
	printf("%d�b = ",t);
	print_HMS(k); 
	// 36001�b = 10:00:01
}

	return 0;
}
