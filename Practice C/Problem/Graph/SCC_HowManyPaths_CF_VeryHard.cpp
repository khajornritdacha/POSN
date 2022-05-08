#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 4e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

stack<int> st;
int disc[N],low[N],ti,V,E,cnt[N],idc,cmp[N];
bool in_ST[N],self[N],cyc[N],vi[N],two[N];
vector<vector<int>> vec;
set<int> rev[N];
vector<pi> edge;
///https://codeforces.com/contest/1547/problem/G
void scc(int u){
    disc[u] = low[u] = ++ti;
    in_ST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        if(in_ST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(low[u] == disc[u]){
        vector<int> chua;
        idc++;
        while(true){
            int now = st.top();
            st.pop();
            in_ST[now] = false;
            cmp[now] = idc;
            chua.emplace_back(now);
            if(now == u)
                break;
        }
        if(chua.size() > 1 or self[u]){
            cyc[idc] = true;
            /*for(int cc : chua)
                cyc[cc] = true;*/
        }
    }

}

void topo(int u){
    vi[u] = true;
    for(int v : rev[u]){
        if(!vi[v])
            topo(v);
    }
    st.push(u);
}


void test_case(){
    ti = idc = 0;
    cin >> V >> E;
    for(int i=0; i<=V; i++){
        disc[i] = low[i] = in_ST[i] = self[i] = cyc[i] = cnt[i] = vi[i] = cmp[i] = two[i] = 0;
        rev[i].clear();
    }
    vec.clear(); vec.resize(V+1); edge.clear();
    for(int i=1; i<=E; i++){
        int u, v;
        cin >> u >> v;
        if(u == v)
            self[u] = true;
        else
            vec[u].emplace_back(v);
        edge.emplace_back(u, v);
    }
    for(int i=1; i<=V; i++){
        if(!disc[i]){
            scc(i);
        }
    }

    for(auto [u, v] : edge){
        if(cmp[u] != cmp[v])
            rev[cmp[u]].insert(cmp[v]);
    }
    topo(cmp[1]);
    for(int i=0; i<=V; i++) vi[i] = 0;
    cnt[cmp[1]] = 1;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        vi[u] = true;
        for(int v : rev[u]){
            cyc[v] |= cyc[u];
            cnt[v] += cnt[u];
            two[v] |= two[u];
            if(cnt[v] > 1){
                two[v] = true;
            }
        }
    }

    for(int i=1; i<=V; i++){
        int res;
        if(cyc[cmp[i]] and cnt[cmp[i]] > 0){
            res = -1;
        }else if(two[cmp[i]]){
            res = 2;
        }else{
            res = cnt[cmp[i]];
        }
        cout << res << " ";
    }
    cout << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
