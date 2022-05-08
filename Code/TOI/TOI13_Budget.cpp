#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii> vec[10005];
vector<int> dis(10005,1e9),dis_r(10005,1e9);
priority_queue < pii , vector<pii> , greater<pii> > pq;
int V,E,st,ed,mon;
bool visit[10005],visit_r[10005];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    cin >> st >> ed >> mon;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    dis[st] = 0;
    dis_r[ed] = 0;
    pq.emplace(0,st);
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visit[u] = true;
        /*if(u==ed)
            break;*/
        for(int i=0;i<vec[u].size();i++){
            int v = vec[u][i].first;
            int w = vec[u][i].second;
            if(dis[u]+w<dis[v]&&visit[v]==false){
                dis[v] = dis[u]+w;
                pq.emplace(dis[v],v);
            }
        }
    }
    /*for(int i=0;i<V;i++){
        cout << dis[i] << " ";
    }
    cout << "\n";*/
    if(dis[ed]<=mon){
        cout << ed << " " << dis[ed] << " " << 0;
        return 0;
    }
    while(!pq.empty())
        pq.pop();

    pq.emplace(0,ed);
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visit_r[u] = true;
        /*if(u==st)
            break;*/
        for(int i=0;i<vec[u].size();i++){
            int v = vec[u][i].first;
            int w = vec[u][i].second;
            if(dis_r[u]+w<dis_r[v]&&visit_r[v]==false){
                dis_r[v] = dis_r[u]+w;
                pq.emplace(dis_r[v],v);
            }
        }
    }
    /*for(int i=0;i<V;i++){
        cout << dis_r[i] << " ";
    }
    cout << "\n";*/
    int minn = 1e9,ansdis,ansnode;
    for(int i=0;i<V;i++){
        if(dis_r[i]<minn&&mon-dis[i]>=0&&i!=ed){
            minn = dis_r[i];
            ansdis = dis[i];
            ansnode = i;
        }
    }
    cout << ansnode << " " << ansdis << " " << minn;
}
