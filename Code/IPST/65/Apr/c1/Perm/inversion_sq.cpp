#include "inversion.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> find_permutation(int n, long long inversion) {
  ll cur = inversion;
  vector<int> gr(n+5), st_idx(n+5);
  for (int i = 0; i < n; i++) st_idx[i] = i;

  for (int round = 0; round < n; round++) {
    for (int i = n-1; i >= 1; i--) {
      ll res = swap_and_report(i, i-1);
      swap(st_idx[i], st_idx[i-1]);
      if (res > cur) {
        gr[st_idx[i-1]]++;
      }
      cur = res;
    } 
  }  
  
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = gr[i]+1;
    // cout << ans[i] << " ";
  }

  return ans;
}