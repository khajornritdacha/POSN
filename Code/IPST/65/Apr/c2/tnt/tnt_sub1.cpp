#include "tnt.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T = 1;

bool ask(vector<int> vec) {
    T++;
    return find_tnt(vec);
}

int add(ll a, ll b, int mod) {
    return (a+b)%mod;
}

vector<int>find_truck(int N) {
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            int res = ask({add(a, 1ll*T*b, N)});
            if (res == true and ask({add(a, 1ll*T*b, N)}) == true) {
                return {a, b};
            }
        }
    }
    assert(0);
    return {};
}
