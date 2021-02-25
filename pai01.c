#include <stdio.h>
#include <math.h>
#define N 10000

double f(double x);

int main(void){

    double s=0,x=0,h=0;
    int i=0;

    h = 1.0/N;
    for(i=0;i<N;i++){

        x = h*i;
        s += ( f(x) + f(x+h) );

    }

    printf("%.10lf\n",s*4*h*0.5);

}

double f(double x){
    return sqrt(1-x*x);
}
