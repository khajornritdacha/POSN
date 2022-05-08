#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int a[N],seg[4*N],n,m;
int qq(int st, int ed, int node = 1, int l = 1, int r = n){
    if(ed < l or st > r)
        return 0;
    if(st <= l and r <= ed)
        return seg[node];
    int mid = (l+r)/2;
    return qq(st, ed, node*2, l, mid)+qq(st, ed, node*2+1, mid+1, r);
}
void up(int pos, int val, int node = 1, int l = 1, int r = n){
    cout << node << " " << l << " " << r << "\n";
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid)
        up(pos, val, node*2, l, mid);
    else
        up(pos, val, node*2+1, mid+1, r);
    seg[node] = seg[node*2]+seg[node*2+1];
}
void build(int node = 1, int l=1, int r=n){
    if(l == r){
        seg[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    seg[node] = seg[node*2]+seg[node*2+1];
}
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    build();
    for(int i=1; i<=m; i++){
        char code;
        int x,y;
        cin >> code >> x >> y;
        if(code == 'C'){
            cout << "Showtime : \n";
            up(x,y);
        }else{
            cout << qq(x,y) << "\n";
        }
    }
}
