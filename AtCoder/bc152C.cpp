#include <iostream>
using namespace std;
int main(void){
    long int n;
    cin >> n;
    long int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    long int min = 10000000;
    int c = 0;
    for(int i=0;i<n;i++){
        if(min >= p[i]){
            c++;
            min = p[i];
        }
    }
    cout << c << endl;
    return 0;
}