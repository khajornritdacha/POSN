#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

//https://cses.fi/problemset/task/1188
//Addtional problem

struct DATA{
    int ans, ml, mr, el, er; //ans, longest common substring in the left, longest common substring in the right, left end element, right end element
};

DATA seg[4*N];
int arr[N], n, Q;

DATA merge(const DATA &L, const DATA &R, int lsz, int rsz){
    DATA res;
    res.ans = max(L.ans, R.ans);
    if(L.er == R.el) res.ans = max(res.ans, L.mr+R.ml);
    
    if(L.ml == lsz and L.er == R.el){
        res.ml = L.ml+R.ml;
    } else {
        res.ml = L.ml;
    }
    res.el = L.el;

    if(R.mr == rsz and L.er == R.el){
        res.mr = L.mr+R.mr;
    } else {
        res.mr = R.mr;
    }
    res.er = R.er;

    return res;
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node] = {1, 1, 1, arr[l], arr[l]};
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = merge(seg[node<<1], seg[node<<1|1], mid-l+1, r-mid);
}

void up(int idx, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node] = {1, 1, 1, arr[l], arr[l]};
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, l, mid, node<<1);
    else up(idx, mid+1, r, node<<1|1);
    seg[node] = merge(seg[node<<1], seg[node<<1|1], mid-l+1, r-mid);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    n = str.size();
    for(int i = 1; i <= n; i++){
        arr[i] = str[i-1]-'0';
    }   
    build();
    
    cin >> Q;
    while(Q--){
        int k; cin >> k;
        arr[k] = 1-arr[k];
        up(k);
        cout << seg[1].ans << " ";
    }

    return 0;
}