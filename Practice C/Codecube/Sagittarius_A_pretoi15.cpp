#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int V,E,t,cnt,p[100005];
ll mst;
bool cd;
vector<pair<pi,pi>> vec;
vector<int> ans;
int fi(int now){
    if(p[now]!=now)
        return p[now]=fi(p[now]);
    return p[now]=now;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1;i<=V;i++)
        p[i]=i;
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec.push_back({{w,i},{u,v}});
    }
    cin >> t;
    sort(vec.rbegin(),vec.rend());
    for(auto x:vec){
        int w=x.first.first,i=x.first.second,u=x.second.first,v=x.second.second;
        int hu=fi(u);
        int hv=fi(v);
        if(p[hu]!=p[hv]){
            cnt++;
            mst+=w;
            ans.push_back(i);
            p[hu]=hv;
        }else if(cd==0){
            cnt++;
            mst+=w;
            cd=1;
            ans.push_back(i);
        }
    }
    if(cnt==V){
        cout << mst << "\n";
        if(t==2){
            for(auto x:ans)
                cout << x << " ";
        }
    }else{ cout << "-1";}
}
