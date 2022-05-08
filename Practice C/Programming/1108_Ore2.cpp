#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
const int N = 1000010;
ll dp[N],qs[N],sum,last,mx;
int n,k,a[N];
deque<pi> dq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    n++;
    for(int i=2; i<=n; i++){
        cin >> a[i];
        if(a[i]>k)
            a[i] = 0;
        qs[i] = qs[i-1]+a[i];
    }
    dq.push_back({0,1});
    ///define dp(i) = max(dp(i-1), dp(j-2)+qs[i]-qs[j-1]);j<=i && qs[i]-qs[j-1]<=K
    ///define dq.front() = max(dp(j-2)-qs[j-1])
    for(int i=2; i<=n; i++){
        while(!dq.empty() && qs[i]-qs[dq.front().second-1] > k)
            dq.pop_front();
        while(!dq.empty() && dp[i-2]-qs[i-1] > dq.back().first)
            dq.pop_back();
        dq.push_back({dp[i-2]-qs[i-1], i});
        dp[i] = max(dp[i-1], dq.front().first+qs[i]);
    }
    /*for(int i=2; i<=n; i++)
        cout << dp[i] << " \n"[i==n];*/
    cout << dp[n] << "\n";
}
