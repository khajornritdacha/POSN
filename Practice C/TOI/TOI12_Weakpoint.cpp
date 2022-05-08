#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int V,pa[N],st,ed,dp[N],pr,mx=-2e9,pos;
bool visit[N],incy[N],code,pr_incycle;
vector<int> incycle;
vector<vector<int>> vec;
bool findcycle(int u, int p){
    //cout << u << "\n";
    visit[u] = true;
    for(int v : vec[u]){
        if(v==p) continue;
        if(!visit[v]){
            pa[v] = u;
            if(findcycle(v, u)){
                return true;
            }
        }else{
            st = v;
            ed = u;
            return true;
        }
    }
    return false;
}
void dfs(int u, int p){
    visit[u] = true;
    for(int v : vec[u]){
        if(visit[v]) continue;
        dfs(v, u);
        dp[u]+=dp[v]+1;
    }
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> pr;
    vec.resize(V+1);
    for(int i=1; i<=V; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    findcycle(pr, -1);
    //cout << "ST: " << st << " "  << ed << " " << pa[st] << " " << pa[ed] << "\n";
    int tmp = ed;
    while(tmp!=st){
        incycle.emplace_back(tmp);
        tmp = pa[tmp];
    }
    incycle.emplace_back(st);
    for(int i=1; i<=V; i++)
        visit[i] = 0;
    visit[pr] = 1;
    for(int u : incycle){
        incy[u] = true;
        if(u == pr)
            pr_incycle = true;
    }
    if(pr_incycle){
        for(int u : incycle)
            visit[u] = true;
        for(int u : incycle)
            dfs(u, -1);
        for(int v : vec[pr])
            if(!visit[v])
                dfs(v, -1);
    }else{
        code = 1;
        dfs(pr, -1);
    }
    for(int i=1; i<=V; i++){
        //cout << dp[i] << " \n"[i==V];
        if(i == pr) continue;
        if(dp[i] > mx){
            mx = dp[i];
            pos = i;
        }else if(dp[i] == mx){
            pos = min(pos, i);
        }
    }
    cout << pos << "\n" << mx << "\n";
}
