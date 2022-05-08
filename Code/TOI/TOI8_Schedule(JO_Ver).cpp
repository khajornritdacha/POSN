#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
pi dp[1010][1010];
int a[1010],b[1010],M,N;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    int day=1,t=0;
    for(int i=1; i<=N; i++){
        cin >> a[i];
        if(t+a[i]>M){
            t=0;
            day++;
        }
        t+=a[i];
        dp[i][0]={day,t};
    }
    day=1,t=0;
    for(int i=1; i<=N; i++){
        cin >> b[i];
        if(t+b[i]>M){
            t=0;
            day++;
        }
        t+=b[i];
        dp[0][i]={day,t};
    }
    day=1,t=a[1];
    if(t+b[1]>M) day++, t=0;
    t+=b[1];
    dp[1][1]={day,t};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1&&j==1) continue;
            day=dp[i-1][j].first, t=dp[i-1][j].second;
            if(t+a[i]>M){
                day++;
                t=0;
            }
            t+=a[i];
            dp[i][j]={day,t};
            day=dp[i][j-1].first, t=dp[i][j-1].second;
            if(t+b[j]>M){
                day++;
                t=0;
            }
            t+=b[j];
            dp[i][j]=min(dp[i][j],{day,t});
        }
    }
    cout << dp[N][N].first << "\n" << dp[N][N].second;
}
