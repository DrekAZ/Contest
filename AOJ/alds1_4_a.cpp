#include <cstdio>
#include <algorithm>
using namespace std;
main(){
    int n,q;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    scanf("%d",&q);
    int t[q];
    for(int i=0;i<q;i++) scanf("%d",&t[i]);

    sort(s, s+n); sort(t, t+q);
    int k=0, c=0;
    for(int i=0;i<n;i++){
        printf("%d %d\n",t[k],s[i]);
        if(t[k] < s[i]){
            k++;
            printf("%d %d\n",t[k],s[i]);
        }
        if(t[k] == s[i]){
            c++;
            k++;
        }
        if(k == q) break;
    }
    /// 306 for1kai ni taisite k++ dato dureru
    printf("%d\n",c);
}