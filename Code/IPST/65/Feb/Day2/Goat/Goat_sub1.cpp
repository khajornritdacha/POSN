#include <bits/stdc++.h>
#include "goatforget.h"
#include <vector>
using namespace std;

vector<vector<int>> ans;

inline void addans(int a, int b){
	vector<int> tmp = {a, b};
	ans.push_back(tmp);
}

std::vector<std::vector<int> > recover_map(int N, int M, int Q){
	// edit this function
	if(N == 2){
		return {{0, 1}};
	}
	
	int preq = -1, u = 0, pa = -1, st = -1;
	while(true){
		int res1 = talk_tae(0);
		if(res1 == pa){
			assert(preq != -1);
			talk_tae(preq);
		} else {
			// addans(res1, u);
			preq = 0;
			pa = u;
			u = res1;
			continue;
		}

		int res2 = talk_tae(N-1);
		if(res2 == pa){
			talk_tae(preq);
			st = u;
			break;
		} else {
			// addans(res2, u);
			preq = N-1;
			pa = u;
			u = res2;
		}
	}

	u = st, pa = -1, preq = -1;
	while(true){
		int res1 = talk_tae(0);
		// cout << "CUR : " << u << " " << res1 << "\n";
		if(res1 == pa){
			assert(preq != -1);
			talk_tae(preq);
		} else {
			addans(res1, u);
			preq = 0;
			pa = u;
			u = res1;
			continue;
		}

		int res2 = talk_tae(N-1);
		if(res2 == pa){
			break;
		} else {
			addans(res2, u);
			preq = N-1;
			pa = u;
			u = res2;
		}
	}

	// cout << "ST : " << st << "\n";
	// for(auto vec : ans) cout << vec[0] << " " << vec[1] << "\n";

	return ans;
}

#ifdef LOCAL
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include "goatforget.h"

static int n, m, q;
static std::vector<int> g[128];
static int goat;
static int tcount;

int talk_tae(int x){
  if(x < 0 || x >= n){
    printf("Invalid talk\n");
    fflush(stdout);
    exit(0);
  }
  tcount++;
  if(tcount > q){
    printf("Too many talks\n");
    fflush(stdout);
    exit(0);
  }
  auto it = std::lower_bound(g[goat].begin(), g[goat].end(), x);
  int ylo = -1;
  int yhi = -1;
  if(it != g[goat].end()) yhi = *it;
  if(it != g[goat].begin()){
    it--;
    ylo = *it;
  }
  if(ylo != -1 && yhi != -1){
    if(abs(ylo - x) > abs(yhi - x)) return goat = yhi;
    else return goat = ylo;
  }else if(ylo != -1){
    return goat = ylo;
  }else{
    return goat = yhi;
  }
}

int main(){
  scanf("%d%d%d",&n,&m,&q);
  std::set<std::pair<int,int> > template_edges;
  for(int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d",&u,&v);
    if(u > v) std::swap(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
    template_edges.insert(std::make_pair(u, v));
  }
  for(int i = 0; i < n; i++){
    std::sort(g[i].begin(), g[i].end());
  }

	// cout << "TEST OUTPUT\n";
  std::vector<std::vector<int> > raw_edges = recover_map(n, m, q);
  if(raw_edges.size() != m){
    printf("Invalid answer\n");
    fflush(stdout);
    exit(0);
  }
  std::set<std::pair<int,int> > edges;
  for(auto e : raw_edges){
    if(e.size() != 2){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    if(e[0] < 0 || e[0] >= n || e[1] < 0 || e[1] >= n || e[0] == e[1]){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    std::pair<int, int> edge = std::make_pair(e[0], e[1]);
    if(edge.first > edge.second) std::swap(edge.first, edge.second);
    if(edges.count(edge)){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    edges.insert(edge);
  }
  if(edges == template_edges){
    printf("Correct answer: %d\n", tcount);
  }else{
    printf("Wrong answer\n");
  }
  return 0;
}
#endif