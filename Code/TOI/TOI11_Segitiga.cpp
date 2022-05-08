#include<bits/stdc++.h>
using namespace std;
int n,a[300],cnt=20;
bool dp[300][300][3][21];
void segi(int, int, int);

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cnt--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            char x;
            cin >> x;
            a[i]=x-'0';
            dp[i][i][a[i]][cnt]=1;
        }
        for(int i=n; i>=1; i--)
        {
            for(int j=i+1; j<=n; j++)
            {
                for(int k=i; k<n; k++)
                {
                    segi(i,k,j);
                }
            }
        }
        cout << (dp[1][n][0][cnt] ? "yes" : "no") << "\n";
    }
}

void segi(int i, int k, int j)
{
    if(dp[i][k][0][cnt])
    {
        if(dp[k+1][j][0][cnt])
            dp[i][j][2][cnt]=1;
        if(dp[k+1][j][1][cnt])
            dp[i][j][1][cnt]=1;
        if(dp[k+1][j][2][cnt])
            dp[i][j][0][cnt]=1;
    }
    if(dp[i][k][1][cnt])
    {
        if(dp[k+1][j][0][cnt])
            dp[i][j][2][cnt]=1;
        if(dp[k+1][j][1][cnt])
            dp[i][j][1][cnt]=1;
        if(dp[k+1][j][2][cnt])
            dp[i][j][1][cnt]=1;
    }
    if(dp[i][k][2][cnt])
    {
        if(dp[k+1][j][0][cnt])
            dp[i][j][1][cnt]=1;
        if(dp[k+1][j][1][cnt])
            dp[i][j][2][cnt]=1;
        if(dp[k+1][j][2][cnt])
            dp[i][j][1][cnt]=1;
    }
}
