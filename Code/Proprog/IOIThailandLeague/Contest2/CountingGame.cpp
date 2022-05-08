#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,dp[N];
int solve(int i){
    //cout << "NOW : " << i << "\n";
    if(i == 1)
        return 0;
    if(dp[i] != 1e9)
        return dp[i];
    int tmp = i;
    bool use[10] = {};
    while(tmp > 0){
        use[tmp%10] = 1;
        //cout << "DIGIT : " << tmp%10 << "\n";
        tmp/=10;
    }
    int chua = 1e9;
    for(int j=2; j<=5; j++){
        if(!use[j] and i%j != 0 and i-j >= 1){
            chua = min(chua, solve(i-j)+1);
        }
    }
    return dp[i] = chua;
}
main(){
    cin >> n;
    for(int i=0; i<=n; i++)
        dp[i] = 1e9;
    int ans = solve(n);
    if(ans == 1e9)
        ans = -1;
    cout << ans;
}
