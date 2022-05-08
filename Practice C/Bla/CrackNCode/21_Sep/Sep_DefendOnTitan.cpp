#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using tu = tuple<ll, int, int>;
const int N = 1e3+10;
int R,C,w[N][N],pr[]={-1,1,0,0},pc[]={0,0,-1,1};
priority_queue<tu, vector<tu>, greater<tu>> pq;
ll dis[N][N];

///Seem to be DP but actually is SSSP
///https://www.hackerrank.com/contests/crack-n-code-september-2021/challenges/defend-on-titan/problem

int main(void){
    cin >> R >> C;
    memset(dis, 127, sizeof(dis));
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> w[i][j];
            if(i == R){
                pq.emplace(w[i][j], i, j);
                dis[i][j] = w[i][j];
            }
        }
    }

    while(!pq.empty()){
        auto [val, nr, nc] = pq.top(); pq.pop();
        if(nr == 1){
            cout << dis[nr][nc] << "\n";
            return 0;
        }
        if(dis[nr][nc] != val) continue;
        for(int i=0; i<4; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(dis[nr][nc]+w[gr][gc] < dis[gr][gc]){
                dis[gr][gc] = dis[nr][nc]+w[gr][gc];
                pq.emplace(dis[gr][gc], gr, gc);
            }
        }
    }

    return 0;
}
