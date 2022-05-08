#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 110;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
using ll = long long;

int n,K,dp[10][N][N],C[N][N],a[N];

void setIO(string filename = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(filename.size()){
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

main(){
    setIO("cbarn2");
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    if(K >=n){
        cout << 0;
        return 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++)
            C[i][j] = C[i][j-1]+(j-i)*a[j];
        if(i != 1)
            C[i][1] = C[i][n]+(1-i+n)*a[1];
        for(int j=2; j<=i-1; j++)
            C[i][j] = C[i][j-1]+(j-i+n)*a[j];
        C[i][0] = C[i][n];
    }

    if(DEBUG){
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                cout << C[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int ans = 1e12;
    for(int k=0; k<=K; k++) for(int i=0; i<=n; i++) for(int st=0; st<=n; st++) dp[k][i][st] = 1e12;

    for(int i=1; i<=n; i++)
        dp[1][i][i] = C[i][i-1];

    for(int k=2; k<=K; k++){
        for(int st=1; st<=n; st++){
            for(int j=st; j<=n; j++){
                for(int i=j+1; i<=n; i++){
                    if(dp[k-1][j][st] == 1e12) continue;
                    dp[k][i][st] = min(dp[k][i][st], dp[k-1][j][st]-C[j][st-1]+C[j][i-1]+C[i][st-1]);
                }
            }
        }
    }

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ans = min(ans, dp[K][i][j]); ///Find answer in separated for in the case that K = 1

    if(DEBUG){
        for(int k=1; k<=K; k++){
            cout << "K : " << k << "\n";
            for(int i=1; i<=n; i++){
                for(int st=1; st<=n; st++){
                    cout << dp[k][i][st] << " ";
                }
                cout << "\n";
            }
            cout << "-----------------\n";
        }
    }

    cout << ans << "\n";
}

