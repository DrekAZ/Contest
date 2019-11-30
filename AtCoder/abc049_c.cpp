#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    string s;
    cin >> s;
    string a[] = {"erase", "dream", "eraser", "dreamer"};
    
    int c=0,k=0;
    while( !s.empty() ){
        c = a[k].size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == a[k][c]){
                c--;
                if(c == -1){
                    s.erase(s.size()-a[k].size(), a[k].size());
                    k=-1;
                    break; 
                }
            }
            else break;
        }
        k++;
        if(k==4)break;
        
    }
    
    if(s.empty())printf("YES\n");
    else printf("NO\n");
    return 0;
}
