#include<bits/stdc++.h>
using namespace std;
int n,a[1010],mx=-1e9,qs[1010],dp[300010];
vector<int> vec;
main(){
    //freopen("slalom.in","r",stdin);
    //freopen("slalom.out","w",stdout);
    for(int i=1; i<=200; i++){
        a[i] = a[i-1]+i;
        qs[i] = qs[i-1]+a[i];
        if(qs[i] > 3e5) break;
        vec.emplace_back(qs[i]);
    }
    for(int i=1; i<=3e5; i++)
        dp[i] = 1e9;
    dp[0] = 0;
    for(int i=1; i<=3e5; i++){
        for(int v : vec){
            if(v > i) break;
            dp[i] = min(dp[i], dp[i-v]+1);
        }
    }
    cin >> n;
    while(n--){
        int x,ans=0;
        cin >> x;
        cout << dp[x] << "\n";
    }
}
