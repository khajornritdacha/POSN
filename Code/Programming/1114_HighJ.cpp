#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
const int N = 610;
int n,w[N][N],dis[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 127, sizeof(dis));
    cin >> n;
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){
            cin >> w[i][j];
        }
    }
    dis[2*n] = 0;
    pq.emplace(0, 2*n);
    while(!pq.empty()){
        int waste, u;
        tie(waste, u) = pq.top();
        pq.pop();
        for(int v=2; v<u; v++){
            if(dis[u]+w[u][v] < dis[v]){
                dis[v] = dis[u]+w[u][v];
                pq.emplace(dis[v], v);
            }
        }
    }
    cout << dis[2] << "\n";
}
