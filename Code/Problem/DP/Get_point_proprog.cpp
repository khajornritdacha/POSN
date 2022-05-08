#include<bits/stdc++.h>
using namespace std;

int dp[100][100],n,x,p,t;

int solve(int now, int lv){
    if(dp[lv][now]!=0)
        return dp[lv][now];
    if(lv==1)
        return 1;
    int sum=0;
    for(int i=0; i<=now; i++){
        sum+=solve(i,lv-1);
    }
    return dp[lv][now]=sum;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> p;
        cout << solve(x-(n*p),n) << "\n";
    }
}
