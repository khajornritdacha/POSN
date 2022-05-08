#include<bits/stdc++.h>
using namespace std;
int mx,mn=1e9;
main(){
    while(true){
        int x;
        cin >> x;
        if(x <= 0)
            break;
        if(x%2){
            mn = min(mn, x);
            mx = max(mx, x);
        }
    }
    cout << mx << "\n" << mn << "\n" << mx-mn;
}
