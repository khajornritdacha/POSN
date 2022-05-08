#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using lb = long double;
using pi = pair<lb,int>;

///denote S := minimum product of edge used from st to ed
///       S = w1*w2*...*wn
///take log; log(S) = log(w1*w2*...*wn)
///                 = log(w1)+log(w2)+....+log(wn)

int V,E,st,ed;
vector<int> bt;
vector<pi> vec[N];
vector<lb> dis;
stack<int> res;

void dij(){
    priority_queue<pi, vector<pi>, greater<pi>> qq;
    qq.emplace(0, st);
    dis[st] = 0;
    while(!qq.empty()){
        auto [wa, u] = qq.top(); qq.pop();
        if(wa != dis[u]) continue;
        for(auto [w, v] : vec[u]){
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                bt[v] = u;
                qq.emplace(dis[v], v);
            }
        }
    }
}


void test_case(){
    cin >> V >> E >> st >> ed;
    dis.resize(V, 1e9); bt.resize(V);
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        lb rw = log10(w);
        vec[u].emplace_back(rw, v);
        vec[v].emplace_back(rw, u);
    }

    dij();

    int now = ed;
    while(now != st){
        res.push(now);
        now = bt[now];
    }
    res.push(st);

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }

}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
