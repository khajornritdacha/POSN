#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using ll = long long;
int color[110],N,M,K;
ll p[110][110], dp[110][110][110], ans = 1e18,mn[110][110][110];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        cin >> color[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> p[i][j];
        }
    }
    for(int i=1; i<=N; i++) for(int k=0; k<=K; k++) for(int c=1; c<=M; c++) dp[i][k][c] = 1e18, mn[i][k][c] = 1e18;
    if(color[1] == 0){
        for(int c=1; c<=M; c++)
            dp[1][1][c] = p[1][c];
        ll le1 = 1e18,le2 = 1e18, pos1 = 0, pos2 = 0;
        for(int c=1; c<=M; c++){
            if(dp[1][1][c] < le1){
                    le1 = dp[1][1][c];
                    pos1 = c;
                }
            }
        for(int c=1; c<=M; c++){
            if(dp[1][1][c] < le2 && c!=pos1){
                le2 = dp[1][1][c];
                pos2 = c;
            }
        }
        for(int c=1; c<=M; c++){
            if(c!=pos1)
                mn[1][1][c] = le1;
            else
                mn[1][1][c] = le2;
        }
    }else{
        dp[1][1][color[1]] = 0;
        for(int c=1; c<=M; c++)
            if(c!=color[1])
                mn[1][1][c] = 0;
    }
    for(int i=2; i<=N; i++){
        for(int k=1; k<=K; k++){
            if(color[i] != 0){
                dp[i][k][color[i]] = min(dp[i][k][color[i]], dp[i-1][k][color[i]]);
                for(int c=1; c<=M; c++){
                    if(c != color[i]){
                        dp[i][k][color[i]] = min(dp[i][k][color[i]], dp[i-1][k-1][c]);
                    }
                }
            }else{
                for(int c=1; c<=M; c++){
                    dp[i][k][c] = min({dp[i][k][c], dp[i-1][k][c]+p[i][c], mn[i-1][k-1][c]+p[i][c]});
                }
            }
                ll le1=1e18,le2=1e18,pos1=0,pos2=0;
                for(int c=1; c<=M; c++){
                    if(dp[i][k][c] < le1){
                        le1 = dp[i][k][c];
                        pos1 = c;
                    }
                }
                for(int c=1; c<=M; c++){
                    if(dp[i][k][c] < le2 && c!=pos1){
                        le2 = dp[i][k][c];
                        pos2 = c;
                    }
                }
                for(int c=1; c<=M; c++){
                    if(c!=pos1)
                        mn[i][k][c] = le1;
                    else
                        mn[i][k][c] = le2;
                }
        }
    }

    if(DEBUG){
        for(int k=1; k<=K; k++){
            for(int c=1; c<=M; c++){
                for(int i=1; i<=N; i++){
                    cout << dp[i][k][c] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        for(int k=1; k<=K; k++){
            for(int c=1; c<=M; c++){
                for(int i=1; i<=N; i++){
                    cout << mn[i][k][c] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
    for(int c=1; c<=M; c++)
        ans = min(ans, dp[N][K][c]);
    if(ans == 1e18) ans=-1;
    cout << ans << "\n";
}
