#include <bits/stdc++.h>
using namespace std;

const int N = 160, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int a[N][N],R,C, dis[2][N][N];

void bfs(int cd, int sr, int sc){
    dis[cd][sr][sc] = 1;
    queue<pi> qq;;
    qq.emplace(sr, sc);
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(dis[cd][r][c] + 1 < dis[cd][gr][gc]){
                dis[cd][gr][gc] = dis[cd][r][c] + 1;
                if(a[gr][gc]){
                    qq.emplace(gr, gc);
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int sr,sc,er,ec;
    cin >> R >> C >> sr >> sc >> er >> ec;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            dis[0][i][j] = dis[1][i][j] = INF;
        }
    }

    bfs(0, sr, sc);
    bfs(1, er, ec);

    int ans = INF, cnt = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(a[i][j] == 0 and dis[0][i][j] != INF and dis[1][i][j] != INF){
                cnt++;                
                ans = min(ans, dis[0][i][j] + dis[1][i][j] - 1);
            }
        }
    }

    cout << cnt << "\n" << ans << "\n";
    return 0;

}