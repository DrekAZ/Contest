#include <iostream>
using namespace std;
main(){
    int n;
    cin >> n;
    int a[n], v, j;
    for(int i=0;i<n;i++) cin >> a[i];

    /// insertionSort
    for(int i=1;i<=n-1;i++){
        for(int k=0;k<n-1;k++) cout << a[k] << " ";
        cout << a[n-1] << endl;

        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
    }
    ///

    for(int k=0;k<n-1;k++) cout << a[k] << " ";
    cout << a[n-1] << endl;
}