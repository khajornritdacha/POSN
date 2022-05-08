#include "onepath.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <utility>

static int n, m, q;
static std::vector<std::pair<int, int>> r;
static std::vector<int> t;
static std::vector<std::pair<int, int>> f;

int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  assert(std::cin >> n >> m >> q);
  for (int i = 0, u, v; i < m; ++i) {
    assert(std::cin >> u >> v);
    r.emplace_back(u, v);
  }
  initialize(n, m, q, r);

  while (q--) {
    int x, y, z;
    assert(std::cin >> x >> y >> z);
    if (x == 1) {
      bool ans = is_dangerous(y, z);
      std::cout << (ans ? "true" : "false") << std::endl;
    } else {
      build_road(y, z);
    }

  }

  // for (int i = 0, x, y, z; i < q; ++i) {
  //   t.emplace_back(x);
  //   f.emplace_back(y, z);
  // }
  // std::vector<bool> answer;
  // for (int i = 0; i < q; ++i) {
  // }
  // for (auto ans : answer) {
  //   std::cout << (ans ? "true" : "false") << std::endl;
  // }
}