#include "inversion.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+10;
typedef long long ll;

int arr[MXN], n;

ll cnt_inversion(int l, int r) {
    if(l == r) return 0;
    int mid = (l+r)>>1;
    ll res = cnt_inversion(l, mid) + cnt_inversion(mid+1, r);

    int tmp[r-l+1] = {}, i = l, j = mid+1, k = 0;
    while(i <= mid and j <= r) {
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
    
    for (int pt = 0, pa = l; pa <= r; pt++, pa++) {
        arr[pa] = tmp[pt];
    }
    return res;
}

ll cnt_inversion(vector<int> vec) {
  for (int i = 0; i < n; i++) arr[i+1] = vec[i];
  return cnt_inversion(1, n);
}



vector<int> find_permutation(int N, long long inversion) {
  n = N;
  vector<int> vec(n);
  for (int i = 1; i <= n; i++) vec[i-1] = i;

  vector< pair<vector<int>, int> > cand;
  vector<vector<int>> act;
  int id = 0;
  do {
    ll res = cnt_inversion(vec);
    if (res == inversion) {
      cand.emplace_back(vec, id);
      act.emplace_back(vec);
      id++;
    }
  } while(next_permutation(vec.begin(), vec.end()));

  vector<pair<int, int>> swap_pos;
  for (int i = 0; i < n-1; i++) {
    swap_pos.emplace_back(i, n-1);
  }
  swap_pos.emplace_back(0, 1);

  for (int i = 0; i < n; i++) {
    ll new_inv = swap_and_report(swap_pos[i].first, swap_pos[i].second);

    vector< pair<vector<int>, int> > nxt;
    for (auto &[cur, idx] : cand) {
      swap(cur[swap_pos[i].first], cur[swap_pos[i].second]);
      ll cur_inv = cnt_inversion(cur);
      if (cur_inv == new_inv) {
        nxt.emplace_back(cur, idx);
      }
    }
    cand = nxt;
  }

  // cout << "Cand size: " << cand.size() << "\n";
  // for (auto [cur, idx] : cand) {
  //   for (int v : cur) {
  //     cout << v << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  // assert(cand.size() > 0);

  return act[cand[0].second];
}