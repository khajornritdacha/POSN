//https://codeforces.com/problemset/problem/1195/D1

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10, mod = 998'244'353;

inline void add(long long &a, long long b){
    a += b;
    if(a >= mod) a-= mod;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        long long pw = 1;
        while(x){
            int cur = x%10;
            add(ans, (n)*((cur*pw + cur*pw*10)%mod)%mod);
            pw = pw*100%mod;
            x /= 10;
        }
    }
    cout << ans << "\n";

    return 0;
}