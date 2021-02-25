#include <cstdio>
#include <queue>
using namespace std;
int main(void){
    int n,q;
    scanf("%d %d",&n,&q);
    char name[n][11];
    int t[n];
    char c[10001];
    scanf("%c",&c[0]);
    
    queue<int> que;
    queue<int> quet;
    for(int i=0;i<n;i++){
        fgets(c, 10001, stdin);
        sscanf(c, "%s %d", name[i], &t[i]);
        que.push(i);
        quet.push(t[i]);
    }
    
    int i=0, y=0, ttt=0;
    while(!que.empty()){
        if(quet.front()-q <= 0){
            printf("%s %d\n",name[que.front()],quet.front()+ttt);
            ttt += quet.front();
            que.pop();
            quet.pop();
        } else {
            que.push(que.front());
            que.pop();
            quet.push(quet.front()-q);
            ttt += q;
            //printf("%d %d\n",i,quet.front()-q);
            quet.pop();
        }
        i++;
        //printf("%d %d\n",i,quet.front());
    }
    return 0;
}
