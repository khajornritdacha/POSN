#include<bits/stdc++.h>
using namespace std;
int N,MW,v[1005],w[1005],dp[1005][1005];
int knap(int pos,int cap){
    if(pos==0||cap==0)
        return 0;
    if(dp[pos][cap]!=0)
        return dp[pos][cap];
    if(w[pos]>cap)
        return dp[pos][cap] = knap(pos-1,cap);
    else{
        return dp[pos][cap] = max(knap(pos-1,cap),knap(pos-1,cap-w[pos])+v[pos]);
    }
}
main(){
    cin >> N >> MW;
    for(int i=1;i<=N;i++){
        cin >> w[i];
        cin >> v[i];
    }
    knap(N,MW);
    cout << dp[N][MW];
}
