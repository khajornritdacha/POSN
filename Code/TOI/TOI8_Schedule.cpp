#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
int M,N,j[1005],k[1005];
pi dp[1005][1005];
pi ad(pi temp,int x){
    if(temp.second+x>M){
        temp.first +=1;
        temp.second = x;
    }else{
        temp.second+=x;
    }
    return temp;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    dp[0][0] = {1,0};
    for(int i=1;i<=N;i++){
        cin >> j[i];
        dp[0][i] = ad(dp[0][i-1],j[i]);
    }
    for(int i=1;i<=N;i++){
        cin >> k[i];
        dp[i][0] = ad(dp[i-1][0],k[i]);
    }
    for(int i=1;i<=N;i++){
        for(int o=1;o<=N;o++){
            dp[i][o] = min(ad(dp[i][o-1],j[o]),ad(dp[i-1][o],k[i]));
        }
    }
    cout << dp[N][N].first << "\n" << dp[N][N].second;
}
