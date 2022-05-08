#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using tu = tuple<int,int,int,int>;
int cnt,p[N],rnk[N],V,E,T;
long long ans;
bitset<N> chk;
vector<tu> edges;

int fi(int x){
    if(p[x] != x) return p[x] = fi(p[x]);
    return x;
}
bool uni(int u, int v){
    int hu = fi(u), hv = fi(v);
    if(hu != hv){
        if(rnk[hu] < rnk[hv])
            swap(hu, hv);
        if(rnk[hu] == rnk[hv])
            rnk[hu]++;
        p[hv] = hu;
        return true;
    }
    return false;
}
main(){
    cin >> V >> E;
    for(int i=1; i<=V; i++){
        p[i] = i;
    }
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v, i);
    }
    cin >> T;
    sort(edges.rbegin(), edges.rend());
    for(int i=0; i<edges.size(); i++){
        int w,u,v,idx;
        tie(w, u, v, idx) = edges[i];
        if(uni(u, v)){
            ans += w;
            chk[i] = true;
            cnt++;
        }
    }

    for(int i=0; i<edges.size(); i++){
        int w = get<0>(edges[i]);
        if(chk[i] == false){
            ans += w;
            chk[i] = true;
            cnt++;
            break;
        }
    }

    if(cnt == V){
        cout << ans << "\n";
        if(T == 2){
            for(int i=0; i<edges.size(); i++){
                if(chk[i]){
                    cout << get<3>(edges[i]) << " ";
                }
            }
        }
    }else{
        cout << "-1";
    }
    cout << "\n";
}
