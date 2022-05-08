#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
const int N = 3e5+10;
using pi = pair<int,int>;

int n,K,T[N],F[N];
ll dp[N][2];

///https://codeforces.com/problemset/problem/1076/F
///dp(i, 0) -> the minimum number of T in the last part of the prefix 1..i
///dp(i, 1) -> the minimum number of F in the last part of the prefix 1..i

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> T[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> F[i];
    }

    for(int i = 1; i <= n; i++){

        dp[i][0] = dp[i][1] = 1e18;

        if(dp[i-1][0] != -1){ ///previous end with T and current end with T
            ll totT = T[i]+dp[i-1][0];
            ll Flb = (totT-1)/K; ///find lower bound and upper bound for F
            ll Fub = T[i]*K; ///if F is in range of its lower bound and upper bound, then F is feasible
            if(F[i] == Flb){
                dp[i][0] = min(dp[i][0], totT-(K*F[i]));
            }else if(F[i] > Flb and F[i] <= Fub){
                dp[i][0] = min(dp[i][0], 1ll); ///if there are so many F, then just we can just put single T at the end and that will result in minimum
            }
        }

        if(dp[i-1][1] != -1){ ///previous end with F and current end with F
            ll totF = F[i]+dp[i-1][1];
            ll Tlb = (totF-1)/K;
            ll Tub = F[i]*K;
            if(T[i] == Tlb){
                dp[i][1] = min(dp[i][1], totF-(K*T[i]));
            }else if(T[i] > Tlb and T[i] <= Tub){
                dp[i][1] = min(dp[i][1], 1ll);
            }
        }

        if(dp[i-1][1] != -1){ ///previous end with F and current end with T
            ll totT = T[i];
            ll Flb = (totT-1)/K;
            ll Fub = (T[i]-1)*K + (K-dp[i-1][1]);
            if(F[i] == Flb){
                dp[i][0] = min(dp[i][0], totT-(K*F[i]));
            }else if(F[i] > Flb and F[i] <= Fub){
                dp[i][0] = min(dp[i][0], 1ll);
            }
        }

        if(dp[i-1][0] != -1){
            ll totF = F[i];
            ll Tlb = (totF-1)/K;
            ll Tub = (F[i]-1)*K + (K-dp[i-1][0]);
            if(T[i] == Tlb){
                dp[i][1] = min(dp[i][1], totF-(K*T[i]));
            }else if(T[i] > Tlb and T[i] <= Tub){
                dp[i][1] = min(dp[i][1], 1ll);
            }
        }

        //if(dp[i][0] == 0) dp[i][0] = 1;
        //if(dp[i][1] == 0) dp[i][1] = 1;

        if(dp[i][0] == 1e18) dp[i][0] = -1;
        if(dp[i][1] == 1e18) dp[i][1] = -1;
        //assert(dp[i][0] != 0 and dp[i][1] != 0);
    }

    if(dp[n][0] != -1 or dp[n][1] != -1) cout << "YES\n";
    else cout << "NO\n";

    /*for(int i = 1; i <= n; i++){
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }*/
    return 0;
}
