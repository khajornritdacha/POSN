#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
using ll = long long;
using pi = pair<ll, ll>;

int n,a[N];
bool vi[N][N];
pi dp[N][N];

bool fi(int l, int r){
    return ((r-l+1)&1) == (n&1);
}

pi solve(int l, int r){
    if(vi[l][r]) return dp[l][r];
    vi[l][r] = true;

    if(l == r){ ///base case
        if(fi(l, r)) return dp[l][r] = pi(a[l], 0);
        return dp[l][r] = pi(0, a[l]);
    }

    pi res, t1 = solve(l+1, r), t2 = solve(l, r-1);

    if(fi(l, r)){
        t1.first += a[l]; t2.first += a[r];
        if(t1.first > t2.first) res = t1;
        else res = t2;
    }else{
        t1.second += a[l]; t2.second += a[r];
        if(t1.second > t2.second) res = t1;
        else res = t2;
    }

    return dp[l][r] = res;
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << solve(1, n).first << "\n";
    return 0;
}
