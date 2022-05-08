#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

struct DATA{
    int l, r, idx;
};

int pre[N], n, Q, fen[N], arr[N], ans[N];
map<int, int> pos;
vector<DATA> order;

void up(int idx, int val){
    if(idx <= 0) return;
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

int sum(int idx){
    int res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int qq(int l, int r){
    return sum(r)-sum(l-1);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = pos[arr[i]];
        pos[arr[i]] = i;
    }
    for(int i = 1; i <= Q; i++){
        int l, r; cin >> l >> r;
        order.push_back({l, r, i});
    }

    sort(order.begin(), order.end(), [&](const DATA &A, const DATA &B){
        return A.r < B.r;
    });

    int i = 0;
    for(DATA o : order){
        while(i+1 <= n and i+1 <= o.r){
            i++;
            up(pre[i], -1);
        }

        ans[o.idx] = (o.r-o.l+1)+qq(o.l, o.r);
    }

    for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";

    return 0;
}