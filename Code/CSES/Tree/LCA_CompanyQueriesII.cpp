#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int n,Q,up[N][22],dep[N];
vector<int> vec[N];

void dfs(int u, int p);
int lca(int u,int v);

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        vec[x].emplace_back(i);
    }
    dfs(1, 1);

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << dep[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << "I " << i << " = ";
            for(int k=0; k<=3; k++){
                cout << up[i][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    while(Q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}

void dfs(int u, int p){
    up[u][0] = p;
    for(int k=1; k<=20; k++){
        if(up[u][k-1] != -1)
            up[u][k] = up[up[u][k-1]][k-1];
        else
            up[u][k] = up[u][k-1];
    }
    for(int v : vec[u]){
        if(v == p)
            continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int k=20; k>=0; k--){
        if(dep[up[u][k]] >= dep[v]){
            u = up[u][k];
        }
    }
    if(u == v) return u;
    //  cout << "U : " << u << "\n";
    for(int k=20; k>=0; k--){
        if(up[u][k] != up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}
