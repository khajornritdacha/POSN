#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

using pi = pair<int,int>;
using tu = tuple<int,int,int>;
const int N = 3e5+10;
int dp[N],a[N],n,D,M[N],R[N],seg[4*N];
deque<pi> dq;
set<pi> ss;
vector<pi> order;

void sli(int idx){
    while(!dq.empty() and idx-dq.front().second >= D)
        dq.pop_front();
    while(!dq.empty() and dq.back().first >= a[idx])
        dq.pop_back();
    dq.emplace_back(a[idx], idx);
}

void up(int idx, int val, int be=1, int ed=n, int node=1){
    if(be == ed){
        seg[node] = val;
        return;
    }
    int mid = (be+ed)/2;
    if(idx <= mid)
        up(idx, val, be, mid, node*2);
    else
        up(idx, val, mid+1, ed, node*2+1);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int qq(int l, int r, int be=1, int ed=n, int node=1){
    if(l > ed or r < be)
        return -1e9;
    if(l <= be and ed <= r)
        return seg[node];
    int mid = (be+ed)/2;
    return max(qq(l, r, be, mid, node*2), qq(l, r, mid+1, ed, node*2+1));
}

main(){
    if(!DEBUG)
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> D;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(i <= D){
            //ss.insert({a[i], i});
            sli(i);
        }
        order.emplace_back(a[i], i);
        dp[i] = -1e9;
        up(i, -1e9);
    }

    for(int i=D+1; i<=n; i++){
        sli(i);
        ss.insert({a[i-D], i-D});
        //cout << dq.front().first << " " << dq.front().second << "\n";
        M[i] = dq.front().first;
        while(!ss.empty() and M[i] > ss.begin()->first){
            R[ss.begin()->second] = i;
            ss.erase(ss.begin());
        }
    }
    for(int i=1; i<=n; i++){
        if(R[i] == 0)
            R[i] = n;
        //cout << R[i] << " \n"[i==n];
    }

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << M[i] << " \n"[i==n];
        }
    }

    sort(order.begin(), order.end(), [&](pi A, pi B){
         if(A.first != B.first)
            return A.first > B.first;
        return A.second < B.second;
    });

    int ans = -1e9;
    for(auto [val, idx] : order){
        dp[idx] = max(qq(idx, R[idx]), 0)+1;
        up(idx, dp[idx]);
        ans = max(ans, dp[idx]);
    }
    cout << ans;

}
