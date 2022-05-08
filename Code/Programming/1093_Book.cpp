#include<bits/stdc++.h>
using namespace std;
int n,a[2010],dp[2010],temp[2010];
int bk(int i){
    if(i>n)
        return 0;
    if(dp[i]!=0)
        return dp[i];
   return dp[i] = max(temp[i]+bk(i+3),bk(i+1));
   //cout << temp << " ";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=3;i<=n;i++){
        temp[i] = a[i-2]+a[i-1]-a[i];
        //cout << temp[i] << " ";
    }
    bk(3);
    cout << dp[3];
}
