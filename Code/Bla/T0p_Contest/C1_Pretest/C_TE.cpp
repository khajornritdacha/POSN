#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int p[N],V,E,Q;
vector<vector<pi>> vec;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0; i<V; i++){
        cin >> p[i];
    }
    vec.resize(V+1);
    for(int i=1; i<=V; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    cin >> Q;
    while(Q--){
        int st,ed,fmx;
        cin >> fmx >> st >> ed;
        priority_queue<tu, vector<tu>, greater<tu>> pq;
        vector<vector<int>> dis;
        dis.assign(V+1, vector<int>(fmx+1, 1e9));
        vector<vector<bool>> vi(V+1, vector<bool>(fmx+1, false));
        dis[st][0] = 0;
        pq.emplace(0, st, 0);
        while(!pq.empty()){
            int wa,u,fn;
            tie(wa, u, fn) = pq.top();
            //cout << "NOW " << u << " " << wa << " " << fn << "\n";
            pq.pop();
            if(vi[u][fn]) continue;
            if(wa != dis[u][fn]) continue;
            vi[u][fn] = true;
            for(int i=0; i<vec[u].size(); i++){
                int v,w;
                tie(v, w) = vec[u][i];
                for(int k=0; fn+k<=fmx; k++){
                    if(fn+k < w) continue;
                    if(dis[u][fn]+k*p[u] < dis[v][fn+k-w]){
                        dis[v][fn+k-w] = dis[u][fn]+k*p[u];
                        pq.emplace(dis[v][fn+k-w], v, fn+k-w);
                    }
                }
            }
        }
        int ans = 1e9;
        for(int k=0; k<=fmx; k++){
            ans = min(ans, dis[ed][k]);
        }
        if(ans == 1e9){
            cout << "impossible\n";
        }else{
            cout << ans << "\n";
        }
    }
}
