#include <cstdio>
using namespace std;
int main(){
	int h[101];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&h[i]);
	int r,l,flag,c;
	while(1){
		flag = 0;
		r=0;l=0;c=0;
		for(int i=0;i<n;i++){
			if(h[i]!=0 && flag==0){
				r=i;
				flag = 1;
			} else if(h[i]==0){
				if(flag==1)l=i;
				else c++;
			}
		}
		for(int i=r;i<=l;i++) h[i] -= m;
		if(r-l == 0){
			if(p==0) p++;
			p *= m;
		} else{
			p++;
		}
	}
	printf("%d\n",p);
}