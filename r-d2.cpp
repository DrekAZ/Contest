#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
main(){

  int n,a[N];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a,a+n);

  for(int i=0;i<n;i++){
    cout << a[i] << endl;;
  }

  return (0);
}
