#include<bits/stdc++.h>
using namespace std;
#define pii pair< int,int >
vector<int> node(100005);
priority_queue < pair<int, pii > > pq;
int E,V,MST;
main(){
    cin >> V >> E;
    for(int i=1;i<=V;i++){
        node[i] = 1e9;
    }
    node[0] = 0;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        pq.push({w*-1,{u,v}});
    }
    while(!pq.empty()){
        int u,v,w;
        u = pq.top().second.first;
        v = pq.top().second.second;
        w = pq.top().first;
        pq.pop();
        if(node[v]!=1e9){
            continue;
        }
        node[v] = w*-1;
        MST+=(w*-1);
    }
    cout << MST;
}
