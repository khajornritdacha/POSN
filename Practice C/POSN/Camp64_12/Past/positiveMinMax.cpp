#include<bits/stdc++.h>
using namespace std;
int mn=1e9,mx;
main(){
    for(int i=1; i<=8; i++){
        int x;
        cin >> x;
        if(x > 0){
            mn = min(mn, x);
            mx = max(mx, x);
        }
    }
    cout << mx << "\n" << mn;
}
