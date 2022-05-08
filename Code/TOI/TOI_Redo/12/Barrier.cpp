#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll,ll>;

//confused with ans = max(dp(i) - dp(j)) -> dp(i) - min(dp(j)) -> dp(i) + max(-dp(j))

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, W; cin >> n >> W;
    
    ll sum = 0, ans = 0, sz = 0;
    deque<pi> dq = {{0, 0}};

    for(int i = 1; i <= n; i++){
        while(!dq.empty() and i-dq.front().second > W) dq.pop_front();
        int x; cin >> x;
        sum += x;
        ll tmp = sum-dq.front().first;

        if(tmp > ans){
            ans = tmp;
            sz = i-dq.front().second;
        }else if(tmp == ans){
            sz = min(sz, i-dq.front().second);
        }

        while(!dq.empty() and sum <= dq.back().first) dq.pop_back();
        dq.push_back({sum, i});

        /*cout << "I " << i << "\n";
        for(auto [x, y] : dq){
            cout << x << " " << y << "\n";
        }*/
    }

    cout << ans << "\n" << sz << "\n";

    return 0;
}