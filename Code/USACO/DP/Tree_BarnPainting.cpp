#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int mod=1e9+7,n,dp[N][5],K,col[N];
vector<int> vec[N];

void dfs(int u, int p){
    if(col[u] == 0)
        dp[u][1] = dp[u][2] = dp[u][3] = 1;
    else
        dp[u][col[u]] = 1;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        for(int i=1; i<=3; i++){
            long long tmp = 0;
            for(int j=1; j<=3; j++){
                if(j == i) continue;
                tmp = (tmp+dp[v][j])%mod;
            }
            dp[u][i] = (1ll*dp[u][i]*tmp)%mod;
        }
    }
}

void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}


main(){
    setIO("barnpainting");
    cin >> n >> K;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=K; i++){
        int b,c;
        cin >> b >> c;
        col[b] = c;
    }
    dfs(1, -1);

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << "I : " << i << " = ";
            for(int j=1; j<=3; j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    cout << (dp[1][1]+dp[1][2]+dp[1][3])%mod << "\n";
}
