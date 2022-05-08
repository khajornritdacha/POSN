#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e6+10;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,K, cnt[N], st[N], ed[N], dp[N];
vector<tu> order;
map<int,int> mp;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K; //interval scheduling problems
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
        if(st[x] == 0) st[x] = i;
        ed[x] = i;
    }

    for(int i = 1; i <= n; i++){
        if(st[i] != 0){
            order.emplace_back(ed[i], st[i], i);
        }
    }

    sort(order.begin(), order.end());

    // for(auto [ed, ss, num] : order){
    //     cout << num << " " << cnt[num] << " " << ss << " " << ed << "\n";
    // }

    mp[0] = 0;
    for(int i = 0; i < order.size(); i++){
        auto [ee, ss, num] = order[i];
        if(i >= 0)
            dp[i] = dp[i-1];
        auto it = (--mp.lower_bound(ss));
        int tmp = it->second;
        dp[i] = max(dp[i], tmp + cnt[num]);
        mp[ee] = dp[i];
    }

    cout << n-dp[(int)order.size()-1] << "\n";
    return 0;
}
