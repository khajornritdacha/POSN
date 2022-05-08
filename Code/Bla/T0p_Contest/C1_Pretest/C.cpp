#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int p[1010],V,E,Q;
vector<pi> vec[1010];

int solve(int fmx, int st, int ed){
    vector<vector<int>> dis;
    vector<vector<bool>> vi;
    priority_queue<tu, vector<tu>, greater<tu>> pq;
    dis.resize(V); vi.resize(V);
    for(int i=0; i<V; i++){
        dis[i].resize(fmx+1, 1e9);
        vi[i].resize(fmx+1, false);
    }
    dis[st][0] = 0;
    pq.emplace(0, 0, st);
    while(!pq.empty()){
        int wa,fn,u;
        tie(wa, fn, u) = pq.top();
        pq.pop();
        if(u == ed){
            return dis[u][fn];
        }
        if(vi[u][fn])
            continue;
        vi[u][fn] = true;
        for(int k=0; fn+k<=fmx; k++){
            for(int i=0; i<vec[u].size(); i++){
                int v,w;
                tie(v, w) = vec[u][i];
                if(fn+k < w) continue;
                if(!vi[v][fn+k-w] && dis[u][fn]+(k*p[u]) < dis[v][fn+k-w]){
                    dis[v][fn+k-w] = dis[u][fn]+(k*p[u]);
                    pq.emplace(dis[v][fn+k-w], fn+k-w, v);
                }
            }
        }
    }
    //cout << "impossible\n";
    return 1e9;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0; i<V; i++){
        cin >> p[i];
    }
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    cin >> Q;
    while(Q--){
        int st,ed,fmx;
        cin >> fmx >> st >> ed;
        int res = solve(fmx, st, ed);
        if(res != 1e9)
            cout << res;
        else
            cout << "impossible";
        cout << "\n";
    }
}
