#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n], c, min=10000;
	for(int i=0;i<n;i++) {
	    scanf("%d",&a[i]);
	    c=0;
	    while(a[i]%2==0){
	        c++;
	        a[i] /= 2;
	    }
	    if(min > c) min = c;
	}
	
	printf("%d\n",min);
	
	return 0;
}