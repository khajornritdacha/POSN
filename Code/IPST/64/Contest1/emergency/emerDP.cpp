#include "emergency.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+10, INF = 2e9+10;

int ans, sub[MXN], fpa[MXN];
vector<pair<int, int>> G[MXN];
bool ishos[MXN], iscen[MXN];

void dfs1(int u, int p){
    if(ishos[u]) sub[u] = 0;
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dfs1(v, u);

        if(sub[v] != -INF){
            sub[u] = max(sub[u], sub[v] + w);
        }
    }
}

void dfs2(int u, int p){
    int mx1 = -INF, v1 = 0, mx2 = -INF;
    if(ishos[u]) fpa[u] = max(fpa[u], 0);

    if(iscen[u]){
        ans = max({ans, sub[u], fpa[u]});
    }

    for(auto [v, w] : G[u]){
        if(v == p) continue;
        int tmp = sub[v] + w;
        if(tmp > mx1){
            swap(tmp, mx1);
            v1 = v;
        }
        if(tmp > mx2) swap(tmp, mx2);

        if(fpa[u] != -INF){
            fpa[v] = fpa[u] + w;
        }
    }

    for(auto [v, w] : G[u]){
        if(v == p) continue;
        if(v != v1){
            fpa[v] = max(fpa[v], mx1+w);
        } else {
            fpa[v] = max(fpa[v], mx2+w);
        }
        dfs2(v, u);
    }
}

int furthest(int N, int H, int K,
	     int roads[][2],
	     int lengths[],
	     int hospitals[],
	     int centers[])
{

	for(int i = 0; i < N-1; i++){
		int u = roads[i][0], v = roads[i][1];
		u++, v++;
		G[u].emplace_back(v, lengths[i]);
		G[v].emplace_back(u, lengths[i]);
	}
	for(int i = 0; i < H; i++){
		ishos[hospitals[i]+1] = true;
	}
	for(int i = 0; i < K; i++){
		iscen[centers[i]+1] = true;
	}

    for(int i = 1; i <= N; i++) fpa[i] = sub[i] = -INF;
	
    dfs1(1, -1);
    dfs2(1, -1);
    
  	return ans;
}
