#include "colorful.h"
#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> tu;
const int MXN = 5e4+10, MXK = 400, LOG = 60;

int oK;
ll pw[LOG];
vector<int> G[MXN];
vector<int> prime;
bitset<MXN> chk;

int go[MXN][MXK];
map< tu, int > vi;


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

ll sub(ll a, ll b) {
    return ((a-b)%oK+oK)%oK;
}

int cal(int u, int c, int k) {
    if (k == 0) return go[u][c];
    tu cur = {u, c, k};
    if (vi[cur] != 0) return vi[cur];
    return vi[cur] = cal(cal(u, c, k-1), (c+pw[k-1])%oK, k-1);
}

void init_machine(int N, int M, int K, int Q, std::vector<int> x, std::vector<int> y){
    assert(N <= 5e4 and M <= 2e5 and K <= 400 and Q <=2e5);

    gen_prime(K);
    oK = K;
    pw[0] = 1;
    for (int i = 1; i < LOG; i++) pw[i] = (pw[i-1]*2ll)%K;

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
            if (mn == -1) {
                go[i][c] = i;
            } else {
                go[i][c] = mn;
            }
        }
    }

    // for (int k = 1; k < LOG; k++) {
    //     for (int u = 1; u <= N; u++) {
    //         for (int c = 0; c < K; c++) {
    //             go[u][c][k] = go[go[u][c][k-1]][(c+pw[k-1])%oK][k-1];
    //         }
    //     }
    // }

    
}

int send_ball(int c, int s, long long t){
    int u = s, co = c;
    ll lt = t;
    for (int k = LOG-1; k >= 0; k--) {
        if (lt-(1ll<<k) >= 0) {
            lt -= (1ll<<k);
            u = cal(u, co, k);
            co = (co+pw[k])%oK;
        }
    }
    return u;
}

