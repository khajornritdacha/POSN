#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

struct SEG{
    int mx,L,R,ans;
};

int laz[4*N],n,Q;
SEG seg[4*N];

void pend(int l, int r, int node){
    seg[node].mx += laz[node];
    seg[node].L += laz[node];
    seg[node].R += laz[node];
    if(l != r){
        laz[node<<1] += laz[node];
        laz[node<<1|1] += laz[node];
    }
    laz[node] = 0;
    return;
}

void up(int a, int b, int val, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(r < a or l > b) return;
    if(a <= l and r <= b){
        laz[node] += val;
        pend(l, r, node);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, val, l, mid, node<<1), up(a, b, val, mid+1, r, node<<1|1);
    seg[node].mx = max(seg[node<<1].mx, seg[node<<1|1].mx);
    seg[node].L = seg[node<<1].L;
    seg[node].R = seg[node<<1|1].R;
    seg[node].ans = 0;
    if(seg[node<<1].mx == seg[node].mx)
        seg[node].ans += seg[node<<1].ans;
    if(seg[node<<1|1].mx == seg[node].mx)
        seg[node].ans += seg[node<<1|1].ans;
    if(seg[node<<1].R == seg[node<<1|1].L and seg[node<<1].R == seg[node].mx)
        seg[node].ans--;
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= 4*n; i++)
        seg[i].ans = 1;
    while(Q--){
        int l,r,val; cin >> l >> r >> val;
        up(l, r, val);
        cout << seg[1].mx << " " << seg[1].ans << "\n";
    }
    return 0;
}
