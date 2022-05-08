#include <bits/stdc++.h>
using namespace std;

const int N = 15010, INF = 2e9;
using ll = long long;
using pi = pair<int, int>;

int n,K,X[N],Y[N],dis[N],ans;
bool vi[N];

int main(void){
    scanf(" %d %d", &n, &K);
    for(int i = 1; i <= n; i++){
        scanf(" %d %d", &X[i], &Y[i]);
        dis[i] = INF;
    }

    dis[1] = 0;
    int pre = 1;
    for(int t = 1; t < n; t++){ //Prim's mst without min heap
        vi[pre] = true;
        int mn = INF, st = -1;
        for(int u = 1; u <= n; u++){
            if(vi[u]) continue;
            dis[u] = min(dis[u], abs(X[pre] - X[u]) + abs(Y[pre] - Y[u]));    
            if(dis[u] < mn){
                mn = dis[u];
                st = u;
            }
        }
        ans += dis[st];
        pre = st;
    }

    //for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    sort(dis+1, dis+n+1, greater<int>());
    for(int i = 1; i < K; i++) ans -= dis[i];
    printf("%d\n", ans);

    return 0;
}