#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

int n,m,K,dis[30][30],qs[N][30],dp[N][30],mn[N][30];
char in[N];

void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen( (name+".in").c_str(), "r", stdin );
        freopen( (name+".out").c_str(), "w", stdout);
    }
}


main(){
    setIO("cowmbat");
    cin >> n >> m >> K;
    for(int i=1; i<=n; i++)
        cin >> in[i];
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> dis[i][j];
        }
    }

    for(int k=0; k<m; k++){
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            qs[i][j] = qs[i-1][j];
            qs[i][j] += dis[in[i]-'a'][j];
        }
    }

    for(int i=0; i<=n; i++) for(int j=0; j<m; j++) mn[i][j] = 1e9;
    for(int i=1; i<=n; i++) for(int j=0; j<m; j++) dp[i][j] = 1e9;

    for(int i=K; i<=n; i++){
        for(int c=0; c<m; c++){
                mn[i][c] = mn[i-1][c];
            for(int t=0; t<m; t++){
                mn[i][c] = min(mn[i][c], dp[i-K][t]-qs[i-K][c]);
            }
            dp[i][c] = mn[i][c]+qs[i][c];
        }
    }

    int ans = 1e9;
    for(int c=0; c<m; c++)
        ans = min(ans, dp[n][c]);
    cout << ans << "\n";
}

