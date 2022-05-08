//https://cses.fi/problemset/task/1080/
//Sol in USACO Gold Range DP

#include <bits/stdc++.h>
using namespace std;

const int N = 510, mod = 1e9+7;

char str[N];
long long fac[2*N], inv[2*N];
long long dp[N][N];

inline long long cal(int n, int r){
    return fac[n]*inv[r]%mod*inv[n-r]%mod;
}

long long pw(long long base, long long p){
    long long res = 1;
    while(p){
        if(p&1){
            res = (res*base)%mod;
        }
        base = (base*base)%mod;
        p /= 2;
    }
    return res;
}

inline long long getdp(int l, int r){
    if(l > r) return 1;
    if((r-l+1)&1) return 0;
    return dp[l][r];
}

int main(void){
    cin >> (str+1);
    int n = strlen(str+1);

    fac[0] = inv[0] = 1;
    for(int i = 1; i < 2*N; i++){
        fac[i] = 1ll*fac[i-1]*i%mod;
        inv[i] = pw(fac[i], mod-2);
    }

    // for(int i = 0; i < 5; i++) cout << fac[i] << " " << inv[i] << "\n";

    for(int sz = 1; sz <= n; sz++){
        for(int l = 1; l <= n-sz+1; l++){
            int r = l+sz-1;
            if((r-l+1)&1) continue; //size of range is odd

            // if(str[l] == str[r]) dp[l][r] = getdp(l+1, r-1);
            for(int k = l+1; k <= r; k++){
                if(str[l] != str[k]) continue;
                long long tmp = getdp(l+1, k-1)*getdp(k+1, r)%mod *cal((r-l+1)/2, (k-l+1)/2)%mod;
                dp[l][r] = (dp[l][r]+tmp)%mod;

                // cout << l << " " << k << " " << k+1 << " " << r << " = " << getdp(l, k) << " " << getdp(k+1, r) << " " << cal((r-l+1)/2, (k-l+1)/2) << "\n";
            }
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}