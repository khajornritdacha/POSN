#include<bits/stdc++.h>
using namespace std;
int t,dp[1010][1010],k;
///longest parlindome subsquence = LCS(str,reverse(str))
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    k=t;
    t++;
    while(t--){
        string a,b;
        getline(cin,a);
        if(t==k) continue;
        b=a;
        reverse(b.begin(),b.end());
        //cout << a << " " << b << " " << '\n';
        for(int i=1; i<=a.size(); i++){
            for(int j=1; j<=b.size(); j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[a.size()][b.size()] << "\n";
        for(int i=0; i<=a.size(); i++) for(int j=0; j<=b.size(); j++) dp[i][j]=0;
    }
}
