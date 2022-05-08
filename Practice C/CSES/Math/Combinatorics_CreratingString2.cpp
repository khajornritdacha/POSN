#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e6 + 10;
using ll = long long;


int cnt[30];
ll fa[N], mod = 1e9+7;
char str[N];

//https://cses.fi/problemset/task/1715/

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
    cin >> (str+1);
    int n = strlen(str+1);
    for(int i = 1; i <= n; i++){
        cnt[str[i]-'a']++;
    }

    fa[0] = 1;
    for(int i = 1; i < N; i++) fa[i] = (fa[i-1] * i)%mod;

    ll ans = fa[n];
    for(int i = 0; i < 26; i++){ // (n!) / (cnt[0]!) / (cnt[1]!) / .. / (cnt[25]!)
        ans = (ans * pw(fa[cnt[i]], mod-2))%mod;
    }
    cout << ans << "\n";
    return 0;
}