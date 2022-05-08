#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+10;
int n,P,Q,dp[N][N];

///used time 42 mins


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

    int l = 1, r = 1e9, ans = -1, lim = min(P, Q), chk = max(P, Q);
    int code = (P < Q);

    while(l <= r){
        int mid = (l+r)/2;
        for(int i=1, j1, j2; i<=n; i++){

            if(code == 0){
                j1 = lower_bound(a.begin()+1, a.end(), a[i]-2*mid+1)-a.begin();
                j2 = lower_bound(a.begin()+1, a.end(), a[i]-mid+1)-a.begin();
            }else{
                j1 = lower_bound(a.begin()+1, a.end(), a[i]-mid+1)-a.begin();
                j2 = lower_bound(a.begin()+1, a.end(), a[i]-2*mid+1)-a.begin();
            }

            for(int q=0; q<=lim; q++){
                dp[i][q] = 1e9;
                if(q > 0)
                    dp[i][q] = dp[j1-1][q-1];
                dp[i][q] = min(dp[i][q], dp[j2-1][q]+1);
            }
        }

        if(dp[n][lim] <= chk){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
