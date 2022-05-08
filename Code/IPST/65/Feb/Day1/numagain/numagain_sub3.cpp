#include "numagain.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 1e9+7;
long long pas[N][N], mx[N], mn[N], arr[N];

inline int add(int a, int b){
    a += b;
    if(a >= mod) a-= mod;
    return a;
}

long long choose(int n, int r){
    if(r > n) return 0;
    return pas[n][r];
}

int find_ans(std::vector<int>number)
{
    sort(number.begin(), number.end());
    int n = number.size(), res[n+5] = {};
    for(int i = 0; i <= n; i++){
        pas[i][0] = 1;
        for(int r = 1; r <= i; r++){
            pas[i][r] = add(pas[i-1][r-1], pas[i-1][r]);
        }
    }

    for(int i = 1; i <= n; i++){
        arr[i] = number[i-1];
        // cout << arr[i] << " ";
    }
    // cout << "\n";

    for(int i = 1; i <= n; i++){
        for(int sz = 2; sz <= n; sz++){
            mn[sz] = add(mn[sz], arr[i]*choose(n-i, sz-1)%mod);
            mx[sz] = add(mx[sz], arr[i]*choose(i-1, sz-1)%mod);
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i++){
        res[i] = 1ll*(mx[i]-mn[i]+mod)*i%mod;
        ans = add(ans, res[i]);
    }

    return ans;
}
