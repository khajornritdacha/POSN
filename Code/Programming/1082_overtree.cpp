#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,m,p[100005];
vector<tuple<int,int,int>> vec;
vector<pi> ans;
int fi(int x){
    if(p[x]!=x) return p[x]=fi(p[x]);
    return x;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec.emplace_back(w,u,v);
    }
    for(int i=1;i<=n;i++)
        p[i]=i;
    sort(vec.begin(),vec.end());
    for(int i=0;i<m;i++){
        int w,u,v;
        tie(w,u,v)=vec[i];
        int hu=fi(u);
        int hv=fi(v);
        if(hv!=hu){
            p[hu]=hv;
            ans.emplace_back(u,v);
        }
    }
    for(auto x:ans)
        cout << x.first << " " << x.second << "\n";
}
