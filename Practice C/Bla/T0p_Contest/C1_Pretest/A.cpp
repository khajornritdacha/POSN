#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+5;
int dp[N];
char str[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        cin >> str+1;
        if(str[1] == '0')
            break;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n = strlen(str+1);
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1];
            if(i>=2 and str[i]!='0' and ((str[i-1] == '1') or (str[i-1] == '2' and str[i] <= '6')))
               dp[i] += dp[i-2];
            if(str[i] == '0')
                dp[i] = dp[i-2];
            //cout << dp[i] << " ";
        }
        cout << dp[n] << "\n";
    }
}
