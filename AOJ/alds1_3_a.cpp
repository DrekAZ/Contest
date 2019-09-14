#include <cstdio>
#include <stack>
#include <cstdlib>
using namespace std;
/// return version
/*int f(stack<char> s){
    char str = s.top();
    s.pop();
    //printf("%c\n", str);
    if(str == '+') return f(s) + f(s);
    else if(str == '-') return f(s) - f(s);
    else if(str == '*') return f(s) * f(s);
    return str - '0';
}*/

/*
11 11 + == 22 111 111 + == 11 ?????? It's mistery so I used t3
*/
main(){
    char str[101];
    int t1, t2;
    stack<int> s;
    while (scanf("%s",str) != EOF){
        if(str[0] == '+'){
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            int t3 = t2+t1;
            s.push(t3);
        } else if(str[0] == '-'){
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            int t3 = t2-t1;
            s.push( t3 );
        } else if(str[0] == '*'){
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            int t3 = t2*t1;
            s.push( t3 );
        } else {
            s.push( atoi(str) );
        }
    }
    printf("%d\n", s.top());
}
