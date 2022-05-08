#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int n,K,P,a[N],qs[N],dp[N][2];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K >> P;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];

        if(DEBUG){
            cout << qs[i] << " \n"[i==n];
        }
    }
    if(K*P >= n){
        cout << qs[n];
        return 0;
    }
    for(int k=1; k<=K; k++){
        int cur = k%2, pre = (k-1)%2;
        for(int i=0; i<=n; i++)
            dp[i][cur] = 0;
        for(int i=P; i<=n; i++){
            if(DEBUG){
                //cout << "NOW : " << i << "\n";
                //cout << dp[i-1][cur] << " " << i-P << " " << dp[i-P][pre] << " " << qs[i] << " " << qs[i-P] << " " << "\n";
            }
            dp[i][cur] = max(dp[i-1][cur], dp[i-P][pre]+qs[i]-qs[i-P]);
        }

        if(DEBUG){
            for(int i=0; i<=n; i++){
                cout << dp[i][pre] << " \n"[i==n];
            }
            for(int i=0; i<=n; i++){
                cout << dp[i][cur] << " \n"[i==n];
            }
            cout << "\n";
        }
    }

    cout << dp[n][K%2];
}
