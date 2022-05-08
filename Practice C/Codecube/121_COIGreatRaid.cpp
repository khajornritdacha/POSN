#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
const int N = 1e5+10;
int V,E,p[N],mst[N],ans;
vector<int> vec[N];
bitset<N> visit;
priority_queue<pi, vector<pi>, greater<pi>> pq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i=1; i<=V; i++){
        cin >> p[i];
        mst[i] = 1e9;
    }
    cin >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    pq.emplace(0,1);
    mst[1] = 0;
    while(!pq.empty()){
        auto [waste, u] = pq.top();
        pq.pop();
        if(visit[u]) continue;
        visit[u] = true;
        ans+=mst[u];
        for(int v : vec[u]){
            if(!visit[v] && p[u] + p[v] < mst[v]){
                mst[v] = p[u]+p[v];
                pq.emplace(mst[v], v);
            }
        }
    }
    cout << ans << "\n";
}
