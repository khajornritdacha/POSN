#include <bits/stdc++.h>
#include "dreaming.h"
using namespace std;

const int MXN = 1e5+10;
using pi = pair<int,int>;

int best,mx[MXN][2],dps[MXN],dpp[MXN],fr[MXN],pos;
bool vi[MXN];
vector<pi> G[MXN];

///https://oj.uz/problem/view/IOI13_dreaming

void dfs1(int u, int p){
    vi[u] = true;
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dfs1(v, u);
        dps[u] = max(dps[u], dps[v]+w);

        int tmp = dps[v]+w, node = v;
        if(tmp > mx[u][0]){
            swap(tmp, mx[u][0]);
            swap(fr[u], node);
        }
        if(tmp > mx[u][1]){
            swap(tmp, mx[u][1]);
        }
    }
}

void dfs2(int u, int p, int code = 0){
    if(code){
        best = max(best, dps[u]+dpp[u]);
    }else{
        if(max(dps[u], dpp[u]) < best){
            best = max(dps[u], dpp[u]);
            pos = u;
        }
    }
    for(auto [v, w] : G[u]){
        if(v == p) continue;

        if(v != fr[u]){
            dpp[v] = max(dpp[u], mx[u][0])+w;
        }else{
            dpp[v] = max(dpp[u], mx[u][1])+w;
        }

        dfs2(v, u, code);
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for(int i = 0; i < M; i++){
        G[A[i]+1].emplace_back(B[i]+1, T[i]);
        G[B[i]+1].emplace_back(A[i]+1, T[i]);
    }

    vector<pi> res;
    for(int i = 1; i <= N; i++){
        if(!vi[i]){
            best = 2e9, pos = -1;
            dfs1(i, 0);
            dfs2(i, 0);
            res.emplace_back(best, pos);
        }
    }

    sort(res.rbegin(), res.rend());
    /*for(auto [val, idx] : res){
        cout << val << " " << idx << "\n";
    }*/
    for(int i = 1; i < res.size(); i++){
        G[res[i].second].emplace_back(res[0].second, L);
        G[res[0].second].emplace_back(res[i].second, L);
    }

    for(int i = 0; i <= N; i++){
        mx[i][0] = mx[i][1] = dps[i] = dpp[i] = fr[i] = 0;
    }

    best = 0;
    dfs1(1, 0);
    dfs2(1, 0, 1);

    return best;
}
/*
int main(void){
    int N,M,L;
    cin >> N >> M >> L;
    int A[M], B[M], T[M];
    for(int i = 0; i < M; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    for(int i = 0; i < M; i++){
        cin >> T[i];
    }
    cout << travelTime(N, M, L, A, B, T) << "\n";
    return 0;
}*/
