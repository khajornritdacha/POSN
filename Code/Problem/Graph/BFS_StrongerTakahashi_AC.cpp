#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;

using tu = tuple<int,int,int>;

int R,C,dis[N][N];
char ta[N][N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

//https://atcoder.jp/contests/abc213/tasks/abc213_e

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            dis[i][j] = INF;
        }
    }

    auto chk = [](int r, int c){
        return (r >= 1 and r <= R and c >= 1 and c <= C);
    };

    dis[1][1] = 0;
    pq.emplace(0, 1, 1);
    while(!pq.empty()){
        auto [wa, r, c] = pq.top(); pq.pop();
        if(wa != dis[r][c]) continue;

        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = r+dr, gc = c+dc;
            if(!chk(gr, gc)) continue;
            
            if(ta[gr][gc] == '#'){
                vector<int> pr, pc;
                int sir = 1, sic = 1;
                if(dr != 0){
                    if(dr == -1) sir = -1;
                    pr = {1, 2};
                    pc = {-1, 0, 1};
                } else {
                    if(dc == -1) sic = -1;
                    pr = {-1, 0, 1};
                    pc = {1, 2};
                }

                for(int ddr : pr) for(int ddc : pc){
                    int ggr = r+(ddr*sir), ggc = c+(ddc*sic);
                    if(!chk(ggr, ggc)) continue;

                    if(dis[r][c] + 1 < dis[ggr][ggc]){
                        dis[ggr][ggc] = dis[r][c] + 1;
                        pq.emplace(dis[ggr][ggc], ggr, ggc);
                    }
                }
            } else {
                if(dis[r][c] < dis[gr][gc]){
                    dis[gr][gc] = dis[r][c];
                    pq.emplace(dis[gr][gc], gr, gc);
                }
            }
        }
    }   

    cout << dis[R][C] << "\n";
    return 0;
}