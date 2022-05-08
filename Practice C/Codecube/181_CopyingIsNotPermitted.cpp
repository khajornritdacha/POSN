#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int cnt,n,m,p,l,r,mid;
vector<int> cmp,wei;
vector<pi> vec[40100],rela;
unordered_map<int,bool> ump;
void dfs(int u, int k, int p){
    cmp[u]=cnt;
    for(auto [v,w]:vec[u]){
        if(cmp[v]||w>=k||v==p) continue;
            dfs(v,k,u);
    }
}
bool chk(int k){
    cnt=0;
    for(int i=1; i<=n; i++)
        cmp[i]=0;
    for(int i=1; i<=n; i++){
        if(!cmp[i]){
            cnt++;
            dfs(i,k,0);
        }
    }
    /*for(int i=1; i<=n; i++){
        cout << cmp[i] << " ";
    }*/
    int cou=0;
    for(auto [x,y]:rela){
        if(cmp[x]!=cmp[y])
            cou++;
    }
    if(cou==rela.size())
        return true;
    else
        return false;
}
main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> p;
    cmp.resize(n+1,0);
    for(int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
        if(!ump[w]){
            ump[w]=true;
            wei.emplace_back(w);
        }
    }
    sort(wei.begin(),wei.end());
    for(int i=0; i<p; i++){
        int x,y;
        cin >> x >> y;
        rela.emplace_back(x,y);
    }
    if(chk(2e9)){
        cout << -1;
        return 0;
    }
    l=0;
    r=wei.size()-1;
    while(l<r){
        mid = (l+r+1)/2;
        //cout << wei[mid] << " ";
        if(chk(wei[mid])){
            //cout << 1;
            l=mid;
        }else{
            //cout << 2;
            r=mid-1;
        }
        //cout << "\n";
    }
    cout << wei[l];
}
