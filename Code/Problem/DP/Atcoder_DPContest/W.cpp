#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int n,m;
vector<pair<int,int>> ep[N];
ll seg[4*N],lazy[4*N],dp[N];

void pend(int l ,int r, int node){
    seg[node] += lazy[node];
    if(l != r){
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
    }
    lazy[node] = 0;
    return;
}

void up(int a, int b, ll val, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(r < a or l > b) return;
    if(a <= l and r <= b){
        lazy[node] += val;
        pend(l, r, node);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, val, l, mid, node<<1);
    up(a, b, val, mid+1, r, node<<1|1);
    seg[node] = max(seg[node<<1], seg[node<<1|1]);
    return;
}

ll ask(int a, int b, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(r < a or l > b) return -1e18;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return max(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int l,r,val; cin >> l >> r >> val;
        l++, r++;
        ep[l].emplace_back(val, l);
        ep[r+1].emplace_back(-val, l);
    }
    ll mx = 0;
    for(int i = 2; i <= n+1; i++){
        for(auto [val, st] : ep[i]){
            up(1, st-1, val);
        }
        dp[i] = ask(1, i-1);
        mx = max(mx, dp[i]);
        up(i, i, dp[i]);
    }
    cout << mx << "\n";
    return 0;
}
