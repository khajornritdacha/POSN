#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;

///https://www.spoj.com/problems/FREQUENT/

struct SEG{
    int vl,vr,fl,fr,ans;
};

int n,Q,a[N],inf = 1e9;
SEG seg[4*N];

SEG mer(SEG L, SEG R){
    SEG res;
    if(L.vl == -1e9){
        res = R;
    }else if(R.vr == -1e9){
        res = L;
    }else{
        res.vl = L.vl;
        res.fl = L.fl+(L.vl == R.vl)*R.fl;
        res.vr = R.vr;
        res.fr = R.fr+(L.vr == R.vr)*L.fr;
        res.ans = max({L.ans, R.ans, (L.vr == R.vl)*(L.fr+R.fl)});
    }
    return res;
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node].vl = seg[node].vr = a[l];
        seg[node].fl = seg[node].fr = seg[node].ans = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = mer(seg[node<<1], seg[node<<1|1]);
    //cout << "l, r :" << l << ", " << r << " = " << seg[node].vl << " " << seg[node].vr << " " << seg[node].fl << " " << seg[node].fr << " " << seg[node].ans << "\n";
    return;
}

SEG ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(r < a or l > b) return {-inf, -inf, 0, 0, 0};
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    SEG L = ask(a, b, l, mid, node<<1), R = ask(a, b, mid+1, r, node<<1|1);
    return mer(L, R);
}

void test_case(){
    cin >> n;
    if(n == 0) exit(0);
    cin >> Q;
    //cout << n << " " << Q << "\n";
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build();
    while(Q--){
        int l,r;
        cin >> l >> r;
        cout << ask(l, r).ans << "\n";
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){ test_case(); }
    return 0;
}
