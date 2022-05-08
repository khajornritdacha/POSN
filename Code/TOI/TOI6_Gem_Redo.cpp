#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

const int N = 4e5+5;

int ti,scc_num,n,m,low[N],scc_id[N],id[N];
bitset<N> in_st;
stack<int> st;
vector<int> G[N];

void SCC(int u){
	low[u] = id[u] = ++ti;
	in_st[u] = true;
	st.push(u);
	for(int v : G[u]){
		if(!id[v]) SCC(v);
		if(in_st[v]) low[u] = min(low[u], low[v]);
	}
	if(low[u] == id[u]){
		scc_num++;
		while(true){
			int now = st.top(); st.pop();
			scc_id[now] = scc_num;
			in_st[now] = false;
			if(now == u) break;
		}
	}
	return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 5;
	while(t--){
        ti = scc_num = 0;
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            int x, y; cin >> x >> y; /// p v q
            G[x+m].push_back(y); ///!p -> q
            G[y+m].push_back(x); ///!q -> p
        }

        for(int i = 1, lim = m/2; i <= lim; i++){
            int x, y; cin >> x >> y; ///if x then !y or if y then !x
            G[x].push_back(y+m);
            G[y].push_back(x+m);
        }

        for(int i = 1, lim = 2*m; i <= lim; i++){
            if(!id[i]) SCC(i);
        }

        bool ans = true;
        for(int i = 1; i <= m; i++){
            if(scc_id[i] == scc_id[i+m]) ans = false;
        }

        if(ans) cout << "Y";
        else cout << "N";

        if(DEBUG){
            cout << "Choose\n";
            vector<bool> assignment(m+1);
            for(int i = 1; i <= m; i++){
                assignment[i] = (scc_id[i] < scc_id[i+m]); ///i = true if and only if !i -> i( topo_order(!i) > topo_order(i) )
                cout << "I " << i << " = " << assignment[i] << "\n";
            }
        }

        for(int i = 0, lim = 2*m; i <= lim; i++){
            G[i].clear();
            scc_id[i] = low[i] = id[i] = in_st[i] = 0;
        }
	}

	return 0;
}
