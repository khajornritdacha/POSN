#include<bits/stdc++.h>
using namespace std;
int ans,n,l,r,dif,h[20];
bool visit[20];
void solve(int lv=1){
    if(lv==n+1){
        int mn=2e9,mx=0,sum=0;
        for(int i=1; i<=n; i++){
            if(!visit[i])
                continue;
            mn=min(mn,h[i]);
            mx=max(mx,h[i]);
            sum+=h[i];
        }
        if(mx-mn>=dif && sum>=l && sum<=r){
            ans++;
        }
        return;
    }
    visit[lv]=true;
    solve(lv+1);
    visit[lv]=false;
    solve(lv+1);
}
main(){
    cin >> n >> l >> r >> dif;
    for(int i=1; i<=n; i++){
        cin >> h[i];
    }
    solve();
    cout << ans << "\n";
}
/*
https://codeforces.com/contest/550/problem/B
*/
