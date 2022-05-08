#include <bits/stdc++.h>
using namespace std;

const int N = 710, INF = 1e9;
using pi = pair<int,int>;

int R,C,mn[N][N];
char ta[N][N];
queue<pi> qq;

void bfs(pi st, vector<vector<int>> &dis){
    dis[st.first][st.second] = 1;
    qq.emplace(st);
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr - dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(ta[gr][gc] == 'I') continue;

            if(dis[r][c] + 1 < dis[gr][gc] and dis[r][c] + 1 < mn[gr][gc]){
                dis[gr][gc] = dis[r][c]+1;
                qq.emplace(gr, gc);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;

    pi vi, my, tre;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            if(ta[i][j] == 'V') vi = pi(i, j);
            else if(ta[i][j] == 'Y') my = pi(i, j);
            else if(ta[i][j] == 'T') tre = pi(i, j);
            mn[i][j] = INF;
        }
    }

    vector<vector<int>> dis(R+1, vector<int>(C+1, INF));
    bfs(vi, dis);

    for(int i = 1; i <= R; i++){
        int st = 0, cm = INF;
        for(int j = 1; j <= C; j++){
            if(ta[i][j] == 'I') continue;

            cm = min(cm, dis[i][j]);
            if(st == 0) st = j;

            if(j == C or ta[i][j+1] == 'I'){
                for(int k = st; k <= j; k++) mn[i][k] = min(mn[i][k], cm);
                cm = INF;
                st = 0;
            }
        }
    }

    for(int j = 1; j <= C; j++){
        int st = 0, cm = INF;
        for(int i = 1; i <= R; i++){
            if(ta[i][j] == 'I') continue;

            cm = min(cm, dis[i][j]);
            if(st == 0) st = i;

            if(i == R or ta[i+1][j] == 'I'){
                for(int k = st; k <= i; k++) mn[k][j] = min(mn[k][j], cm);
                cm = INF;
                st = 0;
            }
        }
    }

    for(int i = 0; i <= R; i++) for(int j = 0; j <= C; j++) dis[i][j] = INF;
    bfs(my, dis);

    if(dis[tre.first][tre.second] < INF) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}