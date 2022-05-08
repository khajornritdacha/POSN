#include<bits/stdc++.h>
using namespace std;
int n,a[105][105],dp[105][105];
int solve(int i, int j){
    if(i==j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    int mn=1e9;
    for(int k=i; k<=j-1; k++){
        int temp=solve(i,k)+solve(k+1,j)+a[i][k]*a[k+1][j];
        if(temp<mn){
            mn=temp;
            a[i][j]=(a[i][k]+a[k+1][j])%100;
        }
    }
    return dp[i][j]=mn;
}
main(){
    while(cin >> n){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]=0;
                a[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){
            cin >> a[i][i];
        }
        cout << solve(0,n-1) << "\n";
    }
}

