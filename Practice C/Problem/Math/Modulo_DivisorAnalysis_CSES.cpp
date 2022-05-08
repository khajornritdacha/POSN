#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;
 
int n;
ll x[N],k[N], mod = 1e9+7;

//https://cses.fi/problemset/task/2182/
//https://usaco.guide/problems/cses-2182-divisor-analysis/solution

ll pw(ll b, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res * b)%mod;
        b = (b*b)%mod;
        p /= 2;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ll A1 = 1, A2 = 1;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> k[i];
        A1 = (A1 * (k[i]+1))%mod;
    }

    for(int i = 1; i <= n; i++){
        ll tmp = (x[i]*(pw(x[i], k[i])-1)%mod+mod)%mod;
        tmp = (tmp * pw(x[i]-1, mod-2))%mod;
        A2 = (A2+tmp*A2)%mod;
    }

    ll di = 1, A3 = 1;
    for(int i = 1; i <= n; i++){
        ll tmp = pw(A3, k[i]+1);
        ll pp = (k[i] * (k[i]+1) / 2 % (mod-1) * di)%(mod-1);
        A3 = (tmp * pw(x[i], pp))%mod;
        di = (di*(k[i]+1))%(mod-1);
    }

    cout << A1 << " " << A2 << " " << A3 << "\n";    

    return 0;
}