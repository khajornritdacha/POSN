#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;

int n,ST,ED,RE,P[N],bt[N];
long long cost[N],ans;
bool in_path[N];
vector<pi> vec[N];

///cal cost from ST to RE and RE to ED
///then get as many extra energy as possible by using solve func

void dfs(int u, int p){
    cost[u] += P[u];
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        cost[v] = cost[u]-w;
        bt[v] = u;
        dfs(v, u);
    }
}

void cal(int st, int ed){
    //cout << "CAL : " << st << " " << ed << "\n";
    cost[st] = 0;
    dfs(st, st);
    ans += cost[ed];
    int now = ed;
    while(now != st){
        //cout << now << " " << bt[now] << "\n";
        P[now] = 0;
        in_path[now] = true;
        now = bt[now];
    }
    P[now] = 0, in_path[now] = true;

    if(DEBUG){
        printf("ST:%d ED:%d\n", st, ed);
        for(int i=1; i<=n; i++){
            printf("%lld ", cost[i]);
        }
        printf("\n");
    }
}

long long solve(int u, int p, int root){
    if(in_path[u] and root != u)
        return 0;

    long long res = P[u];
    for(auto [v,w] : vec[u]){
        if(v == p) continue;
        res += max(0ll, solve(v, u, root)-2*w);
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    for(int i=1; i<=n; i++){
        cin >> P[i];
    }
    cin >> ST >> ED >> RE;
    cal(ST, RE);
    cal(RE, ED);

    //cout << "ANS : " << ans << "\n";
    for(int i=1; i<=n; i++){
        if(in_path[i]){
            ans += max(0ll, solve(i, i, i));
        }
    }
    cout << ans << "\n";


}

