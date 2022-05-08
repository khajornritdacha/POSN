#include<bits/stdc++.h>
using namespace std;
bool chk[300100][2];
bool cd,cd2,foundx,foundy;
int x,y,st;
long long cnt[2],n;
vector<int> vec[300100];
void dfs(int u, int p){
    chk[u][cd]=true;
    //cout << u << " ";
    for(auto v:vec[u]){
        //cout << v << " ";
        if(v==x) foundx=true;
        if(v==y) foundy=true;
        if(v==p||v==x||v==y) continue;
        dfs(v,u);
    }
}
void ddfs(int u, int p){
    cnt[cd2]++;
    for(auto v:vec[u]){
        if(v==p||chk[v][cd]) continue;
        if(cd2==false&&v==y) continue;
        if(cd2==true&&v==x) continue;
        //cout << "V: " << cd2 << " " << v << " ";
        ddfs(v,u);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> y;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    cd=0;
    for(int i=1; i<=n; i++){
        if(i==x||i==y) continue;
        if(!chk[i][0]){
            foundx=foundy=false;
            dfs(i,0);
            if(foundx&&foundy){
                st=i;
                break;
            }
        }
    }
    cd=1;
    //cout << "ST: " << st << "\n";
    dfs(st,0);
    ddfs(x,0);
    cd2=1;
    ddfs(y,0);
    //cout << cnt[0] << " " << cnt[1] << "\n";
    long long ans=(long long)(n-1)*n;
    long long temp=cnt[0]*cnt[1];
    //cout << ans << " " << temp << " " << ans-temp;
    cout << ans-temp;
}
