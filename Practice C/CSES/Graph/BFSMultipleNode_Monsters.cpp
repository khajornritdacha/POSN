#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1e9;
using pi = pair<int,int>;

int R,C,dis[N][N][2],str,stc;
char a[N][N];
queue<pi> qq;
pi pa[N][N];

//https://cses.fi/problemset/task/1194/

bool chk(int r, int c){
    return (r >= 1 and r <= R and c >= 1 and c <= C and a[r][c] != '#');
}

char cal(pi x){
    if(x.first == -1) return 'U';
    else if(x.first == 1) return 'D';
    else if(x.second == -1) return 'L';
    return 'R';
}

void bfs(int cd){
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();
        
        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(!chk(gr, gc)) continue;
            if(dis[r][c][cd] + 1 < dis[gr][gc][cd]){
                dis[gr][gc][cd] = dis[r][c][cd] + 1;
                if(cd == 1) pa[gr][gc] = {dr, dc};
                qq.emplace(gr, gc);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            dis[i][j][0] = dis[i][j][1] = INF;
            if(a[i][j] == 'A') str = i, stc = j;
            else if(a[i][j] == 'M'){
                qq.emplace(i, j);
                dis[i][j][0] = 0;
            }
        }
    }

    bfs(0);

    dis[str][stc][1] = 0;
    qq.emplace(str, stc);
    bfs(1);
    
    int tar = 0, tac = 0;
    for(int i = 1; i <= R; i++){
        if(dis[i][1][1] < INF and dis[i][1][1] < dis[i][1][0]){
            tar = i, tac = 1;
            break;
        }else if(dis[i][C][1] < INF and dis[i][C][1] < dis[i][C][0]){
            tar = i, tac = C;
            break;
        }
    }

    //cout << tar << " " << tac << " " << dis[R][2][0] << " " << dis[R][2][1] << "\n";
    if(tar == 0){
        for(int j = 1; j <= C; j++){
            if(dis[1][j][1] < INF and dis[1][j][1] < dis[1][j][0]){
                tar = 1, tac = j;
                break;
            }
            //cout << dis[R][j][1] << " " << dis[R][j][0] << "\n";
            if(dis[R][j][1] < INF and dis[R][j][1] < dis[R][j][0]){
                tar = R, tac = j;
                break;
            }
        }
    }

    if(tar == 0){
        cout << "NO\n";
    }else{ //back track
        cout << "YES\n";
        stack<char> st;
        int nr = tar, nc = tac;
        while(nr != str or nc != stc){
            st.push(cal(pa[nr][nc]));
            int tr = nr-pa[nr][nc].first, tc = nc-pa[nr][nc].second;
            nr = tr, nc = tc;
        }
        cout << st.size() << "\n";
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }

    return 0;
}