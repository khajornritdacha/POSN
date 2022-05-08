#include<bits/stdc++.h>
#define DEBUG false
#define chk(x) ((x) == 'H')
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
int cmp[N],V,Q,idx;
vector<int> vec[N];
char str[N];

void dfs(int u, int p){
    cmp[u] = idx;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
    }
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
        if(str[u] == str[v]){
            vec[u].emplace_back(v);
            vec[v].emplace_back(u);
        }
   }
    for(int i=1; i<=V; i++){
        if(!cmp[i]){
            idx++;
            dfs(i, -1);
        }
    }
    while(Q--){
        int a,b;
        char c;
        cin >> a >> b >> c;
        if(cmp[a] != cmp[b])
            cout << 1;
        else if(cmp[a] == cmp[b] and str[a] == c)
            cout << 1;
        else
            cout << 0;
    }
}
