#include "roadreverse.h"
#include <bits/stdc++.h>
using namespace std;


const int MXN = 1e5+10;

vector<pair<int, int>> G[MXN];
vector<pair<int, int>> edge;
bool vi[MXN];


void dfs(int u, int ban) {
  vi[u] = true;
  for (auto [v, idx] : G[u]) if (idx != ban and !vi[v]) dfs(v, ban);
}

void unmark(int u) {
  vi[u] = false;
  for (auto [v, idx] : G[u]) if (vi[v]) unmark(v);
}

int count_roads(int N, int M, int K,
		std::vector<std::vector<int>> S,
		std::vector<std::pair<int,int>> R)
{
  int id = 0;
  for (int i = 0; i < K; i++) {
    
    G[0].emplace_back(S[i][0], id++);
    edge.emplace_back(0, S[i][0]);

    for (int j = 0; j+1 < S[i].size(); j++) {
      G[S[i][j]].emplace_back(S[i][j+1], id++);
      edge.emplace_back(S[i][j], S[i][j+1]);
    }
  }
  for (auto [u, v] : R) G[u].emplace_back(v, id++), edge.emplace_back(u, v);

  assert (id == M);

  int ans = M;
  for (int i = 0; i < M; i++) {
    auto [st, ed] = edge[i];
    dfs(st, i);

    if (vi[ed]) ans--;

    unmark(st);
  }

  return ans;

}
