#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<ll, int, int>;

///DEBUG takes too much time :C
///https://www.spoj.com/problems/ANARC05B/

int a[N][2];
ll dis[2][N];
vector<pi> G[2][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        int n,m; cin >> n;
        if(n == 0) return 0;
        //cout << "N : " << n << "\n";
        map<int, int> mp;

        for(int i = 1; i <= n; i++){
            cin >> a[i][0];
            mp[a[i][0]] = i;
            G[0][i].emplace_back(i+1, 0);
        }

        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> a[i][1];
            G[1][i].emplace_back(i+1, 1);
            if(mp.count(a[i][1])){
                //cout << i << " " << mp[a[i][1]] << "\n";
                G[1][i].emplace_back(mp[a[i][1]]+1, 0);
                G[0][mp[a[i][1]]].emplace_back(i+1, 1);
            }
        }

        G[0][0].emplace_back(1, 0);
        G[1][0].emplace_back(1, 1);

        for(int i : {0, 1}) for(int j = 0; j <= max(n, m)+1; j++) dis[i][j] = -1e18;

        priority_queue<tu> pq;
        dis[0][0] = dis[1][0] = 0;
        pq.emplace(0, 0, 0);
        pq.emplace(0, 1, 0);
        while(!pq.empty()){
            auto [wa, cur, u] = pq.top(); pq.pop();

            //cout << "NOW : " << u << " " << cur << " " << wa << "\n";
            if(dis[cur][u] != wa) continue;

            for(auto [v, go] : G[cur][u]){
                assert(go <= 1 and v <= max(n, m)+1);
                //cout << v << " " << go << "\n";
                if(dis[cur][u] + a[u][cur] > dis[go][v]){
                    dis[go][v] = dis[cur][u]+a[u][cur];
                    pq.emplace(dis[go][v], go, v);
                }
            }
        }

        /*cout << "DIS\n";
        for(int i = 0; i <= n+1; i++) cout << dis[0][i] << " ";
        cout << "\n";
        for(int j = 0; j <= m+1; j++) cout << dis[1][j] << " ";
        cout << "\n";*/

        cout << max(dis[0][n+1], dis[1][m+1]) << "\n";

        for(int i = 0; i <= max(n, m); i++) G[0][i].clear(), G[1][i].clear();
    }
    return 0;
}
