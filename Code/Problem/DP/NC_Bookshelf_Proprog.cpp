#include<bits/stdc++.h>
using namespace std;
int n,l,h[2010],w[2010],dp[2010];
main(){
    cin >> n >> l;
    for(int i=1; i<=n; i++){
        cin >> h[i] >> w[i];
        dp[i]=2e9;
    }
    for(int i=1; i<=n; i++){
        int wei=0,last=i,mx=0;
        for(int j=i; j>=1; j--){
            if(wei+w[j]>l){
                break;
            }
            wei+=w[j];
            mx=max(mx,h[j]);
            dp[i]=min(dp[i],dp[j-1]+mx);
            last=j;
        }
        //cout << last << "\n";
        dp[i]=min(dp[i-1]+h[i],dp[i]);
    }
    for(int i=1; i<=n; i++)
        cout << dp[i] << " ";
    cout << dp[n];
}
