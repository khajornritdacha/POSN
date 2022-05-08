#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int n,a[100010],q;
bool cd;
const long long MOD=1e9+7;
long long fac[105],inv[105];

long long solve(int l, int r, int k){
    vector<int> dp(k+1,0);
    dp[0]=1;
    for(int i=l; i<=r; i++){
        for(int j=k; j>=a[i]; j--){
            dp[j]+=dp[j-a[i]];
            dp[j]%=MOD;
        }
    }
    return dp[k]%MOD;
}

ll pw(ll x, ll p){
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    ll tmp = pw(x, p/2);
    tmp = (tmp*tmp)%MOD;
    if(p%2)
        tmp *= x;
    return tmp%MOD;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]!=1)
            cd=1;
    }
    if(cd==0)
    {
        fac[0]=1;
        for(int i=1; i<=100; i++)
        {
            fac[i] = (fac[i-1]*i)%MOD;
            inv[i] = pw(fac[i], MOD-2);
        }
        while(q--)
        {
            long long l,r,k;
            cin >> l >> r >> k;
            long long ans=1,chua=r-l+1;
            for(int i=0; i<k; i++)
            {
                ans*=(r-l+1-i)%MOD;
                ans%=MOD;
            }
            ans*=inv[k];
            ans%=MOD;
            if(k>r-l+1) cout << "0\n";
            else cout << ans << "\n";
        }
    }else{
        while(q--){
            int l,r,k;
            cin >> l >> r >> k;
            cout << solve(l,r,k) << "\n";
        }
    }
}
