#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int ed[N],n,ans;
vector<int> vec[N];
///https://szkopul.edu.pl/problemset/problem/1QaUWE_ePAmitZjgAszOVD1U/site/?key=statement

void dfs(int u, int p){
    int mx1=-1e9, mx2=-1e9;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        int tmp1 = max(vec[v].size()-1+vec[u].size()-1, ed[v]-1+vec[u].size()-1); ///if u is an end point of path then the number of ans from this should be max(let v be start point, append u to longest path of v)
        ed[u] = max(ed[u], tmp1);
        int tmp = max((int)vec[v].size()-1, ed[v]-1);
        if(tmp >= mx1)
            swap(mx1, tmp);
        if(tmp >= mx2)
            swap(mx2, tmp);
    }
    ans = max(ans, ed[u]);
    if(mx1 != -1e9 and mx2 != -1e9)///if this node is a joint of longest path
        ans = max(ans, mx1+mx2+int(vec[u].size())-2);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1,u,v; i<n; i++){
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << ans << "\n";

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << ed[i] << " \n"[i==n];
        }
    }
}

