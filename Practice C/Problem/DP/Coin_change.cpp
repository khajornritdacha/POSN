#include<bits/stdc++.h>
using namespace std;
int n,k,dp[1000010],bt[1000010];
vector<int> C;
main(){
    cout << "Please input amount of money: ";
    cin >> n;
    cout << "Please input amount of coin types: ";
    cin >> k;
    cout << "Please input value of each coin\n";
    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        C.emplace_back(x);
    }
    for(int i=1; i<=n; i++){
        dp[i]=1e9;
        for(auto c:C){
            if(i-c>=0 && dp[i-c]+1<dp[i]){
                dp[i]=dp[i-c]+1;
                bt[i]=c;
            }
        }
    }
    cout << "The least amount of change coin is " << dp[n] << "\n";
    cout << "Contains of : ";
    while(n!=0){
        cout << bt[n] << " ";
        n-=bt[n];
    }
}

/*
10
3
1 3 4
*/
