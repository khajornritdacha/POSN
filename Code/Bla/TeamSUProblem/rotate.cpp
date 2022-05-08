#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> vec,dis;
queue<int> q;
main(){
    cin >> n >> m;
    dis.resize(m+1,2e9);
    for(int i=1; i<=n; i++){
        int u;
        cin >> u;
        u%=m;
        if(u<0)
            u+=m;
        if(dis[u]==2e9){
            dis[u]=1;
            vec.emplace_back(u);
            q.emplace(u);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==0){
            cout << dis[0];
            return 0;
        }
        for(int i=0; i<vec.size(); i++){
            int v=(vec[i]+u)%m;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.emplace(v);
            }
        }
    }
    cout << dis[0];
}
