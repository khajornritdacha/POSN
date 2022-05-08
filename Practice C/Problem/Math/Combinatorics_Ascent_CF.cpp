//https://codeforces.com/problemset/problem/1284/B

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    vector<int> vec;
    int n_asc = 0, mn[T+5], mx[T+5];
    bool asc[T+5];

    for(int i = 1; i <= T; i++){
        mn[i] = INF;
        mx[i] = -INF;
        asc[i] = 0;
    }

    for(int i = 1; i <= T; i++){
        int sz; cin >> sz;

        for(int j = 1; j <= sz; j++){
            int x; cin >> x;
            if(x > mn[i]) asc[i] = true;
            mn[i] = min(mn[i], x);
            mx[i] = max(mx[i], x);
        }

        n_asc += asc[i];
        if(!asc[i])
            vec.emplace_back(mx[i]);
    }

    long long ans = 1ll*T*n_asc;
    sort(vec.begin(), vec.end());

    for(int i = 1; i <= T; i++){
        if(asc[i]) continue;
        ans += (int)vec.size()-(upper_bound(vec.begin(), vec.end(), mn[i])-vec.begin()) + n_asc;
    }

    cout << ans << "\n";


    return 0;
}