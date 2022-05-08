#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n;
vector<int> vec[N];

int dfs(int u, int p){
    int ch = vec[u].size()-(u != 1)+1;
    int sum = 0, tmp = 1;
    while(tmp < ch){
        tmp *= 2;
        sum++;
    }
    for(int v : vec[u]){
        if(v == p) continue;
        sum += dfs(v, u)+1;
    }
    return sum;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    cout << dfs(1, 1);
}
