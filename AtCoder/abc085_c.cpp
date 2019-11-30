#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int x,y;
    scanf("%d %d",&x,&y);
    int a[3];
    a[0]=-1;a[1]=-1;a[2]=-1;
    for(int i=0;i<=x;i++){
        for(int k=0;k<=x-i;k++){
            int total = 10000*i + 5000*k + 1000*(x-k-i);
            if(total == y){
                a[0] = i;
                a[1] = k;
                a[2] = x-k-i;
                break;
            }
        }
    }
    
    printf("%d %d %d\n",a[0],a[1],a[2]);
    return 0;
}
