#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
const int N = 1e5+10;
pi operator+(const pi &a, const pi &b){
    return pi(a.first+b.first, a.second+b.second);
}
int n,m,a[N];
vector<pi> seg;
void up(int pos, pi val, int node=1, int l=1, int r=n){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid){
        up(pos, val, node*2, l, mid);
    }else{
        up(pos, val, node*2+1, mid+1, r);
    }
    seg[node] = seg[node*2]+seg[node*2+1];
}
pi qq(int st, int ed, int node=1, int l=1, int r=n){
    if(st>r or ed<l)
        return {0,0};
    if(st <= l and r <= ed)
        return seg[node];
    int mid = (l+r)/2;
    return qq(st, ed, node*2, l, mid)+qq(st, ed, node*2+1, mid+1, r);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m){
        seg.clear();
        seg.resize(4*n+100, {0,0});
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(a[i] == 0)
                up(i, {0,1});
            if(a[i] < 0)
                up(i, {1,0});
        }
        for(int i=1; i<=m; i++){
            char code;
            int x,y;
            pi tmp;
            cin >> code >> x >> y;
            if(code == 'C'){
                if(y == 0)
                    up(x,{0,1});
                else if(y < 0)
                    up(x,{1,0});
                else
                    up(x,{0,0});
            }else{
                tmp = qq(x,y);
                //cout << "Q: " << x << " " << y << " = " << tmp.first << " " << tmp.second << "\n";
                if(tmp.second != 0)
                    cout << 0;
                else if(tmp.first%2)
                    cout << "-";
                else
                    cout << "+";
            }
            //tmp = qq(1, 1, n, 1, n);
            //cout << "NOW : " << tmp.first << " " << tmp.second << "\n";
        }
        cout << "\n";
    }
}
