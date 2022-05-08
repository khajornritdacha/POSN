#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+10, LOG = 25;
int a[N],n,Q;
ll ta[N][LOG];

///https://cses.fi/problemset/task/1646/

ll ask(int l, int r){
    ll res = 0;
    for(int i = 25; i >= 0; i--){
        if((1<<i) <= r-l+1){
            res += ta[l][i];
            l += (1<<i);
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ta[i][0] = a[i];
    }

    for(int k = 1; k <= LOG; k++){
        for(int i = 1; i+(1<<k)-1 <= n; i++){
            ta[i][k] = ta[i][k-1]+ta[i+(1<<(k-1))][k-1];
        }
    }

    while(Q--){
        int l, r; cin >> l >> r;
        cout << ask(l, r) << "\n";
    }

    return 0;
}
