#include<bits/stdc++.h>
using namespace std;
int x,y;
main(){
    cin >> x >> y;
    x+=(y/400);
    y%=400;
    if(x != 0)
        cout << x << " r ";
    if(y != 0)
        cout << y << " w";
}
