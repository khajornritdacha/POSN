#include "compatibility.h"
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


ll get_ans(int i, int j, ll n, const vector<vector<ll>> &max_point, const vector<ll> &sum) {
  ll res = sum[i] + sum[j] - 2ll*(n-1)*(max_point[i][j]);
  return res;
}

long long maximum_incompatibility(std::vector<std::vector<int>> A) {
  ll n, m;
  vector<ll> sum;
  vector<vector<ll>> max_point;
  
  m = A.size();
  n = A[0].size();

  if (n == 1) return 0;
  
  sum.resize(m, 0);
  max_point.resize(m, vector<ll>(m));

  for (int i = 0; i < m; i++) {
    sum[i] = 1ll*A[i][0] + A[i][n-1];
    for (int j = 1; j < n-1; j++) {
      sum[i] += 2ll*A[i][j];
    }
  }

  for (int i = 0; i < m; i++) for (int j = i+1; j < m; j++) for (int k = 0; k < n; k++) {
      max_point[i][j] = max(max_point[i][j], 1ll*A[i][k]+A[j][n-k-1]);
  }
  

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      ans = max(ans, abs(get_ans(i, j, n, max_point, sum)));
    }
  }
  return ans;
}
