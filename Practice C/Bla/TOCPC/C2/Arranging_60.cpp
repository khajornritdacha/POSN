#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e6+10;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,K, cnt[N], st[N], ed[N], dp[N][2], nst[N], a[N];
pi order[N];

int solve(){
    for(int i = 0; i <= n; i++){
        st[i] = nst[i] = ed[i] = 0;
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(st[a[i]] == 0){
            st[a[i]] = i;
        } else if(st[a[i]] != 0 and nst[a[i]] == 0){
            nst[a[i]] = i;
        }
        ed[a[i]] = i;
    }

    int idx = 0, spe = 0;
    map<int,int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(st[i] != 0){
            if(nst[i] == 0) nst[i] = st[i]+1;
            order[++idx] = pi(ed[i], i);
        }
    }
    sort(order+1, order+idx+1);

    for(int i = 1; i <= idx; i++){
        int ee,num;
        tie(ee, num) = order[i];
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];

        auto it = (--mp.lower_bound(st[num]));
        int tmp = dp[it->second][0];
        dp[i][0] = max(dp[i][0], tmp + cnt[num]);

        tmp = dp[it->second][1];//from previos
        dp[i][1] = max(dp[i][1], tmp + cnt[num]);

        //if k == 1 there are 3 cases : 1. from previous 2. deleting current first element
        it = (--mp.lower_bound(nst[num])); //deleting current first element
        tmp = dp[it->second][0];
        dp[i][1] = max(dp[i][1], tmp + cnt[num]);       
           
        mp[ee] = i;
    }

    // for(int i = 1; i < sz; i++)
    // {
    //     cout << dp[i][0]  << " " << dp[i][1] << "\n";
    // }

    int res = dp[idx][0];
    if(K == 1)
        res = max(res, dp[idx][1]-1);
    return res;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K; //interval scheduling problems
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;        
    }

    int ans = solve();
    //cout << ans << "\n";
    for(int i = 1; i <= n/2; i++){
        swap(a[i], a[n-i+1]);
    }

    ans = max(ans, solve());

    cout << n-ans << "\n";  

    return 0;
}
