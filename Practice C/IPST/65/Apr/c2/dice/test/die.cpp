#include "die.h"
#include <bits/stdc++.h>
using namespace std;



void add(string &ans, char x, int t) {
  for (int i = 0; i < t; i++) ans.push_back(x);
}

string gen_str(int bs, int C) {
  string ans;

  add(ans, '+', bs);
  ans += "[>";
  add(ans, '+', bs);
  ans += "<-]";
  ans += ">";

  int cur = bs*bs;
  while (cur < C) {
    ans.push_back('+');
    cur++;
  }
  while (cur > C) {
      ans.push_back('-');
      cur--;
  }
  return ans;

}


string A(int T, int C) {
  int sq = sqrt(C);

  string res1 = gen_str(sq, C);
  string res2 = gen_str(sq+1, C);

  string ans = res1;
  if (res2.size() < ans.size()) swap(ans, res2);

  if (ans.size() > C) {
    ans.clear();
    add(ans, '+', C);
  }

  return ans;

}
