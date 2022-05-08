#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;
 
const int N = 2e5+10;
using tu = tuple<int,int,int>;
using ll = long long;
using pi = pair<ll,int>;
 
int n,A,B;
ll qs[N];
 
main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++){
        cin >> qs[i];
        qs[i] += qs[i-1];
    }
 
    ll ans = -1e18; //dp(i) = qs(i) - min(qs(j)) ; A <= i-j <= B
    deque<pi> dq, pend = {pi(0, 0)}; //we will push j into deque if it is far from i at least A 
    for(int i = 1; i <= n; i++){ //and use deque to maintain minimum + not far from i than B
        while(!dq.empty() and i-dq.front().second > B) dq.pop_front();
 
        if(i >= A){
            auto [val, idx] = pend.front(); pend.pop_front();
            while(!dq.empty() and val <= dq.back().first) dq.pop_back();
            dq.emplace_back(val, idx);
  
            ll tmp = qs[i] - dq.front().first;
            ans = max(ans, tmp); 
 
        }
        pend.emplace_back(qs[i], i);
    }
 
    cout << ans << "\n";
    return 0;
}