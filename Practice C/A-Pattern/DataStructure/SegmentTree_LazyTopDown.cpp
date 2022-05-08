#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int seg[4*N],lazy[4*N],n,Q;
///up sum of range
///query max of range

void up(int wl, int wr, int val = 1, int l = 1, int r = n, int node = 1){
    if(lazy[node]){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(wl > wr or r < wl or l > wr)
        return;

    if(wl <= l and r <= wr){
        seg[node] += val;
        if(l != r){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    int mid = (l+r)/2;
    up(wl, wr, val, l, mid, node*2);
    up(wl, wr, val, mid+1, r, node*2+1);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int qq(int wl, int wr, int l = 1, int r = n, int node = 1){
    if(lazy[node]){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(wl > wr or r < wl or l > wr)
        return -2e9;

    if(wl <= l and r <= wr)
        return seg[node];

    int mid = (l+r)/2;
    return max(qq(wl, wr, l, mid, node*2), qq(wl, wr, mid+1, r, node*2+1));
}

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    while(Q--){
        char c;
        int x,y,val;
        cin >> c;
        if(c == 'U'){
            cin >> x >> y >> val;
            up(x, y, val);
        }else{
            cin >> x >> y;
            cout << qq(x, y) << "\n";
        }
    }
}

/*
6 6
U 1 4 10
U 2 5 5
Q 1 5
Q 2 3
U 4 5 2
Q 1 5
*/
