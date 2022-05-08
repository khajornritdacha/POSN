#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1e9;
using pi = pair<int,int>;

int R,C,dis[N][N], str, stc, edr, edc;
char a[N][N];
pi pa[N][N];
queue<pi> qq;

//https://cses.fi/problemset/task/1193/

bool chk(int r, int c){
    return (r >= 1 and r <= R and c >= 1 and c <= C and a[r][c] != '#');
}

char cal(pi x){
    if(x.first == -1) return 'U';
    else if(x.first == 1) return 'D';
    else if(x.second == -1) return 'L';
    else return 'R';
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            dis[i][j] = INF;
            if(a[i][j] == 'A') str = i, stc = j;
            else if(a[i][j] == 'B') edr = i, edc = j;
        }
    }

    dis[str][stc] = 0;
    //cout << str << " " << stc << "\n";
    qq.emplace(str, stc);
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(!chk(gr, gc)) continue;
            if(dis[r][c] + 1 < dis[gr][gc]){
                dis[gr][gc] = dis[r][c]+1;
                pa[gr][gc] = {dr, dc};
                qq.emplace(gr, gc);
            }
        }
    }

    //cout << dis[edr+1][edc] << " " << dis[edr][edc] << " " << pa[edr][edc].first << " " << pa[edr][edc].second << "\n";

    if(dis[edr][edc] >= INF){
        cout << "NO\n";
    }else{
        cout << "YES\n";

        stack<char> st;
        int nr = edr, nc = edc;
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