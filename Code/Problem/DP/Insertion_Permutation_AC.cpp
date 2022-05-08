#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3010;

///https://atcoder.jp/contests/dp/tasks/dp_t

int n;
char str[N];
ll dp[N][N],qs[N],mod=1e9+7;

void test_case(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> str[i];
    }
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            qs[j] = (qs[j-1]+dp[i-1][j])%mod;
        }
        for(int j = 1; j <= i; j++){
            if(str[i] == '<'){
                dp[i][j] = (qs[i]-qs[j-1]+mod)%mod;
            }else{
                dp[i][j] = qs[j-1];
            }
        }
    }
    ll ans = 0;
    for(int j = 1; j <= n; j++) ans = (ans+dp[n][j])%mod;
    cout << ans << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
