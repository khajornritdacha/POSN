#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9+7;
using tu = tuple<int, int, int, int>;

int A,B,C,W,H,dis[N][N][4];
char a[N][N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int evc(int dr, int dc){
    //cout << dr << " " << dc << "\n";
    assert((abs(dr) == 1 and dc == 0) or (dr == 0 and abs(dc) == 1));
    if (dr == -1) return 0;
    else if (dr == 1) return 1;
    else if (dc == -1) return 2;
    else if (dc == 1) return 3;
    assert(0);
    return -1;
}

int cal(int cd, int nc){
    if(cd == 0 or cd == 1){
        if(nc == 0 or nc == 1) return A;
        else return B;
    }else{
        if(nc == 2 or nc == 3) return A;
        else return B;
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C >> W >> H;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> a[i][j];
            dis[i][j][0] = dis[i][j][1] = dis[i][j][2] = dis[i][j][3] = INF;
        }
    }

    dis[H][1][3] = (a[H][1] == 'X') ? C : 0;
    pq.emplace(dis[H][1][3], H, 1, 3);
    while(!pq.empty()){
        auto [wa, r, c, cd] = pq.top(); pq.pop();
        if(dis[r][c][cd] != wa) continue;

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc, nc = evc(dr, dc);
            if(gr < 1 or gr > H or gc < 1 or gc > W) continue;
            int w = cal(cd, nc) + (a[gr][gc] == 'X' ? C : 0);
            
            if(dis[r][c][cd] + w < dis[gr][gc][nc]){
                dis[gr][gc][nc] = dis[r][c][cd] + w;
                pq.emplace(dis[gr][gc][nc], gr, gc, nc);
            }
        }
    }

    int ans = -1;
    ans = min({dis[1][W][0] + B, dis[1][W][1] + B, dis[1][W][2] + A, dis[1][W][3] + A});
    cout << ans << "\n";

    return 0;
}