#include <bits/stdc++.h>
#include "emergency.h"
#define DEBUG 0
using namespace std;

const int INF = 2e9+10, N = 2e5+10;

//rerooting dp 

int sub[N], pa[N], ans;
vector<pair<int,int>> G[N];
bool iscen[N], ishos[N];

void dfs1(int u, int p){
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dfs1(v, u);
        if(sub[v] >= 0){
            sub[u] = max(sub[u], sub[v]+w);
        }
    }
    if(iscen[u]) sub[u] = max(sub[u], 0);
}

void dfs2(int u, int p){
    int mxf = -INF, mxs = -INF, fi = -1;

    if(iscen[u]) pa[u] = max(pa[u], 0);
    if(ishos[u]) ans = max({ans, sub[u], pa[u]});

    for(auto [v, w] : G[u]){
        if(v == p) continue;
        if(sub[v] < 0) continue;
        
        int tmp = sub[v]+w;
        if(tmp > mxf) swap(mxf, tmp), fi = v;
        if(tmp > mxs) swap(mxs, tmp);
    }

    for(auto [v, w] : G[u]){
        if(v == p) continue;

        if(pa[u] >= 0) pa[v] = pa[u] + w;
        if(fi != -1){
            if(fi != v) pa[v] = max(pa[v], mxf+w);
            else if(mxs >= 0) pa[v] = max(pa[v], mxs+w);
        }

        dfs2(v, u);
    }
}

int furthest(int N, int H, int K, int roads[][2], int lengths[], int hos[], int cen[]){
    ans = -INF;
    for(int i = 0; i < N; i++) sub[i] = pa[i] = -INF;
    for(int i = 0; i < N-1; i++){
        int u = roads[i][0], v = roads[i][1], w = lengths[i];
        G[u].emplace_back(v, w); 
        G[v].emplace_back(u, w);
    }
    for(int i = 0; i < H; i++) ishos[hos[i]] = true;
    for(int i = 0; i < K; i++) iscen[cen[i]] = true;

    if(DEBUG){
        cout << "\nCheck INPUT\n";
        for(int i = 0; i < N; i++){
            cout << "CUR : " << i << "\n";
            cout << "ISHOS & ISCEN : " << ishos[i] << " " << iscen[i] << "\n";
            for(auto [v, w] : G[i]) cout << v << " " << w << "\n";
            cout << "\n";
        }
    }

    dfs1(0, -1);
    dfs2(0, -1);

    if(DEBUG){
        cout << "\nSUB&PA\n";
        for(int i = 0; i < N; i++){
            cout << sub[i] << " " << pa[i] << "\n";
        }
        cout << "\n";
    }
    

    return ans;
}

// int main(void){
//     int N, H, K; cin >> N >> H >> K;
//     vector<vector<int>> roads(N-1, vector<int>(2));
//     vector<int> lengths(N-1), hospitals(H), centers(K);

//     for(int i = 0; i < N-1; i++) cin >> roads[i][0] >> roads[i][1];
//     for(int i = 0; i < N-1; i++) cin >> lengths[i];
//     for(int i = 0; i < H; i++) cin >> hospitals[i];
//     for(int i = 0; i < K; i++) cin >> centers[i];

//     cout << furthest(N, H, K, roads, lengths, hospitals, centers);

//     return 0;
// }