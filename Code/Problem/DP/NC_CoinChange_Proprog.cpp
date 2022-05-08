#include<bits/stdc++.h>
using namespace std;
long long dp[7510],c[]= {1,5,10,25,50},n;
main()
{
    dp[0] = 1;
    for(int j=0; j<5; j++)
    {
        for(int k=c[j]; k<=7500; k++)
        {
            dp[k] += dp[k-c[j]];
        }
    }
    /*for(int i=1; i<=100; i++)
        cout << "I: " << i << " " << dp[i] << "\n";*/
    while(cin >> n)
    {
        cout << dp[n] << "\n";
    }
}
