#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int P,M,K,coins[15],mn=2e9,ans1,ans2,res[3][15],cost[3];
vector<int> dp;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> P >> M >> K;
    for(int i=1; i<=K; i++)
        cin >> coins[i];
    dp.resize(M+10, 1e9);
    dp[0] = 0;
    for(int i=1; i<=M; i++){
        for(int coin : coins){
            if(i-coin < 0) continue;
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }
    if(DEBUG){
        for(int i=0; i<=M; i++)
            cout << dp[i] << " \n"[i==M];
    }

    for(int i=P; i<=M; i++){
        if(dp[i] + dp[i-P] < mn){
            mn = dp[i]+dp[i-P];
            ans1 = dp[i];
            cost[1] = i;
            ans2 = dp[i-P];
            cost[2] = i-P;
        }
    }
    for(int i=1; i<=2; i++){
        while(cost[i]){
            for(int j=1; j<=K; j++){
                int coin = coins[j];
                if(cost[i]-coin < 0) continue;
                if(dp[cost[i]-coin] == dp[cost[i]]-1){
                    res[i][j]++;
                    cost[i]-=coin;
                    break;
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    for(int i=1; i<=2; i++){
        for(int j=1; j<=K; j++){
            cout << res[i][j] << " \n"[j==K];
        }
    }
}
