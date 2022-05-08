#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+10;
int n,P,Q,dp[N][N];

///Used time : 42 mins
///Date : 14th September 2021
///Find the minimum W by Binary Search and check with DP
///dp(i, q) = the minimum number of small cameras used at position i and used big cameras for q times
///dp(i, q) = minimum between
///1. dp(j-1, q-1) -> used a big camera then j = minimum position that satisfy a[i]-2*w+1 <= a[j]
///2. dp(j-1, q) -> used a small camera then j = minimum position that satisfy a[i]-w+1 <= a[j]

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> P >> Q;
    vector<int> a(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(P+Q >= n){
        cout << "1\n";
        return 0;
    }

    int l = 1, r = 1e9, ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        for(int i=1, j1, j2; i<=n; i++){

            j1 = lower_bound(a.begin()+1, a.end(), a[i]-2*mid+1)-a.begin();
            j2 = lower_bound(a.begin()+1, a.end(), a[i]-mid+1)-a.begin();

            for(int q=0; q<=Q; q++){
                dp[i][q] = 1e9;
                if(q > 0){
                    dp[i][q] = dp[j1-1][q-1];
                }
                dp[i][q] = min(dp[i][q], dp[j2-1][q]+1);
            }
        }

        if(dp[n][Q] <= P){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
