#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 5e5+10;

int n,mx=-2e9,mn=2e9;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        mx = max(mx, x), mn = min(mn, x);
    }
    cout << mx << "\n" << mn << "\n";
}
