#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10, N = 1e5+10;

int pa[N], n;
long long sum[N], mn_path[N], co[N];
vector<int> rg[N];

void dfs(int u){
    int mn = -1;

    for(int v : rg[u]){
        dfs(v);
        if(mn == -1 or mn_path[v] < mn_path[mn]){
            mn = v;
        }
    }

    if(mn == -1){
        sum[u] = mn_path[u] = co[u]; 
    } else {
        for(int v : rg[u]){
            sum[u] += sum[v];
        }
        sum[u] = sum[u]-mn_path[mn]+max(mn_path[mn], co[u]);
        mn_path[u] = max(mn_path[mn], co[u]);
    }
}

void solve(){
    vector<int> roots;
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> co[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> pa[i];
        if(pa[i] != 0)
            rg[pa[i]].emplace_back(i);
        else
            roots.emplace_back(i);
    }

    long long ans = 0;
    for(int u : roots){
        dfs(u);
        ans += sum[u];
    }
    
    cout << ans << "\n";

    for(int i = 0; i <= n; i++){
        rg[i].clear();
        sum[i] = 0;
        mn_path[i] = 0;
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test_case; cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}