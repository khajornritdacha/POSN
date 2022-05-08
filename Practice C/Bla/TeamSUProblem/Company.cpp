#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;

int lis[35], n, deg[N], sz, pr[N], H[N], T[N]; //Size of lis is guarateed to be O(logN)
queue<int> qq;
vector<int> G[N];

//https://codeforces.com/contestInvitation/cc9a1194c8b6698059d72976e7144991fac7fbe9

void ins(int idx, int val){ //every operation is O(logN) cuz it is a binary tree
    for(int i = sz; i >= idx; i--) lis[i+1] = lis[i];
    lis[idx] = val;
    H[val] = lis[idx-1]; //the current has to come after its Head
    T[val] = lis[idx+1]; //and it has to come before the tail its Tail
    sz++;
}

void rem(int val){
    int idx = -1;
    for(int i = 1; i <= sz; i++) if(lis[i] == val) idx = i;
    for(int i = idx; i <= sz; i++){
        lis[i] = lis[i+1];
    }
    sz--;
}

void dfs(int u){
    ins(sz-pr[u]+1, u);
    
    if(2*u <= n) dfs(2*u);
    if(2*u + 1 <= n) dfs(2*u+1);

    rem(u);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pr[i];
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        G[H[i]].emplace_back(i);
        deg[i]++;
        if(T[i] != 0){
            G[i].emplace_back(T[i]);
            deg[T[i]]++;
        }
    }

    vector<int> order;
    qq.emplace(0);
    while(!qq.empty()){ //perform topo to get exact order of ans
        int u = qq.front(); qq.pop();
        
        if(u != 0) order.emplace_back(u);
        
        for(int v : G[u]){
            if(--deg[v] == 0){
                qq.emplace(v);
            }
        }
    }

    for(int ans : order) cout << ans << " ";
    cout << "\n";

    return 0;
}