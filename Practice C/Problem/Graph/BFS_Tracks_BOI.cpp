//Task : BOI 13 Tracks
//BFS if the same character then it is the trace from the same animal otherwise it is made by a new one

#include <bits/stdc++.h>
using namespace std;

const int N = 4010, INF = 1e9;

int R, C, ti[N][N];
char arr[N][N];
queue<pair<int, int>> qq[2];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> arr[i][j];
            ti[i][j] = INF;
        }
    }

    int res = 1;
    ti[1][1] = 1;
    qq[1].emplace(1, 1);

    while(true){
        int cur = res&1;
        while(!qq[cur].empty()){
            auto [nr, nc] = qq[cur].front(); qq[cur].pop();

            for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
                if(abs(dr-dc) != 1) continue;
                int gr = nr+dr, gc = nc+dc;
                if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
                if(arr[gr][gc] != 'F' and arr[gr][gc] != 'R') continue;
                if(ti[gr][gc] != INF) continue;

                // cout << arr[gr][gc] << " " << arr[nr][nc] << "\n";
                if(arr[gr][gc] == arr[nr][nc]){
                    ti[gr][gc] = ti[nr][nc];
                    qq[cur].emplace(gr, gc);
                } else {
                    ti[gr][gc] = ti[nr][nc]+1;
                    qq[1-cur].emplace(gr, gc);
                    // cout << gr << " " << gc << "\n";
                }
            }
        }

        if(qq[1-cur].empty()){
            break;
        }
        res++;
    }

    cout << res << "\n";

    // for(int i = 1; i <= R; i++){
    //     for(int j = 1; j <= C; j++){
    //         cout << ti[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    return 0;
}