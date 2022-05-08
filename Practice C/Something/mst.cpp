#include<bits/stdc++.h>
using namespace std;
int V,E,head[100005],MST=0;
vector< pair<int, pair<int,int> > > edge;
int findH(int x){
    if(head[x] == x)
        return x;
    return head[x] = findH(head[x]);
}
main(){
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.emplace_back(make_pair(w,make_pair(u,v)));
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<=V;i++){
        head[i] = i;
    }
    for(int i=0;i<edge.size();i++){
        int hu = findH(edge[i].second.first);
        int hv = findH(edge[i].second.second);
        if(hu!=hv){
            MST+= edge[i].first;
            head[hu] = head[hv];
        }
    }
    cout << MST;
    return 0;
}
