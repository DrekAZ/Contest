#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359

typedef pair<double, double> p;
int n;
vector<p> v;

void ret(int i, double lx, double ly, double rx, double ry){
    if(i == n){
        v.push_back( pair(rx, ry) );
        return ;
    }
    
    double sx = (rx-lx) /3;
    double sy = (ry-ly) /3;
    double dx = sx * cos(PI/3);
    double dy = sx * sin(PI/3);
    cout << i << " " << lx << " " << rx << "==== : " << sx << " " << sy << " " << dx << " " << dy << endl;
    ret(i+1, lx, ly, lx+sx, ly+sy);
    ret(i+1, lx+sx, ly+sy, lx+sx+dx, ly+sy+dy);
    ret(i+1, lx+sx+dx, ly+sy+dy, lx+sx*2, ly+sy*2);
    ret(i+1, lx+sx*2, ly+sy*2, rx, ry);
    return ;
}

int main() {
    cin >> n;
    double lx=0.0, ly=0.0, rx=100.0, ry=0.0;
    v.push_back( pair(lx, ly) );
    ret(0, lx, ly, rx, ry);
    
    for(int i=0;i<v.size();i++){
        cout << fixed << setprecision(8) << v[i].first << " " << v[i].second << endl;
    }
    
    return 0;
}