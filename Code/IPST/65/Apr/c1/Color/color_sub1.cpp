#include "colorful.h"
#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int MXN = 5e4+10, MXK = 410;

int go[MXN][MXK], oK;
vector<int> G[MXN];
vector<int> prime;
bitset<MXN> chk;

void gen_prime(const int K) {
   for (int i = 2; i < MXN; i++) {
        if (chk[i]) continue;
        prime.emplace_back(i);
        if (int(prime.size()) == K) break;
        for (int j = i + i; j < MXN; j += i) {
            chk[j] = true;
        }
    }
}

void init_machine(int N, int M, int K, int Q, std::vector<int> x, std::vector<int> y){
    assert(N <= 5e4 and M <= 2e5 and K <= 400 and Q <=2e5);

    gen_prime(K);
    oK = K;
    // pw[0] = 1;
    // for (int i = 1; i <= K; i++) pw[i] = (pw[i-1]*2)%K;

    for (int i = 0; i < M; i++) {
        assert(x[i] >= 0 and x[i] <= N);
        assert(y[i] >= 0 and y[i] <= N);
        
        G[x[i]].emplace_back(y[i]);
        G[y[i]].emplace_back(x[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c < K; c++) {
            int mn = -1;
            for (int v : G[i]) {
                if (mn == -1 or v%prime[c] < mn%prime[c] or (v%prime[c] == mn%prime[c] and v < mn)) {
                    mn = v;
                }            
            }
            go[i][c] = mn;
        }
    }

    if (DEBUG) {
        cout << "PRECAL\n";
        for (int i = 1; i <= N; i++) {
            for (int c = 0; c < K; c++) {
                cout << go[i][c] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int send_ball(int c, int s, long long t){
    int u = s;
    // if (go[u][s] == -1) return u;
    while (t--) {
        if (go[u][c] == -1) return u;
        u = go[u][c];
        c = (c+1)%oK;
    }
    return u;
}

