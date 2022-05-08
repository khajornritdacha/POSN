#include<bits/stdc++.h>
using namespace std;
int n,s,w[310],dp[10010];
main(){
    cin >> s >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=s; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+w[i]);
        }
    }
    /*for(int i=1; i<=s; i++)
        cout << dp[i] << " \n"[i==s];*/
    cout << dp[s];
}
