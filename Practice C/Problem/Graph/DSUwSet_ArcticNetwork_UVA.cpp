#include<bits/stdc++.h>
using namespace std;
using tu=tuple<int,int,int>;
int mx,V,S,p[510],ra[510],x[510],y[510],t;
set<int> ss;
vector<tu> vec;

int fi(int x){
    if(p[x]==x)
        return x;
    return p[x]=fi(p[x]);
}
bool uni(int u, int v){
    u=fi(u);
    v=fi(v);
    if(u!=v){
        if(ra[u]<ra[v])
            swap(u,v);
        p[v]=u;
        if(ra[u]==ra[v])
            ra[u]++;
        ss.erase(v);
        return true;
    }
    return false;
}
main(){
    cout << setprecision(2) << fixed;
    cin >> t;
    while(t--){
        mx=0;
        cin >> S >> V;
        for(int i=1; i<=V; i++){
            cin >> x[i] >> y[i];
            ss.insert(i);
            p[i]=i;
            ra[i]=0;
        }
        for(int i=1; i<=V; i++){
            for(int j=i+1; j<=V; j++){
                vec.emplace_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),i,j);
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<vec.size(); i++){
            int w,u,v;
            tie(w,u,v) = vec[i];
            if(uni(u,v))
                mx=max(mx,w);
            if(ss.size()==S)
                break;
        }
        cout << sqrt(mx) << "\n";
        vec.clear();
        ss.clear();
    }
}
