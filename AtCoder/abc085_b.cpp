#include <bits/stdc++.h>
using namespace std;
int main(){
    
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	sort(a, a+n, greater<>());
	int d=0, c=0;
	for(int i=0;i<n;i++){
	    if(d!=a[i]){
	        d=a[i];
	        c++;
	    }
	}
	
	printf("%d\n",c);
	return 0;
}