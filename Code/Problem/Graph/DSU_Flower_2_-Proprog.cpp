#include<bits/stdc++.h>
using namespace std;
int t,n,cmp,p[100100];
vector<pair<int,int>> vec,vec2;
int _fi(int x){
    if(p[x]==x) return p[x];
    return p[x]=_fi(p[x]);
}
void uni(int u, int v){
    int hu=_fi(u);
    int hv=_fi(v);
    if(hu!=hv){
        p[hu]=hv;
        cmp--;
        //cout << "Merge: " <<  u << " " << v << " " << vec[u].first << " " << vec2[u].first << " " << vec[v].first << " " << vec2[v].first << "\n";
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cmp=n;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            vec.emplace_back(x,i);
            vec2.emplace_back(y,i);
            p[i]=i;
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<n-1; i++){
            if(vec[i].first==vec[i+1].first)
                uni(vec[i].second,vec[i+1].second);
        }
        sort(vec2.begin(),vec2.end());
        for(int i=0; i<n-1; i++){
            if(vec2[i].first==vec2[i+1].first){
                uni(vec2[i].second,vec2[i+1].second);
            }
        }
        //cout << "CMP: " << cmp << " ";
        cout << ceil((double)cmp/2) << "\n";
        vec.clear();
        vec2.clear();
    }
}
