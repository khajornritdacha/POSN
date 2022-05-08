#include<bits/stdc++.h>
using namespace std;
using pi=pair<long long, int>;
int n,w,k;
long long a[6000010],qs[6000010],now,ans;
deque<pi> dq;
///ans=max(qs[r]-qs[l]) -> qs[r]-min(qs[l]) if r-w+1 <= l <= r
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
    }
    dq.emplace_back(0,0);
    for(int i=1; i<=n; i++){
        while(!dq.empty()&&i-dq.front().second>w) dq.pop_front();
        //cout << dq.front().first << " " << dq.front().second << "\n";
        now=qs[i]-dq.front().first;
        if(now>ans){
            ans=now;
            k=i-dq.front().second;
        }else if(now==ans){
            k=min(k,i-dq.front().second);
        }
        while(!dq.empty()&&qs[i]<dq.back().first) dq.pop_back();
        dq.emplace_back(qs[i],i);
    }
    cout << ans << "\n" << k;
}
