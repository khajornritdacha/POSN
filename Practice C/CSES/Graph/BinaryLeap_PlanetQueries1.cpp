#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9, LOG = 30;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n, Q, ch[N][LOG];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> ch[i][0];
    }
    
    for(int k = 1; k < LOG; k++) for(int i = 1;  i <= n; i++) ch[i][k] = ch[ch[i][k-1]][k-1];

    while(Q--){
        int u, K; cin >> u >> K;
        for(int k = LOG-1; k >= 0; k--){
            if(K >= 1<<k){
                u = ch[u][k];
                K -= 1<<k;
            }
        }
        cout << u << "\n";
    }

    return 0;
}