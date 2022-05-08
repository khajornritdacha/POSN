#include <bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

int R,C,exr,exc,sr,sc,dis[N][N],ans;
char ta[N][N];
queue<pi> qq;

//https://codeforces.com/contest/329/problem/B
//move every t to the exit so that it can guarantee to make a fight
//fight will ensue if and only if the distance from exit to t is less than or equal to distance from start to exit (dis(ti, tj) <= dis(si, sj))

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            if(ta[i][j] == 'E'){
                exr = i, exc = j;
            } else if(ta[i][j] == 'S'){
                sr = i, sc = j;
            }
            dis[i][j] = INF;
        }
    }

    qq.emplace(exr, exc);
    dis[exr][exc] = 0;
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(ta[gr][gc] == 'T') continue;
            if(dis[gr][gc] != INF) continue;
    
            dis[gr][gc] = dis[r][c] + 1;
            qq.emplace(gr, gc);
        }
    }

    for(int i = 1; i <= R; i++) for(int j = 1; j <= C; j++){
        if(ta[i][j] >= '0' and ta[i][j] <= '9' and dis[i][j] <= dis[sr][sc]){
            ans += ta[i][j]-'0';
        }
    }

    cout << ans << "\n";

    return 0;
}
