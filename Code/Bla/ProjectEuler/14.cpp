#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+10;

int dp[N],mx,lim=5e6,res[N];

int dfs(long long u){
    //mx = max(mx, u);
    assert(u >= 0);
    if(u <= lim and dp[u]) return dp[u];
    int tmp = 1+((u == 1) ? 0 : (u&1) ? dfs(3*u+1) : dfs(u/2));
    if(u <= lim)
        dp[u] = tmp;
    return tmp;
}


int main(void){
    //cout << dfs(5e6) << "\n";
    for(int i = 1; i <= lim; i++){
        dfs(i);
    }
    for(int i = 1; i <= lim; i++){
        if(dp[i-1] > dp[i]){
            dp[i] = dp[i-1];
            res[i] = res[i-1];
        }else{
            res[i] = i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << res[x] << "\n";
    }
    return 0;
}
