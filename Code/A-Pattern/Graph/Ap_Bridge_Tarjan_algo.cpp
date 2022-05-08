///Finding Articulation point and bridge with tarjan algorithm
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi=pair<int,int>;

int low[N],disc[N],cnt,V,E;
vector<pi> bridge;
vector<int> arti_point,vec[N];

void tarjan(int u, int p){
    int child=0;
    low[u]=disc[u]=++cnt;
    for(auto v:vec[u]){
        if(!disc[v]){
            child++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);

            ///find articulation point
            if( p==0 && child > 1)
                arti_point.push_back(u);
            else if( p!=0 && low[v]>=disc[u])
                arti_point.push_back(u);

            ///bridge
            if( low[v] > disc[u] )
                bridge.push_back({u,v});
        }else if(v!=p){
            low[u]=min(low[u],disc[v]);
        }
    }
    return;
}

main(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    tarjan(1,0);
    
    cout << "Articulation point are: ";
    for(int u:arti_point)
        cout << u << " ";
    
    cout << "\nBridge are: ";
    for(auto [u,v]:bridge)
        cout << u << " " << v << ", ";
}

/*
5 5
2 1
1 3
3 2
1 4
4 5
*/
