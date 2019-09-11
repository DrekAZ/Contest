#include <iostream>
#include <algorithm>
using namespace std;
main(){
   int n, r, min, max = -1000000000;
   cin >> n;
   for(int i=0;i<n;i++) {
       cin >> r;
       if(i==0) {
           min=r;
           continue;
       }
       else if(max < r-min) max = r-min;
       if(min > r) min = r;
   }
   
   cout << max << endl;
}