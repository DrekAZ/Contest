#include <iostream>
#include <cstring>
using namespace std;
#define N 101
#define M 5001

main(){

  char str[2][N],data[M],*tok1,*tok2,*ans;
  cin >> str[0] >> str[1];
  cin >> data;

  while(tok2 != NULL){
  tok1 = strstr(data,str[0]);
  tok2 = strstr(data,str[1]);
  ans = &tok2-&tok1;
  if(ans==NULL){
    cout << "<blank>" <<endl;
  }else {
    cout << ans << endl;
  }
}

  return 0;
}
