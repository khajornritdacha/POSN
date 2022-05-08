#include<bits/stdc++.h>
using namespace std;
int x,y,m,n;
main(){
    cin >> x >> y >> m >> n;
    int a = m*2+n;
    int b = m*6+n*4;
    if(x >= a and y >= b){
        cout << "Yes " << x-a << " " << y-b << "\n";
    }else{
        cout << "No " << abs(min(0, x-a)) << " " << abs(min(0, y-b)) << "\n";
    }
}
