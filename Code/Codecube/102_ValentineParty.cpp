#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,T,fen[N];

void up(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int qs(int idx){
    int res = 0;
    if(idx <= 0) return 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> T;
    while(T--){
        int st,K,D,Q;
        cin >> st >> K >> D >> Q;

        up(max(1, st-K), D);
        up(min(st+K+1, n+1), -D);

        if(st-K <= 0){
            up(n+(st-K), D);
        }
        if(st+K > n){
            up(1, D);
            up((st+K)-n+1, -D);
        }

        while(Q--){
            int x;
            cin >> x;
            cout << max(0, 10000-qs(x)) << " ";
        }

        cout << "\n";
    }
}
