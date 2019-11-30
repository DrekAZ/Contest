#include <cstdio>
using namespace std;
int main(){
	int a, b, c, x;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&x);
	int n=0;
	
	for(int i=0;i<=a;i++){
	    for(int j=0;j<=b;j++){
	        for(int k=0;k<=c;k++){
	            if(x == 500*i + 100*j + 50*k) n++;
	        }
	    }
	}
	
	printf("%d\n",n);
	
	return 0;
}