#include "tnt.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll T = 1;

bool ask(vector<int> vec) {
    T++;
    return find_tnt(vec);
}

int add(ll a, ll b, int mod) {
    return (a+b)%mod;
}

int solve(int cl, int cr, int a) {
    // cout << cl << " " << cr << " " << l << " " << r << "\n";
    if (cl+1 == cr) {
        if (ask( {add(a, T*cl, n)} ) == true) 
            return cl;
        return -1;
    }

    vector<int> qq;
    set<int> tmp;
    int midc = (cl+cr)/2;
    for (int i = cl; i < midc; i++) {
        tmp.insert((a+i*T)%n);
    }
    for (int k : tmp) qq.emplace_back(k);

    int res = ask(qq);
    if (res == true) {
        return solve(cl, midc, a);
    } else {
        return solve(midc, cr, a);
    }

}


vector<int>find_truck(int N) {
    n = N;

    for (int a = 0; a < N; a++) {
        int res = solve(0, n, a);
        if (res != -1 and ask({ add(a, T*res, n) }) == true) {
            return {a, res};
        }
    }

    return {};
}
