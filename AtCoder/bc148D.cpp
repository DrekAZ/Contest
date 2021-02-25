#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    int k=0, c=0, flag = 0;
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
      b[i] = 0;
        if(a[i] == k+1) {
            b[i] = 1;
            k++;
            flag = 1;
        }
    }
    if(flag == 1){
        for(int i=0;i<n;i++){
            if(b[i] == 0) c++;
        }
    }
    if(c!=0) printf("%d\n",c);
    else if(flag == 1 && c==0) printf("0\n");
    else printf("-1\n");
    return 0;
}