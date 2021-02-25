#include <stdio.h>
#include <math.h>

#define JUDGE 0.0000000001

double arctan(double x);

int main(void){
    printf("%.10lf\n",arctan(1.0) * 4);
}

double arctan(double x){

    double bunsi= 1, arctan1=0, arctan2=0, ans=0, judge=0, fan=x;
    int i=0;

    do{
      //for(j=0;j<2*i+1){}

      arctan1 = arctan2;
      arctan2 = (bunsi * fan) / (2*i+1);
      judge = fabs( arctan2-arctan1 );
      ans += arctan2 ;
      //ans += ( (pow(bunsi,i)) / (2*i+1) * pow(x,2*i+1) );
      i++;
      bunsi *= -1.0;
      fan *= (x*x);
    }while( judge > JUDGE );

    return ans;
}
