#include <stdio.h>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+10, INF = 1e9+10;

using tu = tuple<int, int, int>;

vector<int> dis, st, G[MXN];
multiset<tu> panda;

void initialize(int N,int M,int S,std::vector<std::vector<int> >R)
{
    for(int i = 0; i < M; i++){
        int u = R[i][0], v = R[i][1];
        u++, v++;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dis.resize(N+5, INF);
    st.resize(N+5, 0);
    queue<int> qq;
    for(int i = 1; i <= S+1; i++){
        st[i] = i;
        dis[i] = 0;
        qq.emplace(i);
    }

    while(!qq.empty()){
        int u = qq.front(); qq.pop();
        for(int v : G[u]){
            if(!st[v]){
                st[v] = st[u];
                dis[v] = dis[u]+1;
                qq.emplace(v);
            }
        }
    }

    // cout << "PrecalPASS\n";
    // for(int i = 1; i <= N; i++){
    //     cout << "I " << i << " = " << st[i] << " " << dis[i] << "\n";
    // }
    // cout << "\n";


}
void panda_spawn(int P,int L,int X)
{
    X++;
    panda.insert({P, L, X});
}

void panda_evac(int P,int L,int X)
{
    X++;
    panda.erase(panda.find({P, L, X}));
}

int travel(int A,int B)
{
    A++, B++;
    if(A > B) swap(A, B);
    assert(A == B);
    int ans = -INF;
    for(auto [P, L, X] : panda){
        ans = max(ans, P-L*(dis[X]+abs(st[X]-A)));
        // cout << "PANDA : " << P << " " << L << " " << X << "\n";
    }

    // cout << "TRAVEL " << A << " " << B << " = " << ans << "\n";
    return ans;
}

#ifdef LOCAL
int main(void){
    int n, m, S, Q; cin >> n >> m >> S >> Q;
    vector<vector<int>> R;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        vector<int> vec = {u, v};
        R.emplace_back(vec);
    }
    initialize(n, m, S, R);

    for(int q = 1; q <= Q; q++){
        int op; cin >> op;
        if(op == 1){
            int P, L, X; cin >> P >> L >> X;
            panda_spawn(P, L, X);
        } else if(op == 2){
            int P, L, X; cin >> P >> L >> X;
            panda_evac(P, L, X);
        } else {
            int A, B; cin >> A >> B;
            cout << travel(A, B) << "\n";
        }
    }

    return 0;
}
#endif