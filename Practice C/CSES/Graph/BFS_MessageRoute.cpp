#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;

//https://cses.fi/problemset/task/1667/

int n,m,dis[N],pa[N];
vector<int> G[N];
queue<int> qq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    for(int i = 2; i <= n; i++) dis[i] = INF;

    qq.emplace(1);
    while(!qq.empty()){
        int u = qq.front(); qq.pop();

        for(int v : G[u]){
            if(dis[u] + 1 < dis[v]){
                dis[v] = dis[u] + 1;
                pa[v] = u;
                qq.emplace(v);
            }
        }
    }

    if(dis[n] >= INF){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << dis[n]+1 << "\n";
        int u = n;
        stack<int> st;
        while(u != 1){
            st.push(u);
            u = pa[u];
        }
        st.push(1);

        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}