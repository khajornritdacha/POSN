#include "manhattan.h"
#include <bits/stdc++.h>
using namespace std;


long long minimum_capacity(int N, int M, int G, int L, std::vector<int> x,
                           std::vector<int> y, std::vector<int> u,
                           std::vector<int> v, std::vector<int> w,
                           std::vector<int> g, std::vector<int> l) {

  if (L <= 1) {
    long long ans = 0;
    for (int i = 0; i < M; i++) {
      ans += w[i];
    }
    return ans;
  } else {
    return -1;
  }

  assert(0);

  return 0ll;
}