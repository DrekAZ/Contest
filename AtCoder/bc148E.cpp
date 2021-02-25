#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
    long long N;
    scanf("%lld",&N);
    long long c=0, d = 10;
    if(N%2 == 1){
        c = 0;
    } else {
        while(d <= N){
            c += N/d;
            d *= 5;
        }
    }
    
    printf("%lld\n",c);
}