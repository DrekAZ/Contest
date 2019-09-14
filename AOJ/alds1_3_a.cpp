#include <cstdio>
#include <stack>
#include <cstdlib>
#include <iostream>
using namespace std;

/*int f(stack<char> s){
    char str = s.top();
    s.pop();
    //printf("%c\n", str);
    if(str == '+') return f(s) + f(s);
    else if(str == '-') return f(s) - f(s);
    else if(str == '*') return f(s) * f(s);
    return str - '0';
}*/


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
            printf("%d\n", s.top());
        } else if(str[0] == '-'){
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            s.push( t2 - t1 );
            printf("%d - %d\n",t2, t1);
        } else if(str[0] == '*'){
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            s.push( t2 * t1 );
            printf("%d * %d\n",t2, t1);
        } else {
            s.push( atoi(str) );
            printf("%d\n", atoi(str));
        }
    }
    t1 = s.top();
    printf("%d\n", t1);
    cout << s.size() << endl;
}
