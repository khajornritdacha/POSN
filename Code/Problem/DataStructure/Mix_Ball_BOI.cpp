//Task : BOI 13 Balls

//1st observation : operation 1 will not insert more than 1e5 balls
//2nd observation : operation 2 will change only 1 node, the node nearest to the root in path from u to root that has a ball

//priority := the order of nodes to be insert balls
//in operation 1, we can just add each ball individually in order of priority and answer the last ball
//in operation 2, just count the number of nodes that contain balls from u to root and remove a ball from the node that is k-th parent to u.
//Counting balls from u to root be done by range update and point query
//Find k-th parent of u can be done by binary lifting

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, LOG = 20;

using pi = pair<int, int>;

int mn[N], tin[N], tout[N], pri[N], pcnt, ti, pa[N][LOG+1], root, n, Q, fen[N];
vector<int> G[N];
priority_queue<pi, vector<pi>, greater<pi>> heap;

void pre(int u){
    mn[u] = u;
    tin[u] = ++ti;
    for(int v : G[u]){
        pre(v);
        mn[u] = min(mn[u], mn[v]);
    }
    tout[u] = ti;
}

void dfs1(int u){
    vector<pair<int, int>> vec;
    for(int v : G[u]){
        vec.emplace_back(mn[v], v);
    }
    sort(vec.begin(), vec.end());

    for(auto [val, v] : vec){
        dfs1(v);
    }

    pri[u] = ++pcnt;
}

int fipa(int u, int val){
    for(int k = LOG; k >= 0; k--){
        if((1<<k) <= val){
            u = pa[u][k];
            val -= (1<<k);
        }
    }
    return u;
}

void up(int idx, int val){
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

int sum(int idx){
    int res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> pa[i][0];
        if(pa[i][0] == 0) root = i;
        else G[pa[i][0]].emplace_back(i);
    }

    pre(root);
    dfs1(root);
    
    for(int k = 1; k <= LOG; k++) for(int i = 1; i <= n; i++) pa[i][k] = pa[pa[i][k-1]][k-1];
    for(int i = 1; i <= n; i++) heap.emplace(pri[i], i);

    // cout << "Priority : ";
    // for(int i = 1; i <= n; i++) cout << pri[i] << " ";
    // cout << "\n";

    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int k; cin >> k;
            for(int i = 1; i <= k; i++){
                auto [pp, u] = heap.top(); heap.pop();
                
                up(tin[u], 1);
                up(tout[u]+1, -1);
                
                if(i == k){ 
                    cout << u << "\n";
                }
            }
        } else if(op == 2){
            int x; cin >> x;
            int res = sum(tin[x])-1;
            int del = fipa(x, res);

            // cout << "RES : " << res << " " << del << "\n";

            up(tin[del], -1);
            up(tout[del]+1, 1);
            heap.emplace(pri[del], del);

            cout << res << "\n";

        }
    }


    return 0;
}