#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int maxn = 1e5+10;
int N,L,U,last,sum[maxn],a[maxn],ans=-1;
bool dp[maxn];
int getdp(int r, int l){
    if(l>r)
        return 0;
    if(l<=0)
        return sum[r];
    return sum[r]-sum[l-1];
}
bool check(int k){
    for(int i=0; i<=N; i++)
        dp[i]=sum[i]=0;
    dp[0]=sum[0]= 1;
    last = -1;
    for(int i=1; i<L; i++){
        if(a[i]>=k)
            last = i;
        sum[i]=sum[i-1];
    }
    for(int i=L; i<=N; i++){
        if(a[i] >= k)
            last = i;
        dp[i] = (getdp(min(i-L, last-1), max(0,i-U)) > 0);
        sum[i]=dp[i]+sum[i-1];
    }
    if(DEBUG){
        cout << "MID : " << k << "\n";
        for(int i=0; i<=N; i++){
            cout << i%10 << " \n"[i==N];
        }
        for(int i=0; i<=N; i++){
            cout << dp[i] << " \n"[i==N];
        }
    }
    return dp[N];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> U;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    int l=0, r=1e9, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            ans = max(ans, mid);
        }else{
            r = mid-1;
        }
    }
    cout << ans << "\n";
}
