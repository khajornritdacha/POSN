#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int V,mxdep[N],mx[N][2],pos[N][2],dep[N],ans[N],bot[N];
vector<int> vec[N];


void fimax(int u, int p){
    mxdep[u] = dep[u];
    for(int v : vec[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        fimax(v, u);
        bot[u] = max(bot[u], bot[v]);
        mxdep[u] = max(mxdep[u], mxdep[v]);
        int tmp = bot[v], no = v;
        if(tmp > mx[u][0]){
            swap(tmp, mx[u][0]);
            swap(no, pos[u][0]);
        }
        if(tmp > mx[u][1]){
            swap(tmp, mx[u][1]);
            swap(no, pos[u][1]);
        }
    }
    bot[u]++;
}

void dfs(int u, int p, int use=0){
    if(DEBUG){
        cout << "NOW " << u << " = " << use << "\n";
    }
    ans[u] = max(mxdep[u]-dep[u], use);
    for(int v : vec[u]){
        if(v == p) continue;
        int send;
        if(v != pos[u][0])
            send = mx[u][0];
        else
            send = mx[u][1];
        dfs(v, u, max(use, send)+1);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i=1; i<V; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    fimax(1, 0);
    dfs(1, 0);

    if(DEBUG){
        cout << "MX\n";
        for(int i=1; i<=V; i++){
            cout << mx[i][0] << " " << pos[i][0] << "\n";
        }
        cout << "\n--------------\n";
        for(int i=1; i<=V; i++){
            cout << mx[i][1] << " " << pos[i][1] << "\n";
        }
        cout << "\n--------------\n";
        for(int i=1; i<=V; i++){
            cout << mxdep[i] << " \n"[i==V];
        }
        cout << "--------------\n";
        for(int i=1; i<=V; i++){
            cout << dep[i] << " \n"[i==V];
        }
        cout << "--------------\n";
    }
    for(int i=1; i<=V; i++)
        cout << ans[i] << " \n"[i==V];

}
