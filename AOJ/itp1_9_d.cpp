#include <cstdio>
#include <cstring>
using namespace std;
int main(void){
    char str[1001];
    scanf("%s",str);
    int q;
    scanf("%d",&q);
    char c;
    char m[q][1001];
    scanf("%c",&c);
    for(int i=0;i<q;i++){
        fgets(m[i], 1001, stdin);
    }
    int a[q],b[q];
    char s[q][1001];
    for(int i=0;i<q;i++){
      if(m[i][2] == 'p') sscanf(m[i], "%s %d %d %s", s[i],&a[i],&b[i],m[i]);
      else sscanf(m[i], "%s %d %d ", s[i],&a[i],&b[i]);
    }
    for(int i=0;i<q;i++){
        if(s[i][0] == 'p'){
            for(int k=a[i];k<=b[i];k++) printf("%c",str[k]);
            printf("\n");
        } else if(s[i][2] == 'p'){
            int d=0;
            for(int k=a[i];k<=b[i];k++){
                str[k] = m[i][d];
                d++;
            } 
        } else if(s[i][2] == 'v'){
            for(int k=0;k<=(b[i]-a[i])/2;k++){
                
                char temp = str[b[i]-k];
                str[b[i]-k] = str[a[i]+k];
                str[a[i]+k] = temp;
                printf("%d %d %d\n",i, b[i]-k, a[i]+k);
            }
        }
        printf("!!!!   %s\n",str);
    }
    return 0;
}