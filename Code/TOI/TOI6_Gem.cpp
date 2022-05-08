#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

vector<vector<int>> vec;
vector<int> disc,low;
vector<bool> in_ST;
stack<int> st;
int idx,cmp[N],a[N],b[N],ti,n,m,no[N];

void dfs(int u){
    disc[u] = low[u] = ++ti;
    in_ST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if(in_ST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(disc[u] == low[u]){
        ++idx;
        while(true){
            int now = st.top();
            st.pop();
            in_ST[now] = false;
            cmp[now] = idx;
            if(now == u)
                break;
        }
    }
}

bool testcase(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }

    memset(cmp, 0, sizeof(cmp));
    disc.assign(m+1, 0), low.assign(m+1, 0), in_ST.assign(m+1, false), vec.resize(m+1);
    for(int i=1; i<=m/2; i++){
        int u, v;
        cin >> u >> v;
        no[u] = v;
        no[v] = u;
    }


    for(int i=1; i<=n; i++){
        vec[no[a[i]]].emplace_back(b[i]);
        vec[no[b[i]]].emplace_back(a[i]);
    }
    for(int i=1; i<=m; i++){
        if(!disc[i])
            dfs(i);
    }

    for(int i=1; i<=m; i++){
        if(cmp[i] == cmp[no[i]])
            return false;
    }
    return true;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 5;
    while(t--){
        ti = 0;
        vec.clear();
        cout << (testcase() ? "Y" : "N");
    }
}

