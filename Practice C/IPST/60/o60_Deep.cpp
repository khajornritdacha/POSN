#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int n,Q,s,a,b,vec[N][2],L,ch[N][25],dep[N];
int dir(){
    int res = ((s&8)>>3);
    s = (s * a+b)%40507;
    return res;
}
///Binary Heap
int dfs(int u, int len){
    if(len == L)
        return u;
    if(vec[u][0] != -1 and vec[u][1] != -1){
        int tmp = dir();
        return dfs(vec[u][tmp], len+1);
    }
    for(int t=0; t<2; t++){
        if(vec[u][t] == -1) continue;
        for(int k=19; k>=0; k--){
            if(ch[u][k] != - 1 and len+(1<<k) <= L)
                return dfs(ch[u][k], len+(1<<k));
        }
    }
    return u;
}
void pre(int u=0, int len=0){
    dep[u] = len;
    for(int t=0; t<2; t++){
        if(vec[u][t] != -1)
            pre(vec[u][t], len+1);
    }
    if(vec[u][0] != -1 and vec[u][1] != -1 or (vec[u][0] == -1 and vec[u][1] == -1)){
        return;
    }
    int v;
    for(int t=0; t<2; t++)
        if(vec[u][t] != -1)
            v = vec[u][t];
    ch[u][0] = v;
    for(int k=1; k<20; k++){
        if(ch[u][k-1] == -1) break;
        ch[u][k] = ch[ch[u][k-1]][k-1];
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=0; i<n; i++){
        for(int t=0; t<2; t++){
            int v;
            cin >> v;
            vec[i][t]=v;
        }
    }
    for(int i=0; i<=n; i++) for(int j=0; j<=20; j++) ch[i][j] = -1;
    pre();
    while(Q--){
        cin >> L >> s >> a >> b;
        cout << dfs(0, 0) << "\n";
    }
}
