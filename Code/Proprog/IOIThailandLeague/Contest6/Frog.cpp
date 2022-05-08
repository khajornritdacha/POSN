#include<bits/stdc++.h>
using namespace std;
int x,y;
main(){
    cin >> x >> y;
    if(y < x)
        cout << 2;
    else
        cout << (y+x-1)/x;
}
