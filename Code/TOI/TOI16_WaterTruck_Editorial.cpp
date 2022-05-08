#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, m;
int x[N], y[N], w[N];
int par[N], dep[N];
bool in_cycle[N];
bool hotspot[N];
vector<vector<int> > g;
int gen_son(int u, int z) {
  return (x[z] ^ y[z] ^ u);
}
void generate(int u, int v) {
  // marking the edges in these cycle by using bitset
  // First, I will mark E(u, v)
  for(int z : g[u]) if(gen_son(u, z) == v) {
    if(in_cycle[z]) return;
    in_cycle[z] = true;
  }
  // then, I know that this edge would be back edge. The depth of u must be more than the depth of v
  while(dep[u] > dep[v]) {
    for(int z : g[u]) if(gen_son(u, z) == par[u]) {
      in_cycle[z] = true;
      u = par[u];
      break;
    }
  }
  while(u != v) {
    for(int z : g[u]) if(gen_son(u, z) == par[u]) {
      in_cycle[z] = true;
      u = par[u];
      break;
    }
    for(int z : g[v]) if(gen_son(v, z) == par[v]) {
      in_cycle[z] = true;
      v = par[v];
      break;
    }
  }
}
void track_cycle(int u, int p) {
  par[u] = p, dep[u] = ~p ? (dep[p] + 1) : 1;
  for(int z : g[u]) {
    int v = gen_son(u, z);
    if(v == p) continue;
    if(dep[v]) {
      // back edge case & find lca and track the edge in cycles
      generate(u, v);
      continue;
    }
    track_cycle(v, u);
  }
}
void compress_cycle(int u) {
  hotspot[u] = false;
  for(int z : g[u]) while(g[gen_son(u, z)].size() == 2 && hotspot[gen_son(u, z)]) {
    // cerr << "====> " << gen_son(u, z) << endl;
    hotspot[gen_son(u, z)] = false;
    for(int zz : g[gen_son(u, z)]) if(gen_son(gen_son(u, z), zz) != u) {
      in_cycle[zz] = false;
      for(int &zzz : g[gen_son(gen_son(u, z), zz)]) if(gen_son(gen_son(gen_son(u, z), zz), zzz) == gen_son(u, z)) {
        zzz = z;
      }
      g[gen_son(u, z)].clear();
      if(x[z] != u) x[z] = gen_son(gen_son(u, z), zz);
      else y[z] = gen_son(gen_son(u, z), zz);
      w[z] += w[zz];
      break;
    }
  }
}
int nleft = 0, start = -1;
int considering[N];
int get_answer(int u, int lv = 0, int cnt = 0, int sum = 0) {
  if(u == start && nleft == cnt) {
    // if(sum == 26) {
      // cerr << u << ' ' << cnt << endl;
    // }
    return sum;
  }
  if(lv == 13) return -1;
  int ret = -1;
  for(int z : g[u]) {
    int v = gen_son(u, z);
    if(considering[z] == 0) cnt++;
    considering[z]++;
    int val = get_answer(v, lv+1, cnt, sum + w[z]);
    if(val == 26) {
      // cerr << "-> " << u << ' ' << w[z] << ' ' << z << endl;
      return val;
    }
    if(~ret) {
      if(~val) ret = min(ret, val);
    } else ret = val;
    considering[z]--;
    if(considering[z] == 0) cnt--;
  }
  return ret;
}
int main() {
  scanf("%d %d", &m, &n);
  g.resize(n);
  for(int i = 0; i < m; ++i) {
    scanf("%d %d %d", x+i, y+i, w+i);
    g[x[i]].emplace_back(i);
    g[y[i]].emplace_back(i);
  }
  // constructing a tree and tracking a cycle
  track_cycle(0, -1);
  // After I know the cycle, I will not consider every subtree in this graph
  g.clear();
  g.resize(n);
  int ans = 0;
  for(int i = 0; i < m; ++i) if(!in_cycle[i]) {
    ans += w[i];
  } else {
    g[x[i]].emplace_back(i);
    g[y[i]].emplace_back(i);
    // cerr << "=> " << x[i] << ' ' << y[i] << endl;
    // mark these nodes as hotspot nodes
    hotspot[x[i]] = hotspot[y[i]] = true;
  }
  ans <<= 1;
  // then, I will brute force in every cycle by denoting the hotspot node
  // cerr << ans << endl;
  // cerr << g[2].size() << endl;
  for(int i = 0; i < n; ++i) if(hotspot[i] && g[i].size() > 2) {
    // cerr << "ft -> " << i << endl;
    compress_cycle(i);
    start = i;
  }
  // cerr << g[2].size() << endl;
  for(int i = 0; i < n; ++i) if(hotspot[i]) {
    // cerr << "se -> " << i << endl;
    compress_cycle(i);
    if(~start) {
      g[x[m] = i].emplace_back(m);
      g[y[m] = start].emplace_back(m);
      in_cycle[m] = true;
      m++;
    } else start = i;
  }
  for(int i = 0; i < m; ++i) if(in_cycle[i]) {
    nleft++;
  }
  if(~start) {
    ans += get_answer(start);
  }
  printf("%d\n", ans);
}
