#include <cstdio>
#include <cmath>
#define PI 3.14159265
using namespace std;
double binary(int a, int b, int c){
	double right=0, left=1000000;
	while(right >= left){
		double mid = (right+left)/2+1;
		double f = a*mid+b*sin(c*mid*PI);
		if(f==100)return mid;
		else if(f > 100)left = mid;
		else if(f < 100)right = mid;
	}
	return -1;
}

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%lf\n",binary(a,b,c));
	return 0;
}