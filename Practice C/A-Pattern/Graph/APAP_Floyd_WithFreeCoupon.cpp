#include<bits/stdc++.h>
using namespace std;
int V,E,q,vec[105][105];
main(){
    cin >> V >> E;
    for(int i=1; i<=V*3; i++){
        for(int j=1; j<=V*3; j++){
            vec[i][j]=1e9;
        }
    }
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ///same stage use weight = w ( does not use free coupon )
        ///different stage use weight = 0 ( use free coupon )
        vec[u][v]=w;
        vec[V+u][V+v]=w;
        vec[V+V+u][v+V+V]=w;
        vec[u][v+V]=0;
        vec[u+V][v+V+V]=0;
    }
    for(int i=1; i<=V; i++){
        vec[i][i]=0;
        vec[V+i][V+i]=0;
        vec[V+V+i][V+V+i]=0;
    }
    for(int k=1; k<=V*3; k++){
        for(int i=1; i<=V*3; i++){
            for(int j=1; j<=V*3; j++){
                vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
            }
        }
    }
    cin >> q;
    while(q--){
        int u,v,x;
        cin >> u >> v >> x;
        cout << vec[u][v+(x*V)] << "\n";
        ///if 0 coupon v+0
    }
    ///total node = V*3
}
