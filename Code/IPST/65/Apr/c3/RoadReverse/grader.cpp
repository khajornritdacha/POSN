#include "roadreverse.h"
#include <iostream>

static int N, M, K;
static std::vector<std::vector<int>> S;
static std::vector<std::pair<int,int>> R;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N >> M >> K;

  int rc = 0;
  for(int i=0; i<K; i++) {
    int l,u;
    std::cin >> l;
    std::vector<int> rr;
    
    for(int i=0; i<l; i++) {
      std::cin >> u;
      rr.push_back(u);
    }
    S.push_back(rr);
    rc += l;
  }
  int mleft = M - rc;
  for(int i=0; i<mleft; i++) {
    int u,v;
    std::cin >> u >> v;
    R.push_back(std::make_pair(u,v));
  }
  std::cout << count_roads(N,M,K,S,R) << std::endl;
}
