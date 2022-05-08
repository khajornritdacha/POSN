#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int n,a[N],dp[N][2];
bool vi[N];
vector<int> rG[N];

void dfs(int u, const int &root, const int &ban, int cd){
    vi[u] = true;

    dp[u][0] = dp[u][1] = 0;
    for(int v : rG[u]){
        if(u == ban and v == root) continue;
        dfs(v, root, ban, cd);
        dp[u][0] += min(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][0]++;

    if(u == ban){
        if(cd == 0){
            dp[u][1] = INF;
        } else {
            dp[u][0] = INF;
        }
    }
    
    return;
}

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        rG[a[i]].emplace_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vi[i]) continue;

        int u = i;
        while(!vi[u]){
            vi[u] = true;
            u = a[u];
        }
        int ch = a[u]; //find root in the cycle and its child

        dfs(u, u, ch, 0); //let ch be villager
        int res = min(dp[u][0], dp[u][1]); //ans is derived from both 0, 1

        dfs(u, u, ch, 1); //let ch be werewolf
        res = min(res, dp[u][0]); //ans can only come from 0(u become villager)

        ans += res;
    }

    cout << ans << "\n";

    for(int i = 0; i <= n; i++){
        rG[i].clear();
        dp[i][0] = dp[i][1] = vi[i] = 0;
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}