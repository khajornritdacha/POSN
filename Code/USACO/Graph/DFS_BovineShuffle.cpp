#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,p[N],ans,vi[N],st;

void dfs(int u){
    if(vi[u] == 2)
        return;
    if(vi[u] == 1){
        st = u;
        return;
    }
    vi[u] = 1;
    dfs(p[u]);
    if(st != -1){
        ans++;
        if(st == u)
            st = -1;
    }
    vi[u] = 2;
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    cout << ans << "\n";
}
