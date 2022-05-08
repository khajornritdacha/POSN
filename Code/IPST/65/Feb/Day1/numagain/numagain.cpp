#include "numagain.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 1e9+7;
int cnt[N];
int ty;
vector<int> cur;

int solve(vector<int> &arr, int lv = 0){
    if(lv == arr.size()){
        if(cur.size() == 0) return 0;
        int mn = N, mx = -N;
        for(int v : cur){
            mn = min(mn, v);
            mx = max(mx, v);
        }
        return 1ll*(mx-mn)*ty%mod;
    }
    cur.emplace_back(arr[lv]);
    if(++cnt[arr[lv]] == 1) ty++;
    int res = solve(arr, lv+1);

    cur.pop_back();
    if(--cnt[arr[lv]] == 0) ty--;
    res = (res+solve(arr, lv+1))%mod;
    return res;
}

int find_ans(std::vector<int>number)
{
    int res = solve(number);
    return res;
}
