#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;

vector<int> rev[N];
vector<pi> ans;
bool use[N];
int n,go[N],cmp,cyc[N];
queue<int> leaf[N];
///https://codeforces.com/contest/22/problem/E

void dfs(int u){
    use[u] = true;
    for(int v : rev[u]){
        if(use[v]) continue;
        dfs(v);
    }
    if(rev[u].size() == 0)
        leaf[cmp].push(u);
}

int cal(int i1){
    int l1;
    if(leaf[i1].size()){
        l1 = leaf[i1].front(); leaf[i1].pop();
    }else{
        l1 = cyc[i1];
    }
    return l1;
}


void test_case(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> go[i];
        rev[go[i]].emplace_back(i);
    }

    for(int i=1; i<=n; i++){
        if(use[i]) continue;
        ++cmp;
        int x = i, y = go[i];
        while(x != y){
            x = go[x];
            y = go[go[y]];
        }
        dfs(x);
        cyc[cmp] = x;
    }

    for(int i=1; i<cmp; i++){
        ans.emplace_back(cyc[i], cal(i+1)); ///join current in_cycle node to the leaf of the next cmp <- this is optimal
    }
    if(cmp > 1)
        ans.emplace_back(cyc[cmp], cal(1));

    for(int i=1; i<=cmp; i++){
        while(!leaf[i].empty()){
            ans.emplace_back(cyc[i], leaf[i].front());
            leaf[i].pop();
        }
    }

    cout << ans.size() << "\n";
    for(auto [u, v] : ans){
        cout << u << " " << v << "\n";
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
