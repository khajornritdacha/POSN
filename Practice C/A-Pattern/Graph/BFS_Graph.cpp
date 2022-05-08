#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int V,E,st,dis[N];
vector<int> vec[N];
bool visit[N];

main(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin >> st;
    queue<int> qq;
    qq.push(st);
    visit[st] = true;
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();

        for(int i=0; i<vec[u].size(); i++){
            int v = vec[u][i];
            if(visit[v] == false){
                visit[v] = true;
                dis[v] = dis[u]+1;
                qq.push(v);
            }
        }
    }

    for(int i=1; i<=V; i++){
        cout << "NODE : " << i << " = " << dis[i] << "\n";
    }
}
/*
8 9
1 2
1 3
1 4
4 8
4 7
3 5
2 5
5 6
7 8
1
*/
