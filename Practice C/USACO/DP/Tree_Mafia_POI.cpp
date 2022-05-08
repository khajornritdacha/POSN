#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+10;
using ll = long long;
using pi = pair<int, int>;
///https://szkopul.edu.pl/problemset/problem/w3YAoAT3ej27YeiaNWjK57_G/site/?key=statement
int dp[N][2],st,code,n,go[N],ans[2],leaf,sz;
bool vi[N],use[N];
vector<int> vec[N];

void cy(int u){
    if(vi[u]){
        st = u; return;
    }
    vi[u] = true;
    cy(go[u]);
}

void dfs(int u){
    use[u] = true;
    sz++;
    bool die = false;
    for(int v : vec[u]){
        if(v == st) continue;
        dfs(v);
        if(vec[v].size() == 0)
            die = true;
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    dp[u][1]++;
    if(vec[u].size() == 0)
        dp[u][0] = 0, dp[u][1] = 1e9, leaf++;
    if(u == go[st]){
        if(code){
            dp[u][0] = 1e9;
        }
    }
    if(die)
        dp[u][0] = 1e9;
}

void cls(int u){
    dp[u][0] = dp[u][1] = 0;
    use[u] = false;
    for(int v : vec[u])
        if(use[v])
            cls(v);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> go[i];
        vec[go[i]].emplace_back(i);
    }
    for(int i=1; i<=n; i++){
        if(use[i]) continue;
        cy(i);
        code = 0;
        dfs(st);
        int res = dp[st][1]; ///case for go[st] survive (go[st] can survive if and only if st die)
        if(DEBUG){
            cout << "ST : " << st << "\n";
            for(int i=1; i<=n; i++){
                printf("I %d : %d %d\n", i, dp[i][0], dp[i][1]);
            }
        }

        sz = leaf = 0;
        code = 1;
        cls(st);
        dfs(st);
        if(DEBUG){
            cout << "ST : " << st << "\n";
            for(int i=1; i<=n; i++){
                printf("I %d : %d %d\n", i, dp[i][0], dp[i][1]);
            }
        }
        ///let go[st] = v and st = u
        ///v can survive if and only if u die (code == 0)
        ///if u survive so v has to die (code == 1)
        res = min({res, dp[st][0], dp[st][1]}); ///case for go[st] die which st can either survive or die
        ans[0] += res;
        ans[1] += ((leaf or st == go[st]) ? sz-leaf : sz-1); ///for the maximum value we can use greedy approach by selecting every node except leaf
    }
    cout << ans[0] << " " << ans[1] << "\n";
}
