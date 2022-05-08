#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;

int n, dp[N], use[N], bt[N];

void solve(int in){
    int cur = in;
    string ans = "";
    while(cur > 1){
        string tmp = "ACV";
        for(int i = 0; i < use[cur]; i++) tmp.push_back('V');
        ans = tmp+ans;
        cur = bt[cur];
    }

    cout << ans << "\n";

}

int main(void){
    for(int i = 2; i < N; i++) dp[i] = INF;
    for(int i = 1; i < N; i++){
        for(int j = i+i, k = 1; j < N; j+=i, k++){
            if(dp[i]+3+k < dp[j]){
                dp[j] = dp[i]+3+k;
                bt[j] = i;
                use[j] = k;
            }
        }
    }

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << 10 << "\n";
    for(int t = 1; t <= 10; t++){
        cout << t << "\n";
        int in; cin >> in;
        solve(in);
    }


    return 0;
}