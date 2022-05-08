#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int n,disc[N],m,ti;
vector<int> vec[N];
vector<tuple<int,int,int>> ans;
///https://codeforces.com/contest/860/problem/D
///we can always have floor(m/2) tour for every component when m is the number of edges in that component
///to do this -> denote u for current node, for each childrens' edges of u if it has odd edges then we have to use edge between u to
///that child to maximize number of edges, if that child has even edges then edge between u and that child still unoccupied and we can use it from u

bool dfs(int u, int p){
    disc[u] = ti++;
    vector<int> now;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v] != -1){
            if(disc[v] < disc[u]) ///can always use back edge to its ancestor
                now.emplace_back(v);
        }else{
            if(dfs(v, u)) ///if child has even edges then edge between u and that child still unoccupied and hence we can use it
                now.emplace_back(v);
        }
    }
    for(int i=0; i<now.size()/2; i++){
        ans.emplace_back(now[2*i], u, now[2*i+1]);
    }

    if(now.size()%2 == 0)  ///parent can use edge p to u
        return 1;

    if(p != -1)
        ans.emplace_back(now.back(), u, p);
    return 0;
}

void test_case(){
    memset(disc, -1, sizeof(disc));
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == -1){
            dfs(i, -1);
        }
    }

    cout << ans.size() << "\n";
    for(auto [x, y, z] : ans)
        cout << x << " " << y << " " << z << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
