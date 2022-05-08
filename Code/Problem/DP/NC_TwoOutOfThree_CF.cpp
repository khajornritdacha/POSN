#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010, INF = 1e18;

using pi = pair<int,int>;
using tu = tuple<int,int,int>;


//https://codeforces.com/contest/82/problem/D

int n, a[N], dp[N][N], bt[N][N];

//dp(i, j) = minimum of suffix i to n with j is a leftover person
//dp(i, j) = min dp(i+2, i)
//               dp(i+2, i+1)
//               dp(i+2, j)

//base case
// dp(n, j) = max(n, j)
// dp(n-1, j) = dp(n+1, j)
// dp(n+1, j) = j

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int j = 1; j <= n; j++) dp[n+1][j] = a[j], dp[n][j] = max(a[n], a[j]);
    for(int i = n-1; i >= 1; i--){
        for(int j = i; j >= 1; j--){
            int tmp1 = dp[i+2][j] + max(a[i], a[i+1]), tmp2 = dp[i+2][i+1] + max(a[i], a[j]), tmp3 = dp[i+2][i] + max(a[i+1], a[j]);
            
            dp[i][j] = min({tmp1, 
                            tmp2,
                            tmp3});

            if(dp[i][j] == tmp1){
                bt[i][j] = j;
            } else if(dp[i][j] == tmp2){
                bt[i][j] = i+1;
            } else {
                bt[i][j] = i;
            }
        }
    }

    vector<pi> ans;
    int i = 2, j = 1;
    while(i < n){
        if(bt[i][j] == j){ //use i, i+1
            ans.emplace_back(i, i+1);
        } else if(bt[i][j] == i+1){ //use i, j
            ans.emplace_back(i, j);
            j = i+1;
        } else { //use i+1, j
            ans.emplace_back(i+1, j);
            j = i;
        }
        i += 2;
    }
    if(n&1) ans.emplace_back(j, n+1);
    else ans.emplace_back(i, j);

    cout << dp[2][1] << "\n";
    for(auto [x, y] : ans){
        if(y <= n) 
            cout << x << " " << y << "\n";
        else 
            cout << x << "\n";
    }


    return 0;
}