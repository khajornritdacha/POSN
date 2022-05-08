#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;

int R,C,ta[N][N],dis[N][N][2];
queue<tuple<int,int,int>> qq;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            char c; cin >> c;
            ta[i][j] = (c == '/');
            dis[i][j][0] = dis[i][j][1] = INF;
        }
    }

    int pr[2][2] = {{-1, 1}, {-1, 1}}, pc[2][2] = {{-1, 1}, {1, -1}};
    dis[1][1][0] = ta[1][1];
    qq.emplace(1, 1, 0);
    while(!qq.empty()){
        auto [r, c, cd] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            
            int w = (ta[gr][gc] == cd);
            if(dis[r][c][cd] + w < dis[gr][gc][!cd]){
                dis[gr][gc][!cd] = dis[r][c][cd] + w;
                qq.emplace(gr, gc, !cd);
            }
        }

        for(int i = 0; i < 2; i++){
            int gr = r+pr[cd][i], gc = c+pc[cd][i];
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            
            int w = (ta[gr][gc] != cd);
            if(dis[r][c][cd] + w < dis[gr][gc][cd]){
                dis[gr][gc][cd] = dis[r][c][cd] + w;
                qq.emplace(gr, gc, cd);
            }

        }
    }

    if(dis[R][C][0] >= INF) cout << "NO SOLUTION\n";
    else cout << dis[R][C][0] << "\n";

    return 0;
}