#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10, BS = 200, INF = 1e9;
using pi = pair<int,int>;

int n,m,Q, sz[N], dis[N][BS], node[N][BS], tv[BS], tn[BS];
vector<int> bl, G[N];
bool ban[N];

///https://oj.uz/problem/view/JOI18_bitaro
//Separate query into 2 types : large and small
//it is large if its Y is greater or equal to BS(200 some value that about sqrt(sigma(Y)))
//if it is large then we it can be at most 1e5/200 -> 500 query of this type and we can perform normal dfs with O(n+m)
//if it is small we just precompute the first BS longest path that ends at every node with O(m * BS)

void preprocess(){
    for(int u = 1; u <= n; u++){
        if(sz[u] < BS){
            dis[u][sz[u]] = 0;
            node[u][sz[u]] = u;
            sz[u]++;
        }

        for(int v : G[u]){ //propagate current max to its child
            int i = 0, j = 0, k = 0; //perform alike merge sort
            while(i < sz[u] and j < sz[v] and k < BS){
                if(dis[u][i] + 1 > dis[v][j]){
                    if(!ban[node[u][i]]){
                        tv[k] = dis[u][i] + 1;
                        tn[k] = node[u][i];
                        ban[node[u][i]] = true;
                        k++;
                    }
                    i++;
                } else {
                    if(!ban[node[v][j]]){
                        tv[k] = dis[v][j];
                        tn[k] = node[v][j];
                        ban[node[v][j]] = true;
                        k++;
                    }
                    j++;
                }
            }

            while(i < sz[u] and k < BS){
                if(!ban[node[u][i]]){
                    tv[k] = dis[u][i] + 1;
                    tn[k] = node[u][i];
                    ban[node[u][i]] = true;
                    k++;
                }
                i++;
            }

            while(j < sz[v] and k < BS){
                if(!ban[node[v][j]]){
                    tv[k] = dis[v][j];
                    tn[k] = node[v][j];
                    ban[node[v][j]] = true;
                    k++;
                }
                j++;
            }

            for(int l = 0; l < k; l++){
                dis[v][l] = tv[l];
                node[v][l] = tn[l];
                ban[tn[l]] = false;
            }
            sz[v] = k;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
    }

    preprocess();

    if(DEBUG){
        for(int u = 1; u <= n; u++){
            cout << "U : " << u << "\n";
            for(int i = 0; i < sz[u]; i++){
                cout << dis[u][i] << " " << node[u][i] << "\n";
            }
            cout << "\n\n";
        }
    }

    while(Q--){
        int st, Y; cin >> st >> Y;
        bl.resize(Y);
        for(int &id : bl){
            cin >> id;
            ban[id] = true;
        }

        if(Y >= BS){
            int mx[N+5];
            for(int i = 1; i <= n; i++) mx[i] = -INF;

            for(int i = 1; i <= n; i++){
                if(!ban[i]) mx[i] = max(0, mx[i]);
                if(mx[i] <= -INF) continue;
                for(int v : G[i]){
                    mx[v] = max(mx[v], mx[i] + 1);
                }
            }

            if(mx[st] <= -INF) cout << "-1\n";
            else cout << mx[st] << "\n";

        }else{
            int ans = -1;
            for(int l = 0; l < sz[st]; l++){
                int val = dis[st][l], idx = node[st][l];
                if(!ban[idx]){
                    ans = val;
                    break;
                }
            }
            cout << ans << "\n";
        }

        for(int id : bl) ban[id] = false;
        bl.clear();
    }

    return 0;
}