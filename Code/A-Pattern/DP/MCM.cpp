#include<bits/stdc++.h>
using namespace std;
int n,a[105],dp[105][105];
int solve(int i, int j){
    if(i==j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    int mn=1e9;
    for(int k=i; k<=j-1; k++){
        mn=min(mn,solve(i,k)+solve(k+1,j)+a[i-1]*a[k]*a[j]);
    }
    return dp[i][j]=mn;
}

main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << solve(1,n-1);
}

/*
5
10 20 30 40 30
*/
//n=5 -> 4 matrix

