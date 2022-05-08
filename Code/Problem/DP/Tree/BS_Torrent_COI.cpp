#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10, INF = 1e9+10;

//https://oj.uz/problem/view/COI16_torrent
//there are path from st[0] to st[1] and we have to separate it optimally so that the required time is as minimum as possible
//we can do so by binary search on bitonic function

int st[2], dp[N], tmp[N], n;
vector<int> G[N], lis;

bool pre(int u, int p){
    if(u == st[1]){
        lis.emplace_back(u);
        return true;
    }
    for(int v : G[u]){
        if(v == p) continue;
        if(pre(v, u)){
            lis.emplace_back(u);
            return true;
        } 
    }
    return false;
}

void dfs(int u, int p, int ban){
    for(int v : G[u]) if(v != p and v != ban) dfs(v, u, ban);
    
    vector<int> vec;
    for(int v : G[u]) if(v != p and v != ban) vec.emplace_back(dp[v]);

    sort(vec.rbegin(), vec.rend());
    for(int i = 0; i < vec.size(); i++){
        dp[u] = max(dp[u], vec[i]+i+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> st[0] >> st[1];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    pre(st[0], -1);

    int l = 0, r = (int)lis.size()-2, ans = INF;
    while(l <= r){
        int mid = (l+r)>>1;

        for(int i = 0; i <= n; i++) dp[i] = 0;
        // assert(mid+1 <= (int)lis.size()-1);
        dfs(st[1], -1, lis[mid+1]);
        dfs(st[0], -1, lis[mid]);

        ans = min(ans, max(dp[st[0]], dp[st[1]]));

        if(dp[st[0]] < dp[st[1]]){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}