#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,t,v;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t >> v;
    cout << "0\n";
    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        cout << max(0ll, y-v) << "\n";
        v = min(v, y);
    }
}
