#include "lingling.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+10;

int n, arr[MXN], cnt[MXN];
long long ans = -1;

long long cnt_inversion(int l, int r) {
  if (l == r) return 0;
  int mid = (l+r)/2;
  long long res = cnt_inversion(l, mid) + cnt_inversion(mid+1, r);

  int i = l, j = mid+1, k = 0;
  int tmp[(r-l+1)] = {};
  while (i <= mid and j <= r) {
    if (arr[j] < arr[i]) {
      res += mid-i+1;
      tmp[k++] = arr[j];
      j++;
    } else {
      tmp[k++] = arr[i];
      i++;
    }
  }

  while (i <= mid) tmp[k++] = arr[i++];
  while (j <= r) tmp[k++] = arr[j++];

  for (int pt = 0, pa = l; pa <= r; pa++, pt++) {
    arr[pa] = tmp[pt];
  }

  return res;
}


void init_monkeys(std::vector<int> P, int Q){
  n = P.size();
  bool dup = false;
  for (int i = 1; i <= n; i++) {
    arr[i] = P[i-1];
    if (cnt[arr[i]]) {
      dup = true;
    }
    cnt[arr[i]] = true;
  }

  if (!dup)
    ans = cnt_inversion(1, n);

  // cout << ans << "\n";
}

long long minimum_branches(int L, int R){
  return ans;
}