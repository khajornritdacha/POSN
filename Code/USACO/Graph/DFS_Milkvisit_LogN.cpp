#include<bits/stdc++.h>
#define DEBUG false
#define chk(x) ((x) == 'H')
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
int V,Q,pa[N][20],dep[N],sum[N][2];
char str[N];
vector<int> vec[N];

void dfs(int u, int p){
    pa[u][0] = p;
    for(int k=1; k<=17; k++){
        pa[u][k] = pa[pa[u][k-1]][k-1];
    }
    sum[u][chk(str[u])]++;
    for(int v : vec[u]){
        if(v == p) continue;
        sum[v][0] += sum[u][0];
        sum[v][1] += sum[u][1];
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int k=17; k>=0; k--){
        if(dep[pa[u][k]] >= dep[v])
            u = pa[u][k];
    }
    if(u == v)
        return u;
    for(int k=17; k>=0; k--){
        if(pa[u][k] != pa[v][k]){
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    return pa[u][0];
}

void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
main(){
    setIO("milkvisits");
    cin >> V >> Q >> str+1;
    for(int i=1; i<V; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, 0);

    if(DEBUG){
        for(int i=1; i<=V; i++){
            for(int j=0; j<2; j++){
                cout << sum[i][j] << " ";
            }
            cout << "\n";
        }
    }

    while(Q--){
        int a,b,res[3]={};
        char c;
        cin >> a >> b >> c;
        int tmp = lca(a, b);
        for(int i=0; i<2; i++)
            res[i] = sum[a][i]+sum[b][i]-sum[pa[tmp][0]][i]-sum[tmp][i];
        cout << (res[chk(c)] > 0);
    }
}
