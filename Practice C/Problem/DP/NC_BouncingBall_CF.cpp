#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> vi(N),dp(N);
int n,P,K,x,y;
char str[N];
///https://codeforces.com/problemset/problem/1415/C
int solve(int i){
    if(i > n)
        return 0;
    if(vi[i])
        return dp[i];
    vi[i] = true;
    return dp[i] = solve(i+K)+(str[i] == '0');
}
void test_case(){
    int ans = 1e9;
    cin >> n >> P >> K;
    vi.assign(n+1, 0),dp.assign(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> str[i];
    }
    cin >> x >> y;
    for(int i=P; i<=n; i++){
        ans = min(ans, (i-P)*y+solve(i)*x);
    }
    cout << ans << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
