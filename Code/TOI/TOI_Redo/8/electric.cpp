#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
using ll = long long;
using pi = pair<int,int>;

int n, K, a[N];
deque<pi> dq;

//dp(i) = a[i] + min(dp(j)) ; i-j <= K
//dp(1) = 1

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = a[1];
    dq.emplace_back(a[1], 1);
    for(int i = 2; i <= n; i++){
        while(!dq.empty() and i-dq.front().second > K) dq.pop_front();

        int cur = a[i] + dq.front().first;
        ans = cur;

        while(!dq.empty() and cur <= dq.back().first) dq.pop_back();
        dq.emplace_back(cur, i);
    }

    cout << ans << "\n";
    return 0;
}