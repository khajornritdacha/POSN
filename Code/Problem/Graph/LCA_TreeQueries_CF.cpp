#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10, LOG = 25;
using ll = long long;

int n,Q,pa[N][LOG+1],dep[N];
vector<int> G[N];

struct DATA{
    int dep,u;
    bool operator < (const DATA &other){
        if(dep != other.dep) return dep < other.dep;
        return u < other.u;
    }
};

void dfs(int u, int p){
    pa[u][0] = p;
    for(int v : G[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int fi(int u, int k){
    for(int i = LOG; i >= 0; i--){
        if((1<<i) <= k){
            k -= 1<<i;
            u = pa[u][i];
        }
    }
    return u;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dep[1] = 1;
    dfs(1, 0);

    for(int j = 1; j <= LOG; j++){
        for(int i = 1; i <= n; i++){
            pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }

    while(Q--){
        int m;
        vector<DATA> vec;
        cin >> m;
        for(int i = 1; i <= m; i++){
            int u; cin >> u;
            u = pa[u][0];
            vec.push_back({dep[u],u});
        }

        sort(vec.begin(), vec.end());

        if(DEBUG){
            cout << "-------------\n";
            for(int i = 0; i < vec.size(); i++){
                cout << vec[i].dep << " " << vec[i].u << "\n";
            }
            cout << "-------------\n";
        }

        bool ok = true;
        for(int i = 1, pre = 0; i < vec.size(); i++){
            if(vec[i].u == vec[i-1].u) continue;
            if(fi(vec[i].u, vec[i].dep-vec[i-1].dep) != vec[pre].u){
                ok = false;
                break;
            }
            pre = i;
        }

        if(ok)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}
