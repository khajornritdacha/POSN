#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using pi = pair<int,int>;
bool chk[N];
set<int> vec[N];
int n,Q,cost[N],pa[N];

int dfs(int u){
    if(chk[u])
        return 0;
    int tmp = 0;
    for(int v : vec[u]){
        tmp += dfs(v);
    }
    return tmp+cost[u];
}
void cls(int u){
    if(chk[u])
        return;
    chk[u] = true;
    for(int v : vec[u])
        cls(v);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        int w,l,r;
        cin >> w >> l >> r;
        cost[i] = w;
        if(l != 0){
            vec[i].insert(l);
            pa[l] = i;
        }
        if(r != 0){
            vec[i].insert(r);
            pa[r] = i;
        }
    }
    while(Q--){
        char code;
        int u;
        cin >> code >> u;
        if(code == 'd'){
            cls(u);
            vec[pa[u]].erase(u);
        }else{
            cout << dfs(u) << "\n";
        }
    }
}
