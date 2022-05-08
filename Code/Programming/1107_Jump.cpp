#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
using pi = pair<int,int>;
int a[N],n,P,K,dp[N];
vector<int> vec;
bool chk(int val){
    deque<pi> dq;
    dq.emplace_back(0,0);
    for(int i=1; i<=n; i++){
        while(!dq.empty() && i-dq.front().second > P)
            dq.pop_front();
        if(a[i] > val)
            dp[i] = dq.front().first+1;
        else
            dp[i] = dp[i-1];
        while(!dq.empty() && dp[i] < dq.back().first)
            dq.pop_back();
        dq.emplace_back(dp[i], i);
    }
    return dp[n] <= K;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K >> P;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        vec.emplace_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    int l=0, r=vec.size()-1, mid, ans=1e9;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(vec[mid])){
            ans = min(ans, vec[mid]);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
