#include<bits/stdc++.h>
using namespace std;
int n,k,dp[100010],qs[100010];
main(){
    cin >> n >> k;
    dp[0]=qs[0]=1;
    for(int i=1; i<=n; i++){
        if(i>k){
            dp[i]+=qs[i-1]-qs[i-k-1];
        }else{
            dp[i]+=qs[i-1];
        }
        dp[i]%=2009;
        if(dp[i]<0) dp[i]+=2009;
        qs[i]=dp[i]+qs[i-1];
        qs[i]%=2009;
    }
    cout << dp[n]%2009;
}
