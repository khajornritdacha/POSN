#include <bits/stdc++.h>
using namespace std;

//seg[node] := the number of left elements in range [l, r]

const int N = 2e5+10;

int seg[4*N], n, Q, arr[N];

void build(int l = 1, int r = n, int node = 1){
    if(l == r) return void(seg[node] = 1); 
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}

int ask(int key, int l = 1, int r = n, int node = 1){
    if(l == r){
        // assert(seg[node] == 1);
        seg[node] = 0;
        return l;
    }
    int mid = (l+r)>>1, res = -1;
    if(key <= seg[node<<1]){
        res = ask(key, l, mid, node<<1);
    } else {
        res = ask(key-seg[node<<1], mid+1, r, node<<1|1);
    }
    seg[node] = seg[node<<1] + seg[node<<1|1];
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build();

    for(int i = 1; i <= n; i++){
        int key; cin >> key;
        int k = ask(key);
        cout << arr[k] << " ";
    }
    return 0;
}