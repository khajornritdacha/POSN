#include<bits/stdc++.h>
using namespace std;
int n,sx=0,sm=1e9;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int mn = 1e9, mx = 0;
        for(int j=1; j<=5; j++){
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        sx = max(sx, mx-mn);
        sm = min(sm, mx-mn);
    }
    cout << sx << " " << sm << " " << sx-sm;
}
