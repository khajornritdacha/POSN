#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

const int N = 25, INF = 1e9;

//Travelling Salesman
//https://www.spoj.com/problems/CLEANRBT/

int C,R,cnt, num[N][N], dp[1<<11][15];
char ta[N][N];
pi st, pos[15];
queue<tu> qq;
bool vi[N][N];

void bfs(int id, vector<int> &dis){
    if(id == -1) qq.emplace(0, st.first, st.second);
    else qq.emplace(0, pos[id].first, pos[id].second);
    
    memset(vi, 0, sizeof(vi));

    while(!qq.empty()){
        auto [di, r, c] = qq.front(); qq.pop();

        if(ta[r][c] == '*') dis[num[r][c]] = di;

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(vi[gr][gc] or ta[gr][gc] == 'x') continue;
            qq.emplace(di+1, gr, gc);
            vi[gr][gc] = true;
        }
    }
}

void test_case(){
    cin >> C >> R;
    
    if(C == 0 and R == 0) exit(0);

    cnt = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            if(ta[i][j] == 'o'){
                st = pi(i, j);
            }else if(ta[i][j] == '*'){
                num[i][j] = cnt;
                pos[cnt] = pi(i, j);
                cnt++;
            }
        }
    }

    vector<int> base(cnt, INF);
    vector<vector<int>> dis(cnt, vector<int>(cnt, INF));

    bfs(-1, base);
    for(int i = 0; i < cnt; i++) bfs(i, dis[i]);

    for(int bit = 0; bit < (1<<cnt); bit++) for(int i = 0; i < cnt; i++) dp[bit][i] = INF;
    for(int i = 0; i < cnt; i++) dp[1<<i][i] = base[i];

    for(int bit = 0; bit < (1<<cnt); bit++){
        for(int i = 0; i < cnt; i++){
            if(bit&(1<<i) == 0) continue;
            for(int j = 0; j < cnt; j++){
                if(bit&(1<<j)) continue;
                dp[bit | (1<<j)][j] = min(dp[bit | (1<<j)][j], dp[bit][i] + dis[i][j]);
            }    
        }   
    }

    int ans = INF;
    for(int i = 0; i < cnt; i++) ans = min(ans, dp[(1<<cnt)-1][i]);
    if(ans >= INF) ans = -1;
    cout << ans << "\n";

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        test_case();
    }    
    return 0;
}