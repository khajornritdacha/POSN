#include<bits/stdc++.h>
using namespace std;
vector<int> order,vec[100010];
bitset<100010> chk;
int V,K,p[100010];
void topo(int u){
    chk[u]=true;
    for(auto v : vec[u]){
        if(!chk[v]){
            topo(v);
        }
    }
    order.emplace_back(u);
}
main(){
    cin >> V >> K;
    for(int i=1; i<=K; i++){
        int n;
        cin >> n;
        for(int j=1; j<=n; j++){
            int v;
            cin >> v;
            vec[i].emplace_back(v);
        }
    }
    for(int i=1; i<=V; i++){
        if(!chk[i])
            topo(i);
    }
    int boss=0;
    for(int i=V-1; i>=0; i--){
        p[order[i]]=boss;
        boss=order[i];
    }
    for(int i=1; i<=V; i++)
        cout << p[i] << "\n";
}
