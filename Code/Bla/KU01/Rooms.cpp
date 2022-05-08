#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int,int>;

int R,C,ans;
char ta[N][N];
bool found,vi[N][N];
pi st;
queue<pi> qq;
vector<pi> warps;


bool valid(int r, int c){
    return (r >= 1 and r <= R and c >= 1 and c <= C);
}

void bfs(int code = 0){
    ans = 0;
    memset(vi, 0, sizeof(vi));
    if(code){
        for(pi warp : warps)
            qq.emplace(warp);
    }
    qq.emplace(st);

    while(!qq.empty()){
        auto [nr, nc] = qq.front(); qq.pop();
        vi[nr][nc] = true;
        if(ta[nr][nc] == '*') ans++;
        found |= (ta[nr][nc] == 'W');
        for(int dr : {-1, 0, 1}){
            for(int dc : {-1, 0, 1}){
                int gr = nr+dr, gc = nc+dc;
                if(abs(dr-dc) != 1) continue;
                if(!valid(gr, gc)) continue;
                if(ta[gr][gc] == '#') continue;
                if(vi[gr][gc]) continue;

                qq.emplace(gr, gc);
                vi[gr][gc] = true;
            }
        }
    }
}

int main(void){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            if(ta[i][j] == 'A'){
                st.first = i;
                st.second = j;
            }else if(ta[i][j] == 'W'){
                warps.emplace_back(i, j);
            }
        }
    }
    bfs();
    if(found){bfs(1); }
    cout << ans << "\n";
    return 0;
}
