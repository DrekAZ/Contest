#include <iostream>
using namespace std;
main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int flag = 1, count=0;
    /// bubble sort
    while (flag){
        flag = 0;
        for(int j=n-1;j>=1;j--){
            if(a[j] < a[j-1]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = 1;
                count++;
            }
        }
    }
    ///
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << count << endl;
}