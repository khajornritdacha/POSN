#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

//https://codeforces.com/problemset/problem/1466/D

int n,a[N];
vector<int> G[N];
priority_queue<pi> pq;

void dfs(int u, int p){
    int ch = 0;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        ch++;
    }
    pq.emplace(a[u], ch + (p != -1) -1);
}

void test_case(){
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i];
    }
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);

    cout << ans << " ";
    for(int i = 2; i < n; i++){
        while(!pq.empty() and pq.top().second <= 0) pq.pop();
        if(!pq.empty()){
            auto [val, num] = pq.top(); pq.pop();
            ans += val;
            num--;
            if(num > 0) pq.emplace(val, num);
        }
        cout << ans << " ";
    }
    cout << "\n";

    while(!pq.empty()) pq.pop();
    for(int i = 0; i <= n; i++) G[i].clear();

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        test_case();
    }

    return 0;
}