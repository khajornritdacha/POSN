#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://www.spoj.com/problems/PIGBANK/

void test_case(){
    int E,F,n;
    cin >> E >> F;
    int want = F-E;
    cin >> n;
    vector<ll> dp(want+5, 1e18),V(n+5),W(n+5);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> V[i] >> W[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = W[i]; j <= want; j++){
            dp[j] = min(dp[j], dp[j-W[i]]+V[i]);
        }
    }
    if(dp[want] == 1e18){
        cout << "This is impossible.\n";
    }else{
        cout << "The minimum amount of money in the piggy-bank is " << dp[want] << ".\n";
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
