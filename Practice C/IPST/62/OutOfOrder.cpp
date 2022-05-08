#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int fen[N];

void up(int idx, int val){
    if(idx <= 0) return;
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

int ask(int idx){
    int res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int ask(int l, int r){
    return ask(r)-ask(l-1);
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    vector<pair<int, int>> vec;
    int D[n+5] = {};

    for(int i = 1; i <= n; i++){
        int h; cin >> h;
        vec.emplace_back(h, i);
    }
    for(int i = 1; i <= n; i++) cin >> D[i];

    sort(vec.rbegin(), vec.rend()); //if height are equal then idx must sort by descending order

    long long ans = 0;
    for(auto [h, idx] : vec){
        ans += ask(max(1, idx-D[idx]), idx);
        up(idx, 1);
    }

    memset(fen, 0, sizeof(fen));

    sort(vec.begin(), vec.end()); //if height are equal then idx must sort by ascending order
    for(auto [h, idx] : vec){
        ans += ask(idx, min(n, idx+D[idx]));
        up(idx, 1);
    }

    cout << ans << "\n";

    return 0;
}