#include <cstdio>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	
	int c=0;
	for(int i=0;i<3;i++){
	    if(a%10==1) c++;
	    a /= 10;
	}
	printf("%d\n",c);
	return 0;
}