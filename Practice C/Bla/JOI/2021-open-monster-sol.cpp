#include <bits/stdc++.h>

#include "monster.h"
using namespace std;

namespace {
mt19937 mt(0x0606);

vector<int> stupid(vector<int> v) {
  int N = v.size();
  vector<vector<bool>> res(N, vector<bool>(N, false));
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      res[j][i] = !(res[i][j] = Query(v[i], v[j]));
  vector<pair<int, int>> cnt(N);
  for (int i = 0; i < N; i++)
    cnt[i] = {count(res[i].begin(), res[i].end(), true), v[i]};
  sort(cnt.begin(), cnt.end());
  for (int i = 0; i < N; i++) v[i] = cnt[i].second;
  if (Query(v[1], v[0])) swap(v[0], v[1]);
  if (Query(v[N - 1], v[N - 2])) swap(v[N - 2], v[N - 1]);
  return v;
}

vector<int> merge_sort(vector<int> v) {
  if (v.size() == 1) return v;
  shuffle(v.begin(), v.end(), mt);
  int m = v.size() / 2;
  vector<int> l(v.begin(), v.begin() + m), r(v.begin() + m, v.end());
  l = merge_sort(l);
  r = merge_sort(r);

  int i = 0, j = 0;
  for (int k = 0; k < v.size(); k++) {
    if (i == l.size())
      v[k] = r[j++];
    else if (j == r.size())
      v[k] = l[i++];
    else if (Query(l[i], r[j]))
      v[k] = r[j++];
    else
      v[k] = l[i++];
  }
  return v;
}
}  // namespace

vector<int> Solve(int N) {
  vector<int> v(N);
  for (int i = 0; i < N; i++) v[i] = i;
  v = merge_sort(v);

  vector<int> s(v.begin(), v.begin() + min(10, N));
  s = stupid(s);
  int b = s[0];
  v.erase(find(v.begin(), v.end(), b));
  v.insert(v.begin(), b);

  for (int i = 1; i < N; i++) {
    int j = i;
    while (j < N && Query(v[j], b)) j++;
    reverse(v.begin() + i, v.begin() + min(j + 1, N));
    b = v[i = j];
  }

  vector<int> S(N);
  for (int i = 0; i < N; i++) S[v[i]] = i;
  return S;
}