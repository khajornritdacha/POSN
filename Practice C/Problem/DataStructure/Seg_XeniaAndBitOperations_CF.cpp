#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

int seg[4*N],n,m,lv[4*N];

//https://codeforces.com/problemset/problem/339/D

void up(int idx, int val, int l = 1, int r = (1<<n), int node = 1){
    if(l == r){
        seg[node] = val; //leaf -> lv = 0
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);

    lv[node] = lv[node<<1] + 1;
    if(lv[node]&1) seg[node] = seg[node<<1] | seg[node<<1|1];
    else seg[node] = seg[node<<1] ^ seg[node<<1|1];
    
    return;
}
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= 1<<n; i++){
        int x; cin >> x;
        up(i, x);
    }

    for(int i = 1; i <= m; i++){
        int idx, val; cin >> idx >> val;
        up(idx, val);
        cout << seg[1] << "\n";
    }

    return 0;
}