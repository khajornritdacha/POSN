#include "emergency.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+10;

int dis[MXN];
vector<pair<int, int>> G[MXN];
bool ishos[MXN], iscen[MXN];

void dfs(int u, int p){
	for(auto [v, w] : G[u]){
		if(v == p) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
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
	int st1 = hospitals[0]+1;
	for(int i = 0; i < H; i++){
		ishos[hospitals[i]+1] = true;
	}
	for(int i = 0; i < K; i++){
		iscen[centers[i]+1] = true;
	}
	
	dis[st1] = 0;
	dfs(st1, -1);
	int mx = 0, st2 = 0;
	for(int i = 1; i <= N; i++){
		if(iscen[i] and dis[i] > mx){
			mx = dis[i];
			st2 = i;
		}
	}
	// cout << st1 << " " << st2 << " " << dis[st2] << "\n";

	dis[st2] = 0;
	dfs(st2, -1);
	for(int i = 1; i <= N; i++){
		if(ishos[i]  and dis[i] > mx){
			mx = dis[i];
		}
	}

  	return mx;
}
