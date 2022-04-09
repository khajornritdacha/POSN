// Min SegmentTree for finding the minimum elements in range [a, b]
// task: https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

int n,Q,seg[4*N];

/**
 * Call once before using to build SegmentTree
 */
void build(int l = 1, int r = n, int node = 1){
    if(l == r) return void( cin >> seg[node] );
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = min(seg[node<<1], seg[node<<1|1]);
    return;
}

/**
 * Replace node at index = idx with value = val
 */
void up(int idx, int val, int l = 1, int r = n, int node = 1){
    if(l == r) return void( seg[node] = val);
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    seg[node] = min(seg[node<<1], seg[node<<1|1]);
    return;
}

/**
 * Return the minimum value in range [a, b]
 */
int ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or r < a) return INF;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return min(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();

    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) up(a, b);
        else cout << ask(a, b) << "\n";
    }
    return 0;
}