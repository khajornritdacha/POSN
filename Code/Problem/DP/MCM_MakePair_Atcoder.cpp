#include <iostream>
#define DEBUG false
using namespace std;

const int N = 410;
using ll = long long;
using pi = pair<int,int>;

ll mod = 998244353,n,m,dp[N][N],ch[N][N];
bool vi[N][N],fr[N][N];
///https://atcoder.jp/contests/abc217/tasks/abc217_f

ll solve(int l, int r){
    if(l >= r) return 1;
    if(l+1 == r) return fr[l][r];
    if(vi[l][r]) return dp[l][r];
    vi[l][r] = true;
    for(int k=l+1; k<=r; k+=2){
        if(fr[l][k]){
            dp[l][r] += (((solve(l+1, k-1)*solve(k+1, r))%mod)*ch[(r-l+1)/2][(k-l+1)/2])%mod;
            //cout << "NOW : " << l << " " << k << " " << r << "\n";
            //cout << (r-l+1)/2 << " " << (k-l+1)/2 << " " << ch[(r-l+1)/2][(k-l+1)/2] << "\n";
        }
        dp[l][r] %= mod;
    }
    //cout << l << " " << r << "\n";
    return dp[l][r];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        ch[i][0] = 1;
        for(int j=1; j<=i; j++){
            ch[i][j] = (ch[i-1][j-1]+ch[i-1][j])%mod;
        }
    }
    for(int i=1; i<=m; i++){
        int a,b; cin >> a >> b;
        fr[a][b] = true;
    }
    cout << solve(1, 2*n);
    return 0;
}
