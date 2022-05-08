#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,dp[2][5010];
main(){
    cin >> n;
    cin >> s1;
    s2=s1;
    reverse(s2.begin(),s2.end());
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            }else{
                dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        }
    }
    cout << n-dp[n%2][n];
}
