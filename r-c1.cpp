#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
#define N 1001
main(){

    char a[N],*tok;
    int num=0;
    cin >> a;
    tok = strtok(a, ".");
    num = atoi(tok);
    while(tok != NULL){

            cout << tok << endl;
      tok = strtok(NULL,".");
    }

    return 0;
}
