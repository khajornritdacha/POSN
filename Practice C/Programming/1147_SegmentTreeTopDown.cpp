#include<bits/stdc++.h>
using namespace std;

const int N = 262200;

int n,Q,seg[4*N];
void up(int idx, int val, int node = 1, int l = 1, int r = n){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid)
        up(idx, val, node*2, l, mid);
    else
        up(idx, val, node*2+1, mid+1, r);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int qq(int st, int ed, int node = 1, int l = 1, int r = n){
    if(l > ed or r < st)
        return -2e9;
    if(st <= l and r <= ed)
        return seg[node];
    int mid = (l+r)/2;
    return max(qq(st, ed, node*2, l, mid), qq(st, ed, node*2+1, mid+1, r));
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    while(Q--){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c == 'U'){
            up(x, y);
        }else{
            cout << qq(x, y) << "\n";
        }
    }
}
