#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int vi[N],ti,n,K,T;
bool cycle;
vector<int> mem[N],G[N];

bool topo(int u){
    if(vi[u]){
        return vi[u] == 1;
    }
    vi[u] = 1;
    ti++;
    for(int v : G[u]){
        if(topo(v))
            return true;
    }
    vi[u] = 2;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K >> T;
    for(int i = 1; i <= n; i++){
        int lv,P; cin >> lv >> P;
        mem[lv].emplace_back(i);
        for(int j = 1; j <= P; j++){
            int v; cin >> v;
            G[i].emplace_back(v);
        }
    }

    int ans = -1;
    for(int i = 1; i <= K; i++){
        for(int m : mem[i]){
            if(!vi[m])
                cycle |= topo(m);
        }
        //cout << i << " " << ti << "\n";
        if(cycle or ti > T) break;
        ans = i;
    }

    cout << ans << "\n";
    return 0;
}
