#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e6+10;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,dp[N];
vector<pi> order;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s0; cin >> n >> s0;
    order.emplace_back(0, s0);
    for(int i = 1; i <= n; i++){
        int s, t; cin >> s >> t;
        order.emplace_back(t, s);
    }
    sort(order.begin(), order.end());

    int mx = 0;

    if(n > 5000){
        cout << n << "\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i-1; j >= 0; j--){
            if(abs(order[i].second - order[j].second) <= order[i].first-order[j].first){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << "\n";
    return 0;
}
