#include "die.h"
#include <bits/stdc++.h>
using namespace std;


const int N = 1010;

bool vi[N];
int dp[N], clg[N], bl[N];


void add(string &ans, char x, int t) {
  for (int i = 0; i < t; i++) ans.push_back(x);
}


void solve(string &ans, int a, int lv) {
  add(ans, '+', a);
  if (lv == 1) {
    return;
  }
  ans += "[>";
  solve(ans, a, lv-1);
  ans += "<-]";
}

int get_log(int C, int a) {
    int res = 0;
    while (C > 1) {
        C /= a;
        res++;
    }
    return res;
}

int get_pw(int base, int p) {
  int res = 1;
  while (p--) {
    res *= base;
  }
  return res;
}


int cal(int i) {
  if (vi[i]) return dp[i];
  vi[i] = true;

  for (int k = 2; k < i; k++) {
    int log = get_log(i, k);
    int pw = get_pw(k, log);
    if (pw > i) log--;
    pw = get_pw(k, log);

    int tmp = (k+6)*log-6 + cal(i-pw) + bl[i-pw]-1;
    // cout << k << " " << tmp << "\n";
    if (tmp < dp[i]) {
      dp[i] = tmp;
      bl[i] = k;
      clg[i] = log;
    }
  }
  return dp[i];
}

string A(int T, int C) {
  string ans;

  for (int i = 0; i <= C; i++) dp[i] = i, vi[i] = 0;

  cal(C);

  cout << "DP : " << dp[C] << "\n";


  // if (a == 1) {
  //   add(ans, '+', C);
  // } else {
  //   solve(ans, a, clog);
  //   add(ans, '>', clog-1);
  //   add(ans, '+', C-get_pw(a, clog));
  // }


  // cout << "A = " << a << "\n";
  // cout << "LOG = " << clog << "\n";
  // cout << "ANS: " << ans << "\n";



  return ans;

}
