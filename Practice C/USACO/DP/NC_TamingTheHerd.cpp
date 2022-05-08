#include<bits/stdc++.h>
#define DEBUG true
#define int long long
using namespace std;

const int N = 110;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

int dp[N][N],a[N],n;

void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int cal(int l, int r){
    int cnt = 0;
    for(int i=0; i<=r-l; i++){
        cnt += (a[l+i] != i);
    }
    return cnt;
}

main(){
    setIO("taming");
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=i; j>=1; j--){
                dp[i][k] = min(dp[i][k], dp[j-1][k-1]+cal(j, i));
            }
        }
        cout << dp[n][k] << "\n";
    }
}

