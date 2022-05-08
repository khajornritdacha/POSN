#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using tu = tuple<int,int,int>;
int n,p[N],ans;
map<int, vector<tu>> st,ed;
///https://www.spoj.com/problems/LEGO/
int fi(int x){
    return p[x] = (p[x] == x ? x : fi(p[x]));
}

void uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return;
    p[u] = v;
    ans--;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        st[y1].emplace_back(x1, x2, i);
        ed[y2].emplace_back(x1, x2, i);
        p[i] = i;
    }
    ans = n;

    for(auto [key, val] : st){
        if(ed.find(key) == ed.end()) continue;
        vector<tu> dow = ed[key];
        sort(val.begin(), val.end());
        sort(dow.begin(), dow.end());
        int j=0;
        for(int i=0; i<val.size() and j<dow.size(); i++){
            int ns,ne, idx;
            tie(ns, ne, idx) = val[i];
            while(j < dow.size() and get<0>(dow[j]) <= ne){
                if(min(ne, get<1>(dow[j]))-max(ns, get<0>(dow[i])) > 0){
                    //cout << "UNI : " << idx << " " << (get<2>(dow[j])) << "\n";
                    uni(idx, get<2>(dow[j]));
                }
                j++;
            }
        }
    }
    cout << ans;
}


