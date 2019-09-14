// not accept

#include <iostream>
using namespace std;

void insertionSort(int a[], int n, int g){
    int cnt=0, j, v;
    for(int i=g;i<n-1;i++){
        v = a[i];
        j = i-g;
        while(j>=0 && a[j]>v){
            a[j+g] = a[j];
            j = j-g;
            cnt++;
        }
        a[j+g] = v;
    }
    cout << cnt << endl;
}
void shellSort(int a[], int n){
    int cnt = 0, m = n/2;
    int g[m];
    for(int i=0;i<m;i++) g[i] = m-i;
    

    cout << m << endl;
    for(int i=0;i<m-1;i++) cout << g[i] << " ";
    cout << g[m-1] << endl;


    for(int i=0;i<m;i++) insertionSort(a, n, g[i]);
}

main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    shellSort(a, n);
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
}
