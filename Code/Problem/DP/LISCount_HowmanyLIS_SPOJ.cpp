#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int n,a[N];
vector<int> mem[N];
vector<ll> qs[N];
ll mod = 1000000007;

///https://www.spoj.com/problems/HMLIS/

int bi(int k, int val){
    int l = 0, r = (int)mem[k].size()-1, res = -1;

    while(l <= r){
        int mid = (l+r)>>1;
        if(mem[k][mid] >= val){
            res = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    //cout << "RES : " << res << "\n";
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    vector<int> lis = {0};
    vector<ll> dp(n+1);
    mem[0] = {0};
    qs[0] = {1};
    //cout << dp[0] << "\n";
    for(int i = 1; i <= n; i++){
        int k = lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
        if(k == lis.size()){
            lis.emplace_back(a[i]);
            ans = 0;
        }else{
            lis[k] = a[i];
        }
        mem[k].emplace_back(a[i]);
        //cout << k << " ";
        int pos = bi(k-1, a[i]);
        if(pos != -1){
            dp[i] -= qs[k-1][pos];
        }
        //cout << k-1 << " " << qs[k-1].back() << "\n";
        dp[i] += qs[k-1].back();

        dp[i] = (dp[i]+mod)%mod;

        qs[k].emplace_back(((qs[k].empty() ? 0 : qs[k].back())+dp[i])%mod);

        if(k+1 == lis.size())
            ans = (ans+dp[i])%mod;
    }
    cout << lis.size()-1 << " " << ans << "\n";
    return 0;
}
