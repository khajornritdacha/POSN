#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

using tu = tuple<int,int,int>;
const int N = 2e3+10;
int dis[2][N][N],n,m,W,a[N][N],pr[]={-1,1,0,0},pc[]={0,0,-1,1};
priority_queue<tu, vector<tu>, greater<tu>> pq;
///https://codeforces.com/problemset/problem/1520/G
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> W;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            for(int t=0; t<2; t++)
                dis[t][i][j] = 1e18;
        }
    }

    int beval=1e18;
    dis[1][n][m] = 0;
    pq.emplace(0, n, m);
    while(!pq.empty()){
       auto [wa, r, c] = pq.top();
       pq.pop();
       if(a[r][c] != 0){
            beval = min(beval, a[r][c]+dis[1][r][c]);
       }
        for(int i=0; i<4; i++){
            int gr = r+pr[i], gc = c+pc[i];
            if(gr < 1 or gr > n or gc < 1 or gc > m) continue;
            if(a[gr][gc] == -1) continue;
            if(dis[1][r][c]+W < dis[1][gr][gc]){
                dis[1][gr][gc] = dis[1][r][c]+W;
                pq.emplace(dis[1][gr][gc], gr, gc);
            }
        }
    }

    dis[0][1][1] = 0;
    pq.emplace(0, 1, 1);
    while(!pq.empty()){
        auto [wa, r, c] = pq.top();
        pq.pop();
        if(a[r][c] != 0){
            dis[0][n][m] = min(dis[0][n][m], dis[0][r][c]+a[r][c]+beval);
        }
        for(int i=0; i<4; i++){
            int gr = r+pr[i], gc = c+pc[i];
            if(gr < 1 or gr > n or gc < 1 or gc > m) continue;
            if(a[gr][gc] == -1) continue;
            if(dis[0][r][c]+W < dis[0][gr][gc]){
                dis[0][gr][gc] = dis[0][r][c]+W;
                pq.emplace(dis[0][gr][gc], gr, gc);
            }
        }
    }


    if(DEBUG){
        for(int t=0; t<2; t++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    cout << dis[t][i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
    if(dis[0][n][m] == 1e18)
        dis[0][n][m] = -1;
    cout << dis[0][n][m];
}
