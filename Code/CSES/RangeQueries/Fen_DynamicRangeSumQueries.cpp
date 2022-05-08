#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

ll fen[N];
int arr[N],n,Q;

void up(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

ll sum(int idx){
    ll res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        up(i, arr[i]);
    }

    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if (op == 1){
            up(a, b-arr[a]);
            arr[a] = b;
        } else {
            cout << sum(b) - sum(a-1) << "\n";
        }
    }
    return 0;
}