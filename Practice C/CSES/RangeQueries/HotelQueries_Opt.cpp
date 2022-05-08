#include <bits/stdc++.h>
using namespace std;

//O(log N) per query

//seg tree stores maximum for each range
//Go to the left child if its maximum is greater or equal to r[i]
//if not go to right child if it satisfy the condition
//else return 0

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

int ask(int val, int l = 1, int r = n, int node = 1){
    if(l == r) return (seg[node] >= val ? l : 0);
    int mid = (l+r)>>1;
    if(seg[node<<1] >= val) return ask(val, l, mid, node<<1);
    else if(seg[node<<1|1] >= val) return ask(val, mid+1, r, node<<1|1);
    else return 0;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();
    
    while(Q--){
        int val; cin >> val;
        int k = ask(val);
        cout << k << " ";
        if(k != 0) up(k, -val);
    }

    return 0;
}