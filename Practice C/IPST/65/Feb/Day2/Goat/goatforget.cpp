#include <bits/stdc++.h>
#include "goatforget.h"
#include <vector>
using namespace std;

const int MXN = 110;
vector<vector<int>> ans;
vector<int> ch[MXN];
bool vi[MXN];

inline void addans(int a, int b){
	vector<int> tmp = {a, b};
	ans.push_back(tmp);
}

// void cal(int l, int r, int u, int pa, const int &N){
// 	// vi[u] = true;
// 	if(l > r) return;
// 	int mid = (l+r)>>1;
// 	int res = talk_tae(mid);
// 	cout << "CUR : " << u << " " << pa << "\n";
// 	cout << "L&R : " << l <<  " " << r << " = " << res << "\n\n";
// 	if(res == u or res == pa or res > r or res < l){
// 		talk_tae(u);
// 		return;
// 	}

// 	addans(u, res);
// 	cal(0, N-1, res, u, N);
// 	cal(l, res-1, u, pa, N);
// 	cal(res+1, r, u, pa, N);
	
// 	if(l == 0 and r == N-1 and pa != -1){
// 		talk_tae(pa);
// 	}
// 	return;
// }
void cal(int l, int r, int u){
	// cout << "CAL : " << l << " " << r << " " << u << "\n";
	if(l > r) return;
	int mid = (l+r)/2;
	int res = talk_tae(mid);
	talk_tae(u);
	if(res > r or res < l){
		if(mid+1 <= r){
			res = talk_tae(mid+1);
			talk_tae(u);
		}
	}
	if(l <= res and res <= r){
		ch[u].emplace_back(res);
		cal(l, res-1, u);
		cal(res+1, r, u);
	}
	return;
}

void solve(int u, int pa, const int &N){
	if(vi[u]) return;
	vi[u] = true;
	int A = talk_tae(0);
	// cout << "A: " << u << " " << pa << " = " << A << "\n";
	if(A != pa){
		solve(A, u, N); //automatically return back to u
		addans(A, u);
	} else {
		talk_tae(u);
	}
	int B = talk_tae(N-1);
	// cout << "B: " << u << " " << pa << " = " << B << "\n";
	if(B == A or B == pa){
		talk_tae(u); //to get back to u
	} else {
		solve(B, u, N);
		addans(B, u);
	}

	// cal(A+1, B-1, u);
	// for(int v : ch[u]){
	// 	talk_tae(v);
	// 	solve(v, u, N);
	// 	addans(v, u);
	// }	
	for(int i = A+1; i <= B-1; i++){
    if(vi[i]) continue;
		int res = talk_tae(i);
		if(res != i){
			talk_tae(u);
		} else {
			solve(i, u, N);
			addans(i, u);
		}
	}
	if(pa != -1) talk_tae(pa);
}

std::vector<std::vector<int> > recover_map(int N, int M, int Q){
	solve(0, -1, N);

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