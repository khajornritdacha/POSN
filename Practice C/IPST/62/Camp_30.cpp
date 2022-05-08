#include <bits/stdc++.h>
using namespace std;

using tu = tuple<int,int,int>;
using pi = pair<int,int>;

const int N = 3e5+10;
using ll = long long;

int n,dp[N][2];
vector<tu> order;

int main(void){
    cin >> n;
    order.emplace_back(-1, -1, -1);
    order.emplace_back(1e9, 1e9, 0);
    for(int i = 1; i <= n; i++){
        int a, b, w; cin >> a >> b >> w;
        order.emplace_back(b, a, w);
    }

    sort(order.begin(), order.end());

    for(int i = 1; i <= n+1; i++){
        auto [b, a, w] = order[i];
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        int mx = 0;
        for(int j = i-1; j >= 0; j--){
            auto [edj, stj, wj] = order[j];
            if(edj < a){
                dp[i][0] = max(dp[i][0], dp[j][0] + w);
                dp[i][1] = max(dp[i][1], dp[j][1] + w);
                dp[i][1] = max(dp[i][1], dp[j][0] + mx + w);
            }
            mx = max(mx, wj);
        }
    }

    cout << max(dp[n+1][0], dp[n+1][1]);
   
    return 0;
}