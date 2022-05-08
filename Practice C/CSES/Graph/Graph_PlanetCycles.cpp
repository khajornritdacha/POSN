#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int st,vi[N],n,sz[N],idx,cmp[N],dis[N];
bool cycle,incyc[N];
vector<int> vec[N],rev[N];
///https://cses.fi/problemset/task/1751
void find_cycle(int u, int p){
    if(vi[u]){
        st = u;
        incyc[u] = true;
        cycle = true;
        sz[idx]++;
        return;
    }
    vi[u] = 1;
    for(int v : vec[u]){
        find_cycle(v, u);
        if(cycle and st == u)
            cycle = false;
        incyc[u] = cycle;
        sz[idx] += cycle;
    }
}

void dfs(int u, int p){
    vi[u] = 2;
    cmp[u] = idx;
    for(int v : rev[u]){
        if(vi[v] == 2) continue;
        if(!incyc[v])
            dis[v] = dis[u]+1;
        dfs(v, u);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec[i].emplace_back(x);
        rev[x].emplace_back(i);
    }
    for(int i=1; i<=n; i++){
        if(!vi[i]){
            idx++;
            st = 0;
            find_cycle(i, -1);
            //cout << "I " << i << " = " << st << "\n";
            dfs(st, -1);
        }
    }

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << cmp[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << incyc[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << sz[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << dis[i] << " \n"[i==n];
        }
    }
    for(int i=1; i<=n; i++){
        cout << dis[i]+sz[cmp[i]] << " ";
    }
}
