#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;
using pi = pair<ll,ll>;

///https://www.hackerrank.com/challenges/minimum-loss/problem

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<ll> ss;
    ll ans = 1e18;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        auto it = (ss.lower_bound(x));
        if(it != ss.end()){
            ans = min(ans, *it-x);
        }
        ss.insert(x);
    }
    cout << ans << "\n";
    return 0;
}
