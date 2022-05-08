#include <bits/stdc++.h>
#include "obstacle.h"
#define DEBUG 0
using namespace std;

const int INF = 2e9+10;

//ans comes from every point such that its row is below a banned row and its column is to the left of a banned column
//ans is the minimum of distance from top-left to x and from x to bottom-right

int n;
vector<vector<int>> tl, br, dp, mn;

void initialize(int N, int M, int Q, vector<vector<int>> &rowlen, vector<vector<int>> &collen){
    n = N;
    tl.resize(N, vector<int>(M, INF));
    br.resize(N, vector<int>(M, INF));
    dp.resize(N, vector<int>(M, INF));
    mn.resize(N+1, vector<int>(M, INF));

    tl[0][0] = 0;
    br[N-1][M-1] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i+1 < N)
                tl[i+1][j] = min(tl[i+1][j], tl[i][j]+collen[i][j]);
            if(j+1 < M)
                tl[i][j+1] = min(tl[i][j+1], tl[i][j]+rowlen[i][j]);
        }
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = M-1; j >= 0; j--){
            dp[i][j] = tl[i][j] + br[i][j];
            if(i-1 >= 0)
                br[i-1][j] = min(br[i-1][j], br[i][j]+collen[i-1][j]);
            if(j-1 >= 0)
                br[i][j-1] = min(br[i][j-1], br[i][j]+rowlen[i][j-1]);
        }
    }

    if(DEBUG){
        cout << "\nTL\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << tl[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nBR\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << br[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    for(int j = 0; j < M; j++){
        for(int i = N-1; i >= 0; i--){
            mn[i][j] = min(dp[i][j], mn[i+1][j]);
        }
    }

    return;
}

int ask(int R, int C){
    if(C == 0 or R == n-1) return -1;
    return mn[R+1][C-1];
}

// int main(void){
//     int N, M, Q; cin >> N >> M >> Q;
//     vector<vector<int>> rowlen(N, vector<int>(M-1)), collen(N-1, vector<int>(M));
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < M-1; j++){
//             cin >> rowlen[i][j];
//         }
//     }
//     for(int i = 0; i < N-1; i++){
//         for(int j = 0; j < M; j++){
//             cin >> collen[i][j];
//         }
//     }

//     initialize(N, M, Q, rowlen, collen);

//     for(int i = 0; i < Q; i++){
//         int r, c; cin >> r >> c;
//         cout << ask(r, c) << "\n";
//     }
//     return 0;
// }