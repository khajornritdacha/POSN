#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int n,k,x[N],c[N],dp[N];
vector<pair<int,int>> vec;
deque<pair<int,int>> dq;
main(){
    cin >> n >> k;
    vec.emplace_back(0,0);
    for(int i=1; i<=n; i++){
        int xx,cc;
        cin >> xx >> cc;
        vec.emplace_back(xx,cc);
    }
    sort(vec.begin(), vec.end());
    int idx = 0;
    for(auto [xx,cc] : vec){
        x[idx] = xx;
        c[idx] = cc;
        idx++;
    }
    dq.emplace_back(c[1]+x[1], 1);
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1];
        while(!dq.empty() && x[i]-x[dq.front().second] > k)
            dq.pop_front();
        if(!dq.empty())
            dp[i] = max(dp[i], dq.front().first+c[i]-x[i]);
        while(!dq.empty() && dp[i-1]+c[i]+x[i] >= dq.back().first)
            dq.pop_back();
        dq.emplace_back(dp[i-1]+c[i]+x[i], i);
    }
    cout << dp[n];
}
