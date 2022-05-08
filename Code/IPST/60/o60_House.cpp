#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+10;

struct SEG{
    ll ans, bl, br, sum;
};

SEG seg[4*N];
int a[N],n,Q,inf = 1e9;

///https://beta.programming.in.th/tasks/o60_oct_c1_house

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        int mx = max(0, a[l]);
        seg[node] = {mx, mx, mx, a[l]};
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    ll ans = max({seg[node<<1].ans, seg[node<<1|1].ans, seg[node<<1].br+seg[node<<1|1].bl});
    ll bl = max(seg[node<<1].bl, seg[node<<1].sum+seg[node<<1|1].bl);
    ll br = max(seg[node<<1|1].br, seg[node<<1].br+seg[node<<1|1].sum);
    ll sum = seg[node<<1].sum+seg[node<<1|1].sum;
    return void(seg[node] = {ans, bl, br, sum});
}

SEG ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(l > b or r < a) return {-inf, -inf, -inf, 0};
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    SEG L = ask(a, b, l, mid, node<<1), R = ask(a, b, mid+1, r, node<<1|1);
    ll ans = max({L.ans, R.ans, L.br+R.bl});
    ll bl = max(L.bl, L.sum+R.bl);
    ll br = max(R.br, L.br+R.sum);
    ll sum = L.sum+R.sum;
    return {ans, bl, br, sum};
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build();

    while(Q--){
        int l, r; cin >> l >> r;
        cout << ask(l+1, r+1).ans << "\n";
    }
    return 0;
}
