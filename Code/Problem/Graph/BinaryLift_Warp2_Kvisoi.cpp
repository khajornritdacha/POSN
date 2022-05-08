#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 2e5+10, LOG = 30;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,Q,go[N],ch[N][LOG];
bool vi[N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++)
    {
        cin >> go[i];
        ch[i][0] = go[i];
    }

    for(int k = 1; k < LOG; k++) for(int i = 1; i <= n; i++) ch[i][k] = ch[ch[i][k-1]][k-1];

    while(Q--)
    {
        int u, K; cin >> u >> K;
        u = go[u];
        for(int k = LOG-1; k >= 0; k--)
        {
            if(K >= (1<<k))
            {
                u = ch[u][k];
                K -= 1<<k;
            }
        }
        cout << u << "\n";
    }
    return 0;
}
