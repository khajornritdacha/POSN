// FenwickTree for Dynamic Range sum queries
// Task: https://cses.fi/problemset/task/1648/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

ll fen[N];
int arr[N],n,Q;

void update(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}


/**
 * @brief Get sum of all elements frorm 1 to idx
 */
ll sum(int idx){
    ll res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}


/**
 * @brief Get the sum in range [a, b]
 */
ll get_sum_range(int a, int b){
    if (a <= 0) return sum(b);
    return sum(b)-sum(a);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }

    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if (op == 1){
            update(a, b-arr[a]);
            arr[a] = b;
        } else {
            cout << get_sum_range(a-1, b) << "\n";
        }
    }
    return 0;
}