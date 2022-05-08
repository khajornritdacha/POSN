#include <bits/stdc++.h>
using namespace std;

const int N = 2010, INF = 1e9;
using pi = pair<int,int>;

int R,C,dis[N][N];
char a[N][N];
queue<pi> qq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            dis[i][j] = INF;
            if(a[i][j] == 'X'){
                qq.emplace(i, j);
                dis[i][j] = 0;
            }
        }
    }

    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C or a[gr][gc] == 'W') continue;
            if(dis[r][c] + 1 < dis[gr][gc]){
                dis[gr][gc] = dis[r][c] + 1;
                qq.emplace(gr, gc);
            }
        }
    }

    int cnt = 0, ti = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(a[i][j] == 'A' and dis[i][j] < INF){
                cnt++;
                ti += dis[i][j]*2;
            }
        }
    }
    cout << cnt << " " << ti << "\n";
}