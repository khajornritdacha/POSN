#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 25;
using ll = long long;
using pi = pair<ll, ll>;

int n,m;
char in0[N],in1[N];
bool vi[N][N][2][2][2];
ll dp[N][N][2][2][2];

ll solve(int i, int j, bool b1, bool b2, bool z){
    //cout << i << " " << j << " " << b1 << " " << b2 << " " << z << "\n";
    if(vi[i][j][b1][b2][z]) return dp[i][j][b1][b2][z];
    vi[i][j][b1][b2][z] = true;
    if(i == n+1) return dp[i][j][b1][b2][z] = 1;

    ll res = 0;
    int r = (b1 ? 9 : in1[i]-'0'), l = (b2 ? 0 : in0[i]-'0');
    //cout << l << " " << r << "\n";
    for(int k = l; k <= r; k++){
        if(j == k and ((j != 0) or (j == 0 and z))) continue;
        res += solve(i+1, k, b1 | (k < r), b2 | (k > l), z | (k != 0));
    }
    return dp[i][j][b1][b2][z] = res;
}

main(void){
    cin >> (in0+1) >> (in1+1);
    n = strlen(in1+1), m = strlen(in0+1);

    if(m < n){
        int i = n;
        for(int j = m; j >= 1; j--, i--){
            in0[i] = in0[j];
            in0[j] = '0';
        }
        for(; i >= 1; i--)
            in0[i] = '0';
    }

    ll ans = 0;
    for(int l = in0[1]-'0', r = in1[1]-'0'; l <= r; l++){
        //cout << l << "\n";
        ans += solve(2, l, l < (in1[1]-'0'), l > (in0[1]-'0'), l != 0);
    }

    cout << ans << "\n";

    return 0;
}
