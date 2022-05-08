#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3e3+10;
int n,ti[N],sum1,sum0,g0,g1,cnt,ans;
vector<int> vec[N];


void dfs(int u, int c, int p){
    if(c){
        sum1 += ti[u];
        g1++;
    }else{
        sum0 += ti[u];
        g0++;
    }

    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, 1-c, u);
    }
}

void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

main(){
    setIO("clocktree");
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> ti[i];
    }
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }

    dfs(1, 0, -1);

    if(sum0%12 == sum1%12)
        cout << n;
    else if((sum0+1)%12 == sum1%12)
        cout << g1;
    else if(sum0%12 == (sum1+1)%12)
        cout << g0;
    else
        cout << 0;
}
