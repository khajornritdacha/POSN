#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n;
double ans,a[N][N],dp[1<<N];
bool visit[1<<N];
double solve(int lv=1,int temp=0){
    if(lv==n+1)
        return 1;
    if(visit[temp])
        return dp[temp];
    double mx=0;
    for(int i=1;i<=n;i++){
        if((temp&(1<<i))!=0)
            continue;
        mx = max(mx,a[lv][i]*solve(lv+1,temp|(1<<i)));
    }
    visit[temp] = true;
    return dp[temp] = mx;
}
main(){
    cin >> n;
    cout << setprecision(6) << fixed;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            a[i][j]/=100;
        }
    }
    cout << solve()*100;
}
