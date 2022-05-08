#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
using lb = long double;
using ll = long long;

int n,D;
string str;
ll dp[N][110][2],mod=1e9+7;
bool vi[N][110][2];

ll solve(int idx, int re, bool b){
    if(idx == str.size()) return (re == 0);
    if(vi[idx][re][b]) return dp[idx][re][b];
    vi[idx][re][b] = true;
    int lim = (b ? 9 : str[idx]-'0');
    for(int j = 0; j <= lim; j++){
        dp[idx][re][b] += solve(idx+1, (re+j)%D, b|(j != lim));
        dp[idx][re][b] %= mod;
    }
    return dp[idx][re][b];
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str >> D;
    cout << (solve(0, 0, 0)-1+mod)%mod << "\n";
    return 0;
}
