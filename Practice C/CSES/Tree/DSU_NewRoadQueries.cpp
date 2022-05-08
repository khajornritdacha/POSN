#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int pa[N],sz[N],n,m,Q,we[N];

///Union by rank to maintain original tree shape
///The answer is the minimum day(weight) of edge required to jump into the same node.

int fi(int x){
    while(pa[x] != -1)
        x = pa[x];
    return x;
}

void uni(int u, int v, int w){
    int hu = fi(u), hv = fi(v);
    if(hu == hv) return;
    if(sz[hu] < sz[hv]) swap(hu, hv);
    pa[hv] = hu;
    sz[hu] += sz[hv];
    we[hv] = w;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        pa[i] = -1;
    }
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        uni(u, v, i);
    }

    if(DEBUG){
        cout << "PA\n";
        for(int i=1; i<=n; i++){
            cout << pa[i] << " ";
        }
        cout << "\n--------------\n";
        cout << "WE\n";
        for(int i=1; i<=n; i++){
            cout << we[i] << " ";
        }
        cout << "\n--------------\n";
    }

    for(int i=1; i<=Q; i++){
        int u,v;
        cin >> u >> v;
        if(u == v){
            cout << "0\n";
        }else if(fi(u) != fi(v)){
            cout << "-1\n";
        }else{
            int l=0, r=m, ans = -1;
            while(l <= r){
                int mid = (l+r)/2;
                int nu = u, nv = v;
                while(pa[nu] != -1 and we[nu] <= mid) nu = pa[nu];
                while(pa[nv] != -1 and we[nv] <= mid) nv = pa[nv];

                if(nu == nv){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            cout << ans << "\n";
        }
    }
}
