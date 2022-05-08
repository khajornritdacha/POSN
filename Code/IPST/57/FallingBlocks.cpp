#include <bits/stdc++.h>
using namespace std;

//cu := the number of pair (i-1, i) such that a[i-1] < a[i]
//dd := the number of pair (i-1, i) such that a[i-1] > a[i]

const int N = 1e5+10;

struct node{
    int cu = 0, dd = 0, lv = 0, rv = 0, lazy = 0;
};

node seg[4*N], INIT;
int n, Q;

inline void push(int cur, int l, int r){
    seg[cur].lv += seg[cur].lazy;
    seg[cur].rv += seg[cur].lazy;
    if(l != r){
        seg[cur<<1].lazy += seg[cur].lazy;
        seg[cur<<1|1].lazy += seg[cur].lazy;
    }
    seg[cur].lazy = 0;
    return;
}

inline node merge(const node L, const node R){
    if(L.lv == -1 or L.rv == -1) return R;
    if(R.lv == -1 or R.rv == -1) return L;
    node res;
    res.cu = L.cu + R.cu; //the number of climb up
    res.dd = L.dd + R.dd; //the number of climb down
    res.lv = L.lv; //leftmost value
    res.rv = R.rv; //rightmost value
    if(L.rv < R.lv) res.cu++;
    else if(L.rv > R.lv) res.dd++;

    return res;
}

void up(int a, int b, int l = 1, int r = n, int cur = 1){
    push(cur, l, r);
    if(a > b or b < l or a > r) return;
    if(a <= l and r <= b){
        seg[cur].lazy++;
        push(cur, l, r);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, l, mid, cur<<1), up(a, b, mid+1, r, cur<<1|1);

    seg[cur] = merge(seg[cur<<1], seg[cur<<1|1]);
    // cout << "UP : " << l << " " << r << " = " << seg[cur].cu << " " << seg[cur].dd << "\n";
}

node ask(int a, int b, int l = 1, int r = n, int cur = 1){
    push(cur, l, r);
    if(a > b or b < l or a > r) return INIT;
    if(a <= l and r <= b) return seg[cur];
    int mid = (l+r)>>1;
    return merge(ask(a, b, l, mid, cur<<1), ask(a, b, mid+1, r, cur<<1|1));
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    INIT.lv = INIT.rv = -1;
    cin >> n >> Q;
    while(Q--){
        int cd; cin >> cd;
        int a, b; cin >> a >> b;
        if(cd == 1){
            up(a, b);
        } else if(cd == 2){
            node res = ask(a, b);
            cout << res.lv << " " << res.rv << "\n";
        } else if(cd == 3){
            node res = ask(a, b);
            cout << res.lv << " " << res.rv << " " << res.cu << " " << res.dd << "\n";
        }
    }

    return 0;
}

