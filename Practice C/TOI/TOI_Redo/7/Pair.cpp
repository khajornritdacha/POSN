#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

ll fen[2][N],n;
pi a[N];

//ai < aj and bi > bj
//if ai == aj then bi > bj so that it won't over count

void up(int idx, int val){ //fenwick tree
    if(idx <= 0) return;
    while(idx < N){
        fen[0][idx] += val;
        fen[1][idx]++;
        idx += idx&-idx;
    }
}

ll sum(int cd, int idx){  
    ll res = 0;
    while(idx){
        res += fen[cd][idx];
        idx -= idx&-idx;
    }
    return res;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1, a+n+1, greater<pi>());

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += sum(0, a[i].second-1) + 1ll*sum(1, a[i].second-1)*a[i].first;
        up(a[i].second, a[i].first);
    }

    cout << ans << "\n";
    return 0;
}