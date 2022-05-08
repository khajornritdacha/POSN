#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 300;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int resz[N*N],n,in[N][N],id[N][N],ans,pr[]={-1,1,0,0}, pc[]={0,0,-1,1};
set<int> vi;
map<pi, map<int, vector<int>>> G;
///compress node
///make sure run time is O(numbers of edges)

int fir(int r, int c, int idx){
    id[r][c] = idx;
    int sum = 1;
    for(int i=0; i<4; i++){
        int gr = r+pr[i], gc = c+pc[i];
        if(!id[gr][gc] and in[gr][gc] == in[r][c])
            sum += fir(gr, gc, idx);
    }
    return sum;
}

int dfs(int u, pi pa){
    if(DEBUG){
        cout << u << " ";
    }

    vi.insert(u);
    int sum = resz[u];
    for(int v : G[pa][u]){
        if(vi.find(v) == vi.end())
            sum += dfs(v, pa);
    }
    return sum;
}

void adde(int i1, int j1, int i2, int j2){
    if(in[i1][j1] > in[i2][j2]){
        swap(i1, i2), swap(j1, j2);
    }
    pi pa = pi(in[i1][j1], in[i2][j2]);
    G[pa][id[i1][j1]].emplace_back(id[i2][j2]);
    G[pa][id[i2][j2]].emplace_back(id[i1][j1]);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> in[i][j];
            in[i][j]++; ///in[i][j] of the border(when i==0 or j==0, etc.) equal zero
        }
    }
    int idx = 0, mx = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(id[i][j]) continue;
            resz[idx] = fir(i, j, ++idx);
            mx = max(resz[idx], mx);
        }
    }

    if(DEBUG){
        cout << "------------------------\nID\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << id[i][j] << " ";
            }
            cout << "\n";
        }
        for(int i=1; i<=idx; i++){
            cout << "Sz : " << i << " = " << resz[i] << "\n";
        }
        cout << "-----------------------\n\n";
    }

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(j+1 <=n and in[i][j+1] != in[i][j])
            adde(i, j, i, j+1);
        if(i+1 <= n and in[i+1][j] != in[i][j])
            adde(i, j, i+1, j);
    }

    for(auto [pa, li] : G){
        vi.clear();
        for(auto [u,out] : li){
            if(vi.find(u) != vi.end()) continue;

            if(DEBUG){
                cout << "START : " << u << "\n";
            }

            ans = max(dfs(u, pa), ans);

            if(DEBUG){
                cout << "\n";
            }
        }
    }

    cout << mx << "\n" << ans << "\n";
}
