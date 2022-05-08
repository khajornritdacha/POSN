#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

///https://atcoder.jp/contests/abc223/tasks/abc223_f

struct SEG{
    int LO,LC;
    bool ok;
};

int n,Q,in[N];
SEG seg[4*N];

SEG Merge(SEG L, SEG R){
    SEG res;
    int mer = min(L.LO, R.LC);
    res.LO = L.LO-mer+R.LO;
    res.LC = L.LC+R.LC-mer;
    res.ok = (L.LC == 0 and R.LO == 0 and L.LO == R.LC);
    return res;
}

void up(int idx, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node].ok = false;
        if(in[idx] == 0){
            seg[node].LO = 1;
            seg[node].LC = 0;
        }else{
            seg[node].LO = 0;
            seg[node].LC = 1;
        }
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, l, mid, node<<1);
    else up(idx, mid+1, r, node<<1|1);
    seg[node] = Merge(seg[node<<1], seg[node<<1|1]);
    return;
}

SEG ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(r < a or l > b){
        SEG tmp;
        tmp.LC = tmp.LO = 0;
        tmp.ok = false;
        return tmp;
    }
    if(a <= l and r <= b){
        return seg[node];
    }
    int mid = (l+r)>>1;
    return Merge(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        in[i] = (c == ')');
        //cout << in[i];
        up(i);
    }
    while(Q--){
        int code,l,r; cin >> code >> l >> r;
        if(code == 1){
            swap(in[l], in[r]);
            up(l); up(r);
        }else{
            cout << (ask(l, r).ok ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
