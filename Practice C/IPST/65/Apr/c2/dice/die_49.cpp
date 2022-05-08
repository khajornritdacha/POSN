#include "die.h"
#include <bits/stdc++.h>
using namespace std;



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


string A(int T, int C) {
  string ans;

  int mn = C;
  int a = 1;
  int clog = -1;

  for (int k = 2; k < C; k++) {
    int log = get_log(C, k);
    int pw = get_pw(k, log);
    if (pw > C) log--;
    pw = get_pw(k, log);

    int tmp = (k+6)*log-6 + C-pw;
    // cout << k << " " << tmp << "\n";
    if (tmp < mn) {
      mn = tmp;
      a = k;
      clog = log;
    }
  }


  if (a == 1) {
    add(ans, '+', C);
  } else {
    solve(ans, a, clog);
    add(ans, '>', clog-1);
    add(ans, '+', C-get_pw(a, clog));
  }


  // cout << "A = " << a << "\n";
  // cout << "LOG = " << clog << "\n";
  // cout << "ANS: " << ans << "\n";



  return ans;

}
