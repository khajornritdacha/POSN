#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e5+10;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int idx,n,U,V;
char c[N],chua[N];
vector<int> G[N];
stack<char> st;

bool dfs(int u, int p, int want){
    chua[++idx] = c[u];
    if(u == want) return true;
    for(int v : G[u]){
        if(v == p) continue;
        if(dfs(v, u, want)){
            return true;
        }
        idx--;
    }
    return false;
}


main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> U >> V;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            idx = 0;
            dfs(U, -1, i);

            dfs(j, -1, V);

            // cout << U << " to " << i << "\n";
            // for(int k = 1; k <= idx; k++){
            //     cout << chua[k];
            // }
            // cout << "\n";

            for(int k = 1; k <= idx; k++){
                if(chua[k] == '(') st.push(chua[k]);
                else if(!st.empty() and st.top() == '(') st.pop();
                else st.push(chua[k]);
            }
            if(st.empty()) ans++;
            else while(!st.empty()) st.pop();
        }
    }

    cout << ans << "\n";

    return 0;

}
