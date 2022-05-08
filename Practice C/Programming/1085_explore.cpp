#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int dp[500005],n,m,k;
bool wall[500005];
vector<int> vec[500005];
int solve(int lv){
    if(lv>=n) return n;
    if(dp[lv]!=0) return dp[lv];
    if(wall[lv]&&vec[lv].size()==0) return lv;
    int temp=0;
    for(int i=0;i<vec[lv].size();i++){
       temp=max(temp,solve(vec[lv][i]));
    }
    if(wall[lv]) return dp[lv]=temp;
    return dp[lv] = max(solve(lv+1),temp);
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        vec[x].push_back(y);
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        wall[x]=true;
    }
    if(solve(1)>=n){
       cout << "1";
    }else{
        cout << "0 " << solve(1);
    }
}
