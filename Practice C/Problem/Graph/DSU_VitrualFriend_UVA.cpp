#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int t,m,p[100010],ra[100010],sz[100010],idx;
string str,str2;
map<string,int> mp;
vector<pi> vec;
int fi(int x){
    if(p[x]==x)
        return x;
    return p[x]=fi(p[x]);
}
void uni(int u, int v){
    u=fi(u);
    v=fi(v);
    if(u!=v){
        if(ra[u]<ra[v])
            swap(u,v);
        p[v]=u;
        sz[u]+=sz[v];
        if(ra[u]==ra[v])
            ra[u]++;
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        idx=0;
        cin >> m;
        for(int i=1; i<=m; i++){
            cin >> str >> str2;
            if(mp[str]==0)
                mp[str]=++idx;
            if(mp[str2]==0)
                mp[str2]=++idx;
            vec.emplace_back(mp[str],mp[str2]);
        }
        for(int i=1; i<=idx; i++){
            p[i]=i;
            ra[i]=0;
            sz[i]=1;
        }
        for(int i=0; i<vec.size(); i++){
            int u,v;
            tie(u,v) = vec[i];
            uni(u,v);
            u=fi(u);
            cout << sz[u] << "\n";
        }
        vec.clear();
        mp.clear();
    }
}
