#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
long long ans;
set<int> ss;
vector<int> vec[N];
int mn[N],V,E,ST,cost[N],mx;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> ST;
    for(int i=1; i<=V; i++){
        cin >> cost[i];
        mn[i] = 1e9;
    }
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    queue<int> qq;
    mn[ST] = 0;
    qq.emplace(ST);
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        mx = max(mx, mn[u]);
        for(int v : vec[u]){
            if(mn[u]+1 < mn[v]){
                mn[v] = mn[u]+1;
                qq.emplace(v);
            }
        }
    }

    //cout << "MX : " << mx << "\n";
    for(int i=1; i<=mx; i++){
        ss.insert(i);
    }
    vector<pair<int,int>> chua;
    for(int i=1; i<=V; i++){
        if(mn[i] == 1e9){
            if(cost[i] > 0)
                ans += cost[i];
        }else{
            chua.emplace_back(cost[i], i);
        }
    }
    sort(chua.rbegin(), chua.rend());
    for(auto [val, i] : chua){
        //cout << val << " " << i << " " << mn[i] << "\n";
        if(val <= 0) break;
        auto it = ss.upper_bound(mn[i]);
        if(it != ss.begin()){
            it--;
            ss.erase(it);
            ans += val;
        }
    }
    cout << ans << "\n";
}
