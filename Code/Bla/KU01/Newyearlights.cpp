#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int n,m,sz[N],in[N];
bool vi[N];
queue<int> qq;
vector<int> G[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> sz[i+n]; ///create fake node that will propagate if and only if all its child is 1
        for(int j = 1; j <= sz[i+n]; j++){
            int x; cin >> x;
            G[x].emplace_back(i+n);
        }
        int x; cin >> x;
        G[i+n].emplace_back(x);
    }

    qq.push(1);
    in[1] = 1;
    int ans = 0;

    while(!qq.empty()){
        int u = qq.front(); qq.pop();

        assert((u > n and in[u] == sz[u]) or (u <= n and in[u] > 0));

        if(vi[u]) continue;
        vi[u] = true;
        ans += (u <= n); ///current node is real node
        //cout << u << "\n";

        for(int v : G[u]){
            in[v]++;
            if(!vi[v]){
                if(v <= n and in[v] > 0) qq.push(v);
                else if(v > n and in[v] == sz[v]) qq.push(v);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
