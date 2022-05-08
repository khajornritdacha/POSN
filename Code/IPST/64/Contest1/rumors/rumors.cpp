#include "rumors.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2010;
using pi = pair<int, int>;

int tr[MXN][MXN], ms[MXN][MXN];
vector<pi> ord[MXN];

inline int bs(int loc, int val){
  int l = 0, r = (int)ord[loc].size()-1, res = 1;
  while(l <= r){
    int mid = (l+r)>>1;
    if(val >= ord[loc][mid].first){
      res = ord[loc][mid].second;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  return res;
}

vector<int> analyze_rumors(int N, int K, int Q, vector<int> d, vector<int> x, vector<int> j) {
  vector<int> ans(Q);

  for(int l = 0; l < N; l++){
    for(int r = l+1; r < N; r++){
      tr[l][r] = tr[l][r-1] + (d[r]-d[r-1]-1)/K;
    }
  }

  for(int sz = 1; sz <= N; sz++){
    deque<pi> dq;
    for(int l = 0, r = sz-1; l < N; l++, r++){
      while(!dq.empty() and dq.front().second < l) dq.pop_front();
      while(!dq.empty() and r < N and dq.back().first >= tr[l][r]) dq.pop_back();
      dq.emplace_back(tr[l][r], r);
      ms[l][sz] = dq.front().first;
    }
  }

  // cout << "TR\n";
  // for(int l = 0; l < N; l++){
  //   for(int r = 0; r < N; r++){
  //     cout << tr[l][r] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  // cout << "ML\n";
  // for(int i = 0; i < N; i++){
  //   cout << "I " << i << " : ";
  //   for(int sz = 1; sz <= N; sz++){
  //     cout << ms[i][sz] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  for(int i = 0; i < N; i++){
    int pre = 1e9;
    for(int sz = N; sz >= 1; sz--){
      if(ms[i][sz] < pre){
        pre = ms[i][sz];
        ord[i].emplace_back(ms[i][sz], sz);
      }
    }
    reverse(ord[i].begin(), ord[i].end());
    // cout << "I : " << i << "\n";
    // for(auto [spend, get] : ord[i]){
    //   cout << spend << " " << get << "\n";
    // }
    // cout << "\n";
  }

  for(int q = 0; q < Q; q++){
    int k = bs(x[q], j[q]);
    ans[q] = k;
  } 

  return ans;
}
