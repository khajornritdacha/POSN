#include "compatibility.h"
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll n, m;
vector<ll> sum;
vector<vector<ll>> max_point;
vector<bool> inc;

ll get_ans(int i, int j) {
  ll res = sum[i] + sum[j] - 2ll*(n-1)*(max_point[i][j]);
  return res;
}

long long maximum_incompatibility(std::vector<std::vector<int>> A) {
  
  m = A.size();
  n = A[0].size();

  if (n == 1) return 0;
  
  sum.resize(m, 0);
  max_point.resize(m, vector<ll>(m));
  inc.resize(m);

  for (int i = 0; i < m; i++) {
    sum[i] = A[i][0] + A[i][n-1];
    for (int j = 1; j < n-1; j++) {
      sum[i] += 2*A[i][j];
    }
    inc[i] = true;
    if (A[i][1] < A[i][0]) inc[i] = false;
  }

  for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) if (i != j) {
    ll tmp = 0;
    if (inc[i] ^ inc[j]) {
      if (inc[i] and !inc[j]) tmp = A[i][n-1] + A[j][0];
      else if (!inc[i] and inc[j]) tmp = A[i][0] + A[j][n-1];
    } else {
      ll m1 = A[i][1] - A[i][0];
      ll m2 = A[j][1] - A[j][0];
      ll dm = m1-m2;
      if (dm > 0) {
        tmp = A[i][n-1] + A[j][0];
      } else {
        tmp = A[i][0] + A[j][n-1];
      }
    }

    max_point[i][j] = tmp;
  }
  

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) continue;
      ans = max(ans, abs(get_ans(i, j)));
    }
  }
  return ans;
}
