#include<bits/stdc++.h>
using namespace std;
bool dp[2][60010];
int n,a[1010],mx=-2e9;
main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    dp[0][30000]=1;
    for(int i=1; i<=n; i++){
        int cur=i%2;
        int bf=(i-1)%2;
        for(int j=0; j<=60005; j++){
            dp[cur][j]|=dp[bf][j];
            if(a[i]+j<0){
                dp[cur][60001+(a[i]+j)] |= dp[bf][j];
            }else if(a[i]+j>60000){
                dp[cur][(a[i]+j)-60001] |= dp[bf][j];
            }else{
                dp[cur][a[i]+j] |= dp[bf][j];
            }
        }
    }
    for(int i=0; i<=60000; i++){
        if(dp[0][i])
            mx=max(mx,i-30000);
        if(dp[1][i])
            mx=max(mx,i-30000);
    }
    cout << mx << "\n";
}
