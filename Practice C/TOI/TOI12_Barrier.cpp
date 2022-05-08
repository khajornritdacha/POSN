#include<bits/stdc++.h>
#define pi pair<int,int>
#define ll long long
using namespace std;
ll n,k,a[6000005],maxx,w;
pair<ll,ll> dp[6000005];
bool ok;
void solve(){
    for(int i=1;i<=k;i++){
        if(dp[i-1].first+a[i]>a[i]){
            dp[i] = {dp[i-1].first+a[i],dp[i-1].second+1};
        }else{
            dp[i] = {a[i],1};
        }
        if(maxx<dp[i].first){
            maxx = dp[i].first;
            w = dp[i].second;
        }else if(maxx==dp[i].first&&dp[i].second<w){
            w = dp[i].second;
        }
    }
    for(int i=k+1;i<=n;i++){
        if(dp[i-1].second>=k){
            if(dp[i-1].first+a[i]-a[i-k]>a[i]){
                dp[i] = {dp[i-1].first+a[i]-a[i-k],k};
            }else{
                dp[i] = {a[i],1};
            }
        }else{
            if(dp[i-1].first+a[i]>a[i]){
                dp[i] = {dp[i-1].first+a[i],dp[i-1].second+1};
            }else{
                dp[i] = {a[i],1};
            }
        }
        if(maxx<dp[i].first){
            maxx = dp[i].first;
            w = dp[i].second;
        }else if(maxx==dp[i].first&&dp[i].second<w){
            w = dp[i].second;
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>0)
            ok = true;
    }
    if(!ok){ cout << 0 << "\n" << 0; return 0; }
    solve();
    /*for(int i=1;i<=n;i++){
        cout << dp[i].first << " " << dp[i].second << "\n";
    }*/
    cout << maxx << "\n" << w;
}


