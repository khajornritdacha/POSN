#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

struct DATA{
    int ans, mxl, mxr, sum;
};

DATA seg[4*N];
int n,m,a[N];

DATA merge(DATA &L, DATA &R){
    DATA res;
    res.ans = max({L.ans, R.ans, L.mxr + R.mxl});
    res.mxl = max(L.mxl, L.sum + R.mxl);
    res.mxr = max(R.mxr, L.mxr + R.sum);
    res.sum = L.sum + R.sum;
    return res;
}

void up(int idx, int val, int l = 1, int r = n, int node = 1){
    if(l == r){
        a[l] = val;
        seg[node] = {a[l], a[l], a[l], a[l]};
        return;
    }

    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    
    seg[node] = merge(seg[node<<1], seg[node<<1|1]);
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        up(i, a[i]);
    }    

    cout << seg[1].ans << "\n";
    
    while(m--){
        int pos, val; cin >> pos >> val;
        pos++;
        up(pos, val);
        cout << seg[1].ans << "\n";
    }

    return 0;
}