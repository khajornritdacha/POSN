#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
const int N = 300;
ll M,Q,ap[N][N],cnt;
pi pos[N];
map<pi, int> mp;
ll dis(pi u, pi v){
    ll absx = abs(u.first-v.first);
    ll absy = abs(u.second-v.second);
    if(absx >= absy) return absx;
    return absy+((absy-absx)&1);
}

ll dij(pi u, pi v){
    pos[0] = u; pos[cnt+1] = v;
    vector<ll> mn(cnt+2, 1e18);
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.emplace(0, 0);
    mn[0] = 0;
    while(!pq.empty()){
        auto [wa, idx] = pq.top(); pq.pop();
        if(wa != mn[idx]) continue;
        for(int i = 0; i <= cnt+1; i++){
            if(i == idx) continue;
            ll tmp;
            if(ap[idx][i]) tmp = 1;
            else tmp = dis(pos[idx], pos[i]);
            if(mn[idx]+tmp < mn[i]){
                mn[i] = mn[idx]+tmp;
                pq.emplace(mn[i], i);
            }
        }
    }
    return mn[cnt+1];
}

int main(void){
    cin >> M >> Q;
    for(int i = 1; i <= M; i++){
        pi u, v;
        cin >> u.first >> u.second >> v.first >> v.second;
        if(mp[u] == 0){ ++cnt, pos[cnt] = u, mp[u] = cnt; }
        if(mp[v] == 0){ ++cnt, pos[cnt] = v, mp[v] = cnt; }
        ap[mp[u]][mp[v]] = ap[mp[v]][mp[u]] = 1;
    }
    //cout << "CNT : " << cnt << "\n";
    while(Q--){
        pi u,v;
        cin >> u.first >> u.second >> v.first >> v.second;
        ll ans = dij(u, v);
        cout << ans << "\n";
    }
    return 0;
}
