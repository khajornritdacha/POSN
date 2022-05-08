#include <bits/stdc++.h>
using namespace std;

const int N = 2020;
using ll = long long;
using pi = pair<int,int>;

ll W,L,m,n, INF = 1e18;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> W >> L >> m >> n;

    ll ans = INF; 
    for(ll A = m; A <= n; A++){
        ans = min(ans, (W%A) * (L%A));
    }

    cout << ans << "\n";

    return 0;
}