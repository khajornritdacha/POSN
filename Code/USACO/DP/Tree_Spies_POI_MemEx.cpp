#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+2;

int dp[N][2],st,n,go[N],ans,code;
bitset<N> vi,use;
vector<int> rev[N];

void cy(int u){
    if(vi[u]){
        st = u;
        return;
    }
    vi[u] = true;
    cy(go[u]);
}

void dfs(int u){

    if(DEBUG){
        printf("%d ", u);
    }

    int mn = 1e9;
    use[u] = true;
    for(int v : rev[u]){
        if(use[v] == true) continue;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        mn = min(mn, max(0, dp[v][1]-dp[v][0]));
    }
    dp[u][1] = max(0, dp[u][0]+1-mn);
    if(u == go[st] and code == 0)
        dp[u][1] = dp[u][0]+1; ///mn = 0
}

void cls(int u){
    dp[u][0] = dp[u][1] = 0;
    use[u] = false;
    for(int v : rev[u]){
        if(use[v] == true){
            cls(v);
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> go[i];
        rev[go[i]].emplace_back(i);
    }
    for(int i=1; i<=n; i++){
        if(use[i]) continue;
        cy(i);

        code = 0;
        dfs(st);
        int res = dp[st][0];

        if(DEBUG){
            printf("\nSt = %d\n", st);
            for(int i=1; i<=n; i++){
                printf("I %d = %d %d\n", i, dp[i][0], dp[i][1]);
            }
            printf("\n");
        }

        code = 1;
        cls(st);
        dfs(st);
        res = max({res, dp[st][0], dp[st][1]});

        if(DEBUG){
            printf("\nSt = %d\n", st);
            for(int i=1; i<=n; i++){
                printf("I %d = %d %d\n", i, dp[i][0], dp[i][1]);
            }
            printf("\n");
        }

        ans += res;
    }
    cout << ans << "\n";
}

/*
7
2
3
1
2
2
4
5
*/
