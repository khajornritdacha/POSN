#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int n,m,Q,ans[N],pa[N];
vector<pi> edge(N),qq(N),bi(N);
vector<int> event[N];
///Parallel B search
///https://cses.fi/problemset/task/2101/
int fi(int x){
    return pa[x] = (pa[x] == x ? x : fi(pa[x]));
}

void uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return;
    pa[u] = v;
}

main(){
    cin >> n >> m >> Q;
    for(int i=1; i<=m; i++){
        cin >> edge[i].first >> edge[i].second;
    }

    for(int i=1; i<=Q; i++){
        cin >> qq[i].first >> qq[i].second;
        ans[i] = -1;
        bi[i] = {0, m};
    }


    while(true){
        bool ch = false;
        for(int i=1; i<=Q; i++){
            if(bi[i].first > bi[i].second) continue;
            ch = true;
            event[(bi[i].first+bi[i].second)/2].emplace_back(i);
            //cout << "I : " << i << " " << bi[i].first << " " << bi[i].second << "\n";
        }
        if(!ch) break;
        for(int i=1; i<=n; i++){
            pa[i] = i;
        }
        for(int i=0; i<=m; i++){
            if(i != 0 ) uni(edge[i].first, edge[i].second);
            for(int idx : event[i]){
                if(fi(qq[idx].first) == fi(qq[idx].second)){
                    ans[idx] = i;
                    bi[idx].second = i-1;
                }else{
                    bi[idx].first = i+1;
                }
            }
            event[i].clear();
        }
    }

    for(int i=1; i<=Q;  i++){
        cout << ans[i] << "\n";
    }
}
