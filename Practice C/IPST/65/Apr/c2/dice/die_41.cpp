#include "die.h"
#include <bits/stdc++.h>
using namespace std;



void add(string &ans, char x, int t) {
  for (int i = 0; i < t; i++) ans.push_back(x);
}


string A(int T, int C) {
  int sq = sqrt(C);
  string ans;


  add(ans, '+', sq);
  ans += "[>";
  add(ans, '+', sq);
  ans += "<-]";
  ans += ">";

  int cur = sq*sq;
  while (cur < C) {
    ans.push_back('+');
    cur++;
  }

  if (ans.size() > C) {
    ans.clear();
    add(ans, '+', C);
  }

  return ans;

}
