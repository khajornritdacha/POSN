#include <bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1143/
//binary search for finding the first element that is greater than r[i]
//O(log^2 N) per query

const int N = 2e5+10, INF = 1e9+10;

int seg[4*N], n, Q;

void build(int l = 1, int r = n, int node = 1){
    if(l == r) return void(cin >> seg[node]);
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = max(seg[node<<1], seg[node<<1|1]);
}

void up(int idx, int val, int l = 1, int r = n, int node = 1){
    if(l == r) return void(seg[node] += val);
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    seg[node] = max(seg[node<<1], seg[node<<1|1]);
}

int ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or a > r) return -INF;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return max(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int lb(int val){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(ask(1, mid) >= val){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();
    
    while(Q--){
        int val; cin >> val;
        int k = lb(val);
        if(k == -1) cout << "0 ";
        else {
            cout << k << " ";
            up(k, -val);
        }
    }

    return 0;
}