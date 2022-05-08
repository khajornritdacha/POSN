#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int N,Q;
long long dp[maxn][5][5];
char str[maxn],let[10]={' ', 'L', 'O', 'V', 'E'};

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> str+1;
    for(int i=1; i<=N; i++){
        for(int l=4; l>=1; l--){
            dp[i][l][l] = dp[i-1][l][l]+(str[i]==let[l]);
            for(int r=l+1; r<=4; r++){
                dp[i][l][r] = dp[i-1][l][r] + dp[i][l][r-1] * (str[i] == let[r]);
            }
        }
        //cout << dp[i][1][4] << " ";
    }
    cin >> Q;
    while(Q--){
        int left,right;
        cin >> left >> right;
        long long cnt[5][5]={};
        for(int l=4; l>=1; l--){
            for(int r=l; r<=4; r++){
                cnt[l][r] = dp[right][l][r]-dp[left-1][l][r];
                for(int k=l; k<r; k++){
                    cnt[l][r]-=dp[left-1][l][k]*cnt[k+1][r];
                }
            }
        }
        /*for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                cout << cnt[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << cnt[1][4] << "\n";
    }
}
