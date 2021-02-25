#include <stdio.h>
#include <math.h>
#define N 100000

double f(double x);

int main(void){

    double s=0,x=0,h=0;
    int i=0;

    h = 1.0/N;
    for(i=0;i<N;i++){

        x = h*i;
        s += ( (f(x) + f(x+h) * 4.0 + f(((x+h+h)-1))) );

    }

    printf("%.10lf\n",s*h*4/6);

    return 0;
}

double f(double x){
    return sqrt(1-x*x);
}
