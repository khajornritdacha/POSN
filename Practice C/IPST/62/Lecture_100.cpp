#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;

const int N = 310, K = 1e5+10, INF = 1e9;

int C, n, m, cl[K], dis[N][N], len[K], gap[K];

main(void){
    cin >> C >> n >> m;
    for(int i = 1; i <= C; i++){
        cin >> cl[i];
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = INF;

    for(int i = 1; i <= C; i++){
        cin >> len[i];
    }

    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w;
    }

    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    
    for(int i = 2; i <= C; i++){
        gap[i] = dis[cl[i-1]][cl[i]];
    }

    ll l = 1, r = 1e12, ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1, pre = len[1];
        bool ok = true;
        for(int i = 2; i <= C; i++){
            ll cur = len[i], tot = pre+cur, use = 1ll*gap[i]*mid;

            if(use <= tot){
                if(use <= pre) pre = cur;
                else {
                    use -= pre;
                    cur -= use;
                    pre = cur;
                }
            } else {
                ok = false;
                break;
            }
        }

        if(ok){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << ans << "\n";
    return 0;
}