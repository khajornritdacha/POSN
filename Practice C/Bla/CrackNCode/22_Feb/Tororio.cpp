#include <bits/stdc++.h>
using namespace std;

struct DATA{
    long long num, deno;
    DATA(int a = 0, int b = 0){
        num = a, deno = b;
    }
    DATA operator+ (const DATA &o){
        DATA res;
        res.num = num + o.num;
        res.deno = deno + o.deno;
        return res;
    }
};

const int N = 1e5+10;

int n, Q;
DATA seg[4*N], lazy[4*N];

inline void push(int node, int l, int r){
    seg[node].num += lazy[node].num*(r-l+1);
    seg[node].deno += lazy[node].deno*(r-l+1);
    if(l != r){
        lazy[node<<1] = lazy[node<<1] + lazy[node];
        lazy[node<<1|1] = lazy[node<<1|1] + lazy[node];
    }
    lazy[node] = DATA(0, 0);
    return;
}

void up(int a, int b, int t, int v, int l = 1, int r = n, int node = 1){
    push(node, l, r);
    if(a > b or b < l or a > r) return;
    if(a <= l and r <= b){
        lazy[node].num += 1ll*t*v;
        lazy[node].deno += v;
        push(node, l, r);
        return;
    }

    int mid = (l+r)>>1;
    up(a, b, t, v, l, mid, node<<1), up(a, b, t, v, mid+1, r, node<<1|1);
    seg[node] = seg[node<<1]+seg[node<<1|1];
    return;
}

DATA ask(int a, int b, int l = 1, int r = n, int node = 1){
    push(node, l, r);
    if(a > b or b < l or a > r) return DATA(0, 0);
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return ask(a, b, l, mid, node<<1)+ask(a, b, mid+1, r, node<<1|1);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    while(Q--){
        int op, l, r; cin >> op >> l >> r;
        if(op == 1){
            int t, v; cin >> t >> v;
            up(l, r, t, v);
        } else {
            DATA res = ask(l, r);
            if(res.deno == 0) cout << "0\n";
            else cout << res.num/res.deno << "\n";
        }
    }

    return 0;
}