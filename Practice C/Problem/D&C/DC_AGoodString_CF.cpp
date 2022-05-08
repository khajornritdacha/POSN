#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int qs[N][30],n;

///https://codeforces.com/problemset/problem/1385/D

int cost(int l, int r, int cur){
    if(cur >= 26) return 1e9;
    return qs[r][cur]-qs[l-1][cur];
}

int solve(int l, int r, int cur){
    if(cur >= 26) return 1e9;
    if(l == r) return cost(l, r, cur);
    int mid = (l+r)>>1;
    return min(cost(l, mid, cur) + solve(mid+1, r, cur+1), solve(l, mid, cur+1) + cost(mid+1, r, cur));
}

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        for(int code = 0; code < 26; code++){
            qs[i][code] = qs[i-1][code]+1;
        }
        qs[i][c-'a']--;
    }

    /*for(int t = 0; t < 5; t++)
        for(int i = 1; i <= n; i++)
            cout << qs[i][t] << " \n"[i==n];*/

    cout << solve(1, n, 0) << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
