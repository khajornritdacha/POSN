#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;
vector<pii> vec;
int V,E,p[200005],cnt;
long long ans;
int findh(int x){
    if(p[x]==x)
        return x;
    return p[x] = findh(p[x]);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec.push_back({w,{u,v}});
    }
    for(int i=1;i<=V;i++){
        p[i] = i;
    }
    sort(vec.begin(),vec.end(),greater<pii>());
    for(int i=0;i<vec.size();i++){
        int w = vec[i].first;
        int u = vec[i].second.first;
        int v = vec[i].second.second;
        int hu = findh(u),hv = findh(v);
        if(hu!=hv){
            p[max(hu,hv)] = min(hu,hv);
            ans+=w-1;
            cnt++;
        }
        if(cnt==V-1)
            break;
    }
    cout << ans;
}
