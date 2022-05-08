#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, Q, arr[N];
long long fen[N];

void up(int idx, long long val){
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

long long sum(int idx){
    long long res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    while(Q--){
        int code; cin >> code;
        if(code == 1){
            int a, b, val; cin >> a >> b >> val;
            up(a, val), up(b+1, -val);
        } else {
            int k; cin >> k;
            cout << arr[k]+sum(k) << "\n";
        }
    }
    return 0;
}