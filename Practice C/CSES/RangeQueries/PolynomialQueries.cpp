#include <bits/stdc++.h>
using namespace std;

//update in range [3, 5] -> arr[3] + 3 - 2, arr[4] + 4 -2, arr[5] + 5 - 2
//update in range [a, b] -> arr[a] + a - (a-1), arr[a+1] + a+1 - (a-1), ..., arr[b] + b - (a-1)
//lazy for plus and mi for minus

const int N = 2e5+10;

int n, Q;
long long seg[4*N], mi[4*N], lazy[4*N];

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ return void(cin >> seg[node]); }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}

void push(int node, int l, int r){
    if(lazy[node] == 0) return;
    // cout << "PUSH : " << l << " " << r << " = " << seg[node] << ", " << 1ll*lazy[node]*(r+l)*(r-l+1)/2 << " " << 1ll*(r-l+1)*mi[node] << "\n";
    seg[node] += 1ll*lazy[node]*(r+l)*(r-l+1)/2 - 1ll*(r-l+1)*mi[node];
    if(l != r){
        lazy[node<<1] += lazy[node];
        mi[node<<1] += mi[node];
        lazy[node<<1|1] += lazy[node];
        mi[node<<1|1] += mi[node];
    }
    lazy[node] = mi[node] = 0;
    return;
}

void up(int a, int b, int l = 1, int r = n, int node = 1){
    push(node, l, r);
    if(a > b or b < l or a > r) return;
    if(a <= l and r <= b){
        lazy[node]++;
        mi[node] += a-1;
        push(node, l, r);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, l, mid, node<<1), up(a, b, mid+1, r, node<<1|1);
    seg[node] = seg[node<<1] + seg[node<<1|1];

    // cout << "UP : " << l << " " << r << " = " << seg[node<<1] << " " << seg[node<<1|1] << "\n";
}

long long ask(int a, int b, int l = 1, int r = n, int node = 1){
    push(node, l, r);
    if(a > b or b < l or a > r) return 0;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return ask(a, b, l, mid, node<<1) + ask(a, b, mid+1, r, node<<1|1);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();

    while(Q--){
        int cd, a, b; cin >> cd >> a >> b;
        if(cd == 1){
            up(a, b);
        } else if(cd == 2){
            cout << ask(a, b) << "\n";
        }
    }

    return 0;
}