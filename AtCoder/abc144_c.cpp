#include <bits/stdc++.h>
using namespace std;
int main(void){
     static const double pi = 3.141592653589793;
    double a,b;
    long long int x;
    long double ans=0.0, aa=0,bb=0,cc=0;
    
    scanf("%lf %lf %lld",&a,&b,&x);
    long double n;
    ans = double(x/(a*a*b));
    printf("%Lf\n",ans);
    printf("%lf\n",tan(45.0));
    n = ans*b;
    if(ans>=0.5){
        bb = (b-n)*2;
        ans = atan(bb/a);
        printf("%Lf %Lf\n",bb,ans);
        printf("%.10Lf\n",ans*(180/pi));
    }else if(ans<0.5){
        bb = (a-n*a);
        ans = atan(bb/a);
        printf("%Lf %Lf\n",bb,cc);

        printf("%.10Lf\n",ans*(180/pi));
    }
    
    return 0;
}
