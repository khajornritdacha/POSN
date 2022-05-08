#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
using ll = long long;

vector<vector<int>> vec;
int dp[N],V,E,dis[N];
bool vi[N];
///https://codeforces.com/contest/1472/problem/G
int solve(int u){
    if(vi[u])
        return dp[u];
    vi[u] = true;
    int mn = 1e9;
    for(int v : vec[u]){
        if(dis[u] < dis[v])
            mn = min(mn, solve(v));
        else
            mn = min(mn, dis[v]);
    }
    return dp[u] = mn;
}

void test_case(){
    cin >> V >> E;
    vec.clear(); vec.resize(V+1);
    for(int i=1; i<=V; i++){
        dp[i] = dis[i] = 1e9;
        vi[i] = false;
    }
    for(int i=1,u,v; i<=E; i++){
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    queue<int> qq;
    qq.emplace(1);
    dis[1] = 0;
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        for(int v : vec[u]){
            if(dis[v] > dis[u]+1){
                dis[v] = dis[u]+1;
                qq.emplace(v);
            }
        }
    }
    for(int i=1; i<=V; i++){
        cout << min(dis[i], solve(i)) << " ";
    }
    cout << "\n";


    if(DEBUG){
        for(int i=1; i<=V; i++){
            cout << dis[i] << " \n"[i==V];
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        test_case();
    }
}
