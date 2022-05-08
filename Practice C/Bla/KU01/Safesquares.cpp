#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int,int>;

int R,C,n,mod=25621;
set<int> dr,dc;

int mul(int A, int B){
    return (A*B)%mod;
}

int sub(int A, int B){
    return ((A-B)%mod+mod)%mod;
}

int main(void){
    cin >> R >> C >> n;
    int res = mul(R%mod, C%mod);
    for(int i = 1; i <= n; i++){
        int r,c; cin >> r >> c;
        int self = 1, desr = (R-dr.size())%mod, desc = (C-dc.size())%mod;;
        if(dr.count(r) != 0){
            desc = 0;
            self = 0;
        }
        if(dc.count(c) != 0){
            desr = 0;
            self = 0;
        }
        res = sub(res, (desr+desc-self)%mod);
        dr.insert(r); dc.insert(c);
    }
    cout << res << "\n";
    return 0;
}
