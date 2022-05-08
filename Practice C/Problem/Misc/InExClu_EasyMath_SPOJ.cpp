#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,m,a,d,wow[10];
ll solve(ll rea, ll lv=1, ll now=1, ll cnt=1){
    if(lv==6){
        ll tt=rea/now;
        if(cnt%2==0){
            tt*=-1;
        }
        return tt;
    }
    ll temp=__gcd(now,wow[lv]);
    return solve(rea, lv+1, (now*wow[lv])/temp, cnt+1)+solve(rea, lv+1, now, cnt);
}
main(){
    cin >>  t;
    while(t--){
        cin >> n >> m >> a >> d;
        wow[1]=a;
        wow[2]=a+d;
        wow[3]=a+d+d;
        wow[4]=a+d+d+d;
        wow[5]=a+d+d+d+d;
        cout << solve(m)-solve(n-1) << "\n";
    }
    return 0;
}
