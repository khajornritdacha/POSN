#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using pi = pair<int,int>;
const int N = 1e5+10;
int n,K,S,ans,tr[4*N],x[N],a[N],dp[N];
vector<pi> vec;
///Top down segTree require 4*N nodes
///Bottom up segTree require 2*N nodes
int query(int l, int r, int node=1, int st=1, int ed=n){
    if(r < st || l > ed)
        return 0;
    if(l <= st && ed <= r)
        return tr[node];
    int mid = (st+ed)/2;
    return max(query(l, r, 2*node, st, mid),query(l, r, 2*node+1, mid+1, ed));
}
void up(int want, int val, int node=1, int l=1, int r=n){
    if(l == r){
        tr[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(want <= mid)
        up(want, val, 2*node, l, mid);
    else
        up(want, val, 2*node+1, mid+1, r);
    tr[node] = max(tr[2*node], tr[2*node+1]);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K >> S;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> a[i];
        vec.emplace_back(x[i], i);
    }
    sort(vec.begin(), vec.end());
    for(int i=n; i>=1; i--){
        dp[i] = a[i];
        int r = upper_bound(vec.begin(), vec.end(), make_pair(x[i]+K, 100000000))-vec.begin();
        int l = lower_bound(vec.begin(), vec.end(), make_pair(x[i]-K, 0))-vec.begin();
        if(r!=0)
            r--;
        dp[i]+=query(l+1, r+1);
        int idx = lower_bound(vec.begin(), vec.end(), make_pair(x[i], i))-vec.begin();
        //cout << "IDX : " << i << " " << l << " " << r << " " << idx << "\n";
        up(idx+1, dp[i]);
    }
    for(int i=1; i<=n; i++){
        if(abs(S-x[i]) <= K){
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;
}
