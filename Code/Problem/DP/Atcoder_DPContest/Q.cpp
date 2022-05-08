#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;

int n,h[N],a[N];
ll seg[4*N],dp[N];

void up(int idx, ll val, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    seg[node] = max(seg[node<<1], seg[node<<1|1]);
    return;
}

ll ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(l > r) return 0;
    if(r < a or l > b) return 0;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return max(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = ask(1, h[i]-1)+a[i];
        up(h[i], dp[i]);
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
    return 0;
}
