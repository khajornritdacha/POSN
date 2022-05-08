#include<bits/stdc++.h>
using namespace std;
long long dp[10010];

main(){
    dp[0]=1;
    for(int i=1; i*i*i<=1e4; i++){
        for(int k=i*i*i; k<=1e4; k++){
            dp[k]+=dp[k-i*i*i];
        }
    }
    //cout << "READY";
    int n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }
}
