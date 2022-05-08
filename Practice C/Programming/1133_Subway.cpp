#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+10, M = 510;

int n,m,sz[M],Q,dis[M][M];
vector<int> st[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> sz[i];
        for(int j=1; j<=sz[i]; j++){
            int x; cin >> x;
            st[x].emplace_back(i);
        }
        for(int j=1; j<=m; j++)
            dis[i][j] = (i == j ? 0 : 1e9);
    }


    for(int i=1; i<=n; i++){
        for(int j=0; j<st[i].size(); j++){
            for(int k=j+1; k<st[i].size(); k++){
                int u = st[i][j], v = st[i][k];
                if(u != v){
                    dis[u][v] = dis[v][u] = 1;
                }
            }
        }
    }


    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << "I " << i << " : ";
            for(int u : st[i])
                cout << u << " ";
            cout << "\n";
        }
        cout << "------------------\n";
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                cout << dis[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "------------------\n";
    }

    for(int k=1; k<=m; k++){
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    cin >> Q;
    for(int i=1; i<=Q; i++){
        int qu, qv; cin >> qu >> qv;

        int mn = 1e9;
        for(int u : st[qu]){
            for(int v : st[qv]){
                mn = min(mn, dis[u][v]);
            }
        }

        if(mn == 1e9)
            cout << "impossible";
        else
            cout << mn;
        cout << "\n";
    }
}
