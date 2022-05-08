#include<bits/stdc++.h>
using namespace std;
int n,k,dp[1<<8],cost[1<<8];
int solve(int s){
    for(int i=1; i<(1<<k); i++){
        if(dp[s]+cost[i]<dp[s|i]){
            //cout << s << " " << i << " " << cost[i] << "\n";
            dp[s|i]=dp[s]+cost[i];
            solve(s|i);
        }
    }
}
main(){
    cin >> n >> k;
    for(int i=1; i<(1<<k); i++)
        dp[i]=cost[i]=1e9;
    for(int i=0; i<n; i++){
        int x,temp=0;
        cin >> x;
        for(int j=0; j<k; j++){
            int y;
            cin >> y;
            temp|=(y<<j);
        }
        cost[temp]=min(x,cost[temp]);
        //cout << temp << " " << cost[temp] << "\n";
    }
    solve(0);
    cout << dp[(1<<k)-1];
}
