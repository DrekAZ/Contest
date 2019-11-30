#include <cstdio>
using namespace std;
int main(){
    
	int n, a, b, c=0;
	
	scanf("%d %d %d",&n,&a,&b);
	int w;
	for(int i=1;i<=n;i++){
	    w=0;
	    int ll = i;
	    while(ll>=10){
	        w += ll%10;
	        ll/=10;
	    }
	    w += ll%10;
	    if(w>=a && w<=b){
	        c += i;  
	    } 
	}
	
	printf("%d\n",c);
	
	return 0;
}