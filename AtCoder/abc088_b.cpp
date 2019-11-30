#include <bits/stdc++.h>
using namespace std;
int main(){
    
	int n;
	scanf("%d",&n);
	int a[n], ab[2];
	
	ab[0]=0;ab[1]=0;
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	sort(a, a+n, greater<>());
	
	for(int i=0;i<n;i++){
	    if(i%2==0) ab[0] += a[i];
	    else ab[1] += a[i];
	}
	
	printf("%d\n",ab[0]-ab[1]);
	
	return 0;
}