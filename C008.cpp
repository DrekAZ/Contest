#include <iostream>
//#include <string>
#include <cstring>
using namespace std;

int main(){

  std::string data;
  int a;
  cin >> data;

  a = data.find("<abc>");
  cout << a << endl;

  /*if(ans==NULL){
    cout << "<blank>" <<endl;
  }else {
    cout << ans << endl;
  }*/
//}

  return 0;
}
