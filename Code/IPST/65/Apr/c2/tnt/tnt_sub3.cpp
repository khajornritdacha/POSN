#include "tnt.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll T = 1;
vector<int> rA;

bool ask(vector<int> vec) {
    T++;
    return find_tnt(vec);
}

int add(ll a, ll b, int mod) {
    return (a+b)%mod;
}

int solve(int cl, int cr, ll l, ll r) {
    // cout << cl << " " << cr << " " << l << " " << r << "\n";
    if (cl+1 == cr) {
        if (ask( {T*cl%n} ) == true) 
            return cl;
        return -1;
    }

    vector<int> qq;
    int midc = (cl+cr)/2;
    for (int i = cl; i < midc; i++) {
        qq.emplace_back(i*T%n);
    }

    int res = ask(qq);
    if (res == true) {
        if (cl == 0 and cr == n) rA = {cl, midc};
        return solve(cl, midc, cl*T, midc*T);
    } else {
        if (cl == 0 and cr == n) rA = {midc, cr};
        return solve(midc, cr, midc*T, cr*T);
    }

}

int findA(int l, int r) {
    if (l+1 == r) return l;
    int mid = (l+r)>>1;
    vector<int> qq;
    for (int i = l; i < mid; i++) {
        qq.emplace_back(i);
    }

    int res = ask(qq);
    if(res == true) {
        return findA(l, mid);
    } else {
        return findA(mid, r);
    }
}

vector<int>find_truck(int N) {
    n = N;
    int res = solve(0, n, 0, n);

    if (res == -1) {
        // cout << "rA : ";
        // for (int v : rA) cout << v << " ";
        // cout << "\n";
        res = findA(rA[0], rA[1]);
        return {res, 0};
    } else {
        return {0, res};
    }

    return {};
}
