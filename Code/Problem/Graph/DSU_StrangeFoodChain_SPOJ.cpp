#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 5e4+10, INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int cp[N],n,m,pa[N],ch[N],hu[3],hv[3];

//https://www.spoj.com/problems/CHAIN/
//look at graph as 3 nodes A to B and B to C and C to A
//to join 2 nodes together if we said that u and v belong to the same group then we should connect u, v together and ch[u], ch[v] together and pa[u], pa[v] together
//if it contradicts then this query is false

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

int joi(int u, int v){
    if(u == -1 and v == -1) return -1;
    if(u != -1 and v != -1){
        cp[v] = u; //1st wrong spot 
        return u;
    }
    if(u != -1) return u;
    if(v != -1) return v;
    return -1;
}

bool uni(){
    if(DEBUG){
        cout << "Chk cycle\n";
        cout << hu[0] << " " << hu[1] << " " << hu[2] << "\n";
        cout << hv[0] << " " << hv[1] << " " << hv[2] << "\n";
    }

    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++){
        if(i == j or hu[i] == -1 or hv[j] == -1) continue;         
        if(hu[i] == hv[j]) return false;
    }

    

    int h[3] = {};
    for(int i = 0; i < 3; i++){
        h[i] = joi(hu[i], hv[i]);
    }

    if(h[0] != -1){
        pa[h[0]] = h[2], ch[h[0]] = h[1];
    }
    if(h[1] != -1){
        pa[h[1]] = h[0], ch[h[1]] = h[2];
    }
    if(h[2] != -1){
        pa[h[2]] = h[1], ch[h[2]] = h[0];
    }

    return true;
}

void test_case(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cp[i] = i;
        pa[i] = ch[i] = -1;
    }

    int wro = 0;
    for(int i = 1; i <= m; i++){
        int cd, u, v; cin >> cd >> u >> v;
        if(u > n or v > n){
            wro++;
        } else {
            int res = 0;
            u = fi(u), v = fi(v);
            if(cd == 1){
                hu[0] = u, hu[1] = ch[u], hu[2] = pa[u];
                hv[0] = v, hv[1] = ch[v], hv[2] = pa[v];
                res = uni();
            } else {
                hu[0] = u, hu[1] = ch[u], hu[2] = pa[u]; //2nd wrong spot -> can't change any of these orders
                hv[0] = pa[v], hv[1] = v, hv[2] = ch[v]; //since we define h[0] as the current and h[1] as the child of h[0]
                res = uni(); //if u eats v then join u with pa[v], join ch[u] with v, join pa[u] with ch[v]
            }
            wro += (1-res);

            if(DEBUG){
                cout << "RESULT : " << res << "\n";
                u = fi(u), v = fi(v);
                cout << u << " " << pa[u] << " " << ch[u] << "\n";
                cout << v << " " << pa[v] << " " << ch[v] << "\n";
                cout << "\n";
            }
        }
    }
    cout << wro << "\n";
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }    
    return 0;
}
