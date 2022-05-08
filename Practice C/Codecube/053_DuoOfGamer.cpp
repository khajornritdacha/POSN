#include<bits/stdc++.h>
using namespace std;

int Q,dp[2][105][105][70],x[31],y[31],v[31],T=35;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    while(Q--){
        int n,A,B,K;
        cin >> n >> A >> B >> K;
        for(int i=1; i<=n; i++){
            cin >> x[i] >> y[i] >> v[i];
        }
        if(K == 0){
            cout << "0\n";
            continue;
        }
        int mx = -1e9;
        ///if for(a = 1->A) or b = 1->B or k = 1->69 it will false
        ///idk the reason
        for(int a=0; a<=A; a++) for(int b=0; b<=B; b++) for(int k=0; k<=69; k++) dp[1][a][b][k+T] = -1e9;

        dp[1][A][B][T] = 0;
        for(int i=1; i<=n; i++){
            int cur = i%2, nex = (i+1)%2;
            for(int a=0; a<=A; a++) for(int b=0; b<=B; b++) for(int k=0; k<=69; k++) dp[nex][a][b][k+T] = -1e9;
            for(int a=1; a<=A; a++){
                for(int b=1; b<=B; b++){
                    for(int k=-n; k<=n; k++){
                        if(dp[cur][a][b][k+T] == -1e9) continue;

                        dp[nex][a][b][k+T] = max(dp[nex][a][b][k+T], dp[cur][a][b][k+T]);

                        if(a-x[i] > 0)
                            dp[nex][a-x[i]][b][k+1+T] = max(dp[nex][a-x[i]][b][k+1+T], dp[cur][a][b][k+T]+v[i]);

                        if(b-y[i] > 0)
                            dp[nex][a][b-y[i]][k-1+T] = max(dp[nex][a][b-y[i]][k-1+T], dp[cur][a][b][k+T]+v[i]);
                    }
                }
            }
        }

        for(int a=1; a<=A; a++) for(int b=1; b<=B; b++) for(int k=-K; k<=K; k++) mx = max(mx, dp[(n+1)%2][a][b][k+T]);

        cout << mx << "\n";
    }
}
