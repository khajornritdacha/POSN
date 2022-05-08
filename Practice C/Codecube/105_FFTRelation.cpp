#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

ll f[N],mod = 1e9+7;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0] = 0, f[1] = 1;
    for(int i=2; i<=2e6; i++){
        f[i] = (f[i-1]+f[i-2])%mod;
    }
    int Q;
    cin >> Q;
    while(Q--){
        int n,K;
        cin >> n >> K;
        ll ans = f[n];
        for(int i=1; i<=K; i++){
            int lv,val;
            cin >> lv >> val;
            ans += (1ll*val*f[n-lv+1])%mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }
}
