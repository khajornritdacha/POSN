#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

int n,coin[N],dd[N];
vector<int> cp[N];
ll st[N], ed[N], qs[N], INF = 1e18, C;

int dis(int fr, int to){
    if(to >= fr) return qs[to] - qs[fr];
    return C + qs[to] - qs[fr];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> coin[i];
        cp[coin[i]].emplace_back(i);
        mx = max(mx, coin[i]);

        st[i] = ed[i] = INF;
        if(coin[i] == 1) 
            st[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        cin >> dd[i];
        C += dd[i];
    }

    qs[1] = dd[n];
    for(int i = 2; i <= n; i++){
        qs[i] = qs[i-1] + dd[i-1];
    }

    // for(int i = 1; i <= n; i++){
    //     cout << qs[i] << " \n"[i==n];
    // }


    for(int k = 1; k <= mx; k++){
        int sz = cp[k].size();

        for(int i : cp[k]){
            for(int j : cp[k-1]){
                st[i] = min(st[i], ed[j] + min(dis(i, j), dis(j, i)));
            }
        }

        if(sz == 1){
            ed[cp[k][0]] = st[cp[k][0]];
        } else {
            for(int i : cp[k]){
                for(int j : cp[k]){
                    if(i == j) continue;
                    ed[i] = min(ed[i], st[j] + min(dis(i, j), dis(j, i)));
                }
            }
        }
    }

    ll ans = INF;
    for(int i : cp[mx]) ans = min(ans, ed[i]);
    cout << ans << "\n";
    return 0;
}