#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;

int n,m,mod=1000000007,low[N],disc[N],co[N],ans1,ans2=1,ti,mn,cnt;
bool in_ST[N];
stack<int> st;
vector<int> vec[N];
///https://codeforces.com/problemset/problem/427/C

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
        mn = 1e9, cnt = 0;
        while(true){
            int now = st.top();
            st.pop();
            in_ST[now] = false;
            if(co[now] < mn){
                mn = co[now];
                cnt = 1;
            }else if(co[now] == mn){
                cnt++;
            }
            if(now == u)
                break;
        }
        ans1 += mn;
        ans2 = (ans2*cnt)%mod;
    }
}

void test_case(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> co[i];
    }
    cin >> m;
    for(int i=1, u, v; i<=m; i++){
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    for(int i=1; i<=n; i++){
        if(disc[i]) continue;
        dfs(i);
    }
    cout << ans1 << " " << ans2 << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
