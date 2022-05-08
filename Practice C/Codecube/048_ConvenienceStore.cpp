#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int n,M,mod=1000007,w[510],dp[N];
main(){
    cin >> n >> M;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    sort(w+1, w+n+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=M; j>=w[i]; j--){
            dp[j] = (dp[j-w[i]]+dp[j])%mod;
        }
    }
    cout << dp[M];
}
