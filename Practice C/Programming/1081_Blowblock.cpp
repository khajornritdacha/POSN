#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
ll ans;
int n,a[N][N],now[2][2];
priority_queue<int> pq[2][2];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            pq[i%2][j%2].emplace(a[i][j]);
        }
    }
    while(!pq[0][0].empty()){
        for(int i=0; i<2; i++) for(int j=0; j<2; j++){
            now[i][j] = pq[i][j].top();
            pq[i][j].pop();
        }
        ans += 1LL*now[0][0]*now[0][1]*now[1][0]*now[1][1];
    }
    cout << ans << "\n";
}
