#include<bits/stdc++.h>
#define DEBUG true
using namespace std;

const int N = 2010;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int dp[N][2][N],M,D,re[15][N],mod=1e9+7;
string a,b;
///https://codeforces.com/contest/628/problem/D

int solve(int po, int idx=0, int les=0, int mor=0, bool mag=0, int rem=0){
    //printf("NOW : %d %d %d %d %d\n", idx, les, mor, mag, rem);
    if(idx == b.size()){
        return (mag == 0 and rem == 0);
    }
    if(les != 0 and mor != 0 and dp[idx][mag][rem] != -1) return dp[idx][mag][rem];

    long long res = 0, li = (les ? 9 : b[idx]-'0'), lo = (mor ? 0 : a[idx]-'0');
    for(int j=lo; j<=li; j++){
        //printf("J = %d\n", j);
        //printf("CALL : %d %d %d %d %d\n", idx+1, les|(j != li), mor|(j != lo), mag|((b.size()-idx)%2 == 0 and j!=D or (b.size()-idx)%2 == 1 and j==D), (rem+re[j][idx])%M);
        res += solve(po-1, idx+1, les|(j != li), mor|(j != lo), mag|((idx&1) == 1 and j!=D or (idx&1) == 0 and j==D), (rem+re[j][po])%M);
    }
    if(les != 0 and mor != 0)
        dp[idx][mag][rem] = res%mod;
    return res%mod;
}

void test_case(){
    cin >> M >> D >> a >> b;

    for(int p=0; p<=b.size(); p++){
        //cout << "P = " << p << " : ";
        for(int i=0; i<=9; i++){
            if(p != 0)
                re[i][p] = (re[i][p-1]*10)%M;
            else
                re[i][p] = i%M;
            //cout << re[i][p] << " ";
        }
        //cout << "\n";
    }

    memset(dp, -1, sizeof(dp));
    int resb = solve(b.size()-1);

    cout << resb << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
