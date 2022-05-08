#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using tu = tuple<int,int,int>;

ll n,Q,mx,pa[N],ch[N][110],qs[N][110],a[N],ans[N];
ll res;
vector<pair<int,int>> qq;
vector<tu> edge;

///https://www.hackerrank.com/contests/crack-n-code-october-2021/challenges/cheat-2/problem

int fi(int x){
    return pa[x] = (pa[x] == x ? x : fi(pa[x]));
}

void uni(int u, int v){
    int hu = fi(u), hv = fi(v);
    for(int i = 1; i <= mx; i++){
        res -= 1ll*ch[hv][i]*(qs[hv][mx]-qs[hv][i]);
        res -= 1ll*ch[hu][i]*(qs[hu][mx]-qs[hu][i]);
    }
    for(int i = 1; i <= mx; i++){
        ch[hv][i] += ch[hu][i];
        qs[hv][i] = qs[hv][i-1]+ch[hv][i];
    }
    for(int i = 1; i <= mx; i++){
        res += 1ll*ch[hv][i]*(qs[hv][mx]-qs[hv][i]);
    }
    pa[hu] = hv;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pa[i] = i;
        ch[i][a[i]] = 1;
        mx = max(mx, a[i]);
    }

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= mx; k++){
            qs[i][k] = qs[i][k-1]+ch[i][k];
        }
    }

    for(int i = 0; i < n-1; i++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    for(int i = 1; i <= Q; i++){
        int x;
        cin >> x;
        qq.emplace_back(x, i);
    }
    sort(qq.begin(), qq.end());

    int ei = 0;
    for(auto [t, idx] : qq){

        while(ei <= n-2 and get<0>(edge[ei]) <= t){
            auto [w, u, v] = edge[ei++];
            uni(u, v);
        }

        ans[idx] = res*2;
    }

    for(int i = 1; i <= Q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
