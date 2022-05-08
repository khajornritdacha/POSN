#include "race.h"
#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
 
//https://oj.uz/problem/view/IOI11_race
//1st mistake: redeclaration of N (firstly MAXN was N)

const int MAXN = 2e5+10;
 
int ans = MAXN;
map<long long, int> mp[MAXN];
vector<pair<int,int>> G[MAXN];
 
void dfs(int u, int p, int dep, long long d, long long k){
  mp[u][d] = dep;
  for(auto [v, w] : G[u]){
    if(v == p) continue;
    dfs(v, u, dep+1, d+w, k);
 
    if(mp[v].size() > mp[u].size()) swap(mp[v], mp[u]);
    for(auto &[key, val] : mp[v]){
      long long tmp = k-key+2*d; //2nd mistake: it must be 2*d instead of 2*dep
      if(mp[u].count(tmp)) ans = min(ans, val+mp[u][tmp]-2*dep);
    }
    for(auto &[key, val] : mp[v]){
      if(mp[u].count(key)) mp[u][key] = min(mp[u][key], val);
      else mp[u][key] = val;
    }
  }
 
  if(mp[u].count(k+d)) ans = min(ans, mp[u][k+d]-dep);
 
}
 
int best_path(int N, int K, int H[][2], int L[])
{
  for(int i = 0; i < N-1; i++){
    int u = H[i][0], v = H[i][1];
    G[u].emplace_back(v, L[i]);
    G[v].emplace_back(u, L[i]);
  }
 
  dfs(0, 0, 0, 0, K);
 
  if(ans >= MAXN) ans = -1;
  return ans;
}