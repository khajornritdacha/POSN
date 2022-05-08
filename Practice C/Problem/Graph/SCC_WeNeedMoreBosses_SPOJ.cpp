#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 3e5+10;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int low[N], id[N], ti, n, m, dis[N], num, scc_id[N];
bool vi[N];
vector<int> G[N],nG[N];
stack<int> st;

void SCC(int u, int p)
{
    id[u] = low[u] = ++ti;
    st.push(u);
    for(int v : G[u])
    {
        if(v == p) continue;
        if(!id[v]) SCC(v, u);
        low[u] = min(low[u], low[v]);
    }
    if(low[u] == id[u])
    {
        num++;
        while(true)
        {
            int now = st.top(); st.pop();
            scc_id[now] = num;
            if(now == u) break;
        }
    }
}

void dfs(int u, int p)
{
    vi[u] = true;
    for(int v : nG[u])
    {
        if(vi[v]) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }    
    
    SCC(1, -1);

    for(int i = 1 ; i <= n; i++)
    {
        for(int v : G[i])
        {
            if(scc_id[i] != scc_id[v])
            {
                nG[scc_id[i]].emplace_back(scc_id[v]);
                nG[scc_id[v]].emplace_back(scc_id[i]);
            }
        }
    }

    dis[0] = -1;
    
    int S = 0;
    dfs(1, -1);
    for(int i = 1; i <= num; i++) 
    {
        if(dis[i] > dis[S]) S = i;        
    }

    for(int i = 1; i <= num; i++) dis[i] = vi[i] = 0;

    int T = 0;
    dfs(S, -1);
    for(int i = 1; i <= num; i++)
    {
        if(dis[i] > dis[T]) T = i;
    }

    cout << dis[T] << "\n";

    return 0;
}
