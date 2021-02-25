#include <stdio.h>
#include <stdlib.h>

#define LOG10_5 0.699
#define LOG10_239 2.378

int pi(int *data, int keta);
int series(int *data, int keta, int maxItem, unsigned bunsi, unsigned bunpo, unsigned plusMinus);

int pi(int *data, int keta){
  int i;

  for(i=0; i < (keta-1)/4+2; i++) data[i]=0;

  if(series(data, keta, (int)(keta/(2*LOG10_5)+2), 4, 5, 1) != 0 ) return -1;
  if(series(data, keta, (int)(keta/(2*LOG10_239)+2), 1, 239, 0) != 0 ) return -1;

  return 0;
}

int series(int *data, int keta, int maxItem, unsigned bunsi, unsigned bunpo, unsigned plusMinus){
  unsigned bunpo2;
  unsigned *item, *itemDiv;
  unsigned *imp, *ikp;
  int *dap;
  int len;
  int i,j,k;
  long x;

  len = (keta-1)/4 +2 +1;
  if((item = (unsigned *)calloc(len, sizeof(unsigned))) == NULL) return -1;
  for(imp = item, i=len; i--;) *imp++ = 0;
if((itemDiv = (unsigned *)calloc(len, sizeof(unsigned))) == NULL){
  free(item);
  return -1;
}

*item = bunsi * bunpo * 4;
bunpo2 = bunpo * bunpo;

for(j=1; maxItem--; j+=2, plusMinus++){
  x = 0;
  for(i=len, imp = item; i--;){
    x = x * 10000 + *imp;
    *imp++ = x / bunpo2;
    x %= bunpo2;
  }

  imp = item;
  ikp = itemDiv;
  if(j==1) for(i = len; i--;) *ikp++ = *imp++;
  else {
    x = 0;
    for(i=len; i--;){
        x = x * 10000 + *imp++;
      *ikp++ = x / j;
      x %= j;
    }
  }

  k = 0;
  dap = data + len;
  ikp = itemDiv + len;
  if(plusMinus & 1){
    for(i=len; i--;){
    *--dap += *--ikp + k;
    if(*dap < 10000) k = 0; //
    else {
    *dap -= 10000; //
    k = 1;
    }
  }
} else {
  for(i=len; i--;){
  *--dap -= *--ikp + k;
  if(*dap >= 0) k=0;
  else {
  *dap += 10000; //
  k=1;
  }
  }
}
}

free(itemDiv);
free(item);
return 0;
}

int main(){
  int i,k,keta;
  static int data[3000];

  printf("---円周率πを算出します---\n");
  printf("小数点以下何桁まで計算しますか？（入力例 1000）\n");
  scanf("%d",&keta);

  k = pi(data, keta);

  if (k != 0) printf("エラーが起きたので、計算できませんでした\n");
  else {
    printf("円周率π = %ld.\n",data[0]);
    //printf("%ld.",data[0]);
    for(i=1; i<=(keta-1)/5+1; i++){
      printf("%04d ",data[i]);
      if(i % 10 == 0) printf("\n");
    }
    if(i % 10 != 1)printf("\n");
  }
  return 0;
}
