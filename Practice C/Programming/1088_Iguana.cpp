#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
char c;
ll ans;
int co,now,n,m;
map<int,int> mp;
int click(int i);
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        mp[x]=(mp[x]+1);
        mp[y+1]=(mp[y+1]-1);
    }
    cin >> c;
    if(c=='R') co=0;
    else if(c=='G') co=1;
    else co=2;
    int pa=1;
    for(auto it=mp.begin();it!=mp.end();it++){
        int dis=(it->first)-pa;
        ans+=(dis*click(now));
        pa=it->first;
        now+=(it->second);
    }
    auto it=mp.end();
    it--;
    if(it->first<=n){
        ans+=(n-it->first+1)*click(now);
    }
    cout << ans;
}
int click(int i){
    i%=3;
    if(co>=i)
        return co-i;
    return co-i+3;
}
