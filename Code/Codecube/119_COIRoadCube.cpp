#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int R = 105, C = 1e4+10;
int N,M,K,a[R][C],dp[R][C],ans;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j];
        }
    }
    for(int i=N; i>=1; i--){
        deque< pair<int,int> > dq;
        for(int j=1; j<=K; j++){
            while(!dq.empty() && dp[i+1][j] > dq.back().first)
                dq.pop_back();
            dq.emplace_back(dp[i+1][j], j);
        }

        if(DEBUG){
            cout << "I : " << i << "\n";
            for(auto [x,y] : dq)
                cout << x << " " << y << "\n";
            cout << "\n";
        }

        for(int j=1; j<=M; j++){
            while(!dq.empty() && j-dq.front().second > K)
                dq.pop_front();
            if(j+K<=M){
                while(!dq.empty() && dp[i+1][j+K] > dq.back().first)
                    dq.pop_back();
                dq.emplace_back(dp[i+1][j+K], j+K);
            }
            dp[i][j] = dq.front().first + a[i][j];

            if(DEBUG){
                cout << "J : " << j << "\n";
                for(auto [x,y] : dq)
                    cout << x << " " << y << "\n";
                cout << "\n";
            }

        }
    }

    if(DEBUG){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }

    for(int j=1; j<=M; j++)
        ans = max(ans, dp[1][j]);
    cout << ans << "\n";
}
/// dp[i][j] = max(dp[i+1][j+r]) + a[i][j]; -K <= r <= K
/// optimize using sliding window
