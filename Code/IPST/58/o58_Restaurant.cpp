#include<bits/stdc++.h>
using namespace std;
const int N = 3e2+10;
int n,T,a[N][N],cnt[N],p[N],sz[N];
vector<tuple<int,int,int>> edges;
int fi(int x){
    if(p[x] == x) return x;
    return p[x] = fi(p[x]);
}
bool uni(int u, int v){
    int hu = fi(u);
    int hv = fi(v);
    if(hu != hv){
        if(sz[hu] < sz[hv])
            swap(hu, hv);
        p[hv] = hu;
        cnt[u]++;
        cnt[v]++;
        if(sz[hu] == sz[hv])
            sz[hu]++;
    }
}
main(){
    cin >> n >> T;
    for(int i=1; i<=n; i++){
        p[i] = i;
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            if(i!=j)
                edges.emplace_back(a[i][j], i, j);
        }
    }
    sort(edges.begin(), edges.end());
    for(auto [w, u, v] : edges){
        uni(u,v);
    }
    int ans = max_element(cnt+1, cnt+n+1)-cnt;
    cout << ans << "\n";
    if(T == 2)
        cout << cnt[ans];
}
