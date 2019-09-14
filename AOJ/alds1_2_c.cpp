#include <iostream>
using namespace std;

struct card{
    char mark, value;
};

void BubbleSort(card c[], int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(c[j].value < c[j-1].value){
                card temp = c[j];
                c[j] = c[j-1];
                c[j-1] = temp;
            }
        }
    }   
}
void SelectionSort(card c[], int n){
    int minj;
    for(int i=0;i<n;i++){
        minj = i;
        for(int j=i;j<n;j++){
            if(c[j].value < c[minj].value){
                minj = j;
            }
        }
        if(i != minj){
            card temp = c[i];
            c[i] = c[minj];
            c[minj] = temp;
        }
    }
}
main(){
    int n;
    cin >> n;
    card c1[n], c2[n];
    int count=0;
    for(int i=0;i<n;i++){
        cin >> c1[i].mark >> c1[i].value;
        c2[i].mark = c1[i].mark;
        c2[i].value = c1[i].value;
    } 


    BubbleSort(c1, n);
    SelectionSort(c2, n);

    for(int i=0;i<n;i++){
        if(c1[i].mark == c2[i].mark && c1[i].value == c2[i].value){
            count++;
        }
    }

    for(int i=0;i<n-1;i++) cout << c1[i].mark << c1[i].value << " ";
    cout << c1[n-1].mark << c1[n-1].value << endl;
    cout << "Stable" << endl;
    for(int i=0;i<n-1;i++) cout << c2[i].mark << c2[i].value << " ";
    cout << c2[n-1].mark << c2[n-1].value << endl;
    if(n == count) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
}