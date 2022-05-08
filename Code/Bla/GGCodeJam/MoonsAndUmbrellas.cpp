#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e3+10;
int n,x,y,dp[N][2];
char t[N];
void TC(){
    cin >> x >> y >> t+1;
    n = strlen(t+1);
    for(int i=1; i<=n; i++){
        dp[i][0] = dp[i][1] = 1e9;
    }
    dp[0][0] = dp[0][1] = 0;
    for(int i=1; i<=n; i++){
        if(t[i] == 'C' or t[i] == '?')
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]+y);
        if(t[i] == 'J' or t[i] == '?')
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]+x);
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
    if(DEBUG){
        for(int k=0; k<=1; k++){
            for(int i=1; i<=n; i++){
                cout << dp[i][k] << " \n"[i==n];
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int te=1; te<=t; te++){
        cout << "Case #" << te << ": ";
        TC();
    }
}
