#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 2e9;

//https://cses.fi/problemset/task/2206

int n, Q, seg[2][4*N];

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        int val; cin >> val;
        seg[0][node] = val-l;
        seg[1][node] = val+l;
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    for(int i : {0, 1}) seg[i][node] = min(seg[i][node<<1], seg[i][node<<1|1]);
}

void up(int idx, int val, int l = 1, int r = n, int node = 1){
    if(l == r){ 
        seg[0][node] = val-l;
        seg[1][node] = val+l;
        return;
    }
    
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    for(int i : {0, 1}) seg[i][node] = min(seg[i][node<<1], seg[i][node<<1|1]);
}

int ask(int cd, int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or a > r) return INF;
    if(a <= l and r <= b) return seg[cd][node];
    int mid = (l+r)>>1;
    return min(ask(cd, a, b, l, mid, node<<1), ask(cd, a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();

    while(Q--){
        int code; cin >> code;
        if(code == 1){
            int pos, val; cin >> pos >> val;
            up(pos, val);
        } else {
            int pos; cin >> pos;
            cout << min(ask(0, 1, pos)+pos, ask(1, pos, n)-pos) << "\n";
        }
    }

    return 0;
}
