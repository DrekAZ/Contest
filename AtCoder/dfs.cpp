#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int v[101][101], k[101], seen[101], d[101],f[101];

int func(int pos, int t){
    //printf("%d %d\n",pos+1,t);
    d[pos] = t;
    seen[pos] = 1;
    t++;
    for(int i=0;i<k[pos];i++){
        if(seen[ v[pos][i]-1 ] != 1){
            //printf("---> %d\n",v[pos][i]);
            t = func(v[pos][i]-1, t);
            t++;
        }
    }
    f[pos] = t;
    return f[pos];
}

int main(){
	int n;
	scanf("%d",&n);
	int u;
	for(int i=0;i<n;i++){
		scanf("%d %d",&u,&k[i]);
		for(int m=0;m<k[i];m++){
		    scanf("%d",&v[i][m]);
		}
	}
	
	int t = func(0, 1);
	
	for(int i=0;i<n;i++){
	    if( seen[i] != 1){
	        t = func(i, ++t);
	    }
	}
	
	for(int i=0;i<n;i++){
	    printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	
	return 0;
}