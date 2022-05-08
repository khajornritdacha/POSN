#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int n,M,ch[N],pho[N],dis[N],path,len;
bool me[N];
vector<int> vec[N];

int fist(int u, int p){
    ch[u] += me[u];
    int far = u;
    for(int v : vec[u]){
        if(v == p) continue;
        dis[v] = dis[u]+1;
        int tmp = fist(v, u);
        ch[u] += ch[v];
        if(ch[v] > 0 and dis[tmp] > dis[far]){
            far = tmp;
        }
    }
    return far;
}

void solve(int u, int p){
    if(me[u])
        len = max(len, dis[u]);
    ch[u] += me[u];
    for(int v : vec[u]){
        if(v == p) continue;
        dis[v] = dis[u]+1;
        solve(v, u);
        ch[u] += ch[v];
        if(ch[v]){
            path++;
        }
    }

    if(DEBUG){
        printf("NOW = %d From = %d\n", u, p);
        printf("Ch = %d\n", ch[u]);
        printf("Path = %d\n\n", path);
    }

}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    for(int i=1; i<=M; i++){
        cin >> pho[i];
        me[pho[i]] = true;
    }
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }

    int st1 = fist(pho[1], -1);
    memset(ch, 0, sizeof(ch));
    memset(dis, 0, sizeof(dis));
    int rst = fist(st1, -1);
    memset(ch, 0, sizeof(ch));
    memset(dis, 0, sizeof(dis));

    solve(rst, -1);

    if(DEBUG){
        printf("ST1 = %d\nRst = %d\n", st1, rst);
        printf("Path = %d\nLen = %d\n", path, len);
    }
    cout << path*2-len << "\n";
}
