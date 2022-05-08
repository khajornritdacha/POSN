#include<bits/stdc++.h>
using namespace std;
string l,r;
int dp[550][550];
main(){
    cin >> l >> r;
    for(int i=1; i<=l.size(); i++)
        dp[i][0]=i;
    for(int j=1; j<=r.size(); j++)
        dp[0][j]=j;
    for(int i=1; i<=l.size(); i++){
        for(int j=1; j<=r.size(); j++){
            if(l[i-1]==r[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
        }
    }
    for(int i=1; i<=l.size(); i++){
        for(int j=1; j<=r.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
