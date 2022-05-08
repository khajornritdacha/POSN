#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/NOI18_collectmushrooms

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R, C, D, K; cin >> R >> C >> D >> K;
    vector<vector<char>> ta(R+10, vector<char>(C+10));
    vector<vector<int>> ep(R+10, vector<int>(C+10));
    
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
            if(ta[i][j] == 'S'){
                ep[max(1, i-D)][max(1, j-D)]++;
                if(i+D+1 <= R) ep[i+D+1][max(1, j-D)]--;
                if(j+D+1 <= C) ep[max(1, i-D)][j+D+1]--;
                if(i+D+1 <= R and j+D+1 <= C) ep[i+D+1][j+D+1]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            // cout << ep[i][j] << " ";
            ep[i][j] += ep[i-1][j]+ep[i][j-1]-ep[i-1][j-1];
     
            if(ta[i][j] == 'M' and ep[i][j] >= K){
                ans++;
            }
        }
        // cout << "\n";
    }

    cout << ans << "\n";

    return 0;
}