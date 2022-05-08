#include<bits/stdc++.h>
using namespace std;
int k,n,dp[105][105];
vector<int> vec;
int solve(int,int);
void cls();
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        cin >> k;
        if(!k) return 0;
        cin >> n;
        vec.emplace_back(0);
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            vec.emplace_back(x);
        }
        vec.emplace_back(k);
        cout << "The minimum cutting is " << solve(0,n+1) << ".\n";
        cls();
        vec.clear();
    }
}

int solve(int i, int j)
{
    if(i+1==j) return 0;
    if(dp[i][j]!=0) return dp[i][j];
    int mn=1e9;
    for(int o=i+1; o<j; o++)
    {
        mn = min(mn,solve(i,o)+solve(o,j)+(vec[j]-vec[i]));
    }
    return dp[i][j] = mn;
}

void cls()
{
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            dp[i][j]=0;
        }
    }
}
