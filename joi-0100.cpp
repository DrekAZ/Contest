#include <iostream.h>
using namespace std;
main(){
    int n;
    while(1){
    cin >> n;
    if(n==0)break;
    int s[3][n];

    for(int i=0;i<3;i++){
      for(int j=0;j<n;j++){
        cin >> s[i][j];
      }
    }

    for(int i=0;i<n;i++){
        if(s[i][1]*s[i][2]>=1000000) cout << s[i][0] << endl;
        else cout << "NA" << endl;
    }

  }
  return (0);
}
