#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int n,Q,seg[2*N];

void up(int idx, int val){
    idx += n-1;
    seg[idx] = val;
    for(idx/=2; idx; idx/=2){
        seg[idx] = max(seg[2*idx], seg[2*idx+1]);
    }
}

int qq(int l, int r){
    int res = -2e9;
    for(l+=n-1, r+=n-1; l<=r; l/=2, r/=2){
        if(l%2 == 1)
            res = max(res, seg[l++]);
        if(r%2 == 0)
            res = max(res, seg[r--]);
    }
    return res;
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    while(Q--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'U'){
            up(x, y);
        }else{
            cout << qq(x, y) << "\n";
        }
    }
}
