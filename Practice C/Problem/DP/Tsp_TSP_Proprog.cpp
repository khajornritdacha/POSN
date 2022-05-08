#include<bits/stdc++.h>
using namespace std;
int xx,yy,n,dp[1<<17][17],ans=1e9;
vector<pair<int,int>> vec;
int dist(int x, int y){
    return abs(vec[x].first-vec[y].first)+abs(vec[x].second-vec[y].second);
}
main(){
    cin >> xx >> yy;
    cin >> n;
    if(n==0){cout << 0; return 0;}
    vec.resize(n+1);
    n++;
    vec[0]={xx,yy};
    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        vec[i]={x,y};
    }
    for(int i=0; i<n; i++) for(int bit=1; bit<(1<<n); bit++) dp[bit][i]=1e9;
    dp[1][0]=0;
    for(int bit=1; bit<(1<<n); bit++){
        for(int u=0; u<n; u++){
            if(!(bit&(1<<u))) continue;
            for(int v=0; v<n; v++){
                if(bit&(1<<v)) continue;
                dp[bit|(1<<v)][v]=min(dp[bit|(1<<v)][v],dp[bit][u]+dist(u,v));
            }
        }
    }
    for(int i=1; i<n; i++){
        ans=min(ans,dp[(1<<n)-1][i]+dist(0,i));
    }
    cout << ans << "\n";
}
